double DDEVF(void *Paramstuff, double *RandNumsPass ,size_t dim, int pop, int maxy_t, double hatch, int q, int dataset) //SH DOES save into array

{

STRUCTURE* Params;
Params = (STRUCTURE*) Paramstuff;

int FlagDay=0;

int MAXT3=47; 

//-------------------------------------- PARAMETER DECLARATION -------------------------------------------//
int num_sub = Params->num_sub;

//--- need to update to get cc data----
double t=h;		double t_next=h;	double t_0=h;	int i;	int ii;			// time loop and index

double y_ode[DIM]; // NEEDS TO BE BIGGER

double rand_nuR[num_sub][MAXT3];
double rand_nuF[num_sub][MAXT3];

double temp_now[num_sub];  //CIK// used simplify decay functions
double total_rainfall[num_sub] = {0.0};  //used to sum up rainfall
int rain_day[num_sub];  //used to sum up rainfall

double DDtemp_now;  //CIK// used simplify decay functions

double nuF2[num_sub];
double nuR2[num_sub];

double DD10[num_sub] = {0.0};    //accumulated degree days about 10 degrees C
double R_seed = 0.05;


// --------------------------------------- STOCHASTICITY -------------------------------------------- //
for (ii=0; ii<num_sub; ii++){
	for (i=0;i<=MAXT3;i++)	{
		rand_nuR[ii][i]=gsl_cdf_gaussian_Pinv(RandNumsPass[i],Params->R_stoch);
		rand_nuF[ii][i]=gsl_cdf_gaussian_Pinv(RandNumsPass[i+MAXT3],Params->F_stoch);
	}
}
// ----------------------------------------- FIXED PARAMETERS  ---------------------------------------------- //

double R_end;   //CK//  Change value for function of latitude
double R_start;   //CK//  Change value for function of latitude

// ------------------------------------- INITIALIZE MODEL PARAMETERS --------------------------------------- //

int FlagWeek;	int FlagV=0;	int FlagR=0;	int FlagR_end=0;		// keep track of end of week
FlagV=1;  //At the beginning stage, part of the population is infected.

int day = 0; int week = 0;							// keeps track of day and week number

int line_ticker=0;   //CK// Ticker used to associate t in function with numbered days.
int line_ticker2;
int test_day=0;	//CK// used to find the line in the weather data that corresponds to the starting day of collections
int num_day =  hatch;  //CK// Starting day number

line_ticker = num_day;

line_ticker=line_ticker-1;

int num_weeks=48/7; 

//state variable declaration
double S[num_sub]; double V[num_sub]; double C[num_sub]; double R[num_sub];
double IV[num_sub]; double IF[num_sub];

//exposed class declaratoin
double E_V[num_sub][n+1]; double E_F[num_sub][m+1];

// ----------------------------------- CONIDIA BLOOMING TIMES --------------------------------------- //

R_start=hatch; //SH Resting spores start blooming from start day //UPDATE THIS

R_end[num_sub] = 0.0;
test_day = line_ticker;

for (i = 0; i < num_sub; i++)
{
	while(DD10[num_sub] <= DDstop){

		DDtemp_now = Params->WDATA[1][test_day][4][0]-10.0; //UPDATE WEATHER DATA
		if(DDtemp_now<0.0){DDtemp_now=0.0;}
		DD10[num_sub] = DD10[num_sub] + DDtemp_now;			//CK// summing degree days over time
		R_end[num_sub]++;
		test_day[num_sub]++;
	}

	DD10[num_sub]=0.0;
}
// ---------------------------- INITIALIZE POPULATION SIZES ------------------------------- //

double r_germ = R_start;		
if (r_germ<0)	r_germ=0;

double INITS[num_sub];
double INITV[num_sub];
double INITR[num_sub];

for(i=0; i<num_sub; i++){
	INITS[i] = Params->STATEVARS[1][i] - Params->STATEVARS[1][i]*Params->STATEVARS[3][i];
	INITV[i] = Params->STATEVARS[1][i]*Params->STATEVARS[3][i];
	//printf("j = %i InitV[%i] = %lf\n", j, i, INITV[i]);
	//printf("j = %i InitV[%i] = %lf\n", j, i, INITV[i]);	
}

// ----------------------------------------- INITIALIZE RESULTS ------------------------------------------- //

//single epizootic state params
//printf("day=%i\n", day-1);
for(i=0; i<num_sub; i++){ 
	S[i] = INITS[i]; //host density
	//printf("S[%i] = %lf\n", i, S[i]);
	V[i] = 0; //virus cadavers
	C[i] = 0; //conidia 
	for (ii=1;ii<=n;ii++){ //virus infection
		if (ii==1){
			E_V[i][ii] = 0;
		}
		else{
			E_V[i][ii] = 0;
		}
	}
	for (ii=1;ii<=m;ii++){ //fungus
		E_F[i][ii] = 0;
	}
	IF[i]=0;
	IV[i]=0;
}

//long-term state params
double Vnext[num_sub];
double Vkill[num_sub];
double Fnext[num_sub];
double Fkill[num_sub];


for(i=0; i<num_sub; i++){ //initial conditions
	Vnext[i] = 0;
	Vkill[i] = 0;
	Fnext[i] = 0;
	Fkill[i] = 0;
}

double timing[6]={r_germ,R_end,MAXT3}; // need to expand to accomodate all subpops

// -------------------- MAIN LOOP!! (calculate populations as time is increased) -------------------------- //

while (t_0<MAXT3+h)	{ 
	
	FlagWeek=0;
	// ------------------------------- Find Stoppage Event ----------------------------------------------- //
	// --------------------- end of day -------------------- //
	if (day+1<timing[0] && day+1<timing[1])	{

		FlagDay=1;

		t_next=day+1;
		day++;
		num_day++;
		line_ticker++;

		if (day%7==0)	{
			week++;
			FlagWeek=1;
		}
		//getc(stdin);
	}
	// --------------------- resting spores bloom -------------------- //
	else if (timing[0]<timing[1] && timing[0]<day+1)	{
		FlagR=1;
		t_next=timing[0];
		timing[0]=999.9;
		//printf("Resting spores bloom: t=%f\n",t_next);		//getc(stdin);
	}
	// --------------------- resting spores done -------------------- //
	else if (timing[1]<timing[0] && timing[1]<day+1)	{
		FlagR_end=1;
		t_next=timing[1];
		timing[0]=999.9;
		timing[1]=999.9;
		//printf("Resting spores done: t=%f\n",t_next);		//getc(stdin);
	}
	// --------------------- resting spores bloom and end of day -------------------- //
	else if (abs(day+1-timing[0])<epsilon)	{

		FlagDay=1;

		FlagR=1;
		t_next=day+1;
		timing[0]=999.9;
		day++;
		num_day++;
		line_ticker++;

		if (day%7==0)	{
			week++;
			FlagWeek=1;
		}
		//printf("end of day and Resting Spores bloom: t=%f\n",t_next);	//getc(stdin);
	}
	// --------------------- resting spores done and end of day -------------------- //
	else if (abs(day+1-timing[1])<epsilon)	{

		FlagDay=1;

		FlagR_end=1;
		t_next=day+1;
		timing[0]=999.9;
		timing[1]=999.9;
		day++;
		num_day++;
		line_ticker++;

		if (day%7==0)	{
			week++;
			FlagWeek=1;
		}
		//printf("end of day and Resting Spores done: t=%f\n",t_next);	//getc(stdin);
	}
	else {
		printf("ERROR: NO EVENT IS NEXT IN TIME???\n");
		getc(stdin);
	}

	//indexing variables
	int sub;

	// -------------------------- integrate until next stoppage event ---------------------------------- //

	while (t<t_next)	{

//---------------------- LARVAL DISPERSAL ----------------------------//
	if((day-1)==8){ //dispersal occurs throughout first week

			//unlease the cadavers
			for(sub=0; sub<num_sub; sub++){ 
				V[sub] = INITV[sub];
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
				for(sub=0; sub<num_sub; sub++){

					Sout[sub] = 0;
					Sin[sub] = 0;

					Vout[sub] = 0;
					Vin[sub] = 0;
				}

				//larvae disperse
				for(subout=0; subout<num_sub; subout++)
				{
					Sout[subout] = exp(-Params->l_a_sub[subout]*10) * S[subout];

					Vout[subout] += exp(-Params->l_a_sub[subout]*10) * V[subout];
				}
				//some fraction arrive at another population
				for(subout=0; subout<num_sub; subout++)
				{
					for(subin=0; subin<num_sub; subin++)
					{
						if(subin!=subout)
						{
							Sin[subin] = Sout[subout]*exp(-Params->l_a_sub[subout]*Params->DISTANCE[j][subout][subin]);

							Vin[subin] += Vout[subout]*exp(-Params->l_a_sub[subout]*Params->DISTANCE[j][subout][subin]);
						}
					}
				}
				for(sub=0; sub<num_sub; sub++){ //update larval density

					S[sub] += (Sin[sub] - Sout[sub]);

					V[sub] += (Vin[sub] - Vout[sub]);
				}
			} 
	}	                        	
		
	//-------------------------------------- DAILY UPDATE OF Y_ODE -------------------------------------------// //FIGURE OUT NEW SUB INDEX CODE
	//printf("DAY = %i\n", day-1);
	for(sub=0; sub<num_sub; sub++){ 
		y_ode[0+sub_index[sub]]=S[sub];	//SUSCEPTIBLE
		//printf("preode S[%i] = %lf\n", sub, y_ode[0+sub_index[sub]]);

		for (i=1;i<=m;i++)	{ //FUNGUS INFECTED 
			y_ode[i+sub_index[sub]]=E_F[sub][i];
		}
		for (i=1;i<=n;i++)	{ //VIRUS INFECTED
			y_ode[m+i+sub_index[sub]]=E_V[sub][i];
		} 
		y_ode[m+n+1+sub_index[sub]]=C[sub];	//CONIDIA
		y_ode[m+n+2+sub_index[sub]]=V[sub]; //OBS
		//printf("V[%i] = %lf\n", sub, V[sub]);
	}
	

	//******************************* Weather Stuff ******************************// // NEED TO GIVE EACH SUB ITS OWN WEATHER
	for (i = 0; i < num_sub; i++) // NEED TO FINISH
	{
		DDtemp_now = Params->WDATA[1][line_ticker - 1][4][0]-10.0;  //CK// begin calculation of accumulated Degree Days
		if(DDtemp_now<0.0){DDtemp_now=0.0;}
		DD10[num_sub] = DD10[num_sub] + DDtemp_now;			//CK// summing degree days over time


		nuF2 = Params->specific_nuF[num_sub]*exp(RH_P*Params->WDATA[1][line_ticker - 1][6][0]) * exp(rand_nuF[(int)t]);    //JL: Reading in MinRH here
		if(nuF2> pow(8.0,8.0)){nuF2= pow(8.0,8.0);}
		Params->nuF[num_sub] = (DD10[num_sub]/fourth_size)*nuF2;

		temp_now = Params->WDATA[1][line_ticker - 1][2][0];  //JL: Reading in MaxT here

		Params->muF[num_sub] = specific_muF*exp(temp_P*temp_now);	//CK// Conidia Decay Response #2.2  BEST SO FAR!!
		if(Params->muF[num_sub] > pow(10.0,10.0)){Params->muF[num_sub] = pow(10.0,10.0);}

		total_rainfall = 0.0;
		rain_day= line_ticker - beta - 1;

		for (rain_day= (line_ticker - beta - theta - 1);rain_day <= line_ticker - theta -1;rain_day++)	{

			if (rain_day<0){
				total_rainfall=0;
			}
			else{
					total_rainfall = Params->WDATA[1][rain_day][0][0]+total_rainfall;
			}
		}

		nuR2=(rain_P/(1+rain_P2*exp(-rain_P3*total_rainfall)) - rain_P/(rain_P2+1))*exp(rand_nuR[(int)t]);  
		if(nuR2> pow(10.0,10.0)){nuR2= pow(10.0,10.0);}

		Params->nuR[num_sub] = (DD10/fourth_size)*nuR2;
	}

//********************************************************
		t=ODE_Solver(t,t_next,Params,y_ode);
//********************************************************

//update state variables
	for(sub=0; sub<num_sub; sub++){
		S[sub]=y_ode[0+sub_index[sub]]; //SUSCEPTIBLES
		//printf("postode S[%i] = %lf\n", sub, S[sub]);
		C[sub]=y_ode[m+n+1+sub_index[sub]]; //CONIDIA
		V[sub]=y_ode[m+n+2+sub_index[sub]]; //OBS
		//printf("post ODE S = %lf\t C = %lf\t V = %lf\n", S[sub], C[sub], V[sub]);
	}
	for(sub=0; sub<num_sub; sub++){	
	
		IF[sub]=0; //FUNGUS INFECTED
		IV[sub]=0; //IRUS INFECTED

		for (i=1;i<=m;i++)	{ //fungus infected
			E_F[sub][i]=y_ode[i+sub_index[sub]];
			IF[sub] += E_F[sub][i];
		}

		for (i=1;i<=n;i++)	{ //early virus infections which can be coinfected
			E_V[sub][i]=y_ode[m+i+sub_index[sub]];
			IV[sub] += E_V[sub][i];
		}

	}

//*******************************PRINT MODEL OUTPUT**************************//
		//LOOP THROUGH ARRAYS
	int day_index[4] = {0, 47, 95, 143}; //to append 48 day epizootics //probably a better way to do this //TIME TO FIGURE IT OUT
	//CHANGE remove zeros
	for(sub=0; sub<num_sub; sub++){	
		//FRACTIONS 
		///*
		Params->MODEL[j][day-1+day_index[sub]][0] = S[sub]/(S[sub]+IV[sub]+IF[sub]); //Saving daily fraction uninfected S 
		Params->MODEL[j][day-1+day_index[sub]][1] = IV[sub]/(S[sub]+IV[sub]+IF[sub]); //Saving daily fraction infected V 
		Params->MODEL[j][day-1+day_index[sub]][2] = IF[sub]/(S[sub]+IV[sub]+IF[sub]); //Saving daily fraction infected F
		//*/
		//ABSOLUTE VALUES
		/*
		Params->MODEL[j][day-1+day_index[sub]][0] = S[sub];
		Params->MODEL[j][day-1+day_index[sub]][1] = IV[sub];
		Params->MODEL[j][day-1+day_index[sub]][2] = IF[sub]; 
		*/
		//printf("TOTAL POP for sub %i = %lf\n", sub, S[sub]+IV[sub]+IF[sub]+V[sub]);ING

		fprintf(fpsims, "%i %i %i %e %e %e\n", year, sub, day-1, Params->MODEL[j][day-1+day_index[sub]][0], Params->MODEL[j][day-1+day_index[sub]][1], Params->MODEL[j][day-1+day_index[sub]][2]);
		//printf("%i\t %i\t %i\t %e\t %e\t %e\n", j, sub, day-1, Params->MODEL[j][day-1+day_index[sub]][0], Params->MODEL[j][day-1+day_index[sub]][1], Params->MODEL[j][day-1+day_index[sub]][2]);
	}
	//getc(stdin);
}

t_0=t_next;
}

return 0;
}