int fast_odes(double t, const double y[], double dydt[],void *Paramstruct)
{
// --------------------------------- Set Up -------------------------------------//
STRUCTURE* Params;
Params = (STRUCTURE*) Paramstruct;

//local variales
int num_sub = Params->numsub;
int i;								//indexing
int j = Params->j; 					//dataset
double Cdisp[4] = {0, 0, 0, 0}; 	//net conidia dispersal
double lambdaV = 1/exposetime;
int n1 = ((exposetime-1/lambdaF)/exposetime)*n;    //early virus infection
int n2 = n-n1;                  //late virus infection
double size_C=1;				//?

//subpopulation structure
int sub;
int sub_index[num_sub];
sub_index[0] = 0; 			
for(sub=1; sub<num_sub; sub++){	
	sub_index[sub] = sub_index[sub-1]+ max_class; 
}

//dispersal
int coni_dispersal_on = 1; 			//set to 0 for no dispersal
int subout; int subin; 				//indexing
double con_disp; 					//frac dispersing from subout to subin
double netdisp[4] = {0, 0, 0, 0};

//------------------------------------- Parameters to Fit ---------------------------------------------------//

//Initial conditions
double S0[4] = {Params->FITINIT[j][1], Params->FITINIT[j][2], Params->FITINIT[j][3]}; //SH all have same inital population size
double R[4]  = {Params->FITINIT[j][8], Params->FITINIT[j][9], Params->FITINIT[j][10], Params->FITINIT[j][11]}; //different R for each subpop

//migration parameters
Params->con_mrg = Params->FITMETA[0];
Params->a = Params->FITMETA[1];
double con_mgr = Params->con_mrg;
double a = Params->a;

//coinfection parameters
Params->coinf_V = Params->FITMETA[4];
Params->VFSus = Params->FITMETA[3];
double coinf_V = Params->coinf_V;
double VFSus = Params->VFSus;

//-------------------------------------- Conidia Dispersal -------------------------------------------//
if(coni_dispersal_on == 1){ 
	if (j==1 || j==2 || j==3) { 
		for(subout = 0; subout < num_sub; subout++){ 
			for(subin = 0; subin < num_sub; subin++){
				if(subout != subin){
					con_disp = con_mgr*exp(-a*Params->DISTANCE[j][subout][subin]);
					netdisp[subout] = netdisp[subout] - con_disp*y[m+n+1+sub_index[subout]]; 
					netdisp[subin] = netdisp[subin] + con_disp*y[m+n+1+sub_index[subout]]; 
				}
			}
		}
		for(sub=0; sub<num_sub; sub++){ 
			Cdisp[sub] = y[m+n+1+sub_index[sub]] + netdisp[sub];
		}
	} 
}

// ------------------------------------------ Update Array Holding ODE's -------------------------------------------- //

for(sub=0; sub<num_sub; sub++){
	dydt[0+sub_index[sub]]  = -y[0+sub_index[sub]]*(nuF*(y[m+n+1+sub_index[sub]]+Cdisp[sub]) + nuR*R[sub])-y[0+sub_index[sub]]*nuV*y[m+n+3+sub_index[sub]]*pow((y[0+sub_index[sub]]/S0[sub]),squareCVV);
	dydt[1+sub_index[sub]]  = nuF*y[m+n+1+sub_index[sub]]*y[0+sub_index[sub]] + nuR*R[sub]*y[0+sub_index[sub]] - m*lambdaF*y[1+sub_index[sub]];
	for(i=2; i <= m; i++){
		dydt[i+sub_index[sub]]=m*lambdaF*(y[i-1+sub_index[sub]] -y[i+sub_index[sub]]);
	}
	//First group of classes exposed to virus, which can be infected by fungus and going into exposed classes for fungus
	dydt[m+1+sub_index[sub]] = y[0+sub_index[sub]]*nuV*y[m+n+3+sub_index[sub]]*pow((y[0+sub_index[sub]]/S0[sub]),squareCVV)-n*lambdaV*y[m+1+sub_index[sub]]-y[m+1+sub_index[sub]]*(nuF*y[m+n+1+sub_index[sub]] + nuR*R[sub])*VFSus;
	for (i=2;i<=n1;i++){
		dydt[m+i+sub_index[sub]]=n*lambdaV*(y[m+i-1+sub_index[sub]]-y[m+i+sub_index[sub]])-y[m+i+sub_index[sub]]*(nuF*y[m+n+1+sub_index[sub]] + nuR*R[sub])*VFSus;
	}

	//Second group of classes exposed to virus, which cannot be infected by fungus, and generate virus for the next epizootic
	dydt[m+n1+1+sub_index[sub]]=n*lambdaV*y[m+n1+sub_index[sub]]-n*lambdaV*y[m+n1+1+sub_index[sub]];
	for (i=2;i<=n2;i++){
		dydt[m+n1+i+sub_index[sub]]=n*lambdaV*(y[m+n1+i-1+sub_index[sub]]-y[m+n1+i+sub_index[sub]]);
	}
	dydt[m+n+1+sub_index[sub]] = m*lambdaF*(y[m+sub_index[sub]]+(1-coinf_V)*y[m+n+6+m+sub_index[sub]])*size_C - muF*y[m+n+1+sub_index[sub]];  //Conidia class!  Transission from final exposed class (m) to conidia class (m+1)
	dydt[m+n+2+sub_index[sub]] = indexR*m*lambdaF*(y[m+sub_index[sub]]+(1-coinf_V)*y[m+n+6+m+sub_index[sub]]);
	dydt[m+n+3+sub_index[sub]] = n*lambdaV*y[m+n+sub_index[sub]]+m*lambdaF*y[m+n+6+m+sub_index[sub]]*coinf_V-muV*y[m+n+3+sub_index[sub]];  //Class of cadavers infected by virus
	dydt[m+n+4+sub_index[sub]] = n*lambdaV*y[m+n+sub_index[sub]]+m*lambdaF*y[m+n+6+m+sub_index[sub]]*coinf_V;
	dydt[m+n+5+sub_index[sub]] = m*lambdaF*(y[m+sub_index[sub]]+(1-coinf_V)*y[m+n+6+m+sub_index[sub]]);
	dydt[m+n+6+sub_index[sub]] = indexV*(n*lambdaV*y[m+n+sub_index[sub]]+m*lambdaF*y[m+n+6+m+sub_index[sub]]*coinf_V);

	//Recording the hosts already infected with virus and taken over by the fungus
	dydt[m+n+6+1+sub_index[sub]] = (nuF*y[m+n+1+sub_index[sub]] + nuR*R[sub])*y[m+1+sub_index[sub]]*VFSus- m*lambdaF*y[m+n+6+1+sub_index[sub]];
	for (i=2;i<=n1;i++){
		dydt[m+n+6+1+sub_index[sub]] += (nuF*y[m+n+1+sub_index[sub]] + nuR*R[sub])*y[m+i+sub_index[sub]]*VFSus;
	}
	for(i=2; i <= m; i++){
		dydt[m+n+6+i+sub_index[sub]]=m*lambdaF*(y[m+n+6+i-1+sub_index[sub]] -y[m+n+6+i+sub_index[sub]]);
	}
	
}
return GSL_SUCCESS;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

double ODE_Solver(double t_ode,double t_end,void *Paramstruct,double *y_ode)
{
// --------------------------------- Set Up -------------------------------------//
STRUCTURE* Params;
Params = (STRUCTURE*) Paramstruct;

//local variables
int i;					//indexing
int status_ode;
double h_init = 1.0e-5;
int sub;
int num_sub = Params->numsub;
int DIM = num_sub*max_class;
int j = Params->j; 					//dataset

//set up ode solver
const gsl_odeiv_step_type *solver_ode	= gsl_odeiv_step_rkf45; // Runge-Kutta Fehlberg (4, 5)
gsl_odeiv_step *step_ode	= gsl_odeiv_step_alloc(solver_ode, DIM);
gsl_odeiv_control *tol_ode	= gsl_odeiv_control_standard_new(1.0e-10, 1.0e-5, 1.0, 0.2);
gsl_odeiv_evolve *evol_ode	= gsl_odeiv_evolve_alloc(DIM);
gsl_odeiv_system sys_ode;
sys_ode.function  = fast_odes;
sys_ode.dimension = (size_t)(DIM);
sys_ode.params	  = Params;

// ----------------------------------- Daily Integration ------------------------------------ //
while (t_ode<t_end)	{

	status_ode = gsl_odeiv_evolve_apply(evol_ode, tol_ode, step_ode, &sys_ode, &t_ode, t_end, &h_init, y_ode);
/*
	for(sub=0; sub<num_sub; sub++){
		for (i=0;i<DIM;i++)	{
			if (y_ode[num_sub+i]>Params->INITS[j][sub])	{
				printf("y(%d) TOO LARGE!!\n",i);
				y_ode[num_sub+i]=S0[sub];
			}
		}
	}

}*/
// -------------------------------------- Clear Memory ----------------------------------------- //
gsl_odeiv_evolve_free(evol_ode);
gsl_odeiv_control_free(tol_ode);
gsl_odeiv_step_free(step_ode);

return (t_end);
}
}
