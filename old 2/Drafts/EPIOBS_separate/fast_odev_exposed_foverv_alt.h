// --------------------------------Begin ODE system of White model --------------------------------------------//
int fast_odes(double t, const double y[], double dydt[],void *Paramstuff)
{
STRUCTURE* Params;
Params = (STRUCTURE*) Paramstuff;

//variables constant across treatments, priors from CK 
double nuV		= Params->PARS[2]; //virus transmission
double nuF		= Params->nuF;	//conidia transmission	//Params->PARS[3];
double nuR		= Params->nuR;	//resting spore transmission
double muV		= 0.39; //virus decay
double muF		= Params->muF;  //CK//  Using the site-specific muF that was loaded up in DDEVF14
double lambdaV = 1/exposetime;
double lambdaF=Params->PARS[18];		// decay rate of E_V and E_F
VFPass=exposetime-1/Params->PARS[18];

double size_C		= Params->size_C;  //Scaling effect of size on susceptibility over time.
double indexR = Params->indexR;
double indexV = Params->indexV;

//exposed classes
int m = Params->PARS[9]; //fungus
int n = Params->PARS[8];  //virus
int n1=(VFPass/exposetime)*Params->PARS[8];    //virus exposed that can be taken over by fungus
int n2=n-n1;                //The number of the first group of exposed classes to virus

//state variables
//double S[7] = {Params->INITS[0], Params->INITS[0], Params->INITS[0], Params->INITS[0], Params->INITS[0], Params->INITS[0], Params->INITS[0]}; //SH NEED TO CHANGE
double S = Params->INITS[0];
//double C = y[m+n+1];
double R  = Params->POPS[3];


//double Finf = y[0]*nuF*C;
//double Rinf = y[0]*nuF*R;


//------DISPERSAL TO DO-------//
// 1. make each equation x4 
	// a. make sure y_ode can hold it (dim)
// 2. pull conidia net dispersal from PARAMS and add to each conidia equation (from DDEVF)

int num_tmts = 4;
int tmt;
int i;

// ------------------------------------------ ODEs -------------------------------------------- //

int tmt_index[num_tmts];
int max_class = m+n+6+m;
tmt_index[0] = 0; //treatment 1 index addition is zero
for(tmt=1; tmt<num_tmts; tmt++){	//create tmt array 
	tmt_index[tmt] = tmt_index[tmt-1]+ max_class; //SH can maybe multiply 
}

for(tmt=0; tmt<num_tmts; tmt++){
	dydt[0+tmt_index[tmt]]  = -y[0+tmt_index[tmt]]*(nuF*y[m+n+1+tmt_index[tmt]] + nuR*R)-y[0+tmt_index[tmt]]*nuV*y[m+n+3+tmt_index[tmt]]*pow((y[0+tmt_index[tmt]]/S),squareCVV);
	//printf("%e\t %e\t %e\t %e\t %e\n", y[0+tmt_index[tmt]], y[m+n+1+tmt_index[tmt]], y[0+tmt_index[tmt]], y[m+n+3+tmt_index[tmt]], y[0+tmt_index[tmt]]/S);
	dydt[1+tmt_index[tmt]]  = nuF*y[m+n+1+tmt_index[tmt]]*y[0+tmt_index[tmt]] + nuR*R*y[0+tmt_index[tmt]] - m*lambdaF*y[1+tmt_index[tmt]];
	for(i=2; i <= m; i++){
		dydt[i+tmt_index[tmt]]=m*lambdaF*(y[i-1+tmt_index[tmt]] -y[i+tmt_index[tmt]]);
	}

	//First group of classes exposed to virus, which can be infected by fungus and going into exposed classes for fungus
	dydt[m+1+tmt_index[tmt]] = y[0+tmt_index[tmt]]*nuV*y[m+n+3+tmt_index[tmt]]*pow((y[0+tmt_index[tmt]]/S),squareCVV)-n*lambdaV*y[m+1+tmt_index[tmt]]-y[m+1+tmt_index[tmt]]*(nuF*y[m+n+1+tmt_index[tmt]] + nuR*R)*VFSus;
	for (i=2;i<=n1;i++){
		dydt[m+i+tmt_index[tmt]]=n*lambdaV*(y[m+i-1+tmt_index[tmt]]-y[m+i+tmt_index[tmt]])-y[m+i+tmt_index[tmt]]*(nuF*y[m+n+1+tmt_index[tmt]] + nuR*R)*VFSus;
	}

	//Second group of classes exposed to virus, which cannot be infected by fungus, and generate virus for the next epizootic
	dydt[m+n1+1+tmt_index[tmt]]=n*lambdaV*y[m+n1+tmt_index[tmt]]-n*lambdaV*y[m+n1+1+tmt_index[tmt]];
	for (i=2;i<=n2;i++){
		dydt[m+n1+i+tmt_index[tmt]]=n*lambdaV*(y[m+n1+i-1+tmt_index[tmt]]-y[m+n1+i+tmt_index[tmt]]);
	}
	dydt[m+n+1+tmt_index[tmt]] = m*lambdaF*(y[m+tmt_index[tmt]]+(1-coinf_V)*y[m+n+6+m+tmt_index[tmt]])*size_C - muF*y[m+n+1+tmt_index[tmt]];  //Conidia class!  Transission from final exposed class (m) to conidia class (m+1)
	dydt[m+n+2+tmt_index[tmt]] = indexR*m*lambdaF*(y[m+tmt_index[tmt]]+(1-coinf_V)*y[m+n+6+m+tmt_index[tmt]]);
	dydt[m+n+3+tmt_index[tmt]] = n*lambdaV*y[m+n+tmt_index[tmt]]+m*lambdaF*y[m+n+6+m+tmt_index[tmt]]*coinf_V-muV*y[m+n+3+tmt_index[tmt]];  //Class of cadavers infected by virus
	dydt[m+n+4+tmt_index[tmt]] = n*lambdaV*y[m+n+tmt_index[tmt]]+m*lambdaF*y[m+n+6+m+tmt_index[tmt]]*coinf_V;
	dydt[m+n+5+tmt_index[tmt]] = m*lambdaF*(y[m+tmt_index[tmt]]+(1-coinf_V)*y[m+n+6+m+tmt_index[tmt]]);
	dydt[m+n+6+tmt_index[tmt]] = indexV*(n*lambdaV*y[m+n+tmt_index[tmt]]+m*lambdaF*y[m+n+6+m+tmt_index[tmt]]*coinf_V);

	//Recording the hosts already infected with virus and taken over by the fungus
	dydt[m+n+6+1+tmt_index[tmt]] = (nuF*y[m+n+1+tmt_index[tmt]] + nuR*R)*y[m+1+tmt_index[tmt]]*VFSus- m*lambdaF*y[m+n+6+1+tmt_index[tmt]];
	for (i=2;i<=n1;i++){
		dydt[m+n+6+1+tmt_index[tmt]] += (nuF*y[m+n+1+tmt_index[tmt]] + nuR*R)*y[m+i+tmt_index[tmt]]*VFSus;
	}
	for(i=2; i <= m; i++){
		dydt[m+n+6+i+tmt_index[tmt]]=m*lambdaF*(y[m+n+6+i-1+tmt_index[tmt]] -y[m+n+6+i+tmt_index[tmt]]);
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

int DIM = 4*(Params->PARS[9]+Params->PARS[8]+4+2+1+Params->PARS[9]); //SH multiplied by 4 to hold all equations for each treatment

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
			//printf("NEGATIVE OR NAN y_ode[%i]=%e\n", i, y_ode[i]);				{
			printf("y(%d) NEGATIVE or not a number\n",i);
			y_ode[i]=0;
		}
		if (i==Params->PARS[9]+Params->PARS[8]+3 || i==Params->PARS[9]+Params->PARS[8]+1){

		}
		else{
		if (y_ode[i]>Params->INITS[0])	{
			printf("y(%d) TOO LARGE!!\n",i);
			//printf("TOO LARGE y_ode[%i]=%e\n", i, y_ode[i]);	
			y_ode[i]=Params->INITS[0];
		}
		}
	}

}
// -------------------------------------- Clear Memory ----------------------------------------- //
gsl_odeiv_evolve_free(evol_ode);
gsl_odeiv_control_free(tol_ode);
gsl_odeiv_step_free(step_ode);

return (t_end);
}


