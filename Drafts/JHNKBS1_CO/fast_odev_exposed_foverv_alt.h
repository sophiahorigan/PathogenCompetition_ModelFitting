// --------------------------------Begin ODE system of White model --------------------------------------------//
int fast_odes(double t, const double y[], double dydt[],void *Paramstuff)
{
STRUCTURE* Params;
Params = (STRUCTURE*) Paramstuff;

int m = Params->PARS[9];  //CK//  the number of exposed classes to fungus.  adjustable and fit.  yay!
int n = Params->PARS[8];             //JL//  the number of exposed classes to virus

double C		= y[m+n+1];
double nuV		= Params->PARS[2];		//CK//  FOR FUNGUS ONLY MODEL. NO VIRUS INFECTION
double nuF		= Params->nuF;		//Params->PARS[3];
double nuR		= Params->nuR;	//param for nuR after it includes rainfall
double muV		= 0.39;		//CK// FUNGUS ONLY MODEL.  MAKE SURE DECAY IS ZERO SO NEGATIVE VIRUS DOESN'T HAPPEN!!
double lambdaV = 1/exposetime;
double lambdaF=Params->PARS[18];		// decay rate of E_V and E_F
VFPass=exposetime-1/Params->PARS[18];

int n1=(VFPass/exposetime)*Params->PARS[8];    //The number of the first group of exposed classes to virus
int n2=n-n1;                //The number of the first group of exposed classes to virus
//printf("%lf,%d,%d\n",VFPass,n1,n2);
//double rsquareCVV=1/1.5;
//double squareCVV=1.5;

double size_C		= Params->size_C;  //Scaling effect of size on susceptibility over time.
double indexR = Params->indexR;
double indexV = Params->indexV;

double muF		= Params->muF;  //CK//  Using the site-specific muF that was loaded up in DDEVF14

int i;

double S0 = Params->INITS[0];
double R  = Params->POPS[3];

double Finf = y[0]*nuF*C;
double Rinf = y[0]*nuF*R;


// ------------------------------------------ ODEs -------------------------------------------- //
//if		(y[0]<.000001)	dydt[0]=0;
//else

dydt[0]  = -y[0]*(nuF*y[m+n+1] + nuR*R)-y[0]*nuV*y[m+n+3]*pow((y[0]/S0),squareCVV);
dydt[1]  = nuF*y[m+n+1]*y[0] + nuR*R*y[0] - m*lambdaF*y[1];
//for (i=1;i<=n1;i++){
//    dydt[1] += (nuF*y[m+n+1] + nuR*R)*y[m+i]*VFSus;
//}

for(i=2; i <= m; i++){
	dydt[i]=m*lambdaF*(y[i-1] -y[i]);
}


//First group of classes exposed to virus, which can be infected by fungus and going into exposed classes for fungus
dydt[m+1] = y[0]*nuV*y[m+n+3]*pow((y[0]/S0),squareCVV)-n*lambdaV*y[m+1]-y[m+1]*(nuF*y[m+n+1] + nuR*R)*VFSus;
for (i=2;i<=n1;i++){
    dydt[m+i]=n*lambdaV*(y[m+i-1]-y[m+i])-y[m+i]*(nuF*y[m+n+1] + nuR*R)*VFSus;
}

//Second group of classes exposed to virus, which cannot be infected by fungus, and generate virus for the next epizootic
dydt[m+n1+1]=n*lambdaV*y[m+n1]-n*lambdaV*y[m+n1+1];
for (i=2;i<=n2;i++){
    dydt[m+n1+i]=n*lambdaV*(y[m+n1+i-1]-y[m+n1+i]);
}
dydt[m+n+1] = m*lambdaF*(y[m]+(1-coinf_V)*y[m+n+6+m])*size_C - muF*y[m+n+1];  //Conidia class!  Transission from final exposed class (m) to conidia class (m+1)
dydt[m+n+2] = indexR*m*lambdaF*(y[m]+(1-coinf_V)*y[m+n+6+m]);
dydt[m+n+3] = n*lambdaV*y[m+n]+m*lambdaF*y[m+n+6+m]*coinf_V-muV*y[m+n+3];  //Class of cadavers infected by virus
dydt[m+n+4] = n*lambdaV*y[m+n]+m*lambdaF*y[m+n+6+m]*coinf_V;
dydt[m+n+5] = m*lambdaF*(y[m]+(1-coinf_V)*y[m+n+6+m]);
dydt[m+n+6] = indexV*(n*lambdaV*y[m+n]+m*lambdaF*y[m+n+6+m]*coinf_V);

//Recording the hosts already infected with virus and taken over by the fungus
dydt[m+n+6+1] = (nuF*y[m+n+1] + nuR*R)*y[m+1]*VFSus- m*lambdaF*y[m+n+6+1];
for (i=2;i<=n1;i++){
    dydt[m+n+6+1] += (nuF*y[m+n+1] + nuR*R)*y[m+i]*VFSus;
}
for(i=2; i <= m; i++){
	dydt[m+n+6+i]=m*lambdaF*(y[m+n+6+i-1] -y[m+n+6+i]);
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

//int DIM = Params->PARS[9]+3;
int DIM = Params->PARS[9]+Params->PARS[8]+4+2+1+Params->PARS[9];

//printf("ODE_solver:\n parm 2=%f parm 3=%f parm 4=%f parm 5=%f parm 6=%f\n",
//	   Params->PARS[2],Params->PARS[3],Params->PARS[4],Params->PARS[5],Params->PARS[6]);
//getc(stdin);

const gsl_odeiv_step_type *solver_ode	= gsl_odeiv_step_rkf45; // Runge-Kutta Fehlberg (4, 5)
//const gsl_odeiv_step_type *solver_ode = gsl_odeiv_step_rk4;

// returns pointer to a newly allocated instance of a stepping function of type 'solver_ode' for a system of DIM dimensions //
gsl_odeiv_step *step_ode	= gsl_odeiv_step_alloc(solver_ode, DIM);

gsl_odeiv_control *tol_ode	= gsl_odeiv_control_standard_new(1.0e-10, 1.0e-5, 1.0, 0.2);
gsl_odeiv_evolve *evol_ode	= gsl_odeiv_evolve_alloc(DIM);

gsl_odeiv_system sys_ode;
sys_ode.function  = fast_odes;
sys_ode.dimension = (size_t)(DIM);
sys_ode.params	  = Params;

//double y_err[DIM]; double dydt_in[DIM];	double dydt_out[DIM];

// ----------------------------------- Integrate Over Time ------------------------------------ //
while (t_ode<t_end)	{
	status_ode = gsl_odeiv_evolve_apply(evol_ode, tol_ode, step_ode, &sys_ode, &t_ode, t_end, &h_init, y_ode);

	for (i=0;i<DIM;i++)	{
		if (y_ode[i]>0)		{
			// keep y_ode as is
		}
		else				{
			//printf("y(%d) NEGATIVE or not a number\n",i);
			y_ode[i]=0;
		}
		if (i==Params->PARS[9]+Params->PARS[8]+3 || i==Params->PARS[9]+Params->PARS[8]+1){

		}
		else{
		if (y_ode[i]>Params->INITS[0])	{
			printf("y(%d) TOO LARGE!!\n",i);
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


