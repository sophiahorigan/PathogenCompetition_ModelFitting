// DDEVF sets up model and calls 0DE_SOLVER, returns Params->sim_results

double DDEVF(void *Paramstuff,gsl_rng *RandNumsPass,size_t dim,int pop,int maxy_t, double hatch, int q, int tmt) //SH DOES save into array

{

STRUCTURE* Params;
Params = (STRUCTURE*) Paramstuff;
		//declarations of stuff for plotting
double PLOT=1.0;

double Fprob;
double p1,p2,p3;	        // simulation results (p_i is the probability of being in each of the three classes)
double Cpar, Cprob, Cprob2, Cprob3;					//CK//
double Opar, Oprob, Oprob2, Oprob3;					//CK//
double r1, r2, r3, c1, c2;	            //CK// simulation results (r1 is resting spore density, c1 is condidia density)
r1 = 0.0; r2=0.0; c1= 0.0; c2=0.0;

double cover_C = Params->PARS[17];		//CK// effect of cage.  Testing to see if EXP bugs had higher or lower infection than ferals
double cover_R = Params->PARS[20];
double open_C = Params->PARS[24];		//CK// effect of cage.  Testing to see if EXP bugs had higher or lower infection than ferals
double open_R = Params->PARS[25];		//CK// effect of cage.  Testing to see if EXP bugs had higher or lower infection than ferals

int FlagDay=0;

int MAXT3=maxy_t;

int k = tmt; //SH looping through treamtent numbers below

int m = Params->PARS[9];
int n = Params->PARS[8]; 
int DIM = m+n+4+2+1+m; //SH need to add an m in this? need to increase anyways 

int n1=(VFPass/exposetime)*Params->PARS[8];    //The number of the first group of exposed classes to virus
int n2=n-n1;                  //The number of the first group of exposed classes to virus

double t=h;		double t_next=h;	double t_0=h;	int i;				// time loop and index
double epsilon = pow(10,-6);
double y_ode[DIM]; //SH this might be important
double rand_nuR[MAXT3];
double rand_nuF[MAXT3];

double ave_R = Params->PARS[50+pop];
double specific_muF = Params->PARS[6];   //general intercept for MAX TEMP decay function for conidia
double specific_nuF = Params->PARS[3];   //Site-specific infection rate for conidia
double rain_P = Params->PARS[21];  //fit param used to scale accumulating rain.
double rain_P2 = Params->PARS[26];  //fit param used to scale accumulating rain.
double rain_P3 = Params->PARS[29];  //fit param used to scale accumulating rain.
double RH_P = Params->PARS[22];   //CK//  Parameter for RH data
double temp_P = Params->PARS[23];   //CK//  Parameter for temperature data
double fourth_size=Params->PARS[28];	//CK// degree day when the bugs reach 4th instar

double DDstart	= Params->PARS[27];  //CK// param used for starting date
double DDstop	= Params->PARS[19];  //CK// param used for starting date

Params->size_C = 1.0;
Params->indexR = 0.0;
Params->indexV = 0.0;
double C_end=Params->PARS[16];	  //CK// fit param that turns off new conidia production once a specific size has been reached

double temp_now;  //CIK// used simplify decay functions
double total_rainfall=0.0;  //used to sum up rainfall
int rain_day;  //used to sum up rainfall
int beta;		//used to dictate how many days to go back when accumulating rain
int theta;    //used to determine lag period before calculating accumulated rainfall
beta=Params->PARS[7];
theta=1;

double DDtemp_now;  //CIK// used simplify decay functions

double nuF2;
double nuR2;

double FIO_Cc;
double FIO_Cr;
double FIO_Oc;
double FIO_Or;

double DD10=0;    //accumulated degree days about 10 degrees C

//SH again, why do I need to declare these again
double vinfected; //SH to hold daily fraction infected
double finfected; //SH add coinfected eventually
double survivors; //SH = IF/IV etc divided by initial host density
double total;

double Fkill_cum=0; //SH to get accurate daily fraction infected
double Vkill_cum=0;
double dailydead;

// ----------------------------------- Generate Random Numbers -------------------------------------------- //
for (i=0;i<=MAXT3;i++)	{
	rand_nuR[i]=0;
	rand_nuF[i]=0;
	//rand_nuF[i]=gsl_cdf_gaussian_Pinv(RandNumsPass[i],Params->PARS[12]);
	//printf("i(%d)\t var1=%f\t var2=%f\t rand parts: nuR=%e\t nuF=%e\n",i,Params->PARS[11],Params->PARS[12],rand_nuR[i],rand_nuF[i]);
}//getc(stdin);
// ------------------------------------- Initial Conditions ---------------------------------------------- //
// THIS SHOULD BE A NEW FUNCTION (should be in main?? outside an extra loop??)//
	//printf("DDEVF check2 HERE!");		getc(stdin);

//CK//  Changing initial conditions for fungus only model.  Don't need to take out virus infected neonates
//CK//  Assume that all hatched bugs are susceptible to fungus
//CK//  Also going to convert to bugs per meter^2 for units of S(0), rather than egg masses per 1/40th of a hectare

Params->INITS[0] = Params->PARS[30+pop];			// initS
Params->INITS[3] = ave_R;												// initR  //CK// changed to use average R(0), not site-specific

// END OF NEW FUNCTION //
double initS = Params->INITS[0];			// initS
double initV = VPass;			// initV, passed from VPass in head file
double initR = Params->INITS[3];			// initR

// ----------------------------------------- Fixed Parameters ---------------------------------------------- //
int gstepsV		= (int) Params->PARS[8];	int gstepsF	= (int) Params->PARS[9];
double ratio = 1;
double neo_v	= 7.0;			// latent period of neonates (days) FUNGUS ONLY MODEL!
double R_end;   //CK//  Change value for function of latitude
double R_start;   //CK//  Change value for function of latitude

Params->PARS[0]=1.0;


// ------------------------------------- initialize model parameters --------------------------------------- //
int FlagWeek;	int FlagV=0;	int FlagR=0;	int FlagR_end=0;		// keep track of end of week
FlagV=1;  //At the beginning stage, part of the population is infected.
double ConiBefore=0.0;    //CK// Thing to store conidia the day before the feral collection
double RestBefore=0.0;    //CK// Thing to store resting spores the day before the feral collection

int day = 0; int week = 0;							// keeps track of day and week number

int line_ticker=0;   //CK// Ticker used to associate t in function with numbered days.
int line_ticker2;
int test_day=0;	//CK// used to find the line in the weather data that corresponds to the starting day of collections
int num_day =  hatch;  //CK// Starting day number


line_ticker = num_day;

line_ticker=line_ticker-1;

double S,V,F,R;	double IV=0, IF=0, IVF=0,IFV=0; //SH IFV captures coinfections
double E_V[n2+1]; double E_F[gstepsF+1]; double E_VF[n1+1]; double E_FV[gstepsF+1]; //VF: early infected virus that can be coinfected
//FV are coinfected indls
int num_weeks=MAXT3/7;



// -----------------------------------//CK// calculating ending blooming times //CK//--------------------------------------- //
/* //SH REMOVE BECAUSE WANT RESTING SPORES TO START BLOOMING FROM DAY 1
DD10=0.0;		R_start = 0.0;
test_day = line_ticker;

while(DD10 <= DDstart){

	DDtemp_now = Params->WDATA[0][test_day][3][0]-10.0;  //CK// begin calculation of accumulated Degree Days
	if(DDtemp_now<0.0){DDtemp_now=0.0;}
	DD10 = DD10 + DDtemp_now;			//CK// summing degree days over time
	R_start++;
	test_day++;
//printf("temp now: %f DD10: %f R_start: %f test_day: %d\n", DDtemp_now, DD10, R_start, test_day);		//getc(stdin);
}
//printf("temp now: %f DD10: %f R_start: %f test_day: %d\n", DDtemp_now, DD10, R_start, test_day);		//getc(stdin);
*/

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


// ---------------------------- Calculated Parameters  and Population Sizes ------------------------------- //
double Vstart = ratio*initV;						// viral cadavers after infected neonates die

double r_germ = R_start;		//CK// nixing r_time because I made all germ dates start at beginning of the collections
if (r_germ<0)	r_germ=0;
S=initS;
V=0; F=0.0; R=0.0;
for (i=1;i<=n2;i++)		{	E_V[i]=0;			}
for (i=1;i<=n1;i++)		{	E_VF[i]=0;		    }
for (i=1;i<=gstepsF;i++)		{	E_F[i]=0;	E_FV[i]=0;		}
double timing[6]={r_germ,R_end,MAXT3};

// ----------------------------------------- initialize results ------------------------------------------- //
double P[4] = {0,0,0,0};				// model results (0,healthy,viral kill,fungal kill)
double FRnext=0, Vkill=0, Fkill=0, Vnext=0;				// total individuals infected (used in calculating fraction infected)
double Vcadaver=0, Fcadaver=0;
double VirFI[100], FungFI[100];			// fraction of infected individals (by week number)
VirFI[0] = 0.0; VirFI[1] = 0.0; FungFI[0] = 0.0; FungFI[1] = 0.0;		// fraction infected first two weeks

// -------------------- MAIN LOOP!! (calculate populations as time is increased) -------------------------- //

while (t_0<MAXT3+h)	{    //CK// change MAXT to MAXT2 to let it go to the end of the experimental datasets?
	//if (week>=num_weeks)	break;
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
/*	// --------------------- infected neonates die -------------------- //
	else if (timing[0]<timing[1] && timing[0]<timing[2] && timing[0]<day+1)			{
		FlagV=1;
		t_next=timing[0];
		timing[0]=999.9;
		//printf("VIRAL INFECTED NEONATES DIE: t=%f\n",t_next);	//getc(stdin);
	}
*/	// --------------------- resting spores bloom -------------------- //
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
/*	// --------------------- infected neonates die and end of day -------------------- //
	else if (abs(day+1-timing[0])<epsilon)	{
		FlagV=1;
		t_next=day+1;
		timing[0]=999.9;
		day++;
		num_day++;
		line_ticker++;

		if (day%7==0)	{
			week++;
			FlagWeek=1;
		}
		//printf("end of day and Resting Spores bloom: t=%f\n",t_next);	getc(stdin);
	}
*/	// --------------------- resting spores bloom and end of day -------------------- //
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
	// -------------------------- integrate until next stoppage event ---------------------------------- //
	while (t<t_next)	{ //SH this is day
		y_ode[0]=S;	y_ode[m+n+1]=Fcadaver;	Params->POPS[3]=R;
		y_ode[m+n+3]=Vcadaver;

		for (i=1;i<=gstepsF;i++)	{
			y_ode[i]=E_F[i];
		}
		for (i=1;i<=n1;i++)	{
			y_ode[gstepsF+i]=E_VF[i];
		}
		for (i=1;i<=n2;i++)	{
			y_ode[gstepsF+n1+i]=E_V[i];
		}
		y_ode[m+n+2]=FRnext;
		y_ode[m+n+4]=Vkill;
		y_ode[m+n+5]=Fkill;
		y_ode[m+n+6]=Vnext;

		for (i=1;i<=gstepsF;i++)	{
			y_ode[m+n+6+i]=E_FV[i];
		}

		
		Params->nuV = Params->PARS[2];
		DDtemp_now = Params->WDATA[1][line_ticker - 1][4][0]-10.0;  //CK// begin calculation of accumulated Degree Days
		if(DDtemp_now<0.0){DDtemp_now=0.0;}
		DD10 = DD10 + DDtemp_now;			//CK// summing degree days over time
       

		nuF2 = specific_nuF*exp(RH_P*Params->WDATA[1][line_ticker - 1][6][0]) * exp(rand_nuF[(int)t]);    //JL: Reading in MinRH here
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
		
		nuR2=(rain_P/(1+rain_P2*exp(-rain_P3*total_rainfall)) - rain_P/(rain_P2+1))*exp(rand_nuR[(int)t]);  //JL: Should be the same as DDEVF for MCMC?
		if(nuR2> pow(10.0,10.0)){nuR2= pow(10.0,10.0);}

		Params->nuR = (DD10/fourth_size)*nuR2;
		if(Params->POPS[3] == 0.0){Params->nuR = 0.0; nuR2 = 0.0;}


		t=ODE_Solver(t,t_next,Params,y_ode);

		S=y_ode[0];	Fcadaver=y_ode[m+n+1]; Vcadaver=y_ode[m+n+3];
		FRnext=y_ode[m+n+2];			// killed populations
		Vkill=y_ode[m+n+4];
		Fkill=y_ode[m+n+5];			// killed populations
		Vnext=y_ode[m+n+6];

		IF=0;
		IV=0;
		IVF=0;
		IFV=0;

	if ((day+1)%7==0)	{
		ConiBefore=y_ode[m+1]*nuF2;  //CK// Saving the conidia 24 hours before feral collection
		RestBefore = Params->POPS[3]*nuR2;
	}
		for (i=1;i<=gstepsF;i++)	{
			E_F[i]=y_ode[i];
			IF += E_F[i];
		}

		for (i=1;i<=n1;i++)	{
			E_VF[i]=y_ode[gstepsF+i];
			IVF += E_VF[i];
		}

		for (i=1;i<=n2;i++)	{
			E_V[i]=y_ode[gstepsF+n1+i];
			IV += E_V[i];
		}

		for (i=1;i<=gstepsF;i++)	{
			E_FV[i]=y_ode[gstepsF+gstepsV+6+i];
			IFV += E_FV[i];
			//IF += (1-coinf_V)*E_FV[i]; //SH these are double counting coinfections I think.
			//IV += coinf_V*E_FV[i];
		}

		if (day==MAXT3-7){
            InfFungusWeekbefore=Fkill+IF;
            InfVirusWeekbefore=Vkill+IV;
            //Params->indexV=1;
		}

		if (day==MAXT3-19){
            InfFungusTwoWeekbefore=Fkill+IF;
            InfVirusTwoWeekbefore=Vkill+IV;
            Params->indexR=1;
            Params->size_C=0;
		}

		if (day==MAXT3-30){
            InfFungusMonthbefore=Fkill+IF;
            InfVirusMonthbefore=Vkill+IV;
            //Params->indexV=1;
            //Params->indexR=1;
            //if (Params->size_C==0){
            //    Params->indexR=1;
            //}
            //else {
            //    Params->size_C=0.5;
            //    Params->indexR=0.5;
            //}
		}

	}
	if (FlagV==1)			{	//printf("VIRAL INFECTED NEONATES DIE: t=%f\n",t_next);		//getc(stdin);
        Vcadaver=Vstart;
		FlagV=2;
	}

	//printf("t_0=%lf\n",t_0);
    //int tlag=t_0+Vdelayday;
	//if (tlag<64){
    //    Pdelay[tlag]=V;
    //    printf("Pdelay[%d]=%lf\n",tlag,Pdelay[tlag]);
    //}
	if (FlagR==1)			{	//printf("Resting spores bloom: t=%f\n",t_next);			//	getc(stdin);
		R=initR;
		FlagR=2;
	}

	else if (FlagR_end==1)	{	//printf("Resting spores done: t=%f\n",t_next);				// getc(stdin);
		R=0;
		FlagR_end=2;
	}


//Add daily plotting output here
	//if (FlagWeek==1 && PLOT==1.0)	{
    if (FlagDay==1 && PLOT==1.0)	{

		if ((S+IF)==0)	{
			Fprob=0;
		}
		else					{
			//VirFI[week]  = IV/(S+IV+IF);		// fraction infected at the end of each week
			Fprob = IF/(S+IF);
		}
		p1 = y_ode[m+n+1]*Params->nuF;
		p2 = Params->POPS[3]*Params->nuR;

		//p1 = 1-(Fprob);
		//p2 = 0;  			//CK//	formerly virus infected
		p3 = Fprob;


		c1 = y_ode[m+n+1]*nuF2;
		r1 = Params->POPS[3]*nuR2;

	
		Cpar = cover_C*((c1+c2)/2) + cover_R*((r1+r2)/2);
		Opar = open_C*((c1+c2)/2) + open_R*((r1+r2)/2);	//uncovered cages

		//printf("cover_C=%e, cover_R=%e, open_C=%e, open_R=%e\n",cover_C, cover_R, open_C, open_R);
		//printf("c1=%e, c2=%e, r1=%e, r2=%e, nuF2=%e, nuR2=%e\n",c1,c2,r1,r2,nuF2,nuR2);

		FIO_Cc = cover_C*((c1+c2)/2);
		FIO_Cr =  cover_R*((r1+r2)/2);
		FIO_Oc = open_C*((c1+c2)/2);
		FIO_Or = open_R*((r1+r2)/2);

		Cprob = exp(-Cpar);	Oprob = exp(-Opar);

//		printf("%d\t %d\t %f\t %f\t %f\t %f\t\n",pop,day,prob,1.0-prob, prob2, prob3); // getc(stdin);

		Cprob2 = (( cover_C*((c1+c2)/2))/(cover_C*((c1+c2)/2) + cover_R*((r1+r2)/2)))*((1 - Cprob));  //OPEN fraction of F infection due to conidia
		Cprob3 = ((cover_R*((r1+r2)/2))/(cover_C*((c1+c2)/2) + cover_R*((r1+r2)/2)))*((1 - Cprob));  //fraction of F infection due to resting spores
		Oprob2 = ((open_C*((c1+c2)/2))/(open_C*((c1+c2)/2) + open_R*((r1+r2)/2)))*((1 - Oprob));  //OPEN fraction of F infection due to conidia
		Oprob3 = ((open_R*((r1+r2)/2))/(open_C*((c1+c2)/2) + open_R*((r1+r2)/2)))*((1 - Oprob));  //fraction of F infection due to resting spores

		if(Cprob == 1.0){Cprob2=0.0; Cprob3=0.0;}
		if(Oprob == 1.0){Oprob2=0.0; Oprob3=0.0;}

		//printf("%d\t %e\t %e\t %e\n", day-1, S, IV, IF);
		//SH below line prints daily output to global file fp1
		//fprintf(fp1, "%d\t %d\t %d\n", S/initS, IV/initS, IF/initS);
        //fprintf(fp1, "%d\t %d\t %e\t %e\t %e\t %e\t %e\t %e\t %e\t %e\t %e\n",pop,day-1,initS,y_ode[0],Fkill,Vkill,Fcadaver,Vcadaver,IF,IV,y_ode[0]+Fkill+Vkill+IV+IF); //getc(stdin);
		//SH yode[0] host at end of day, IV/IF: individuals in exposed classes (i.e. infected but not yet killed)

        //printf("%d\t %d\t %e\t %e\t %e\t %e\t %e\t %e\t %e\t %e\t %e\n",pop,day-1,initS,y_ode[0],Fkill,Vkill,Fcadaver,Vcadaver,IF,IV,y_ode[0]+Fkill+Vkill+IV+IF); //getc(stdin);
		//SH need to keep a running tab of death to find out daily density to get accurate daily fraction infected.
		/*
		Fkill_cum = Fkill_cum + Fkill;
		Vkill_cum = Vkill_cum + Vkill;
		dailydead = initS-Fkill_cum-Vkill_cum;

		printf("%e\t %e\t %e\t %e\t %e\n", Fkill, Fkill_cum, Vkill, Vkill_cum, dailydead);
		*/

//*******************************Appends output for each treatment run based on one epizootic length of 48**************************//
		//printf("Value of k %i\n", k);
		if (k == 1){
			sim_output[day-1][0] = S/(y_ode[0]+IV+IF+IVF); //Saving daily fraction uninfected S 
			sim_output[day-1][1] = IV/(y_ode[0]+IV+IF+IVF); //Saving daily fraction infected V 
			sim_output[day-1][2] = IF/(y_ode[0]+IV+IF+IVF); //Saving daily fraction infected F
			sim_output[day-1][3] = IFV/(y_ode[0]+IV+IF+IVF); //Saving daily fraction coinfected 
		}
		else if (k == 2){
			sim_output[day-1+47][0] = S/(y_ode[0]+IV+IF+IVF); //Saving daily fraction uninfected S 
			sim_output[day-1+47][1] = IV/(y_ode[0]+IV+IF+IVF); //Saving daily fraction infected V 
			sim_output[day-1+47][2] = IF/(y_ode[0]+IV+IF+IVF); //Saving daily fraction infected F
			sim_output[day-1+47][3] = IFV/(y_ode[0]+IV+IF+IVF); //Saving daily fraction coinfected 
		}
		else if (k == 3){
			sim_output[day-1+95][0] = S/(y_ode[0]+IV+IF+IVF); //Saving daily fraction uninfected S 
			sim_output[day-1+95][1] = IV/(y_ode[0]+IV+IF+IVF); //Saving daily fraction infected V 
			sim_output[day-1+95][2] = IF/(y_ode[0]+IV+IF+IVF); //Saving daily fraction infected F
			sim_output[day-1+95][3] = IFV/(y_ode[0]+IV+IF+IVF); //Saving daily fraction coinfected 
		}
		else if (k == 4){
			sim_output[day-1+143][0] = S/(y_ode[0]+IV+IF+IVF); //Saving daily fraction uninfected S 
			sim_output[day-1+143][1] = IV/(y_ode[0]+IV+IF+IVF); //Saving daily fraction infected V 
			sim_output[day-1+143][2] = IF/(y_ode[0]+IV+IF+IVF); //Saving daily fraction infected F
			sim_output[day-1+143][3] = IFV/(y_ode[0]+IV+IF+IVF); //Saving daily fraction coinfected 
		}
		
		fprintf(fp1, "%i\t %d\t %e\t %e\t %e\t %e\n", k, day-1, S/(y_ode[0]+IV+IF+IVF), IV/(y_ode[0]+IV+IF+IVF), IF/(y_ode[0]+IV+IF+IVF), IFV/(y_ode[0]+IV+IF+IVF));


		c2=c1;	r2=r1;   //make today's C and R yesterday's C and R
        //printf("c2=%e,r2=%e\n",c2,r2);
		FlagDay=0;
		//FlagWeek=0;
	//printf("Rstart:%e\t Rend:%e\t R=%e\t nuF=%e\t nuR=%e\t muF=%e\n",R_start, R_end,R,Params->nuF,Params->nuR,Params->muF);
	//printf("%d\t %e\t %e\n",day-1,Params->size_C,Params->indexR);

	//fprintf(fp1, "%d\t %d\t %e\t %e\t %e\t %e\t %e\t %e\t %e\t %e\t %e\t %e\t %e\n",pop,day-1,initS,y_ode[0],Fkill,FRnext,Vkill,Vnext,Fcadaver,Vcadaver,Fkill+IF+IVF,Vkill+IV,y_ode[0]+Fkill+Vkill+IV+IF+IVF);

	}

//Done with daily plotting output here


	// ---------------------------- end of the week updates ---------------------------------- //

t_0=t_next;
//printf("t_0=%lf\n",t_0);
}
SusEnd=y_ode[0]; //susceptibles at end of day 

if (initR==0){
   InfVirusEnd=Vkill+IV+IVF;
   InfFungusNext=0;
   InfFungusEnd=0;
   InfVirusNext=Vkill+IV+IVF;
}
else{
   InfVirusEnd=Vkill+IV+IVF;
   InfFungusNext=FRnext+IF;
   InfFungusEnd=Fkill+IF;
   InfVirusNext=Vkill+IV+IVF;
}
InfFungusAdj=InfFungusEnd-InfFungusWeekbefore;
InfVirusAdj=InfVirusEnd-InfVirusWeekbefore;

return 0;
}
