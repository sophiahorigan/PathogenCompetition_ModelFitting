// --------------------------------Begin ODE system of White model --------------------------------------------//
int fast_odes(double t, const double y[], double dydt[],void *Paramstuff)
{
STRUCTURE* Params;
Params = (STRUCTURE*) Paramstuff;

//FIT PARAMETERS
double nuV 		= Params->nuV; //fitting //used to be 0.64
//printf("nuV=%lf\t", nuV);
double nuF		= Params->nuF;	//conidia transmission
//printf("nuF=%lf\t", nuF);
double muV		= Params->muV; //virus decay
double squareCVV = Params->CV*Params->CV; //heterogeneity

//WEATHER CALCULATED VALUES
double nuR		= Params->nuR;	//resting spore transmission
double muF		= Params->muF;  //conidia decay

//INDEXING
int j = Params->j; //dataset
int i;
int num_sub = Params->numsub;
//printf("fast ode num_sub = %i\n", num_sub);
int sub;
//state variables
double S0[4];
double R[4];

if (j==1 || j==2 || j==3){
	for(i=0; i<num_sub; i++){
		S0[i] = Params->FITINIT[j][i];
		R[i] = Params->FITINIT[j][i+num_sub+num_sub];
	}
}
if (j==4 || j==5 || j==6){
	S0[0] = Params->FITINIT[j][0];
	R[0] = Params->FITINIT[j][8];
}

int subout; //indexing
int subin; //indexing
double Cout[4];
double Cin[4];
double netC[4];
double c_a[4][4];
double c_m[4][4];

for(sub=0; sub<num_sub; sub++){
	Cout[sub] = 0;
	Cin[sub] = 0;
	netC[sub] = 0;
}

//-------------------------------------- CONIDIA DISPERSAL -------------------------------------------//
if(conidia_dispersal == 1){ 

	//COMPETING MODELS
	//a
	if (c_a_pop_fit == 1){
		for(i=1; i<=3; i++){
			for(sub=0;sub<num_sub;sub++){
				c_a[i][sub] = Params->c_a_pop; //one value for entire population 
			}
		}
	}
	if (c_a_meta_fit == 1){
		for(i=1; i<=3; i++){
			for(sub=0;sub<num_sub;sub++){
				c_a[i][sub] = Params->c_a_meta[i]; //one value for each metapopulation 
			}
		}
	}
	if (c_a_sub_fit == 1){
		for(i=1; i<=3; i++){
			for(sub=0;sub<num_sub;sub++){
				c_a[i][sub] = Params->c_a_sub[i][sub]; //one value for each subpopulation 
			}
		}
	}	
	//m
	if (c_m_pop_fit == 1){
		for(i=1; i<=3; i++){
			for(sub=0;sub<num_sub;sub++){
				c_m[i][sub] = Params->c_m_pop; //one value for entire population 
			}
		}
	}
	if (c_m_meta_fit == 1){
		for(i=1; i<=3; i++){
			for(sub=0;sub<num_sub;sub++){
				c_m[i][sub] = Params->c_m_meta[i]; //one value for each metapopulation 
			}
		}
	}
	if (c_m_sub_fit == 1){
		for(i=1; i<=3; i++){
			for(sub=0;sub<num_sub;sub++){
				c_m[i][sub] = Params->c_m_sub[i][sub]; //one value for each subpopulation 
			}
		}
	}	
	//BEGIN DISPERSAL
	if (j==1 || j==2 || j==3) { 

		for(subout = 0; subout < num_sub; subout++){ //calculate net dispersal
			
			//SCALE OF MIGRATION
			Cout[subout] = exp(-c_a[j][subout]*10) * y[m+n+1+sub_index[subout]]; //r = 10m
			//printf("sub=%i\t Cout=%lf\t C=%lf\n", subout, Cout[subout], y[m+n+1+sub_index[subout]]);

			for(subin = 0; subin < num_sub; subin++){

				if(subout != subin){

					Cin[subin] += Cout[subout] * c_m[j][subout] * exp(-c_a[j][subout]*Params->DISTANCE[j][subout][subin]);

				}
			} 
		}
		for(sub=0; sub<num_sub; sub++){ //update conidia density

			netC[sub] += (Cin[sub] - Cout[sub]);
			//netC[sub] = 0; //TEST, TURNING DISPERSAL OFF

		}
		
	}	
	if (j==4 || j==5 || j==6) { //no dispersal in observational populations

		for(subout = 0; subout < num_sub; subout++){

			netC[sub] = 0;
		}

	}
}

for(sub=0; sub<num_sub; sub++){
	//*******************SUSCEPTIBLE*********************
	dydt[0+sub_index[sub]]  = -y[0+sub_index[sub]]*(nuF*y[m+n+1+sub_index[sub]] + nuR*R[sub])-y[0+sub_index[sub]]*nuV*y[m+n+2+sub_index[sub]]*pow((y[0+sub_index[sub]]/S0[sub]),squareCVV);
	//printf("S=%lf\n", dydt[0+sub_index[sub]]);
	//printf("initS = %lf\t fungus infected = %lf\t virus infected = %lf\n", y[0+sub_index[sub]], -y[0+sub_index[sub]]*(nuF*y[m+n+1+sub_index[sub]] + nuR*R[sub]),  y[0+sub_index[sub]]*nuV*y[m+n+2+sub_index[sub]]*pow((y[0+sub_index[sub]]/S0[sub]),squareCVV));
	//***********************FUNGUS-INFECTED**********************
	dydt[1+sub_index[sub]]  = nuF*y[m+n+1+sub_index[sub]]*y[0+sub_index[sub]] + nuR*R[sub]*y[0+sub_index[sub]] - m*lambdaF*y[1+sub_index[sub]]; 
	//printf("F1=%lf\n", dydt[1+sub_index[sub]]);
	for(i=2; i<=m; i++){
		dydt[i+sub_index[sub]]=m*lambdaF*(y[(i-1)+sub_index[sub]] -y[i+sub_index[sub]]);
		//printf("F=%lf\n", dydt[i+sub_index[sub]]);

	}

	//**********************VIRUS-INFECTED************************
	dydt[m+1+sub_index[sub]] = y[0+sub_index[sub]]*nuV*y[m+n+2+sub_index[sub]]*pow((y[0+sub_index[sub]]/S0[sub]),squareCVV)-n*lambdaV*y[m+1+sub_index[sub]];
	//printf("V1=%lf\n", dydt[m+1+sub_index[sub]]);
	//printf("first term = %lf\t, second term = %lf\n", y[0+sub_index[sub]]*nuV*y[m+n+2+sub_index[sub]]*pow((y[0+sub_index[sub]]/S0[sub]),squareCVV), n*lambdaV*y[m+1+sub_index[sub]]);
	//printf("InitS = %lf\t nuV = %lf\t OBS = %lf\t pow = %lf\t n = %lf\t lambdaV = %lf\t V1 = %lf\n",y[0+sub_index[sub]], nuV, y[m+n+2+sub_index[sub]], pow((y[0+sub_index[sub]]/S0[sub]),squareCVV), n, lambdaV, y[m+1+sub_index[sub]]);
	//printf("n=%i\n", n);
	//printf("lambdaV=%lf\n", lambdaV);
	//printf("pow yo = %lf\t S0 = %lf\t divide = %lf\t squareCVV = %lf\n", y[0+sub_index[sub]], S0[sub], (y[0+sub_index[sub]]/S0[sub]), squareCVV);
	for (i=2;i<=n;i++){
		dydt[m+i+sub_index[sub]]=n*lambdaV*(y[m+(i-1)+sub_index[sub]]-y[m+i+sub_index[sub]]);
		//printf("V=%lf\n", dydt[m+i+sub_index[sub]]);

	}
	//**********************CONIDIA*****************
	dydt[m+n+1+sub_index[sub]] = m*lambdaF*y[m+sub_index[sub]] - muF*y[m+n+1+sub_index[sub]] + netC[sub];
	//printf("C=%lf\n", dydt[m+n+1+sub_index[sub]]);

	//*************************OBS***********************
	dydt[m+n+2+sub_index[sub]] = n*lambdaV*y[m+n+sub_index[sub]] - muV*y[m+n+2+sub_index[sub]]; 
	//printf("OB=%lf\n", dydt[m+n+2+sub_index[sub]]);

	//getc(stdin);
}

return GSL_SUCCESS;
}


// ------------------------------------------  ODE Solver  ----------------------------------------------- //
double ODE_Solver(double t_ode,double t_end,void *Paramstuff,double *y_ode)
{
int i;
int status_ode;
double h_init=1.0e-5;
int DIM = 508;  //CHANGE 508

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
			y_ode[i]=0;
		}
	}

}
// -------------------------------------- Clear Memory ----------------------------------------- //
gsl_odeiv_evolve_free(evol_ode);
gsl_odeiv_control_free(tol_ode);
gsl_odeiv_step_free(step_ode);

return (t_end);
}