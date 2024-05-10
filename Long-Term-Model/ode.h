// --------------------------------Begin ODE system of White model --------------------------------------------//
int odes(double t, const double y[][EPI_DIM], double dydt[][EPI_DIM],void *Paramstuff)
{
STRUCTURE* Params;
Params = (STRUCTURE*) Paramstuff;

//INDEXING
int i;
int num_sub = Params->num_sub;
int sub;

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
for (sub = 0; sub < num_sub; sub++) // IS THIS RIGHT?
{
	S0[sub] = Params->INITS[sub]; 
	R[sub] = Params->INITR[sub];
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
		Cout[subout] = exp(-Params->c_a[subout]*10) * y[subout][m+n+1]; //r = 10m

		for(subin = 0; subin < num_sub; subin++){

			if(subout != subin){

				Cin[subin] += Cout[subout] * exp(-Params->c_a[subout]*Params->DISTANCE_MAT[subout][subin]); //UPDATE DISTANCE

			}
		} 
	}
	for(sub=0; sub<num_sub; sub++){ //update conidia density

		netC[sub] += (Cin[sub] - Cout[sub]);
		//netC[sub] = 0; //TEST, TURNING DISPERSAL OFF

	}
}

for (sub = 0; sub < num_sub; sub++)
{
	//----------- Susceptible ---------
	dydt[sub][0]  = -y[sub][0] * (nuF[sub] * y[sub][m+n+1] + nuR[sub] * R[sub]) - y[sub][0] * nuV * y[sub][m+n+3] * pow((y[sub][0] / S0[sub]), squareCVV);

	//-------- Fungus Infected ------
	dydt[sub][1]  = nuF[sub] * y[sub][m+n+1]*y[sub][0] + nuR[sub] * R[sub] * y[sub][0] - m * lambdaF * y[sub][1]; 
	for (i = 2; i <= m; i++)
	{
		dydt[sub][i] = m * lambdaF * (y[sub][i-1] - y[sub][i]);
	}

	//--------- Virus Infected -------
	dydt[sub][m+1] = y[sub][0] * nuV * y[sub][m+n+3] * pow((y[sub][0] / S0[sub]), squareCVV) - n * lambdaV * y[sub][m+1];

	for (i = 2; i <= n; i++)
	{
		dydt[sub][m+i] = n * lambdaV * (y[sub][m+(i-1)] - y[sub][m+i]);

	}
	//--------- Conidia ----------
	dydt[sub][m+n+1] = m * lambdaF * y[sub][m] * Params->size_C[sub] - muF[sub] * y[sub][m+n+1] + netC[sub];

	//---------- Resting Spores --------
	dydt[sub][m+n+2] = Params->indexR[sub] * m * lambdaF * y[sub][m];

	//------------ OBs-----------
	dydt[sub][m+n+3] = n * lambdaV * y[sub][m+n] - muV * y[sub][m+n+3]; 

	//---------- Vkill ---------
	dydt[sub][m+n+4] = n * lambdaV * y[sub][m+n];

	//--------- Fkill ---------
	dydt[sub][m+n+5] = m * lambdaF * y[sub][m];
}

return GSL_SUCCESS;
}


// ------------------------------------------  ODE Solver  ----------------------------------------------- //
double ODE_Solver(double t_ode, double t_end, void *Paramstuff, double **y_ode) // MAKE Y_ODE GLOBAL? THEN YOU CAN PASS EACH ROW BUT IT WILL HAVE ACCESS TO ALL ROWS?
{

	STRUCTURE* Params;
	Params = (STRUCTURE*) Paramstuff;

	int i; int sub;
	int status_ode;
	double h_init = 1.0e-5;
	int num_sub = Params->num_sub;

	double (*p)[EPI_DIM];

	const gsl_odeiv_step_type *solver_ode	= gsl_odeiv_step_rkf45; // Runge-Kutta Fehlberg (4, 5)


	for (sub = 0; sub < num_sub; sub++)
	{

		// returns pointer to a newly allocated instance of a stepping function of type 'solver_ode' for a system of DIM dimensions //
		gsl_odeiv_step *step_ode	= gsl_odeiv_step_alloc(solver_ode, EPI_DIM);

		// adaptive step size 
		// D_i = eps_abs + eps_rel * (a_y |y_i| + a_dydt h |y'_i|)
		// original: gsl_odeiv_control *tol_ode	= gsl_odeiv_control_standard_new(1.0e-10, 1.0e-5, 1.0, 0.2)
		gsl_odeiv_control *tol_ode	= gsl_odeiv_control_standard_new(1e-6, 1e-6, 1.0, 0.2); // eps_abs, eps_rel, a_y, a_dydt
		gsl_odeiv_evolve *evol_ode	= gsl_odeiv_evolve_alloc(EPI_DIM);

		gsl_odeiv_system sys_ode;
		sys_ode.function  = odes;
		sys_ode.dimension = (size_t)(EPI_DIM);
		sys_ode.params	  = Params;

		while (t_ode < t_end) // run for a single day
		{

			p = &y_ode[sub]; // pointer to row for sub in y_ode

			status_ode = gsl_odeiv_evolve_apply(evol_ode, tol_ode, step_ode, &sys_ode, &t_ode, t_end, &h_init, p);

			for (i = 0; i <= EPI_DIM; i++)
			{
				if (p[i] < 0)
				{
					p[i] = 0;
				}
			}
		}
		
		gsl_odeiv_evolve_free(evol_ode);
		gsl_odeiv_control_free(tol_ode);
		gsl_odeiv_step_free(step_ode);

		// compile each subpop into collective array // MIGHT NOT NEED THIS
		/*
		for (i = 0; i < EPI_DIM; i++)
		{
			Params->ode_output[sub][t_ode][i] = y_ode[i];
		}*/
		
	}

	return (t_end); 
}