#include "head_meta.h"
gsl_rng *r;

int main(void)
{

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
int num_adj_pars = 50;			// number of adjustable parameters
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
FILE *fp_results;

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

int searches = 5; //number of iterations for each specific parameter
int round;
int numround = 10;

int num_ltfparams = 54;	//number of parameters to fit
double ltf_params[54] = {0};      //arrays to hold different parameter values
double init_ltfparams[54]={0};

for (i=0;i<num_ltfparams;i++){ 											//give random initial value for each parameter
    double randn = gsl_rng_uniform_pos(r_seed);
    ltf_params[i] = bound(i,1) + randn * bound(i,2);
    init_ltfparams[i] = ltf_params[i]; 
    //printf("%lf\n",init_ltfparams[i]);
	//printf("i = %i\t, lft_params = %lf\n %lf\n",i, init_ltfparams[i]);
}
//CHECK
double localmax_params[54]={0};         //Array to record param values for the local max likelihood in line search
int a,b,c;								//indexing loops
double localmax_posterior; double max_posterior;
for (c=0;c<num_ltfparams;c++){			//initial parameters begin as 'best' parameters
    localmax_params[c]=ltf_params[c];
}

int r;


//----------------------------------------------------Print Output to File-------------------------------------------//
int pid;
pid=getpid();

char namev[50];
sprintf(namev, "allmeta_s%i_r%i_%d", searches, numround, pid);
fpv=fopen(namev, "a+");

char name1[50];
sprintf(name1, "model_realizations");
fp1=fopen(name1, "a+");

char namel[50];
sprintf(namel, "lhood_s%i_r%i_%d", searches, numround, pid);
fpl=fopen(namel, "a+");

//---------------------------------------------- Line-Search -------------------------------------------------------//
//specify parameter bounds and increments
//all but dispersal
//int paramfit[46] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 48, 49}; //array of params to fit
//int paramfit[5] = {36, 37, 38, 48, 49};
//int paramfit[17] = {12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 45, 46, 47, 48, 49};
//int len_paramfit = 17; //length of fit array - 1

for (round=0;round<numround;round++){
	printf("in the rounds loop\n");
	localmax_posterior=-999999999999;
	a=0;
	while (a<num_ltfparams){            
		if (round>0){					
			ltf_params[a] = ltf_params[a] - step(a) * searches;
			if(ltf_params[a] <= bound(i,1)){
				printf("in the a loop\n");
				ltf_params[a] = bound(i,1);
			}
		}
		for (b=0;b<searches;b++){ 
			if (b>0){
				ltf_params[a] = ltf_params[a] + step(a);
				printf("in the b loop\n");
				if(ltf_params[a] >= (bound(i,2)+bound(i,1))){
					ltf_params[a] = (bound(i,2)+bound(i,1));
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
		double log_prior=0; double new_posterior=0;
		double meta_err=0;
		double lhood_total=0;
		double lhood_reps=0;

		int calls=10;					//number of stochastic simulations for each parameter and IC set //100-300

		size_t dim;

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
			//printf("MADE IT OUT: log_lhood_meta = %lf\n", log_lhood_meta);
			total_loghood_metas = total_loghood_metas + log_lhood_meta;
			//printf("total = %lf\n", total_loghood_metas);

			//calculate priors
			for (k=0; k<num_ltfparams; k++){
				//printf("numparams = %i\n", num_ltfparams);
				log_prior = log_prior + log(gsl_ran_flat_pdf(ltf_params[k], bound(k,1), (bound(k,2)+bound(k,1))));
				//printf("param = %lf\t log prior = %lf\n", ltf_params[k], log(gsl_ran_flat_pdf(ltf_params[k], bound(k,1), (bound(k,2)+bound(k,1)))));
				//printf("k = %i\t param = %lf\t log prior = %lf\n", k, ltf_params[k], log_prior);
			}

			new_posterior = total_loghood_metas + log_prior;
			//printf("new posterior = %lf\n", new_posterior);
		}//j 
		if (new_posterior>localmax_posterior){ //compare likelihood //sum - one you just generated //local max - best you've seen
			localmax_posterior=new_posterior;

			for (c=0;c<num_ltfparams;c++){
				localmax_params[c]=ltf_params[c]; //save best param set from each individual search
			}
		}
	}  //best param set from within searches
	for (c=0;c<num_ltfparams;c++){
		ltf_params[c]=localmax_params[c];
		//fprintf(fpv, "param %i\t %lf\t %lf\n", c, ltf_params[c], localmax_lhood);
	}
	max_posterior=localmax_posterior;
	//printf("max_post = %lf\n", localmax_posterior);
	a++; //move to next parameter
	} //a
}
//print all param values to file
for(ii=0; ii<num_ltfparams; ii++){
	fprintf(fpv, "%lf\t", ltf_params[ii]);
}
fprintf(fpv, "\n");
fprintf(fpl, "max_post = %lf\n", max_posterior); //print just final likelihood value
//fclose(fpl);
fclose(fpv); //parameter values
fclose(fp1); //model realizations
fclose(fpl); //likelihood scores
//free_i3tensor(Params.EXPDATA,0,DATA_SETS,0,MAX_WEEKS,0,3);
return 0;
}
