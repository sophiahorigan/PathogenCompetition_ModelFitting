#include "head.h"
gsl_rng *r;
//-----------------------Dot Product-----------------------//
float DotProduct (int Length, double *Holder, double *PCA)
{
  double answer = 0;

  int i;
  for(i=0;i<Length;i++){
    answer += PCA[i]*Holder[i];   //JL: Used in the reconstruction of parameter values from PCA
  }
  return(answer);

}

//-----------------------line-search mcmc-------------------------//

int main(int argc, char *argv[])
{

STRUCTURE Params;
inputdata(&Params);				
gsl_rng *r_seed;
r_seed=random_setup();

char *y = argv[1]; char *z = argv[2];
Params.model = atoi(y); Params.algorithm = atoi(z);

int model = Params.model;
int algorithm = Params.algorithm;

int VERBOSE = 1;
int TEST = 0;

// --------------------------------------------------Set Up-------------------------------------------------------------------- //

//ALGORITHM
if(algorithm==1){
	linesearch=1;reals=0;mcmc=0;
}
if(algorithm==2){
	linesearch=0;reals=1;mcmc=0;
}
if(algorithm==3){
	linesearch=0;reals=0;mcmc=1;
}
//printf("model= %i\t algorithm=%i\n", model, algorithm);
//DISPERSAL
//1 is fit, 0 is don't fit
int *p;
p = dispersal_fit(model);
larval_dispersal = p[0]; l_a_pop_fit = p[1]; l_a_meta_fit = p[2]; l_a_sub_fit = p[3]; l_m_pop_fit = p[4]; l_m_meta_fit = p[5]; l_m_sub_fit = p[6]; 
conidia_dispersal = p[7]; c_a_pop_fit = p[8]; c_a_meta_fit = p[9]; c_a_sub_fit = p[10]; c_m_pop_fit = p[11]; c_m_meta_fit = p[12]; c_m_sub_fit = p[13];
r_pop_fit = p[14]; r_meta_fit = p[15]; r_sub_fit = p[16];

//FIT LIST
//1 is fit, 0 is don't fit
//static int fit_params[92] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91};
int *f; 
f = which_fit(model);
for(int i=0;i<92;i++){
	fit[i] = f[i];
}
//LOG FIT
//1 is log fit, 0 is non-long fit
static int log_fit[92] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1};
//TEST MODE
if(VERBOSE==1){
	LScalls=50; Rcalls=10; Mcalls=100; Realizations=2000000;
	numround=30;searches=10;
}
if(TEST==1){
	LScalls=10; Rcalls=10; Mcalls=5; Realizations=10000;//Reals needs to be num params *2 to get all params
	numround=20;searches=2;
}

//----------------------------------Generate Inital Parameter Values------------------------//
int num_ltfparams = 92;
double ltf_params[92] = {0};   
double init_ltfparams[92] = {0};
double step_size[92] = {0};
double temp[92] = {0};

for (int i=0;i<num_ltfparams;i++){
    double randn = gsl_rng_uniform_pos(r_seed);
		if(log_fit[i]==1){//sampling in log space
  			temp[i] = exp(ls_bound(model, i,1)) + randn * exp(ls_bound(model,i,2)); //propose initial values in exp space to avoid issue with negative numbers
			ltf_params[i] = log(temp[i]); //re-log since we will be taking steps in log space
		}
		else{
			temp[i] = ls_bound(model,i,1) + randn * ls_bound(model,i,2); //propose initial values in exp space to avoid issue with negative numbers
			ltf_params[i] = temp[i]; //re-log since we will be taking steps in log space
		}
    init_ltfparams[i] = ltf_params[i];
	step_size[i] = (ls_bound(model,i,2)-ls_bound(model,i,1))/(searches*3);
}

double localmax_params[92]={0};         //Array to record param values for the local max likelihood in line search
int a,b,c;								//indexing loops
double best_posterior;
double total_loghood_metas;
for (c=0;c<num_ltfparams;c++){			//initial parameters begin as 'best' parameters
    localmax_params[c]=ltf_params[c];
}

///////////////////////////////////////////////////LINE-SEARCH///////////////////////////////////////////////////
if(linesearch==1){
int pid;
pid=getpid();

char namels[50];
sprintf(namels, "LS_s%i_r%i_m%i", searches, numround, model );
fpls=fopen(namels, "a+");

for (int round=0;round<numround;round++){
	best_posterior=-66666666666666;
	double log_prior = 0;
	a=0;
	int i=0;

	for(int i=0;i<num_ltfparams;i++){ 
		if(fit[i] == 1){
			a = i;

			if (round>0){		
				ltf_params[a] = ltf_params[a] - (step_size[a] * searches);
				if(ltf_params[a] < ls_bound(model,a,1)){ 
					ltf_params[a] = ls_bound(model,a,1);
				}
			}
			for (b=0;b<searches;b++){ 
				if (b>0){
					ltf_params[a] = ltf_params[a] + step_size[a]; 
					if(ltf_params[a] > ls_bound(model,a,2)){ 
						ltf_params[a] = ls_bound(model,a,2);
					}
				}

			//calculate priors for this parameter set
			log_prior=0;
			double new_log_prior=0;
			for (int k=0; k<num_ltfparams; k++){
				if(fit[k] == 1){
					if(log_fit[k]==1){ //log fit!
						new_log_prior = log(gsl_ran_flat_pdf(exp(ltf_params[k]), exp(ls_bound(model,k,1)), (exp(ls_bound(model,k,1))+exp(ls_bound(model,k,2)))));
					}
					else{ //non log fit!
						new_log_prior = log(gsl_ran_flat_pdf(ltf_params[k], ls_bound(model,k,1), (ls_bound(model,k,1)+ls_bound(model,k,2))));
					}
					if(isnan(new_log_prior) || isinf(new_log_prior)){ //outside of bounds, set bad score
						printf("PROBLEM WITH PRIORS\n");
						printf("k=%i\t new log prior = %lf\n", k, new_log_prior);
						new_log_prior = -999999;
					}
					log_prior = log_prior + new_log_prior;
				}
			}
			//getc(stdin);
			//********FIXED PARAMS***********
			//INITIAL CONDITIONS
			//meta1
			Params.FITINIT[1][4] = 0; //initV //fonly //FX
			Params.FITINIT[1][5] = 0.2; //initV  //FX
			Params.FITINIT[1][6] = 0.2; //initV //FX
			Params.FITINIT[1][7] = 0; //initV //control //FX
			Params.FITINIT[1][9] = 0; //initR //vonly  //FX
			Params.FITINIT[1][10] = 0; //initR //fv //FX
			Params.FITINIT[1][11] = 0; //initR //control //FX
			//meta2
			Params.FITINIT[2][4] = 0; //initV //fonly //FX
			Params.FITINIT[2][5] = 0.2; //initV  //FX
			Params.FITINIT[2][6] = 0.2; //initV //FX
			Params.FITINIT[2][7] = 0; //initV //control //FX
			//meta3
			Params.FITINIT[3][4] = 0; //initV //f only //FX
			Params.FITINIT[3][5] = 0.2; //initV //FX
			Params.FITINIT[3][6] = 0.2; //initV //FX
			Params.FITINIT[3][7] = 0; //initV //control //FX
			//meta5
			Params.FITINIT[5][8] = 0; //initR

			//************FIT PARAMS*******************
			//S -- pop fit
			Params.FITINIT[1][0] = exp(ltf_params[0]); //initS //send in exponentiated param
			Params.FITINIT[1][1] = exp(ltf_params[0]); //initS 
			Params.FITINIT[1][2] = exp(ltf_params[0]); //initS 
			Params.FITINIT[1][3] = exp(ltf_params[0]); //initS 
			Params.FITINIT[2][0] = exp(ltf_params[0]); //initS  
			Params.FITINIT[2][1] = exp(ltf_params[0]); //initS 
			Params.FITINIT[2][2] = exp(ltf_params[0]); //initS 
			Params.FITINIT[2][3] = exp(ltf_params[0]); //initS 
			Params.FITINIT[3][0] = exp(ltf_params[0]); //initS 
			Params.FITINIT[3][1] = exp(ltf_params[0]); //initS 
			Params.FITINIT[3][2] = exp(ltf_params[0]); //initS 
			Params.FITINIT[3][3] = exp(ltf_params[0]); //initS 

			//INIT R
			//POP
			Params.r_pop = exp(ltf_params[1]);
			//printf("rpop=%lf\n", Params.r_pop);
			//META
			Params.r_meta[1] = exp(ltf_params[2]);;
			Params.r_meta[2] = exp(ltf_params[3]);;
			Params.r_meta[3] = exp(ltf_params[4]);;
			//SUB
			//meta1
			Params.FITINIT[1][8] = exp(ltf_params[5]); //initR
			//printf("initR S")
			//meta2
			Params.FITINIT[2][8] = exp(ltf_params[6]); //initR //fonly 
			Params.FITINIT[2][9] = exp(ltf_params[7]); //initR //vonly 
			Params.FITINIT[2][10] = exp(ltf_params[8]); //initR //fv
			Params.FITINIT[2][11] = exp(ltf_params[9]); //initR //control
			//meta3
			Params.FITINIT[3][8] = exp(ltf_params[10]); //initR //fonly
			Params.FITINIT[3][9] = exp(ltf_params[11]); //initR //vonly
			Params.FITINIT[3][10] = exp(ltf_params[12]); //initR //fv
			Params.FITINIT[3][11] = exp(ltf_params[13]); //initR //control

			//VIRUS //3
			Params.muV			= exp(ltf_params[14]); //Fuller 2012 //virus decay //0.39
			Params.CV			= exp(ltf_params[15]); //hetereogeneity to virus infection //previously 0.86
			Params.nuV    		= exp(ltf_params[16]); //virus transmission
			//FUNGUS //1
			Params.specific_nuF	= exp(ltf_params[17]); //fungus transmission
			//STOCHASTICITY //2
			Params.R_stoch 		= exp(ltf_params[18]);
			Params.F_stoch		= exp(ltf_params[19]);
			//CONIDIA DISPERSAL
			//c_a - pop //1
			Params.c_a_pop = exp(ltf_params[20]);
			//c_a - meta //3
			Params.c_a_meta[1] = exp(ltf_params[21]);
			Params.c_a_meta[2] = exp(ltf_params[22]);
			Params.c_a_meta[3] = exp(ltf_params[23]);
			//c_a - sub //12
			//meta 1
			Params.c_a_sub[1][0] = exp(ltf_params[24]); 
			Params.c_a_sub[1][1] = exp(ltf_params[25]);
			Params.c_a_sub[1][2] = exp(ltf_params[26]);
			Params.c_a_sub[1][3] = exp(ltf_params[27]);
			//meta 2
			Params.c_a_sub[2][0] = exp(ltf_params[28]); 
			Params.c_a_sub[2][1] = exp(ltf_params[29]);
			Params.c_a_sub[2][2] = exp(ltf_params[30]);
			Params.c_a_sub[2][3] = exp(ltf_params[31]);
			//meta 3
			Params.c_a_sub[3][0] = exp(ltf_params[32]); 
			Params.c_a_sub[3][1] = exp(ltf_params[33]);
			Params.c_a_sub[3][2] = exp(ltf_params[34]);
			Params.c_a_sub[3][3] = exp(ltf_params[35]);
			//c_m - pop //1
			Params.c_m_pop		= ltf_params[36]; 
			//c_m - meta //3
			Params.c_m_meta[1]	= ltf_params[37];
			Params.c_m_meta[2]	= ltf_params[38];
			Params.c_m_meta[3]	= ltf_params[39];
			//c_m - sub //12
			//meta1
			Params.c_m_sub[1][0] = ltf_params[40];
			Params.c_m_sub[1][1] = ltf_params[41];
			Params.c_m_sub[1][2] = ltf_params[42];
			Params.c_m_sub[1][3] = ltf_params[43];
			//meta2	
			Params.c_m_sub[2][0] = ltf_params[44];
			Params.c_m_sub[2][1] = ltf_params[45];
			Params.c_m_sub[2][2] = ltf_params[46];
			Params.c_m_sub[2][3] = ltf_params[47];
			//meta3
			Params.c_m_sub[3][0] = ltf_params[48];
			Params.c_m_sub[3][1] = ltf_params[49];
			Params.c_m_sub[3][2] = ltf_params[50];
			Params.c_m_sub[3][3] = ltf_params[51];

			//LARVAL DISPERSAL
			//l_a - pop //1
			Params.l_a_pop = exp(ltf_params[52]);
			//l_a - meta //3
			Params.l_a_meta[1] = exp(ltf_params[53]);
			Params.l_a_meta[2] = exp(ltf_params[54]);
			Params.l_a_meta[3] = exp(ltf_params[55]);
			//l_a - sub //12
			//meta 1
			Params.l_a_sub[1][0] = exp(ltf_params[56]); 
			Params.l_a_sub[1][1] = exp(ltf_params[57]);
			Params.l_a_sub[1][2] = exp(ltf_params[58]);
			Params.l_a_sub[1][3] = exp(ltf_params[59]);
			//meta 2
			Params.l_a_sub[2][0] = exp(ltf_params[60]); 
			Params.l_a_sub[2][1] = exp(ltf_params[61]);
			Params.l_a_sub[2][2] = exp(ltf_params[62]);
			Params.l_a_sub[2][3] = exp(ltf_params[63]);
			//meta 3
			Params.l_a_sub[3][0] = exp(ltf_params[64]); 
			Params.l_a_sub[3][1] = exp(ltf_params[65]);
			Params.l_a_sub[3][2] = exp(ltf_params[66]);
			Params.l_a_sub[3][3] = exp(ltf_params[67]);
			//l_m - pop //1
			Params.l_m_pop		= ltf_params[68]; 
			//l_m - meta //3
			Params.l_m_meta[1]	= ltf_params[69];
			Params.l_m_meta[2]	= ltf_params[70];
			Params.l_m_meta[3]	= ltf_params[71];
			//l_m - sub //12
			//meta1
			Params.l_m_sub[1][0] = ltf_params[72];
			Params.l_m_sub[1][1] = ltf_params[73];
			Params.l_m_sub[1][2] = ltf_params[74];
			Params.l_m_sub[1][3] = ltf_params[75];
			//meta2	
			Params.l_m_sub[2][0] = ltf_params[76];
			Params.l_m_sub[2][1] = ltf_params[77];
			Params.l_m_sub[2][2] = ltf_params[78];
			Params.l_m_sub[2][3] = ltf_params[79];
			//meta3
			Params.l_m_sub[3][0] = ltf_params[80];
			Params.l_m_sub[3][1] = ltf_params[81];
			Params.l_m_sub[3][2] = ltf_params[82];
			Params.l_m_sub[3][3] = ltf_params[83];
			//OBS INIT CONDITIONS //8
			//meta4
			Params.FITINIT[4][0] = exp(ltf_params[84]); //initS
			Params.FITINIT[4][4] = exp(ltf_params[85]); //initV
			Params.FITINIT[4][8] = exp(ltf_params[86]); //initR
			//meta5
			Params.FITINIT[5][0] = exp(ltf_params[87]); //initS
			Params.FITINIT[5][4] = exp(ltf_params[88]); //initV
			//meta6
			Params.FITINIT[6][0] = exp(ltf_params[89]); //initS
			Params.FITINIT[6][4] = exp(ltf_params[90]); //initV
			Params.FITINIT[6][8] = exp(ltf_params[91]); //initR

			//getc(stdin);

				//-------------------MISER CALCULATE LIKELIHOOD------------------------------//
			double lhood_meta=0; double log_lhood_meta=0; total_loghood_metas = 0;
			double new_posterior=0;
			double meta_err=0;
			double lhood_total=0;
			double lhood_reps=0;

			for(int j=1; j<=3; j++){
				Params.j = j;

				Params.miser_ticker = 1; Params.miser2_flag = 0; 

				gsl_monte_function G = { &likelihood_calc, dim, &Params };	// declares function calling lhood_meta.h
				double xl[dim];	double xu[dim];	// need to redeclare xl and xu since the size changes
				for (int jj=0;jj<dim;jj++)	{
					xl[jj]=0;	
					xu[jj]=1;
				}

				gsl_monte_miser_state *s = gsl_monte_miser_alloc(dim);
				gsl_monte_miser_integrate (&G,xl,xu,dim,LScalls,r_seed,s,&lhood_meta,&meta_err); //call MISER, pop_lhood is output from .h (likelihood value)
				gsl_monte_miser_free(s);
				
				while(Params.miser2_flag > 0){ //indicates that a better likelihood score (or a few) were found
					Params.miser2_flag = 0;
					Params.lhood_adjust[j] = -Params.bestlhood[j];
					
					gsl_monte_miser_state *s = gsl_monte_miser_alloc(dim);
					gsl_monte_miser_integrate (&G,xl,xu,dim,LScalls,r_seed,s,&lhood_meta,&meta_err); //call MISER, pop_lhood is output from .h (likelihood value)
					gsl_monte_miser_free(s);
				}

				log_lhood_meta = log(lhood_meta) - Params.lhood_adjust[j];
				//printf("loglhood .c = %lf\n", log_lhood_meta);

				if(isnan(log_lhood_meta) || isinf(log_lhood_meta)){ //can't be in lhoodcalc bc it messes with the adjustment
					log_lhood_meta = -999999999999;
				}
				
				total_loghood_metas = total_loghood_metas + log_lhood_meta;

				new_posterior = total_loghood_metas + log_prior;
			}
			//printf("new posterior = %lf\t best posterior = %lf\n", new_posterior, best_posterior);
			if (new_posterior>best_posterior){ //compare likelihood //sum - one you just generated //local max - best you've seen
				best_posterior=new_posterior;
				for (c=0;c<num_ltfparams;c++){
					localmax_params[c]=ltf_params[c]; //save best param set from each individual search
				}
			}
		}  //best param set from within searches
		for (c=0;c<num_ltfparams;c++){
			ltf_params[c]=localmax_params[c];
		}
		i++;
		}
	} 
	int index;
	//printf("printing!\n");
	for(int ii=0; ii<num_ltfparams; ii++){
		if(fit[ii]==1){
			//printf("fitting param # = %i\n", ii);
			if(log_fit[ii]==1){
				fprintf(fpls, "%5.3f ", ltf_params[ii]); //print in log scale, can modify in R plotting
				printf("%5.3f ", ltf_params[ii]);
			}
			else if (log_fit[ii]==0){
				fprintf(fpls, "%5.3f ", ltf_params[ii]); //print in non-log scale
				printf("%5.3f ", ltf_params[ii]);
			}
		}
	}
	fprintf(fpls, "%4.3e ", total_loghood_metas);
	printf("%4.3e ", total_loghood_metas);
	fprintf(fpls, "%4.3e ", best_posterior);
	printf("%4.3e ", best_posterior);
	fprintf(fpls, "\n");
	printf("\n");
	//getc(stdin);

}

//fclose(fpl);
fclose(fpls); //parameter values
}
///////////////////////////////////////////////////REALIZATIONS///////////////////////////////////////////////////

if(reals==1){

	char name1[50];
	sprintf(name1, "REALS_c%i_m%i", Rcalls,  model );
	fpr=fopen(name1, "a+");

	char nameme[50];
	sprintf(nameme, "meta_err_m%i", Params.model );
	fpme=fopen(nameme, "a+");

	//********FIXED PARAMS***********
		//INITIAL CONDITIONS
		//meta1
		Params.FITINIT[1][4] = 0; //initV //fonly //FX
		Params.FITINIT[1][5] = 0.2; //initV  //FX
		Params.FITINIT[1][6] = 0.2; //initV //FX
		Params.FITINIT[1][7] = 0; //initV //control //FX
		Params.FITINIT[1][9] = 0; //initR //vonly  //FX
		Params.FITINIT[1][10] = 0; //initR //fv //FX
		Params.FITINIT[1][11] = 0; //initR //control //FX
		//meta2
		Params.FITINIT[2][4] = 0; //initV //fonly //FX
		Params.FITINIT[2][5] = 0.2; //initV  //FX
		Params.FITINIT[2][6] = 0.2; //initV //FX
		Params.FITINIT[2][7] = 0; //initV //control //FX
		//meta3
		Params.FITINIT[3][4] = 0; //initV //f only //FX
		Params.FITINIT[3][5] = 0.2; //initV //FX
		Params.FITINIT[3][6] = 0.2; //initV //FX
		Params.FITINIT[3][7] = 0; //initV //control //FX
		//meta5
		Params.FITINIT[5][8] = 0; //initR

		//************FIT PARAMS*******************
		//S -- pop fit
		double INITS = 2.275638;
		Params.FITINIT[1][0] = INITS; //initS 
		Params.FITINIT[1][1] = INITS; //initS 
		Params.FITINIT[1][2] = INITS; //initS 
		Params.FITINIT[1][3] = INITS; //initS 
		Params.FITINIT[2][0] = INITS; //initS  
		Params.FITINIT[2][1] = INITS; //initS 
		Params.FITINIT[2][2] = INITS; //initS 
		Params.FITINIT[2][3] = INITS; //initS 
		Params.FITINIT[3][0] = INITS; //initS 
		Params.FITINIT[3][1] = INITS; //initS 
		Params.FITINIT[3][2] = INITS; //initS 
		Params.FITINIT[3][3] = INITS; //initS 

		//INIT R
		//POP
		Params.r_pop = exp(ltf_params[1]);
		//META
		Params.r_meta[1] = exp(ltf_params[2]);;
		Params.r_meta[2] = exp(ltf_params[3]);;
		Params.r_meta[3] = exp(ltf_params[4]);;
		//SUB
		//meta1
		Params.FITINIT[1][8] = 7.8e-05; //initR
		//meta2
		Params.FITINIT[2][8] = 0.009483; //initR //fonly 
		Params.FITINIT[2][9] = 0.000232; //initR //vonly 
		Params.FITINIT[2][10] = 0.008484; //initR //fv
		Params.FITINIT[2][11] = 0.003019; //initR //control
		//meta3
		Params.FITINIT[3][8] = 0.015967; //initR //fonly
		Params.FITINIT[3][9] = 0.001740; //initR //vonly
		Params.FITINIT[3][10] = 0.008910; //initR //fv
		Params.FITINIT[3][11] = 0.003761; //initR //control

		//VIRUS //3
		Params.muV 			= 5.767914; //Fuller 2012 //virus decay //0.39
		Params.CV			= 0.325657;  //hetereogeneity to virus infection //previously 0.86
		Params.nuV			= 6.304857; //virus transmission

		//FUNGUS //1
		Params.specific_nuF	= 2e-06; //fungus transmission

		//STOCHASTICITY //2
		Params.R_stoch 		= 0.596874;
		Params.F_stoch		= 0.146241;

		//CONIDIA DISPERSAL
		//c_a - pop //1
		Params.c_a_pop = 	216076.2;
		//c_a - meta //3
		Params.c_a_meta[1] = exp(ltf_params[21]);
		Params.c_a_meta[2] = exp(ltf_params[22]);
		Params.c_a_meta[3] = exp(ltf_params[23]);
		//c_a - sub //12
		//meta 1
		Params.c_a_sub[1][0] = exp(ltf_params[24]); 
		Params.c_a_sub[1][1] = exp(ltf_params[25]);
		Params.c_a_sub[1][2] = exp(ltf_params[26]);
		Params.c_a_sub[1][3] = exp(ltf_params[27]);
		//meta 2
		Params.c_a_sub[2][0] = exp(ltf_params[28]); 
		Params.c_a_sub[2][1] = exp(ltf_params[29]);
		Params.c_a_sub[2][2] = exp(ltf_params[30]);
		Params.c_a_sub[2][3] = exp(ltf_params[31]);
		//meta 3
		Params.c_a_sub[3][0] = exp(ltf_params[32]); 
		Params.c_a_sub[3][1] = exp(ltf_params[33]);
		Params.c_a_sub[3][2] = exp(ltf_params[34]);
		Params.c_a_sub[3][3] = exp(ltf_params[35]);
		//c_m - pop //1
		Params.c_m_pop		= 0.160793;
		//c_m - meta //3
		Params.c_m_meta[1]	= exp(ltf_params[37]);
		Params.c_m_meta[2]	= exp(ltf_params[38]);
		Params.c_m_meta[3]	= exp(ltf_params[39]);
		//c_m - sub //12
		//meta1
		Params.c_m_sub[1][0] = exp(ltf_params[40]);
		Params.c_m_sub[1][1] = exp(ltf_params[41]);
		Params.c_m_sub[1][2] = exp(ltf_params[42]);
		Params.c_m_sub[1][3] = exp(ltf_params[43]);
		//meta2	
		Params.c_m_sub[2][0] = exp(ltf_params[44]);
		Params.c_m_sub[2][1] = exp(ltf_params[45]);
		Params.c_m_sub[2][2] = exp(ltf_params[46]);
		Params.c_m_sub[2][3] = exp(ltf_params[47]);
		//meta3
		Params.c_m_sub[3][0] = exp(ltf_params[48]);
		Params.c_m_sub[3][1] = exp(ltf_params[49]);
		Params.c_m_sub[3][2] = exp(ltf_params[50]);
		Params.c_m_sub[3][3] = exp(ltf_params[51]);

		//LARVAL DISPERSAL
		//l_a - pop //1
		Params.l_a_pop = 0.164315;
		//l_a - meta //3
		Params.l_a_meta[1] = exp(ltf_params[53]);
		Params.l_a_meta[2] = exp(ltf_params[54]);
		Params.l_a_meta[3] = exp(ltf_params[55]);
		//l_a - sub //12
		//meta 1
		Params.l_a_sub[1][0] = exp(ltf_params[56]); 
		Params.l_a_sub[1][1] = exp(ltf_params[57]);
		Params.l_a_sub[1][2] = exp(ltf_params[58]);
		Params.l_a_sub[1][3] = exp(ltf_params[59]);
		//meta 2
		Params.l_a_sub[2][0] = exp(ltf_params[60]); 
		Params.l_a_sub[2][1] = exp(ltf_params[61]);
		Params.l_a_sub[2][2] = exp(ltf_params[62]);
		Params.l_a_sub[2][3] = exp(ltf_params[63]);
		//meta 3
		Params.l_a_sub[3][0] = exp(ltf_params[64]); 
		Params.l_a_sub[3][1] = exp(ltf_params[65]);
		Params.l_a_sub[3][2] = exp(ltf_params[66]);
		Params.l_a_sub[3][3] = exp(ltf_params[67]);
		//l_m - pop //1
		Params.l_m_pop		= 0.264100; 
		//l_m - meta //3
		Params.l_m_meta[1]	= exp(ltf_params[69]);
		Params.l_m_meta[2]	= exp(ltf_params[70]);
		Params.l_m_meta[3]	= exp(ltf_params[71]);
		//l_m - sub //12
		//meta1
		Params.l_m_sub[1][0] = exp(ltf_params[72]);
		Params.l_m_sub[1][1] = exp(ltf_params[73]);
		Params.l_m_sub[1][2] = exp(ltf_params[74]);
		Params.l_m_sub[1][3] = exp(ltf_params[75]);
		//meta2	
		Params.l_m_sub[2][0] = exp(ltf_params[76]);
		Params.l_m_sub[2][1] = exp(ltf_params[77]);
		Params.l_m_sub[2][2] = exp(ltf_params[78]);
		Params.l_m_sub[2][3] = exp(ltf_params[79]);
		//meta3
		Params.l_m_sub[3][0] = exp(ltf_params[80]);
		Params.l_m_sub[3][1] = exp(ltf_params[81]);
		Params.l_m_sub[3][2] = exp(ltf_params[82]);
		Params.l_m_sub[3][3] = exp(ltf_params[83]);

		//OBS INIT CONDITIONS //8
		//meta4
		Params.FITINIT[4][0] = 8.816404; //initS
		Params.FITINIT[4][4] = 0.078705; //initV
		Params.FITINIT[4][8] = 0.000884; //initR
		//meta5
		Params.FITINIT[5][0] = 4.310543; //initS
		Params.FITINIT[5][4] = 0.138899; //initV
		//meta6
		Params.FITINIT[6][0] = 6.254701; //initS
		Params.FITINIT[6][4] = 0.003656; //initV
		Params.FITINIT[6][8] = 0.003448; //initR

	//start realizations. In this case, calls = # realizations
	double lhood_meta=0; double log_lhood_meta=0; double total_loghood_metas = 0;
	double new_posterior=0;
	double meta_err=0;
	double lhood_total=0;
	double lhood_reps=0;

	for(int j=1; j<=3; j++){
	//for(int j=4; j<=6; j++){
		Params.j = j;

		Params.miser_ticker = 1; Params.miser2_flag = 0;

		gsl_monte_function G = { &likelihood_calc, dim, &Params };	// declares function calling lhood_meta.h
		double xl[dim];	double xu[dim];	// need to redeclare xl and xu since the size changes
		for (int jj=0;jj<dim;jj++)	{
			xl[jj]=0;	
			xu[jj]=1;
		}

		gsl_monte_miser_state *s = gsl_monte_miser_alloc(dim);
		gsl_monte_miser_integrate (&G,xl,xu,dim,Rcalls,r_seed,s,&lhood_meta,&meta_err); //call MISER, pop_lhood is output from .h (likelihood value)
		gsl_monte_miser_free(s);

		log_lhood_meta = log(lhood_meta) - Params.lhood_adjust[j];
		if(isnan(log_lhood_meta) || isinf(log_lhood_meta)){
			log_lhood_meta = -99999999; //very bad score
		}
		
		total_loghood_metas = total_loghood_metas + log_lhood_meta;

		new_posterior = total_loghood_metas; //NOT INCLUDING PRIOR //THAT IS A PROBLEM, FIGURE OUT HOW TO DEAL WITH IT LATER
	}
	//}
	fclose(fpr); 
	fclose(fpme);

}
//----------------------------------------------------Print Output to File-----------------------------

if(mcmc==1){
	//CUSTOMIZATIONS	
	//1. change PCA .txt names
	//2. implement skip fit and log fit here

	//FITTING ROUTINE
	int NumberOfParams = NumFitParams(model);    
	//printf("numfitparams = %i\n", NumberOfParams);

	//FILE OUTPUT
	int pid;
	pid=getpid();

	char namem[50];
	sprintf(namem, "mcmc_results_%i_model%i", pid, model);
	fpm=fopen(namem, "a+");

	//RANDOM NUMBER
	const gsl_rng_type * T;

	gsl_rng * r;
	gsl_rng_env_setup();
	T = gsl_rng_default;
	r = gsl_rng_alloc (T);
	gsl_rng_set(r, time(NULL)*(int)getpid());     //JL: Include the process id to avoid taking the same random number at the beginning stage (multiple jobs submitted together at the same time).
	srand(time(NULL));

	//SET-UP
	double delta=0;

	double RandomNumber;

	double LogJumpToNew;
	double LogJumpToOld;
	double ProbOfAcceptance;

	double LogOldPosterior;
	double LogNewPosterior;
	double LogNewPrior;

	int run; //CHECK maybe don't need
	int changer; //CHECK maybe don't need
	
	double pop_lhood, pop_lhood2, pop_err,post_hood;	// population lhood (and posterior lhood) calculated for each initS and initR
	double pop_best_lhood;					// likelihood and error for best initS and initR
	double best_post_hood;	double best_lhood=0;		// best post_hood and lhood
	//ouble prior[num_ltfparams]; //

	//Arrays
	double SDpca[NumberOfParams];
	double Coefficients[NumberOfParams*NumberOfParams];
	double Center[NumberOfParams];
	double Scale[NumberOfParams];
	double PC[NumberOfParams];
	double Old_PC[NumberOfParams];
	double Holder[NumberOfParams];
	double PCAparams[NumberOfParams];
	double Old_Params[NumberOfParams];

	int a;
	int b;
	int ticker;
	int ticker2;

	int Case;

	int Accepted=0;
	signed int LoopNumber=-1;

	int ParCnt2 = NumberOfParams;

	double SigmaInflation=1;

	double sigma[NumberOfParams];

	run=1;	changer=1;	best_post_hood=-1000000000000;


//---------------------------------Read in PCA-----------------------------------//

	FILE *file;

	file=fopen("PCAsd2_21.txt", "r");          //Reading in the standard deviations of PCA.
	for (a=0; a<(NumberOfParams); a++)
	{
		fscanf(file, "%lf\n", &SDpca[a]);
		//printf("%i\t %lf\n", a, SDpca[a]);
	}
	fclose(file);


	file=fopen("PCArotations2_21.txt", "r");   //Reading in the rotations (coefficients between PC's and parameters)
	for (a=0; a<(NumberOfParams*NumberOfParams); a++)
	{
		fscanf(file, "%lf\n", &Coefficients[a]);
		//printf("%i\t %lf\n", a, Coefficients[a]);
	}
	fclose(file);

	file=fopen("PCAscale2_21.txt", "r");        //Reading in the scales to reconstruct parameter values from PC's.
	for (a=0; a<NumberOfParams; a++)
	{
		fscanf(file, "%lf\n", &Scale[a]);
		//printf("%i\t %lf\n", a, Scale[a]);
	}
	fclose(file);

	file=fopen("PCAcenter2_21.txt", "r");       //Reading in the centers of parameters. Used in the reconstruction of parameters.

	for (a=0; a<NumberOfParams; a++)
	{
		fscanf(file, "%lf\n", &Center[a]);
		//printf("%i\t %lf\n", a, Center[a]);
	}
	fclose(file);

//-------------------------generate initial PCs---------------------//
//start out by inflating variance to make overdispersed, then see if var goes down with time.
		//as variance goes down, that's evidence that chains are converging
	for(a=0; a<NumberOfParams; a++){
		sigma[a]=SigmaInflation*SDpca[a]; //not converted out of log space?? all others are
		//printf("%lf\n", sigma[a]);
	}

	for (a=0; a<NumberOfParams; a++){ 
		PC[a]=gsl_ran_gaussian (r, sigma[a]);    
		//printf("%lf\n", PC[a]);
	}

//----------------------Reconstruct initial parameter set and check if in bounds-------------------// TEST
	int PCA_ticker=0;
	while(PCA_ticker==0){

		for (a=0; a<NumberOfParams; a++){ //generate new PC
			PC[a]=gsl_ran_gaussian (r, sigma[a]);    
		//printf("%lf\n", PC[a]);
		}
		//reconstruct parms
		for (a=0;a<NumberOfParams; a++)	{							//Back transform PC's into model parameters
			for (b=0; b<NumberOfParams; b++){
				Holder[b]=Coefficients[a*NumberOfParams+b];         //Store the coefficients between a certain parameter and all the PC's
			}
			PCAparams[a]=exp(DotProduct(ParCnt2, Holder, PC)*Scale[a]+Center[a]);            //Reconstruct the parameter value after tweaking one PC
			//printf("first set of params generated\n");
		}

		//check params
		PCA_ticker=1;
		for (a=0;a<NumberOfParams; a++)	{
			//printf("in loop a = %i\n", a);
			if(PCAparams[a] < prior_bound_mcmc(model,a,1) || PCAparams[a] > prior_bound_mcmc(model,a,2)){ //if out of bounds...
				PCA_ticker=0;
				printf("out of bounds initial PC proposal for param %i\n", a);
				printf("value = %lf\t lower bound = %lf\t upper bound = %lf\n", PCAparams[a],prior_bound_mcmc(model, a,1),prior_bound_mcmc(model, a,2));	
			}
			else{}
		}
		//printf("stuck in loop PCA param ticker = %i\n", PCA_ticker);
	}
	printf("initial parameter set successful\n");


//------------------------begin loop---------------------------------//
while (LoopNumber<=Realizations) {     
		//printf("loop number = %i\n", LoopNumber);
		LoopNumber=LoopNumber+1;

		Case=LoopNumber%NumberOfParams;					//Determines which PC to change
		//printf("CASE = %i\n");
		//printf("numbrparams=%i\n", NumberOfParams);
		for (a=0; a<NumberOfParams; a++){
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
		//CHECK IF PARAM IS IN BOUNDS
		while(PCAparams[Case] < prior_bound_mcmc(model,Case,1) || PCAparams[Case] > prior_bound_mcmc(model,Case,2)){ //try 5 new ones then just move on.
			//printf("BOUND ERROR param %i not in bounds\n", Case);
			//printf("value = %lf\t lower bound = %lf\t upper bound = %lf\n",PCAparams[Case],prior_bound_mcmc(model, Case,1),prior_bound_mcmc(model, Case,2));
			//draw a new value for that PC
			PC[Case]=gsl_ran_gaussian (r, sigma[Case]);
			//and reconstruct
			PCAparams[Case]=exp(DotProduct(ParCnt2, Holder, PC)*Scale[Case]+Center[Case]); 
		}
		//printf("FIXED param %i within bounds\n", Case);
		//printf("value = %lf\t lower bound = %lf\t upper bound = %lf\n",PCAparams[Case],prior_bound_mcmc(model, Case,1),prior_bound_mcmc(model, Case,2));
		
		//---------------------- Fix initial parameters ------------------------//
		/*
		if(Accepted==0){
			if(model==21){
				Old_Params[0]=exp(0.600000);
				Old_Params[1]=exp(-9.500000);
				Old_Params[2]=exp(-3.573817);
				Old_Params[3]=exp(-8.874833);
				Old_Params[4]=exp(-3.588437);
				Old_Params[5]=exp(-7.649000);
				Old_Params[6]=exp(-3.219981);
				Old_Params[7]=exp(-7.042000);
				Old_Params[8]=exp(-3.153335);
				Old_Params[9]=exp(-6.808860);
				Old_Params[10]=exp(1.238322);
				Old_Params[11]=exp(-4.370000);
				Old_Params[12]=exp(0.604556);
				Old_Params[13]=exp(-12.796250);
				Old_Params[14]=exp(-0.653609);
				Old_Params[15]=exp(-6.100000);
				Old_Params[16]=exp(12.42679);
				Old_Params[17]=0.571717;
				Old_Params[18]=exp(-1.666667);
				Old_Params[19]=0.280893;
				printf("fixed init params set\n");
			}
		}*/
		//---------------------- Priors ------------------------//
		double log_prior_Old=0;
		double log_prior_New=0;
		for (a=0;a<NumberOfParams; a++){
			log_prior_Old = log(gsl_ran_flat_pdf(PCAparams[a], prior_bound_mcmc(model, a,1), (prior_bound_mcmc(model, a,2)+prior_bound_mcmc(model, a,1))));
			log_prior_New = log(gsl_ran_flat_pdf(Old_Params[a], prior_bound_mcmc(model, a,1), (prior_bound_mcmc(model, a,2)+prior_bound_mcmc(model, a,1))));
			if(isinf(log_prior_New)){ //outside of bounds, set bad score
					//printf("PROBLEM WITH PRIORS NEW\n");
					//printf("k=%i\t new log prior = %lf\n", a, log_prior_New);
					log_prior_New = -99999999;
				}
			if(isinf(log_prior_Old)){
				//printf("PROBLEM WITH PRIORS OLD\n");
				//printf("k=%i\t old log prior = %lf\n", a, log_prior_Old);
				log_prior_New = -99999999;
			}
			log_prior_Old += log_prior_Old;
			log_prior_New += log_prior_New;
		}
		//printf("log_prior_old = %e\n", log_prior_Old);
		//printf("log_prior_new = %e\n", log_prior_New);

		//-------------------- Metropolis sampling step ------------//
		LogJumpToNew= -log(gsl_ran_gaussian_pdf(PC[Case], sigma[Case])); //LATER YOU WILL USE THIS TO CORRECT FOR PROPOSAL
		LogJumpToOld= -log(gsl_ran_gaussian_pdf(Old_PC[Case], sigma[Case]));
		
		//-------------------MISER likelihood NEW------------------------------//
		//fixed parms
			Params.FITINIT[1][4] = 0; //initV //fonly //FX
			Params.FITINIT[1][5] = 0.2; //initV  //FX
			Params.FITINIT[1][6] = 0.2; //initV //FX
			Params.FITINIT[1][7] = 0; //initV //control //FX
			Params.FITINIT[1][9] = 0; //initR //vonly  //FX
			Params.FITINIT[1][10] = 0; //initR //fv //FX
			Params.FITINIT[1][11] = 0; //initR //control //FX
			//meta2
			Params.FITINIT[2][4] = 0; //initV //fonly //FX
			Params.FITINIT[2][5] = 0.2; //initV  //FX
			Params.FITINIT[2][6] = 0.2; //initV //FX
			Params.FITINIT[2][7] = 0; //initV //control //FX
			//meta3
			Params.FITINIT[3][4] = 0; //initV //f only //FX
			Params.FITINIT[3][5] = 0.2; //initV //FX
			Params.FITINIT[3][6] = 0.2; //initV //FX
			Params.FITINIT[3][7] = 0; //initV //control //FX
			//meta5
			Params.FITINIT[5][8] = 0; //initR

		if(model==21){
			//---assign new parameter values---//
			
			Params.FITINIT[1][0] = PCAparams[0];
			Params.FITINIT[1][1] = PCAparams[0];
			Params.FITINIT[1][2] = PCAparams[0]; 
			Params.FITINIT[1][3] = PCAparams[0]; 
			Params.FITINIT[2][0] = PCAparams[0]; 
			Params.FITINIT[2][1] = PCAparams[0];
			Params.FITINIT[2][2] = PCAparams[0];
			Params.FITINIT[2][3] = PCAparams[0];
			Params.FITINIT[3][0] = PCAparams[0]; 
			Params.FITINIT[3][1] = PCAparams[0]; 
			Params.FITINIT[3][2] = PCAparams[0];
			Params.FITINIT[3][3] = PCAparams[0];
			//meta1
			Params.FITINIT[1][8] = PCAparams[1];
			//meta2
			Params.FITINIT[2][8] = PCAparams[2];
			Params.FITINIT[2][9] = PCAparams[3]; 
			Params.FITINIT[2][10] = PCAparams[4];
			Params.FITINIT[2][11] = PCAparams[5];
			//meta1
			Params.FITINIT[3][8] = PCAparams[6];
			Params.FITINIT[3][9] = PCAparams[7];
			Params.FITINIT[3][10] = PCAparams[8];
			Params.FITINIT[3][11] = PCAparams[9];
			//CORE SET
			Params.muV			= PCAparams[10]; //virus decay
			Params.CV			= PCAparams[11]; //hetereogeneity to virus infection 
			Params.nuV    		= PCAparams[12]; //virus transmission
			Params.specific_nuF	= PCAparams[13]; //fungus transmissison
			Params.R_stoch 		= PCAparams[14];
			Params.F_stoch		= PCAparams[15];
			//dispersal
			Params.c_a_pop = PCAparams[16];
			Params.c_m_pop = PCAparams[17];
			Params.l_a_pop = PCAparams[18];
			Params.l_m_pop = PCAparams[19];
		}

		double lhood_meta=0; double log_lhood_meta=0; double total_loghood_metas = 0;
		double new_posterior=0;
		double meta_err=0;
		double lhood_total=0;
		double lhood_reps=0;	

		for(int j=1; j<=3; j++){ 

			Params.miser_ticker = 1; Params.miser2_flag = 0; 
			
			Params.j = j;

			gsl_monte_function G = { &likelihood_calc, dim, &Params };	// declares function calling lhood_meta.h
			double xl[dim];	double xu[dim];	// need to redeclare xl and xu since the size changes
			for (int jj=0;jj<dim;jj++)	{
				xl[jj]=0;	
				xu[jj]=1;
			}

			gsl_monte_miser_state *s = gsl_monte_miser_alloc(dim);
			gsl_monte_miser_integrate (&G,xl,xu,dim,Mcalls,r_seed,s,&lhood_meta,&meta_err); //call MISER, pop_lhood is output from .h (likelihood value)
			gsl_monte_miser_free(s);
			
			while(Params.miser2_flag > 0){ //indicates that a better likelihood score (or a few) were found
				Params.miser2_flag = 0;
				Params.lhood_adjust[j] = -Params.bestlhood[j];
				
				gsl_monte_miser_state *s = gsl_monte_miser_alloc(dim);
				gsl_monte_miser_integrate (&G,xl,xu,dim,Mcalls,r_seed,s,&lhood_meta,&meta_err); //call MISER, pop_lhood is output from .h (likelihood value)
				gsl_monte_miser_free(s);
			}
			
			log_lhood_meta = log(lhood_meta) - Params.lhood_adjust[j];
			if(isnan(log_lhood_meta) || isinf(log_lhood_meta)){ 
				log_lhood_meta = -99999999;
			}
			//printf("loglhoodmeta new = %lf\n", log_lhood_meta);
			total_loghood_metas = total_loghood_metas + log_lhood_meta;
			LogNewPosterior = 0.0;
			LogNewPosterior = total_loghood_metas + log_prior_New;
			//printf("log new posterior = %lf\n", LogNewPosterior);
			//printf("log new prior = %lf\n", log_prior_New);
		}//j
		
		if(LoopNumber==1){ //Initial calcualtion to get the ball rolling on likelihood comparison
			//fixed parms
			Params.FITINIT[1][4] = 0; //initV //fonly //FX
			Params.FITINIT[1][5] = 0.2; //initV  //FX
			Params.FITINIT[1][6] = 0.2; //initV //FX
			Params.FITINIT[1][7] = 0; //initV //control //FX
			Params.FITINIT[1][9] = 0; //initR //vonly  //FX
			Params.FITINIT[1][10] = 0; //initR //fv //FX
			Params.FITINIT[1][11] = 0; //initR //control //FX
			//meta2
			Params.FITINIT[2][4] = 0; //initV //fonly //FX
			Params.FITINIT[2][5] = 0.2; //initV  //FX
			Params.FITINIT[2][6] = 0.2; //initV //FX
			Params.FITINIT[2][7] = 0; //initV //control //FX
			//meta3
			Params.FITINIT[3][4] = 0; //initV //f only //FX
			Params.FITINIT[3][5] = 0.2; //initV //FX
			Params.FITINIT[3][6] = 0.2; //initV //FX
			Params.FITINIT[3][7] = 0; //initV //control //FX
			//meta5
			Params.FITINIT[5][8] = 0; //initR
			//-------------------MISER likelihood OLD------------------------------//
			if(model==21){ //start in known good parameter space from line search
				//---assign old parameter vaues---//
				Params.FITINIT[1][0] = Old_Params[0];
				Params.FITINIT[1][1] = Old_Params[0];
				Params.FITINIT[1][2] = Old_Params[0]; 
				Params.FITINIT[1][3] = Old_Params[0]; 
				Params.FITINIT[2][0] = Old_Params[0]; 
				Params.FITINIT[2][1] = Old_Params[0];
				Params.FITINIT[2][2] = Old_Params[0];
				Params.FITINIT[2][3] = Old_Params[0];
				Params.FITINIT[3][0] = Old_Params[0]; 
				Params.FITINIT[3][1] = Old_Params[0]; 
				Params.FITINIT[3][2] = Old_Params[0];
				Params.FITINIT[3][3] = Old_Params[0];
				//meta1
				Params.FITINIT[1][8] = Old_Params[1];
				//meta2
				Params.FITINIT[2][8] = Old_Params[2];
				Params.FITINIT[2][9] = Old_Params[3]; 
				Params.FITINIT[2][10] = Old_Params[4];
				Params.FITINIT[2][11] = Old_Params[5];
				//meta1
				Params.FITINIT[3][8] = Old_Params[6];
				Params.FITINIT[3][9] = Old_Params[7];
				Params.FITINIT[3][10] = Old_Params[8];
				Params.FITINIT[3][11] = Old_Params[9];
				//CORE SET
				Params.muV			= Old_Params[10]; //virus decay
				Params.CV			= Old_Params[11];//hetereogeneity to virus infection 
				Params.nuV    		= Old_Params[12]; //virus transmission
				Params.specific_nuF	= Old_Params[13]; //fungus transmissison
				Params.R_stoch 		= Old_Params[14];
				Params.F_stoch		= Old_Params[15];
				//dispersal
				Params.c_a_pop = Old_Params[16];
				Params.c_m_pop = Old_Params[17];
				//printf("c m pop =%lf\n", Old_Params[17]);
				Params.l_a_pop = Old_Params[18];
				Params.l_a_pop = Old_Params[19];
			}

			lhood_meta=0; log_lhood_meta=0; total_loghood_metas = 0;
			new_posterior=0;
			meta_err=0;
			lhood_total=0;
			lhood_reps=0;

			for(int j=1; j<=3; j++){

				Params.miser_ticker = 1; Params.miser2_flag = 0; 
				
				Params.j = j;

				gsl_monte_function G = { &likelihood_calc, dim, &Params };	// declares function calling lhood_meta.h
				double xl[dim];	double xu[dim];	// need to redeclare xl and xu since the size changes
				for (int jj=0;jj<dim;jj++)	{
					xl[jj]=0;	
					xu[jj]=1;
				}

				gsl_monte_miser_state *s = gsl_monte_miser_alloc(dim);
				gsl_monte_miser_integrate (&G,xl,xu,dim,Mcalls,r_seed,s,&lhood_meta,&meta_err); //call MISER, pop_lhood is output from .h (likelihood value)
				gsl_monte_miser_free(s);
				
				while(Params.miser2_flag > 0){ //indicates that a better likelihood score (or a few) were found
					Params.miser2_flag = 0;
					Params.lhood_adjust[j] = -Params.bestlhood[j];
					
					gsl_monte_miser_state *s = gsl_monte_miser_alloc(dim);
					gsl_monte_miser_integrate (&G,xl,xu,dim,Mcalls,r_seed,s,&lhood_meta,&meta_err); //call MISER, pop_lhood is output from .h (likelihood value)
					gsl_monte_miser_free(s);
				}
				
				log_lhood_meta = log(lhood_meta) - Params.lhood_adjust[j];
				if(isnan(log_lhood_meta) || isinf(log_lhood_meta)){ //change to zero of inf or nan, only update lhood adj if not
					log_lhood_meta = -99999999;
				}
				//printf("log_lhood_meta=%lf", log_lhood_meta);
				total_loghood_metas = total_loghood_metas + log_lhood_meta;
				LogOldPosterior = 0.0;
				LogOldPosterior = total_loghood_metas + log_prior_Old;
				//printf("logold posterior = %lf\n", LogOldPosterior);
				//printf("log old prior = %lf\n", log_prior_Old);
			}//j

		}

		//----------compare new parm set with old parm set----------------
		
		ProbOfAcceptance=exp(LogNewPosterior+LogJumpToOld - LogOldPosterior-LogJumpToNew);    //Probability of accepting the new PC

		Params.LoopVect[Case] = Params.LoopVect[Case] + 1;

		if (ProbOfAcceptance>1 || gsl_rng_uniform_pos (r) < ProbOfAcceptance){   //ACCEPT PASS 1
			//-------------------MISER likelihood OLD------------------------------//
			//fixed parms
			Params.FITINIT[1][4] = 0; //initV //fonly //FX
			Params.FITINIT[1][5] = 0.2; //initV  //FX
			Params.FITINIT[1][6] = 0.2; //initV //FX
			Params.FITINIT[1][7] = 0; //initV //control //FX
			Params.FITINIT[1][9] = 0; //initR //vonly  //FX
			Params.FITINIT[1][10] = 0; //initR //fv //FX
			Params.FITINIT[1][11] = 0; //initR //control //FX
			//meta2
			Params.FITINIT[2][4] = 0; //initV //fonly //FX
			Params.FITINIT[2][5] = 0.2; //initV  //FX
			Params.FITINIT[2][6] = 0.2; //initV //FX
			Params.FITINIT[2][7] = 0; //initV //control //FX
			//meta3
			Params.FITINIT[3][4] = 0; //initV //f only //FX
			Params.FITINIT[3][5] = 0.2; //initV //FX
			Params.FITINIT[3][6] = 0.2; //initV //FX
			Params.FITINIT[3][7] = 0; //initV //control //FX
			//meta5
			Params.FITINIT[5][8] = 0; //initR

			if(model==21){
				//---assign old parameter vaues---//
				Params.FITINIT[1][0] = Old_Params[0];
				Params.FITINIT[1][1] = Old_Params[0];
				Params.FITINIT[1][2] = Old_Params[0]; 
				Params.FITINIT[1][3] = Old_Params[0]; 
				Params.FITINIT[2][0] = Old_Params[0]; 
				Params.FITINIT[2][1] = Old_Params[0];
				Params.FITINIT[2][2] = Old_Params[0];
				Params.FITINIT[2][3] = Old_Params[0];
				Params.FITINIT[3][0] = Old_Params[0]; 
				Params.FITINIT[3][1] = Old_Params[0]; 
				Params.FITINIT[3][2] = Old_Params[0];
				Params.FITINIT[3][3] = Old_Params[0];
				//meta1
				Params.FITINIT[1][8] = Old_Params[1];
				//meta2
				Params.FITINIT[2][8] = Old_Params[2];
				Params.FITINIT[2][9] = Old_Params[3]; 
				Params.FITINIT[2][10] = Old_Params[4];
				Params.FITINIT[2][11] = Old_Params[5];
				//meta1
				Params.FITINIT[3][8] = Old_Params[6];
				Params.FITINIT[3][9] = Old_Params[7];
				Params.FITINIT[3][10] = Old_Params[8];
				Params.FITINIT[3][11] = Old_Params[9];
				//CORE SET
				Params.muV			= Old_Params[10]; //virus decay
				Params.CV			= Old_Params[11];//hetereogeneity to virus infection 
				Params.nuV    		= Old_Params[12]; //virus transmission
				Params.specific_nuF	= Old_Params[13]; //fungus transmissison
				Params.R_stoch 		= Old_Params[14];
				Params.F_stoch		= Old_Params[15];
				//dispersal
				Params.c_a_pop = Old_Params[16];
				Params.c_m_pop = Old_Params[17];
				Params.l_a_pop = Old_Params[18];
				Params.l_m_pop = Old_Params[19];
			}
			lhood_meta=0; log_lhood_meta=0; total_loghood_metas = 0;
			new_posterior=0;
			meta_err=0;
			lhood_total=0;
			lhood_reps=0;

			for(int j=1; j<=3; j++){ //??? DO I WANT TO USE MY TICKER ALGORITHM HERE

				Params.miser_ticker = 1; Params.miser2_flag = 0; 
				
				Params.j = j;

				gsl_monte_function G = { &likelihood_calc, dim, &Params };	// declares function calling lhood_meta.h
				double xl[dim];	double xu[dim];	// need to redeclare xl and xu since the size changes
				for (int jj=0;jj<dim;jj++)	{
					xl[jj]=0;	
					xu[jj]=1;
				}

				gsl_monte_miser_state *s = gsl_monte_miser_alloc(dim);
				gsl_monte_miser_integrate (&G,xl,xu,dim,Mcalls,r_seed,s,&lhood_meta,&meta_err); //call MISER, pop_lhood is output from .h (likelihood value)
				gsl_monte_miser_free(s);
				
				while(Params.miser2_flag > 0){ //indicates that a better likelihood score (or a few) were found
					Params.miser2_flag = 0;
					Params.lhood_adjust[j] = -Params.bestlhood[j];
					
					gsl_monte_miser_state *s = gsl_monte_miser_alloc(dim);
					gsl_monte_miser_integrate (&G,xl,xu,dim,Mcalls,r_seed,s,&lhood_meta,&meta_err); //call MISER, pop_lhood is output from .h (likelihood value)
					gsl_monte_miser_free(s);
				}
				
				log_lhood_meta = log(lhood_meta) - Params.lhood_adjust[j];
				if(isnan(log_lhood_meta) || isinf(log_lhood_meta)){ //change to zero of inf or nan, only update lhood adj if not
					log_lhood_meta = -99999999;
				}
				//printf("log_lhood_meta=%lf\n", log_lhood_meta);
				total_loghood_metas = total_loghood_metas + log_lhood_meta;
				LogOldPosterior = 0.0;
				LogOldPosterior = total_loghood_metas + log_prior_Old;
				//printf("log prior old 2 = %lf\n", log_prior_Old);
				//printf("Log Old Posterior 2 = %lf\n", LogOldPosterior);
			}//j
			if (ProbOfAcceptance>1 || gsl_rng_uniform_pos (r) < ProbOfAcceptance){ //ACCEPT FINAL

				LogOldPosterior=LogNewPosterior;  //Accept the new parameter values.
				Accepted=Accepted+1;
				//printf("Accepted\n");
				Params.AcceptedVect[Case] = Params.AcceptedVect[Case] + 1;
				SigmaInflation = 1; //only to sample in overdispersed space for initial sampling
			}
			else{ //REJECTED FINAL
				for (a=0; a<NumberOfParams; a++){
					PC[a]=Old_PC[a];            //Keep the old parameter values.
				}
				//printf("Rejected 2\n");
			}
		}
		else{ //REJECTED PASS 1
			for (a=0; a<NumberOfParams; a++){
				PC[a]=Old_PC[a];            //Keep the old parameter values.
			}
			//printf("Rejected 1\n");
		}

		// ------------------------------------------ output results to file  --------------------------------------- //

		if (LoopNumber % 10 == 0){ //printing every 10
			//printf("printing!\n");
			for(int ii=0; ii<NumberOfParams; ii++){
				fprintf(fpm, "%lf\t", PCAparams[ii]);
			}
		fprintf(fpm, "%lf\t", LogNewPosterior);
		//printf("PRINTING post = %lf\n", LogNewPosterior);
		fprintf(fpm, "\n");
		fflush(stdout);
		fflush(fpm);
		}
	}
	fclose(fpm);
}

return 0;
}
