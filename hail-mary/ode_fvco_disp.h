// --------------------------------Begin ODE system of White model --------------------------------------------//
int fast_odes(double t, const double y[], double dydt[],void *Paramstuff)
{
STRUCTURE* Params;
Params = (STRUCTURE*) Paramstuff;

//variables constant across treatments, priors from CK 
double nuV		= Params->PARS[2]; //virus transmission
double nuF		= Params->nuF;	//conidia transmission	//Params->PARS[3];
double nuR		= Params->nuR;	//resting spore transmission

double muF		= Params->muF;  //CK//  Using the site-specific muF that was loaded up in DDEVF14
double lambdaV = 1/exposetime;
double lambdaF=Params->PARS[18];		// decay rate of E_V and E_F
VFPass=exposetime-1/Params->PARS[18];

double size_C		= Params->size_C;  //Scaling effect of size on susceptibility over time.
double indexR = Params->indexR;
double indexV = Params->indexV;

int j = Params->j; //dataset

//indexing
int i;
int num_sub = Params->numsub;
//printf("fast ode num_sub = %i\n", num_sub);
int sub;

//exposed classes
int m = Params->PARS[9]; //fungus
int n = Params->PARS[8];  //virus
int n1=(VFPass/exposetime)*Params->PARS[8];    //virus exposed that can be taken over by fungus
int n2=n-n1;                //The number of the first group of exposed classes to virus

//state variables
double S0[4];
double R[4];

if (j==1 || j==2 || j==3){
	for(i=0; i<num_sub; i++){
		S0[i] = Params->FITINIT[j][i];
		R[i] = Params->FITINIT[j][i+num_sub+num_sub];
		//printf("S0 = %lf\t R = %lf\n", S0[i], R[i]);
	}
}
if (j==4 || j==5 || j==6){
	S0[0] = Params->FITINIT[j][0];
	R[0] = Params->FITINIT[j][8];
	//printf("S0 = %lf\t R = %lf\n", S0[0], R[0]);
}

//printf("muV=%lf\n", Params->muV);

//dispersal
int coni_dispersal_on = 1; //set to 0 for no dispersal
double Cdisp[4] = {0, 0, 0, 0}; //net conidia dispersal
//printf("VFSus = %lf\n",Params->VFSus);

//printf("Did I find j from params? j = %i\n", j);
// ------------------------------------------ ODEs -------------------------------------------- //

int sub_index[num_sub];
int max_class = m+n+7+m;
sub_index[0] = 0; //treatment 1 index addition is zero
for(sub=1; sub<num_sub; sub++){	//createsub array 
	sub_index[sub] = sub_index[sub-1]+ max_class; //SH can maybe multiply 
}

//-------------------------------------- CONIDIA DISPERSAL -------------------------------------------//
if(coni_dispersal_on == 1){ //turn off at declaration at top of script

	if (j==1 || j==2 || j==3) { //only for datasets with subpopulations
		//printf("I'm in the dispersal loop! j = %i\n", j);
		int subout; //indexing
		int subin; //indexing
		double con_disp; //frac dispersing from subout to subin
		double netdisp[4] = {0, 0, 0, 0};
		
		for(subout = 0; subout < num_sub; subout++){ //calculate net dispersal
			for(subin = 0; subin < num_sub; subin++){
				if(subout != subin){
					con_disp = Params->con_mgr*exp(-Params->a*Params->DISTANCE[j][subout][subin]);
					//printf("con_disp=%lf\n", con_disp);
					//con_disp = 0;
					netdisp[subout] = netdisp[subout] - con_disp*y[m+n+1+sub_index[subout]]; 
					netdisp[subin] = netdisp[subin] + con_disp*y[m+n+1+sub_index[subout]]; 
					//printf("netdispout[%i] = %e\t netdispin[%i] = %e\n", subout, netdisp[subout], subin, netdisp[subin]);
				}
			}
		}
		for(sub=0; sub<num_sub; sub++){ //update conidia density
			//printf("pre-disp C[%i]= %e\n", sub, C[sub]);
			Cdisp[sub] = y[m+n+1+sub_index[sub]] + netdisp[sub];
			//printf("j = %i, net C[%i]= %e\n", j, sub, Cdisp[sub]);
		}
	} 
}

for(sub=0; sub<num_sub; sub++){
	//printf("sub=%i\n", sub);
	//printf("GREETINGS from line 100 in ode\n");
	dydt[0+sub_index[sub]]  = -y[0+sub_index[sub]]*(nuF*(y[m+n+1+sub_index[sub]]+Cdisp[sub]) + nuR*R[sub])-y[0+sub_index[sub]]*nuV*y[m+n+3+sub_index[sub]]*pow((y[0+sub_index[sub]]/S0[sub]),squareCVV);
	//printf("subindex[sub]=%i\t dydt[0]=%e\n", sub_index[sub], dydt[0+sub_index[sub]]); //SH GREG CHECK; THIS ALWAYS = 0...
	//getc(stdin);
	//printf("%e\t %e\t %e\t %e\t %e\n", y[0+sub_index[sub]], y[m+n+1+sub_index[sub]], y[0+sub_index[sub]], y[m+n+3+sub_index[sub]], y[0+sub_index[sub]]/S0[sub]);
	//printf("%e\t %e\t %e\t %e\n", nuF, y[m+n+1+sub_index[sub]], nuV, y[m+n+3+sub_index[sub]]);
	
	//getc(stdin);
	dydt[1+sub_index[sub]]  = nuF*y[m+n+1+sub_index[sub]]*y[0+sub_index[sub]] + nuR*R[sub]*y[0+sub_index[sub]] - m*lambdaF*y[1+sub_index[sub]];
	for(i=2; i <= m; i++){
		dydt[i+sub_index[sub]]=m*lambdaF*(y[i-1+sub_index[sub]] -y[i+sub_index[sub]]);
	}

	//First group of classes exposed to virus, which can be infected by fungus and going into exposed classes for fungus
	dydt[m+1+sub_index[sub]] = y[0+sub_index[sub]]*nuV*y[m+n+3+sub_index[sub]]*pow((y[0+sub_index[sub]]/S0[sub]),squareCVV)-n*lambdaV*y[m+1+sub_index[sub]]-y[m+1+sub_index[sub]]*(nuF*y[m+n+1+sub_index[sub]] + nuR*R[sub])*Params->VFSus;
	for (i=2;i<=n1;i++){
		dydt[m+i+sub_index[sub]]=n*lambdaV*(y[m+i-1+sub_index[sub]]-y[m+i+sub_index[sub]])-y[m+i+sub_index[sub]]*(nuF*y[m+n+1+sub_index[sub]] + nuR*R[sub])*Params->VFSus;
	}

	//Second group of classes exposed to virus, which cannot be infected by fungus, and generate virus for the next epizootic
	dydt[m+n1+1+sub_index[sub]]=n*lambdaV*y[m+n1+sub_index[sub]]-n*lambdaV*y[m+n1+1+sub_index[sub]];
	for (i=2;i<=n2;i++){
		dydt[m+n1+i+sub_index[sub]]=n*lambdaV*(y[m+n1+i-1+sub_index[sub]]-y[m+n1+i+sub_index[sub]]);
	}
	dydt[m+n+1+sub_index[sub]] = m*lambdaF*(y[m+sub_index[sub]]+(1-coinf_V)*y[m+n+6+m+sub_index[sub]])*size_C - muF*y[m+n+1+sub_index[sub]];  //Conidia class!  Transission from final exposed class (m) to conidia class (m+1)
	dydt[m+n+2+sub_index[sub]] = indexR*m*lambdaF*(y[m+sub_index[sub]]+(1-coinf_V)*y[m+n+6+m+sub_index[sub]]);
	dydt[m+n+3+sub_index[sub]] = n*lambdaV*y[m+n+sub_index[sub]]+m*lambdaF*y[m+n+6+m+sub_index[sub]]*coinf_V-Params->muV*y[m+n+3+sub_index[sub]];  //Class of cadavers infected by virus
	dydt[m+n+4+sub_index[sub]] = n*lambdaV*y[m+n+sub_index[sub]]+m*lambdaF*y[m+n+6+m+sub_index[sub]]*coinf_V;
	dydt[m+n+5+sub_index[sub]] = m*lambdaF*(y[m+sub_index[sub]]+(1-coinf_V)*y[m+n+6+m+sub_index[sub]]);
	dydt[m+n+6+sub_index[sub]] = indexV*(n*lambdaV*y[m+n+sub_index[sub]]+m*lambdaF*y[m+n+6+m+sub_index[sub]]*coinf_V);

	//Recording the hosts already infected with virus and taken over by the fungus //coinfections
	dydt[m+n+6+1+sub_index[sub]] = (nuF*y[m+n+1+sub_index[sub]] + nuR*R[sub])*y[m+1+sub_index[sub]]*Params->VFSus- m*lambdaF*y[m+n+6+1+sub_index[sub]];
	//printf("sub = %i\t nuf = %lf\t C = %lf\t nuR = %lf\t R = %lf\t V = %lf\t VFSUS = %lf\n", sub, nuF, y[m+n+1+sub_index[sub]], nuR, R[sub], y[m+1+sub_index[sub]], Params->VFSus);
	for (i=2;i<=n1;i++){
		dydt[m+n+6+1+sub_index[sub]] += (nuF*y[m+n+1+sub_index[sub]] + nuR*R[sub])*y[m+i+sub_index[sub]]*Params->VFSus;
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

int DIM = num_sub*(Params->PARS[9]+Params->PARS[8]+4+2+1+Params->PARS[9]); //SH multiplied by 4 to hold all equations for each treatment

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

	for (i=0;i<DIM;i++)	{
		if (y_ode[i]>=0)		{
			// keep y_ode as is
		}
		else  {//why can't it be zero?
			//printf("NEGATIVE OR NAN y_ode[%i]=%e\n", i, y_ode[i]);				
			//printf("y(%d) NEGATIVE or not a number\n",i);
			y_ode[i]=0;
			//is this indicative of a problem in the code or just because we don't do negative numbers
		}
		if (i==Params->PARS[9]+Params->PARS[8]+3 || i==Params->PARS[9]+Params->PARS[8]+1){

		}
		else{
		//if (y_ode[i]>Params->INITS[Params->numsub])	{
		//	printf("y(%d) TOO LARGE!!\n",i);
			//printf("TOO LARGE y_ode[%i]=%e\n", i, y_ode[i]);	
		//	y_ode[i]=Params->INITS[0];
		//}
		}
	}

}
// -------------------------------------- Clear Memory ----------------------------------------- //
gsl_odeiv_evolve_free(evol_ode);
gsl_odeiv_control_free(tol_ode);
gsl_odeiv_step_free(step_ode);

return (t_end);
}