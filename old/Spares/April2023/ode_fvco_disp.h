// --------------------------------Begin ODE system of White model --------------------------------------------//
int fast_odes(double t, const double y[], double dydt[],void *Paramstuff)
{
STRUCTURE* Params;
Params = (STRUCTURE*) Paramstuff;

//FIT PARAMETERS
double nuV 		= Params->nuV; //fitting //used to be 0.64
double nuF		= Params->nuF;	//conidia transmission


//WEATHER CALCULATED VALUES
double nuR		= Params->nuR;	//resting spore transmission
double muF		= Params->muF;  

int j = Params->j; //dataset

//indexing
int i;
int num_sub = Params->numsub;
//printf("fast ode num_sub = %i\n", num_sub);
int sub;
//state variables
double S0[4];
double R[4];

//coinfection variables
//we don't want coinfection to play a part in our experimental data
double VFSus;
double coinf_V;

if (j==1 || j==2 || j==3){
	for(i=0; i<num_sub; i++){
		S0[i] = Params->FITINIT[j][i];
		R[i] = Params->FITINIT[j][i+num_sub+num_sub];
		//printf("S0 = %lf\t R = %lf\n", S0[i], R[i]);
		VFSus = 0;
		coinf_V = 0;
	}
}
if (j==4 || j==5 || j==6){
	S0[0] = Params->FITINIT[j][0];
	R[0] = Params->FITINIT[j][8];
	//printf("S0 = %lf\t R = %lf\n", S0[0], R[0]);
	VFSus = Params->VFSus;
	coinf_V = Params->coinf_V;
}

//printf("j = %i\t, VFSus = %lf\t, coinf_V = %lf\n", j, VFSus, coinf_V);
//printf("muV=%lf\n", Params->muV);

//heterogeneity
double squareCVV = Params->CV*Params->CV;

//dispersal
int coni_dispersal_on = 0; //set to 0 for no dispersal
int subout; //indexing
int subin; //indexing
double Cout[4];
double Cin[4];
double netC[4];

for(sub=0; sub<num_sub; sub++){
	Cout[sub] = 0;
	Cin[sub] = 0;
	netC[4] = 0;
}

//-------------------------------------- CONIDIA DISPERSAL -------------------------------------------//
if(coni_dispersal_on == 1){ //turn off at declaration at top of script

	if (j==1 || j==2 || j==3) { 

		for(subout = 0; subout < num_sub; subout++){ //calculate net dispersal
			
			//SCALE OF MIGRATION
			//netCout[subout] = ((Params->m_c_sub[j][subout] * 2.0 * M_PI)/Params->a_c_pop) * y[m+n+1+sub_index[subout]];
			Cout[subout] = exp(-Params->a_c_pop*10) * y[m+n+1+sub_index[subout]]; //r = 10m
			//printf("sub=%i\t Cout=%lf\t C=%lf\n", subout, Cout[subout], y[m+n+1+sub_index[subout]]);
			//printf("IN DISPERSAL sub=%i\t C=%e\n", subout, y[m+n+1+sub_index[subout]]);

			for(subin = 0; subin < num_sub; subin++){

				if(subout != subin){

					//netCin[subin] += y[m+n+1+sub_index[subout]] * Params->m_c_sub[j][subout] * exp(-Params->a_c_pop*Params->DISTANCE[j][subout][subin]);
					Cin[subin] += Cout[subout] * Params->m_c_pop * exp(-Params->a_c_pop*Params->DISTANCE[j][subout][subin]);

				}
			} 
		}
		for(sub=0; sub<num_sub; sub++){ //update conidia density

			netC[sub] += (Cin[sub] - Cout[sub]);

			if((y[m+n+1+sub_index[sub]])<0){
				//printf("TOO MUCH DISPERSAL! NEGATIVE CONIDIA POPULATIONS.");
				//printf("sub=%i\t C=%e\t netC=%e\n", sub, y[m+n+1+sub_index[sub]], netC[sub]);
			}
		}
	}	
}

for(sub=0; sub<num_sub; sub++){
	//*******************SUSCEPTIBLE*********************
	dydt[0+sub_index[sub]]  = -y[0+sub_index[sub]]*(nuF*y[m+n+1+sub_index[sub]] + nuR*R[sub])-y[0+sub_index[sub]]*nuV*y[m+n+3+sub_index[sub]]*pow((y[0+sub_index[sub]]/S0[sub]),squareCVV);
	//printf("sub=%i\t dydt[0]=%e\n", sub, dydt[0+sub_index[sub]]);
	//printf("%e\t %e\t %e\t %e\n", y[0+sub_index[sub]], y[m+n+1+sub_index[sub]], y[m+n+3+sub_index[sub]], y[0+sub_index[sub]]/S0[sub]);
	//printf("params nuF=%e\t nuR = %e\t Rsub=%lf\t nuV%lf\t squareCVV=%lf\n", nuF, nuR, R[sub], nuV, squareCVV);
	//printf("%e\t %e\t %e\t %e\n", nuF, y[m+n+1+sub_index[sub]], nuV, y[m+n+3+sub_index[sub]]);
	//getc(stdin);
	//getc(stdin);
	//***********************FUNGUS-INFECTED**********************
	dydt[1+sub_index[sub]]  = nuF*y[m+n+1+sub_index[sub]]*y[0+sub_index[sub]] + nuR*R[sub]*y[0+sub_index[sub]] - m*lambdaF*y[1+sub_index[sub]];
	for(i=2; i <= m; i++){
		dydt[i+sub_index[sub]]=m*lambdaF*(y[(i-1)+sub_index[sub]] -y[i+sub_index[sub]]);
		printf("sub = %i\t i=%i\t previousclass = %e\t moving= %e\n", sub, i, y[i-1+sub_index[sub]], y[i+sub_index[sub]]);
	}
	getc(stdin);

	//**********************VIRUS-INFECTED************************
	//First group of classes exposed to virus, which can be infected by fungus and going into exposed classes for fungus
	dydt[m+1+sub_index[sub]] = y[0+sub_index[sub]]*nuV*y[m+n+3+sub_index[sub]]*pow((y[0+sub_index[sub]]/S0[sub]),squareCVV)-n*lambdaV*y[m+1+sub_index[sub]]-y[m+1+sub_index[sub]]*(nuF*y[m+n+1+sub_index[sub]] + nuR*R[sub])*VFSus;
	for (i=2;i<=n1;i++){
		dydt[m+i+sub_index[sub]]=n*lambdaV*(y[m+(i-1)+sub_index[sub]]-y[m+i+sub_index[sub]])-y[m+i+sub_index[sub]]*(nuF*y[m+n+1+sub_index[sub]]+ nuR*R[sub])*VFSus;
	}

	//Second group of classes exposed to virus, which cannot be infected by fungus, and generate virus for the next epizootic
	dydt[m+n1+1+sub_index[sub]]=n*lambdaV*y[m+n1+sub_index[sub]]-n*lambdaV*y[m+n1+1+sub_index[sub]];
	for (i=2;i<=n2;i++){
		dydt[m+n1+i+sub_index[sub]]=n*lambdaV*(y[m+n1+i-1+sub_index[sub]]-y[m+n1+i+sub_index[sub]]);
	}

	//**********************Fungus cadavers (conidia)**************
	//conidia
	dydt[m+n+1+sub_index[sub]] = m*lambdaF*(y[m+sub_index[sub]]+(1-coinf_V)*y[m+n+6+m+sub_index[sub]])*size_C - muF*y[m+n+1+sub_index[sub]] + netC[sub];  //Conidia class!  Transission from final exposed class (m) to conidia class (m+1)
	//printf("sub = %i\t conidia = %e\n", sub, dydt[m+n+1+sub_index[sub]]);
	//printf("term 1 = %e\t, term 2 = %e\n", m*lambdaF*(y[m+sub_index[sub]]+(1-coinf_V)*y[m+n+6+m+sub_index[sub]])*size_C,  muF*(y[m+n+1+sub_index[sub]]+netC[sub]));
	//printf("ym = %e\t ymn6m = %e\n", y[m+sub_index[sub]], y[m+n+6+m+sub_index[sub]]);
	//printf("m=%lf\t lambdaF=%e\t big one = %e\t ymsub = %e\t 1-coinfV=%lf\t ymnmsub=%e\t sizec=%lf\n", m, lambdaF, (y[m+sub_index[sub]]+(1-coinf_V)*y[m+n+6+m+sub_index[sub]]), y[m+sub_index[sub]],(1-coinf_V), y[m+n+6+m+sub_index[sub]], size_C);
	//printf("coinfV=%lf\t lambdaF=%e\n", coinf_V, lambdaF);
	getc(stdin);
	//resting spores
	dydt[m+n+2+sub_index[sub]] = indexR*m*lambdaF*(y[m+sub_index[sub]]+(1-coinf_V)*y[m+n+6+m+sub_index[sub]]);

	//*************************VIRUS CADAVERS***********************
	dydt[m+n+3+sub_index[sub]] = n*lambdaV*y[m+n+sub_index[sub]]+m*lambdaF*y[m+n+6+m+sub_index[sub]]*coinf_V-Params->muV*y[m+n+3+sub_index[sub]];  //Class of cadavers infected by virus
	dydt[m+n+4+sub_index[sub]] = n*lambdaV*y[m+n+sub_index[sub]]+m*lambdaF*y[m+n+6+m+sub_index[sub]]*coinf_V;
	dydt[m+n+5+sub_index[sub]] = m*lambdaF*(y[m+sub_index[sub]]+(1-coinf_V)*y[m+n+6+m+sub_index[sub]]);
	dydt[m+n+6+sub_index[sub]] = indexV*(n*lambdaV*y[m+n+sub_index[sub]]+m*lambdaF*y[m+n+6+m+sub_index[sub]]*coinf_V);

	//*******************COINFECTION******************
	//Recording the hosts already infected with virus and taken over by the fungus
	dydt[m+n+6+1+sub_index[sub]] = (nuF*y[m+n+1+sub_index[sub]] + nuR*R[sub])*y[m+1+sub_index[sub]]*VFSus- m*lambdaF*y[m+n+6+1+sub_index[sub]];
	//printf("sub = %i\t nuf = %lf\t C = %lf\t nuR = %lf\t R = %lf\t V = %lf\t VFSUS = %lf\n", sub, nuF, y[m+n+1+sub_index[sub]], nuR, R[sub], y[m+1+sub_index[sub]], Params->VFSus);
	for (i=2;i<=n1;i++){
		dydt[m+n+6+1+sub_index[sub]] += (nuF*y[m+n+1+sub_index[sub]] + nuR*R[sub])*y[m+i+sub_index[sub]]*VFSus;
	}
	for(i=2; i <= m; i++){
		dydt[m+n+6+i+sub_index[sub]]=m*lambdaF*(y[m+n+6+i-1+sub_index[sub]] -y[m+n+6+i+sub_index[sub]]);
	}
	
}

return GSL_SUCCESS;
}


// ------------------------------------------  ODE Solver  ----------------------------------------------- //
double ODE_Solver(double t_ode,double t_end,void *Paramstuff,double *y_ode)
{
int i;
int status_ode;
double h_init=1.0e-5;

STRUCTURE* Params;
Params = (STRUCTURE*) Paramstuff;
int num_sub = Params->numsub;

//int DIM = num_sub*(Params->PARS[9]+Params->PARS[8]+4+2+1+Params->PARS[9]); //SH multiplied by 4 to hold all equations for each treatment

const gsl_odeiv_step_type *solver_ode	= gsl_odeiv_step_rkf45; // Runge-Kutta Fehlberg (4, 5)

// returns pointer to a newly allocated instance of a stepping function of type 'solver_ode' for a system of DIM dimensions //
gsl_odeiv_step *step_ode	= gsl_odeiv_step_alloc(solver_ode, DIM);

gsl_odeiv_control *tol_ode	= gsl_odeiv_control_standard_new(1.0e-10, 1.0e-5, 1.0, 0.2);
gsl_odeiv_evolve *evol_ode	= gsl_odeiv_evolve_alloc(DIM);

gsl_odeiv_system sys_ode;
sys_ode.function  = fast_odes;
sys_ode.dimension = (size_t)(DIM);
sys_ode.params	  = Params;

// ----------------------------------- Integrate Over Time ------------------------------------ //
while (t_ode<t_end)	{
	status_ode = gsl_odeiv_evolve_apply(evol_ode, tol_ode, step_ode, &sys_ode, &t_ode, t_end, &h_init, y_ode);
	//relative vs absolute error value

	for (i=0;i<DIM;i++)	{
		if (y_ode[i]>=0)		{
			// keep y_ode as is
		}
		else if(y_ode[i]<0)  {//why can't it be zero?
			//printf("NEGATIVE OR NAN y_ode[%i]=%e\n", i, y_ode[i]);				
			//printf("y(%d) NEGATIVE or not a number\n",i);
			//y_ode[i]=0;
		}
	}

}
// -------------------------------------- Clear Memory ----------------------------------------- //
gsl_odeiv_evolve_free(evol_ode);
gsl_odeiv_control_free(tol_ode);
gsl_odeiv_step_free(step_ode);

return (t_end);
}