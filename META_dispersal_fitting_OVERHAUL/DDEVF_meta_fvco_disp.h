double DDEVF(void *Paramstruct, double *RandNumsPass, size_t dim, int dataset)
{

// --------------------------------- Set Up -------------------------------------//
STRUCTURE* Params;
Params = (STRUCTURE*) Paramstruct;

//local variables
int num_sub;					//number of subpopulations within a metapopulation		
int j = dataset;				//metapopulation number
double rand_nuR[epi_length];	//hold stochastic value for each day impacting resting spore transmssion
double rand_nuF[epi_length];	//hold stochastic value for each day impacting conidia transmission
double lambdaV = 1/exposetime;
int n1 = ((exposetime-1/lambdaF)/exposetime)*n;    //early virus infection
int n2 = n-n1;                  //late virus infection
double initC = 0; 				//initial conidia density
int subout; int subin; 			//dispersal indexing
double netVdisp[4] = {0, 0, 0, 0}; //dispersal array for virus-infecteds
double netSdisp[4] = {0, 0, 0, 0}; //dispersal array for susceptibles
double fracV; 						//fracS = 1-fracV //early in epi, only S and V around
double poptotal;
int day = 0;						// keeps track of day
double epsilon = pow(10,-6);
int line_ticker=0;   //CK// Ticker used to associate t in function with numbered days.
int line_ticker2;
int test_day=0;	//CK// used to find the line in the weather data that corresponds to the starting day of collections
R_start=0;
int num_day =  R_start;  //CK// Starting day number
line_ticker = num_day;
line_ticker=line_ticker-1;
double timing[6]={R_start,R_end,epi_length};
int day_index[4] = {0, 47, 95, 143}; //to append 48 day epizootics 
double t=h;		double t_next=h;	double t_0=h;	int i;	int ii;			// time loop and index //why is h 0.1?? shouldn't it be 1?


//subpopulation structure
if (j==1 || j==2 || j==3) { 
	Params->numsub=4;
	num_sub = Params->numsub; 
}
if (j==4 || j==5 || j==6) { 	
	Params->numsub=1;
	num_sub = Params->numsub;
}
int sub;
int sub_index[num_sub];
int max_class = m+n+7+m;
sub_index[0] = 0;
for(sub=1; sub<num_sub; sub++){	
	sub_index[sub] = sub_index[sub-1]+ max_class;  
	
}

//state variable arrays
double S[num_sub]; double V[num_sub]; double C[num_sub]; double R[num_sub];
double IV[num_sub]; double IF[num_sub]; double IVF[num_sub]; double IFV[num_sub];
double E_V[num_sub][n2+1]; double E_F[num_sub][m+1]; double E_VF[num_sub][n1+1]; double E_FV[num_sub][m+1];

//dispersal
int larvae_dispersal_on = 1; 	//set to 0 for no dispersal

//stochasticity
for (i=0;i<epi_length;i++)	{        
	rand_nuR[i]=gsl_cdf_gaussian_Pinv(RandNumsPass[i],sdR); //mean, sigma
	rand_nuF[i]=gsl_cdf_gaussian_Pinv(RandNumsPass[i+epi_length],sdC);
}

//ode set up
int DIM = num_sub*(m+n+4+2+1+m); //number of ode's
double y_ode[DIM]; 				 //array to hold ode's 

//-------------------------------------- Figure Out -------------------------------------------//

double temp_now;  //CIK// used simplify decay functions
double total_rainfall=0.0;  //used to sum up rainfall
int rain_day;  //used to sum up rainfall
int theta = 1;    //used to determine lag period before calculating accumulated rainfall
double DDtemp_now;  //CIK// used simplify decay functions

double nuF2;
double nuR2;

double DD10=0;    //accumulated degree days about 10 degrees C

// ------------------------------------- Parameters to Fit ---------------------------------------------- //

//Initial conditions
if (j==1 || j==2 || j==3) { //epi data
	Params->INITS[0] = Params->FITINIT[j][0]; 	//fungus-only
	Params->INITS[1] = Params->FITINIT[j][1]; 	//virus-only
	Params->INITS[2] = Params->FITINIT[j][2]; 	//virus-only
	Params->INITS[3] = Params->FITINIT[j][3]; 	//control	

	Params->INITV[0] = Params->FITINIT[j][4]; 			//fungus-only
	Params->INITV[1] = Params->FITINIT[j][5]; 		//virus-only
	Params->INITV[2] = Params->FITINIT[j][6]; 		//virus-only
	Params->INITV[3] = Params->FITINIT[j][7]; 			//control

	Params->INITR[0] = Params->FITINIT[j][8]; 	//fungus-only
	Params->INITR[1] = Params->FITINIT[j][9]; 	//virus-only
	Params->INITR[2] = Params->FITINIT[j][10]; //virus-only
	Params->INITR[3] = Params->FITINIT[j][11]; //control
}
if (j==4 || j==5 || j==6) { // obs data
	Params->INITS[0] = Params->FITINIT[j][0];
	Params->INITV[0] = Params->FITINIT[j][4];			
	Params->INITR[0] = Params->FITINIT[j][8];
}

//disperasl parameters
Params->lar_disp = Params->FITMETA[16]; //prob of migrating out //TO FIT
double lar_disp = Params->lar_disp;


// ----------------------------------------- Initialize Arrays ------------------------------------------- //
for(i=0; i<num_sub; i++){ 
	S[i] = Params->INITS[i]; 
	V[i] = Params->INITV[i]; 
	C[i] = initC;
	R[i] = Params->INITR[i];

	for (ii=1;ii<=n2;ii++){ 
		E_V[i][ii]=0;
	}
	for (ii=1;ii<=n1;ii++){
		E_VF[i][ii]=0;
	}
	for (ii=1;ii<=m;ii++){
		E_F[i][ii]=0;
		E_FV[i][ii]=0;
	}

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

// ----------------------------------------- Begin Epizootic Loop ------------------------------------------- //

while (t_0<epi_length+h)	{  //for each day...

	// ------------------------------- Resting Spore Blooming ----------------------------------------------- //
	// --------------------- end of day -------------------- //
	if (day+1<timing[0] && day+1<timing[1])	{
		t_next=day+1;
		day++;
		num_day++;
		line_ticker++;
	}
	// --------------------- resting spores bloom -------------------- //
	else if (timing[0]<timing[1] && timing[0]<day+1)	{
		t_next=timing[0];
		timing[0]=999.9;
	}
	// --------------------- resting spores done -------------------- //
	else if (timing[1]<timing[0] && timing[1]<day+1)	{
		t_next=timing[1];
		timing[0]=999.9;
		timing[1]=999.9;
	}
	// --------------------- resting spores bloom and end of day -------------------- //
	else if (abs(day+1-timing[0])<epsilon)	{
		t_next=day+1;
		timing[0]=999.9;
		day++;
		num_day++;
		line_ticker++;
	}
	// --------------------- resting spores done and end of day -------------------- //
	else if (abs(day+1-timing[1])<epsilon)	{
		t_next=day+1;
		timing[0]=999.9;
		timing[1]=999.9;
		day++;
		num_day++;
		line_ticker++;
	}
	else {
		printf("RESTING SPORE BLOOM ERROR\n");
		getc(stdin);
	}

	//-------------------------------------- Update State Variables -------------------------------------------//

	while (t<t_next)	{
		
		for(sub=0; sub<num_sub; sub++){ //for each treatment
			y_ode[0+sub_index[sub]]=S[sub];	y_ode[m+n+1+sub_index[sub]]=C[sub];
			y_ode[m+n+3+sub_index[sub]]=V[sub];
			
			for (i=1;i<=m;i++)	{
				y_ode[i+sub_index[sub]]=E_F[sub][i];
			}
			for (i=1;i<=n1;i++)	{
				y_ode[m+i+sub_index[sub]]=E_VF[sub][i];
			}
			for (i=1;i<=n2;i++)	{
				y_ode[m+n1+i+sub_index[sub]]=E_V[sub][i];
			}
			y_ode[m+n+2+sub_index[sub]]=Fnext[sub];
			y_ode[m+n+4+sub_index[sub]]=Vkill[sub];
			y_ode[m+n+5+sub_index[sub]]=Fkill[sub];
			y_ode[m+n+6+sub_index[sub]]=Vnext[sub];

			for (i=1;i<=m;i++)	{
				y_ode[m+n+6+i+sub_index[sub]]=E_FV[sub][i]; 
			}
		}


	//-------------------------------------- Larval Dispersal -------------------------------------------//
		if(larvae_dispersal_on == 1){
			if(day-1<8){ 					//dispersal occurs during first week
				if (j==1 || j==2 || j==3){ //only for datasets with subpopulations
					for(subout = 0; subout < num_sub; subout++){ 
						for(subin = 0; subin < num_sub; subin++){
								poptotal = S[subout]+V[subout]+C[subout];
								fracV = V[subout]/poptotal; 
								//EVENT 1: RANDOM INSECTS LEAVE, FRAC ARE V FRAC ARE S
								netVdisp[subout] = netVdisp[subout] - lar_disp*poptotal*fracV; //frac of virus infected insects that leave
								netSdisp[subout] = netSdisp[subout] - lar_disp*poptotal*(1-fracV);
								//EVENT 2: THEY MAKE IT TO ANOTHER SUBPOP
								netVdisp[subin] = netVdisp[subin] + lar_disp*poptotal*fracV*Params->DISPROB[j][subout][subin]; //prob leave * prob make it 
								netSdisp[subin] = netSdisp[subin] + lar_disp*poptotal*(1-fracV)*Params->DISPROB[j][subout][subin];
						}
					}
					for(sub=0; sub<num_sub; sub++){ //update larvae density
						S[sub] = S[sub] + S[sub]*netSdisp[sub]; //net movement * frac that are S
						V[sub] = V[sub] + V[sub]*netVdisp[sub]; //net movement * frac that are V
					}
				} 
			}
		}

	//-------------------------------------- Weather and Stochasticity on Fungal Transmission -------------------------------------------//
		//accumulation of degree days
		DDtemp_now = Params->WDATA[1][day - 1][4][0]-10.0; 
		if(DDtemp_now<0.0){
			DDtemp_now=0.0;
		}
		DD10 = DD10 + DDtemp_now;	

		//accumulation of rainfall
		total_rainfall = 0.0;
		rain_day = day - beta - 1;
		for (rain_day= (day - beta - theta - 1); rain_day <= day - theta -1; rain_day++)	{
			if (rain_day<0){
				total_rainfall=0;
			}
			else{
					total_rainfall = Params->WDATA[1][rain_day][0][0]+total_rainfall;
			}
		}		

		//daily value of nuF modified by daily stochastic RH
		nuF2 = nuF*exp(scale_RH*Params->WDATA[1][day - 1][6][0]) * exp(rand_nuF[(int)t]);  
		if(nuF2 > pow(8.0,8.0)){ 	
			nuF2 = pow(8.0,8.0);
		}
		nuF = (DD10/size_S)*nuF2;

		//daily value of muF modified by daily temperature
		temp_now = Params->WDATA[1][day - 1][2][0];	
		muF = muF*exp(scale_temp*temp_now);
		if(muF > pow(10.0,10.0)){
			muF = pow(10.0,10.0);
		}

		//daily value of nuR modified by rainfall
		nuR2 = (scale_R1/(1+scale_R2*exp(-scale_R3*total_rainfall)) - scale_R1/(scale_R2+1))*exp(rand_nuR[(int)t]);
		if(nuR2> pow(10.0,10.0)){
			nuR2= pow(10.0,10.0);
		}
		nuR = (DD10/size_S) * nuR2;
	//-------------------------------------- ODE Solver -------------------------------------------//

	//*****************************************************************************//
	
		t=ODE_Solver(t,t_next,Params,y_ode);
	
	//*******************************************************************************//

	//-------------------------------------- Update State Variables -------------------------------------------//

		for(sub=0; sub<num_sub; sub++){
			S[sub]=y_ode[0+sub_index[sub]]; 
			C[sub]=y_ode[m+n+1+sub_index[sub]]; 
			V[sub]=y_ode[m+n+3+sub_index[sub]];
			Fnext[sub]=y_ode[m+n+2+sub_index[sub]];			
			Vkill[sub]=y_ode[m+n+4+sub_index[sub]];
			Fkill[sub]=y_ode[m+n+5+sub_index[sub]];			
			Vnext[sub]=y_ode[m+n+6+sub_index[sub]];
			IF[sub]=0;
			IV[sub]=0;
			IVF[sub]=0;
			IFV[sub]=0;
		}
		
		for(sub=0; sub<num_sub; sub++){	
			for (i=1;i<=m;i++)	{
				E_F[sub][i]=y_ode[i+sub_index[sub]];
				IF[sub] += E_F[sub][i];
			}
			for (i=1;i<=n1;i++)	{
				E_VF[sub][i]=y_ode[m+i+sub_index[sub]];
				IVF[sub] += E_VF[sub][i];
			}
			for (i=1;i<=n2;i++)	{
				E_V[sub][i]=y_ode[m+n1+i+sub_index[sub]];
				IV[sub] += E_V[sub][i];
			}
			for (i=1;i<=m;i++)	{
				E_FV[sub][i]=y_ode[m+n+6+i+sub_index[sub]];
				IFV[sub] += E_FV[sub][i];
			}
		}

//-------------------------------------- Save Daily Output Into Array -------------------------------------------//

	
		for(sub=0; sub<num_sub; sub++){	

			Params->MODEL[j][day-1+day_index[sub]][0] = S[sub]/(y_ode[0+sub_index[sub]]+IV[sub]+IF[sub]+IVF[sub]); //Saving daily fraction uninfected S 
			Params->MODEL[j][day-1+day_index[sub]][1] = IV[sub]/(y_ode[0+sub_index[sub]]+IV[sub]+IF[sub]+IVF[sub]); //Saving daily fraction infected V 
			Params->MODEL[j][day-1+day_index[sub]][2] = IF[sub]/(y_ode[0+sub_index[sub]]+IV[sub]+IF[sub]+IVF[sub]); //Saving daily fraction infected F
			Params->MODEL[j][day-1+day_index[sub]][3] = IFV[sub]/(y_ode[0+sub_index[sub]]+IV[sub]+IF[sub]+IVF[sub]); //Saving daily fraction coinfected 
		}

	}

t_0=t_next;

}

return 0;

}
