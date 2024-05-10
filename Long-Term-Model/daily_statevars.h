double DDEVF(void *Paramstuff, double *RandNumsPass, int year) //SH DOES save into array

{

STRUCTURE* Params;
Params = (STRUCTURE*) Paramstuff;

int sub;

//-------------------------------------- PARAMETER DECLARATION -------------------------------------------//
int num_sub = Params->num_sub;
int MAX_T = Params->MAX_EPI_LENGTH;

//--- need to update to get cc data----
double t=h;		double t_next=h;	double t_0=h;	int i;	int ii;			// time loop and index

double y_ode[MAX_SUBS][EPI_DIM]; // NEEDS TO BE BIGGER - NUMBER OF ALL INFECTIOUS CLASSES! 

double rand_nuR[MAX_SUBS][MAX_T];
double rand_nuF[MAX_SUBS][MAX_T]; //how do I make this flexible with different epi length sizes. I don't think I can.

double temp_now;  
double total_rainfall = {0.0}; 
int rain_day;  

double DDtemp_now;  //CIK// used simplify decay functions
double DD10; 

double nuF2;
double nuR2;

// --------------------------------------- STOCHASTICITY -------------------------------------------- //
for (ii = 0; ii < num_sub; ii++)
{
	for (i = 0; i <= MAX_T; i++)
	{	
		//WHY DO I HAVE THIS??? SEEMS WRONG...
		//rand_nuR[ii][i]=gsl_cdf_gaussian_Pinv(RandNumsPass,Params->R_stoch);
		//rand_nuF[ii][i]=gsl_cdf_gaussian_Pinv(RandNumsPass,Params->F_stoch);
		rand_nuR[ii][i]=gsl_ran_gaussian(RandNumsPass,Params->R_stoch); // DO THESE NEED DIFFERENT SEEDS? I DON'T THINK SO.
		rand_nuF[ii][i]=gsl_ran_gaussian(RandNumsPass,Params->F_stoch);
	}
	
}

// ------------------------------------- INITIALIZE MODEL PARAMETERS --------------------------------------- //
int FlagWeek;	int FlagDay[MAX_SUBS];  int FlagV[MAX_SUBS];	int FlagR[MAX_SUBS];	int FlagR_end[MAX_SUBS];  int Flag4[MAX_SUBS];

for (ii = 0; ii < num_sub; ii++)
{
	Params->size_C[sub] = 1.0;
	Params->indexR[sub] = 0.0;	
	FlagR[sub] = 0;
	FlagR_end[sub] = 0;
	FlagV[sub] = 0;
	FlagDay[sub] = 0;
	Flag4[sub] = 0;
}

int day = 0; int week = 0;							// keeps track of day and week number

int line_ticker = 0;   //CK// Ticker used to associate t in function with numbered days.
int line_ticker2;
int test_day = 0;	//CK// used to find the line in the weather data that corresponds to the starting day of collections
int num_day =  hatch;  //CK// Starting day number

line_ticker = num_day;

line_ticker = line_ticker-1;

double S[MAX_SUBS]; // susceptible insects
double V[MAX_SUBS]; // OB's (insects killed by virus) //Vcadaver
double C[MAX_SUBS]; // conidia (insects killed by fungus) //Fcadaver
double R[MAX_SUBS]; // resting spores (4th instars killed by fungus) //FRnext
double IV[MAX_SUBS]; // total virus infected insects
double IF[MAX_SUBS]; // total fungus infected insects
double E_V[MAX_SUBS][n+1]; // virus infected insects classes
double E_F[MAX_SUBS][m+1]; // fungus infected insect classes

// ----------------------------------- INFECTION START --------------------------------------- //

for (sub = 0; sub < num_sub; sub++)
{
	DD10 = 0.0;
	Params->R_start[sub] = 0.0;
	test_day = Params->S_start[sub]; // hatch

	// R start
	while (DD10 <= DDstart)
	{
		DDtemp_now = Params->WEATHER[sub][test_day][3] - 10.0; // avet
		if (DDtemp_now < 0.0) {DDtemp_now = 0.0;}
		DD10 = DD10 + DDtemp_now;		
		Params->R_start[sub]++;
		test_day++;
	}	

	DD10 = 0.0;
	Params->R_end[sub] = 0.0;
	test_day = Params->S_start[sub]; // hatch

	// R end
	while (DD10 <= DDstop)
	{
		DDtemp_now = Params->WEATHER[sub][test_day][3] - 10.0; // avet
		if (DDtemp_now < 0.0) {DDtemp_now = 0.0;}
		DD10 = DD10 + DDtemp_now;			
		Params->R_end[sub]++;
		test_day++;
	}

	DD10 = 0.0;
	Params->V_start[sub] = 0.0;
	test_day = Params->S_start[sub];

	// V start
	while(DD10 <= VDDstart){

		DDtemp_now = Params->WEATHER[sub][test_day][3] - 10.0; // avet
		if (DDtemp_now < 0.0) {DDtemp_now = 0.0;}
		DD10 = DD10 + DDtemp_now;			
		Params->V_start[sub]++;
		test_day++;
	}
}
// ---------------------------- LONG TERM VARIABLES ------------------------------- //
for (sub = 0; sub < num_sub; sub++)
{
	Params->INITS[sub] = Params->STATEVARS[1][i];
	Params->INITV[sub] = Params->STATEVARS[2][i];
	Params->INITR[sub] = Params->STATEVARS[3][i];
}

// ----------------------------------------- INITIALIZE RESULTS ------------------------------------------- //
for (sub = 0; sub < num_sub; sub++)
{
	// Susceptible insects
	S[sub] = Params->INITS[sub]; 
	// Fungus infected insects
	for (ii = 1; ii <= m; ii++)
	{ 
		E_F[i][ii] = 0;
	}
	IF[i] = 0;
	// Virus infected insects
	for (ii = 1; ii <= n; ii++)
	{
			E_V[i][ii] = 0;
	}
	IV[i] = 0;
	// Conidia
	C[sub] = 0.0;
	// Resting spores at end of epizootic
	R[sub] = 0.0; 
	// OBs 
	V[sub] = 0.0;
	if (FlagV[sub] == 1)
	{
		V[sub] = Params->INITV[sub]; 
	}
	Params->Vkill[i] = 0;
	Params->Fkill[i] = 0;
}

double timing[num_sub][3];

for (sub = 0; sub < num_sub; sub++){ //initial conditions
	timing[i][0] = Params->R_start[sub];
	timing[i][1] = Params->R_end[sub];
	timing[i][2] = MAX_T;
	timing[i][3] = Params->V_start[sub];
}

// -------------------- MAIN LOOP!! (calculate populations as time is increased) -------------------------- //

while (t_0 < MAX_T + h)	{ //different subs have different epi lengths

	for (int sub = 0; sub < num_sub; sub++) // this loop is going to mess up DAY
	{
		if (MAX_T > Params->EPI_LENGTH[sub])
		{
			// set all densities to zero
		}
	
		FlagWeek = 0;

		// --------------------- Keep track of days/weeks -------------------- //
		// should this be S start and S end?
		if (day+1 < timing[sub][0] && day+1 < timing[sub][1])
		{ 
			FlagDay[sub] = 1;
			if ((abs(day+1 - timing[sub][3]) < epsilon) && FlagV[sub] == 0)  //Starting virus infection (before resting spore bloom)
			{    
            	FlagV[sub] = 1;
			}

			t_next = day+1;
			day++;
			num_day++; //CHECK
			line_ticker++; //CHECK 

			if (day % 7 == 0)
			{
				week++;
				FlagWeek = 1;
			}
		}
		// --------------------- Resting spores bloom -------------------- //
		else if (timing[sub][0] < timing[sub][1] && timing[sub][0] < day+1)
		{
			FlagR[sub] = 1;
			if ((abs(day+1 - timing[sub][3]) < epsilon) && FlagV[sub] == 0)
			{     //Starting virus infection (before resting spore bloom)
            	FlagV[sub] = 1;
			}
			t_next = timing[sub][0];
			timing[sub][0] = 999.9;
		}
		// --------------------- Resting spores done -------------------- //
		else if (timing[sub][1] < timing[sub][0] && timing[sub][1] < day+1)
		{
			FlagR_end[sub] = 1;
			t_next = timing[sub][1];
			timing[sub][0] = 999.9;
			timing[sub][1] = 999.9;
		}
		// --------------------- Resting spores bloom and end of day -------------------- //
		else if (abs(day+1 - timing[sub][0]) < epsilon)
		{
			FlagDay[sub] = 1; // does this need a sub?
			FlagR[sub] = 1;
			if ((abs(day+1 - timing[sub][3]) < epsilon) && FlagV[sub] == 0){     //Starting virus infection (before resting spore bloom)
            	FlagV[sub] = 1;
			}
			t_next = day + 1;
			timing[sub][0] = 999.9;
			day++;
			num_day++;
			line_ticker++;

			if (day%7 == 0)
			{
				week++;
				FlagWeek = 1;
			}
			//printf("end of day and Resting Spores bloom: t=%f\n",t_next);	//getc(stdin);
		}
		// --------------------- resting spores done and end of day -------------------- //
		else if (abs(day+1 - timing[sub][1]) < epsilon)
		{
			FlagDay[sub] = 1;
			FlagR_end[sub] = 1;
			t_next = day+1;
			timing[sub][0] = 999.9;
			timing[sub][1] = 999.9;
			day++;
			num_day++;
			line_ticker++;

			if (day%7 == 0)
			{
				week++;
				FlagWeek = 1;
			}
		}
		else {
			printf("ERROR: NO EVENT IS NEXT IN TIME???\n");
			getc(stdin);
		}
	}
	//---------------------- LARVAL DISPERSAL ----------------------------//
	if ((day-1) == 8)
	{ 

			//unlease the cadavers
			for(sub=0; sub<num_sub; sub++){ 
				V[sub] = Params->INITV[sub];
			}

			if(larval_dispersal == 1){ 

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
		
	// -------------------------- integrate until next stoppage event ---------------------------------- //
	while (t<t_next)
	{

	//-------------------------------------- DAILY UPDATE OF Y_ODE -------------------------------------------// //FIGURE OUT NEW SUB INDEX CODE
	for (sub = 0; sub < num_sub; sub++)
	{
		// Susceptible insects 
		y_ode[sub][0] = S[sub];	
		// Fungus infected insects
		for (i = 1; i <= m; i++)	{
			y_ode[sub][i] = E_F[sub][i];
		}
		// Virus infected insects
		for (i = 1; i <= n; i++)	{ 
			y_ode[sub][m+i] = E_V[sub][i];
		} 
		// Conidia
		y_ode[sub][m+n+1] = C[sub];	
		// Resting spores at end of epizootic
		y_ode[sub][m+n+2] = R[sub]; 
		// OBs
		y_ode[sub][m+n+3] = V[sub]; 
		// Vkill
		y_ode[sub][m+n+4] = Params->Vkill[sub]; 
		// Fkill
		y_ode[sub][m+n+5] = Params->Fkill[sub];

		//------------------CALCULATE WEATHER DEPENDENT FUNGUS TRANSMISSION PARAMS------//
		// Degree Day
		DDtemp_now = Params->WEATHER[sub][test_day][3] - 10.0;  //avet
		if (DDtemp_now < 0.0) {DDtemp_now=0.0;}
		DD10 = DD10 + DDtemp_now;		

		// conidia production
		if(DD10 >= (fourth_size) && Flag4[sub] == 0){
               Params->size_C[sub] = 0.0;
               Params->indexR[sub] = 1;
               lateinstar[sub] = y_ode[sub][0];
               Flag4[sub] = 1;
               lateinstarday[sub] = day-1;
		}	

		// nuF - RH
		nuF2 = specific_nuF * exp(RH_P * Params->WEATHER[sub][test_day][1]) * exp(rand_nuF[i][day]);   
		if (nuF2 > pow(8.0,8.0)) {nuF2 = pow(8.0,8.0);}
		Params->nuF[num_sub] = (DD10 / fourth_size) * nuF2;

		// muF - T
		temp_now = Params->WEATHER[sub][test_day][3];  //avet
		Params->muF[num_sub] = specific_muF * exp(temp_P * temp_now);	
		if (Params->muF[num_sub] > pow(10.0,10.0)) {Params->muF[num_sub] = pow(10.0,10.0);}

		// nuR - R
		total_rainfall = 0.0;
		rain_day = line_ticker - beta - 1;
		for (rain_day = (line_ticker - beta - theta - 1); rain_day <= line_ticker - theta -1; rain_day++)
		{
			if (rain_day < 0){
				total_rainfall = 0.0;
			}
			else{
				total_rainfall = Params->WEATHER[sub][rain_day][0] + total_rainfall; // CHECK DAY INDEXING 
			}
		}

		nuR2 = (rain_P / (1 + rain_P2 * exp(-rain_P3 * total_rainfall)) - rain_P / (rain_P2+1)) * exp(rand_nuR[i][day]);  //exp(rand_nuR[(int)t]); ??
		if (nuR2 > pow(10.0,10.0)) {nuR2 = pow(10.0,10.0);}

		Params->nuR[num_sub] = (DD10 / fourth_size) * nuR2;

	} //sub

//********************************************************
		t = ODE_Solver(t, t_next, Params, y_ode);
//********************************************************

//update state variables
	for (sub = 0; sub < num_sub; sub++)
	{
		// Susceptible insects
		S[sub] = y_ode[sub][0];
		// Fungus infected insects
		for (i = 1; i <= m; i++) 
		{ 
			E_F[sub][i] = y_ode[sub][i];
			IF[sub] += E_F[sub][i];
		}
		// Virus infected insects
		for (i = 1; i <= n; i++)	
		{ 
			E_V[sub][i] = y_ode[sub][m+i];
			IV[sub] += E_V[sub][i];
		}
		IV[sub] = 0;
		IF[sub] = 0; 
		// Conidia
		C[sub] = y_ode[sub][m+n+1];
		// Resting spores
		R[sub] = y_ode[sub][m+n+2];
		// OBs
		V[sub] = y_ode[sub][m+n+3];
		Params->Vkill[sub] = y_ode[sub][m+n+4];
		Params->Fkill[sub] = y_ode[sub][m+n+5];
	
		if (FlagV[sub] == 1)
		{
			V[sub] = Params->INITV[sub]; 
			Vstartday[sub] = day;
		}
		if (FlagR[sub] == 1)			
		{	
			R[sub] = Params->INITR[sub];
			Rstartday[sub] = day;
			FlagR[sub] = 2;
		}
		else if (FlagR_end[sub] == 1)	{	
			R[sub] = 0;
			Rendday[sub] = day;
			FlagR_end[sub] = 2;
		}
	}

//------------------------PRINT SINGLE EPI OUTPUT--------------------

	for (sub = 0; sub < num_sub; sub++) 
	{	
		Params->SINGLE_EPI_MODEL[year][sub][day-1][0] = S[sub]/(S[sub]+IV[sub]+IF[sub]); //Saving daily fraction uninfected S 
		Params->SINGLE_EPI_MODEL[year][sub][day-1][1] = IV[sub]/(S[sub]+IV[sub]+IF[sub]); //Saving daily fraction infected V 
		Params->SINGLE_EPI_MODEL[year][sub][day-1][2] = IF[sub]/(S[sub]+IV[sub]+IF[sub]); //Saving daily fraction infected F

		if (Params->PRINT_INTRA)
		{
		fprintf(fpintra, "%i %i %i %e %e %e\n", year, sub, day-1, Params->SINGLE_EPI_MODEL[year][sub][day-1][0], Params->SINGLE_EPI_MODEL[year][sub][day-1][1], Params->SINGLE_EPI_MODEL[year][sub][day-1][2]);
		}
	}
	//getc(stdin);
}

t_0=t_next;
}

return 0;
}