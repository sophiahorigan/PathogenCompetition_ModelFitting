// DDEVF sets up model and calls 0DE_SOLVER, returns Params->sim_results

double DDEVF(void *Paramstuff,gsl_rng *RandNumsPass,size_t dim,int pop,int maxy_t, double hatch, int q) //SH DOES save into array

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

//int k = tmt; //SH looping through treamtent numbers below

int n = Params->PARS[8]; //number of virus exposed classes
int m = Params->PARS[9]; //number of fungus exposed classes
int DIM = 4*(m+n+4+2+1+m); //SH multipled by 4 to hold all equations

VFPass=exposetime-1/Params->PARS[18]; 

int n1=(VFPass/exposetime)*Params->PARS[8];    //The number of the first group of exposed classes to virus
int n2=n-n1;                  //The number of the first group of exposed classes to virus

double t=h;		double t_next=h;	double t_0=h;	int i;	int j;			// time loop and index
double epsilon = pow(10,-6);
double y_ode[DIM]; //**SH** this holds 
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


// ----------------------------------- Generate Random Numbers -------------------------------------------- //
for (i=0;i<=MAXT3;i++)	{
	rand_nuR[i]=0;
	rand_nuF[i]=0;
	//rand_nuF[i]=gsl_cdf_gaussian_Pinv(RandNumsPass[i],Params->PARS[12]);
	//printf("i(%d)\t var1=%f\t var2=%f\t rand parts: nuR=%e\t nuF=%e\n",i,Params->PARS[11],Params->PARS[12],rand_nuR[i],rand_nuF[i]);
}//getc(stdin);




// ------------------------------------- Initial Conditions ---------------------------------------------- //

Params->INITS[0] = Params->PARS[30+pop];			// initS
Params->INITS[3] = ave_R;												// initR  //CK// changed to use average R(0), not site-specific

// END OF NEW FUNCTION //
//EVENTUALLY MAKE FIT SH
double initS = Params->INITS[0];			// initS
double initV = VPass;			// initV, passed from VPass in head file
double initR = Params->INITS[3];			// initR



// ----------------------------------------- Fixed Parameters ---------------------------------------------- //
int gstepsV		= (int) Params->PARS[8];	int gstepsF	= (int) Params->PARS[9]; //gstepsV = m, gstepsF = n
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

int num_weeks=MAXT3/7;

// ******************************************************** //SH// TREATMENT STRUCTURE //SH// ******************************************************** //

int num_tmts = 4;

//state variable declaration
double S[num_tmts]; double V[num_tmts]; double F[num_tmts]; double R[num_tmts];
double IV[num_tmts]; double IF[num_tmts]; double IVF[num_tmts]; double IFV[num_tmts];

//exposed class declaratoin
double E_V[num_tmts][n2+1]; double E_F[num_tmts][gstepsF+1]; double E_VF[num_tmts][n1+1]; double E_FV[num_tmts][gstepsF+1];

//treatment indexing to fill arrays


// -----------------------------------//CK// calculating ending blooming times //CK//--------------------------------------- //

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
double Vstart = ratio*initV;						// viral cadavers after infected neonates die //SH need to make 4x?

double r_germ = R_start;		//CK// nixing r_time because I made all germ dates start at beginning of the collections
if (r_germ<0)	r_germ=0;

// ----------------------------------------- initialize results ------------------------------------------- //

//single epizootic state params
for(i=0; i<4; i++){ 
	S[i] = initS;
	V[i] = 0;
	F[i] = 0;
	R[i] = 0;

	for (j=1;j<=n2;j++){
		E_V[i][j]=0;
	}
	for (j=1;j<=n1;j++){
		E_VF[i][j]=0;
	}
	for (j=1;j<=gstepsF;j++){
		E_F[i][j]=0;
		E_FV[i][j]=0;
	}

}


//long-term state params
double Vnext[num_tmts];
double Vkill[num_tmts];
double Vcadaver[num_tmts];

double Fnext[num_tmts];
double Fkill[num_tmts];
double Fcadaver[num_tmts];

for(i=0; i<4; i++){ //Will need to fit!!
	Vnext[i] = 0;
	Vkill[i] = 0;
	Vcadaver[i] = 0;
	Fnext[i] = 0;
	Fkill[i] = 0;
	Fcadaver[i] = 0;
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


	// -------------------------- integrate until next stoppage event ---------------------------------- //
	
	//indexing variables
	int tmt;
	int tmt_index[num_tmts];
	int max_class = m+n+7+gstepsF;
	tmt_index[0] = 0; //treatment 1 index addition is zero
	for(tmt=1; tmt<num_tmts; tmt++){	//create tmt array 
		tmt_index[tmt] = tmt_index[tmt-1]+ max_class; //SH can maybe multiply 
		printf("tmt_index=%i", tmt_index[tmt]);
	}
	

	while (t<t_next)	{ //for one day
		
		for(tmt=0; tmt<4; tmt++){ //for each treatment
			y_ode[0+tmt_index[tmt]]=S[tmt];	y_ode[m+n+1+tmt_index[tmt]]=Fcadaver[tmt];	Params->POPS[3]=R[tmt];
			//printf("initS[%i] = %e\n", tmt, S[tmt]);
			printf("y_ode[%i] = %e\n", tmt_index[tmt], y_ode[0+tmt_index[tmt]]);
			y_ode[m+n+3+tmt_index[tmt]]=Vcadaver[tmt];
			
			for (i=1;i<=gstepsF;i++)	{
				y_ode[i+tmt_index[tmt]]=E_F[tmt][i+tmt_index[tmt]];
			}
			for (i=1;i<=n1;i++)	{
				y_ode[gstepsF+i+tmt_index[tmt]]=E_VF[tmt][i+tmt_index[tmt]];
			}
			for (i=1;i<=n2;i++)	{
				y_ode[gstepsF+n1+i+tmt_index[tmt]]=E_V[tmt][i+tmt_index[tmt]];
			}
			y_ode[m+n+2+tmt_index[tmt]]=Fnext[tmt];
			y_ode[m+n+4+tmt_index[tmt]]=Vkill[tmt];
			y_ode[m+n+5+tmt_index[tmt]]=Fkill[tmt];
			y_ode[m+n+6+tmt_index[tmt]]=Vnext[tmt];

			for (i=1;i<=gstepsF;i++)	{
				y_ode[m+n+6+i+tmt_index[tmt]]=E_FV[tmt][i+tmt_index[tmt]]; //end of fill for each treatment
			}
		}




		//******************************* Weather Stuff ******************************//
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



//*** add dispersal here! use migration function to calculate movement based on current value of E_F
//*** ADD
// add into params, which passes to ODE_Solver
//
//	for treatment 1
//   net1 = dispersal_func(dispersal_param, d2,1)*densities? + dispersal_func(dispersal_param, d3,1) + dispersal_func(dispersal_param, d4,1)
//				- dispersal_func(dispersal_param, d1,2)
//?? where do densities go, out here or in the ode-sovler? 
//
//
//
//
//
//
//


//********************************************************
		t=ODE_Solver(t,t_next,Params,y_ode);
//********************************************************
		



//update state variables
	for(tmt=0; tmt<4; tmt++){
		S[tmt]=y_ode[0+tmt_index[tmt]];
		Fcadaver[tmt]=y_ode[m+n+1+tmt_index[tmt]]; 
		Vcadaver[tmt]=y_ode[m+n+3+tmt_index[tmt]];
		Fnext[tmt]=y_ode[m+n+2+tmt_index[tmt]];			
		Vkill[tmt]=y_ode[m+n+4+tmt_index[tmt]];
		Fkill[tmt]=y_ode[m+n+5+tmt_index[tmt]];			
		Vnext[tmt]=y_ode[m+n+6+tmt_index[tmt]];
		IF[tmt]=0;
		IV[tmt]=0;
		IVF[tmt]=0;
		IFV[tmt]=0;
	}
		

	//*** SH START BELOW TO REPLICATE**//

	//SH check to see if I need this, given that I don't have cages
	if ((day+1)%7==0)	{
		ConiBefore=y_ode[m+1]*nuF2;  //CK// Saving the conidia 24 hours before feral collection
		RestBefore = Params->POPS[3]*nuR2;
	}

	for(tmt=0; tmt<4; tmt++){	
	
		for (i=1;i<=gstepsF;i++)	{
			E_F[tmt][i+tmt_index[tmt]]=y_ode[i+tmt_index[tmt]];
			IF[tmt] += E_F[tmt][i+tmt_index[tmt]];
		}

		for (i=1;i<=n1;i++)	{
			E_VF[tmt][i+tmt_index[tmt]]=y_ode[gstepsF+i+tmt_index[tmt]];
			IVF[tmt] += E_VF[tmt][i+tmt_index[tmt]];
		}

		for (i=1;i<=n2;i++)	{
			E_V[tmt][i+tmt_index[tmt]]=y_ode[gstepsF+n1+i+tmt_index[tmt]];
			IV[tmt] += E_V[tmt][i+tmt_index[tmt]];
		}

		for (i=1;i<=gstepsF;i++)	{
			E_FV[tmt][i+tmt_index[tmt]]=y_ode[gstepsF+gstepsV+6+i+tmt_index[tmt]];
			IFV[tmt] += E_FV[tmt][i+tmt_index[tmt]];
			//IF += (1-coinf_V)*E_FV[i]; //SH these are double counting coinfections I think.
			//IV += coinf_V*E_FV[i];
		}

	}

		/*//I think I can delete the stuff below?

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


//*************************SH below line prints daily output to global file fp1 **************/
//fprintf(fp1, "%d\t %d\t %d\n", S/initS, IV/initS, IF/initS);
//fprintf(fp1, "%d\t %d\t %e\t %e\t %e\t %e\t %e\t %e\t %e\t %e\t %e\n",pop,day-1,initS,y_ode[0],Fkill,Vkill,Fcadaver,Vcadaver,IF,IV,y_ode[0]+Fkill+Vkill+IV+IF); //getc(stdin);
//SH yode[0] host at end of day, IV/IF: individuals in exposed classes (i.e. infected but not yet killed)

//printf("%d\t %d\t %e\t %e\t %e\t %e\t %e\t %e\t %e\t %e\t %e\n",pop,day-1,initS,y_ode[0],Fkill,Vkill,Fcadaver,Vcadaver,IF,IV,y_ode[0]+Fkill+Vkill+IV+IF); //getc(stdin);


//*******************************Appends output for each treatment run based on one epizootic length of 48**************************//

		//LOOP THROUGH ARRAYS
	int day_index[4] = {0, 47, 95, 143}; //to append 48 day epizootics //probably a better way to do this
	
	for(tmt=0; tmt<4; tmt++){	

		sim_output[day-1+day_index[tmt]][0] = S[tmt]/(y_ode[0+tmt_index[tmt]]+IV[tmt]+IF[tmt]+IVF[tmt]); //Saving daily fraction uninfected S 
		sim_output[day-1+day_index[tmt]][1] = IV[tmt]/(y_ode[0+tmt_index[tmt]]+IV[tmt]+IF[tmt]+IVF[tmt]); //Saving daily fraction infected V 
		sim_output[day-1+day_index[tmt]][2] = IF[tmt]/(y_ode[0+tmt_index[tmt]]+IV[tmt]+IF[tmt]+IVF[tmt]); //Saving daily fraction infected F
		sim_output[day-1+day_index[tmt]][3] = IFV[tmt]/(y_ode[0+tmt_index[tmt]]+IV[tmt]+IF[tmt]+IVF[tmt]); //Saving daily fraction coinfected 
	
	}

	//SH need to fix print statement
	//fprintf(fp1, "%d\t %e\t %e\t %e\t %e\n %e\t %e\t %e\t %e\t %e\t %e\t %e\t %e\t %e\t %e\t %e\t %e\n", day-1, S_1/(y_ode[0]+IV_1+IF_1+IVF_1), IV_1/(y_ode[0]+IV_1+IF_1+IVF_1), IF_1/(y_ode[0]+IV_1+IF_1+IVF_1), IFV_1/(y_ode[0]+IV_1+IF_1+IVF_1), S_2/(y_ode[0]+IV_2+IF_2+IVF_2), IV_2/(y_ode[0]+IV_2+IF_2+IVF_2), IF_2/(y_ode[0]+IV_2+IF_2+IVF_2), IFV_2/(y_ode[0]+IV_2+IF_2+IVF_2), S_3/(y_ode[0]+IV_3+IF_3+IVF_3), IV_3/(y_ode[0]+IV_3+IF_3+IVF_3), IF_3/(y_ode[0]+IV_3+IF_3+IVF_3), IFV_3/(y_ode[0]+IV_3+IF_3+IVF_3), S_4/(y_ode[0]+IV_4+IF_4+IVF_4), IV_4/(y_ode[0]+IV_4+IF_4+IVF_4), IF_4/(y_ode[0]+IV_4+IF_4+IVF_4), IFV_4/(y_ode[0]+IV_4+IF_4+IVF_4));


		//c2=c1;	r2=r1;   //make today's C and R yesterday's C and R
        //printf("c2=%e,r2=%e\n",c2,r2);
		//FlagDay=0;
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
/* //SH end of epizootic info

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
*/
return 0;
}
