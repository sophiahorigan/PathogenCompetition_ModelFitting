#include "head.h"
gsl_rng *r;

///////////////////////////////////////////////////DOT-PRODUCT///////////////////////////////////////////////////
float DotProduct (int Length, double *Holder, double *PCA)
{
  double answer = 0;
  for(int i = 0; i < Length; i++)
  {
    answer += PCA[i] * Holder[i];
  }
  return(answer);
}

int main(int argc, char *argv[])
{

///////////////////////////////////////////////////SET-UP///////////////////////////////////////////////////

time_t start = time(NULL);

STRUCTURE Params;
inputdata(&Params);	

//--------RANDOM NUMBERS--------
//gsl_rng *r_seed;
//r_seed=random_setup();
//printf("rseed=%ld\n", r_seed);

const gsl_rng_type * K;

gsl_rng * r_seed;
gsl_rng_env_setup();
K = gsl_rng_default;
r_seed = gsl_rng_alloc (K);
double set_seed1 = time(NULL)*(int)getpid();
gsl_rng_set(r_seed, set_seed1);     
//gsl_rng_set(r_seed, 9558817455614.000000); 		//fix seed to troubleshoot

srand(time(NULL));

//--------ALGORITHM--------
char *y = argv[1]; char *z = argv[2];
Params.model = atoi(y); Params.algorithm = atoi(z);

int model = Params.model;
int algorithm = Params.algorithm;

if (algorithm > 3){
	printf("INACCURATE ALGORITHM. Try again from the options below.\n");
	printf("1 = linesearch 2 = realizations 3 = mcmc\n");
}
if (model > 45 || model < 0){
	printf("INACCURATE MODEL. Model options range from 0 - 45. See Read Me for model options.\n");
}

int VERBOSE = 1;
int TEST = 0;

if(algorithm == 1)
{
	linesearch = 1; reals = 0; mcmc = 0;
}
if(algorithm == 2)
{
	linesearch = 0; reals = 1; mcmc = 0;
}
if(algorithm == 3)
{
	linesearch = 0; reals = 0; mcmc = 1;
}

//-------DISPERSAL--------
int *p;
p = dispersal_fit(model);		//function returns 1 for fitting dispersal, 0 for not fitting dispersal
larval_dispersal = p[0]; l_a_pop_fit = p[1]; l_a_meta_fit = p[2]; l_a_sub_fit = p[3]; l_m_pop_fit = p[4]; l_m_meta_fit = p[5]; l_m_sub_fit = p[6]; 
conidia_dispersal = p[7]; c_a_pop_fit = p[8]; c_a_meta_fit = p[9]; c_a_sub_fit = p[10]; c_m_pop_fit = p[11]; c_m_meta_fit = p[12]; c_m_sub_fit = p[13];
r_pop_fit = p[14]; r_meta_fit = p[15]; r_sub_fit = p[16];

//-------FIT LIST--------
int num_ltfparams = 92;
double ltf_params[92] = {0};   
double init_ltfparams[92] = {0};
double step_size[92] = {0};
double temp[92] = {0};
double localmax_params[92]={0};	

double total_loghood_metas;

int *f; 
f = which_fit(model);			//function returns 1 for fitting param, 0 for not fitting param
for(int i = 0; i < num_ltfparams; i++)
{
	fit[i] = f[i];
}

//-------LOG FIT--------
static int log_fit[92] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1};			//1 for fitting on log-scale, 0 for fitting on non-log scale

//-------TEST MODE--------
if(VERBOSE == 1)
{
	LScalls = 50; Rcalls = 10; Mcalls = 50; Realizations = 50000;
	numround = 60; searches = 20;
}
if(TEST == 1)
{
	LScalls = 10; Rcalls = 10; Mcalls = 10; Realizations = 500;		//Reals needs to be num params *2 to get all params
	numround = 2; searches = 2;
}

///////////////////////////////////////////////////LINE-SEARCH///////////////////////////////////////////////////
	if(linesearch == 1)
	{
		//-------FILE SETUP--------
		int pid;
		pid = getpid();

		char namels[50];
		sprintf(namels, "M%i_LS_s%i_r%i_%i", model, searches, numround, pid);
		fpls = fopen(namels, "a+");
		setbuf(fpls, NULL);							

		//-------PROPOSE INITIAL PARAM SET--------
		for (int i=0;i<num_ltfparams;i++)
		{
			double randn = gsl_rng_uniform_pos(r_seed);
				if(log_fit[i]==1) 		//sampling in log space
				{
					temp[i] = exp(ls_bound(model, i,1)) + randn * exp(ls_bound(model,i,2)); 		//propose initial values in exp space to avoid issue with negative numbers
					ltf_params[i] = log(temp[i]); 		//re-log since we will be taking steps in log space
				}
				else
				{
					temp[i] = ls_bound(model,i,1) + randn * ls_bound(model,i,2); 		//propose initial values in exp space to avoid issue with negative numbers
					ltf_params[i] = temp[i]; 		//re-log since we will be taking steps in log space
				}
			init_ltfparams[i] = ltf_params[i];
			step_size[i] = (ls_bound(model,i,2) - ls_bound(model,i,1)) / (searches * 3);
		}
		for (int c = 0; c < num_ltfparams; c++)
		{			
			localmax_params[c] = ltf_params[c]; 		//initial parameters begin as 'best' parameters
		}

		//-------BEGIN LINE SEARCH--------
		for (int round = 0; round < numround; round++)
		{
			double best_posterior = -66666666666666;
			int a = 0;

			for (int i = 0; i < num_ltfparams; i++)
			{ 
				//--------ALTER PARAM-------
				if (fit[i] == 1)
				{
					a = i;
					if (round > 0)
					{		
						ltf_params[a] = ltf_params[a] - (step_size[a] * searches);
						if (ltf_params[a] < ls_bound(model,a,1))
						{ 
							ltf_params[a] = ls_bound(model,a,1);
						}
					}
					for (int b = 0; b < searches; b++)
					{ 
						if (b>0)
						{
							ltf_params[a] = ltf_params[a] + step_size[a]; 
							if (ltf_params[a] > ls_bound(model,a,2))
							{ 
								ltf_params[a] = ls_bound(model,a,2);
							}
						}

					//--------CALCULATE PRIORS-------
					double log_prior = 0;
					double new_log_prior = 0;

					for (int k = 0; k < num_ltfparams; k++)
					{
						if (fit[k] == 1)
						{
							if (log_fit[k] == 1)	//log fit
							{ 
								new_log_prior = log(gsl_ran_flat_pdf(exp(ltf_params[k]), exp(ls_bound(model,k,1)), (exp(ls_bound(model,k,1)) + exp(ls_bound(model,k,2)))));
								//printf("param %i = %lf\n", k, ltf_params[k]);
								//printf("newlog prior = %lf\n", new_log_prior);
							}
							else 					//non-log fit
							{ 
								new_log_prior = log(gsl_ran_flat_pdf(ltf_params[k], ls_bound(model,k,1), (ls_bound(model,k,1) + ls_bound(model,k,2))));
								//printf("param %i = %lf\n", k, ltf_params[k]);
								//printf("newlog prior = %lf\n", new_log_prior);
							}
							if (isnan(new_log_prior) || isinf(new_log_prior)) 	//outside of bounds
							{ 
								printf("PROBLEM WITH PRIORS\n k=%i\t new log prior = %lf\n", k, new_log_prior);
								new_log_prior = -999999;	//assign bad score
							}
							log_prior = log_prior + new_log_prior;
						}
					}
					//--------PASS FIXED PARAMS-------
					//INITV
					Params.FITINIT[1][4] 	= 	0.00000000000001; 		//META 1 SUB 1
					Params.FITINIT[1][5] 	= 	0.05; 					//META 1 SUB 2
					Params.FITINIT[1][6] 	= 	0.05;					//META 1 SUB 3
					Params.FITINIT[1][7] 	= 	0.00000000000001; 		//META 1 SUB 4
					Params.FITINIT[2][4] 	= 	0.00000000000001; 		//META 2 SUB 1
					Params.FITINIT[2][5] 	= 	0.05; 					//META 2 SUB 2
					Params.FITINIT[2][6] 	= 	0.05; 					//META 2 SUB 3
					Params.FITINIT[2][7] 	= 	0.00000000000001; 		//META 2 SUB 4
					Params.FITINIT[3][4] 	= 	0.00000000000001; 		//META 3 SUB 1
					Params.FITINIT[3][5] 	= 	0.05; 					//META 3 SUB 2
					Params.FITINIT[3][6] 	= 	0.05; 					//META 3 SUB 3
					Params.FITINIT[3][7] 	= 	0.00000000000001; 		//META 3 SUB 4
					//INITR
					Params.FITINIT[1][9] 	= 	0; 						//META 1 SUB 2
					Params.FITINIT[1][10] 	= 	0; 						//META 1 SUB 3
					Params.FITINIT[1][11] 	= 	0; 						//META 1 SUB 4
					Params.FITINIT[5][8] 	= 	0; 						//META 5
					//VIRUS DECAY
					Params.muV				= 	0.4102453; 				//POP
					//VIRUS HETERO		
					Params.CV				= 	0.86; 					//POP
					//VIRUS TRANS
					Params.nuV    			= 	0.4607038; 				//POP
					//FUNGUS TRANS
					Params.specific_nuF		= 	0.000241071699421562; 	//POP

					//--------PASS FIT PARAMS-------
					Params.FITINIT[1][0] 	= 	exp(ltf_params[0]); 	//META 1 SUB 1
					Params.FITINIT[1][1] 	= 	exp(ltf_params[0]); 	//META 1 SUB 2
					Params.FITINIT[1][2] 	= 	exp(ltf_params[0]); 	//META 1 SUB 3
					Params.FITINIT[1][3] 	= 	exp(ltf_params[0]); 	//META 1 SUB 4
					Params.FITINIT[2][0] 	= 	exp(ltf_params[0]); 	//META 2 SUB 1
					Params.FITINIT[2][1] 	= 	exp(ltf_params[0]); 	//META 2 SUB 2
					Params.FITINIT[2][2] 	= 	exp(ltf_params[0]); 	//META 2 SUB 3
					Params.FITINIT[2][3] 	= 	exp(ltf_params[0]); 	//META 2 SUB 4
					Params.FITINIT[3][0] 	= 	exp(ltf_params[0]); 	//META 3 SUB 1
					Params.FITINIT[3][1] 	= 	exp(ltf_params[0]); 	//META 3 SUB 2
					Params.FITINIT[3][2] 	= 	exp(ltf_params[0]); 	//META 3 SUB 3
					Params.FITINIT[3][3] 	= 	exp(ltf_params[0]); 	//META 3 SUB 4
					//INITR
					Params.r_pop 			= 	exp(ltf_params[1]);		//POP

					Params.r_meta[1] 		= 	exp(ltf_params[2]);		//META 1
					Params.r_meta[2] 		= 	exp(ltf_params[3]);		//META 2
					Params.r_meta[3] 		=	exp(ltf_params[4]);		//META 3
					Params.FITINIT[1][8] 	= 	exp(ltf_params[5]); 	//META 1 SUB 1
					Params.FITINIT[2][8] 	= 	exp(ltf_params[6]); 	//META 2 SUB 1
					Params.FITINIT[2][9] 	= 	exp(ltf_params[7]); 	//META 2 SUB 2 
					Params.FITINIT[2][10] 	= 	exp(ltf_params[8]); 	//META 2 SUB 3
					Params.FITINIT[2][11] 	= 	exp(ltf_params[9]); 	//META 2 SUB 4
					Params.FITINIT[3][8] 	= 	exp(ltf_params[10]); 	//META 3 SUB 1
					Params.FITINIT[3][9] 	= 	exp(ltf_params[11]); 	//META 3 SUB 2
					Params.FITINIT[3][10] 	= 	exp(ltf_params[12]); 	//META 3 SUB 3
					Params.FITINIT[3][11] 	= 	exp(ltf_params[13]); 	//META 3 SUB 4
					//RSTOCH
					Params.R_stoch 			= 	exp(ltf_params[18]);	//POP
					//FSTOCH
					Params.F_stoch			= 	exp(ltf_params[19]);	//POP
					//CONIDIA 1/AVG DIST DISP
					Params.c_a_pop 			= 	exp(ltf_params[20]);	//POP
					Params.c_a_meta[1] 		= 	exp(ltf_params[21]);	//META 1
					Params.c_a_meta[2] 		= 	exp(ltf_params[22]);	//META 2
					Params.c_a_meta[3] 		= 	exp(ltf_params[23]);	//META 3
					Params.c_a_sub[1][0] 	= 	exp(ltf_params[24]); 	//META 1 SUB 1
					Params.c_a_sub[1][1] 	= 	exp(ltf_params[25]);	//META 1 SUB 2
					Params.c_a_sub[1][2] 	= 	exp(ltf_params[26]);	//META 1 SUB 3
					Params.c_a_sub[1][3] 	= 	exp(ltf_params[27]);	//META 1 SUB 4
					Params.c_a_sub[2][0] 	= 	exp(ltf_params[28]); 	//META 2 SUB 1
					Params.c_a_sub[2][1] 	= 	exp(ltf_params[29]);	//META 2 SUB 2
					Params.c_a_sub[2][2] 	= 	exp(ltf_params[30]);	//META 2 SUB 3
					Params.c_a_sub[2][3] 	= 	exp(ltf_params[31]);	//META 2 SUB 4
					Params.c_a_sub[3][0] 	= 	exp(ltf_params[32]); 	//META 3 SUB 1
					Params.c_a_sub[3][1] 	= 	exp(ltf_params[33]);	//META 3 SUB 2
					Params.c_a_sub[3][2] 	= 	exp(ltf_params[34]);	//META 3 SUB 3
					Params.c_a_sub[3][3] 	= 	exp(ltf_params[35]);	//META 3 SUB 4
					//CONIDIA FRAC SUCCESSFUL DISP
					Params.c_m_pop			= 	ltf_params[36]; 		//POP
					Params.c_m_meta[1]		= 	ltf_params[37];			//META 1
					Params.c_m_meta[2]		= 	ltf_params[38];			//META 2
					Params.c_m_meta[3]		= 	ltf_params[39];			//META 3
					Params.c_m_sub[1][0] 	= 	ltf_params[40];			//META 1 SUB 1
					Params.c_m_sub[1][1] 	= 	ltf_params[41];			//META 1 SUB 2
					Params.c_m_sub[1][2]	= 	ltf_params[42];			//META 1 SUB 3
					Params.c_m_sub[1][3] 	= 	ltf_params[43];			//META 1 SUB 4
					Params.c_m_sub[2][0] 	= 	ltf_params[44];			//META 2 SUB 1
					Params.c_m_sub[2][1] 	= 	ltf_params[45];			//META 2 SUB 2
					Params.c_m_sub[2][2] 	= 	ltf_params[46];			//META 2 SUB 3
					Params.c_m_sub[2][3] 	= 	ltf_params[47];			//META 2 SUB 4
					Params.c_m_sub[3][0] 	= 	ltf_params[48];			//META 3 SUB 1
					Params.c_m_sub[3][1] 	= 	ltf_params[49];			//META 3 SUB 2
					Params.c_m_sub[3][2] 	= 	ltf_params[50];			//META 3 SUB 3
					Params.c_m_sub[3][3] 	= 	ltf_params[51];			//META 3 SUB 4
					//LARVAE 1/AVG DIST DISP
					//TEMP
					Params.l_a_pop 			= 	exp(ltf_params[52]);	//POP
					Params.l_a_meta[1] 		= 	exp(ltf_params[53]);	//META 1
					Params.l_a_meta[2] 		= 	exp(ltf_params[54]);	//META 2
					Params.l_a_meta[3] 		= 	exp(ltf_params[55]);	//META 3
					Params.l_a_sub[1][0] 	= 	exp(ltf_params[56]);	//META 1 SUB 1
					Params.l_a_sub[1][1] 	= 	exp(ltf_params[57]);	//META 1 SUB 2
					Params.l_a_sub[1][2] 	= 	exp(ltf_params[58]);	//META 1 SUB 3
					Params.l_a_sub[1][3] 	= 	exp(ltf_params[59]);	//META 1 SUB 4
					Params.l_a_sub[2][0] 	=	exp(ltf_params[60]); 	//META 2 SUB 1
					Params.l_a_sub[2][1] 	= 	exp(ltf_params[61]);	//META 2 SUB 2
					Params.l_a_sub[2][2] 	= 	exp(ltf_params[62]);	//META 2 SUB 3
					Params.l_a_sub[2][3] 	= 	exp(ltf_params[63]);	//META 2 SUB 4
					Params.l_a_sub[3][0] 	= 	exp(ltf_params[64]); 	//META 3 SUB 1
					Params.l_a_sub[3][1] 	= 	exp(ltf_params[65]);	//META 3 SUB 2
					Params.l_a_sub[3][2] 	= 	exp(ltf_params[66]);	//META 3 SUB 3
					Params.l_a_sub[3][3] 	= 	exp(ltf_params[67]);	//META 3 SUB 4
					//LARVAE FRAC SUCCESSFUL DISP
					Params.l_m_pop			= 	ltf_params[68]; 		//POP
					Params.l_m_meta[1]		= 	ltf_params[69];			//META 1
					Params.l_m_meta[2]		= 	ltf_params[70];			//META 2
					Params.l_m_meta[3]		= 	ltf_params[71];			//META 3
					Params.l_m_sub[1][0] 	= 	ltf_params[72];			//META 1 SUB 1
					Params.l_m_sub[1][1] 	= 	ltf_params[73];			//META 1 SUB 2
					Params.l_m_sub[1][2] 	= 	ltf_params[74];			//META 1 SUB 3
					Params.l_m_sub[1][3] 	= 	ltf_params[75];			//META 1 SUB 4
					Params.l_m_sub[2][0] 	= 	ltf_params[76];			//META 2 SUB 1
					Params.l_m_sub[2][1] 	= 	ltf_params[77];			//META 2 SUB 2
					Params.l_m_sub[2][2] 	= 	ltf_params[78];			//META 2 SUB 3
					Params.l_m_sub[2][3] 	= 	ltf_params[79];			//META 2 SUB 4
					Params.l_m_sub[3][0] 	= 	ltf_params[80];			//META 3 SUB 1
					Params.l_m_sub[3][1] 	= 	ltf_params[81];			//META 3 SUB 2
					Params.l_m_sub[3][2] 	= 	ltf_params[82];			//META 3 SUB 3
					Params.l_m_sub[3][3] 	= 	ltf_params[83];			//META 3 SUB 4
					//OBSERVATIONAL
					Params.FITINIT[4][0] = exp(ltf_params[84]); 		//META 4 INITS
					Params.FITINIT[4][4] = exp(ltf_params[85]); 		//META 4 INITV
					Params.FITINIT[4][8] = exp(ltf_params[86]); 		//META 4 INITR
					Params.FITINIT[5][0] = exp(ltf_params[87]); 		//META 5 INITS
					Params.FITINIT[5][4] = exp(ltf_params[88]); 		//META 5 INITV
					Params.FITINIT[6][0] = exp(ltf_params[89]);	 		//META 6 INITS
					Params.FITINIT[6][4] = exp(ltf_params[90]); 		//META 6 INITV
					Params.FITINIT[6][8] = exp(ltf_params[91]); 		//META 6 INITR

					//--------MISER CALUCLATE LIKELIHOOD-------
					double lhood_meta = 0; double log_lhood_meta = 0; total_loghood_metas = 0;
					double new_posterior = 0;
					double meta_err = 0;

					for (int j = 1; j <= 3; j++)				//only using experimental datsets currently
					{
						Params.j = j;

						Params.miser_ticker = 1; Params.miser2_flag = 0; 

						gsl_monte_function G = { &likelihood_calc, dim, &Params };			//declares function calling lhood_meta.h

						double xl[dim];	double xu[dim];	
						for (int jj = 0;jj < dim; jj++)	
						{
							xl[jj] = 0;	
							xu[jj] = 1;
						}

						gsl_monte_miser_state *s = gsl_monte_miser_alloc(dim);
						gsl_monte_miser_integrate (&G, xl, xu, dim, LScalls, r_seed, s, &lhood_meta, &meta_err); 		//call MISER
						gsl_monte_miser_free(s);
						
						while (Params.miser2_flag > 0)		//indicates that a better likelihood score (or a few) were found
						{ 
							Params.miser2_flag = 0;
							Params.lhood_adjust[j] = -Params.bestlhood[j];
							
							gsl_monte_miser_state *s = gsl_monte_miser_alloc(dim);
							gsl_monte_miser_integrate (&G, xl, xu, dim, LScalls, r_seed, s, &lhood_meta, &meta_err); 
							gsl_monte_miser_free(s);
						}

						log_lhood_meta = log(lhood_meta) - Params.lhood_adjust[j];

						if (isnan(log_lhood_meta) || isinf(log_lhood_meta))			//assign bad score to errors
						{ 
							log_lhood_meta = -999999999999;
						}
						
						total_loghood_metas = total_loghood_metas + log_lhood_meta;

						new_posterior = total_loghood_metas + log_prior;
					}
					//printf("LINESEARCH\n");
					//printf("loghood metas = %lf\n", total_loghood_metas);
					//printf("prior = %lf\n", log_prior);
					//printf("new_posterior = %lf\n", new_posterior);

					//--------EVALUATE POSTERIOR-------
					if (new_posterior > best_posterior)
					{ 
						best_posterior = new_posterior;
						for (int c = 0; c < num_ltfparams; c++)
						{
							localmax_params[c] = ltf_params[c]; 			
						}
					}
				}  
				for (int d = 0; d < num_ltfparams; d++)
				{
					ltf_params[d] = localmax_params[d];
				}
				i++;
				}
			} 
			//--------PRINT BEST PARAM SET FROM ROUND-------
			int index;
			for(int ii=0; ii < num_ltfparams; ii++)
			{
				if (fit[ii] == 1)
				{
					if (log_fit[ii] == 1)
					{
						fprintf(fpls, "%5.3f ", ltf_params[ii]);
					}
					else if (log_fit[ii] == 0)
					{
						fprintf(fpls, "%5.3f ", ltf_params[ii]); 
					}
				}
			}
			fprintf(fpls, "%4.3e ", total_loghood_metas);
			//printf("printing best Param set = %lf\n", total_loghood_metas);
			fprintf(fpls, "%4.3e ", best_posterior);
			fprintf(fpls, "\n");
		}
		fclose(fpls); 
	}
///////////////////////////////////////////////////REALIZATIONS///////////////////////////////////////////////////
	if (reals == 1)
	{
		//--------FILE SETUP-------
		char name1[50];
		sprintf(name1, "M%i_REALS_c%i", model, Rcalls);
		fpr = fopen(name1, "a+");
		setbuf(fpr, NULL);

		char nameme[50];
		sprintf(nameme, "meta_err_m%i", Params.model);
		fpme = fopen(nameme, "a+");
		setbuf(fpme, NULL);

		//--------PASS FIXED PARAMS-------
		//INITV
		Params.FITINIT[1][4] 	= 	0.00000000000001; 		//META 1 SUB 1
		Params.FITINIT[1][5] 	= 	0.05; 					//META 1 SUB 2
		Params.FITINIT[1][6] 	= 	0.05;					//META 1 SUB 3
		Params.FITINIT[1][7] 	= 	0.00000000000001; 		//META 1 SUB 4
		Params.FITINIT[2][4] 	= 	0.00000000000001; 		//META 2 SUB 1
		Params.FITINIT[2][5] 	= 	0.05; 					//META 2 SUB 2
		Params.FITINIT[2][6] 	= 	0.05; 					//META 2 SUB 3
		Params.FITINIT[2][7] 	= 	0.00000000000001; 		//META 2 SUB 4
		Params.FITINIT[3][4] 	= 	0.00000000000001; 		//META 3 SUB 1
		Params.FITINIT[3][5] 	= 	0.05; 					//META 3 SUB 2
		Params.FITINIT[3][6] 	= 	0.05; 					//META 3 SUB 3
		Params.FITINIT[3][7] 	= 	0.00000000000001; 		//META 3 SUB 4
		//INITR
		Params.FITINIT[1][9] 	= 	0; 						//META 1 SUB 2
		Params.FITINIT[1][10] 	= 	0; 						//META 1 SUB 3
		Params.FITINIT[1][11] 	= 	0; 						//META 1 SUB 4
		Params.FITINIT[5][8] 	= 	0; 						//META 5
		//VIRUS DECAY
		Params.muV				= 	0.4102453; 				//POP
		//VIRUS HETERO		
		Params.CV				= 	0.86; 					//POP
		//VIRUS TRANS
		Params.nuV    			= 	0.4607038; 				//POP
		//FUNGUS TRANS
		Params.specific_nuF		= 	0.000241071699421562; 	//POP

		//--------PASS FIT PARAMS ESTIMATES-------
		//INITS
		double init_s = 2.687;
		Params.FITINIT[1][0] 	= 	init_s;				 	//META 1 SUB 1
		Params.FITINIT[1][1] 	= 	init_s;				 	//META 1 SUB 2
		Params.FITINIT[1][2] 	= 	init_s;				 	//META 1 SUB 3
		Params.FITINIT[1][3] 	= 	init_s;				 	//META 1 SUB 4
		Params.FITINIT[2][0] 	= 	init_s;				 	//META 2 SUB 1
		Params.FITINIT[2][1] 	= 	init_s;				 	//META 2 SUB 2
		Params.FITINIT[2][2] 	= 	init_s;				 	//META 2 SUB 3
		Params.FITINIT[2][3] 	= 	init_s;				 	//META 2 SUB 4
		Params.FITINIT[3][0] 	= 	init_s;				 	//META 3 SUB 1
		Params.FITINIT[3][1] 	= 	init_s;				 	//META 3 SUB 2
		Params.FITINIT[3][2] 	= 	init_s;				 	//META 3 SUB 3
		Params.FITINIT[3][3] 	= 	init_s;				 	//META 3 SUB 4
		//INITR
		Params.r_pop 			= 	exp(-5.404);				//POP
		Params.r_meta[1] 		= 	exp(-5.404);		//META 1
		Params.r_meta[2] 		= 	exp(-5.404);		//META 2
		Params.r_meta[3] 		=	exp(-5.404);		//META 3
		Params.FITINIT[1][8] 	= 	exp(-5.404); 		//META 1 SUB 1
		Params.FITINIT[2][8] 	= 	exp(-5.404);		//META 2 SUB 1
		Params.FITINIT[2][9] 	= 	exp(-5.404); 		//META 2 SUB 2 
		Params.FITINIT[2][10] 	= 	exp(-5.404);		//META 2 SUB 3
		Params.FITINIT[2][11] 	= 	exp(-5.404);		//META 2 SUB 4
		Params.FITINIT[3][8] 	= 	exp(-5.404); 		//META 3 SUB 1
		Params.FITINIT[3][9] 	= 	exp(-5.404);		//META 3 SUB 2
		Params.FITINIT[3][10] 	= 	exp(-5.404); 		//META 3 SUB 3
		Params.FITINIT[3][11] 	= 	exp(-5.404); 		//META 3 SUB 4
		//RSTOCH
		Params.R_stoch 			=	exp(-0.604);				//POP
		//FSTOCH
		Params.F_stoch			= 	exp(-2.603);				//POP
		//CONIDIA 1/AVG DIST DISP
		Params.c_a_pop 			= 	exp(ltf_params[20]);	//POP
		Params.c_a_meta[1] 		= 	exp(ltf_params[21]);	//META 1
		Params.c_a_meta[2] 		= 	exp(ltf_params[22]);	//META 2
		Params.c_a_meta[3] 		= 	exp(ltf_params[23]);	//META 3
		Params.c_a_sub[1][0] 	= 	exp(ltf_params[24]); 	//META 1 SUB 1
		Params.c_a_sub[1][1] 	= 	exp(ltf_params[25]);	//META 1 SUB 2
		Params.c_a_sub[1][2] 	= 	exp(ltf_params[26]);	//META 1 SUB 3
		Params.c_a_sub[1][3] 	= 	exp(ltf_params[27]);	//META 1 SUB 4
		Params.c_a_sub[2][0] 	= 	exp(ltf_params[28]); 	//META 2 SUB 1
		Params.c_a_sub[2][1] 	= 	exp(ltf_params[29]);	//META 2 SUB 2
		Params.c_a_sub[2][2] 	= 	exp(ltf_params[30]);	//META 2 SUB 3
		Params.c_a_sub[2][3] 	= 	exp(ltf_params[31]);	//META 2 SUB 4
		Params.c_a_sub[3][0] 	= 	exp(ltf_params[32]); 	//META 3 SUB 1
		Params.c_a_sub[3][1] 	= 	exp(ltf_params[33]);	//META 3 SUB 2
		Params.c_a_sub[3][2] 	= 	exp(ltf_params[34]);	//META 3 SUB 3
		Params.c_a_sub[3][3] 	= 	exp(ltf_params[35]);	//META 3 SUB 4
		//CONIDIA FRAC SUCCESSFUL DISP
		Params.c_m_pop			= 	ltf_params[36]; 		//POP
		Params.c_m_meta[1]		= 	ltf_params[37];			//META 1
		Params.c_m_meta[2]		= 	ltf_params[38];			//META 2
		Params.c_m_meta[3]		= 	ltf_params[39];			//META 3
		Params.c_m_sub[1][0] 	= 	ltf_params[40];			//META 1 SUB 1
		Params.c_m_sub[1][1] 	= 	ltf_params[41];			//META 1 SUB 2
		Params.c_m_sub[1][2]	= 	ltf_params[42];			//META 1 SUB 3
		Params.c_m_sub[1][3] 	= 	ltf_params[43];			//META 1 SUB 4
		Params.c_m_sub[2][0] 	= 	ltf_params[44];			//META 2 SUB 1
		Params.c_m_sub[2][1] 	= 	ltf_params[45];			//META 2 SUB 2
		Params.c_m_sub[2][2] 	= 	ltf_params[46];			//META 2 SUB 3
		Params.c_m_sub[2][3] 	= 	ltf_params[47];			//META 2 SUB 4
		Params.c_m_sub[3][0] 	= 	ltf_params[48];			//META 3 SUB 1
		Params.c_m_sub[3][1] 	= 	ltf_params[49];			//META 3 SUB 2
		Params.c_m_sub[3][2] 	= 	ltf_params[50];			//META 3 SUB 3
		Params.c_m_sub[3][3] 	= 	ltf_params[51];			//META 3 SUB 4
		//LARVAE 1/AVG DIST DISP
		Params.l_a_pop 			= 	exp(-1.760);				//POP
		Params.l_a_meta[1] 		= 	exp(ltf_params[53]);	//META 1
		Params.l_a_meta[2] 		= 	exp(ltf_params[54]);	//META 2
		Params.l_a_meta[3] 		= 	exp(ltf_params[55]);	//META 3
		Params.l_a_sub[1][0] 	= 	exp(ltf_params[56]);	//META 1 SUB 1
		Params.l_a_sub[1][1] 	= 	exp(ltf_params[57]);	//META 1 SUB 2
		Params.l_a_sub[1][2] 	= 	exp(ltf_params[58]);	//META 1 SUB 3
		Params.l_a_sub[1][3] 	= 	exp(ltf_params[59]);	//META 1 SUB 4
		Params.l_a_sub[2][0] 	=	exp(ltf_params[60]); 	//META 2 SUB 1
		Params.l_a_sub[2][1] 	= 	exp(ltf_params[61]);	//META 2 SUB 2
		Params.l_a_sub[2][2] 	= 	exp(ltf_params[62]);	//META 2 SUB 3
		Params.l_a_sub[2][3] 	= 	exp(ltf_params[63]);	//META 2 SUB 4
		Params.l_a_sub[3][0] 	= 	exp(ltf_params[64]); 	//META 3 SUB 1
		Params.l_a_sub[3][1] 	= 	exp(ltf_params[65]);	//META 3 SUB 2
		Params.l_a_sub[3][2] 	= 	exp(ltf_params[66]);	//META 3 SUB 3
		Params.l_a_sub[3][3] 	= 	exp(ltf_params[67]);	//META 3 SUB 4
		//LARVAE FRAC SUCCESSFUL DISP
		Params.l_m_pop			= 	0.267; 				//POP
		Params.l_m_meta[1]		= 	ltf_params[69];			//META 1
		Params.l_m_meta[2]		= 	ltf_params[70];			//META 2
		Params.l_m_meta[3]		= 	ltf_params[71];			//META 3
		Params.l_m_sub[1][0] 	= 	ltf_params[72];			//META 1 SUB 1
		Params.l_m_sub[1][1] 	= 	ltf_params[73];			//META 1 SUB 2
		Params.l_m_sub[1][2] 	= 	ltf_params[74];			//META 1 SUB 3
		Params.l_m_sub[1][3] 	= 	ltf_params[75];			//META 1 SUB 4
		Params.l_m_sub[2][0] 	= 	ltf_params[76];			//META 2 SUB 1
		Params.l_m_sub[2][1] 	= 	ltf_params[77];			//META 2 SUB 2
		Params.l_m_sub[2][2] 	= 	ltf_params[78];			//META 2 SUB 3
		Params.l_m_sub[2][3] 	= 	ltf_params[79];			//META 2 SUB 4
		Params.l_m_sub[3][0] 	= 	ltf_params[80];			//META 3 SUB 1
		Params.l_m_sub[3][1] 	= 	ltf_params[81];			//META 3 SUB 2
		Params.l_m_sub[3][2] 	= 	ltf_params[82];			//META 3 SUB 3
		Params.l_m_sub[3][3] 	= 	ltf_params[83];			//META 3 SUB 4
		//OBSERVATIONAL
		Params.FITINIT[4][0] = exp(ltf_params[84]); 		//META 4 INITS
		Params.FITINIT[4][4] = exp(ltf_params[85]); 		//META 4 INITV
		Params.FITINIT[4][8] = exp(ltf_params[86]); 		//META 4 INITR
		Params.FITINIT[5][0] = exp(ltf_params[87]); 		//META 5 INITS
		Params.FITINIT[5][4] = exp(ltf_params[88]); 		//META 5 INITV
		Params.FITINIT[6][0] = exp(ltf_params[89]);	 		//META 6 INITS
		Params.FITINIT[6][4] = exp(ltf_params[90]); 		//META 6 INITV
		Params.FITINIT[6][8] = exp(ltf_params[91]); 		//META 6 INITR

		//--------GENERATE REALIZATIONS USING MISER-------
		double lhood_meta = 0; double log_lhood_meta = 0; double total_loghood_metas = 0;
		double new_posterior = 0;
		double meta_err = 0;

		for (int j = 1; j <= 3; j++)
		{
			Params.j = j;

			Params.miser_ticker = 1; Params.miser2_flag = 0;

			gsl_monte_function G = { &likelihood_calc, dim, &Params };	

			double xl[dim];	double xu[dim];	
			for (int jj=0;jj<dim;jj++)	
			{
				xl[jj] = 0;	
				xu[jj] = 1;
			}

			gsl_monte_miser_state *s = gsl_monte_miser_alloc(dim);
			gsl_monte_miser_integrate (&G, xl, xu, dim, Rcalls, r_seed, s, &lhood_meta, &meta_err); 
			gsl_monte_miser_free(s);

			log_lhood_meta = log(lhood_meta) - Params.lhood_adjust[j];

			if (isnan(log_lhood_meta) || isinf(log_lhood_meta))
			{
				log_lhood_meta = -99999999;
			}
			
			total_loghood_metas = total_loghood_metas + log_lhood_meta;

		}
		printf("total loghood metas = %lf\n", total_loghood_metas);
		fclose(fpr); 
		fclose(fpme);
	}
///////////////////////////////////////////////////MCMC//////////////////////////////////////////////////////////
	if (mcmc == 1)
	{
		//-------FITTING ROUTINE--------
		int NumberOfParams = NumFitParams(model);    

		//-------FILE SETUP--------
		int pid;
		pid = getpid();

		char namem[50];
		sprintf(namem, "M%i_mcmc_%i", model, pid);
		fpm = fopen(namem, "a+");
		setbuf(fpm, NULL);

		//-------RANDOM NUMBER--------
		const gsl_rng_type * T;

		gsl_rng * r;
		gsl_rng_env_setup();
		T = gsl_rng_default;
		r = gsl_rng_alloc (T);
		double set_seed2 = time(NULL)*(int)getpid();
		gsl_rng_set(r, set_seed2);     
		//gsl_rng_set(r, 9558817455614.000000); 
		//printf("rand time pid = %lf\n", set_seed2);
		
		srand(time(NULL));

		//printf("r=%i\n", r);

		//-------VARIABLE AND ARRAY SETUP--------
		double LogJumpToNew;
		double LogJumpToOld;
		double ProbOfAcceptance;

		double LogOldPosterior;
		double LogNewPosterior;
		double LogNewPrior;
		double PreviousLogOldPosterior = -100000000000000;

		double SDpca[NumberOfParams];
		double Coefficients[NumberOfParams*NumberOfParams];
		double Center[NumberOfParams];
		double Scale[NumberOfParams];
		double New_PC[NumberOfParams];
		double Old_PC[NumberOfParams];
		double Holder[NumberOfParams];
		double New_Params[NumberOfParams];
		double Old_Params[NumberOfParams];

		int Accept=0;
		int Attempt=0;

		int a;
		int b;
		int ticker;
		int ticker2;

		int Case;

		signed int LoopNumber=-1;

		int ParCnt2 = NumberOfParams;

		double SigmaInflation=1.2;

		double sigma[NumberOfParams];

		double log_prior_new;
		double log_prior_old;
		double log_prior_OLD;
		double log_prior_NEW;

		double lhood_meta;
		double log_lhood_meta;
		double total_loghood_metas_OLD;
		double total_loghood_metas_NEW;
		double meta_err;

		//-------READ IN PCA--------
		FILE *file;

		if(model==1)
		{
			file = fopen("PCAsd2_1.txt", "r");         
			for (a = 0; a < (NumberOfParams); a++)
			{
				fscanf(file, "%lf\n", &SDpca[a]);
			}
			fclose(file);

			file = fopen("PCArotations2_1.txt", "r");  
			for (a = 0; a < (NumberOfParams*NumberOfParams); a++)
			{
				fscanf(file, "%lf\n", &Coefficients[a]);
			}
			fclose(file);

			file = fopen("PCAscale2_1.txt", "r");       
			for (a = 0; a < NumberOfParams; a++)
			{
				fscanf(file, "%lf\n", &Scale[a]);
			}
			fclose(file);

			file = fopen("PCAcenter2_1.txt", "r");      
			for (a = 0; a < NumberOfParams; a++)
			{
				fscanf(file, "%lf\n", &Center[a]);
			}
			fclose(file);
		}
		if(model==2)
		{
			file = fopen("PCAsd2_2.txt", "r");         
			for (a = 0; a < (NumberOfParams); a++)
			{
				fscanf(file, "%lf\n", &SDpca[a]);
			}
			fclose(file);

			file = fopen("PCArotations2_2.txt", "r");  
			for (a = 0; a < (NumberOfParams*NumberOfParams); a++)
			{
				fscanf(file, "%lf\n", &Coefficients[a]);
			}
			fclose(file);

			file = fopen("PCAscale2_2.txt", "r");       
			for (a = 0; a < NumberOfParams; a++)
			{
				fscanf(file, "%lf\n", &Scale[a]);
			}
			fclose(file);

			file = fopen("PCAcenter2_2.txt", "r");      
			for (a = 0; a < NumberOfParams; a++)
			{
				fscanf(file, "%lf\n", &Center[a]);
			}
			fclose(file);
		}
		if(model==4)
		{
			file = fopen("PCAsd2_4.txt", "r");         
			for (a = 0; a < (NumberOfParams); a++)
			{
				fscanf(file, "%lf\n", &SDpca[a]);
			}
			fclose(file);

			file = fopen("PCArotations2_4.txt", "r");  
			for (a = 0; a < (NumberOfParams*NumberOfParams); a++)
			{
				fscanf(file, "%lf\n", &Coefficients[a]);
			}
			fclose(file);

			file = fopen("PCAscale2_4.txt", "r");       
			for (a = 0; a < NumberOfParams; a++)
			{
				fscanf(file, "%lf\n", &Scale[a]);
			}
			fclose(file);

			file = fopen("PCAcenter2_4.txt", "r");      
			for (a = 0; a < NumberOfParams; a++)
			{
				fscanf(file, "%lf\n", &Center[a]);
			}
			fclose(file);
		}
		if(model==22)
		{
			file = fopen("PCAsd2_22.txt", "r");         
			for (a = 0; a < (NumberOfParams); a++)
			{
				fscanf(file, "%lf\n", &SDpca[a]);
			}
			fclose(file);

			file = fopen("PCArotations2_22.txt", "r");  
			for (a = 0; a < (NumberOfParams*NumberOfParams); a++)
			{
				fscanf(file, "%lf\n", &Coefficients[a]);
			}
			fclose(file);

			file = fopen("PCAscale2_22.txt", "r");       
			for (a = 0; a < NumberOfParams; a++)
			{
				fscanf(file, "%lf\n", &Scale[a]);
			}
			fclose(file);

			file = fopen("PCAcenter2_22.txt", "r");      
			for (a = 0; a < NumberOfParams; a++)
			{
				fscanf(file, "%lf\n", &Center[a]);
			}
			fclose(file);
		}
		if(model==28)
		{
			file = fopen("PCAsd2_28.txt", "r");         
			for (a = 0; a < (NumberOfParams); a++)
			{
				fscanf(file, "%lf\n", &SDpca[a]);
			}
			fclose(file);

			file = fopen("PCArotations2_28.txt", "r");  
			for (a = 0; a < (NumberOfParams*NumberOfParams); a++)
			{
				fscanf(file, "%lf\n", &Coefficients[a]);
			}
			fclose(file);

			file = fopen("PCAscale2_28.txt", "r");       
			for (a = 0; a < NumberOfParams; a++)
			{
				fscanf(file, "%lf\n", &Scale[a]);
			}
			fclose(file);

			file = fopen("PCAcenter2_28.txt", "r");      
			for (a = 0; a < NumberOfParams; a++)
			{
				fscanf(file, "%lf\n", &Center[a]);
			}
			fclose(file);
		}
		if(model==32)
		{
			file = fopen("PCAsd2_32.txt", "r");         
			for (a = 0; a < (NumberOfParams); a++)
			{
				fscanf(file, "%lf\n", &SDpca[a]);
			}
			fclose(file);

			file = fopen("PCArotations2_32.txt", "r");  
			for (a = 0; a < (NumberOfParams*NumberOfParams); a++)
			{
				fscanf(file, "%lf\n", &Coefficients[a]);
			}
			fclose(file);

			file = fopen("PCAscale2_32.txt", "r");       
			for (a = 0; a < NumberOfParams; a++)
			{
				fscanf(file, "%lf\n", &Scale[a]);
			}
			fclose(file);

			file = fopen("PCAcenter2_32.txt", "r");      
			for (a = 0; a < NumberOfParams; a++)
			{
				fscanf(file, "%lf\n", &Center[a]);
			}
			fclose(file);
		}
		//-------GENERATE INITIAL PCS--------
		for (a = 0; a < NumberOfParams; a++)
		{
			sigma[a] = SigmaInflation * SDpca[a]; 
		}
		//-------RECONSTRUCT PARAMS FROM PCS AND BOUND CHECK--------
		int PCA_ticker = 0;
		while (PCA_ticker == 0)
		{
			for (a = 0; a < NumberOfParams; a++)
			{ 
				New_PC[a] = gsl_ran_gaussian (r, sigma[a]);  
			}
			for (a = 0; a < NumberOfParams; a++)
			{							
				for (b = 0; b < NumberOfParams; b++)
				{
					Holder[b] = Coefficients[a * NumberOfParams + b];         
				}
				New_Params[a] = exp(DotProduct(ParCnt2, Holder, New_PC) * Scale[a] + Center[a]); 
			}

			PCA_ticker=1;
			for (a = 0; a < NumberOfParams; a++)
			{
				if (New_Params[a] < mcmc_bound(model, a, 1) || New_Params[a] > mcmc_bound(model, a, 2))
				{ 
					PCA_ticker = 0;
					printf("model = %i\n", model);
					printf("out of bounds initial PC proposal for param %i\n", a);
					printf("value = %lf\t lower bound = %lf\t upper bound = %lf\n", New_Params[a], mcmc_bound(model, a, 1), mcmc_bound(model, a, 2));	
				}
				else
				{
				}
			}
		}
		printf("initial parameter set successful\n");
	//-------BEGIN MCMC--------
	while (LoopNumber <= Realizations) 
	{     
			LoopNumber = LoopNumber + 1;

			Case = LoopNumber % NumberOfParams;					//Determines which PC to change

			//-------STORE NEW PCS AS OLD--------
			for (a = 0; a < NumberOfParams; a++)
			{
				Old_PC[a] = New_PC[a];							//Store old PC values
			}

			//-------DRAW NEW PC IN NEW--------
			SigmaInflation = 1; 			// original old_PC is set at 1.2, all new PC set a 1
			
			sigma[Case] = SigmaInflation * SDpca[Case]; 

			New_PC[Case]=gsl_ran_gaussian (r, sigma[Case]);

			//-------RECONSTRUCT OLD AND NEW PCS TO PARAMS--------
			for (a = 0; a < NumberOfParams; a++)								
			{
				for (b = 0; b < NumberOfParams; b++)
				{
					Holder[b] = Coefficients[a * NumberOfParams + b];        
				}

				New_Params[a]=exp(DotProduct(ParCnt2, Holder, New_PC)*Scale[a]+Center[a]);            
				Old_Params[a]=exp(DotProduct(ParCnt2, Holder, Old_PC)*Scale[a]+Center[a]);       
			}
			//-------BOUND CHECK PARAMS-------- 
			while (New_Params[Case] < mcmc_bound(model, Case, 1) || New_Params[Case] > mcmc_bound(model, Case, 2))			//if CASE out of bounds
			{
				printf("BOUND ERROR param %i not in bounds\n", Case);
				printf("value = %lf\t lower bound = %lf\t upper bound = %lf\n",New_Params[Case], mcmc_bound(model, Case, 1), mcmc_bound(model, Case, 2));
				
				New_PC[Case] = gsl_ran_gaussian (r, sigma[Case]);			//draw new CASE

				for (a = 0; a < NumberOfParams; a++)			//reconstruct all
				{							
					for (b = 0; b < NumberOfParams; b++)
					{
						Holder[b] = Coefficients[a * NumberOfParams + b];         
					}
					New_Params[a] = exp(DotProduct(ParCnt2, Holder, New_PC) * Scale[a] + Center[a]);            
				}
			}

			//-------CALCULATE PRIORS--------
			log_prior_NEW = 0; log_prior_OLD = 0;
			log_prior_new = 0; log_prior_old = 0;
			for (a = 0; a < NumberOfParams; a++)
			{
				log_prior_new = log(gsl_ran_flat_pdf(New_Params[a], mcmc_bound(model, a, 1), (mcmc_bound(model, a, 2) + mcmc_bound(model, a, 1))));
				log_prior_old = log(gsl_ran_flat_pdf(Old_Params[a], mcmc_bound(model, a, 1), (mcmc_bound(model, a, 2) + mcmc_bound(model, a, 1))));
				
				//printf("a = %i\t logprior new = %lf\t log prior old = %lf\n", a, log_prior_new, log_prior_old);
				if (isinf(log_prior_new))
				{ 
					log_prior_new = -66666666666666;
				}
				if (isinf(log_prior_old))
				{
					log_prior_old = -66666666666666;
				}

				log_prior_OLD = log_prior_OLD + log_prior_old;
				log_prior_NEW = log_prior_NEW + log_prior_new;
				
			}
			for (a = 0; a < NumberOfParams; a++)

			//-------METROPOLIS SAMPLING STEP--------
			LogJumpToNew = -log(gsl_ran_gaussian_pdf(New_PC[Case], sigma[Case])); 
			LogJumpToOld = -log(gsl_ran_gaussian_pdf(Old_PC[Case], sigma[Case]));
			
			//-------CALCULATE LIKELIHOOD NEW PARAM SET--------
			//--------PASS FIXED PARAMS-------
			//INITV
			Params.FITINIT[1][4] 	= 	0.00000000000001; 		//META 1 SUB 1
			Params.FITINIT[1][5] 	= 	0.05; 					//META 1 SUB 2
			Params.FITINIT[1][6] 	= 	0.05;					//META 1 SUB 3
			Params.FITINIT[1][7] 	= 	0.00000000000001; 		//META 1 SUB 4
			Params.FITINIT[2][4] 	= 	0.00000000000001; 		//META 2 SUB 1
			Params.FITINIT[2][5] 	= 	0.05; 					//META 2 SUB 2
			Params.FITINIT[2][6] 	= 	0.05; 					//META 2 SUB 3
			Params.FITINIT[2][7] 	= 	0.00000000000001; 		//META 2 SUB 4
			Params.FITINIT[3][4] 	= 	0.00000000000001; 		//META 3 SUB 1
			Params.FITINIT[3][5] 	= 	0.05; 					//META 3 SUB 2
			Params.FITINIT[3][6] 	= 	0.05; 					//META 3 SUB 3
			Params.FITINIT[3][7] 	= 	0.00000000000001; 		//META 3 SUB 4
			//INITR
			Params.FITINIT[1][9] 	= 	0; 						//META 1 SUB 2
			Params.FITINIT[1][10] 	= 	0; 						//META 1 SUB 3
			Params.FITINIT[1][11] 	= 	0; 						//META 1 SUB 4
			Params.FITINIT[5][8] 	= 	0; 						//META 5
			//VIRUS DECAY
			Params.muV				= 	0.4102453; 				//POP
			//VIRUS HETERO		
			Params.CV				= 	0.86; 					//POP
			//VIRUS TRANS
			Params.nuV    			= 	0.4607038; 				//POP
			//FUNGUS TRANS
			Params.specific_nuF		= 	0.000241071699421562; 	//POP

			//--------PASS FIT PARAMS-------
			if(model==1) //R POP, C NA, L POP
			{
				//INITS
				Params.FITINIT[1][0] 	=	New_Params[0];		//META 1 SUB 1
				Params.FITINIT[1][1] 	=	New_Params[0];		//META 1 SUB 2
				Params.FITINIT[1][2] 	= 	New_Params[0]; 		//META 1 SUB 3
				Params.FITINIT[1][3] 	= 	New_Params[0]; 		//META 1 SUB 4
				Params.FITINIT[2][0] 	= 	New_Params[0]; 		//META 2 SUB 1
				Params.FITINIT[2][1] 	= 	New_Params[0];		//META 2 SUB 2
				Params.FITINIT[2][2] 	= 	New_Params[0];		//META 2 SUB 3
				Params.FITINIT[2][3] 	= 	New_Params[0];		//META 2 SUB 4
				Params.FITINIT[3][0] 	= 	New_Params[0]; 		//META 3 SUB 1
				Params.FITINIT[3][1]	= 	New_Params[0]; 		//META 3 SUB 2
				Params.FITINIT[3][2]	= 	New_Params[0];		//META 3 SUB 3
				Params.FITINIT[3][3]	= 	New_Params[0];		//META 3 SUB 4
				//INITR
				Params.r_pop 			= 	New_Params[1];		//POP
				//RSTOCH
				Params.R_stoch 			= 	New_Params[2];		//POP
				//FSTOCH										
				Params.F_stoch			= 	New_Params[3];		//POP
				//L DISP
				Params.l_a_pop 			=	New_Params[4];		//POP
				Params.l_m_pop 			= 	New_Params[5];		//POP
			}
			if(model==2) //R META, C NA, L POP
			{
				//INITS
				//---assign new parameter values---//
				Params.FITINIT[1][0] = New_Params[0];
				Params.FITINIT[1][1] = New_Params[0];
				Params.FITINIT[1][2] = New_Params[0]; 
				Params.FITINIT[1][3] = New_Params[0]; 
				Params.FITINIT[2][0] = New_Params[0]; 
				Params.FITINIT[2][1] = New_Params[0];
				Params.FITINIT[2][2] = New_Params[0];
				Params.FITINIT[2][3] = New_Params[0];
				Params.FITINIT[3][0] = New_Params[0]; 
				Params.FITINIT[3][1] = New_Params[0]; 
				Params.FITINIT[3][2] = New_Params[0];
				Params.FITINIT[3][3] = New_Params[0];
				//INIT R
				Params.r_meta[1] 		= 	New_Params[1];		//META 1
				Params.r_meta[2] 		= 	New_Params[2];		//META 2
				Params.r_meta[3] 		=	New_Params[3];		//META 3
				//RSTOCH
				Params.R_stoch 			= 	New_Params[4];		//POP
				//FSTOCH										
				Params.F_stoch			= 	New_Params[5];		//POP
				//L DISP
				Params.l_a_pop 			=	New_Params[6];		//POP
				Params.l_m_pop 			= 	New_Params[7];		//POP
			}
			if(model==4) //R POP, C NA, L META
			{
				//INITS
				Params.FITINIT[1][0] 	=	New_Params[0];		//META 1 SUB 1
				Params.FITINIT[1][1] 	=	New_Params[0];		//META 1 SUB 2
				Params.FITINIT[1][2] 	= 	New_Params[0]; 		//META 1 SUB 3
				Params.FITINIT[1][3] 	= 	New_Params[0]; 		//META 1 SUB 4
				Params.FITINIT[2][0] 	= 	New_Params[0]; 		//META 2 SUB 1
				Params.FITINIT[2][1] 	= 	New_Params[0];		//META 2 SUB 2
				Params.FITINIT[2][2] 	= 	New_Params[0];		//META 2 SUB 3
				Params.FITINIT[2][3] 	= 	New_Params[0];		//META 2 SUB 4
				Params.FITINIT[3][0] 	= 	New_Params[0]; 		//META 3 SUB 1
				Params.FITINIT[3][1]	= 	New_Params[0]; 		//META 3 SUB 2
				Params.FITINIT[3][2]	= 	New_Params[0];		//META 3 SUB 3
				Params.FITINIT[3][3]	= 	New_Params[0];		//META 3 SUB 4
				//INITR
				Params.r_pop 			= 	New_Params[1];		//POP
				//RSTOCH
				Params.R_stoch 			= 	New_Params[2];		//POP
				//FSTOCH										
				Params.F_stoch			= 	New_Params[3];		//POP
				//L DISP
				Params.l_a_meta[1] 		= 	New_Params[4];		//META 1
				Params.l_a_meta[2] 		= 	New_Params[5];		//META 2
				Params.l_a_meta[3] 		= 	New_Params[6];		//META 3
				Params.l_m_meta[1] 		= 	New_Params[7];		//META 1
				Params.l_m_meta[2] 		= 	New_Params[8];		//META 2
				Params.l_m_meta[3] 		= 	New_Params[9];		//META 3
			}
			if(model==22) //R POP, C META, L POP
			{
				//INITS
				Params.FITINIT[1][0] 	=	New_Params[0];		//META 1 SUB 1
				Params.FITINIT[1][1] 	=	New_Params[0];		//META 1 SUB 2
				Params.FITINIT[1][2] 	= 	New_Params[0]; 		//META 1 SUB 3
				Params.FITINIT[1][3] 	= 	New_Params[0]; 		//META 1 SUB 4
				Params.FITINIT[2][0] 	= 	New_Params[0]; 		//META 2 SUB 1
				Params.FITINIT[2][1] 	= 	New_Params[0];		//META 2 SUB 2
				Params.FITINIT[2][2] 	= 	New_Params[0];		//META 2 SUB 3
				Params.FITINIT[2][3] 	= 	New_Params[0];		//META 2 SUB 4
				Params.FITINIT[3][0] 	= 	New_Params[0]; 		//META 3 SUB 1
				Params.FITINIT[3][1]	= 	New_Params[0]; 		//META 3 SUB 2
				Params.FITINIT[3][2]	= 	New_Params[0];		//META 3 SUB 3
				Params.FITINIT[3][3]	= 	New_Params[0];		//META 3 SUB 4
				//INITR
				Params.r_pop 			= 	New_Params[1];		//POP
				//RSTOCH
				Params.R_stoch 			= 	New_Params[2];		//POP
				//FSTOCH										
				Params.F_stoch			= 	New_Params[3];		//POP
				//C DISP
				Params.c_a_meta[1] 		= 	New_Params[4];		//META 1
				Params.c_a_meta[2] 		= 	New_Params[5];		//META 2
				Params.c_a_meta[3] 		= 	New_Params[6];		//META 3
				Params.c_m_meta[1] 		= 	New_Params[7];		//META 1
				Params.c_m_meta[2] 		= 	New_Params[8];		//META 2
				Params.c_m_meta[3] 		= 	New_Params[9];		//META 3
				//L DISP
				Params.l_a_pop 			=	New_Params[10];		//POP
				Params.l_m_pop 			= 	New_Params[11];		//POP
			}
			if(model==28) //R POP, C POP, L META
			{
				//INITS
				Params.FITINIT[1][0] 	=	New_Params[0];		//META 1 SUB 1
				Params.FITINIT[1][1] 	=	New_Params[0];		//META 1 SUB 2
				Params.FITINIT[1][2] 	= 	New_Params[0]; 		//META 1 SUB 3
				Params.FITINIT[1][3] 	= 	New_Params[0]; 		//META 1 SUB 4
				Params.FITINIT[2][0] 	= 	New_Params[0]; 		//META 2 SUB 1
				Params.FITINIT[2][1] 	= 	New_Params[0];		//META 2 SUB 2
				Params.FITINIT[2][2] 	= 	New_Params[0];		//META 2 SUB 3
				Params.FITINIT[2][3] 	= 	New_Params[0];		//META 2 SUB 4
				Params.FITINIT[3][0] 	= 	New_Params[0]; 		//META 3 SUB 1
				Params.FITINIT[3][1]	= 	New_Params[0]; 		//META 3 SUB 2
				Params.FITINIT[3][2]	= 	New_Params[0];		//META 3 SUB 3
				Params.FITINIT[3][3]	= 	New_Params[0];		//META 3 SUB 4
				//INITR
				Params.r_pop 			= 	New_Params[1];		//POP
				//RSTOCH
				Params.R_stoch 			= 	New_Params[2];		//POP
				//FSTOCH										
				Params.F_stoch			= 	New_Params[3];		//POP
				//C DISP
				Params.c_a_pop 			=	New_Params[4];		//POP
				Params.c_m_pop 			= 	New_Params[5];		//POP
				//L DISP
				Params.l_a_meta[1] 		= 	New_Params[6];		//META 1
				Params.l_a_meta[2] 		= 	New_Params[7];		//META 2
				Params.l_a_meta[3] 		= 	New_Params[8];		//META 3
				Params.l_m_meta[1] 		= 	New_Params[9];		//META 1
				Params.l_m_meta[2] 		= 	New_Params[10];		//META 2
				Params.l_m_meta[3] 		= 	New_Params[11];		//META 3
			}
			if(model==32) //R META, C META, L META
			{
				//INITS
				Params.FITINIT[1][0] 	=	New_Params[0];		//META 1 SUB 1
				Params.FITINIT[1][1] 	=	New_Params[0];		//META 1 SUB 2
				Params.FITINIT[1][2] 	= 	New_Params[0]; 		//META 1 SUB 3
				Params.FITINIT[1][3] 	= 	New_Params[0]; 		//META 1 SUB 4
				Params.FITINIT[2][0] 	= 	New_Params[0]; 		//META 2 SUB 1
				Params.FITINIT[2][1] 	= 	New_Params[0];		//META 2 SUB 2
				Params.FITINIT[2][2] 	= 	New_Params[0];		//META 2 SUB 3
				Params.FITINIT[2][3] 	= 	New_Params[0];		//META 2 SUB 4
				Params.FITINIT[3][0] 	= 	New_Params[0]; 		//META 3 SUB 1
				Params.FITINIT[3][1]	= 	New_Params[0]; 		//META 3 SUB 2
				Params.FITINIT[3][2]	= 	New_Params[0];		//META 3 SUB 3
				Params.FITINIT[3][3]	= 	New_Params[0];		//META 3 SUB 4
				//INIT R
				Params.r_meta[1] 		= 	New_Params[1];		//META 1
				Params.r_meta[2] 		= 	New_Params[2];		//META 2
				Params.r_meta[3] 		=	New_Params[3];		//META 3
				//RSTOCH
				Params.R_stoch 			= 	New_Params[4];		//POP
				//FSTOCH										
				Params.F_stoch			= 	New_Params[5];		//POP
				//C DISP
				Params.c_a_meta[1] 		= 	New_Params[6];		//META 1
				Params.c_a_meta[2] 		= 	New_Params[7];		//META 2
				Params.c_a_meta[3] 		= 	New_Params[8];		//META 3
				Params.c_m_meta[1] 		= 	New_Params[9];		//META 1
				Params.c_m_meta[2] 		= 	New_Params[10];		//META 2
				Params.c_m_meta[3] 		= 	New_Params[11];		//META 3
				//L DISP
				Params.l_a_meta[1] 		= 	New_Params[12];		//META 1
				Params.l_a_meta[2] 		= 	New_Params[13];		//META 2
				Params.l_a_meta[3] 		= 	New_Params[14];		//META 3
				Params.l_m_meta[1] 		= 	New_Params[15];		//META 1
				Params.l_m_meta[2] 		= 	New_Params[16];		//META 2
				Params.l_m_meta[3] 		= 	New_Params[17];		//META 3
			}

			lhood_meta = 0; log_lhood_meta = 0; total_loghood_metas_NEW = 0;
			meta_err = 0;

			for (int j = 1; j <= 3; j++)
			{ 

				Params.miser_ticker = 1; Params.miser2_flag = 0; 
				
				Params.j = j;

				gsl_monte_function G = { &likelihood_calc, dim, &Params };	

				double xl[dim];	double xu[dim];	
				for (int jj = 0; jj < dim; jj++)
				{
					xl[jj] = 0;	
					xu[jj] = 1;
				}

				gsl_monte_miser_state *s = gsl_monte_miser_alloc(dim);
				gsl_monte_miser_integrate (&G, xl, xu, dim, Mcalls, r_seed, s, &lhood_meta, &meta_err); 
				gsl_monte_miser_free(s);
				
				while (Params.miser2_flag > 0)
				{ 
					Params.miser2_flag = 0;
					Params.lhood_adjust[j] = -Params.bestlhood[j];
					
					gsl_monte_miser_state *s = gsl_monte_miser_alloc(dim);
					gsl_monte_miser_integrate (&G, xl, xu, dim, Mcalls, r_seed, s, &lhood_meta, &meta_err); 
					gsl_monte_miser_free(s);
				}
				
				log_lhood_meta = log(lhood_meta) - Params.lhood_adjust[j];
				if (isnan(log_lhood_meta) || isinf(log_lhood_meta))
				{ 
					log_lhood_meta = -100000000000000;
				}

				total_loghood_metas_NEW = total_loghood_metas_NEW + log_lhood_meta;
				LogNewPosterior = 0.0;
				LogNewPosterior = total_loghood_metas_NEW + log_prior_NEW;
			}
			//printf("MCMC PASS 1\n");
			//printf("loghood metas = %lf\n", total_loghood_metas_NEW);
			//printf("prior = %lf\n", log_prior_NEW);
			//printf("new_posterior = %lf\n", LogNewPosterior);

			//-------CALCULATE LIKELIHOOD NEW PARAM SET--------
			//--------PASS FIXED PARAMS-------
			//INITV
			Params.FITINIT[1][4] 	= 	0.00000000000001; 		//META 1 SUB 1
			Params.FITINIT[1][5] 	= 	0.05; 					//META 1 SUB 2
			Params.FITINIT[1][6] 	= 	0.05;					//META 1 SUB 3
			Params.FITINIT[1][7] 	= 	0.00000000000001; 		//META 1 SUB 4
			Params.FITINIT[2][4] 	= 	0.00000000000001; 		//META 2 SUB 1
			Params.FITINIT[2][5] 	= 	0.05; 					//META 2 SUB 2
			Params.FITINIT[2][6] 	= 	0.05; 					//META 2 SUB 3
			Params.FITINIT[2][7] 	= 	0.00000000000001; 		//META 2 SUB 4
			Params.FITINIT[3][4] 	= 	0.00000000000001; 		//META 3 SUB 1
			Params.FITINIT[3][5] 	= 	0.05; 					//META 3 SUB 2
			Params.FITINIT[3][6] 	= 	0.05; 					//META 3 SUB 3
			Params.FITINIT[3][7] 	= 	0.00000000000001; 		//META 3 SUB 4
			//INITR
			Params.FITINIT[1][9] 	= 	0; 						//META 1 SUB 2
			Params.FITINIT[1][10] 	= 	0; 						//META 1 SUB 3
			Params.FITINIT[1][11] 	= 	0; 						//META 1 SUB 4
			Params.FITINIT[5][8] 	= 	0; 						//META 5
			//VIRUS DECAY
			Params.muV				= 	0.4102453; 				//POP
			//VIRUS HETERO		
			Params.CV				= 	0.86; 					//POP
			//VIRUS TRANS
			Params.nuV    			= 	0.4607038; 				//POP
			//FUNGUS TRANS
			Params.specific_nuF		= 	0.000241071699421562; 	//POP

			//--------PASS FIT PARAMS-------
			if(model==1) //R POP, C NA, L POP
			{
				//INITS
				Params.FITINIT[1][0] 	=	Old_Params[0];		//META 1 SUB 1
				Params.FITINIT[1][1] 	=	Old_Params[0];		//META 1 SUB 2
				Params.FITINIT[1][2] 	= 	Old_Params[0]; 		//META 1 SUB 3
				Params.FITINIT[1][3] 	= 	Old_Params[0]; 		//META 1 SUB 4
				Params.FITINIT[2][0] 	= 	Old_Params[0]; 		//META 2 SUB 1
				Params.FITINIT[2][1] 	= 	Old_Params[0];		//META 2 SUB 2
				Params.FITINIT[2][2] 	= 	Old_Params[0];		//META 2 SUB 3
				Params.FITINIT[2][3] 	= 	Old_Params[0];		//META 2 SUB 4
				Params.FITINIT[3][0] 	= 	Old_Params[0]; 		//META 3 SUB 1
				Params.FITINIT[3][1]	= 	Old_Params[0]; 		//META 3 SUB 2
				Params.FITINIT[3][2]	= 	Old_Params[0];		//META 3 SUB 3
				Params.FITINIT[3][3]	= 	Old_Params[0];		//META 3 SUB 4
				//INITR
				Params.r_pop 			= 	Old_Params[1];		//POP
				//RSTOCH
				Params.R_stoch 			= 	Old_Params[2];		//POP
				//FSTOCH										
				Params.F_stoch			= 	Old_Params[3];		//POP
				//L DISP
				Params.l_a_pop 			=	Old_Params[4];		//POP
				Params.l_m_pop 			= 	Old_Params[5];		//POP
			}
			if(model==2) //R META, C NA, L POP
			{
				//INITS
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
				//INIT R
				Params.r_meta[1] 		= 	Old_Params[1];		//META 1
				Params.r_meta[2] 		= 	Old_Params[2];		//META 2
				Params.r_meta[3] 		=	Old_Params[3];		//META 3
				//RSTOCH
				Params.R_stoch 			= 	Old_Params[4];		//POP
				//FSTOCH										
				Params.F_stoch			= 	Old_Params[5];		//POP
				//L DISP
				Params.l_a_pop 			=	Old_Params[6];		//POP
				Params.l_m_pop 			= 	Old_Params[7];		//POP
			}
			if(model==4) //R POP, C NA, L META
			{
				//INITS
				Params.FITINIT[1][0] 	=	Old_Params[0];		//META 1 SUB 1
				Params.FITINIT[1][1] 	=	Old_Params[0];		//META 1 SUB 2
				Params.FITINIT[1][2] 	= 	Old_Params[0]; 		//META 1 SUB 3
				Params.FITINIT[1][3] 	= 	Old_Params[0]; 		//META 1 SUB 4
				Params.FITINIT[2][0] 	= 	Old_Params[0]; 		//META 2 SUB 1
				Params.FITINIT[2][1] 	= 	Old_Params[0];		//META 2 SUB 2
				Params.FITINIT[2][2] 	= 	Old_Params[0];		//META 2 SUB 3
				Params.FITINIT[2][3] 	= 	Old_Params[0];		//META 2 SUB 4
				Params.FITINIT[3][0] 	= 	Old_Params[0]; 		//META 3 SUB 1
				Params.FITINIT[3][1]	= 	Old_Params[0]; 		//META 3 SUB 2
				Params.FITINIT[3][2]	= 	Old_Params[0];		//META 3 SUB 3
				Params.FITINIT[3][3]	= 	Old_Params[0];		//META 3 SUB 4
				//INITR
				Params.r_pop 			= 	Old_Params[1];		//POP
				//RSTOCH
				Params.R_stoch 			= 	Old_Params[2];		//POP
				//FSTOCH										
				Params.F_stoch			= 	Old_Params[3];		//POP
				//L DISP
				Params.l_a_meta[1] 		= 	Old_Params[4];		//META 1
				Params.l_a_meta[2] 		= 	Old_Params[5];		//META 2
				Params.l_a_meta[3] 		= 	Old_Params[6];		//META 3
				Params.l_m_meta[1] 		= 	Old_Params[7];		//META 1
				Params.l_m_meta[2] 		= 	Old_Params[8];		//META 2
				Params.l_m_meta[3] 		= 	Old_Params[9];		//META 3
			}
			if(model==22) //R POP, C META, L POP
			{
				//INITS
				Params.FITINIT[1][0] 	=	Old_Params[0];		//META 1 SUB 1
				Params.FITINIT[1][1] 	=	Old_Params[0];		//META 1 SUB 2
				Params.FITINIT[1][2] 	= 	Old_Params[0]; 		//META 1 SUB 3
				Params.FITINIT[1][3] 	= 	Old_Params[0]; 		//META 1 SUB 4
				Params.FITINIT[2][0] 	= 	Old_Params[0]; 		//META 2 SUB 1
				Params.FITINIT[2][1] 	= 	Old_Params[0];		//META 2 SUB 2
				Params.FITINIT[2][2] 	= 	Old_Params[0];		//META 2 SUB 3
				Params.FITINIT[2][3] 	= 	Old_Params[0];		//META 2 SUB 4
				Params.FITINIT[3][0] 	= 	Old_Params[0]; 		//META 3 SUB 1
				Params.FITINIT[3][1]	= 	Old_Params[0]; 		//META 3 SUB 2
				Params.FITINIT[3][2]	= 	Old_Params[0];		//META 3 SUB 3
				Params.FITINIT[3][3]	= 	Old_Params[0];		//META 3 SUB 4
				//INITR
				Params.r_pop 			= 	Old_Params[1];		//POP
				//RSTOCH
				Params.R_stoch 			= 	Old_Params[2];		//POP
				//FSTOCH										
				Params.F_stoch			= 	Old_Params[3];		//POP
				//C DISP
				Params.c_a_meta[1] 		= 	Old_Params[4];		//META 1
				Params.c_a_meta[2] 		= 	Old_Params[5];		//META 2
				Params.c_a_meta[3] 		= 	Old_Params[6];		//META 3
				Params.c_m_meta[1] 		= 	Old_Params[7];		//META 1
				Params.c_m_meta[2] 		= 	Old_Params[8];		//META 2
				Params.c_m_meta[3] 		= 	Old_Params[9];		//META 3
				//L DISP
				Params.l_a_pop 			=	Old_Params[10];		//POP
				Params.l_m_pop 			= 	Old_Params[11];		//POP
			}
			if(model==28) //R POP, C POP, L META
			{
				//INITS
				Params.FITINIT[1][0] 	=	Old_Params[0];		//META 1 SUB 1
				Params.FITINIT[1][1] 	=	Old_Params[0];		//META 1 SUB 2
				Params.FITINIT[1][2] 	= 	Old_Params[0]; 		//META 1 SUB 3
				Params.FITINIT[1][3] 	= 	Old_Params[0]; 		//META 1 SUB 4
				Params.FITINIT[2][0] 	= 	Old_Params[0]; 		//META 2 SUB 1
				Params.FITINIT[2][1] 	= 	Old_Params[0];		//META 2 SUB 2
				Params.FITINIT[2][2] 	= 	Old_Params[0];		//META 2 SUB 3
				Params.FITINIT[2][3] 	= 	Old_Params[0];		//META 2 SUB 4
				Params.FITINIT[3][0] 	= 	Old_Params[0]; 		//META 3 SUB 1
				Params.FITINIT[3][1]	= 	Old_Params[0]; 		//META 3 SUB 2
				Params.FITINIT[3][2]	= 	Old_Params[0];		//META 3 SUB 3
				Params.FITINIT[3][3]	= 	Old_Params[0];		//META 3 SUB 4
				//INITR
				Params.r_pop 			= 	Old_Params[1];		//POP
				//RSTOCH
				Params.R_stoch 			= 	Old_Params[2];		//POP
				//FSTOCH										
				Params.F_stoch			= 	Old_Params[3];		//POP
				//C DISP
				Params.c_a_pop 			=	Old_Params[4];		//POP
				Params.c_m_pop 			= 	Old_Params[5];		//POP
				//L DISP
				Params.l_a_meta[1] 		= 	Old_Params[6];		//META 1
				Params.l_a_meta[2] 		= 	Old_Params[7];		//META 2
				Params.l_a_meta[3] 		= 	Old_Params[8];		//META 3
				Params.l_m_meta[1] 		= 	Old_Params[9];		//META 1
				Params.l_m_meta[2] 		= 	Old_Params[10];		//META 2
				Params.l_m_meta[3] 		= 	Old_Params[11];		//META 3
			}
			if(model==32) //R META, C META, L META
			{
				//INITS
				Params.FITINIT[1][0] 	=	Old_Params[0];		//META 1 SUB 1
				Params.FITINIT[1][1] 	=	Old_Params[0];		//META 1 SUB 2
				Params.FITINIT[1][2] 	= 	Old_Params[0]; 		//META 1 SUB 3
				Params.FITINIT[1][3] 	= 	Old_Params[0]; 		//META 1 SUB 4
				Params.FITINIT[2][0] 	= 	Old_Params[0]; 		//META 2 SUB 1
				Params.FITINIT[2][1] 	= 	Old_Params[0];		//META 2 SUB 2
				Params.FITINIT[2][2] 	= 	Old_Params[0];		//META 2 SUB 3
				Params.FITINIT[2][3] 	= 	Old_Params[0];		//META 2 SUB 4
				Params.FITINIT[3][0] 	= 	Old_Params[0]; 		//META 3 SUB 1
				Params.FITINIT[3][1]	= 	Old_Params[0]; 		//META 3 SUB 2
				Params.FITINIT[3][2]	= 	Old_Params[0];		//META 3 SUB 3
				Params.FITINIT[3][3]	= 	Old_Params[0];		//META 3 SUB 4
				//INIT R
				Params.r_meta[1] 		= 	Old_Params[1];		//META 1
				Params.r_meta[2] 		= 	Old_Params[2];		//META 2
				Params.r_meta[3] 		=	Old_Params[3];		//META 3
				//RSTOCH
				Params.R_stoch 			= 	Old_Params[4];		//POP
				//FSTOCH										
				Params.F_stoch			= 	Old_Params[5];		//POP
				//C DISP
				Params.c_a_meta[1] 		= 	Old_Params[6];		//META 1
				Params.c_a_meta[2] 		= 	Old_Params[7];		//META 2
				Params.c_a_meta[3] 		= 	Old_Params[8];		//META 3
				Params.c_m_meta[1] 		= 	Old_Params[9];		//META 1
				Params.c_m_meta[2] 		= 	Old_Params[10];		//META 2
				Params.c_m_meta[3] 		= 	Old_Params[11];		//META 3
				//L DISP
				Params.l_a_meta[1] 		= 	Old_Params[12];		//META 1
				Params.l_a_meta[2] 		= 	Old_Params[13];		//META 2
				Params.l_a_meta[3] 		= 	Old_Params[14];		//META 3
				Params.l_m_meta[1] 		= 	Old_Params[15];		//META 1
				Params.l_m_meta[2] 		= 	Old_Params[16];		//META 2
				Params.l_m_meta[3] 		= 	Old_Params[17];		//META 3
			}
				
				lhood_meta = 0; log_lhood_meta = 0; total_loghood_metas_OLD = 0;
				meta_err = 0;

				for (int j = 1; j <= 3; j++)
				{

					Params.miser_ticker = 1; Params.miser2_flag = 0; 
					
					Params.j = j;

					gsl_monte_function G = { &likelihood_calc, dim, &Params };	

					double xl[dim];	double xu[dim];	
					for (int jj = 0; jj < dim; jj++)
					{
						xl[jj] = 0;	
						xu[jj] = 1;
					}

					gsl_monte_miser_state *s = gsl_monte_miser_alloc(dim);
					gsl_monte_miser_integrate (&G, xl, xu, dim, Mcalls, r_seed, s, &lhood_meta, &meta_err); 
					gsl_monte_miser_free(s);
					
					while (Params.miser2_flag > 0)
					{ 
						Params.miser2_flag = 0;
						Params.lhood_adjust[j] = -Params.bestlhood[j];
						
						gsl_monte_miser_state *s = gsl_monte_miser_alloc(dim);
						gsl_monte_miser_integrate (&G, xl, xu, dim, Mcalls, r_seed, s, &lhood_meta, &meta_err);
						gsl_monte_miser_free(s);
					}
					
					log_lhood_meta = log(lhood_meta) - Params.lhood_adjust[j];

					if (isnan(log_lhood_meta) || isinf(log_lhood_meta))
					{ 
						log_lhood_meta = -100000000000000;
					}

					total_loghood_metas_OLD = total_loghood_metas_OLD + log_lhood_meta;
					LogOldPosterior = 0.0;
					LogOldPosterior = total_loghood_metas_OLD + log_prior_OLD;

				}
				//printf("MCMC PASS OLD\n");
				//printf("loghood metas = %lf\n", total_loghood_metas_OLD);
				//printf("prior = %lf\n", log_prior_OLD);
				//printf("new_posterior = %lf\n", LogOldPosterior);

				if (LogOldPosterior > -1000000)
				{ 
					PreviousLogOldPosterior = LogOldPosterior;
				}
				if (LogOldPosterior < -10000000 & LoopNumber > 10)
				{
					//printf("BUM POSTERIOR! assigning previous old \n");
					//getc(stdin);
					//printf("log old posterior = %lf\n", LogOldPosterior);
					LogOldPosterior = PreviousLogOldPosterior; //wash due to weird stochasticity, assign previous value
						//printf("previous old = %lf\n", PreviousLogOldPosterior);
					//getc(stdin);
				}
				//printf("log old posterior = %lf\n", LogOldPosterior);

			//--------EVALUTE NEW VERSUS OLD-------
			ProbOfAcceptance = exp((LogNewPosterior + LogJumpToOld) - (LogOldPosterior - LogJumpToNew));   

			if (isinf(ProbOfAcceptance))
			{
				ProbOfAcceptance=1;
			}
			Attempt = Attempt + 1;

			//--------IF NEW IS BETTER THAN OLD-------
			if (ProbOfAcceptance>1 || gsl_rng_uniform_pos (r) < ProbOfAcceptance)
			{ 
				//--------AVOID WINNERS CURSE BY RECALCULATING NEW-------
				//--------PASS FIXED PARAMS-------
				//INITV
				Params.FITINIT[1][4] 	= 	0.00000000000001; 		//META 1 SUB 1
				Params.FITINIT[1][5] 	= 	0.05; 					//META 1 SUB 2
				Params.FITINIT[1][6] 	= 	0.05;					//META 1 SUB 3
				Params.FITINIT[1][7] 	= 	0.00000000000001; 		//META 1 SUB 4
				Params.FITINIT[2][4] 	= 	0.00000000000001; 		//META 2 SUB 1
				Params.FITINIT[2][5] 	= 	0.05; 					//META 2 SUB 2
				Params.FITINIT[2][6] 	= 	0.05; 					//META 2 SUB 3
				Params.FITINIT[2][7] 	= 	0.00000000000001; 		//META 2 SUB 4
				Params.FITINIT[3][4] 	= 	0.00000000000001; 		//META 3 SUB 1
				Params.FITINIT[3][5] 	= 	0.05; 					//META 3 SUB 2
				Params.FITINIT[3][6] 	= 	0.05; 					//META 3 SUB 3
				Params.FITINIT[3][7] 	= 	0.00000000000001; 		//META 3 SUB 4
				//INITR
				Params.FITINIT[1][9] 	= 	0; 						//META 1 SUB 2
				Params.FITINIT[1][10] 	= 	0; 						//META 1 SUB 3
				Params.FITINIT[1][11] 	= 	0; 						//META 1 SUB 4
				Params.FITINIT[5][8] 	= 	0; 						//META 5
				//VIRUS DECAY
				Params.muV				= 	0.4102453; 				//POP
				//VIRUS HETERO		
				Params.CV				= 	0.86; 					//POP
				//VIRUS TRANS
				Params.nuV    			= 	0.4607038; 				//POP
				//FUNGUS TRANS
				Params.specific_nuF		= 	0.000241071699421562; 	//POP

				//--------PASS FIT PARAMS-------
				if(model==1) //R POP, C NA, L POP
				{
					//INITS
					Params.FITINIT[1][0] 	=	New_Params[0];		//META 1 SUB 1
					Params.FITINIT[1][1] 	=	New_Params[0];		//META 1 SUB 2
					Params.FITINIT[1][2] 	= 	New_Params[0]; 		//META 1 SUB 3
					Params.FITINIT[1][3] 	= 	New_Params[0]; 		//META 1 SUB 4
					Params.FITINIT[2][0] 	= 	New_Params[0]; 		//META 2 SUB 1
					Params.FITINIT[2][1] 	= 	New_Params[0];		//META 2 SUB 2
					Params.FITINIT[2][2] 	= 	New_Params[0];		//META 2 SUB 3
					Params.FITINIT[2][3] 	= 	New_Params[0];		//META 2 SUB 4
					Params.FITINIT[3][0] 	= 	New_Params[0]; 		//META 3 SUB 1
					Params.FITINIT[3][1]	= 	New_Params[0]; 		//META 3 SUB 2
					Params.FITINIT[3][2]	= 	New_Params[0];		//META 3 SUB 3
					Params.FITINIT[3][3]	= 	New_Params[0];		//META 3 SUB 4
					//INITR
					Params.r_pop 			= 	New_Params[1];		//POP
					//RSTOCH
					Params.R_stoch 			= 	New_Params[2];		//POP
					//FSTOCH										
					Params.F_stoch			= 	New_Params[3];		//POP
					//L DISP
					Params.l_a_pop 			=	New_Params[4];		//POP
					Params.l_m_pop 			= 	New_Params[5];		//POP
				}
				if(model==2) //R META, C NA, L POP
				{
					//INITS
					//---assign new parameter values---//
					Params.FITINIT[1][0] = New_Params[0];
					Params.FITINIT[1][1] = New_Params[0];
					Params.FITINIT[1][2] = New_Params[0]; 
					Params.FITINIT[1][3] = New_Params[0]; 
					Params.FITINIT[2][0] = New_Params[0]; 
					Params.FITINIT[2][1] = New_Params[0];
					Params.FITINIT[2][2] = New_Params[0];
					Params.FITINIT[2][3] = New_Params[0];
					Params.FITINIT[3][0] = New_Params[0]; 
					Params.FITINIT[3][1] = New_Params[0]; 
					Params.FITINIT[3][2] = New_Params[0];
					Params.FITINIT[3][3] = New_Params[0];
					//INIT R
					Params.r_meta[1] 		= 	New_Params[1];		//META 1
					Params.r_meta[2] 		= 	New_Params[2];		//META 2
					Params.r_meta[3] 		=	New_Params[3];		//META 3
					//RSTOCH
					Params.R_stoch 			= 	New_Params[4];		//POP
					//FSTOCH										
					Params.F_stoch			= 	New_Params[5];		//POP
					//L DISP
					Params.l_a_pop 			=	New_Params[6];		//POP
					Params.l_m_pop 			= 	New_Params[7];		//POP
				}
				if(model==4) //R POP, C NA, L META
				{
					//INITS
					Params.FITINIT[1][0] 	=	New_Params[0];		//META 1 SUB 1
					Params.FITINIT[1][1] 	=	New_Params[0];		//META 1 SUB 2
					Params.FITINIT[1][2] 	= 	New_Params[0]; 		//META 1 SUB 3
					Params.FITINIT[1][3] 	= 	New_Params[0]; 		//META 1 SUB 4
					Params.FITINIT[2][0] 	= 	New_Params[0]; 		//META 2 SUB 1
					Params.FITINIT[2][1] 	= 	New_Params[0];		//META 2 SUB 2
					Params.FITINIT[2][2] 	= 	New_Params[0];		//META 2 SUB 3
					Params.FITINIT[2][3] 	= 	New_Params[0];		//META 2 SUB 4
					Params.FITINIT[3][0] 	= 	New_Params[0]; 		//META 3 SUB 1
					Params.FITINIT[3][1]	= 	New_Params[0]; 		//META 3 SUB 2
					Params.FITINIT[3][2]	= 	New_Params[0];		//META 3 SUB 3
					Params.FITINIT[3][3]	= 	New_Params[0];		//META 3 SUB 4
					//INITR
					Params.r_pop 			= 	New_Params[1];		//POP
					//RSTOCH
					Params.R_stoch 			= 	New_Params[2];		//POP
					//FSTOCH										
					Params.F_stoch			= 	New_Params[3];		//POP
					//L DISP
					Params.l_a_meta[1] 		= 	New_Params[4];		//META 1
					Params.l_a_meta[2] 		= 	New_Params[5];		//META 2
					Params.l_a_meta[3] 		= 	New_Params[6];		//META 3
					Params.l_m_meta[1] 		= 	New_Params[7];		//META 1
					Params.l_m_meta[2] 		= 	New_Params[8];		//META 2
					Params.l_m_meta[3] 		= 	New_Params[9];		//META 3
				}
				if(model==22) //R POP, C META, L POP
				{
					//INITS
					Params.FITINIT[1][0] 	=	New_Params[0];		//META 1 SUB 1
					Params.FITINIT[1][1] 	=	New_Params[0];		//META 1 SUB 2
					Params.FITINIT[1][2] 	= 	New_Params[0]; 		//META 1 SUB 3
					Params.FITINIT[1][3] 	= 	New_Params[0]; 		//META 1 SUB 4
					Params.FITINIT[2][0] 	= 	New_Params[0]; 		//META 2 SUB 1
					Params.FITINIT[2][1] 	= 	New_Params[0];		//META 2 SUB 2
					Params.FITINIT[2][2] 	= 	New_Params[0];		//META 2 SUB 3
					Params.FITINIT[2][3] 	= 	New_Params[0];		//META 2 SUB 4
					Params.FITINIT[3][0] 	= 	New_Params[0]; 		//META 3 SUB 1
					Params.FITINIT[3][1]	= 	New_Params[0]; 		//META 3 SUB 2
					Params.FITINIT[3][2]	= 	New_Params[0];		//META 3 SUB 3
					Params.FITINIT[3][3]	= 	New_Params[0];		//META 3 SUB 4
					//INITR
					Params.r_pop 			= 	New_Params[1];		//POP
					//RSTOCH
					Params.R_stoch 			= 	New_Params[2];		//POP
					//FSTOCH										
					Params.F_stoch			= 	New_Params[3];		//POP
					//C DISP
					Params.c_a_meta[1] 		= 	New_Params[4];		//META 1
					Params.c_a_meta[2] 		= 	New_Params[5];		//META 2
					Params.c_a_meta[3] 		= 	New_Params[6];		//META 3
					Params.c_m_meta[1] 		= 	New_Params[7];		//META 1
					Params.c_m_meta[2] 		= 	New_Params[8];		//META 2
					Params.c_m_meta[3] 		= 	New_Params[9];		//META 3
					//L DISP
					Params.l_a_pop 			=	New_Params[10];		//POP
					Params.l_m_pop 			= 	New_Params[11];		//POP
				}
				if(model==28) //R POP, C POP, L META
				{
					//INITS
					Params.FITINIT[1][0] 	=	New_Params[0];		//META 1 SUB 1
					Params.FITINIT[1][1] 	=	New_Params[0];		//META 1 SUB 2
					Params.FITINIT[1][2] 	= 	New_Params[0]; 		//META 1 SUB 3
					Params.FITINIT[1][3] 	= 	New_Params[0]; 		//META 1 SUB 4
					Params.FITINIT[2][0] 	= 	New_Params[0]; 		//META 2 SUB 1
					Params.FITINIT[2][1] 	= 	New_Params[0];		//META 2 SUB 2
					Params.FITINIT[2][2] 	= 	New_Params[0];		//META 2 SUB 3
					Params.FITINIT[2][3] 	= 	New_Params[0];		//META 2 SUB 4
					Params.FITINIT[3][0] 	= 	New_Params[0]; 		//META 3 SUB 1
					Params.FITINIT[3][1]	= 	New_Params[0]; 		//META 3 SUB 2
					Params.FITINIT[3][2]	= 	New_Params[0];		//META 3 SUB 3
					Params.FITINIT[3][3]	= 	New_Params[0];		//META 3 SUB 4
					//INITR
					Params.r_pop 			= 	New_Params[1];		//POP
					//RSTOCH
					Params.R_stoch 			= 	New_Params[2];		//POP
					//FSTOCH										
					Params.F_stoch			= 	New_Params[3];		//POP
					//C DISP
					Params.c_a_pop 			=	New_Params[4];		//POP
					Params.c_m_pop 			= 	New_Params[5];		//POP
					//L DISP
					Params.l_a_meta[1] 		= 	New_Params[6];		//META 1
					Params.l_a_meta[2] 		= 	New_Params[7];		//META 2
					Params.l_a_meta[3] 		= 	New_Params[8];		//META 3
					Params.l_m_meta[1] 		= 	New_Params[9];		//META 1
					Params.l_m_meta[2] 		= 	New_Params[10];		//META 2
					Params.l_m_meta[3] 		= 	New_Params[11];		//META 3
				}
				if(model==32) //R META, C META, L META
				{
					//INITS
					Params.FITINIT[1][0] 	=	New_Params[0];		//META 1 SUB 1
					Params.FITINIT[1][1] 	=	New_Params[0];		//META 1 SUB 2
					Params.FITINIT[1][2] 	= 	New_Params[0]; 		//META 1 SUB 3
					Params.FITINIT[1][3] 	= 	New_Params[0]; 		//META 1 SUB 4
					Params.FITINIT[2][0] 	= 	New_Params[0]; 		//META 2 SUB 1
					Params.FITINIT[2][1] 	= 	New_Params[0];		//META 2 SUB 2
					Params.FITINIT[2][2] 	= 	New_Params[0];		//META 2 SUB 3
					Params.FITINIT[2][3] 	= 	New_Params[0];		//META 2 SUB 4
					Params.FITINIT[3][0] 	= 	New_Params[0]; 		//META 3 SUB 1
					Params.FITINIT[3][1]	= 	New_Params[0]; 		//META 3 SUB 2
					Params.FITINIT[3][2]	= 	New_Params[0];		//META 3 SUB 3
					Params.FITINIT[3][3]	= 	New_Params[0];		//META 3 SUB 4
					//INIT R
					Params.r_meta[1] 		= 	New_Params[1];		//META 1
					Params.r_meta[2] 		= 	New_Params[2];		//META 2
					Params.r_meta[3] 		=	New_Params[3];		//META 3
					//RSTOCH
					Params.R_stoch 			= 	New_Params[4];		//POP
					//FSTOCH										
					Params.F_stoch			= 	New_Params[5];		//POP
					//C DISP
					Params.c_a_meta[1] 		= 	New_Params[6];		//META 1
					Params.c_a_meta[2] 		= 	New_Params[7];		//META 2
					Params.c_a_meta[3] 		= 	New_Params[8];		//META 3
					Params.c_m_meta[1] 		= 	New_Params[9];		//META 1
					Params.c_m_meta[2] 		= 	New_Params[10];		//META 2
					Params.c_m_meta[3] 		= 	New_Params[11];		//META 3
					//L DISP
					Params.l_a_meta[1] 		= 	New_Params[12];		//META 1
					Params.l_a_meta[2] 		= 	New_Params[13];		//META 2
					Params.l_a_meta[3] 		= 	New_Params[14];		//META 3
					Params.l_m_meta[1] 		= 	New_Params[15];		//META 1
					Params.l_m_meta[2] 		= 	New_Params[16];		//META 2
					Params.l_m_meta[3] 		= 	New_Params[17];		//META 3
				}
				
				lhood_meta = 0; log_lhood_meta = 0; total_loghood_metas_NEW = 0;
				meta_err = 0;

				for (int j = 1; j <= 3; j++)
				{

					Params.miser_ticker = 1; Params.miser2_flag = 0; 
					
					Params.j = j;

					gsl_monte_function G = { &likelihood_calc, dim, &Params };

					double xl[dim];	double xu[dim];
					for (int jj = 0; jj < dim; jj++)
					{
						xl[jj] = 0;	
						xu[jj] = 1;
					}

					gsl_monte_miser_state *s = gsl_monte_miser_alloc(dim);
					gsl_monte_miser_integrate (&G, xl, xu, dim, Mcalls, r_seed, s, &lhood_meta, &meta_err);
					gsl_monte_miser_free(s);
					
					while (Params.miser2_flag > 0)
					{ 
						Params.miser2_flag = 0;
						Params.lhood_adjust[j] = -Params.bestlhood[j];
						
						gsl_monte_miser_state *s = gsl_monte_miser_alloc(dim);
						gsl_monte_miser_integrate (&G, xl, xu, dim, Mcalls, r_seed, s, &lhood_meta, &meta_err); 
						gsl_monte_miser_free(s);
					}
					
					log_lhood_meta = log(lhood_meta) - Params.lhood_adjust[j];

					if (isnan(log_lhood_meta) || isinf(log_lhood_meta)){ 
						log_lhood_meta = -100000000000000;
					}

					total_loghood_metas_NEW = total_loghood_metas_NEW + log_lhood_meta;
					LogNewPosterior = 0.0;
					LogNewPosterior = total_loghood_metas_NEW + log_prior_NEW;
				}
				//printf("MCMC PASS NEW 2\n");
				//printf("loghood metas = %lf\n", total_loghood_metas_NEW);
				//printf("prior = %lf\n", log_prior_NEW);
				//printf("new_posterior = %lf\n", LogNewPosterior);

				//--------REEVALUATE OLD AND NEW-------
				ProbOfAcceptance = exp((LogNewPosterior + LogJumpToOld) - (LogOldPosterior - LogJumpToNew));  
				if (isinf(ProbOfAcceptance))
				{ 
					ProbOfAcceptance=1;
				}

				//--------IF BETTER, ACCEPT-------
				if (ProbOfAcceptance>1 || gsl_rng_uniform_pos (r) < ProbOfAcceptance)
				{
					LogOldPosterior = LogNewPosterior;  
					total_loghood_metas_OLD = total_loghood_metas_NEW;

					for (a = 0; a < NumberOfParams; a++)
					{
						Old_Params[a] = New_Params[a]; 
					}
					Accept = Accept+1;
				}
				//--------IF WORSE, REJECT-------
				else
				{ 
					for (a = 0; a < NumberOfParams; a++)
					{
						New_PC[a] = Old_PC[a];           
					}
				}
			}
			//--------IF WORSE, REJECT--------
			else
			{ 
				for (a = 0; a < NumberOfParams; a++)
				{
					New_PC[a] = Old_PC[a];      
				}
			}

			fprintf(fpm, "%i\t", LoopNumber); //mcmc iteration

			for (int ii = 0; ii < NumberOfParams; ii++)
			{ 
				fprintf(fpm, "%lf\t", Old_Params[ii]);
			}
			fprintf(fpm, "%lf\t %lf\t %i\t %i\n", total_loghood_metas_OLD, LogOldPosterior, Accept, Attempt); 
			fflush(stdout);
			fflush(fpm);
		}
		fclose(fpm);
	}

	time_t end = time(NULL);

	printf("All iterations took %f seconds\n", difftime(end, start));

	return 0;
}
