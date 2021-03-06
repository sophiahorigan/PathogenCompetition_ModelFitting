#include "head_meta.h"
gsl_rng *r;
//-----------------------Dot Product-----------------------//
float DotProduct (int Length, double *Holder, double *PCA)
{
  double answer = 0;

  int i;
  for(i=0;i<Length;i++)
    answer += PCA[i]*Holder[i];   //JL: Used in the reconstruction of parameter values from PCA

  return(answer);

}


//-----------------------line-search mcmc-------------------------//

int main(void)
{

int linesearch = 1;
int mcmc = 0;
int reals = 0;

int test = 66; //CK// Second test mode.  Like the full program but less runs and less MISER calls

int View = 0;  //CK// turn to 1 to print line search progress.  turn to 0 to run for real.

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

// ----------------------------------------Set Up-------------------------------------------------------------------- //
int i=0; int j;int ii; int jj; int k; int l; 
int num_adj_pars = 54;			// number of adjustable parameters
int epi_length = 48;

inputdata(&Params);				// gets Params.DATA[j][i][0-2] and Params.MAXT[i] from inputdata.h
/*
double lhood_meta; double log_lhood_meta;
double meta_err;
double lhood_total;
double ave_lhood;
*/
// --------------------------------------- Name for Output Files ----------------------------------------------------- //
char strFileName[99];					// from filenames.h
GetString(pro,0,strFileName,98);		fflush(stdout);		//getc(stdin);
FILE *mcmc_results;

//char named[50];
//sprintf(named, "daily_output");
//fp1=fopen(named, "a+");
// ---------------------------------------- Random Number Stuff ------------------------------------------------------ //
gsl_rng *r_seed;
r_seed=random_setup();
//printf("Random Seed: %f\n", r_seed); //getc(stdin);

//----------------------------------Set-Up Line Search------------------------//

//set initial likelihood adjustment values
Params.lhood_adjust[1] = 6000;
Params.lhood_adjust[2] = 6000;
Params.lhood_adjust[3] = 6000;
Params.lhood_adjust[4] = 2000;
Params.lhood_adjust[5] = 2000;
Params.lhood_adjust[6] = 1000;

int searches = 3; //number of iterations for each specific parameter
int round;
int numround = 2;
int calls;
size_t dim;

int num_ltfparams = 54;	//number of parameters to fit
double ltf_params[54] = {0};      //arrays to hold different parameter values
double init_ltfparams[54]={0};

double log_prior=0;

for (i=0;i<num_ltfparams;i++){ 											//give random initial value for each parameter
    double randn = gsl_rng_uniform_pos(r_seed);
    ltf_params[i] = ls_bound(i,1) + randn * ls_bound(i,2);
    init_ltfparams[i] = ltf_params[i]; 
    //printf("%lf\n",init_ltfparams[i]);
	//printf("i = %i\t, lft_params = %lf\n %lf\n",i, init_ltfparams[i]);
}
//CHECK
double localmax_params[54]={0};         //Array to record param values for the local max likelihood in line search
int a,b,c;								//indexing loops
double best_posterior;
for (c=0;c<num_ltfparams;c++){			//initial parameters begin as 'best' parameters
    localmax_params[c]=ltf_params[c];
}
//calculate priors
for (k=0; k<num_ltfparams; k++){
	log_prior = log_prior + log(gsl_ran_flat_pdf(ltf_params[k], prior_bound(k,1), (prior_bound(k,2)+prior_bound(k,1))));
	//printf("k = %i\t param = %lf\t log prior = %lf\n", k, ltf_params[k], log_prior);
}
//-------------------------------------------------Realizations-----------------------------------------------//
if(reals==1){

	char name1[50];
	sprintf(name1, "model_realizations");
	fpm=fopen(name1, "a+");
	
	double linesearchpars[54] = {198.890583,105.518878,118.732095,150.761538,0.007897,0.172561,0.045577,0.002373,0.008667,0.009468,0.009891,0.001392,164.394604,135.896308,98.305476,199.724284,0.002756,0.097985,0.182305,0.007402,0.006673,0.000479,0.001276,0.000786,101.259181,93.120187,134.255696,96.491262,0.003349,0.017231,0.06059,0.007751,0.007525,0.003303,0.008875,0.000574,57.938313,0.306001,0.003744,48.973371,0.472622,0.006452,69.554753,0.155475,0.005912,6.405986,0.579409,0.958631,0.639453,87.161354,1.985191,0.176238,1.471849,1.352933};

	//propose parameter values
	//metapopulation one
	Params.FITINIT[1][0] = linesearchpars[0]; //initS
	Params.FITINIT[1][1] = linesearchpars[1]; //initS
	Params.FITINIT[1][2] = linesearchpars[2]; //initS
	Params.FITINIT[1][3] = linesearchpars[3]; //initS
	Params.FITINIT[1][4] = linesearchpars[4]; 				//initV //fonly
	Params.FITINIT[1][5] = linesearchpars[5]; //initV
	Params.FITINIT[1][6] = linesearchpars[6]; //initV
	Params.FITINIT[1][7] = linesearchpars[7]; 				//initV //control
	Params.FITINIT[1][8] = linesearchpars[8]; //initR
	Params.FITINIT[1][9] = linesearchpars[9]; //initR
	Params.FITINIT[1][10] = linesearchpars[10]; //initR
	Params.FITINIT[1][11] = linesearchpars[11]; //initR

	//metapopulation two
	Params.FITINIT[2][0] = linesearchpars[12]; //initS
	Params.FITINIT[2][1] = linesearchpars[13]; //initS
	Params.FITINIT[2][2] = linesearchpars[14]; //initS
	Params.FITINIT[2][3] = linesearchpars[15]; //initS
	Params.FITINIT[2][4] = linesearchpars[16]; 				//initV //fonly
	Params.FITINIT[2][5] = linesearchpars[17]; //initV
	Params.FITINIT[2][6] = linesearchpars[18]; //initV
	Params.FITINIT[2][7] = linesearchpars[19]; 				//initV //control
	Params.FITINIT[2][8] = linesearchpars[20]; //initR
	Params.FITINIT[2][9] = linesearchpars[21]; //initR
	Params.FITINIT[2][10] = linesearchpars[22]; //initR
	Params.FITINIT[2][11] = linesearchpars[23]; //initR

	//metapopulation three
	Params.FITINIT[3][0] = linesearchpars[24]; //initS
	Params.FITINIT[3][1] = linesearchpars[25]; //initS
	Params.FITINIT[3][2] = linesearchpars[26]; //initS
	Params.FITINIT[3][3] = linesearchpars[27]; //initS
	Params.FITINIT[3][4] = linesearchpars[28]; 				//initV //f only
	Params.FITINIT[3][5] = linesearchpars[29]; //initV
	Params.FITINIT[3][6] = linesearchpars[30]; //initV
	Params.FITINIT[3][7] = linesearchpars[31];				 //initV //control
	Params.FITINIT[3][8] = linesearchpars[32]; //initR
	Params.FITINIT[3][9] = linesearchpars[33]; //initR
	Params.FITINIT[3][10] = linesearchpars[34]; //initR
	Params.FITINIT[3][11] = linesearchpars[35]; //initR

	//metapopultion four
	Params.FITINIT[4][0] = linesearchpars[36]; //initS
	Params.FITINIT[4][4] = linesearchpars[37]; //initV
	Params.FITINIT[4][8] = linesearchpars[38]; //initR

	//metapopultion five
	Params.FITINIT[5][0] = linesearchpars[39]; //initS
	Params.FITINIT[5][4] = linesearchpars[40]; //initV
	Params.FITINIT[5][8] = linesearchpars[41]; //initR

	//metapopultion six
	Params.FITINIT[6][0] = linesearchpars[42]; //initS
	Params.FITINIT[6][4] = linesearchpars[43]; //initV
	Params.FITINIT[6][8] = linesearchpars[44]; //initR

	//dispersal parameters
	Params.con_mrg 		= linesearchpars[45];
	Params.a 			= linesearchpars[46];
	Params.lar_disp 	= linesearchpars[47];
	//coinfection parameters
	Params.coinf_V		= linesearchpars[48];
	Params.VFSus		= linesearchpars[49];
	//stochasticity parameters
	Params.Rsd_exp 		= linesearchpars[50];
	Params.Fsd_exp		= linesearchpars[51];
	Params.Rsd_obs		= linesearchpars[52];
	Params.Fsd_exp		= linesearchpars[53];

	//start realizations. In this case, calls = # realizations
	double lhood_meta=0; double log_lhood_meta=0; double total_loghood_metas = 0;
	double new_posterior=0;
	double meta_err=0;
	double lhood_total=0;
	double lhood_reps=0;

	calls=10;					//number of stochastic simulations for each parameter and IC set //100-300

	for(j=1; j<=DATA_SETS; j++){
		//for(j=1; j<2; j++){
			Params.j = j;

			dim = 48*2; 

			//define function
			gsl_monte_function G = { &LHood_Meta, dim, &Params };	// declares function calling lhood_meta.h
			double xl[dim];	double xu[dim];	// need to redeclare xl and xu since the size changes
			for (jj=0;jj<=dim;jj++)	{
				xl[jj]=0;	
				xu[jj]=1;
			}

			gsl_monte_miser_state *s = gsl_monte_miser_alloc(dim);
			gsl_monte_miser_integrate (&G,xl,xu,dim,calls,r_seed,s,&lhood_meta,&meta_err); //call MISER, pop_lhood is output from .h (likelihood value)
			gsl_monte_miser_free(s);

			log_lhood_meta = log(lhood_meta) - Params.lhood_adjust[j];
			if(isnan(log_lhood_meta) || isinf(log_lhood_meta)){ //change to zero of inf or nan, only update lhood adj if not
				log_lhood_meta = 0;
			}
			else{
				Params.lhood_adjust[j] = -1*log_lhood_meta; //update lhood adj based on average so it is dynamic
				//printf("ELSE adj = %lf\n", Params.lhood_adjust[j]);
			}
			//printf("MADE IT OUT: log_lhood_meta = %lf\n", log_lhood_meta);
			total_loghood_metas = total_loghood_metas + log_lhood_meta;
			//printf("total = %lf\n", total_loghood_metas);
			new_posterior = total_loghood_metas + log_prior;
	}
	fclose(fpm); //TURN ON FP1 PRINT STATEMENT IN DDEVF

}
//----------------------------------------------------Print Output to File-------------------------------------------//

if(linesearch==1){
int pid;
pid=getpid();

char namev[50];
sprintf(namev, "allmeta_s%i_r%i_%d", searches, numround, pid);
fpv=fopen(namev, "a+");

char name1[50];
sprintf(name1, "model_realizations");
fp1=fopen(name1, "a+");

//char namel[50];
//sprintf(namel, "lhood_s%i_r%i_%d", searches, numround, pid);
//fpl=fopen(namel, "a+");

///////////////////////////////////////////////////LINE-SEARCH///////////////////////////////////////////////////

for (round=0;round<numround;round++){
	//printf("round");
	best_posterior=-999999999999;
	a=0;
	while (a<num_ltfparams){            
		if (round>0){					
			ltf_params[a] = ltf_params[a] - step(a) * searches;
			if(ltf_params[a] <= ls_bound(i,1)){
				//printf("in the a loop\n");
				ltf_params[a] = ls_bound(i,1);
			}
		}
		for (b=0;b<searches;b++){ 
			if (b>0){
				ltf_params[a] = ltf_params[a] + step(a);
				//printf("in the b loop\n");
				if(ltf_params[a] >= (ls_bound(i,2)+ls_bound(i,1))){
					ltf_params[a] = (ls_bound(i,2)+ls_bound(i,1));
				}
			}

			//Send new parameter values into code
			//metapopulation one
			Params.FITINIT[1][0] = ltf_params[0]; //initS
			Params.FITINIT[1][1] = ltf_params[1]; //initS
			Params.FITINIT[1][2] = ltf_params[2]; //initS
			Params.FITINIT[1][3] = ltf_params[3]; //initS
			Params.FITINIT[1][4] = ltf_params[4]; 				//initV //fonly
			Params.FITINIT[1][5] = ltf_params[5]; //initV
			Params.FITINIT[1][6] = ltf_params[6]; //initV
			Params.FITINIT[1][7] = ltf_params[7]; 				//initV //control
			Params.FITINIT[1][8] = ltf_params[8]; //initR
			//Params.FITINIT[1][9] = ltf_params[8]; //initR //same R across all sites
			//Params.FITINIT[1][10] = ltf_params[8]; //initR
			//Params.FITINIT[1][11] = ltf_params[8]; //initR
			Params.FITINIT[1][9] = ltf_params[9]; //initR
			Params.FITINIT[1][10] = ltf_params[10]; //initR
			Params.FITINIT[1][11] = ltf_params[11]; //initR

			//metapopulation two
			Params.FITINIT[2][0] = ltf_params[12]; //initS
			Params.FITINIT[2][1] = ltf_params[13]; //initS
			Params.FITINIT[2][2] = ltf_params[14]; //initS
			Params.FITINIT[2][3] = ltf_params[15]; //initS
			Params.FITINIT[2][4] = ltf_params[16]; 				//initV //fonly
			Params.FITINIT[2][5] = ltf_params[17]; //initV
			Params.FITINIT[2][6] = ltf_params[18]; //initV
			Params.FITINIT[2][7] = ltf_params[19]; 				//initV //control
			//Params.FITINIT[2][8] = ltf_params[8]; //initR //same R across all sites
			//Params.FITINIT[2][9] = ltf_params[8]; //initR
			//Params.FITINIT[2][10] = ltf_params[8]; //initR
			//Params.FITINIT[2][11] = ltf_params[8]; //initR
			Params.FITINIT[2][8] = ltf_params[20]; //initR
			Params.FITINIT[2][9] = ltf_params[21]; //initR
			Params.FITINIT[2][10] = ltf_params[22]; //initR
			Params.FITINIT[2][11] = ltf_params[23]; //initR

			//metapopulation three
			Params.FITINIT[3][0] = ltf_params[24]; //initS
			Params.FITINIT[3][1] = ltf_params[25]; //initS
			Params.FITINIT[3][2] = ltf_params[26]; //initS
			Params.FITINIT[3][3] = ltf_params[27]; //initS
			Params.FITINIT[3][4] = ltf_params[28]; 				//initV //f only
			Params.FITINIT[3][5] = ltf_params[29]; //initV
			Params.FITINIT[3][6] = ltf_params[30]; //initV
			Params.FITINIT[3][7] = ltf_params[31];				 //initV //control
			//Params.FITINIT[3][8] = ltf_params[8]; //initR
			//Params.FITINIT[3][9] = ltf_params[8]; //initR
			//Params.FITINIT[3][10] = ltf_params[8]; //initR
			//Params.FITINIT[3][11] = ltf_params[8]; //initR
			Params.FITINIT[3][8] = ltf_params[32]; //initR
			Params.FITINIT[3][9] = ltf_params[33]; //initR
			Params.FITINIT[3][10] = ltf_params[34]; //initR
			Params.FITINIT[3][11] = ltf_params[35]; //initR

			//metapopultion four
			Params.FITINIT[4][0] = ltf_params[36]; //initS
			Params.FITINIT[4][4] = ltf_params[37]; //initV
			//Params.FITINIT[4][8] = ltf_params[8]; //initR
			Params.FITINIT[4][8] = ltf_params[38]; //initR

			//metapopultion five
			Params.FITINIT[5][0] = ltf_params[39]; //initS
			Params.FITINIT[5][4] = ltf_params[40]; //initV
			//Params.FITINIT[5][8] = ltf_params[8]; //initR
			Params.FITINIT[5][8] = ltf_params[41]; //initR

			//metapopultion six
			Params.FITINIT[6][0] = ltf_params[42]; //initS
			Params.FITINIT[6][4] = ltf_params[43]; //initV
			//Params.FITINIT[6][8] = ltf_params[8]; //initR
			Params.FITINIT[6][8] = ltf_params[44]; //initR

			//dispersal parameters
			Params.con_mrg 		= ltf_params[45];
			Params.a 			= ltf_params[46];
			Params.lar_disp 	= ltf_params[47];
			//coinfection parameters
			Params.coinf_V		= ltf_params[48];
			Params.VFSus		= ltf_params[49];
			//stochasticity parameters
			Params.Rsd_exp 		= ltf_params[50];
			Params.Fsd_exp		= ltf_params[51];
			Params.Rsd_obs		= ltf_params[52];
			Params.Fsd_exp		= ltf_params[53];
		
			
			//-------------------MISER CALCULATE LIKELIHOOD------------------------------//
		double lhood_meta=0; double log_lhood_meta=0; double total_loghood_metas = 0;
		double new_posterior=0;
		double meta_err=0;
		double lhood_total=0;
		double lhood_reps=0;

		calls=10;					//number of stochastic simulations for each parameter and IC set //100-300

		for(j=1; j<=DATA_SETS; j++){
		//for(j=1; j<2; j++){
			Params.j = j;

			dim = 48*2; 

			//define function
			gsl_monte_function G = { &LHood_Meta, dim, &Params };	// declares function calling lhood_meta.h
			double xl[dim];	double xu[dim];	// need to redeclare xl and xu since the size changes
			for (jj=0;jj<=dim;jj++)	{
				xl[jj]=0;	
				xu[jj]=1;
			}

			gsl_monte_miser_state *s = gsl_monte_miser_alloc(dim);
			gsl_monte_miser_integrate (&G,xl,xu,dim,calls,r_seed,s,&lhood_meta,&meta_err); //call MISER, pop_lhood is output from .h (likelihood value)
			gsl_monte_miser_free(s);

			//fprintf(fpl, "For dataset %i, lhood = %lf\t, err = %lf\n", j, lhood_meta, meta_err);
			//fprintf(fpl, "For dataset %i, lhood = %lf\n", j, lhood_meta);
			//printf("lhood post MISER = %lf\n", lhood_meta);
			
			log_lhood_meta = log(lhood_meta) - Params.lhood_adjust[j];
			if(isnan(log_lhood_meta) || isinf(log_lhood_meta)){ //change to zero of inf or nan, only update lhood adj if not
			}
			else{
				Params.lhood_adjust[j] = -1*log_lhood_meta; //update lhood adj based on average so it is dynamic
				//printf("ELSE adj = %lf\n", Params.lhood_adjust[j]);
			}
			//printf("MADE IT OUT: log_lhood_meta = %lf\n", log_lhood_meta);
			total_loghood_metas = total_loghood_metas + log_lhood_meta;
			//printf("total = %lf\n", total_loghood_metas);
			new_posterior = total_loghood_metas + log_prior;
			//printf("new posterior = %lf\n", new_posterior);
		}//j 
		if (new_posterior>best_posterior){ //compare likelihood //sum - one you just generated //local max - best you've seen
			best_posterior=new_posterior;
			printf("best posterior = %lf\n", best_posterior);
			for (c=0;c<num_ltfparams;c++){
				localmax_params[c]=ltf_params[c]; //save best param set from each individual search
			}
		}
		//printf("best post = %lf\n", best_posterior);
	}  //best param set from within searches
	for (c=0;c<num_ltfparams;c++){
		ltf_params[c]=localmax_params[c];
	}
	a++; //move to next parameter	
	} //a
	for(ii=0; ii<num_ltfparams; ii++){
		fprintf(fpv, "%lf\t", ltf_params[ii]);
	}
	fprintf(fpv, "%lf\t", best_posterior);
	fprintf(fpv, "\n");
}

//fclose(fpl);
fclose(fpv); //parameter values
fclose(fp1); //model realizations
}



///////////////////////////////////////////////////MCMC///////////////////////////////////////////////////


if(mcmc==1){

	int pid;
	pid=getpid();

	char namem[50];
	sprintf(namem, "mcmc_results_%d", pid);
	fpm=fopen(namem, "a+");

	int NumberOfParams=54;		

	int Realizations=100;         //JL: Number of realizations in the MCMC step

	double RandomNumber;

	double LogJumpToNew;
	double LogJumpToOld;
	double ProbOfAcceptance;

	double LogOldPosterior;
	double LogNewPosterior;
	double LogNewPrior;

	int run;
	int changer;
	
	double pop_lhood, pop_lhood2, pop_err,post_hood;	// population lhood (and posterior lhood) calculated for each initS and initR
	double pop_best_lhood;					// likelihood and error for best initS and initR
	double best_post_hood;	double best_lhood=0;		// best post_hood and lhood
	double prior[num_adj_pars];


	const gsl_rng_type * T;

	gsl_rng * r;
	gsl_rng_env_setup();
	T = gsl_rng_default;
	r = gsl_rng_alloc (T);
	gsl_rng_set(r, time(NULL)*(int)getpid());     //JL: Include the process id to avoid taking the same random number at the beginning stage (multiple jobs submitted together at the same time).
	srand(time(NULL));

	double delta=0;

	//Some variables for recording the PCA results//
	double SDpca[NumberOfParams];
	double Coefficients[NumberOfParams*NumberOfParams];
	double Center[NumberOfParams];
	double Scale[NumberOfParams];
	double PC[NumberOfParams];
	double Old_PC[NumberOfParams];
	double Holder[NumberOfParams];
	double PCAparams[NumberOfParams];
	double Old_Params[NumberOfParams];

	//double AcceptedVect[NumberOfParams]={0.0};
	//double LoopVect[NumberOfParams]={0.0};

	int a;
	int b;
	int ticker;
	int ticker2;

	int Case;

	int Accepted=0;
	signed int LoopNumber=-1;

	int ParCnt2 = NumberOfParams;

	double SigmaInflation=1.20;  //CK// Dave had 4 as his sigma inflation factor - FORMERLY WAS 0.5, WHICH IS A BAD THING

	double sigma[NumberOfParams];

	run=1;	changer=1;	best_post_hood=-10000000000;


//---------------------------------Read in PCA-----------------------------------//

	FILE *file;

	file=fopen("PCAsd_test.txt", "r");          //Reading in the standard deviations of PCA.
	for (a=0; a<(NumberOfParams); a++)
	{
		fscanf(file, "%lf\n", &SDpca[a]);
		//printf("%lf\n", SDpca[a]);
	}
	fclose(file);


	file=fopen("PCArotations_test.txt", "r");   //Reading in the rotations (coefficients between PC's and parameters)
	for (a=0; a<(NumberOfParams*NumberOfParams); a++)
	{
		fscanf(file, "%lf\n", &Coefficients[a]);
		//printf("%lf\n", Coefficients[a]);
	}
	fclose(file);

	file=fopen("PCAscale_test.txt", "r");        //Reading in the scales to reconstruct parameter values from PC's.
	for (a=0; a<NumberOfParams; a++)
	{
		fscanf(file, "%lf\n", &Scale[a]);
		//printf("%lf\n", Scale[a]);
	}
	fclose(file);

	file=fopen("PCAcenter_test.txt", "r");       //Reading in the centers of parameters. Used in the reconstruction of parameters.

	for (a=0; a<NumberOfParams; a++)
	{
		fscanf(file, "%lf\n", &Center[a]);
		//printf("%lf\n", Center[a]);
	}
	fclose(file);

	//getc(stdin);

//-------------------------generate PCs---------------------//
//start out by inflating variance to make overdispersed, then see if var goes down with time.
		//as variance goes down, that's evidence that chains are converging
	for(a=0; a<NumberOfParams; a++){
		sigma[a]=SigmaInflation*SDpca[a];
		//printf("%lf\n", sigma[a]);
	}


	for (a=0; a<NumberOfParams; a++){
		PC[a]=gsl_ran_gaussian (r, sigma[a]);    //CK//  PC contains current set of PC values
		//printf("%lf\n", PC[a]);
	}
	//getc(stdin);

//------------------------begin loop---------------------------------//
while (LoopNumber<=Realizations) {     
		//printf("loop number = %i\n", LoopNumber);
		LoopNumber=LoopNumber+1;

		Case=LoopNumber%NumberOfParams;					//Determines which PC to change
		//printf("CASE = %i\n");

		for (a=0; a<NumberOfParams; a++)
		{
			Old_PC[a]=PC[a];							//Store old PC values
		}

		//--------------------------draw new PC------------------------------//
		PC[Case]=gsl_ran_gaussian (r, sigma[Case]);

		//---------------------------------reconstruct PCA---------------------//
		for (a=0;a<NumberOfParams; a++)								//Back transform PC's into model parameters
		{
			for (b=0; b<NumberOfParams; b++){
				Holder[b]=Coefficients[a*NumberOfParams+b];         //Store the coefficients between a certain parameter and all the PC's
			}

			//reconstruct PCA into parameter values
			PCAparams[a]=exp(DotProduct(ParCnt2, Holder, PC)*Scale[a]+Center[a]);            //Reconstruct the parameter value after tweaking one PC
			Old_Params[a]=exp(DotProduct(ParCnt2, Holder, Old_PC)*Scale[a]+Center[a]);       //Reconstruct the parameter value before tweaking that PC

		    //printf("%f\n", PC[a]);
		    //printf("PCAparams: %e\n", PCAparams[a]);  
			//getc(stdin);

		}

		LogJumpToNew= -log(gsl_ran_gaussian_pdf(PC[Case], sigma[Case]));		//Metropolis sampling step: LATER YOU WILL USE THIS TO CORRECT FOR PROPOSAL
		LogJumpToOld= -log(gsl_ran_gaussian_pdf(Old_PC[Case], sigma[Case]));

		//------------------assign new parameter values----------------------//
			Params.FITINIT[1][0] = PCAparams[0]; //initS
			Params.FITINIT[1][1] = PCAparams[1]; //initS
			Params.FITINIT[1][2] = PCAparams[2]; //initS
			Params.FITINIT[1][3] = PCAparams[3]; //initS
			Params.FITINIT[1][4] = PCAparams[4]; 				//initV //fonly
			Params.FITINIT[1][5] = PCAparams[5]; //initV
			Params.FITINIT[1][6] = PCAparams[6]; //initV
			Params.FITINIT[1][7] = PCAparams[7]; 				//initV //control
			Params.FITINIT[1][8] = PCAparams[8]; //initR
			Params.FITINIT[1][9] = PCAparams[9]; //initR
			Params.FITINIT[1][10] = PCAparams[10]; //initR
			Params.FITINIT[1][11] = PCAparams[11]; //initR

			//metapopulation two
			Params.FITINIT[2][0] = PCAparams[12]; //initS
			Params.FITINIT[2][1] = PCAparams[13]; //initS
			Params.FITINIT[2][2] = PCAparams[14]; //initS
			Params.FITINIT[2][3] = PCAparams[15]; //initS
			Params.FITINIT[2][4] = PCAparams[16]; 				//initV //fonly
			Params.FITINIT[2][5] = PCAparams[17]; //initV
			Params.FITINIT[2][6] = PCAparams[18]; //initV
			Params.FITINIT[2][7] = PCAparams[19]; 				//initV //control
			Params.FITINIT[2][8] = PCAparams[20]; //initR
			Params.FITINIT[2][9] = PCAparams[21]; //initR
			Params.FITINIT[2][10] = PCAparams[22]; //initR
			Params.FITINIT[2][11] = PCAparams[23]; //initR

			//metapopulation three
			Params.FITINIT[3][0] = PCAparams[24]; //initS
			Params.FITINIT[3][1] = PCAparams[25]; //initS
			Params.FITINIT[3][2] = PCAparams[26]; //initS
			Params.FITINIT[3][3] = PCAparams[27]; //initS
			Params.FITINIT[3][4] = PCAparams[28]; 				//initV //f only
			Params.FITINIT[3][5] = PCAparams[29]; //initV
			Params.FITINIT[3][6] = PCAparams[30]; //initV
			Params.FITINIT[3][7] = PCAparams[31];				 //initV //control
			Params.FITINIT[3][8] = PCAparams[32]; //initR
			Params.FITINIT[3][9] = PCAparams[33]; //initR
			Params.FITINIT[3][10] = PCAparams[34]; //initR
			Params.FITINIT[3][11] = PCAparams[35]; //initR

			//metapopultion four
			Params.FITINIT[4][0] = PCAparams[36]; //initS
			Params.FITINIT[4][4] = PCAparams[37]; //initV
			Params.FITINIT[4][8] = PCAparams[38]; //initR

			//metapopultion five
			Params.FITINIT[5][0] = PCAparams[39]; //initS
			Params.FITINIT[5][4] = PCAparams[40]; //initV
			Params.FITINIT[5][8] = PCAparams[41]; //initR

			//metapopultion six
			Params.FITINIT[6][0] = PCAparams[42]; //initS
			Params.FITINIT[6][4] = PCAparams[43]; //initV
			Params.FITINIT[6][8] = PCAparams[44]; //initR

			//dispersal parameters
			Params.con_mrg 		= PCAparams[45];
			Params.a 			= PCAparams[46];
			Params.lar_disp 	= PCAparams[47];
			//coinfection parameters
			Params.coinf_V		= PCAparams[48];
			Params.VFSus		= PCAparams[49];
			//stochasticity parameters
			Params.Rsd_exp 		= PCAparams[50];
			Params.Fsd_exp		= PCAparams[51];
			Params.Rsd_obs		= PCAparams[52];
			Params.Fsd_exp		= PCAparams[53];
		
		//-------------------MISER likelihood new------------------------------//
		double lhood_meta=0; double log_lhood_meta=0; double total_loghood_metas = 0;
		double new_posterior=0;
		double meta_err=0;
		double lhood_total=0;
		double lhood_reps=0;

		calls=10;					//number of stochastic simulations for each parameter and IC set //100-300

		for(j=1; j<=DATA_SETS; j++){
		//for(j=1; j<2; j++){
			Params.j = j;

			dim = 48*2; 

			//define function
			gsl_monte_function G = { &LHood_Meta, dim, &Params };	// declares function calling lhood_meta.h
			double xl[dim];	double xu[dim];	// need to redeclare xl and xu since the size changes
			for (jj=0;jj<=dim;jj++)	{
				xl[jj]=0;	
				xu[jj]=1;
			}

			gsl_monte_miser_state *s = gsl_monte_miser_alloc(dim);
			gsl_monte_miser_integrate (&G,xl,xu,dim,calls,r_seed,s,&lhood_meta,&meta_err); //call MISER, pop_lhood is output from .h (likelihood value)
			gsl_monte_miser_free(s);

			//fprintf(fpl, "For dataset %i, lhood = %lf\t, err = %lf\n", j, lhood_meta, meta_err);
			//fprintf(fpl, "For dataset %i, lhood = %lf\n", j, lhood_meta);
			//printf("lhood post MISER = %lf\n", lhood_meta);
			
			log_lhood_meta = log(lhood_meta) - Params.lhood_adjust[j];
			if(isnan(log_lhood_meta) || isinf(log_lhood_meta)){ //change to zero of inf or nan, only update lhood adj if not
				log_lhood_meta = 0;
			}
			else{
				Params.lhood_adjust[j] = -1*log_lhood_meta; //update lhood adj based on average so it is dynamic
				//printf("ELSE adj = %lf\n", Params.lhood_adjust[j]);
			}
			total_loghood_metas = total_loghood_metas + log_lhood_meta;
			//printf("total = %lf\n", total_loghood_metas);
			LogNewPosterior = 0.0;
			LogNewPosterior = total_loghood_metas + log_prior;
			//printf("new posterior = %lf\n", LogNewPosterior);
		}//j 

		//-------------------assign old parameter values-----------------------//
			Params.FITINIT[1][0] = Old_Params[0]; //initS
			Params.FITINIT[1][1] = Old_Params[1]; //initS
			Params.FITINIT[1][2] = Old_Params[2]; //initS
			Params.FITINIT[1][3] = Old_Params[3]; //initS
			Params.FITINIT[1][4] = Old_Params[4]; 				//initV //fonly
			Params.FITINIT[1][5] = Old_Params[5]; //initV
			Params.FITINIT[1][6] = Old_Params[6]; //initV
			Params.FITINIT[1][7] = Old_Params[7]; 				//initV //control
			Params.FITINIT[1][8] = Old_Params[8]; //initR
			Params.FITINIT[1][9] = Old_Params[9]; //initR
			Params.FITINIT[1][10] = Old_Params[10]; //initR
			Params.FITINIT[1][11] = Old_Params[11]; //initR

			//metapopulation two
			Params.FITINIT[2][0] = Old_Params[12]; //initS
			Params.FITINIT[2][1] = Old_Params[13]; //initS
			Params.FITINIT[2][2] = Old_Params[14]; //initS
			Params.FITINIT[2][3] = Old_Params[15]; //initS
			Params.FITINIT[2][4] = Old_Params[16]; 				//initV //fonly
			Params.FITINIT[2][5] = Old_Params[17]; //initV
			Params.FITINIT[2][6] = Old_Params[18]; //initV
			Params.FITINIT[2][7] = Old_Params[19]; 				//initV //control
			Params.FITINIT[2][8] = Old_Params[20]; //initR
			Params.FITINIT[2][9] = Old_Params[21]; //initR
			Params.FITINIT[2][10] = Old_Params[22]; //initR
			Params.FITINIT[2][11] = Old_Params[23]; //initR

			//metapopulation three
			Params.FITINIT[3][0] = Old_Params[24]; //initS
			Params.FITINIT[3][1] = Old_Params[25]; //initS
			Params.FITINIT[3][2] = Old_Params[26]; //initS
			Params.FITINIT[3][3] = Old_Params[27]; //initS
			Params.FITINIT[3][4] = Old_Params[28]; 				//initV //f only
			Params.FITINIT[3][5] = Old_Params[29]; //initV
			Params.FITINIT[3][6] = Old_Params[30]; //initV
			Params.FITINIT[3][7] = Old_Params[31];				 //initV //control
			Params.FITINIT[3][8] = Old_Params[32]; //initR
			Params.FITINIT[3][9] = Old_Params[33]; //initR
			Params.FITINIT[3][10] = Old_Params[34]; //initR
			Params.FITINIT[3][11] = Old_Params[35]; //initR

			//metapopultion four
			Params.FITINIT[4][0] = Old_Params[36]; //initS
			Params.FITINIT[4][4] = Old_Params[37]; //initV
			Params.FITINIT[4][8] = Old_Params[38]; //initR

			//metapopultion five
			Params.FITINIT[5][0] = Old_Params[39]; //initS
			Params.FITINIT[5][4] = Old_Params[40]; //initV
			Params.FITINIT[5][8] = Old_Params[41]; //initR

			//metapopultion six
			Params.FITINIT[6][0] = Old_Params[42]; //initS
			Params.FITINIT[6][4] = Old_Params[43]; //initV
			Params.FITINIT[6][8] = Old_Params[44]; //initR

			//dispersal parameters
			Params.con_mrg 		= Old_Params[45];
			Params.a 			= Old_Params[46];
			Params.lar_disp 	= Old_Params[47];
			//coinfection parameters
			Params.coinf_V		= Old_Params[48];
			Params.VFSus		= Old_Params[49];
			//stochasticity parameters
			Params.Rsd_exp 		= Old_Params[50];
			Params.Fsd_exp		= Old_Params[51];
			Params.Rsd_obs		= Old_Params[52];
			Params.Fsd_exp		= Old_Params[53];

		//-------------------MISER likelihood old------------------------------//
		lhood_meta=0; log_lhood_meta=0; total_loghood_metas = 0;
		new_posterior=0;
		meta_err=0;
		lhood_total=0;
		lhood_reps=0;

		calls=10;					//number of stochastic simulations for each parameter and IC set //100-300

		for(j=1; j<=DATA_SETS; j++){
		//for(j=1; j<2; j++){
			Params.j = j;

			dim = 48*2; 
			//printf("in the old loop\n");
			//define function
			gsl_monte_function G = { &LHood_Meta, dim, &Params };	// declares function calling lhood_meta.h
			double xl[dim];	double xu[dim];	// need to redeclare xl and xu since the size changes
			for (jj=0;jj<=dim;jj++)	{
				xl[jj]=0;	
				xu[jj]=1;
			}

			gsl_monte_miser_state *s = gsl_monte_miser_alloc(dim);
			gsl_monte_miser_integrate (&G,xl,xu,dim,calls,r_seed,s,&lhood_meta,&meta_err); //call MISER, pop_lhood is output from .h (likelihood value)
			gsl_monte_miser_free(s);

			//fprintf(fpl, "For dataset %i, lhood = %lf\t, err = %lf\n", j, lhood_meta, meta_err);
			//fprintf(fpl, "For dataset %i, lhood = %lf\n", j, lhood_meta);
			//printf("out of the old\n");
			
			log_lhood_meta = log(lhood_meta) - Params.lhood_adjust[j];
			if(isnan(log_lhood_meta) || isinf(log_lhood_meta)){ //change to zero of inf or nan, only update lhood adj if not
				log_lhood_meta = 0;
			}
			else{
				Params.lhood_adjust[j] = -1*log_lhood_meta; //update lhood adj based on average so it is dynamic
				//printf("ELSE adj = %lf\n", Params.lhood_adjust[j]);
			}
			//printf("MADE IT OUT: log_lhood_meta = %lf\n", log_lhood_meta);
			total_loghood_metas = total_loghood_metas + log_lhood_meta;
			//printf("total = %lf\n", total_loghood_metas);
			LogOldPosterior=0.0;
			LogOldPosterior = total_loghood_metas + log_prior;
			//printf("old posterior = %lf\n", LogOldPosterior);
		}//j 


		//----------compare new parm set with old parm set----------------
		
		ProbOfAcceptance=exp(LogNewPosterior+LogJumpToOld - LogOldPosterior-LogJumpToNew);    //Probability of accepting the new PC

		Params.LoopVect[Case] = Params.LoopVect[Case] + 1;

		if (ProbOfAcceptance>1 || gsl_rng_uniform_pos (r) < ProbOfAcceptance)   //MH-MCMC algorithm
		{
			LogOldPosterior=LogNewPosterior;  //Accept the new parameter values.
			//Accepted=Accepted+1;
			printf("Accepted\n");
			Params.AcceptedVect[Case] = Params.AcceptedVect[Case] + 1;
		}

		else
		{
			for (a=0; a<NumberOfParams; a++)
			{
				PC[a]=Old_PC[a];            //Keep the old parameter values.
			}

			printf("Rejected\n");

		}

		// ------------------------------------------ output results to file  --------------------------------------- //
		if (LoopNumber % 10 == 0)   	//CK// output results every 10 loops (probably not best plan but we'll see)
		{
			printf("printing! loop number = %i\n", LoopNumber);
			for(ii=0; ii<NumberOfParams; ii++){
				fprintf(fpm, "%lf\t", PCAparams[ii]);
			}
			fprintf(fpm, "\n");
			//fflush(stdout);
		}
	}
	fclose(fpm);
}

return 0;
}
