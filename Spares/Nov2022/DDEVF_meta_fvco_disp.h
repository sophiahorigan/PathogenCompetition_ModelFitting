// DDEVF sets up model and calls 0DE_SOLVER, returns Params->sim_results

double DDEVF(void *Paramstuff, double *RandNumsPass ,size_t dim,int pop,int maxy_t, double hatch, int q, int dataset) //SH DOES save into array

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

int MAXT3=47;

//there! j= %i\n", j);

//-------------------------------------- METAPOPULATION STRUCTURE -------------------------------------------//

int num_sub;
Params->j = dataset;
int j = Params->j;
//printf("j in DDEVF = %i, PARAMS j = %i, j = %i\n", dataset, Params->j, j);

// SUBS
// SUB 1 (0) = FUNGUS-ONLY
// SUB 2 (1) = VIRUS-ONLY
// SUB 3 (2) = FUNGUS-VIRUS
// SUB 4 (3) = CONTROL

if (j==1 || j==2 || j==3) { //epi data
	//printf("In loop one j= %i\n", j);
	Params->numsub=4;
	num_sub = Params->numsub; 
	//printf("In loop one num_sub = %i\n", num_sub);
}
if (j==4 || j==5 || j==6) { // obs data
	//printf("In loop two j= %i\n", j);	
	Params->numsub=1;
	num_sub = Params->numsub;
	//printf("In loop two num_sub = %i\n", num_sub);
}

int larvae_dispersal_on = 0; //set to 0 for no dispersal

//printf("numsub = %i", num_sub);

//-------------------------------------- PARAMETER DECLARATION -------------------------------------------//


int n = Params->PARS[8]; //number of virus exposed classes
int m = Params->PARS[9]; //number of fungus exposed classes
int DIM = num_sub*(m+n+4+2+1+m); //SH multipled by 4 to hold all equations
//printf("j = %i\t num_sub = %i\t DIM = %i\n", j, num_sub, DIM);	

VFPass=exposetime-1/Params->PARS[18]; 

int n1=(VFPass/exposetime)*Params->PARS[8];    //The number of the first group of exposed classes to virus
int n2=n-n1;                  //The number of the first group of exposed classes to virus

double t=h;		double t_next=h;	double t_0=h;	int i;	int ii;			// time loop and index
double epsilon = pow(10,-6);
double y_ode[DIM]; 
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
double R_seed = 0.05;

// --------------------------------------- STOCHASTICITY -------------------------------------------- //
for (i=0;i<=MAXT3;i++)	{
	if (j==1 || j==2 || j==3){
	rand_nuR[i]=gsl_cdf_gaussian_Pinv(RandNumsPass[i],Params->Rsd_exp);
	rand_nuF[i]=gsl_cdf_gaussian_Pinv(RandNumsPass[i+MAXT3],Params->Fsd_exp);
	}
	if (j==4 || j==5 || j==6){
	rand_nuR[i]=gsl_cdf_gaussian_Pinv(RandNumsPass[i],Params->Rsd_obs);
	rand_nuF[i]=gsl_cdf_gaussian_Pinv(RandNumsPass[i+MAXT3],Params->Fsd_obs);	
	}
	//printf("randon nuR = %lf\t, random nuF = %lf\n", rand_nuR[i], rand_nuF[i]);
}//getc(stdin);


// ------------------------------------- INITIAL CONDITIONS ---------------------------------------------- //

Params->INITS[0] = Params->PARS[30+pop];			// initS
Params->INITS[3] = ave_R;												// initR  //CK// changed to use average R(0), not site-specific

// END OF NEW FUNCTION //
//EVENTUALLY MAKE FIT SH
double initS = Params->INITS[0];			// initS
double initV = VPass;			// initV, passed from VPass in head file
double initR = Params->INITS[3];			// initR



// ----------------------------------------- FIXED PARAMETERS  ---------------------------------------------- //

int gstepsV		= (int) Params->PARS[8];	int gstepsF	= (int) Params->PARS[9]; //gstepsV = m, gstepsF = n
double ratio = 1;
double neo_v	= 7.0;			// latent period of neonates (days) FUNGUS ONLY MODEL!
double R_end;   //CK//  Change value for function of latitude
double R_start;   //CK//  Change value for function of latitude

Params->PARS[0]=1.0;


// ------------------------------------- INITIALIZE MODEL PARAMETERS --------------------------------------- //

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

int num_weeks=48/7;

//SH CHECK WITH GREG
//state variable declaration
double S[num_sub]; double V[num_sub]; double C[num_sub]; double R[num_sub];
double IV[num_sub]; double IF[num_sub]; double IVF[num_sub]; double IFV[num_sub];

//exposed class declaratoin
double E_V[num_sub][n2+1]; double E_F[num_sub][gstepsF+1]; double E_VF[num_sub][n1+1]; double E_FV[num_sub][gstepsF+1];

//treatment indexing to fill arrays


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

double Vstart = ratio*initV;						// viral cadavers after infected neonates die //SH need to make 4x?

double r_germ = R_start;		//CK// nixing r_time because I made all germ dates start at beginning of the collections
if (r_germ<0)	r_germ=0;

double INITS[4];
double INITV[4];
double INITR[4];

if (j==1 || j==2 || j==3){
	for(i=0; i<num_sub; i++){
		INITS[i] = Params->FITINIT[j][i];
		INITV[i] = Params->FITINIT[j][i+num_sub];
		INITR[i] = Params->FITINIT[j][i+num_sub+num_sub];
	}
	//printf("j = %i\t initS = %lf\t initV = %lf\t initR = %lf\n");
}
if (j==4 || j==5 || j==6){
	INITS[0] = Params->FITINIT[j][0];
	INITV[0] = Params->FITINIT[j][4];
	INITR[0] = Params->FITINIT[j][8];
}

// ----------------------------------------- INITIALIZE RESULTS ------------------------------------------- //

//single epizootic state params
//printf("numsub = %i\n", num_sub);
for(i=0; i<num_sub; i++){ 
	S[i] = INITS[i];
	V[i] = INITV[i]; 
	C[i] = 0;
	R[i] = INITR[i];
	//printf("J = %i\t, INITIAL CONDITIONS: S=%lf\t, V=%lf\t, R=%lf\n",j, num_sub, S[i], V[i], R[i]);

	for (ii=1;ii<=n2;ii++){ //SH ASK GREG: WHY DOES THIS START AT 1
		E_V[i][ii]=0;
	}
	for (ii=1;ii<=n1;ii++){
		E_VF[i][ii]=0;
	}
	for (ii=1;ii<=gstepsF;ii++){
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

	
//indexing variables
int sub;
//int sub_index[num_sub];
//int max_class = m+n+7+gstepsF;
//sub_index[0] = 0; //treatment 1 index addition is zero
//sub_index[1] = 127;
//sub_index[2] = 254;
//sub_index[3] = 381;

const int sub_index[4] = {0, 127, 254, 381};
/*
for(sub=1; sub<num_sub; sub++){	//create sub array 
	sub_index[sub] = sub_index[sub-1]+ max_class; //SH can maybe multiply 
	//printf("sub_index=%i\n", sub_index[sub]);
}*/

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

	while (t<t_next)	{
	//printf("day = %i\n", day-1);

	//---------------------- LARVAL DISPERSAL ----------------------------//
	if(day-1<8){ //dispersal only occurs as first instars, 1 week
		
		if (j==1 || j==2 || j==3) { //only for datasets with subpopulations
		
			if(larvae_dispersal_on == 1){
			
			//printf("day = %i\n", day-1);
			
				//indexing
				int subout;
				int subin;
				double netVin[num_sub][n2]; //one for each subpop 0-3
				double netVout[num_sub][n2]; //one for each subpop 0-3
				double netVFout[num_sub][n1]; //one for each subpop 0-3
				double netVFin[num_sub][n1]; //one for each subpop 0-3
				//dummy param
				double disp = 0;
		
				//initialize dispersal array
				for(sub=0; sub<num_sub; sub++){
					for(i=1;i<=n1;i++){
						netVFout[sub][i] = 0;
						netVFin[sub][i] = 0;
					}
					for (ii=1;ii<=n2;ii++)	{
						netVout[sub][ii] = 0;
						netVin[sub][ii] = 0;
					}
				}

				for(subout = 0; subout < num_sub; subout++){ //for i
				//printf("subout loop subout = %i\n", subout);
					//printf("subout = %i\n", subout);
					for(subin = 0; subin < num_sub; subin++){ //for j
					//printf("subin loop subin = %i\n", subin);
						if(subout != subin){
							//printf("subout = %i\t subin = %i\n", subout, subin);
							for (i=1;i<=n1;i++)	{ //for each exposed class
								disp = E_VF[subout][i]*Params->lar_mgr*exp(-Params->a2*Params->DISTANCE[j][subout][subin]);
								//printf("j = %i\t subout = %i\t subin = %i\t distance = %i\n", j, subin, subout, Params->DISTANCE[j][subout][subin]);
								//printf("Evf = %lf\t larmgr = %lf\t a = %lf\t distance = %i\t exp = %lf\n",E_VF[subout][i], Params->lar_mgr, Params->a2, Params->DISTANCE[j][subout][subin], exp(-Params->a2*Params->DISTANCE[j][subout][subin]));
								//printf("disp out VF = %lf\n", disp);
								netVFout[subout][i] = netVFout[subout][i] + disp;
								netVFin[subin][i] = netVFin[subin][i] + disp;
								//printf("netvfout = %lf\t netfvin = %lf\n",netVFout[subout][i],netVFin[subin][i]);
								//printf("n1 loop n1 = %i\n", i);
							}
							for (ii=1;ii<=n2;ii++)	{
								disp = E_V[subout][ii]*Params->lar_mgr*exp(-Params->a2*Params->DISTANCE[j][subout][subin]);
								//printf("disp out V = %lf", disp);
								netVout[subout][ii] = netVout[subout][ii] + disp;
								netVin[subin][ii] = netVin[subin][ii] + disp;
								//printf("netvout = %lf\t netvin = %lf\n",netVout[subout][i],netVin[subin][i]);
								//printf("n2 loop n2 = %i\n", ii);
							}
						}
						else{
							//printf("done! subout = %i\t subin = %i\n", subin, subout);
						}
					}
				}
				for(sub=0; sub<num_sub; sub++){ //update larval density
				//printf("UPDATES = %i\t subindex sub = %i\n", sub, sub_index[sub]);
				//printf("made it in?\n");
					for (i=1;i<=n1;i++)	{ //for each exposed class
						E_VF[sub][i] = E_VF[sub][i] + netVFin[sub][i] - netVFout[sub][i];
						//printf("EVF = %lf\n", E_VF[sub][i]);
					}
					for (i=1;i<=n2;i++)	{
						E_V[sub][i] = E_V[sub][i] + netVin[sub][i] - netVout[sub][i];
						//printf("EV = %lf\n", E_V[sub][i]);
					}
				}
			} 
		}
	}	                        


	//-------------------------------------- DAILY UPDATE OF Y_ODE -------------------------------------------//
		printf("day = %i\n", day);
		//printf("check 1\n");
		for(sub=0; sub<num_sub; sub++){ //for each treatment
		//printf("sub = %i\t subindex sub = %i\n", sub, sub_index[sub]);

			y_ode[0+sub_index[sub]]=S[sub];
	
			y_ode[m+n+1+sub_index[sub]]=C[sub];
			printf("C[%i]\t = %e\n", sub, C[sub]);

			Params->POPS[3]=R[sub];
	
			
			//printf("y_ode[%i] = %e\n", sub_index[sub], y_ode[0+sub_index[sub]]);
			y_ode[m+n+3+sub_index[sub]]=V[sub];
			//printf("check 1.6\n");
			
			
			for (i=1;i<=gstepsF;i++)	{
				y_ode[i+sub_index[sub]]=E_F[sub][i];
				//printf("check 1.36\n");
			}
			for (i=1;i<=n1;i++)	{
				y_ode[gstepsF+i+sub_index[sub]]=E_VF[sub][i];
				//printf("sub = %i\t EVF = %lf\n", sub, E_VF[sub][i+sub_index[sub]]);
				//printf("check 1.46\n");
			}
			for (i=1;i<=n2;i++)	{
				y_ode[gstepsF+n1+i+sub_index[sub]]=E_V[sub][i];
				//printf("sub = %i\t EV = %lf\n", sub, E_V[sub][i+sub_index[sub]]);
				//printf("check 1.56\n");
			}
			y_ode[m+n+2+sub_index[sub]]=Fnext[sub];
			y_ode[m+n+4+sub_index[sub]]=Vkill[sub];
			y_ode[m+n+5+sub_index[sub]]=Fkill[sub];
			y_ode[m+n+6+sub_index[sub]]=Vnext[sub];

			for (i=1;i<=gstepsF;i++)	{
				y_ode[m+n+6+i+sub_index[sub]]=E_FV[sub][i]; //end of fill for each treatment
				//printf("check 1.66\n");
			}
			//printf("sub = %i\t C = %lf\t V = %lf\n", sub, C[sub], V[sub]);
		}
		
		/*
		int k;
		for(k=0; k<DIM; k++){
			printf("y_ode[%i]=%e\n", k, y_ode[k]);
			//getc(stdin);
		}
		*/


	//******************************* Weather Stuff ******************************//
	//printf("check 2\n");
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


//********************************************************
		t=ODE_Solver(t,t_next,Params,y_ode);
//********************************************************

/*		
for(k=0; k<DIM; k++){
	printf("y_ode[%i]=%e\n", k, y_ode[k]);
	//getc(stdin);
}
*/
//printf("check 3\n");
//update state variables
	for(sub=0; sub<num_sub; sub++){
		//printf("in the sub\n");
		//printf("subindex sub = %i\n", sub_index[sub]);
		S[sub]=y_ode[0+sub_index[sub]]; //SH ASK GREG: FOR OBS SITE, THIS ISN'T GETTING UPDATED
		//printf("S[%i] = %e\n", sub, S[sub]);
		//printf("yode=%lf\n",  y_ode[0+sub_index[sub]]);
		C[sub]=y_ode[m+n+1+sub_index[sub]]; //fungus cadavers?
		//printf("C[%i] = %e\n", sub, C[sub]);
		V[sub]=y_ode[m+n+3+sub_index[sub]]; //virus cadavers?
		//printf("V[%i] = %e\n", sub, V[sub]);
		Fnext[sub]=y_ode[m+n+2+sub_index[sub]];			
		Vkill[sub]=y_ode[m+n+4+sub_index[sub]];
		Fkill[sub]=y_ode[m+n+5+sub_index[sub]];			
		Vnext[sub]=y_ode[m+n+6+sub_index[sub]];
		IF[sub]=0;
		IV[sub]=0;
		IVF[sub]=0;
		IFV[sub]=0;
	}
		
//printf("check 4\n");
	//SH check to see if I need this, given that I don't have cages
	if ((day+1)%7==0)	{
		ConiBefore=y_ode[m+1]*nuF2;  //CK// Saving the conidia 24 hours before feral collection
		RestBefore = Params->POPS[3]*nuR2;
	}


	//sum daily infected across exposed classes
	for(sub=0; sub<num_sub; sub++){	
	//printf("check 5\n");
		for (i=1;i<=gstepsF;i++)	{
			E_F[sub][i]=y_ode[i+sub_index[sub]];
			IF[sub] += E_F[sub][i];
			//printf("EF = %lf\t IF = %lf\n", E_F[sub][i], IF[sub]);
		}

		for (i=1;i<=n1;i++)	{ //early virus infections which can be coinfected
			E_VF[sub][i]=y_ode[gstepsF+i+sub_index[sub]];
			IVF[sub] += E_VF[sub][i];
			//printf("E_VF = %lf\t IVF = %lf\n", E_VF[sub][i], IVF[sub]);
		}

		for (i=1;i<=n2;i++)	{
			E_V[sub][i]=y_ode[gstepsF+n1+i+sub_index[sub]];
			IV[sub] += E_V[sub][i];
			//printf("E_V = %lf\t IV = %lf\n", E_V[sub][i], IV[sub]);
		}

		for (i=1;i<=gstepsF;i++)	{ //coinfected
			E_FV[sub][i]=y_ode[gstepsF+gstepsV+6+i+sub_index[sub]];
			//printf("j = %i\t sub = %i\t E_FV = %lf\n", j, sub, E_FV[sub]);
			IFV[sub] += E_FV[sub][i];
			//printf("j = %i\t sub = %i\t IF = %lf\t IV = %lf\t IVF = %lf\n",j, sub, IF[sub], IV[sub], IFV[sub]);
		}
		if(E_V[sub] < 0 || E_VF[sub] < 0 || E_FV[sub] < 0 || E_F[sub] < 0){
			printf("NEGATIVE EXPOSED CLASS!! ERROR!");
		}
 
	}
	//printf("day = %i\t j = %i\t sub = %i\t IF = %lf\t IV = %lf\t IVF = %lf\n",day, j, sub, IF[sub], IV[sub], IFV[sub]);

//*******************************Appends output for each treatment run based on one epizootic length of 48**************************//
//printf("check 6\n");c
		//LOOP THROUGH ARRAYS
	int day_index[4] = {0, 47, 95, 143}; //to append 48 day epizootics //probably a better way to do this
	
	for(sub=0; sub<num_sub; sub++){	

		Params->MODEL[j][day-1+day_index[sub]][0] = S[sub]/(y_ode[0+sub_index[sub]]+IV[sub]+IF[sub]+IVF[sub]+IFV[sub]); //Saving daily fraction uninfected S 
		//printf("DAY = %i\t j = %i\t sub = %i\t S = %lf\t yode = %lf\t IV = %lf\t IF = %lf\t IVF = %lf\n", day-1, j, sub, S[sub], y_ode[0+sub_index[sub]], IV[sub], IF[sub], IVF[sub]);
		Params->MODEL[j][day-1+day_index[sub]][1] = (IV[sub]+IVF[sub])/(y_ode[0+sub_index[sub]]+IV[sub]+IF[sub]+IVF[sub]+IFV[sub]); //Saving daily fraction infected V 
		Params->MODEL[j][day-1+day_index[sub]][2] = IF[sub]/(y_ode[0+sub_index[sub]]+IV[sub]+IF[sub]+IVF[sub]+IFV[sub]); //Saving daily fraction infected F
		Params->MODEL[j][day-1+day_index[sub]][3] = IFV[sub]/(y_ode[0+sub_index[sub]]+IV[sub]+IF[sub]+IVF[sub]+IFV[sub]); //Saving daily fraction coinfected 

		//MODEL REALIZATION PRINTING
		fprintf(fpm, "%i\t %i\t %i\t %e\t %e\t %e\t %e\n", j, sub, day-1, Params->MODEL[j][day-1+day_index[sub]][0], Params->MODEL[j][day-1+day_index[sub]][1], Params->MODEL[j][day-1+day_index[sub]][2], Params->MODEL[j][day-1+day_index[sub]][3]);
		//printf("%i\t %i\t %i\t %lf\t %lf\t %lf\t %lf\n", j, sub, day-1, Params->MODEL[j][day-1+day_index[sub]][0], Params->MODEL[j][day-1+day_index[sub]][1], Params->MODEL[j][day-1+day_index[sub]][2], Params->MODEL[j][day-1+day_index[sub]][3]);
	}
	}

//Done with daily plotting output here


	// ---------------------------- end of the week updates ---------------------------------- //

t_0=t_next;
//printf("t_0=%lf\n",t_0);
}

return 0;
} 