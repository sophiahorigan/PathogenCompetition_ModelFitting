// --------------------------------Begin ODE system of White model --------------------------------------------//
int odes(double t, const double y[], double dydt[],void *Paramstuff)
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

	// conidia dispersal // TO DO 
	/*
	double c1 = ode_parms.c1;

	double dx = 1.0 / (double) ode_parms.m;
	double speed = c1 * (double) ode_parms.m * (double) ode_parms.m / 3.0;

	int i, j, n1, n2, n3, n4, curr;
	int n_ngbrs = 4;
	int ngbr_ids[n_ngbrs];
	double ngbr_sum;
	*/

	for (sub = 0; sub < num_sub; sub++)
	{
		if (conidia_dispersal == 1)
		{	
			/*
			// Figure out neighbor IDs 
			//n1 (above)
			ngbr_ids[0] = n1 = sub - Params->grid_length;
			//n2 (left)
			if (modulo(sub, Params->grid_length == 1)){ //edge
				ngbr_ids[1] = n2 = NAN; // will this work
			}
			else{
				ngbr_ids[1] = n2 = sub - 1;
			}
			//n3 (right)
			if (modulo(sub, Params->grid_length == 0)){ //edge
				ngbr_ids[2] = n3 = NAN; // will this work
			}
			else{
				ngbr_ids[2] = n3 = sub + 1;
			}
			//n4 (below)
			ngbr_ids[3] = n4 = sub + Params->grid_length; 

			// ------------------------------------------ ODEs -------------------------------------------- //
			ngbr_sum = 0.0;

			for (i = 0; i < n_ngbrs; i++)
			{
				ngbr_sum += y[ngbr_ids[i]];
			}

			dydt[m+n+1 + EPI_DIM*sub]  = speed * ngbr_sum / 4 - y[sub] * (mu + speed);	 //dP/dt // how do I combine this with the other ode for conidia? // just add it?
			*/
		}

		//----------- Susceptible ---------
		dydt[0 + EPI_DIM*sub]  = -y[0 + EPI_DIM*sub] * (nuF[sub] * y[m+n+1 + EPI_DIM*sub] + nuR[sub] * R[sub]) - y[0 + EPI_DIM*sub] * nuV * y[m+n+3 + EPI_DIM*sub] * pow((y[0 + EPI_DIM*sub] / S0[sub]), squareCVV);

		//-------- Fungus Infected ------
		dydt[1 + EPI_DIM*sub]  = nuF[sub] * y[m+n+1 + EPI_DIM*sub]*y[0 + EPI_DIM*sub] + nuR[sub] * R[sub] * y[0 + EPI_DIM*sub] - m * lambdaF * y[1 + EPI_DIM*sub]; 
		for (i = 2; i <= m; i++)
		{
			dydt[i + EPI_DIM*sub] = m * lambdaF * (y[i-1 + EPI_DIM*sub] - y[i + EPI_DIM*sub]);
		}

		//--------- Virus Infected -------
		dydt[m+1 + EPI_DIM*sub] = y[0 + EPI_DIM*sub] * nuV * y[m+n+3 + EPI_DIM*sub] * pow((y[0 + EPI_DIM*sub] / S0[sub]), squareCVV) - n * lambdaV * y[m+1 + EPI_DIM*sub];

		for (i = 2; i <= n; i++)
		{
			dydt[m+i + EPI_DIM*sub] = n * lambdaV * (y[m+(i-1) + EPI_DIM*sub] - y[m+i + EPI_DIM*sub]);

		}
		//--------- Conidia ----------
		dydt[m+n+1 + EPI_DIM*sub] = m * lambdaF * y[m + EPI_DIM*sub] * Params->size_C[sub] - muF[sub] * y[m+n+1 + EPI_DIM*sub];

		//---------- Resting Spores --------
		dydt[m+n+2 + EPI_DIM*sub] = Params->indexR[sub] * m * lambdaF * y[m + EPI_DIM*sub];

		//------------ OBs-----------
		dydt[m+n+3 + EPI_DIM*sub] = n * lambdaV * y[m+n + EPI_DIM*sub] - muV * y[m+n+3 + EPI_DIM*sub]; 

		//---------- Vkill ---------
		dydt[m+n+4 + EPI_DIM*sub] = n * lambdaV * y[m+n + EPI_DIM*sub];

		//--------- Fkill ---------
		dydt[m+n+5 + EPI_DIM*sub] = m * lambdaF * y[m + EPI_DIM*sub];
	}

return GSL_SUCCESS;
}


// ------------------------------------------  ODE Solver  ----------------------------------------------- //
double ODE_Solver(double t_ode, double t_end, void *Paramstuff, double *y_ode) 
{

	STRUCTURE* Params;
	Params = (STRUCTURE*) Paramstuff;

	int i; int sub;
	int status_ode;
	double h_init = 1.0e-5;
	int num_sub = Params->num_sub;

	int odeDIM = EPI_DIM*num_sub;

	const gsl_odeiv_step_type *solver_ode	= gsl_odeiv_step_rkf45; // Runge-Kutta Fehlberg (4, 5)

	// returns pointer to a newly allocated instance of a stepping function of type 'solver_ode' for a system of DIM dimensions //
	gsl_odeiv_step *step_ode	= gsl_odeiv_step_alloc(solver_ode, odeDIM);

	// adaptive step size 
	// D_i = eps_abs + eps_rel * (a_y |y_i| + a_dydt h |y'_i|)
	// original: gsl_odeiv_control *tol_ode	= gsl_odeiv_control_standard_new(1.0e-10, 1.0e-5, 1.0, 0.2)
	gsl_odeiv_control *tol_ode	= gsl_odeiv_control_standard_new(1e-6, 1e-6, 1.0, 0.2); // eps_abs, eps_rel, a_y, a_dydt
	gsl_odeiv_evolve *evol_ode	= gsl_odeiv_evolve_alloc(odeDIM);

	gsl_odeiv_system sys_ode;
	sys_ode.function  = odes;
	sys_ode.dimension = (size_t)(odeDIM);
	sys_ode.params	  = Params;

	while (t_ode < t_end) // run for a single day
	{

		status_ode = gsl_odeiv_evolve_apply(evol_ode, tol_ode, step_ode, &sys_ode, &t_ode, t_end, &h_init, y_ode);

		for (i = 0; i <= odeDIM; i++)
		{
			if (y_ode[i] < 0)
			{
				y_ode[i] = 0;
			}
		}
		
	}
	
	gsl_odeiv_evolve_free(evol_ode);
	gsl_odeiv_control_free(tol_ode);
	gsl_odeiv_step_free(step_ode);
		

	return (t_end); 
}