#include "headDEMO_exposed_foverv_alt.h"

int main(int argc, char *argv[])
{
//int test = atoi(argv[1]);                  // test is 99 for checking, 0 otherwise

//int test = 99;
int test = 66; //CK// Second test mode.  Like the full program but less runs and less MISER calls

int View = 0;  //CK// turn to 1 to print line search progress.  turn to 0 to run for real.

//VERSION OF BIG MODEL TO PRINT OUTPUTS!


////////////
///NOTE:  Going to try to change nuF to a site-specific parameter and make R(0) a general parameter
////////// Just going to try making a new parameter for average R(0).  Make it number 23.
////////// Comment out param #3 (general nuF) but leave structure in place if we go back to it
////////// Pipe param #23 into R for all populations
////////// Make it fit nuF, rather than R(0), for each population.  Sounds simple enough....

STRUCTURE Params;

int pro = 1;//atoi(argv[1]);						// pro and argv[1] are the inputs (argv[i] is the i^th input)
//printf("Profile Parameter is %d\n",pro);	fflush(stdout);
// ------------------------------------- Adustable accuracy vs. speed ------------------------------------------------ //
int num_runs	 = 20;
double parm_inc, host_inc, initR_inc;	//int inc_gamma_box= 1;

//if (pro==1)	{	parm_inc=200.0;		host_inc=100.0;	initR_inc=100.0;	}
if (pro==1)	{	parm_inc=50.0;		host_inc=10.0;	initR_inc=15.0;	}
//if (pro==1)	{	parm_inc=34.0;		host_inc=18.0;	initR_inc=20.0;	}
else		{	parm_inc=15.0;		host_inc=10.0;	initR_inc=10.0;	}

//if (test==66)	{	printf("for checking CK MODE2!!!\n");        num_runs=5;} //CK// New test mode!

if (test==66)	{      num_runs=5;	parm_inc=12.0;	host_inc=6.0;	initR_inc=8.0;}

//if (test==66)	{	printf("for checking!!!\n");        num_runs=5;	parm_inc=6.0;	host_inc=4.0;	initR_inc=4.0;	}
//printf("runs=%d\t incs: parm=%2.0f\t S_0=%2.0f\t R_0=%2.0f\n",num_runs,parm_inc,host_inc,initR_inc);

//---------------//CK// Best fit params and initial conditions from previous run //CK//-------------------------------------------------------//

//low rainP3!
//SS R(0) logWIN10 medium: 1	-603.071543	1.000000e+00,	1.000000e+00,	0.000000e+00,	6.304491e-02,	0.000000e+00,	0.000000e+00,	5.623413e+00,	1.000000e+01,	5.000000e+00,	5.000000e+01,	0.000000e+00,	5.000000e-01,	1.875004e-01,	2.371374e+00,	1.154782e+00,	0.000000e+00,	4.937500e+02,	4.062500e+00,	1.274029e-01,	2.593750e+02,	1.115625e+01,	1.442238e+02,	6.826867e-02,	1.872394e-01,	4.250000e+00,	4.975000e+00,	4.648264e+01,	1.193740e+02,	2.949078e+02,	3.249256e-04,
//3.019952e-01,	1.905461e-01,	1.737801e-02,	1.412538e-01,	2.818383e-02,	1.000000e-02,	3.981072e-12,	1.000000e-12,
//double bestparams[30]={1.0, 1.0, 0.64, 0.000236746849982845, 0, 0, 0.00990261949833669, 10, 20, 50, 0, 0.36488604999901, 0.192505599999974, 2.22609199996204, 0.94980394999444, 0, 524.545399999847, 8.32031899999946, 0.12163699999852, 267.069449999995, 7.88894449942196, 3.7664044999997, 0.0706599349999956, 0.236693999999915, 7.02416699998797, 6.36154149999762, 3.64051149605409, 100.39899999995, 291.253549999481, 0.168491049984977};
double bestparams[30]={1.0, 1.0, 0.64, 0.000241071699421562, 0, 0, 0.00962435749864498, 10, 20, 50, 0, 0.37161719994828, 0.913699399999732, 2.2223804999527, 0.945435549999967, 0, 525.015699999847, 8.32036899999904, 0.119701349994476, 267.034499999981, 7.88482749903281, 3.80285399989692, 0.070488499999861, 0.233982799999915, 7.05116449999956, 6.38002749970359, 3.54725448752468, 100.157149999888, 291.2745, 0.166585199947054};

//double bestparams[30]={1.0, 1.0, 0.64, 0, 0, 0, 0, 10, 20, 50, 0, 0, 0, 2.22609199996204, 0.94980394999444, 0, 524.545399999847, 8.32031899999946, 0.12163699999852, 267.069449999995, 7.88894449942196, 3.7664044999997, 0.0706599349999956, 0.236693999999915, 7.02416699998797, 6.36154149999762, 3.64051149605409, 100.39899999995, 291.253549999481, 0.168491049984977};       //JL: Turn off the fungus
//double bestparams[30]={1.0, 0.000000e+00,	0.0,	6.304491e-02,	0.000000e+00,	0.000000e+00,	5.623413e+00,	1.000000e+01,	5.000000e+00,	5.000000e+01,	0.000000e+00,	0.0,	0.0,	2.371374e+00,	1.154782e+00,	0.000000e+00,	4.937500e+02,	4.062500e+00,	1.274029e-01,	2.593750e+02,	1.115625e+01,	1.442238e+02,	6.826867e-02,	1.872394e-01,	4.250000e+00,	4.975000e+00,	4.648264e+01,	1.193740e+02,	2.949078e+02,	3.249256e-04};
//double bestparams[30]={1.0, 0.000000e+00,	0.0,	6.304491e-02,	0.000000e+00,	0.000000e+00,	5.623413e+00,	1.000000e+01,	5.000000e+00,	5.000000e+01,	0.000000e+00,	5.000000e-01,	1.875004e-01,	2.371374e+00,	1.154782e+00,	0.000000e+00,	4.937500e+02,	4.062500e+00,	1.274029e-01,	2.593750e+02,	1.115625e+01,	1.442238e+02,	6.826867e-02,	1.872394e-01,	4.250000e+00,	4.975000e+00,	4.648264e+01,	1.193740e+02,	2.949078e+02,	3.249256e-04};
//double initial_nuF[8]={3.019952e-01,	1.905461e-01,	1.737801e-02,	1.412538e-01,	2.818383e-02,	1.000000e-02,	3.981072e-12,	1.000000e-12};


int pop2 = 2;
//printf("Long-term pathogen survival rates: %e, %e, %e, %e\n",phivirus,gammavirus,phifungus,gammafungus);
//printf("%lf,%lf\n",lambdaV,squareCVV);


//---------------//CK// Initial conditions for S from field observations //CK//-------------------------------------------------------//

//double initialS[7]={1.92, 53.1, 7.68, 98.2, 72.6, 6.72, 5.76};	 //CK// my observed average egg density per circle at each site S(0)
//double initialS[7]={1.0,1.0,1.0,1.0,1.0,1.0,1.0};
//double initialS[8]={1.92*10, 98.2, 7.68*5, 72.6, 53.1, 6.72, 5.76, 247.36};	 //CK// my observed average egg density per circle at each site S(0)

//double initialS[9] = {10.0, 10.0, 10.0, 75.0, 75.0, 75.0, 150.0, 150.0, 150.0};
//double initialS[9] = {70.0, 70.0, 70.0, 200.0, 200.0, 200.0, 250.0, 250.0, 250.0};
//double initialS[9] = {200.0, 200.0, 200.0, 200.0, 200.0, 200.0, 200.0, 200.0, 250.0};
//double initialS[9] = {150.0, 150.0, 150.0, 150.0, 150.0, 150.0, 150.0, 150.0, 250.0};
//double initialS[8] = {10, 10, 10, 10, 10, 10, 10, 10};
double initialS[8] = {1, 3, 5, 10, 25, 50, 75, 100};
//double initialV = initialS[0]*0.01;
double initialV=1;
//double initialS[8] = {0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1};

//double initialS[8] = {500.0, 500.0, 500.0, 500.0, 500.0, 500.0, 500.0, 500.0};
//double initialR[9] = {5.0e-4, 5.0e-3, 5.0e-2, 5.0e-4, 5.0e-3, 5.0e-2, 5.0e-4, 5.0e-3, 5.0e-2};
double initial_nuF[8] = {5.0e-6, 5.0e-3, 5.0e-3, 5.0e-3, 5.0e-3, 5.0e-3, 5.0e-3, 5.0e-3};
//double initial_nuF[8] = {0,0,0,0,0,0,0,0};       //JL: Turn off the fungus

// ------------------------------------------------------------------------------------------------------------------ //
int i=0; int j;int ii; int jj; int k; int l;
//int run;	            int changer;	    double index, tot_index;

int num_adj_pars=29;			// number of adjustable parameters

//double inner_parm;				//double outer_parm;
//double inner_parm2;				//double outer_parm;

//double nuVholder1;  	//CK// holder for logging nuV on line search

int pop;
//double log_pop;
//Params.th_id=0;
// -------------------------------------------- MISTER STUFF --------------------------------------------------------- //
inputdata(&Params);				// gets Params.DATA[j][i][0-2] and Params.MAXT[i] from inputdata.h


//int calls=2;					//CK// turned down to run without stochasticity
int calls=50;					// number of stochastic simulations for each parameter and IC set
if (test==99)	calls=50;
if (test==66)	calls=50; //CK// second test mode
//if (test==66)	calls=5; //CK// second test mode
size_t dim;
//size_t dim2;
// --------------------------------------- Name for Output Files ----------------------------------------------------- //
char strFileName[99];					// from filenames.h
GetString(pro,0,strFileName,98);		fflush(stdout);		//getc(stdin);
FILE *fp_results;
// ---------------------------------------- Random Number Stuff ------------------------------------------------------ //
gsl_rng *r_seed;
r_seed=random_setup();
//printf("Random Seed: %f\n", r_seed); //getc(stdin);
// -------------------- parameter high/low values and increments and fixed parameter values ------------------------- //
global_fixed_parms(&Params);  // gets Params.PARS[i] for fixed parameters from bounds.h
parm_range_inc(&Params,parm_inc,host_inc,initR_inc,num_adj_pars); // gets Params.parm_set,low,high,R_END from bounds.h

// ------------------------------------ Declare Likelidhood Quanitites ----------------------------------------------- //
//double pop_lhood, pop_lhood2, pop_err,post_hood;	// population lhood (and posterior lhood) calculated for each initS and initR
//double pop_best_lhood;					// likelihood and error for best initS and initR
double total_lhood;						// sum of pop_best_lhood over all patches
//double best_post_hood;	double best_lhood=0;		// best post_hood and lhood
//double prior[num_adj_pars];



// -----------------------Declaring things for CC simulation------------------------------------ //

double DD10=0.0;		double S_start = 0.0;	double S_end = 0.0;
int test_day;
//int line_ticker;
double DDtemp_now;
double hatch =317.0;       //From Russo et al 1993
double Hlim1 = 3.0;
double Hlim2 = 40.0-Hlim1;
double pupate = 586.5;     //From Carter et al 1992
double Plim1=7.65;
double Plim2=41.0-Plim1;
int MAXT3;
int limit;
int MAXT4;


int reps;	//number of stochastic simulations to do per
double INFECTED;


//---------------------Write over the initial params with known fit params --------------------------//

for (k=0;k<=num_adj_pars;k++)	{
	Params.PARS[k] = bestparams[k];
	//printf("%e\n",Params.PARS[k]);
}
/*
for (pop=1;pop<=DATA_SETS;pop++)	{
	Params.MLE_host[pop] = initialS[pop-1];
	printf("%e\n",Params.MLE_host[pop]);
}
for (pop=1;pop<=DATA_SETS;pop++)		{
	Params.MLE_initR[pop] = initialR[pop-1];
	printf("%e\n",Params.MLE_initR[pop]);
}
*/

reps = 1;

//for (Params.pop=1;Params.pop<=DATA_SETS;Params.pop++)	{

int year;
double sdensity;
double fdensity;
double vdensity;

//int bbf;
//for (bbf=0;bbf<15;bbf++){ //SH removed for now, just set VfSus to something
//VFPass=VFtime;
// SH need to set initial conditions
VFSus=15; //SH random pick 
sdensity=100; //SH random pick 
fdensity=0.026; //SH from literature
vdensity=0.2; //SH guesstimate

//SH KEEP brings initial values into structure
Params.PARS[30+pop]=sdensity; 
VPass=vdensity;
Params.PARS[50+pop]=fdensity;



//************SH prints output each day into file******************//

char name1[50];
sprintf(name1, "sim_output_");
fp1=fopen(name1,"a+"); //or a+, not sure which
//for(j=0; j<reps; j++){ //SH add loop back in when doing multiple years
DDEVF(&Params,r_seed,dim,pop,48,0,year);
fclose(fp1);



//*****************************SH saves output into array without printing file**************//
/*
DDEVF(&Params,r_seed,dim,pop,48,0,year);
printf("%e\t %e\t %e\t", sim_output[12][1], sim_output[12][2], sim_output[12][3]);
*/



//************* SH hard code data **********/
const int JHN_Co[55][4] = {
	{-1, -1, -1, -1},
	{-1, -1, -1, -1},
	{-1, -1, -1, -1},
	{-1, -1, -1, -1},
	{-1, -1, -1, -1},
	{-1, -1, -1, -1},
	{-1, -1, -1, -1},
	{-1, -1, -1, -1},
	{-1, -1, -1, -1},
	{-1, -1, -1, -1},
	{-1, -1, -1, -1},
	{-1, -1, -1, -1},
	{-1, -1, -1, -1},
	{-1, -1, -1, -1},
	{42, 7, 0, 0},
	{-1, -1, -1, -1},
	{-1, -1, -1, -1},
	{-1, -1, -1, -1},
	{-1, -1, -1, -1},
	{-1, -1, -1, -1},
	{29, 18, 1, 0},
	{-1, -1, -1, -1},
	{-1, -1, -1, -1},
	{33, 15, 0, 0},
	{-1, -1, -1, -1},
	{-1, -1, -1, -1},
	{36, 11, 1, 0},
	{-1, -1, -1, -1},
	{-1, -1, -1, -1},
	{38, 10, 1, 0},
	{-1, -1, -1, -1},
	{-1, -1, -1, -1},
	{-1, -1, -1, -1},
	{25, 21, 4, 0},
	{-1, -1, -1, -1},
	{-1, -1, -1, -1},
	{19, 30, 2, 0},
	{-1, -1, -1, -1},
	{-1, -1, -1, -1},
	{-1, -1, -1, -1},
	{11, 33, 2, 5},
	{-1, -1, -1, -1},
	{-1, -1, -1, -1},
	{7, 41, 1, 1},
	{-1, -1, -1, -1},
	{-1, -1, -1, -1},
	{-1, -1, -1, -1},
	{-1, -1, -1, -1}
};
//int (*ptr_JHN_NoCo)[55][3]; 

//**************SH prints content of JHN_NoCo******************//
/*
int loop3, loop4;
for(loop3 = 0; loop3 < 48; loop3++){
	for (loop4 = 0; loop4 < 3; loop4++){
		printf("JHN_NoCo[%i][%i] = %i\n", loop3, loop4, JHN_NoCo[loop3][loop4]);
	}	
}
*/



//*************** SH let's calculate a likelihood!! ******************//

int m; double lhood_JHN = 0;

for (m = 0; m < 48; m++){
	if (JHN_Co[m][0] != -1) {	
		lhood_JHN = lhood_JHN + gsl_ran_multinomial_lnpdf(4, sim_output[m], JHN_Co[m]);
		printf("%lf\n", lhood_JHN);
	}
	else{

	}
}
printf("%lf\n", lhood_JHN);






//**************SH prints output at end of week****************//
   // FILE *fp;
   // char name[50];
    // sprintf(name,"typethree_Vall_Cthreeweek_fut_immi_VFSus_alt_%lf_1.txt",VFSusF[bbf]);
    //sprintf(name,"fv_bf_%f_row_%d_col_%d.txt",bfungus[bbf],row,col);
	//sprintf(name, "JHN_KBS1daily_15_10000_0.026_0.2"); //SH attempt at naming output based on above lines

   // fp=fopen(name,"a+");    //a+ for reading and appending! Could only get the output of the last year with w+.



	// INFECTED = 1.0 - (Params.survivors/Params.total); //SH need to modify to add two infection classes (V/F)

	//printf("%lf\t %lf\t %lf\t %lf\t %lf\n", Params.PARS[30+pop], Params.PARS[50+pop], INFECTED, Params.survivors, Params.total);
	// fprintf(fp,"%d\t %e\t %e\t %e\t %e\t %e\t %e\t %e\n",year,Params.PARS[30+pop],Params.PARS[50+pop],VPass,InfFungusNext,InfFungusEnd,InfVirusNext,InfVirusEnd); //After dispersal
	//year, initial s, initial f, initial v, end f to next epi, f at end, v to next epi, v at end

    //printf("After an epizootic: %e\t %e\t %e\n",SusEnd,InfFungusEnd,InfVirusEnd); //getc(stdin);
    //printf("SusEnd=%e, N*(1-if-iv)=%e\n",SusEnd,sdensity-InfFungusEnd-InfVirusEnd);
    double stoch=exp(gsl_ran_gaussian(r_seed,0.25));
    double tempor=sdensity;
    //printf("%f\n",SusEnd);
    sdensity=fecundity*SusEnd*(1-(2*preda*predb*sdensity)/(predb*predb+sdensity*sdensity))+1e-5;
    //if (sdensity<1e-8){
        //sdensity=1e-5;
    //}
    //sdensity=fecundity*SusEnd*(1-preda*sdensity/(predb+sdensity));
    //sdensity=fecundity*SusEnd; //No Predation
    //initialS[0]=fecundity*SusEnd*(1-InfFungusEnd-InfVirusEnd);
    //initial_nuF[0]=phifungus*
    //fdensity=InfFungusEnd;
    //vdensity=InfVirusEnd;
    // if (year>15){
    // fdensity=phifungus*InfFungusNext+gammafungus*fdensity;
    //fdensity=phifungus*tempor/(1+psifungus*fdensity);
    //fdensity=phifungus*InfFungusAdj+gammafungus*fdensity;
   // }
    // vdensity=eta*(phivirus/eta*InfVirusNext+gammavirus*vdensity/eta);
    //vdensity=eta*(phivirus/eta*InfVirusAdj+gammavirus*vdensity/eta);
    //fclose(fp);
    
    


/*				// ----------------------- loop over patch numbers -------------------------------------------- //
				for (Params.pop=1;Params.pop<=DATA_SETS;Params.pop++)	{
					pop=Params.pop;
					pop_best_lhood = -1e9;

					int MAXT3=(Params.EXPDATA[pop][Params.MAXT2[pop]][2]+1)*7;

					if(pop==6){MAXT3=77;}  ///can't figure out why plot 6 (UMBS 2012) is fucked up.  says it only has 2 weeks of data, but that's not true at all...

					dim = 2*MAXT3;     //CK//  Changed dim to accomodate the longer EXP data sets... hopefully that works

					//dim = 2*Params.MAXT[pop];		// need to let this vary by patch (double because of nuV and nuF)
					gsl_monte_function G = { &Hood_Pops, dim, &Params };	// declares function calling Hood_Pops.h
					double xl[dim];	double xu[dim];	// need to redeclare xl and xu since the size changes
					for (jj=0;jj<=dim;jj++)	{
						xl[jj]=0;
						xu[jj]=1;
					}

					Params.PARS[30+pop]=initialS[pop-1];  //CK//  I think these should just be initialS[pop], not initialS[pop-1].  Keep everything where pop starts at 1
					//Params.PARS[40+pop]=initial_T[pop-1];  //CK// Needs to be [pop-1].  initialS is where the conditions are read in, so it starts at 0 and needs to be adjusted for
					Params.PARS[50+pop] = initial_nuF[pop-1];

					//printf("ssNuF: %e\n",Params.PARS[50+pop]);


							// ----------- Use MISER to call function pop_lhood --------------------------------- //
							gsl_monte_miser_state *s = gsl_monte_miser_alloc(dim);
							gsl_monte_miser_integrate (&G,xl,xu,dim,calls,r_seed,s,&pop_lhood,&pop_err);
							gsl_monte_miser_free(s);
							//printf("pop:%d lhood=%f log_error=%f error=%f best_post_hood=%f\n",
								//pop,pop_lhood,log(pop_err),pop_err,pop_best_lhood);
							// ------------------- check to see if these ICs are better  ------------------------ //
							pop_lhood2=log(pop_lhood)-700.0;  //CK// Converting back to log likelihoods for MCMC
								//printf("pop_lhood:%e\t pop_lhood2:%f\n",pop_lhood,pop_lhood2); getc(stdin);

							if (pop_lhood2>pop_best_lhood) {
								//printf("update!\n");
			//CK// Changed it so that MISER receives and outputs a likelihood value
			//CK// Now, Ln the ouput of MISER before comparing the the previous best lhood
			//CK// Keeping the machinery that maximizes the log likelihood the same
								pop_best_lhood = pop_lhood2;
								//Params.best_initS[pop] = Params.PARS[40+pop];
								Params.best_initR[pop] = Params.PARS[50+pop];
								//printf("pop_best_lhood:%f\t SS Rain beta:%f\t SS nuF=%f\n",pop_best_lhood,Params.best_initS[pop],Params.best_initR[pop]); //getc(stdin);
							}//getc(stdin);

							//printf("pop_lhood:%e\t pop_lhood2:%f\t pop_best_lhood=%f\n",pop_lhood,pop_lhood2,pop_best_lhood); //getc(stdin);

						//}	//CK// end of nuF line search
					//}		//CK// end of muF line search
					total_lhood += pop_best_lhood;
					//printf("total_lhood=%f\n",total_lhood);	getc(stdin);
				} //CK// end of going through patches

				//printf("total_lhood=%f\n",total_lhood);	//getc(stdin);

				//prior[5]=log(prior_dist(5,log10(Params.PARS[5])));	//printf("prior[5]=%f\n",prior[5]);
				prior[6]=log(prior_dist(6,log10(Params.PARS[6])));	//printf("prior[6]=%f\n",prior[6]);
				post_hood=total_lhood;
				//printf("lhood=%f\t param(5)=%f\t prior(5)=%e\t params(6)=%f\t prior(6)=%e\n",total_lhood,log10(Params.PARS[5]),prior[5],log10(Params.PARS[6]),prior[6]);
				//printf("\t parm:%d posthood=%f\t best_post_hood=%f\t prior5=%f\t prior6=%f\n",i,post_hood,best_post_hood,prior[5],prior[6]);
*/
// ------------------------------------------------------------------------------------------------------- //
//}   //end of the infinite while loop

free_i3tensor(Params.DATA,0,DATA_SETS,0,MAX_WEEKS,0,3);
// free_i3tensor(Params.EXPDATA,0,DATA_SETS,0,MAX_WEEKS,0,3);
//  free_d3tensor(Params.WDATA,0,100,0,MAX_WEEKS2,0,4);
//free_i3tensor(Params.WDATA,0,0,0,MAX_WEEKS2,0,2);
//free(Params.Rain);
//free(Params.MaxT);
//free(Params.MinRH);
//printf("DONE!!!\n");

return 0;
}
