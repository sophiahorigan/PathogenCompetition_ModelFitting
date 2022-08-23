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

int linesearch = 0;
int mcmc = 0;
int reals = 1;

STRUCTURE Params;

int pro = 1;//atoi(argv[1]);						// pro and argv[1] are the inputs (argv[i] is the i^th input)
//printf("Profile Parameter is %d\n",pro);	fflush(stdout);

// ----------------------------------------Set Up-------------------------------------------------------------------- //
int i=0; int j;int ii; int jj; int k; int l; 
int num_adj_pars = 55;			// number of adjustable parameters
int epi_length = 49;

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
Params.lhood_adjust[1] = 2500;
Params.lhood_adjust[2] = 2500;
Params.lhood_adjust[3] = 2500;
Params.lhood_adjust[4] = 2000;
Params.lhood_adjust[5] = 2000;
Params.lhood_adjust[6] = 1000;

int searches = 7; //number of iterations for each specific parameter
int round;
int numround = 4;
int calls;
size_t dim;

int num_ltfparams = 55;	//number of parameters to fit
double ltf_params[55] = {0};      //arrays to hold different parameter values
double init_ltfparams[55]={0};

double log_prior=0;

for (i=0;i<num_ltfparams;i++){ 											//give random initial value for each parameter
    double randn = gsl_rng_uniform_pos(r_seed);
    ltf_params[i] = ls_bound(i,1) + randn * ls_bound(i,2);
    init_ltfparams[i] = ltf_params[i]; 
    //printf("%lf\n",init_ltfparams[i]);
	//printf("i = %i\t, lft_params = %lf\n %lf\n",i, init_ltfparams[i]);
}
//CHECK
double localmax_params[55]={0};         //Array to record param values for the local max likelihood in line search
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
	
	double initS_fit = 19.53;
	//propose parameter values
	//metapopulation one
	Params.FITINIT[1][0] = initS_fit; //initS
	Params.FITINIT[1][1] = initS_fit; //initS
	Params.FITINIT[1][2] = initS_fit; //initS
	Params.FITINIT[1][3] = initS_fit; //initS
	Params.FITINIT[1][4] = 0.000001; 				//initV //fonly
	Params.FITINIT[1][5] = 0.2; //initV
	Params.FITINIT[1][6] = 0.2; //initV
	Params.FITINIT[1][7] = 0.000001; 				//initV //control
	Params.FITINIT[1][8] = 0.003396; //initR
	Params.FITINIT[1][9] = 0.002306; //initR
	Params.FITINIT[1][10] = 0.000446; //initR
	Params.FITINIT[1][11] = 0.002157; //initR

	//metapopulation two
	Params.FITINIT[2][0] = initS_fit; //initS
	Params.FITINIT[2][1] = initS_fit; //initS
	Params.FITINIT[2][2] = initS_fit; //initS
	Params.FITINIT[2][3] = initS_fit; //initS
	Params.FITINIT[2][4] = 0.000001; 				//initV //fonly
	Params.FITINIT[2][5] = 0.2; //initV
	Params.FITINIT[2][6] = 0.2; //initV
	Params.FITINIT[2][7] = 0.000001; 				//initV //control
	Params.FITINIT[2][8] = 0.001272; //initR
	Params.FITINIT[2][9] = 0.002010; //initR
	Params.FITINIT[2][10] = 0.003034; //initR
	Params.FITINIT[2][11] = 0.003778; //initR

	//metapopulation three
	Params.FITINIT[3][0] = initS_fit; //initS
	Params.FITINIT[3][1] = initS_fit; //initS
	Params.FITINIT[3][2] = initS_fit; //initS
	Params.FITINIT[3][3] = initS_fit; //initS
	Params.FITINIT[3][4] = 0.0000000001; 				//initV //f only
	Params.FITINIT[3][5] = 0.2; //initV
	Params.FITINIT[3][6] = 0.2; //initV
	Params.FITINIT[3][7] = 0.0000000001;				 //initV //control
	Params.FITINIT[3][8] = 0.006094; //initR
	Params.FITINIT[3][9] = 0.002874; //initR
	Params.FITINIT[3][10] = 0.008925; //initR
	Params.FITINIT[3][11] = 0.006389; //initR

	//metapopultion four
	Params.FITINIT[4][0] = 15.968701; //initS
	Params.FITINIT[4][4] = 0.123265; //initV
	Params.FITINIT[4][8] = 0.001997; //initR

	//metapopultion five
	Params.FITINIT[5][0] = 82.875750; //initS
	Params.FITINIT[5][4] = 0.112749; //initV
	Params.FITINIT[5][8] = 0; //initR

	//metapopultion six
	Params.FITINIT[6][0] = 4.944996; //initS
	Params.FITINIT[6][4] = 0.05; //initV
	Params.FITINIT[6][8] = 0.003756; //initR

	//dispersal parameters
	Params.con_mgr 		= 20.658830;
	Params.a 			= 1;
	Params.lar_mgr 		= 54.001590;
	Params.a2			= 0.055372;

	//coinfection parameters
	Params.coinf_V		= 0;
	Params.VFSus		= 0;

	//stochasticity parameters
	Params.Rsd_exp 		= 0;
	Params.Fsd_exp		= 0;
	Params.Rsd_obs		= 0;
	Params.Fsd_obs		= 0;

	//start realizations. In this case, calls = # realizations
	double lhood_meta=0; double log_lhood_meta=0; double total_loghood_metas = 0;
	double new_posterior=0;
	double meta_err=0;
	double lhood_total=0;
	double lhood_reps=0;

	calls=10;					//number of stochastic simulations for each parameter and IC set //100-300

	//for(j=1; j<=DATA_SETS; j++){
		for(j=1; j<4; j++){
			Params.j = j;

			dim = 49*2; 

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

int exptmt = 1;	
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
		if (a==0 | a==8 | a==9 | a==10 | a==11 | a==20 | a==21 | a==22 | a==23 | a==32 | a==33 | a==34 | a==35 | a==45 | a==46 | a==47 | a==48){ 
		//if (a==8 | a==9 | a==10 | a==11 | a==45 | a==46 | a==47 | a==48){
		//observationals
		//if (a == 36 | a == 37 | a == 38 | a == 39 | a == 40 | a == 41 | a == 42 || a == 43 || a == 44 || a == 49 || a == 50){   
		if (round>0){		
			ltf_params[a] = ltf_params[a] - (step(a) * searches);
			if(ltf_params[a] <= ls_bound(a,1)){
				//printf("in the a loop\n");
				ltf_params[a] = ls_bound(a,1);
			}
		}
		for (b=0;b<searches;b++){ 
			if (b>0){
				ltf_params[a] = ltf_params[a] + step(a);
				//printf("in the b loop\n");
				if(ltf_params[a] >= (ls_bound(a,2)+ls_bound(a,1))){
					ltf_params[a] = (ls_bound(a,2)+ls_bound(a,1));
				}
			}

			if(exptmt==1){
			//Send new parameter values into code
			//printf("made it in");
			//metapopulation one
			Params.FITINIT[1][0] = ltf_params[0]; //initS
			Params.FITINIT[1][1] = ltf_params[0]; //initS
			Params.FITINIT[1][2] = ltf_params[0]; //initS
			Params.FITINIT[1][3] = ltf_params[0]; //initS
			Params.FITINIT[1][4] = 0.0000000001; 				//initV //fonly
			Params.FITINIT[1][5] = 0.2; //initV
			Params.FITINIT[1][6] = 0.2; //initV
			Params.FITINIT[1][7] = 0.0000000001; 				//initV //control
			Params.FITINIT[1][8] = ltf_params[8]; //initR
			//printf("initR one of them = %lf\n", Params.FITINIT[1][8]);
			Params.FITINIT[1][9] = ltf_params[9]; //initR //same R across all sites
			Params.FITINIT[1][10] = ltf_params[10]; //initR
			Params.FITINIT[1][11] = ltf_params[11]; //initR
			//Params.FITINIT[1][9] = ltf_params[9]; //initR
			//Params.FITINIT[1][10] = ltf_params[10]; //initR
			//Params.FITINIT[1][11] = ltf_params[11]; //initR

			//metapopulation two
			Params.FITINIT[2][0] = ltf_params[0]; //initS
			Params.FITINIT[2][1] = ltf_params[0]; //initS
			Params.FITINIT[2][2] = ltf_params[0]; //initS
			Params.FITINIT[2][3] = ltf_params[0]; //initS

			Params.FITINIT[2][4] = 0.0000000001; 				//initV //fonly
			Params.FITINIT[2][5] = 0.2; //initV
			Params.FITINIT[2][6] = 0.2; //initV
			Params.FITINIT[2][7] = 0.0000000001; 				//initV //control

			Params.FITINIT[2][8] = ltf_params[20]; //initR
			Params.FITINIT[2][9] = ltf_params[21]; //initR
			Params.FITINIT[2][10] = ltf_params[22]; //initR
			Params.FITINIT[2][11] = ltf_params[23]; //initR

			//metapopulation three
			Params.FITINIT[3][0] = ltf_params[0]; //initS
			Params.FITINIT[3][1] = ltf_params[0]; //initS
			Params.FITINIT[3][2] = ltf_params[0]; //initS
			Params.FITINIT[3][3] = ltf_params[0]; //initS

			Params.FITINIT[3][4] = 0.0000000001; 				//initV //f only
			Params.FITINIT[3][5] = 0.2; //initV
			Params.FITINIT[3][6] = 0.2; //initV
			Params.FITINIT[3][7] = 0.0000000001;				 //initV //control

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
			Params.con_mgr 		= ltf_params[45];
			Params.a 			= ltf_params[46];
			Params.lar_mgr	 	= ltf_params[47];
			Params.a2 			= ltf_params[48];

			//coinfection parameters
			Params.coinf_V		= ltf_params[49];
			Params.VFSus		= ltf_params[50];
	
			//stochasticity parameters
			//Params.Rsd_exp 		= ltf_params[51];
			Params.Rsd_exp 		= 0;
			Params.Fsd_exp		= 0;
			//Params.Fsd_exp		= ltf_params[52];
			Params.Rsd_obs		= 0;
			Params.Fsd_exp		= 0;
			//Params.Rsd_obs		= ltf_params[53];
			//Params.Fsd_exp		= ltf_params[54];
			}


			if(exptmt==0){
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
			Params.con_mgr 		= ltf_params[45];
			Params.a 			= ltf_params[46];
			Params.lar_mgr	 	= ltf_params[47];
			Params.a2 			= ltf_params[48];
			//coinfection parameters
			Params.coinf_V		= ltf_params[49];
			Params.VFSus		= ltf_params[50];
			//stochasticity parameters
			Params.Rsd_exp 		= ltf_params[51];
			Params.Fsd_exp		= ltf_params[52];
			Params.Rsd_obs		= ltf_params[53];
			Params.Fsd_obs		= ltf_params[54];
			}
			
		
			
			//-------------------MISER CALCULATE LIKELIHOOD------------------------------//
		double lhood_meta=0; double log_lhood_meta=0; double total_loghood_metas = 0;
		double new_posterior=0;
		double meta_err=0;
		double lhood_total=0;
		double lhood_reps=0;

		calls=10;					//number of stochastic simulations for each parameter and IC set //100-300

		//for(j=1; j<=DATA_SETS; j++){
		for(j=1; j<4; j++){
			Params.j = j;
			//printf("j in meta = %i\n", Params.j);

			dim = 49*2; 

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
			//printf("best posterior = %lf\n", best_posterior);
			for (c=0;c<num_ltfparams;c++){
				localmax_params[c]=ltf_params[c]; //save best param set from each individual search
			}
		}
		//printf("best post = %lf\n", best_posterior);
	}  //best param set from within searches
	for (c=0;c<num_ltfparams;c++){
		ltf_params[c]=localmax_params[c];
	}
	} //only params we want to fit
	a++; //move to next parameter	
	} //a

	//modified printing to only print fitting params without having to change num_lftparams
	int print_len = 17;

	//meta 1 : len = 10
	int printlist[17] = {0,8,9,10,11,20,21,22,23,32,33,34,35,45,46,47,48};
	//int printlist[8] = {8, 9, 10, 11, 45, 46, 47, 48};
	//int printlist[11] = {36, 37, 38, 39, 40, 41, 42, 43, 44, 49, 50};

	//experimental treatment : len = 30
	//int printlist[30] = {8, 9, 10, 11, 20, 21, 22, 23, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 51, 52, 53, 54};
	int index;
	for(ii=0; ii<print_len; ii++){
		index = printlist[ii];
		fprintf(fpv, "%lf\t", ltf_params[index]);
	}
	fprintf(fpv, "%lf\t", best_posterior);
	//printf("best posterior = %lf\n", best_posterior);
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

	int NumberOfParams=55;		

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
			Params.con_mgr 		= PCAparams[45];
			Params.a 			= PCAparams[46];
			Params.lar_mgr 		= PCAparams[47];
			Params.a2			= PCAparams[48];
			//coinfection parameters
			Params.coinf_V		= PCAparams[49];
			Params.VFSus		= PCAparams[50];
			//stochasticity parameters
			Params.Rsd_exp 		= PCAparams[51];
			Params.Fsd_exp		= PCAparams[52];
			Params.Rsd_obs		= PCAparams[53];
			Params.Fsd_obs		= PCAparams[54];
		
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

			dim = 49*2; 

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
			Params.con_mgr 		= Old_Params[45];
			Params.a 			= Old_Params[46];
			Params.lar_mgr	 	= Old_Params[47];
			Params.a2			= Old_Params[48];
			//coinfection parameters
			Params.coinf_V		= Old_Params[49];
			Params.VFSus		= Old_Params[50];
			//stochasticity parameters
			Params.Rsd_exp 		= Old_Params[51];
			Params.Fsd_exp		= Old_Params[52];
			Params.Rsd_obs		= Old_Params[53];
			Params.Fsd_obs		= Old_Params[54];

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

			dim = 49*2; 
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
			//printf("out of the old\n");l
			
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
