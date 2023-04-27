double DDEVF(void *Paramstuff, double *RandNumsPass ,size_t dim,int pop,int maxy_t, double hatch, int q, int dataset) //SH DOES save into array

{


STRUCTURE* Params;
Params = (STRUCTURE*) Paramstuff;

int FlagDay=0;

int MAXT3=47;



//-------------------------------------- METAPOPULATION STRUCTURE -------------------------------------------//

int num_sub;
Params->j = dataset;
int j = Params->j;

if (j==1 || j==2 || j==3) { //epi data
	Params->numsub=4;
	num_sub = Params->numsub; 
}
if (j==4 || j==5 || j==6) { // obs data
	Params->numsub=1;
	num_sub = Params->numsub;
}

int larvae_dispersal_on = 1; //set to 0 for no dispersal



//-------------------------------------- PARAMETER DECLARATION -------------------------------------------//
double t=h;		double t_next=h;	double t_0=h;	int i;	int ii;			// time loop and index
double y_ode[DIM]; //**SH** this holds 
double rand_nuR[MAXT3];
double rand_nuF[MAXT3];

double temp_now;  //CIK// used simplify decay functions
double total_rainfall=0.0;  //used to sum up rainfall
int rain_day;  //used to sum up rainfall

double DDtemp_now;  //CIK// used simplify decay functions

double nuF2;
double nuR2;

double DD10=0;    //accumulated degree days about 10 degrees C
double R_seed = 0.05;

// --------------------------------------- STOCHASTICITY -------------------------------------------- //
for (i=0;i<=MAXT3;i++)	{
	if (j==1 || j==2 || j==3){
	rand_nuR[i]=gsl_cdf_gaussian_Pinv(RandNumsPass[i],Params->Rsd_exp);
	//printf("Rand[%i] = %lf\n", i, RandNumsPass[i]);
	rand_nuF[i]=gsl_cdf_gaussian_Pinv(RandNumsPass[i+MAXT3],Params->Fsd_exp);
	}
	if (j==4 || j==5 || j==6){
	rand_nuR[i]=gsl_cdf_gaussian_Pinv(RandNumsPass[i],Params->Rsd_obs);
	rand_nuF[i]=gsl_cdf_gaussian_Pinv(RandNumsPass[i+MAXT3],Params->Fsd_obs);	
	}
	//printf("randon nuR = %lf\t, random nuF = %lf\n", rand_nuR[i], rand_nuF[i]);
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

//SH CHECK WITH GREG
//state variable declaration
double S[num_sub]; double V[num_sub]; double C[num_sub]; double R[num_sub];
double IV[num_sub]; double IF[num_sub]; double IVF[num_sub]; double IFV[num_sub];

//exposed class declaratoin
double E_V[num_sub][n2+1]; double E_F[num_sub][n+1]; double E_VF[num_sub][n1+1]; double E_FV[num_sub][n+1]; //CHECK



// ----------------------------------- CONIDIA BLOOMING TIMES --------------------------------------- //

R_start=hatch; //SH Resting spores start blooming from start day

DD10=0.0;		R_end = 0.0;
test_day = line_ticker;

while(DD10 <= DDstop){

	DDtemp_now = Params->WDATA[1][test_day][4][0]-10.0;  //JL: Reading in AveT here
	if(DDtemp_now<0.0){DDtemp_now=0.0;}
	DD10 = DD10 + DDtemp_now;			//CK// summing degree days over time
	R_end++;
	test_day++;
}

DD10=0.0;



// ---------------------------- INITIALIZE POPULATION SIZES ------------------------------- //

double r_germ = R_start;		//CK// nixing r_time because I made all germ dates start at beginning of the collections
if (r_germ<0)	r_germ=0;

double INITS[4];
double INITV[4];
double INITR[4];

//printf("j=%i\n", j);
//printf("Params.fitinit10= %lf\n", Params->FITINIT[1][0]);
if (j==1 || j==2 || j==3){
	for(i=0; i<num_sub; i++){
		INITS[i] = Params->FITINIT[j][i];
		INITV[i] = Params->FITINIT[j][i+num_sub];
		INITR[i] = Params->FITINIT[j][i+num_sub+num_sub];
		//printf("j = %i\n INITS = %lf\t INITV=%lf\t INITR=%lf\n", j,INITS[i], INITV[i], INITR[i]);
	}
	//printf("j = %i\t initS = %lf\t initV = %lf\t initR = %lf\n", j, INITS[i], INITV[i], INITR[i]);
}

if (j==4 || j==5 || j==6){
	INITS[0] = Params->FITINIT[j][0];
	INITV[0] = Params->FITINIT[j][4];
	INITR[0] = Params->FITINIT[j][8];
	//printf("j=%i\t S=%lf\t V=%lf\t R=%lf\n", j, INITS[0], INITV[0], INITR[0]);
}

// ----------------------------------------- INITIALIZE RESULTS ------------------------------------------- //

//single epizootic state params
//printf("numsub = %i\n", num_sub);
for(i=0; i<num_sub; i++){ 
	S[i] = INITS[i]; //host density
	//printf("S[%i] = %lf\n", i, S[i]);
	V[i] = 0; //virus cadavers
	C[i] = 0; //conidia 
	R[i] = INITR[i]; //resting spores
	//printf("J = %i\t, INITIAL CONDITIONS: S=%lf\t, V=%lf\t, R=%lf\n",j, num_sub, S[i], V[i], R[i]);
	for (ii=1;ii<=n1;ii++){ //early virus infected
		if (ii==1){
			E_VF[i][ii] = INITV[i];
		}
		else{
			E_VF[i][ii]=0; //initial virus infection set by experimental setup
		}
		//printf("sub = %i\t ii = %i\t EVF = %lf\n", i, ii, E_VF[i][ii]);
	}
	for (ii=1;ii<=n2;ii++){ //late virus infected
		E_V[i][ii]=0;
	}
	for (ii=1;ii<=n;ii++){ //fungus and coinfected
		E_F[i][ii]=0;
		E_FV[i][ii]=0;
	}
	IF[i]=0;
	IV[i]=0;
	IVF[i]=0;
	IFV[i]=0;
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

double timing[6]={r_germ,R_end,MAXT3};

// -------------------- MAIN LOOP!! (calculate populations as time is increased) -------------------------- //

while (t_0<MAXT3+h)	{    //CK// change MAXT to MAXT2 to let it go to the end of the experimental datasets?
	
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
	const int sub_index[4] = {0, 127, 254, 381};


	// -------------------------- integrate until next stoppage event ---------------------------------- //

	while (t<t_next)	{

//---------------------- LARVAL DISPERSAL ----------------------------//
	if(day-1<8){ //dispersal only occurs as first instars, 1 week
		
		if (j==1 || j==2 || j==3) { //only for datasets with subpopulations
		
			if(larvae_dispersal_on == 1){

				int subout;
				int subin;

				double Vin[num_sub][n2]; //one for each subpop 0-3
				double Vout[num_sub][n2]; //one for each subpop 0-3
				double VFout[num_sub][n1]; //one for each subpop 0-3
				double VFin[num_sub][n1]; //one for each subpop 0-3

				double Sout[num_sub]; 
				double Sin[num_sub]; 

				//initialize dispersal array
				for(sub=0; sub<num_sub; sub++){

					Sout[sub] = 0;
					Sin[sub] = 0;

					for(i=1;i<=n1;i++){
						VFout[sub][i] = 0;
						VFin[sub][i] = 0;
					}
					for (ii=1;ii<=n2;ii++)	{
						Vout[sub][ii] = 0;
						Vin[sub][ii] = 0;
					}
				}

				for(subout=0; subout<num_sub; subout++){
					//susceptible larvae dispersing
					
					//SCALE OF MIGRATION
					//Sout[subout] = ((Params->m_l_sub[j][subout] * 2.0 * M_PI)/Params->a_l_pop) * S[subout];
					Sout[subout] = exp(-Params->a_l_pop*10) * S[subout];
					//printf("m = %lf\t a = %lf\n", Params->m_l_pop, Params->a_l_pop);

					//susceptible larvae that arrive at another metapopulation
					for(subin=0; subin<num_sub; subin++){
						if(subin!=subout){

							//SCALE OF MIGRATION
							//Sin[subin] = S[subout]*Params->m_l_sub[j][subout]*exp(-Params->a_l_pop*Params->DISTANCE[j][subout][subin]);
							Sin[subin] = Sout[subout]*Params->m_l_pop*exp(-Params->a_l_pop*Params->DISTANCE[j][subout][subin]);
							//printf("distance[%i][%i][%i] = %i\n", j, subout, subin, Params->DISTANCE[j][subout][subin]);
						}
					}

					for (i=1;i<=n1;i++)	{ //for each exposed class
						//infected larvae dispersing
						//SCALE OF MIGRATION
						//VFout[subout][i] += ((Params->m_l_sub[j][subout] * 2.0 * M_PI)/Params->a_l_pop) * E_VF[subout][i];
						VFout[subout][i] += exp(-Params->a_l_pop*10) * E_VF[subout][i];

						for(subin=0; subin<num_sub; subin++){

							if(subin!=subout){
								//infected larvae that arrive at another metapopulation
								//SCALE OF MIGRATION
								//VFin[subin][i] += E_VF[subout][i]*Params->m_l_sub[j][subout]*exp(-Params->a_l_pop*Params->DISTANCE[j][subout][subin]);
								VFin[subin][i] += VFout[subout][i]*Params->m_l_pop*exp(-Params->a_l_pop*Params->DISTANCE[j][subout][subin]);
							}
						}
					}
					for (ii=1;ii<=n2;ii++)	{ //ii not i
						//SCALE OF MIGRATION
						//Vout[subout][ii] += ((Params->m_l_sub[j][subout] * 2.0 * M_PI)/Params->a_l_pop) * E_V[subout][ii];
						Vout[subout][ii] += exp(-Params->a_l_pop*10) * E_V[subout][ii];

						for(subin=0; subin<num_sub; subin++){

							if(subin!=subout){
								//SCALE OF MIGRATION
								//Vin[subin][ii] += E_V[subin][ii]*Params->m_l_sub[j][subout] * exp(-Params->a_l_pop*Params->DISTANCE[j][subout][subin]);
								Vin[subin][ii] += Vout[subin][ii]*Params->m_l_pop * exp(-Params->a_l_pop*Params->DISTANCE[j][subout][subin]);
							}
						}
					}
				}
				for(sub=0; sub<num_sub; sub++){ //update larval density
					//printf("preS = %e\n", S[sub]);
					S[sub] += (Sin[sub] - Sout[sub]);
					//printf("S = %e\t sub = %i\t sub in = %e\t subout = %e\n", S[sub], sub, Sin[sub], Sout[sub]);

					for (i=1;i<=n1;i++)	{ //for each exposed class
						E_VF[sub][i] += (VFin[sub][i] - VFout[sub][i]);
					}
					for (i=1;i<=n2;i++)	{
						E_V[sub][i] += (Vin[sub][i] - Vout[sub][i]);
					}
					if(S[sub]<0 || E_VF[sub]<0 || E_V[sub]<0){
						printf("TOO MUCH DISPERSAL! NEGATIVE POPULATIONS.");
					}
				}
			} 
		}
	}	                        	
		
		//-------------------------------------- DAILY UPDATE OF Y_ODE -------------------------------------------//
		//printf("day = %i\n", day);
		for(sub=0; sub<num_sub; sub++){ //for each treatment
			y_ode[0+sub_index[sub]]=S[sub];	y_ode[m+n+1+sub_index[sub]]=C[sub];	//Params->POPS[3]=R[sub];
			//printf("PreODES C[%i] = %e\n", sub, C[sub]);
			//printf("y_ode[%i] = %e\n", sub_index[sub], y_ode[0+sub_index[sub]]);
			y_ode[m+n+3+sub_index[sub]]=V[sub];
			
			for (i=1;i<=n1;i++)	{
				y_ode[n+i+sub_index[sub]]=E_VF[sub][i];
				//printf("sub = %i\t i = %i\t EVF = %lf\n", sub, i, E_VF[sub][i+sub_index[sub]]);
			}
			for (i=1;i<=n;i++)	{
				y_ode[i+sub_index[sub]]=E_F[sub][i];
			}
			for (i=1;i<=n2;i++)	{
				y_ode[n+n1+i+sub_index[sub]]=E_V[sub][i];
				//printf("sub = %i\t EV = %lf\n", sub, E_V[sub][i+sub_index[sub]]);
			}
			y_ode[m+n+2+sub_index[sub]]=Fnext[sub];
			y_ode[m+n+4+sub_index[sub]]=Vkill[sub];
			y_ode[m+n+5+sub_index[sub]]=Fkill[sub];
			y_ode[m+n+6+sub_index[sub]]=Vnext[sub];

			for (i=1;i<=n;i++)	{
				y_ode[m+n+6+i+sub_index[sub]]=E_FV[sub][i]; //end of fill for each treatment
			}
			//printf("PRE ODE sub = %i\t S = %e\t C = %e\t V = %e\n", sub, S[sub], C[sub], V[sub]);
		}
		

	//******************************* Weather Stuff ******************************//
	DDtemp_now = Params->WDATA[1][line_ticker - 1][4][0]-10.0;  //CK// begin calculation of accumulated Degree Days
	if(DDtemp_now<0.0){DDtemp_now=0.0;}
	DD10 = DD10 + DDtemp_now;			//CK// summing degree days over time


	nuF2 = Params->specific_nuF*exp(RH_P*Params->WDATA[1][line_ticker - 1][6][0]) * exp(rand_nuF[(int)t]);    //JL: Reading in MinRH here
	if(nuF2> pow(8.0,8.0)){nuF2= pow(8.0,8.0);}
	Params->nuF = (DD10/fourth_size)*nuF2;

	temp_now = Params->WDATA[1][line_ticker - 1][2][0];  //JL: Reading in MaxT here

	Params->muF = specific_muF*exp(temp_P*temp_now);	//CK// Conidia Decay Response #2.2  BEST SO FAR!!
	if(Params->muF > pow(10.0,10.0)){Params->muF= pow(10.0,10.0);}

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

	Params->nuR = (DD10/fourth_size)*nuR2;

//********************************************************
		t=ODE_Solver(t,t_next,Params,y_ode);
//********************************************************

//update state variables
	for(sub=0; sub<num_sub; sub++){
		S[sub]=y_ode[0+sub_index[sub]]; 
		//printf("POSTODES[%i] = %e\n", sub, S[sub]);
		C[sub]=y_ode[m+n+1+sub_index[sub]]; //fungus cadavers?
		//printf("post ode C[%i\t] = %e\n", sub, C[sub]);
		V[sub]=y_ode[m+n+3+sub_index[sub]]; //virus cadavers?
		//printf("sub = %i\t V = %lf\n",sub, V[sub]);
		Fnext[sub]=y_ode[m+n+2+sub_index[sub]];			
		Vkill[sub]=y_ode[m+n+4+sub_index[sub]];
		Fkill[sub]=y_ode[m+n+5+sub_index[sub]];			
		Vnext[sub]=y_ode[m+n+6+sub_index[sub]];
		IF[sub]=0;
		IV[sub]=0;
		IVF[sub]=0;
		IFV[sub]=0;
		printf("POST ODE sub = %i\t S = %e\t C = %e\t V = %e\n", sub, S[sub], C[sub], V[sub]);

	}
		
	//sum daily infected across exposed classes
	for(sub=0; sub<num_sub; sub++){	
	
		for (i=1;i<=n;i++)	{ //fungus infected
			E_F[sub][i]=y_ode[i+sub_index[sub]];
			IF[sub] += E_F[sub][i];
		}

		for (i=1;i<=n1;i++)	{ //early virus infections which can be coinfected
			E_VF[sub][i]=y_ode[n+i+sub_index[sub]];
			IVF[sub] += E_VF[sub][i];
		}

		for (i=1;i<=n2;i++)	{
			E_V[sub][i]=y_ode[n+n1+i+sub_index[sub]];
			IV[sub] += E_V[sub][i];
			//printf("E_V = %lf\t IV = %lf\n", E_V[sub][i], IV[sub]);
		}

		for (i=1;i<=n;i++)	{ //coinfected
			E_FV[sub][i]=y_ode[n+m+6+i+sub_index[sub]];
			//printf("j = %i\t sub = %i\t E_FV = %lf\n", j, sub, E_FV[sub]);
			IFV[sub] += E_FV[sub][i];
			//printf("j = %i\t sub = %i\t IF = %lf\t IV = %lf\t IVF = %lf\n",j, sub, IF[sub], IV[sub], IFV[sub]);
		}

	}
	//printf("day = %i\t j = %i\t sub = %i\t IF = %lf\t IV = %lf\t IVF = %lf\n",day, j, sub, IF[sub], IV[sub], IFV[sub]);

//*******************************Appends output for each treatment run based on one epizootic length of 48**************************//

		//LOOP THROUGH ARRAYS
	int day_index[4] = {0, 47, 95, 143}; //to append 48 day epizootics //probably a better way to do this
	
	for(sub=0; sub<num_sub; sub++){	

		Params->MODEL[j][day-1+day_index[sub]][0] = S[sub]/(y_ode[0+sub_index[sub]]+IV[sub]+IF[sub]+IVF[sub]+IFV[sub]); //Saving daily fraction uninfected S 
		//printf("DAY = %i\t j = %i\t sub = %i\t S = %lf\t yode = %lf\t IV = %lf\t IF = %lf\t IVF = %lf\n", day-1, j, sub, S[sub], y_ode[0+sub_index[sub]], IV[sub], IF[sub], IVF[sub]);
		Params->MODEL[j][day-1+day_index[sub]][1] = (IV[sub]+IVF[sub])/(y_ode[0+sub_index[sub]]+IV[sub]+IF[sub]+IVF[sub]+IFV[sub]); //Saving daily fraction infected V 
		Params->MODEL[j][day-1+day_index[sub]][2] = IF[sub]/(y_ode[0+sub_index[sub]]+IV[sub]+IF[sub]+IVF[sub]+IFV[sub]); //Saving daily fraction infected F
		Params->MODEL[j][day-1+day_index[sub]][3] = IFV[sub]/(y_ode[0+sub_index[sub]]+IV[sub]+IF[sub]+IVF[sub]+IFV[sub]); //Saving daily fraction coinfected 

		//MODEL REALIZATION PRINTING
		//fprintf(fpr, "%i\t %i\t %i\t %e\t %e\t %e\t %e\n", j, sub, day-1, Params->MODEL[j][day-1+day_index[sub]][0], Params->MODEL[j][day-1+day_index[sub]][1], Params->MODEL[j][day-1+day_index[sub]][2], Params->MODEL[j][day-1+day_index[sub]][3]);
		//printf("%i\t %i\t %i\t %e\t %e\t %e\t %e\n", j, sub, day-1, Params->MODEL[j][day-1+day_index[sub]][0], Params->MODEL[j][day-1+day_index[sub]][1], Params->MODEL[j][day-1+day_index[sub]][2], Params->MODEL[j][day-1+day_index[sub]][3]);
	}
	}

//Done with daily plotting output here


	// ---------------------------- end of the week updates ---------------------------------- //

t_0=t_next;
//printf("t_0=%lf\n",t_0);
}

return 0;
}