double DDEVF(void *Paramstuff, const gsl_rng *RandNumsPass, int year) 
{

STRUCTURE* Params;
Params = (STRUCTURE*) Paramstuff;

int sub; int d;

//-------------------------------------- PARAMETER DECLARATION -------------------------------------------//
int num_sub = Params->num_sub;
int MAX_T = Params->MAX_EPI_LENGTH;

int t = 0; int t_next; int t_0 = 0; int i;	int ii;			// time loop and index

double y_ode[num_sub*EPI_DIM]; 

double rand_nuR[num_sub][MAX_T];
double rand_nuF[num_sub][MAX_T]; 

double temp_now;  
double total_rainfall = 0.0; 
int rain_day;  

double DDtemp_now;  
double DD10[sub]; 

double nuF2;
double nuR2;

// --------------------------------------- STOCHASTIC FUNGAL PARAMS ----------------------------------------- //
for (sub = 0; sub < num_sub; sub++)
{
	for (d = 0; d <= MAX_T; d++)
	{	
		rand_nuR[sub][d] = gsl_ran_gaussian(RandNumsPass, Params->R_stoch[sub]); 
		rand_nuF[sub][d] = gsl_ran_gaussian(RandNumsPass, Params->F_stoch[sub]);
	}
}

// ------------------------------------- INITIALIZE MODEL PARAMETERS --------------------------------------- //
int day; int test_day; int EPI_FLAG = 0; int Flag4[MAX_SUBS];

day = 0;

for (sub = 0; sub < num_sub; sub++)
{
	Params->size_C[sub] = 1.0;
	Params->indexR[sub] = 0.0;	
	Flag4[sub] = 0;
}

double S[num_sub]; // susceptible insects
double V[num_sub]; // OB's (insects killed by virus) //Vcadaver
double C[num_sub]; // conidia (insects killed by fungus) //Fcadaver
double R[num_sub]; // resting spores (4th instars killed by fungus) //FRnext
double IV[num_sub]; // total virus infected insects
double IF[num_sub]; // total fungus infected insects
double E_V[num_sub][n+1]; // virus infected insects classes
double E_F[num_sub][m+1]; // fungus infected insect classes

// ----------------------------------- INFECTION START --------------------------------------- //

for (sub = 0; sub < num_sub; sub++)
{
	if (VERBOSE) printf("For sub: %i\n", sub);

	// R start
	DD10[sub] = 0.0;
	Params->R_start[sub] = 0.0;
	test_day = Params->S_start[sub];
	
	while (DD10[sub] <= DDstart)
	{
		DDtemp_now = Params->WEATHER[sub][test_day][3] - 10.0; // avet // why minus 10?
		if (DDtemp_now < 0.0) {DDtemp_now = 0.0;}
		DD10[sub] = DD10[sub] + DDtemp_now;		
		Params->R_start[sub]++;
		test_day++;
	}
	Params->R_start[sub] = Params->R_start[sub] + Params->S_start[sub];
	if (VERBOSE) printf("R start: %i\n", Params->R_start[sub]);	

	// R end
	DD10[sub] = 0.0;
	Params->R_end[sub] = 0.0;
	test_day = Params->S_start[sub];
	
	while (DD10[sub] <= DDstop)
	{
		DDtemp_now = Params->WEATHER[sub][test_day][3] - 10.0; // avet
		if (DDtemp_now < 0.0) {DDtemp_now = 0.0;}
		DD10[sub] = DD10[sub] + DDtemp_now;			
		Params->R_end[sub]++;
		test_day++;
	}
	Params->R_end[sub] = Params->R_end[sub] + Params->S_start[sub];
	if (VERBOSE) printf("R end: %i\n", Params->R_end[sub]);	

	// V start
	DD10[sub] = 0.0;
	Params->V_start[sub] = 0.0;
	test_day = Params->S_start[sub];

	while(DD10[sub] <= VDDstart){

		DDtemp_now = Params->WEATHER[sub][test_day][3] - 10.0; // avet
		if (DDtemp_now < 0.0) {DDtemp_now = 0.0;}
		DD10[sub] = DD10[sub] + DDtemp_now;			
		Params->V_start[sub]++;
		test_day++;
	}
	Params->V_start[sub] = Params->V_start[sub] + Params->S_start[sub];
	if (VERBOSE) printf("V start: %i\n", Params->V_start[sub]);	

	DD10[sub] = 0.0;
}

if (VERBOSE) printf("R and V timing set\n");	

// ---------------------------- LONG TERM VARIABLES ------------------------------- //
for (sub = 0; sub < num_sub; sub++)
{
	Params->INITS[sub] = Params->STATEVARS[1][sub];
	Params->INITV[sub] = Params->STATEVARS[2][sub];
	Params->INITR[sub] = Params->STATEVARS[3][sub];
}

// ----------------------------------------- INITIALIZE RESULTS ------------------------------------------- //
for (sub = 0; sub < num_sub; sub++)
{
	// Susceptible insects
	S[sub] = 0; 
	// Fungus infected insects
	for (ii = 1; ii <= m; ii++)
	{ 
		E_F[sub][ii] = 0;
	}
	IF[sub] = 0;
	// Virus infected insects
	for (ii = 1; ii <= n; ii++)
	{
			E_V[sub][ii] = 0;
	}
	IV[sub] = 0;
	// Conidia
	C[sub] = 0.0;
	// Resting spores at end of epizootic
	R[sub] = 0.0; 
	// OBs 
	V[sub] = 0.0;

	Params->Vkill[sub] = 0;
	Params->Fkill[sub] = 0;
}

// -------------------- LOOP THROUGH EPIZOOTIC DAYS -------------------------- // // WHEN DOING STOCHASTIC REPLICATES DON"T NEED TO RE-DO ALL SAVES TIME

for (day = Params->EARLIEST_EPI_START; day <= Params->LATEST_EPI_END; day++)
{

	t = day;
	t_next = day + 1;

	if (VERBOSE) printf("day = %i\n", day);
		
	//---------------- CHECK FOR DAILY EVENTS ---------//
	for (sub = 0; sub < num_sub; sub++)
	{		
		// S hatch
		if (day == Params->S_start[sub])
		{
			S[sub] = Params->INITS[sub] + S[sub];
			EPI_FLAG = 1;
			if (VERBOSE) printf("S start for sub %i\n", sub);
		}
		// Virus starts
		if (day == Params->V_start[sub])
		{
			V[sub] = Params->INITV[sub] + V[sub];
			Params->Vstartday[sub] = day;
			if (VERBOSE) printf("V start for sub %i\n", sub);
		}
		// Resting spore bloom
		if (day == Params->R_start[sub])
		{
			R[sub] = Params->INITR[sub];
			Params->Rstartday[sub] = day;
			if (VERBOSE) printf("R start for sub %i\n", sub);
		}
		// Resting spores done
		if (day == Params->R_end[sub])
		{
			R[sub] = 0;
			Params->Rendday[sub] = day;
			if (VERBOSE) printf("R end for sub %i\n", sub);
		}
		// End of epizootic
		if (day == Params->S_end[sub])
		{
			if (VERBOSE) printf("Epizootic over for sub %i\n", sub);

			S[sub] = 0; // is this right?
			V[sub] = 0;
			R[sub] = 0;
			C[sub] = 0;
			for (i = 1; i <= m; i++)
			{
				E_F[sub][i] = 0;
			}
			for (i = 1; i <= n; i++)
			{ 
				E_V[sub][i] = 0;
			} 
		}
		if (day > Params->LATEST_EPI_END) // done with ode solver
		{
			if (VERBOSE) printf("All epizootics finished for year.\n");
			EPI_FLAG = 0;
			break;
		}
	}
	
	//---------------------- LARVAL DISPERSAL ----------------------------//
	for (sub = 0; sub < num_sub; sub++)
	{
		if (day == Params->V_start[sub] + 7)
		{ 
			if (VERBOSE) printf("Larval dispersal\n");
			//unleash the cadavers
			for (sub = 0; sub < num_sub; sub++)
			{ 
				V[sub] = Params->INITV[sub];
			}

			if (larval_dispersal == 1)
			{ 
				int subout;
				int subin;
				int sub;

				double Vin[num_sub]; //cadavers
				double Vout[num_sub];

				double Sout[num_sub]; //susceptible insects
				double Sin[num_sub]; 

				//initialize dispersal array
				for (sub = 0; sub < num_sub; sub++){

					Sout[sub] = 0;
					Sin[sub] = 0;

					Vout[sub] = 0;
					Vin[sub] = 0;
				}

				//larvae disperse
				for (subout = 0; subout < num_sub; subout++)
				{
					Sout[subout] = exp(-Params->l_a[subout]*10) * S[subout];

					Vout[subout] += exp(-Params->l_a[subout]*10) * V[subout];
				}
				//some fraction arrive at another population
				for (subout = 0; subout < num_sub; subout++)
				{
					for(subin=0; subin<num_sub; subin++)
					{
						if(subin!=subout)
						{
							Sin[subin] = Sout[subout]*exp(-Params->l_a[subout]*Params->DISTANCE_MAT[subout][subin]);

							Vin[subin] += Vout[subout]*exp(-Params->l_a[subout]*Params->DISTANCE_MAT[subout][subin]);
						}
					}
				}
				for (sub = 0; sub < num_sub; sub++){ //update larval density

					S[sub] += (Sin[sub] - Sout[sub]);

					V[sub] += (Vin[sub] - Vout[sub]);
				}
			} 
		}	                        	
	}
		
	//--------------------------- UPDATE Y_ODE --------------------------------//
	for (sub = 0; sub < num_sub; sub++)
	{
		// Susceptible insects 
		y_ode[0 + EPI_DIM*sub] = S[sub];	
		// Fungus infected insects
		for (i = 1; i <= m; i++)
		{
			y_ode[i + EPI_DIM*sub] = E_F[sub][i];
		}
		// Virus infected insects
		for (i = 1; i <= n; i++)
		{ 
			y_ode[m+i + EPI_DIM*sub] = E_V[sub][i];
		} 
		// Conidia
		y_ode[m+n+1 + EPI_DIM*sub] = C[sub];	
		// Resting spores at end of epizootic
		y_ode[m+n+2 + EPI_DIM*sub] = R[sub]; 
		// OBs
		y_ode[m+n+3 + EPI_DIM*sub] = V[sub]; 
		// Vkill
		y_ode[m+n+4 + EPI_DIM*sub] = Params->Vkill[sub]; 
		// Fkill
		y_ode[m+n+5 + EPI_DIM*sub] = Params->Fkill[sub];

		if (VERBOSE){
			printf("Pre ode state vars for sub: %i\n", sub);
			printf("S: %lf C: %lf V: %lf R: %lf\n", S[sub], C[sub], V[sub], R[sub]);
		}

		//------------------ CALCULATE WEATHER DEPENDENT FUNGUS TRANSMISSION PARAMS ------//
		// Calculate degree day
		DDtemp_now = Params->WEATHER[sub][day][3] - 10.0;  //avet
		if (DDtemp_now < 0.0) {DDtemp_now = 0.0;}
		DD10[sub] = DD10[sub] + DDtemp_now;		

		// conidia production
		if(DD10[sub] >= (fourth_size) && Flag4[sub] == 0)
		{
			Params->size_C[sub] = 0.0;
			Params->indexR[sub] = 1;
			Params->lateinstar[sub] = y_ode[0 + EPI_DIM*sub];
			Flag4[sub] = 1;
			Params->lateinstarday[sub] = day;
		}	

		// nuF - RH
		nuF2 = specific_nuF * exp(RH_P * Params->WEATHER[sub][day][1]) * exp(rand_nuF[i][day]);   
		if (nuF2 > pow(8.0,8.0)) {nuF2 = pow(8.0,8.0);}
		Params->nuF[sub] = (DD10[sub] / fourth_size) * nuF2;

		// muF - T
		temp_now = Params->WEATHER[sub][day][3];  //avet
		Params->muF[sub] = specific_muF * exp(temp_P * temp_now);	
		if (Params->muF[sub] > pow(10.0,10.0)) {Params->muF[sub] = pow(10.0,10.0);}

		// nuR - R
		total_rainfall = 0.0;
		rain_day = day - beta - 1;
		for (rain_day = (day - beta - theta - 1); rain_day <= day - theta - 1; rain_day++) // last 10 days of rain
		{
			if (rain_day < 0){
				total_rainfall = 0.0;
			}
			else{
				total_rainfall = Params->WEATHER[sub][rain_day][0] + total_rainfall; 
			}
		}

		nuR2 = (rain_P / (1 + rain_P2 * exp(-rain_P3 * total_rainfall)) - rain_P / (rain_P2+1)) * exp(rand_nuR[sub][day]);  //exp(rand_nuR[(int)t]); ??
		if (nuR2 > pow(10.0,10.0)) {nuR2 = pow(10.0,10.0);}

		Params->nuR[sub] = (DD10[sub] / fourth_size) * nuR2;

	} //sub

	if (VERBOSE) printf("Daily weather parameters calculated, starting integration\n");

	//--------------------------- INTEGRATE --------------------------------//

	t = ODE_Solver(t, t_next, Params, y_ode); // t's might not work as is - 

	//--------------------------- UPDATE STATE VARIABLES --------------------------------//
	for (sub = 0; sub < num_sub; sub++)
	{
		// Susceptible insects
		S[sub] = y_ode[0 + EPI_DIM*sub];
		// Fungus infected insects
		for (i = 1; i <= m; i++) 
		{ 
			E_F[sub][i] = y_ode[i + EPI_DIM*sub];
			IF[sub] += E_F[sub][i];
		}
		// Virus infected insects
		for (i = 1; i <= n; i++)	
		{ 
			E_V[sub][i] = y_ode[m+i + EPI_DIM*sub];
			IV[sub] += E_V[sub][i];
		}
		IV[sub] = 0;
		IF[sub] = 0; 
		// Conidia
		C[sub] = y_ode[m+n+1 + EPI_DIM*sub];
		// Resting spores
		R[sub] = y_ode[m+n+2 + EPI_DIM*sub];
		// OBs
		V[sub] = y_ode[m+n+3 + EPI_DIM*sub];
		Params->Vkill[sub] = y_ode[m+n+4 + EPI_DIM*sub];
		Params->Fkill[sub] = y_ode[m+n+5 + EPI_DIM*sub];

		if (VERBOSE){
			printf("Post ode state vars for sub: %i\n", sub);
			printf("S: %lf C: %lf V: %lf R: %lf\n", S[sub], C[sub], V[sub], R[sub]);
		}
	}
	
	//------------------------PRINT DAILY OUTPUT--------------------
	for (sub = 0; sub < num_sub; sub++) 
	{	
		Params->SINGLE_EPI_MODEL[year][sub][day][0] = S[EPI_DIM*sub]; //Saving daily count uninfected S 
		Params->SINGLE_EPI_MODEL[year][sub][day][1] = IV[EPI_DIM*sub]; //Saving daily count infected V 
		Params->SINGLE_EPI_MODEL[year][sub][day][2] = IF[EPI_DIM*sub]; //Saving daily count infected F
		
		if (Params->PRINT_INTRA)
		{
			fprintf(fpintra, "%i %i %i %e %e %e\n", year, sub, day, Params->SINGLE_EPI_MODEL[year][sub][day][0], Params->SINGLE_EPI_MODEL[year][sub][day][1], Params->SINGLE_EPI_MODEL[year][sub][day][2]);
		}
	}
	//getc(stdin);
}

//------------------------UPDATE LONG-TERM PARAMS--------------------
for (sub = 0; sub < num_sub; sub++)
{
	Params->SusEnd[sub] = S[sub];
	Params->InfFungusNext[sub] = R[sub];
	Params->InfVirusNext[sub] = Params->Vkill[sub] + IV[sub];
}

return 0;
}