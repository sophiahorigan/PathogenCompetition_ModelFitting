// --------------------------------Begin ODE system of White model --------------------------------------------//
int odes(double t, const double y[], double dydt[],void *Paramstuff)
{
STRUCTURE* Params;
Params = (STRUCTURE*) Paramstuff;

//INDEXING
int j = Params->j; //dataset
int i;
int num_sub = Params->numsub;
int sub;

//FIXED PARAMETERS
double nuV 		= Params->nuV; 	//virus transmission
double muV		= Params->muV; 	//virus decay
double squareCVV = Params->CV*Params->CV; //heterogeneity

//WEATHER PARAMS
double nuR[num_sub];
double muF[num_sub];
double nuF[num_sub];

for (sub = 0; sub < num_sub; sub++)
{
	nuF[sub] = Params->nuF[sub];	//conidia transmission
	muF[sub] = Params->muF[sub];	//conidia decay
	nuR[sub] = Params->nuR[sub]; 	//resting spore transmission
}

//state variables
double S0[num_sub];
double R[num_sub];

// Assign init R
for (i=0; i<num_sub; i++)
{
	S0[i] = Params->STATEVARS[1][i]; //SHOULD THIS BE UPATED EACH TIME? OR FIXED FROM DAY 1? (IN WHICH CASE PUT IT IN MAIN.C)
	R[i] = Params->STATEVARS[2][i];
}

int subout; //indexing
int subin; //indexing
double Cout[num_sub];
double Cin[num_sub];
double netC[num_sub];

for(sub=0; sub<num_sub; sub++)
{
	Cout[sub] = 0;
	Cin[sub] = 0;
	netC[sub] = 0;
}
//printf("conidia dispersal = %i\n", conidia_dispersal);
//-------------------------------------- CONIDIA DISPERSAL -------------------------------------------//
if(conidia_dispersal == 1){ 

	for(subout = 0; subout < num_sub; subout++){ //calculate net dispersal
		
		//SCALE OF MIGRATION
		Cout[subout] = exp(-c_a[subout]*10) * y[subout][m+n+1]; //r = 10m

		for(subin = 0; subin < num_sub; subin++){

			if(subout != subin){

				Cin[subin] += Cout[subout] * exp(-c_a[subout]*Params->DISTANCE[j][subout][subin]); //UPDATE DISTANCE

			}
		} 
	}
	for(sub=0; sub<num_sub; sub++){ //update conidia density

		netC[sub] += (Cin[sub] - Cout[sub]);
		//netC[sub] = 0; //TEST, TURNING DISPERSAL OFF

	}
}

for(sub=0; sub<num_sub; sub++){

	//*******************SUSCEPTIBLE*********************
	dydt[sub][0]  = -y[sub][0] * (nuF[sub] * y[sub][m+n+1] + nuR[sub] * R[sub]) - y[sub][0] * nuV * y[sub][m+n+2] * pow((y[sub][0] / S0[sub]), squareCVV);

	//***********************FUNGUS-INFßECTED**********************
	dydt[sub][1]  = nuF[sub] * y[sub][m+n+1]*y[sub][0] + nuR[sub] * R[sub] * y[sub][0] - m * lambdaF * y[sub][1]; 

	for (i = 2; i <= m; i++)
	{
		dydt[sub][i] = m * lambdaF * (y[sub][i-1] - y[sub][i]);
	}

	//**********************VIRUS-INFECTED************************
	dydt[sub][m+1] = y[sub][0] * nuV * y[sub][m+n+2] * pow((y[sub][0] / S0[sub]), squareCVV) - n * lambdaV * y[sub][m+1];

	for (i = 2; i <= n; i++)
	{
		dydt[sub][m+i] = n * lambdaV * (y[sub][m+(i-1)] - y[sub][m+i]);

	}
	//**********************CONIDIA*****************
	dydt[sub][m+n+1] = m * lambdaF * y[sub][m] - muF[sub] * y[sub][m+n+1] + netC[sub];

	//*************************OBS***********************
	dydt[sub][m+n+2] = n * lambdaV * y[sub][m+n] - muV * y[sub][m+n+2]; 
}

return GSL_SUCCESS;
}


// ------------------------------------------  ODE Solver  ----------------------------------------------- //
// --- CAN YOU PASS A 2D ARRAY INTO AN ODE SOLVER? OR DO I NEED TO LOOP THROUGH SOLVING FOR EACH SUBPOP? ---//
double ODE_Solver(double t_ode, double t_end, void *Paramstuff, double *y_ode)
{
int i;
int status_ode;
double h_init = 1.0e-5;
int DIM = 320; //WHAT IS THIS? ??DIM of y_ode I think

STRUCTURE* Params;
Params = (STRUCTURE*) Paramstuff;
int num_sub = Params->numsub;

const gsl_odeiv_step_type *solver_ode	= gsl_odeiv_step_rkf45; // Runge-Kutta Fehlberg (4, 5)

// returns pointer to a newly allocated instance of a stepping function of type 'solver_ode' for a system of DIM dimensions //
gsl_odeiv_step *step_ode	= gsl_odeiv_step_alloc(solver_ode, DIM);

// adaptive step size 
// D_i = eps_abs + eps_rel * (a_y |y_i| + a_dydt h |y'_i|)
// original: gsl_odeiv_control *tol_ode	= gsl_odeiv_control_standard_new(1.0e-10, 1.0e-5, 1.0, 0.2)
gsl_odeiv_control *tol_ode	= gsl_odeiv_control_standard_new(1e-6, 1e-6, 1.0, 0.2); // eps_abs, eps_rel, a_y, a_dydt
gsl_odeiv_evolve *evol_ode	= gsl_odeiv_evolve_alloc(DIM);

gsl_odeiv_system sys_ode;
sys_ode.function  = odes;
sys_ode.dimension = (size_t)(DIM);
sys_ode.params	  = Params;
//double yerr[DIM];

// ----------------------------------- Integrate Over Time ------------------------------------ //
while (t_ode < t_end)
{
	status_ode = gsl_odeiv_evolve_apply(evol_ode, tol_ode, step_ode, &sys_ode, &t_ode, t_end, &h_init, y_ode);

	for (i = 0; i <= DIM; i++)
	{
		if (y_ode[i] > 0)
		{
			// keep y_ode as is
		}
		else
		{
			//printf("y(%d) NEGATIVE or not a number\n",i);
			y_ode[i] = 0;
		}
	}

}
// -------------------------------------- Clear Memory ----------------------------------------- //
gsl_odeiv_evolve_free(evol_ode);
gsl_odeiv_control_free(tol_ode);
gsl_odeiv_step_free(step_ode);

return (t_end);
}