#include "head.h"
gsl_rng *r;

///////////////////////////////////////////////////DOT-PRODUCT////////////////////////////////////////////////
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

#define VERBOSE 0				//select 1 for detailed output
#define MAXITNLS 3				// number of linesearch full parameter sweeps to run
#define REALIZATIONS 15000		// number of mcmc iterations to run //has to be at least number of params to get through all cases

STRUCTURE Params;
inputdata(&Params);	

time_t start = time(NULL);

//--------RANDOM NUMBERS--------
gsl_rng * r;
gsl_rng_env_setup();
const gsl_rng_type * K;
K = gsl_rng_default;
r = gsl_rng_alloc (K);

long seed;
srand((unsigned) time(NULL));
seed = time(NULL)*(int)getpid();
gsl_rng_set(r, seed);

//--------ALGORITHM--------
char *y = argv[1]; char *z = argv[2];
Params.model = atoi(y); Params.algorithm = atoi(z);

int model = Params.model;
int algorithm = Params.algorithm;

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
if (algorithm > 3){
	printf("INACCURATE ALGORITHM. Try again from the options below.\n");
	printf("1 = linesearch 2 = realizations 3 = mcmc\n");
}
if (model > 48 || model < 0){
	printf("INACCURATE MODEL. Model options range from 0 - 45. See Read Me for model options.\n");
}

printf("model = %i\n", model);

 //-------TEST MODE--------
int TEST = 0;
if(TEST)
{
	LScalls = 10; Rcalls = 10; Mcalls = 10; 	
} else {
	LScalls = 50; Rcalls = 10; Mcalls = 50; 
}

//-------DISPERSAL--------
int *p;
p = dispersal_fit(model);		//function returns 1 for fitting dispersal, 0 for not fitting dispersal
larval_dispersal = p[0]; l_a_pop_fit = p[1]; l_a_meta_fit = p[2]; l_a_sub_fit = p[3]; l_m_pop_fit = p[4]; l_m_meta_fit = p[5]; l_m_sub_fit = p[6]; 
conidia_dispersal = p[7]; c_a_pop_fit = p[8]; c_a_meta_fit = p[9]; c_a_sub_fit = p[10]; c_m_pop_fit = p[11]; c_m_meta_fit = p[12]; c_m_sub_fit = p[13];
r_pop_fit = p[14]; r_meta_fit = p[15]; r_sub_fit = p[16];

//-------FIT LIST--------
int *f; 
f = which_fit(model);			//function returns 1 for fitting param, 0 for not fitting param
for(int i = 0; i < NUM_PARS; i++)
{
	fit[i] = f[i];
}
static int log_fit[92] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1};			//1 for fitting on log-scale, 0 for fitting on non-log scale

///////////////////////////////////////////////////LINE-SEARCH///////////////////////////////////////////////////
if(linesearch == 1)
{
	//-------FILES--------
	int pid;
	pid = getpid();

	char namels[50];
	sprintf(namels, "M%i_LS_%i", model, pid);
	fpls = fopen(namels, "a+");
	setbuf(fpls, NULL);	

	//--------VARIABLES---------
	double new_params[NUM_PARS] = {0};
	double old_params[NUM_PARS] = {0};

	double new_lhood_pointwise[DATA_SETS+1][NUM_POINTWISE];
	double old_lhood_pointwise[DATA_SETS+1][NUM_POINTWISE];

	double lhood_meta;
	double new_lhood_meta;

	double old_lhood_pop;
	double new_lhood_pop;

	double lprior;
	double new_lprior;

	double new_posterior;
	double old_posterior;

	double meta_err;

	double adder, jumper, ls_tmp, par_sto;
	size_t ls_itns = MAXITNLS;
	int verbose = VERBOSE;

	//-------SET INITIAL PARAMS--------
	for (int i = 0; i < NUM_PARS; i++)
	{
		if (fit[i])
		{
			jumper = gsl_rng_uniform_pos(r);

			par_sto = param_bound(i, 1) + (param_bound(i,2) - param_bound(i,1)) * jumper;

			if (log_fit[i]) new_params[i] = old_params[i] = exp(par_sto); 		

			else new_params[i] = old_params[i] = par_sto; 

			if (verbose) printf("%d - %lf\n", i, exp(par_sto));
		}
	}
	if (verbose) printf("\n");

	//---------START LINE SEARCH--------
	double jumps[NUM_PARS];
	double half_njmp = 7.0;
	int j_iter;

	for (int b = 0; b < ls_itns; b++)
	{	
		if (verbose) printf("itn %d\n", b);

		if (b == 0) // set jump size
		{
			for (int i = 0; i < NUM_PARS; i++)
			{
				if (fit[i])
				{
					adder = gsl_rng_uniform(r);
					jumper = half_njmp + half_njmp * adder;
					jumps[i] = (param_bound(i, 2) - param_bound(i, 1)) / jumper;
				}
			}

			old_posterior = -6666666666666;
		}
		for (int j = 0; j < NUM_PARS; j++) 
		{ 
			if (fit[j])
			{

				if (verbose) printf("staring with %d until ls_tmp = %lf\n", j, param_bound(j, 2));

				for (ls_tmp = param_bound(j, 1) + jumps[j], j_iter = 0; ls_tmp <= param_bound(j, 2); ls_tmp += jumps[j])
				{

					par_sto = new_params[j]; //store old value of param

					if (log_fit[j])
					{
						new_params[j] = exp(ls_tmp); //tweak param	
						if (verbose) printf("tmp param[%i] = %lf from exp(%lf)\n", j, exp(ls_tmp), ls_tmp);	
					} else {
						new_params[j] = ls_tmp;
						if (verbose) printf("tmp param[%i] = %lf\n", j, ls_tmp);
					} 
					//--------PASS FIXED PARAMS-------
					//INITV //percentage of initS that are infected
					Params.FITINIT[1][4] 	= 	1e-6; 					//META 1 SUB 1
					Params.FITINIT[1][5] 	= 	0.2; 					//META 1 SUB 2
					Params.FITINIT[1][6] 	= 	0.2;					//META 1 SUB 3
					Params.FITINIT[1][7] 	= 	1e-6; 					//META 1 SUB 4
					Params.FITINIT[2][4] 	= 	1e-6; 					//META 2 SUB 1
					Params.FITINIT[2][5] 	= 	0.2; 					//META 2 SUB 2
					Params.FITINIT[2][6] 	= 	0.2; 					//META 2 SUB 3
					Params.FITINIT[2][7] 	= 	1e-6; 					//META 2 SUB 4
					Params.FITINIT[3][4] 	= 	1e-6; 					//META 3 SUB 1
					Params.FITINIT[3][5] 	= 	0.2; 					//META 3 SUB 2
					Params.FITINIT[3][6] 	= 	0.2; 					//META 3 SUB 3
					Params.FITINIT[3][7] 	= 	1e-6; 					//META 3 SUB 4
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
					Params.FITINIT[1][0] 	= 	new_params[0]; 			//META 1 SUB 1
					Params.FITINIT[1][1] 	= 	new_params[0]; 			//META 1 SUB 2
					Params.FITINIT[1][2] 	= 	new_params[0]; 			//META 1 SUB 3
					Params.FITINIT[1][3] 	= 	new_params[0]; 			//META 1 SUB 4
					Params.FITINIT[2][0] 	= 	new_params[0]; 			//META 2 SUB 1
					Params.FITINIT[2][1] 	= 	new_params[0]; 			//META 2 SUB 2
					Params.FITINIT[2][2] 	= 	new_params[0]; 			//META 2 SUB 3
					Params.FITINIT[2][3] 	= 	new_params[0]; 			//META 2 SUB 4
					Params.FITINIT[3][0] 	= 	new_params[0]; 			//META 3 SUB 1
					Params.FITINIT[3][1] 	= 	new_params[0]; 			//META 3 SUB 2
					Params.FITINIT[3][2] 	= 	new_params[0]; 			//META 3 SUB 3
					Params.FITINIT[3][3] 	= 	new_params[0]; 			//META 3 SUB 4
					//INITR
					Params.r_pop 			= 	new_params[1];			//POP
					Params.r_meta[1] 		= 	new_params[2];			//META 1
					Params.r_meta[2] 		= 	new_params[3];			//META 2
					Params.r_meta[3] 		=	new_params[4];			//META 3
					Params.FITINIT[1][8] 	= 	new_params[5]; 			//META 1 SUB 1
					Params.FITINIT[2][8] 	= 	new_params[6]; 			//META 2 SUB 1
					Params.FITINIT[2][9] 	= 	new_params[7]; 			//META 2 SUB 2 
					Params.FITINIT[2][10] 	= 	new_params[8]; 			//META 2 SUB 3
					Params.FITINIT[2][11] 	= 	new_params[9]; 			//META 2 SUB 4
					Params.FITINIT[3][8] 	= 	new_params[10]; 		//META 3 SUB 1
					Params.FITINIT[3][9] 	= 	new_params[11]; 		//META 3 SUB 2
					Params.FITINIT[3][10] 	= 	new_params[12]; 		//META 3 SUB 3
					Params.FITINIT[3][11] 	= 	new_params[13]; 		//META 3 SUB 4
					//RSTOCH
					Params.R_stoch 			= 	new_params[18];			//POP
					//FSTOCH
					Params.F_stoch			= 	new_params[19];			//POP
					//CONIDIA 1/AVG DIST DISP
					Params.c_a_pop 			= 	new_params[20];			//POP
					Params.c_a_meta[1] 		= 	new_params[21];			//META 1
					Params.c_a_meta[2] 		= 	new_params[22];			//META 2
					Params.c_a_meta[3] 		= 	new_params[23];			//META 3
					Params.c_a_sub[1][0] 	= 	new_params[24]; 		//META 1 SUB 1
					Params.c_a_sub[1][1] 	= 	new_params[25];			//META 1 SUB 2
					Params.c_a_sub[1][2] 	= 	new_params[26];			//META 1 SUB 3
					Params.c_a_sub[1][3] 	= 	new_params[27];			//META 1 SUB 4
					Params.c_a_sub[2][0] 	= 	new_params[28]; 		//META 2 SUB 1
					Params.c_a_sub[2][1] 	= 	new_params[29];			//META 2 SUB 2
					Params.c_a_sub[2][2] 	= 	new_params[30];			//META 2 SUB 3
					Params.c_a_sub[2][3] 	= 	new_params[31];			//META 2 SUB 4
					Params.c_a_sub[3][0] 	= 	new_params[32]; 		//META 3 SUB 1
					Params.c_a_sub[3][1] 	= 	new_params[33];			//META 3 SUB 2
					Params.c_a_sub[3][2] 	= 	new_params[34];			//META 3 SUB 3
					Params.c_a_sub[3][3] 	= 	new_params[35];			//META 3 SUB 4
					//CONIDIA FRAC SUCCESSFUL DISP
					Params.c_m_pop			= 	new_params[36]; 		//POP
					Params.c_m_meta[1]		= 	new_params[37];			//META 1
					Params.c_m_meta[2]		= 	new_params[38];			//META 2
					Params.c_m_meta[3]		= 	new_params[39];			//META 3
					Params.c_m_sub[1][0] 	= 	new_params[40];			//META 1 SUB 1
					Params.c_m_sub[1][1] 	= 	new_params[41];			//META 1 SUB 2
					Params.c_m_sub[1][2]	= 	new_params[42];			//META 1 SUB 3
					Params.c_m_sub[1][3] 	= 	new_params[43];			//META 1 SUB 4
					Params.c_m_sub[2][0] 	= 	new_params[44];			//META 2 SUB 1
					Params.c_m_sub[2][1] 	= 	new_params[45];			//META 2 SUB 2
					Params.c_m_sub[2][2] 	= 	new_params[46];			//META 2 SUB 3
					Params.c_m_sub[2][3] 	= 	new_params[47];			//META 2 SUB 4
					Params.c_m_sub[3][0] 	= 	new_params[48];			//META 3 SUB 1
					Params.c_m_sub[3][1] 	= 	new_params[49];			//META 3 SUB 2
					Params.c_m_sub[3][2] 	= 	new_params[50];			//META 3 SUB 3
					Params.c_m_sub[3][3] 	= 	new_params[51];			//META 3 SUB 4
					//LARVAE 1/AVG DIST DISP
					//TEMP
					Params.l_a_pop 			= 	new_params[52];			//POP
					Params.l_a_meta[1] 		= 	new_params[53];			//META 1
					Params.l_a_meta[2] 		= 	new_params[54];			//META 2
					Params.l_a_meta[3] 		= 	new_params[55];			//META 3
					Params.l_a_sub[1][0] 	= 	new_params[56];			//META 1 SUB 1
					Params.l_a_sub[1][1] 	= 	new_params[57];			//META 1 SUB 2
					Params.l_a_sub[1][2] 	= 	new_params[58];			//META 1 SUB 3
					Params.l_a_sub[1][3] 	= 	new_params[59];			//META 1 SUB 4
					Params.l_a_sub[2][0] 	=	new_params[60]; 		//META 2 SUB 1
					Params.l_a_sub[2][1] 	= 	new_params[61];			//META 2 SUB 2
					Params.l_a_sub[2][2] 	= 	new_params[62];			//META 2 SUB 3
					Params.l_a_sub[2][3] 	= 	new_params[63];			//META 2 SUB 4
					Params.l_a_sub[3][0] 	= 	new_params[64]; 		//META 3 SUB 1
					Params.l_a_sub[3][1] 	= 	new_params[65];			//META 3 SUB 2
					Params.l_a_sub[3][2] 	= 	new_params[66];			//META 3 SUB 3
					Params.l_a_sub[3][3] 	= 	new_params[67];			//META 3 SUB 4
					//LARVAE FRAC SUCCESSFUL DISP
					Params.l_m_pop			= 	new_params[68]; 		//POP
					Params.l_m_meta[1]		= 	new_params[69];			//META 1
					Params.l_m_meta[2]		= 	new_params[70];			//META 2
					Params.l_m_meta[3]		= 	new_params[71];			//META 3
					Params.l_m_sub[1][0] 	= 	new_params[72];			//META 1 SUB 1
					Params.l_m_sub[1][1] 	= 	new_params[73];			//META 1 SUB 2
					Params.l_m_sub[1][2] 	= 	new_params[74];			//META 1 SUB 3
					Params.l_m_sub[1][3] 	= 	new_params[75];			//META 1 SUB 4
					Params.l_m_sub[2][0] 	= 	new_params[76];			//META 2 SUB 1
					Params.l_m_sub[2][1] 	= 	new_params[77];			//META 2 SUB 2
					Params.l_m_sub[2][2] 	= 	new_params[78];			//META 2 SUB 3
					Params.l_m_sub[2][3] 	= 	new_params[79];			//META 2 SUB 4
					Params.l_m_sub[3][0] 	= 	new_params[80];			//META 3 SUB 1
					Params.l_m_sub[3][1] 	= 	new_params[81];			//META 3 SUB 2
					Params.l_m_sub[3][2] 	= 	new_params[82];			//META 3 SUB 3
					Params.l_m_sub[3][3] 	= 	new_params[83];			//META 3 SUB 4
					//OBSERVATIONAL
					Params.FITINIT[4][0] 	= 	new_params[84]; 		//META 4 INITS
					Params.FITINIT[4][4] 	= 	new_params[85]; 		//META 4 INITV
					Params.FITINIT[4][8] 	= 	new_params[86]; 		//META 4 INITR
					Params.FITINIT[5][0] 	= 	new_params[87]; 		//META 5 INITS
					Params.FITINIT[5][4] 	= 	new_params[88]; 		//META 5 INITV
					Params.FITINIT[6][0] 	= 	new_params[89];	 		//META 6 INITS
					Params.FITINIT[6][4] 	= 	new_params[90]; 		//META 6 INITV
					Params.FITINIT[6][8] 	= 	new_params[91]; 		//META 6 INITR

					//--------MISER CALUCLATE LIKELIHOOD-------
					for (int j = 1; j <= 3; j++)
					{
						for(int i = 0; i < 10; i++)
						{
							Params.lhood_point[j][i] = 0.0;
						}
					}

					new_lhood_pop = 0;

					for (int j = 1; j <= 3; j++)				
					{
						lhood_meta = new_lhood_meta = meta_err = 0;

						Params.j = j;

						Params.miser_ticker = 1; Params.miser2_flag = 0; 

						gsl_monte_function G = { &likelihood_calc, dim, &Params };	

						double xl[dim];	double xu[dim];	
						for (int jj = 0; jj < dim; jj++)	
						{
							xl[jj] = 0;	
							xu[jj] = 1;
						}

						gsl_monte_miser_state *s = gsl_monte_miser_alloc(dim);
						gsl_monte_miser_integrate (&G, xl, xu, dim, LScalls, r, s, &lhood_meta, &meta_err); 		//call MISER
						gsl_monte_miser_free(s);
						
						while (Params.miser2_flag > 0)		//indicates that a better likelihood score (or a few) were found
						{ 
							Params.miser2_flag = 0;
							Params.lhood_adjust[j] = -Params.bestlhood[j];
							
							gsl_monte_miser_state *s = gsl_monte_miser_alloc(dim);
							gsl_monte_miser_integrate (&G, xl, xu, dim, LScalls, r, s, &lhood_meta, &meta_err); 
							gsl_monte_miser_free(s);
						}

						new_lhood_meta = log(lhood_meta) - Params.lhood_adjust[j];

						if (isnan(new_lhood_meta) || isinf(new_lhood_meta))			//assign bad score to errors
						{ 
							new_lhood_meta = -99999;
						}
						
						new_lhood_pop += new_lhood_meta;
					}
					//-----------AVERAGE DATA POINT LHOODS-----
					for (int j = 1; j <= 3; j++)
					{
						for(int i = 0; i < 10; i++)
						{
							Params.lhood_point[j][i] = Params.lhood_point[j][i]/LScalls;
						}
					}
					//------------CALCULATE AND ADD PRIOR----------
					new_posterior = new_lprior = lprior = 0;

					for (int k = 0; k < NUM_PARS; k++)
					{
						if (fit[k])
						{
							if (log_fit[k])
							{ 
								lprior = log(gsl_ran_flat_pdf(new_params[k], exp(param_bound(k,1)), (exp(param_bound(k,1)) + exp(param_bound(k,2)))));

							} else {

								lprior = log(gsl_ran_flat_pdf(new_params[k], param_bound(k,1), (param_bound(k,1) + param_bound(k,2))));
							}
							if (isnan(lprior) || isinf(lprior)) 	//outside of bounds
							{ 
								printf("PROBLEM WITH PRIORS\n k=%i\t new log prior = %lf\n", k, lprior);
								lprior = -999999;	//assign bad score
							}
							new_lprior += lprior;
						}
					}

					new_posterior = new_lhood_pop + new_lprior;

					//--------EVALUATE POSTERIOR-------
					if (verbose) printf("new posterior = %lf vs old posterior = %lf\n", new_posterior, old_posterior);

					if (new_posterior > old_posterior)
					{ 	
						if (verbose) printf("saving...\n");

						old_posterior = new_posterior; 

						old_lhood_pop = new_lhood_pop;

						for (int j = 1; j <= 3; j++)
						{
							for(int i = 0; i < 10; i++)
							{
								old_lhood_pointwise[j][i] = Params.lhood_point[j][i];
							}
						}

						old_params[j] = new_params[j]; 	//save parameter value	

					} else {

						new_params[j] = par_sto; //reset parameter value

					}
					j_iter++;
				}  //ls_tmp

			} //fit list

			//save best param value for jumps
			new_params[j] = old_params[j];

		} //pars

	} //itns

	//------PRINT------
	if (verbose) 
	{
		printf("vals =\n");

		for (int j = 0; j < NUM_PARS; j++)
		{
			if (fit[j])
			{
				printf("%lf ", new_params[j]);
			}
		}
		printf("\n");
	}

	for (int j = 0; j < NUM_PARS; j++)
	{
		if (fit[j])
		{
			fprintf(fpls, "%lf ", new_params[j]);
		}
	}

	fprintf(fpls, "%lf %lf ", old_lhood_pop, old_posterior);

	for (int m = 1; m <= 3; m++)
	{
		for (int n = 0; n < 10; n++)
		{
			fprintf(fpls, "%lf ", log(old_lhood_pointwise[m][n])); //convert back to log for use in looic
		}
	}
	fprintf(fpls, "\n");
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

	char namelhood[50];
	sprintf(namelhood, "reals_lhood_m%i", Params.model);
	fplhood = fopen(namelhood, "a+");
	setbuf(fplhood, NULL);

	FILE *fileR;

	char realparams[50] = "./realsparams";
	char str_model[10];
	sprintf(str_model, "_%i.txt", model);

	strcat(realparams, str_model);

	//---------PARAMS----------
	int verbose = VERBOSE;

	int a, b, m, k;
	int num_param_sets = 10;
	double new_log_prior = 0;
	double log_prior = 0;
	double real_params[num_param_sets][NUM_PARS];
	for (a = 0; a < num_param_sets; a++)
	{
		for (b = 0; b < NUM_PARS; b++)
		{
			real_params[a][b] = -100; 
		}
	}

	//------READ IN PARAMS-----
	fileR = fopen(realparams, "r");
	for (a = 0; a < num_param_sets; a++)
	{
		for (b = 0; b < NUM_PARS; b++)
		{
			if (fit[b] == 1) fscanf(fileR, "%lf\n", &real_params[a][b]);		
			if (verbose && fit[b] == 1) printf("real_params[%i][%i] = %lf\n", a, b, real_params[a][b]);	
		}
	}         
	fclose(fileR);
	/*
	for (a = 0; a < num_param_sets; a++)
	{
		for (b = 0; b < NUM_PARS; b++)
		{
			printf("real_params[%i][%i] = %lf\n", a, b, real_params[a][b]);	
		}
	}  */

	//---------LOOP THROUGH PARAM SETS-----
	for (m = 0; m < num_param_sets; m++)
	{
		//printf("m = %i\n", m);
		//----------CALCULATE PRIORS-------
		/*
		log_prior = 0; new_log_prior = 0;

		for (k = 0; k < NUM_PARS; k++)
		{
			if (fit[k])
			{
				if (log_fit[k])
				{
					log_prior = log(gsl_ran_flat_pdf(exp(real_params[m][k]), exp(param_bound(a, 1)), (exp(param_bound(a, 2)) + exp(param_bound(a, 1)))));
					printf("k = %i LOG FIT log prior = %lf param = %lf lower bound = %lf upper bound = %lf\n", k, log_prior, exp(real_params[m][k]), exp(param_bound(a, 1)), (exp(param_bound(a, 2)) + exp(param_bound(a, 1))));
				}
				else
				{
					log_prior = log(gsl_ran_flat_pdf(real_params[m][k], param_bound(a, 1), (param_bound(a, 2) + param_bound(a, 1))));
					printf("k = %i NON LOG FIT log prior = %lf param = %lf lower bound = %lf upper bound = %lf\n", k, log_prior, real_params[m][k], param_bound(a, 1), (param_bound(a, 2) + param_bound(a, 1)));
				}

				if (isinf(log_prior))
				{ 
					//printf("PROBLEM WITH PRIORS\n k=%i\t new log prior = %lf\n", k, new_log_prior);
				}
				new_log_prior =+ log_prior;
			}
		}*/
		//--------PASS FIXED PARAMS-------
		//INITV
		Params.FITINIT[1][4] 	= 	0;						//META 1 SUB 1 
		Params.FITINIT[1][5] 	= 	0.2; 					//META 1 SUB 2 
		Params.FITINIT[1][6] 	= 	0.2;					//META 1 SUB 3
		Params.FITINIT[1][7] 	= 	0;						//META 1 SUB 4
		Params.FITINIT[2][4] 	= 	0;						//META 2 SUB 1
		Params.FITINIT[2][5] 	= 	0.2; 					//META 2 SUB 2
		Params.FITINIT[2][6] 	= 	0.2; 					//META 2 SUB 3
		Params.FITINIT[2][7] 	= 	0;						//META 2 SUB 4
		Params.FITINIT[3][4] 	= 	0;						//META 3 SUB 1
		Params.FITINIT[3][5] 	= 	0.2; 					//META 3 SUB 2
		Params.FITINIT[3][6] 	= 	0.2; 					//META 3 SUB 3
		Params.FITINIT[3][7] 	= 	0;						//META 3 SUB 4
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
		Params.FITINIT[1][0] 	= 	exp(real_params[m][0]);			//META 1 SUB 1
		Params.FITINIT[1][1] 	= 	exp(real_params[m][0]);			//META 1 SUB 2
		Params.FITINIT[1][2] 	= 	exp(real_params[m][0]);			//META 1 SUB 3
		Params.FITINIT[1][3] 	= 	exp(real_params[m][0]);			//META 1 SUB 4
		Params.FITINIT[2][0] 	= 	exp(real_params[m][0]);			//META 2 SUB 1
		Params.FITINIT[2][1] 	= 	exp(real_params[m][0]);			//META 2 SUB 2
		Params.FITINIT[2][2] 	= 	exp(real_params[m][0]);			//META 2 SUB 3
		Params.FITINIT[2][3] 	= 	exp(real_params[m][0]);			//META 2 SUB 4
		Params.FITINIT[3][0] 	= 	exp(real_params[m][0]);			//META 3 SUB 1
		Params.FITINIT[3][1] 	= 	exp(real_params[m][0]);			//META 3 SUB 2
		Params.FITINIT[3][2] 	= 	exp(real_params[m][0]);			//META 3 SUB 3
		Params.FITINIT[3][3] 	= 	exp(real_params[m][0]);			//META 3 SUB 4
		//INITR
		Params.r_pop 			= 	exp(real_params[m][1]);			//POP
		Params.r_meta[1] 		= 	exp(real_params[m][2]);			//META 1
		Params.r_meta[2] 		= 	exp(real_params[m][3]);			//META 2
		Params.r_meta[3] 		=	exp(real_params[m][4]);			//META 3
		Params.FITINIT[1][8] 	= 	exp(real_params[m][5]); 		//META 1 SUB 1
		Params.FITINIT[2][8] 	= 	exp(real_params[m][6]);			//META 2 SUB 1
		Params.FITINIT[2][9] 	= 	exp(real_params[m][7]); 		//META 2 SUB 2 
		Params.FITINIT[2][10] 	= 	exp(real_params[m][8]);			//META 2 SUB 3
		Params.FITINIT[2][11] 	= 	exp(real_params[m][9]);			//META 2 SUB 4
		Params.FITINIT[3][8] 	= 	exp(real_params[m][10]); 		//META 3 SUB 1
		Params.FITINIT[3][9] 	= 	exp(real_params[m][11]);		//META 3 SUB 2
		Params.FITINIT[3][10] 	= 	exp(real_params[m][12]); 		//META 3 SUB 3
		Params.FITINIT[3][11] 	= 	exp(real_params[m][13]); 		//META 3 SUB 4
		//RSTOCH
		Params.R_stoch 			=	exp(real_params[m][18]);		//POP
		//FSTOCH
		Params.F_stoch			= 	exp(real_params[m][19]);		//POP
		//CONIDIA 1/AVG DIST DISP
		Params.c_a_pop 			= 	exp(real_params[m][20]);		//POP
		Params.c_a_meta[1] 		= 	exp(real_params[m][21]);		//META 1
		Params.c_a_meta[2] 		= 	exp(real_params[m][22]);		//META 2
		Params.c_a_meta[3] 		= 	exp(real_params[m][23]);		//META 3
		Params.c_a_sub[1][0] 	= 	exp(real_params[m][24]); 		//META 1 SUB 1
		Params.c_a_sub[1][1] 	= 	exp(real_params[m][25]);		//META 1 SUB 2
		Params.c_a_sub[1][2] 	= 	exp(real_params[m][26]);		//META 1 SUB 3
		Params.c_a_sub[1][3] 	= 	exp(real_params[m][27]);		//META 1 SUB 4
		Params.c_a_sub[2][0] 	= 	exp(real_params[m][28]); 		//META 2 SUB 1
		Params.c_a_sub[2][1] 	= 	exp(real_params[m][29]);		//META 2 SUB 2
		Params.c_a_sub[2][2] 	= 	exp(real_params[m][30]);		//META 2 SUB 3
		Params.c_a_sub[2][3] 	= 	exp(real_params[m][31]);		//META 2 SUB 4
		Params.c_a_sub[3][0] 	= 	exp(real_params[m][32]); 		//META 3 SUB 1
		Params.c_a_sub[3][1] 	= 	exp(real_params[m][33]);		//META 3 SUB 2
		Params.c_a_sub[3][2] 	= 	exp(real_params[m][34]);		//META 3 SUB 3
		Params.c_a_sub[3][3] 	= 	exp(real_params[m][35]);		//META 3 SUB 4
		//CONIDIA FRAC SUCCESSFUL DISP
		Params.c_m_pop			= 	real_params[m][36]; 		//POP
		Params.c_m_meta[1]		= 	real_params[m][37];		//META 1
		Params.c_m_meta[2]		= 	real_params[m][38];		//META 2
		Params.c_m_meta[3]		= 	real_params[m][39];		//META 3
		Params.c_m_sub[1][0] 	= 	real_params[m][40];		//META 1 SUB 1
		Params.c_m_sub[1][1] 	= 	real_params[m][41];		//META 1 SUB 2
		Params.c_m_sub[1][2]	= 	real_params[m][42];		//META 1 SUB 3
		Params.c_m_sub[1][3] 	= 	real_params[m][43];		//META 1 SUB 4
		Params.c_m_sub[2][0] 	= 	real_params[m][44];		//META 2 SUB 1
		Params.c_m_sub[2][1] 	= 	real_params[m][45];		//META 2 SUB 2
		Params.c_m_sub[2][2] 	= 	real_params[m][46];		//META 2 SUB 3
		Params.c_m_sub[2][3] 	= 	real_params[m][47];		//META 2 SUB 4
		Params.c_m_sub[3][0] 	= 	real_params[m][48];		//META 3 SUB 1
		Params.c_m_sub[3][1] 	= 	real_params[m][49];		//META 3 SUB 2
		Params.c_m_sub[3][2] 	= 	real_params[m][50];		//META 3 SUB 3
		Params.c_m_sub[3][3] 	= 	real_params[m][51];		//META 3 SUB 4
		//LARVAE 1/AVG DIST DISP
		Params.l_a_pop 			= 	exp(real_params[m][52]);		//POP
		Params.l_a_meta[1] 		= 	exp(real_params[m][53]);		//META 1
		Params.l_a_meta[2] 		= 	exp(real_params[m][54]);		//META 2
		Params.l_a_meta[3] 		= 	exp(real_params[m][55]);		//META 3
		Params.l_a_sub[1][0] 	= 	exp(real_params[m][56]);		//META 1 SUB 1
		Params.l_a_sub[1][1] 	= 	exp(real_params[m][57]);		//META 1 SUB 2
		Params.l_a_sub[1][2] 	= 	exp(real_params[m][58]);		//META 1 SUB 3
		Params.l_a_sub[1][3] 	= 	exp(real_params[m][59]);		//META 1 SUB 4
		Params.l_a_sub[2][0] 	=	exp(real_params[m][60]); 		//META 2 SUB 1
		Params.l_a_sub[2][1] 	= 	exp(real_params[m][61]);		//META 2 SUB 2
		Params.l_a_sub[2][2] 	= 	exp(real_params[m][62]);		//META 2 SUB 3
		Params.l_a_sub[2][3] 	= 	exp(real_params[m][63]);		//META 2 SUB 4
		Params.l_a_sub[3][0] 	= 	exp(real_params[m][64]); 		//META 3 SUB 1
		Params.l_a_sub[3][1] 	= 	exp(real_params[m][65]);		//META 3 SUB 2
		Params.l_a_sub[3][2] 	= 	exp(real_params[m][66]);		//META 3 SUB 3
		Params.l_a_sub[3][3] 	= 	exp(real_params[m][67]);		//META 3 SUB 4
		//LARVAE FRAC SUCCESSFUL DISP
		Params.l_m_pop			= 	real_params[m][68]; 		//POP
		Params.l_m_meta[1]		= 	real_params[m][69];		//META 1
		Params.l_m_meta[2]		= 	real_params[m][70];		//META 2
		Params.l_m_meta[3]		= 	real_params[m][71];		//META 3
		Params.l_m_sub[1][0] 	= 	real_params[m][72];		//META 1 SUB 1
		Params.l_m_sub[1][1] 	= 	real_params[m][73];		//META 1 SUB 2
		Params.l_m_sub[1][2] 	= 	real_params[m][74];		//META 1 SUB 3
		Params.l_m_sub[1][3] 	= 	real_params[m][75];		//META 1 SUB 4
		Params.l_m_sub[2][0] 	= 	real_params[m][76];		//META 2 SUB 1
		Params.l_m_sub[2][1] 	= 	real_params[m][77];		//META 2 SUB 2
		Params.l_m_sub[2][2] 	= 	real_params[m][78];		//META 2 SUB 3
		Params.l_m_sub[2][3] 	= 	real_params[m][79];		//META 2 SUB 4
		Params.l_m_sub[3][0] 	= 	real_params[m][80];		//META 3 SUB 1
		Params.l_m_sub[3][1] 	= 	real_params[m][81];		//META 3 SUB 2
		Params.l_m_sub[3][2] 	= 	real_params[m][82];		//META 3 SUB 3
		Params.l_m_sub[3][3] 	= 	real_params[m][83];		//META 3 SUB 4
		//OBSERVATIONAL
		Params.FITINIT[4][0] 	= 	exp(real_params[m][84]); 		//META 4 INITS
		Params.FITINIT[4][4] 	= 	exp(real_params[m][85]); 		//META 4 INITV
		Params.FITINIT[4][8] 	= 	exp(real_params[m][86]); 		//META 4 INITR
		Params.FITINIT[5][0] 	= 	exp(real_params[m][87]); 		//META 5 INITS
		Params.FITINIT[5][4] 	= 	exp(real_params[m][88]); 		//META 5 INITV
		Params.FITINIT[6][0] 	= 	exp(real_params[m][89]);	 	//META 6 INITS
		Params.FITINIT[6][4] 	= 	exp(real_params[m][90]); 		//META 6 INITV
		Params.FITINIT[6][8] 	= 	exp(real_params[m][91]); 		//META 6 INITR

		//--------GENERATE REALIZATIONS USING MISER-------
		double lhood_meta; double log_lhood_meta; double total_loghood_metas = 0;
		double new_posterior = 0;
		double meta_err = 0;

		for (int j = 1; j <= 3; j++)
		{
			Params.j = j;

			lhood_meta = 0;
			log_lhood_meta = 0;

			gsl_monte_function G = { &likelihood_calc, dim, &Params };	

			double xl[dim];	double xu[dim];	
			for (int jj=0;jj<dim;jj++)	
			{
				xl[jj] = 0;	
				xu[jj] = 1;
			}

			gsl_monte_miser_state *s = gsl_monte_miser_alloc(dim);
			gsl_monte_miser_integrate (&G, xl, xu, dim, Rcalls, r, s, &lhood_meta, &meta_err); 
			gsl_monte_miser_free(s);
			
			log_lhood_meta = log(lhood_meta) - Params.lhood_adjust[j];

			if (isnan(log_lhood_meta) || isinf(log_lhood_meta))
			{
				log_lhood_meta = -99999999;
			}
			
			total_loghood_metas += log_lhood_meta;
		}
		new_log_prior = 0;
		new_posterior = total_loghood_metas + new_log_prior;

		fprintf(fplhood, "%lf %lf\n", total_loghood_metas, new_posterior);
	}
	fclose(fplhood);
	fclose(fpr); 
	fclose(fpme);
}

///////////////////////////////////////////////////MCMC///////////////////////////////////////////////////////////
if (mcmc == 1)
{
	//-------FILES--------
	int pid;
	pid = getpid();

	char namem[50];
	sprintf(namem, "M%i_mcmc_%i", model, pid);
	fpm = fopen(namem, "a+");
	setbuf(fpm, NULL);

	FILE *file;

	//-------VARIABLES--------
	int i, j, k, a, b, x, p, j_iter;
	double q, a_value;
	size_t d; 
	int verbose = VERBOSE;

	char rotsfp[50] = "./rotations";
	char sclsfp[50] = "./scale";
	char ctrsfp[50] = "./center";
	char sdsfp[50] = "./sd";
	char imptfp[50] = "./impt";
	
	char str_model[10];

	sprintf(str_model, "_%i.txt", model);

	strcat(rotsfp, str_model);
	strcat(sclsfp, str_model);
	strcat(ctrsfp, str_model);
	strcat(sdsfp, str_model);
	strcat(imptfp, str_model);

	double Coefficients[NUM_PARS*NUM_PARS];
	double Scale[NUM_PARS], Center[NUM_PARS], SDPca[NUM_PARS];

	for (i = 0; i < NUM_PARS; i++)
	{
		Scale[i] = Center[i] = SDPca[i] = 0.0;
	}

	for (int j = 0; j < NUM_PARS*NUM_PARS; j++)
	{
		Coefficients[j] = 0.0;
	}

	//--------READ IN LINESEARCH RESULTS-----
	file = fopen(rotsfp, "r");       
  
	for (i = 0; i < NUM_PARS; i++)
	{
		if (fit[i])
		{
			for (j = 0; j < NUM_PARS; j++)
			{
				if (fit[j]) fscanf(file, "%lf ", &Coefficients[j+(NUM_PARS*i)]);
				if (verbose && fit[j]) printf("j:%i i:%i index:%d Coefficients:%e\n", j, i, j+(NUM_PARS*i), Coefficients[j+(NUM_PARS*i)]);
			}
		}		
	}
	fclose(file);
	getc(stdin);

	file = fopen(sclsfp, "r");  
	for (i = 0; i < NUM_PARS; i++)
	{
		if (fit[i]) fscanf(file, "%lf ", &Scale[i]);
		if (verbose && fit[i]) printf("i:%d Scale:%e\n", i, Scale[i]);
		//printf("i:%d Scale:%e\n", i, scale[i]);
	}
	fclose(file);

	file = fopen(ctrsfp, "r");       
	for (i = 0; i < NUM_PARS; i++)
	{
		if (fit[i]) fscanf(file, "%lf ", &Center[i]);
		if (verbose && fit[i]) printf("i:%d Center:%e\n", i, Center[i]);
		//printf("i:%d Center:%e\n", i, center[i]);
	}
	fclose(file);

	file = fopen(sdsfp, "r");      
	for (i = 0; i < NUM_PARS; i++)
	{
		if (fit[i]) fscanf(file, "%lf ", &SDPca[i]);
		if (verbose && fit[i]) printf("i:%d SD:%e\n", i, SDPca[i]);
		//printf("i:%d SD:%e\n", i, sd[i]);
	}
	fclose(file);

	//-------VARIABLE AND ARRAY SETUP--------
	double LogJumpToNew;
	double LogJumpToOld;
	double ProbOfAcceptance;

	double LogOldPosterior;
	double LogNewPosterior;
	double LogNewPrior;
	double PreviousLogOldPosterior = -100000000000000;

	double New_PC[NUM_PARS] = {0.0};
	double Old_PC[NUM_PARS] = {0.0};
	double Holder[NUM_PARS] = {0.0};
	double New_Params[NUM_PARS] = {0.0};
	double Old_Params[NUM_PARS] = {0.0};

	double new_lhood_pointwise[DATA_SETS+1][NUM_POINTWISE];
	double old_lhood_pointwise[DATA_SETS+1][NUM_POINTWISE];

	int Accept=0;
	int Attempt=0;

	int ticker;
	int ticker2;

	int Case;

	signed int LoopNumber=-1;

	double SigmaInflation=1.2;

	double sigma[NUM_PARS];

	double log_prior_new;
	double log_prior_old;
	double log_prior_OLD;
	double log_prior_NEW;

	double lhood_meta;
	double log_lhood_meta;
	double total_loghood_metas_OLD;
	double total_loghood_metas_NEW;
	double meta_err;

	//-------GENERATE INITIAL PCS--------
	for (a = 0; a < NUM_PARS; a++)
	{
		if (fit[a]) sigma[a] = SigmaInflation * SDPca[a];
	}
	//-------RECONSTRUCT PARAMS FROM PCS AND BOUND CHECK--------
	int PCA_ticker = 0;
	while (PCA_ticker == 0)
	{
		for (a = 0; a < NUM_PARS; a++)
		{
			if (fit[a]) New_PC[a] = gsl_ran_gaussian (r, sigma[a]); 
		}
		for (a = 0; a < NUM_PARS; a++)
		{
			if(fit[a])
			{						
				for (b = 0; b < NUM_PARS; b++)
				{
					if (fit[b]) Holder[b] = Coefficients[a * NUM_PARS + b];         
				}

				New_Params[a] = exp(DotProduct(NUM_PARS, Holder, New_PC) * Scale[a] + Center[a]); 

				if (verbose) printf("a = %i fit[a] = %i New_Params[a] = %lf\n", a, fit[a], New_Params[a]);
			}
		}

		PCA_ticker=1;
		for (a = 0; a < NUM_PARS; a++)
		{
			if (fit[a])
			{
				if (log_fit[a])
				{
					if (New_Params[a] < exp(param_bound(a, 1)) || New_Params[a] > exp(param_bound(a, 2)))
					{ 
						PCA_ticker = 0;
						printf("model = %i\n", model);
						printf("out of bounds initial PC proposal for param %i\n", a);
						printf("value = %lf\t lower bound = %lf\t upper bound = %lf\n", New_Params[a], exp(param_bound(a, 1)), exp(param_bound(a, 2)));	
					}
				}
				else
				{
					if (New_Params[a] < param_bound(a, 1) || New_Params[a] > param_bound(a, 2))
					{ 
						PCA_ticker = 0;
						printf("model = %i\n", model);
						printf("out of bounds initial PC proposal for param %i\n", a);
						printf("value = %lf\t lower bound = %lf\t upper bound = %lf\n", New_Params[a], param_bound(a, 1), param_bound(a, 2));	
					}
				}
			}
		}
	}
	printf("initial parameter set successful\n");

	//-------BEGIN MCMC--------
	Case = -1;

	while (LoopNumber < REALIZATIONS) 
	{     
		LoopNumber = LoopNumber + 1;

		//----DETERMINE WHICH PARAM TO CHANGE---
		Case = Case + 1;

		if (fit[Case]==0)
		{
			while (fit[Case]==0)
			{ 
				Case = Case + 1;
				
				if(Case == NUM_PARS)
				{
					Case = 0;
				}
			}
		}

		if (verbose) printf("Case = %i\n", Case);

		//-------STORE NEW PCS AS OLD--------
		for (a = 0; a < NUM_PARS; a++)
		{
			if (fit[a]) Old_PC[a] = New_PC[a];							//Store old PC values
		}

		//-------DRAW NEW PC IN NEW--------
		SigmaInflation = 1; 			// original old_PC is set at 1.2, all new PC set a 1
		
		sigma[Case] = SigmaInflation * SDPca[Case]; 

		New_PC[Case] = gsl_ran_gaussian (r, sigma[Case]);

		if (verbose) printf("old pc [%i] = %lf\n", Case, Old_PC[Case]);
		if (verbose) printf("new pc [%i] = %lf\n", Case, New_PC[Case]);

		//-------RECONSTRUCT OLD AND NEW PCS TO PARAMS--------
		for (a = 0; a < NUM_PARS; a++)								
		{
			if (fit[a])
			{
				for (b = 0; b < NUM_PARS; b++)
				{
					if (fit[b]) Holder[b] = Coefficients[a * NUM_PARS + b];        
				}

				New_Params[a]=exp(DotProduct(NUM_PARS, Holder, New_PC)*Scale[a]+Center[a]);            
				Old_Params[a]=exp(DotProduct(NUM_PARS, Holder, Old_PC)*Scale[a]+Center[a]);
				if (verbose) printf("a = %i newpc = %lf newparam = %lf, oldpc = %lf old param = %lf\n", a, New_PC[a], New_Params[a], Old_PC[a], Old_Params[a]);       
			}
		}

		//-------BOUND CHECK PARAMS--------
		int bound_ticker = 0;
		if (log_fit[Case])
		{ 
			while (New_Params[Case] < exp(param_bound(Case, 1)) || New_Params[Case] > exp(param_bound(Case, 2)))			//if CASE out of bounds
			{
				if (bound_ticker > NUM_PARS) exit(1);

				printf("BOUND ERROR param %i not in bounds\n", Case);
				printf("value = %lf\t lower bound = %lf\t upper bound = %lf\n",New_Params[Case], exp(param_bound(Case, 1)), exp(param_bound(Case, 2)));
				
				New_PC[Case] = gsl_ran_gaussian (r, sigma[Case]);			//draw new CASE
				bound_ticker++;

				for (a = 0; a < NUM_PARS; a++)			//reconstruct all
				{
					if (fit[a])
					{							
						for (b = 0; b < NUM_PARS; b++)
						{
							if (fit[b]) Holder[b] = Coefficients[a * NUM_PARS + b];         
						}
						New_Params[a] = exp(DotProduct(NUM_PARS, Holder, New_PC) * Scale[a] + Center[a]);  
					}          
				}
			}
		}
		else
		{
			while (New_Params[Case] < param_bound(Case, 1) || New_Params[Case] > param_bound(Case, 2))		//if CASE out of bounds
			{
				if (bound_ticker > NUM_PARS) exit(1);

				printf("BOUND ERROR param %i not in bounds\n", Case);
				printf("value = %lf\t lower bound = %lf\t upper bound = %lf\n", New_Params[Case], param_bound(Case, 1), param_bound(Case, 2));
				
				New_PC[Case] = gsl_ran_gaussian (r, sigma[Case]);			//draw new CASE
				bound_ticker++;

				for (a = 0; a < NUM_PARS; a++)			//reconstruct all
				{
					if (fit[a])
					{							
						for (b = 0; b < NUM_PARS; b++)
						{
							if (fit[b]) Holder[b] = Coefficients[a * NUM_PARS + b];         
						}
						New_Params[a] = exp(DotProduct(NUM_PARS, Holder, New_PC) * Scale[a] + Center[a]);            
					}
				}
			}
		}
		//-------CALCULATE PRIORS--------
		log_prior_NEW = 0; log_prior_OLD = 0;
		log_prior_new = 0; log_prior_old = 0;

		for (a = 0; a < NUM_PARS; a++)
		{
			if (fit[a]){
				if (log_fit[a])
				{
					log_prior_new = log(gsl_ran_flat_pdf(New_Params[a], exp(param_bound(a, 1)), (exp(param_bound(a, 2)) + exp(param_bound(a, 1)))));
					log_prior_old = log(gsl_ran_flat_pdf(Old_Params[a], exp(param_bound(a, 1)), (exp(param_bound(a, 2)) + exp(param_bound(a, 1)))));
				}
				else
				{
					log_prior_new = log(gsl_ran_flat_pdf(New_Params[a], param_bound(a, 1), (param_bound(a, 2) + param_bound(a, 1))));
					log_prior_old = log(gsl_ran_flat_pdf(Old_Params[a], param_bound(a, 1), (param_bound(a, 2) + param_bound(a, 1))));
				}

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
		}
		if (verbose) printf("log prior old = %lf log prior new = %lf\n", log_prior_OLD, log_prior_NEW);

		//-------METROPOLIS SAMPLING STEP--------
		LogJumpToNew = -log(gsl_ran_gaussian_pdf(New_PC[Case], sigma[Case])); 
		LogJumpToOld = -log(gsl_ran_gaussian_pdf(Old_PC[Case], sigma[Case]));

		//------CALCULATE LIKELIHOOD NEW---
		//--------PASS FIXED PARAMS-------
		//INITV
		Params.FITINIT[1][4] 	= 	1e-6; 					//META 1 SUB 1
		Params.FITINIT[1][5] 	= 	0.2; 					//META 1 SUB 2
		Params.FITINIT[1][6] 	= 	0.2;					//META 1 SUB 3
		Params.FITINIT[1][7] 	= 	1e-6; 					//META 1 SUB 4
		Params.FITINIT[2][4] 	= 	1e-6; 					//META 2 SUB 1
		Params.FITINIT[2][5] 	= 	0.2; 					//META 2 SUB 2
		Params.FITINIT[2][6] 	= 	0.2; 					//META 2 SUB 3
		Params.FITINIT[2][7] 	= 	1e-6; 					//META 2 SUB 4
		Params.FITINIT[3][4] 	= 	1e-6; 					//META 3 SUB 1
		Params.FITINIT[3][5] 	= 	0.2; 					//META 3 SUB 2
		Params.FITINIT[3][6] 	= 	0.2; 					//META 3 SUB 3
		Params.FITINIT[3][7] 	= 	1e-6; 					//META 3 SUB 4
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
		Params.FITINIT[1][0] 	= 	New_Params[0]; 			//META 1 SUB 1
		Params.FITINIT[1][1] 	= 	New_Params[0]; 			//META 1 SUB 2
		Params.FITINIT[1][2] 	= 	New_Params[0]; 			//META 1 SUB 3
		Params.FITINIT[1][3] 	= 	New_Params[0]; 			//META 1 SUB 4
		Params.FITINIT[2][0] 	= 	New_Params[0]; 			//META 2 SUB 1
		Params.FITINIT[2][1] 	= 	New_Params[0]; 			//META 2 SUB 2
		Params.FITINIT[2][2] 	= 	New_Params[0]; 			//META 2 SUB 3
		Params.FITINIT[2][3] 	= 	New_Params[0]; 			//META 2 SUB 4
		Params.FITINIT[3][0] 	= 	New_Params[0]; 			//META 3 SUB 1
		Params.FITINIT[3][1] 	= 	New_Params[0]; 			//META 3 SUB 2
		Params.FITINIT[3][2] 	= 	New_Params[0]; 			//META 3 SUB 3
		Params.FITINIT[3][3] 	= 	New_Params[0]; 			//META 3 SUB 4
		//INITR
		Params.r_pop 			= 	New_Params[1];			//POP
		Params.r_meta[1] 		= 	New_Params[2];			//META 1
		Params.r_meta[2] 		= 	New_Params[3];			//META 2
		Params.r_meta[3] 		=	New_Params[4];			//META 3
		Params.FITINIT[1][8] 	= 	New_Params[5]; 			//META 1 SUB 1
		Params.FITINIT[2][8] 	= 	New_Params[6]; 			//META 2 SUB 1
		Params.FITINIT[2][9] 	= 	New_Params[7]; 			//META 2 SUB 2 
		Params.FITINIT[2][10] 	= 	New_Params[8]; 			//META 2 SUB 3
		Params.FITINIT[2][11] 	= 	New_Params[9]; 			//META 2 SUB 4
		Params.FITINIT[3][8] 	= 	New_Params[10]; 		//META 3 SUB 1
		Params.FITINIT[3][9] 	= 	New_Params[11]; 		//META 3 SUB 2
		Params.FITINIT[3][10] 	= 	New_Params[12]; 		//META 3 SUB 3
		Params.FITINIT[3][11] 	= 	New_Params[13]; 		//META 3 SUB 4
		//RSTOCH
		Params.R_stoch 			= 	New_Params[18];			//POP
		//FSTOCH
		Params.F_stoch			= 	New_Params[19];			//POP
		//CONIDIA 1/AVG DIST DISP
		Params.c_a_pop 			= 	New_Params[20];			//POP
		Params.c_a_meta[1] 		= 	New_Params[21];			//META 1
		Params.c_a_meta[2] 		= 	New_Params[22];			//META 2
		Params.c_a_meta[3] 		= 	New_Params[23];			//META 3
		Params.c_a_sub[1][0] 	= 	New_Params[24]; 		//META 1 SUB 1
		Params.c_a_sub[1][1] 	= 	New_Params[25];			//META 1 SUB 2
		Params.c_a_sub[1][2] 	= 	New_Params[26];			//META 1 SUB 3
		Params.c_a_sub[1][3] 	= 	New_Params[27];			//META 1 SUB 4
		Params.c_a_sub[2][0] 	= 	New_Params[28]; 		//META 2 SUB 1
		Params.c_a_sub[2][1] 	= 	New_Params[29];			//META 2 SUB 2
		Params.c_a_sub[2][2] 	= 	New_Params[30];			//META 2 SUB 3
		Params.c_a_sub[2][3] 	= 	New_Params[31];			//META 2 SUB 4
		Params.c_a_sub[3][0] 	= 	New_Params[32]; 		//META 3 SUB 1
		Params.c_a_sub[3][1] 	= 	New_Params[33];			//META 3 SUB 2
		Params.c_a_sub[3][2] 	= 	New_Params[34];			//META 3 SUB 3
		Params.c_a_sub[3][3] 	= 	New_Params[35];			//META 3 SUB 4
		//CONIDIA FRAC SUCCESSFUL DISP
		Params.c_m_pop			= 	New_Params[36]; 		//POP
		Params.c_m_meta[1]		= 	New_Params[37];			//META 1
		Params.c_m_meta[2]		= 	New_Params[38];			//META 2
		Params.c_m_meta[3]		= 	New_Params[39];			//META 3
		Params.c_m_sub[1][0] 	= 	New_Params[40];			//META 1 SUB 1
		Params.c_m_sub[1][1] 	= 	New_Params[41];			//META 1 SUB 2
		Params.c_m_sub[1][2]	= 	New_Params[42];			//META 1 SUB 3
		Params.c_m_sub[1][3] 	= 	New_Params[43];			//META 1 SUB 4
		Params.c_m_sub[2][0] 	= 	New_Params[44];			//META 2 SUB 1
		Params.c_m_sub[2][1] 	= 	New_Params[45];			//META 2 SUB 2
		Params.c_m_sub[2][2] 	= 	New_Params[46];			//META 2 SUB 3
		Params.c_m_sub[2][3] 	= 	New_Params[47];			//META 2 SUB 4
		Params.c_m_sub[3][0] 	= 	New_Params[48];			//META 3 SUB 1
		Params.c_m_sub[3][1] 	= 	New_Params[49];			//META 3 SUB 2
		Params.c_m_sub[3][2] 	= 	New_Params[50];			//META 3 SUB 3
		Params.c_m_sub[3][3] 	= 	New_Params[51];			//META 3 SUB 4
		//LARVAE 1/AVG DIST DISP
		//TEMP
		Params.l_a_pop 			= 	New_Params[52];			//POP
		Params.l_a_meta[1] 		= 	New_Params[53];			//META 1
		Params.l_a_meta[2] 		= 	New_Params[54];			//META 2
		Params.l_a_meta[3] 		= 	New_Params[55];			//META 3
		Params.l_a_sub[1][0] 	= 	New_Params[56];			//META 1 SUB 1
		Params.l_a_sub[1][1] 	= 	New_Params[57];			//META 1 SUB 2
		Params.l_a_sub[1][2] 	= 	New_Params[58];			//META 1 SUB 3
		Params.l_a_sub[1][3] 	= 	New_Params[59];			//META 1 SUB 4
		Params.l_a_sub[2][0] 	=	New_Params[60]; 		//META 2 SUB 1
		Params.l_a_sub[2][1] 	= 	New_Params[61];			//META 2 SUB 2
		Params.l_a_sub[2][2] 	= 	New_Params[62];			//META 2 SUB 3
		Params.l_a_sub[2][3] 	= 	New_Params[63];			//META 2 SUB 4
		Params.l_a_sub[3][0] 	= 	New_Params[64]; 		//META 3 SUB 1
		Params.l_a_sub[3][1] 	= 	New_Params[65];			//META 3 SUB 2
		Params.l_a_sub[3][2] 	= 	New_Params[66];			//META 3 SUB 3
		Params.l_a_sub[3][3] 	= 	New_Params[67];			//META 3 SUB 4
		//LARVAE FRAC SUCCESSFUL DISP
		Params.l_m_pop			= 	New_Params[68]; 		//POP
		Params.l_m_meta[1]		= 	New_Params[69];			//META 1
		Params.l_m_meta[2]		= 	New_Params[70];			//META 2
		Params.l_m_meta[3]		= 	New_Params[71];			//META 3
		Params.l_m_sub[1][0] 	= 	New_Params[72];			//META 1 SUB 1
		Params.l_m_sub[1][1] 	= 	New_Params[73];			//META 1 SUB 2
		Params.l_m_sub[1][2] 	= 	New_Params[74];			//META 1 SUB 3
		Params.l_m_sub[1][3] 	= 	New_Params[75];			//META 1 SUB 4
		Params.l_m_sub[2][0] 	= 	New_Params[76];			//META 2 SUB 1
		Params.l_m_sub[2][1] 	= 	New_Params[77];			//META 2 SUB 2
		Params.l_m_sub[2][2] 	= 	New_Params[78];			//META 2 SUB 3
		Params.l_m_sub[2][3] 	= 	New_Params[79];			//META 2 SUB 4
		Params.l_m_sub[3][0] 	= 	New_Params[80];			//META 3 SUB 1
		Params.l_m_sub[3][1] 	= 	New_Params[81];			//META 3 SUB 2
		Params.l_m_sub[3][2] 	= 	New_Params[82];			//META 3 SUB 3
		Params.l_m_sub[3][3] 	= 	New_Params[83];			//META 3 SUB 4
		//OBSERVATIONAL
		Params.FITINIT[4][0] 	= 	New_Params[84]; 		//META 4 INITS
		Params.FITINIT[4][4] 	= 	New_Params[85]; 		//META 4 INITV
		Params.FITINIT[4][8] 	= 	New_Params[86]; 		//META 4 INITR
		Params.FITINIT[5][0] 	= 	New_Params[87]; 		//META 5 INITS
		Params.FITINIT[5][4] 	= 	New_Params[88]; 		//META 5 INITV
		Params.FITINIT[6][0] 	= 	New_Params[89];	 		//META 6 INITS
		Params.FITINIT[6][4] 	= 	New_Params[90]; 		//META 6 INITV
		Params.FITINIT[6][8] 	= 	New_Params[91]; 		//META 6 INITR

		//--------MISER CALUCLATE LIKELIHOOD-------
		for (int j = 1; j <= 3; j++)
		{
			for(int i = 0; i < 10; i++)
			{
				Params.lhood_point[j][i] = 0.0;
			}
		}

		lhood_meta = 0; log_lhood_meta = 0; total_loghood_metas_NEW = 0;
		meta_err = 0;

		for (int j = 1; j <= 3; j++)				
		{
			Params.j = j;

			Params.miser_ticker = 1; Params.miser2_flag = 0; 

			gsl_monte_function G = { &likelihood_calc, dim, &Params };	

			double xl[dim];	double xu[dim];	
			for (int jj = 0; jj < dim; jj++)	
			{
				xl[jj] = 0;	
				xu[jj] = 1;
			}

			gsl_monte_miser_state *s = gsl_monte_miser_alloc(dim);
			gsl_monte_miser_integrate (&G, xl, xu, dim, Mcalls, r, s, &lhood_meta, &meta_err); 		//call MISER
			gsl_monte_miser_free(s);
			
			while (Params.miser2_flag > 0)		//indicates that a better likelihood score (or a few) were found
			{ 
				Params.miser2_flag = 0;
				Params.lhood_adjust[j] = -Params.bestlhood[j];
				
				gsl_monte_miser_state *s = gsl_monte_miser_alloc(dim);
				gsl_monte_miser_integrate (&G, xl, xu, dim, Mcalls, r, s, &lhood_meta, &meta_err); 
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
		if (verbose) printf("loghood NEW = %lf posterior NEW = %lf\n", total_loghood_metas_NEW, LogNewPosterior);
		
		//-----------AVERAGE DATA POINT LHOODS-----
		for (int j = 1; j <= 3; j++)
		{
			for(int i = 0; i < 10; i++)
			{
				new_lhood_pointwise[j][i] = Params.lhood_point[j][i]/Mcalls;
			}
		}
		//------CALCULATE LIKELIHOOD OLD------
		//--------PASS FIXED PARAMS-------
		//INITV
		Params.FITINIT[1][4] 	= 	1e-6; 					//META 1 SUB 1
		Params.FITINIT[1][5] 	= 	0.2; 					//META 1 SUB 2
		Params.FITINIT[1][6] 	= 	0.2;					//META 1 SUB 3
		Params.FITINIT[1][7] 	= 	1e-6; 					//META 1 SUB 4
		Params.FITINIT[2][4] 	= 	1e-6; 					//META 2 SUB 1
		Params.FITINIT[2][5] 	= 	0.2; 					//META 2 SUB 2
		Params.FITINIT[2][6] 	= 	0.2; 					//META 2 SUB 3
		Params.FITINIT[2][7] 	= 	1e-6; 					//META 2 SUB 4
		Params.FITINIT[3][4] 	= 	1e-6; 					//META 3 SUB 1
		Params.FITINIT[3][5] 	= 	0.2; 					//META 3 SUB 2
		Params.FITINIT[3][6] 	= 	0.2; 					//META 3 SUB 3
		Params.FITINIT[3][7] 	= 	1e-6; 					//META 3 SUB 4
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
		Params.FITINIT[1][0] 	= 	Old_Params[0]; 			//META 1 SUB 1
		Params.FITINIT[1][1] 	= 	Old_Params[0]; 			//META 1 SUB 2
		Params.FITINIT[1][2] 	= 	Old_Params[0]; 			//META 1 SUB 3
		Params.FITINIT[1][3] 	= 	Old_Params[0]; 			//META 1 SUB 4
		Params.FITINIT[2][0] 	= 	Old_Params[0]; 			//META 2 SUB 1
		Params.FITINIT[2][1] 	= 	Old_Params[0]; 			//META 2 SUB 2
		Params.FITINIT[2][2] 	= 	Old_Params[0]; 			//META 2 SUB 3
		Params.FITINIT[2][3] 	= 	Old_Params[0]; 			//META 2 SUB 4
		Params.FITINIT[3][0] 	= 	Old_Params[0]; 			//META 3 SUB 1
		Params.FITINIT[3][1] 	= 	Old_Params[0]; 			//META 3 SUB 2
		Params.FITINIT[3][2] 	= 	Old_Params[0]; 			//META 3 SUB 3
		Params.FITINIT[3][3] 	= 	Old_Params[0]; 			//META 3 SUB 4
		//INITR
		Params.r_pop 			= 	Old_Params[1];			//POP
		Params.r_meta[1] 		= 	Old_Params[2];			//META 1
		Params.r_meta[2] 		= 	Old_Params[3];			//META 2
		Params.r_meta[3] 		=	Old_Params[4];			//META 3
		Params.FITINIT[1][8] 	= 	Old_Params[5]; 			//META 1 SUB 1
		Params.FITINIT[2][8] 	= 	Old_Params[6]; 			//META 2 SUB 1
		Params.FITINIT[2][9] 	= 	Old_Params[7]; 			//META 2 SUB 2 
		Params.FITINIT[2][10] 	= 	Old_Params[8]; 			//META 2 SUB 3
		Params.FITINIT[2][11] 	= 	Old_Params[9]; 			//META 2 SUB 4
		Params.FITINIT[3][8] 	= 	Old_Params[10]; 		//META 3 SUB 1
		Params.FITINIT[3][9] 	= 	Old_Params[11]; 		//META 3 SUB 2
		Params.FITINIT[3][10] 	= 	Old_Params[12]; 		//META 3 SUB 3
		Params.FITINIT[3][11] 	= 	Old_Params[13]; 		//META 3 SUB 4
		//RSTOCH
		Params.R_stoch 			= 	Old_Params[18];			//POP
		//FSTOCH
		Params.F_stoch			= 	Old_Params[19];			//POP
		//CONIDIA 1/AVG DIST DISP
		Params.c_a_pop 			= 	Old_Params[20];			//POP
		Params.c_a_meta[1] 		= 	Old_Params[21];			//META 1
		Params.c_a_meta[2] 		= 	Old_Params[22];			//META 2
		Params.c_a_meta[3] 		= 	Old_Params[23];			//META 3
		Params.c_a_sub[1][0] 	= 	Old_Params[24]; 		//META 1 SUB 1
		Params.c_a_sub[1][1] 	= 	Old_Params[25];			//META 1 SUB 2
		Params.c_a_sub[1][2] 	= 	Old_Params[26];			//META 1 SUB 3
		Params.c_a_sub[1][3] 	= 	Old_Params[27];			//META 1 SUB 4
		Params.c_a_sub[2][0] 	= 	Old_Params[28]; 		//META 2 SUB 1
		Params.c_a_sub[2][1] 	= 	Old_Params[29];			//META 2 SUB 2
		Params.c_a_sub[2][2] 	= 	Old_Params[30];			//META 2 SUB 3
		Params.c_a_sub[2][3] 	= 	Old_Params[31];			//META 2 SUB 4
		Params.c_a_sub[3][0] 	= 	Old_Params[32]; 		//META 3 SUB 1
		Params.c_a_sub[3][1] 	= 	Old_Params[33];			//META 3 SUB 2
		Params.c_a_sub[3][2] 	= 	Old_Params[34];			//META 3 SUB 3
		Params.c_a_sub[3][3] 	= 	Old_Params[35];			//META 3 SUB 4
		//CONIDIA FRAC SUCCESSFUL DISP
		Params.c_m_pop			= 	Old_Params[36]; 		//POP
		Params.c_m_meta[1]		= 	Old_Params[37];			//META 1
		Params.c_m_meta[2]		= 	Old_Params[38];			//META 2
		Params.c_m_meta[3]		= 	Old_Params[39];			//META 3
		Params.c_m_sub[1][0] 	= 	Old_Params[40];			//META 1 SUB 1
		Params.c_m_sub[1][1] 	= 	Old_Params[41];			//META 1 SUB 2
		Params.c_m_sub[1][2]	= 	Old_Params[42];			//META 1 SUB 3
		Params.c_m_sub[1][3] 	= 	Old_Params[43];			//META 1 SUB 4
		Params.c_m_sub[2][0] 	= 	Old_Params[44];			//META 2 SUB 1
		Params.c_m_sub[2][1] 	= 	Old_Params[45];			//META 2 SUB 2
		Params.c_m_sub[2][2] 	= 	Old_Params[46];			//META 2 SUB 3
		Params.c_m_sub[2][3] 	= 	Old_Params[47];			//META 2 SUB 4
		Params.c_m_sub[3][0] 	= 	Old_Params[48];			//META 3 SUB 1
		Params.c_m_sub[3][1] 	= 	Old_Params[49];			//META 3 SUB 2
		Params.c_m_sub[3][2] 	= 	Old_Params[50];			//META 3 SUB 3
		Params.c_m_sub[3][3] 	= 	Old_Params[51];			//META 3 SUB 4
		//LARVAE 1/AVG DIST DISP
		//TEMP
		Params.l_a_pop 			= 	Old_Params[52];			//POP
		Params.l_a_meta[1] 		= 	Old_Params[53];			//META 1
		Params.l_a_meta[2] 		= 	Old_Params[54];			//META 2
		Params.l_a_meta[3] 		= 	Old_Params[55];			//META 3
		Params.l_a_sub[1][0] 	= 	Old_Params[56];			//META 1 SUB 1
		Params.l_a_sub[1][1] 	= 	Old_Params[57];			//META 1 SUB 2
		Params.l_a_sub[1][2] 	= 	Old_Params[58];			//META 1 SUB 3
		Params.l_a_sub[1][3] 	= 	Old_Params[59];			//META 1 SUB 4
		Params.l_a_sub[2][0] 	=	Old_Params[60]; 		//META 2 SUB 1
		Params.l_a_sub[2][1] 	= 	Old_Params[61];			//META 2 SUB 2
		Params.l_a_sub[2][2] 	= 	Old_Params[62];			//META 2 SUB 3
		Params.l_a_sub[2][3] 	= 	Old_Params[63];			//META 2 SUB 4
		Params.l_a_sub[3][0] 	= 	Old_Params[64]; 		//META 3 SUB 1
		Params.l_a_sub[3][1] 	= 	Old_Params[65];			//META 3 SUB 2
		Params.l_a_sub[3][2] 	= 	Old_Params[66];			//META 3 SUB 3
		Params.l_a_sub[3][3] 	= 	Old_Params[67];			//META 3 SUB 4
		//LARVAE FRAC SUCCESSFUL DISP
		Params.l_m_pop			= 	Old_Params[68]; 		//POP
		Params.l_m_meta[1]		= 	Old_Params[69];			//META 1
		Params.l_m_meta[2]		= 	Old_Params[70];			//META 2
		Params.l_m_meta[3]		= 	Old_Params[71];			//META 3
		Params.l_m_sub[1][0] 	= 	Old_Params[72];			//META 1 SUB 1
		Params.l_m_sub[1][1] 	= 	Old_Params[73];			//META 1 SUB 2
		Params.l_m_sub[1][2] 	= 	Old_Params[74];			//META 1 SUB 3
		Params.l_m_sub[1][3] 	= 	Old_Params[75];			//META 1 SUB 4
		Params.l_m_sub[2][0] 	= 	Old_Params[76];			//META 2 SUB 1
		Params.l_m_sub[2][1] 	= 	Old_Params[77];			//META 2 SUB 2
		Params.l_m_sub[2][2] 	= 	Old_Params[78];			//META 2 SUB 3
		Params.l_m_sub[2][3] 	= 	Old_Params[79];			//META 2 SUB 4
		Params.l_m_sub[3][0] 	= 	Old_Params[80];			//META 3 SUB 1
		Params.l_m_sub[3][1] 	= 	Old_Params[81];			//META 3 SUB 2
		Params.l_m_sub[3][2] 	= 	Old_Params[82];			//META 3 SUB 3
		Params.l_m_sub[3][3] 	= 	Old_Params[83];			//META 3 SUB 4
		//OBSERVATIONAL
		Params.FITINIT[4][0] 	= 	Old_Params[84]; 		//META 4 INITS
		Params.FITINIT[4][4] 	= 	Old_Params[85]; 		//META 4 INITV
		Params.FITINIT[4][8] 	= 	Old_Params[86]; 		//META 4 INITR
		Params.FITINIT[5][0] 	= 	Old_Params[87]; 		//META 5 INITS
		Params.FITINIT[5][4] 	= 	Old_Params[88]; 		//META 5 INITV
		Params.FITINIT[6][0] 	= 	Old_Params[89];	 		//META 6 INITS
		Params.FITINIT[6][4] 	= 	Old_Params[90]; 		//META 6 INITV
		Params.FITINIT[6][8] 	= 	Old_Params[91]; 		//META 6 INITR

		//--------MISER CALUCLATE LIKELIHOOD-------
		for (int j = 1; j <= 3; j++)
		{
			for(int i = 0; i < 10; i++)
			{
				Params.lhood_point[j][i] = 0.0;
			}
		}

		lhood_meta = 0; log_lhood_meta = 0; total_loghood_metas_OLD = 0;
		meta_err = 0;

		for (int j = 1; j <= 3; j++)				
		{
			Params.j = j;

			Params.miser_ticker = 1; Params.miser2_flag = 0; 

			gsl_monte_function G = { &likelihood_calc, dim, &Params };	

			double xl[dim];	double xu[dim];	
			for (int jj = 0; jj < dim; jj++)	
			{
				xl[jj] = 0;	
				xu[jj] = 1;
			}

			gsl_monte_miser_state *s = gsl_monte_miser_alloc(dim);
			gsl_monte_miser_integrate (&G, xl, xu, dim, Mcalls, r, s, &lhood_meta, &meta_err); 		//call MISER
			gsl_monte_miser_free(s);
			
			while (Params.miser2_flag > 0)		//indicates that a better likelihood score (or a few) were found
			{ 
				Params.miser2_flag = 0;
				Params.lhood_adjust[j] = -Params.bestlhood[j];
				
				gsl_monte_miser_state *s = gsl_monte_miser_alloc(dim);
				gsl_monte_miser_integrate (&G, xl, xu, dim, Mcalls, r, s, &lhood_meta, &meta_err); 
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
		if (verbose) printf("loghood OLD = %lf posterior OLD = %lf\n", total_loghood_metas_OLD, LogOldPosterior);
		
		//-----------AVERAGE DATA POINT LHOODS-----
		for (int j = 1; j <= 3; j++)
		{
			for(int i = 0; i < 10; i++)
			{
				old_lhood_pointwise[j][i] = Params.lhood_point[j][i]/Mcalls;
			}
		}

		if (LogOldPosterior > -1000000)
		{ 
			PreviousLogOldPosterior = LogOldPosterior;
		}
		if (LogOldPosterior < -10000000 & LoopNumber > 10)
		{
			printf("BUM POSTERIOR! assigning previous old \n");
			//getc(stdin);
			//printf("log old posterior = %lf\n", LogOldPosterior);
			LogOldPosterior = PreviousLogOldPosterior; //wash due to weird stochasticity, assign previous value
			//printf("previous old = %lf\n", PreviousLogOldPosterior);
			//getc(stdin);
		}
		//printf("log old posterior = %lf\n", LogOldPosterior);
		
		//--------EVALUTE NEW VERSUS OLD-------
		ProbOfAcceptance = exp((LogNewPosterior + LogJumpToOld) - (LogOldPosterior - LogJumpToNew));   

		if (verbose) printf("prob of acceptance first pass = %lf\n", ProbOfAcceptance);

		//if (isinf(ProbOfAcceptance))
		//{
		//	ProbOfAcceptance=1;
		//	printf("")
		//}
		Attempt = Attempt + 1;

		//--------IF NEW IS BETTER THAN OLD-------
		if (ProbOfAcceptance>1 || gsl_rng_uniform_pos (r) < ProbOfAcceptance)
		{ 
			if (verbose) printf("Accepted first pass. Recalculating new to avoid winner's curse.\n");
			//------RECALCULATE NEW------
			//INITV
			Params.FITINIT[1][4] 	= 	1e-6; 					//META 1 SUB 1
			Params.FITINIT[1][5] 	= 	0.2; 					//META 1 SUB 2
			Params.FITINIT[1][6] 	= 	0.2;					//META 1 SUB 3
			Params.FITINIT[1][7] 	= 	1e-6; 					//META 1 SUB 4
			Params.FITINIT[2][4] 	= 	1e-6; 					//META 2 SUB 1
			Params.FITINIT[2][5] 	= 	0.2; 					//META 2 SUB 2
			Params.FITINIT[2][6] 	= 	0.2; 					//META 2 SUB 3
			Params.FITINIT[2][7] 	= 	1e-6; 					//META 2 SUB 4
			Params.FITINIT[3][4] 	= 	1e-6; 					//META 3 SUB 1
			Params.FITINIT[3][5] 	= 	0.2; 					//META 3 SUB 2
			Params.FITINIT[3][6] 	= 	0.2; 					//META 3 SUB 3
			Params.FITINIT[3][7] 	= 	1e-6; 					//META 3 SUB 4
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
			Params.FITINIT[1][0] 	= 	New_Params[0]; 			//META 1 SUB 1
			Params.FITINIT[1][1] 	= 	New_Params[0]; 			//META 1 SUB 2
			Params.FITINIT[1][2] 	= 	New_Params[0]; 			//META 1 SUB 3
			Params.FITINIT[1][3] 	= 	New_Params[0]; 			//META 1 SUB 4
			Params.FITINIT[2][0] 	= 	New_Params[0]; 			//META 2 SUB 1
			Params.FITINIT[2][1] 	= 	New_Params[0]; 			//META 2 SUB 2
			Params.FITINIT[2][2] 	= 	New_Params[0]; 			//META 2 SUB 3
			Params.FITINIT[2][3] 	= 	New_Params[0]; 			//META 2 SUB 4
			Params.FITINIT[3][0] 	= 	New_Params[0]; 			//META 3 SUB 1
			Params.FITINIT[3][1] 	= 	New_Params[0]; 			//META 3 SUB 2
			Params.FITINIT[3][2] 	= 	New_Params[0]; 			//META 3 SUB 3
			Params.FITINIT[3][3] 	= 	New_Params[0]; 			//META 3 SUB 4
			//INITR
			Params.r_pop 			= 	New_Params[1];			//POP
			Params.r_meta[1] 		= 	New_Params[2];			//META 1
			Params.r_meta[2] 		= 	New_Params[3];			//META 2
			Params.r_meta[3] 		=	New_Params[4];			//META 3
			Params.FITINIT[1][8] 	= 	New_Params[5]; 			//META 1 SUB 1
			Params.FITINIT[2][8] 	= 	New_Params[6]; 			//META 2 SUB 1
			Params.FITINIT[2][9] 	= 	New_Params[7]; 			//META 2 SUB 2 
			Params.FITINIT[2][10] 	= 	New_Params[8]; 			//META 2 SUB 3
			Params.FITINIT[2][11] 	= 	New_Params[9]; 			//META 2 SUB 4
			Params.FITINIT[3][8] 	= 	New_Params[10]; 		//META 3 SUB 1
			Params.FITINIT[3][9] 	= 	New_Params[11]; 		//META 3 SUB 2
			Params.FITINIT[3][10] 	= 	New_Params[12]; 		//META 3 SUB 3
			Params.FITINIT[3][11] 	= 	New_Params[13]; 		//META 3 SUB 4
			//RSTOCH
			Params.R_stoch 			= 	New_Params[18];			//POP
			//FSTOCH
			Params.F_stoch			= 	New_Params[19];			//POP
			//CONIDIA 1/AVG DIST DISP
			Params.c_a_pop 			= 	New_Params[20];			//POP
			Params.c_a_meta[1] 		= 	New_Params[21];			//META 1
			Params.c_a_meta[2] 		= 	New_Params[22];			//META 2
			Params.c_a_meta[3] 		= 	New_Params[23];			//META 3
			Params.c_a_sub[1][0] 	= 	New_Params[24]; 		//META 1 SUB 1
			Params.c_a_sub[1][1] 	= 	New_Params[25];			//META 1 SUB 2
			Params.c_a_sub[1][2] 	= 	New_Params[26];			//META 1 SUB 3
			Params.c_a_sub[1][3] 	= 	New_Params[27];			//META 1 SUB 4
			Params.c_a_sub[2][0] 	= 	New_Params[28]; 		//META 2 SUB 1
			Params.c_a_sub[2][1] 	= 	New_Params[29];			//META 2 SUB 2
			Params.c_a_sub[2][2] 	= 	New_Params[30];			//META 2 SUB 3
			Params.c_a_sub[2][3] 	= 	New_Params[31];			//META 2 SUB 4
			Params.c_a_sub[3][0] 	= 	New_Params[32]; 		//META 3 SUB 1
			Params.c_a_sub[3][1] 	= 	New_Params[33];			//META 3 SUB 2
			Params.c_a_sub[3][2] 	= 	New_Params[34];			//META 3 SUB 3
			Params.c_a_sub[3][3] 	= 	New_Params[35];			//META 3 SUB 4
			//CONIDIA FRAC SUCCESSFUL DISP
			Params.c_m_pop			= 	New_Params[36]; 		//POP
			Params.c_m_meta[1]		= 	New_Params[37];			//META 1
			Params.c_m_meta[2]		= 	New_Params[38];			//META 2
			Params.c_m_meta[3]		= 	New_Params[39];			//META 3
			Params.c_m_sub[1][0] 	= 	New_Params[40];			//META 1 SUB 1
			Params.c_m_sub[1][1] 	= 	New_Params[41];			//META 1 SUB 2
			Params.c_m_sub[1][2]	= 	New_Params[42];			//META 1 SUB 3
			Params.c_m_sub[1][3] 	= 	New_Params[43];			//META 1 SUB 4
			Params.c_m_sub[2][0] 	= 	New_Params[44];			//META 2 SUB 1
			Params.c_m_sub[2][1] 	= 	New_Params[45];			//META 2 SUB 2
			Params.c_m_sub[2][2] 	= 	New_Params[46];			//META 2 SUB 3
			Params.c_m_sub[2][3] 	= 	New_Params[47];			//META 2 SUB 4
			Params.c_m_sub[3][0] 	= 	New_Params[48];			//META 3 SUB 1
			Params.c_m_sub[3][1] 	= 	New_Params[49];			//META 3 SUB 2
			Params.c_m_sub[3][2] 	= 	New_Params[50];			//META 3 SUB 3
			Params.c_m_sub[3][3] 	= 	New_Params[51];			//META 3 SUB 4
			//LARVAE 1/AVG DIST DISP
			//TEMP
			Params.l_a_pop 			= 	New_Params[52];			//POP
			Params.l_a_meta[1] 		= 	New_Params[53];			//META 1
			Params.l_a_meta[2] 		= 	New_Params[54];			//META 2
			Params.l_a_meta[3] 		= 	New_Params[55];			//META 3
			Params.l_a_sub[1][0] 	= 	New_Params[56];			//META 1 SUB 1
			Params.l_a_sub[1][1] 	= 	New_Params[57];			//META 1 SUB 2
			Params.l_a_sub[1][2] 	= 	New_Params[58];			//META 1 SUB 3
			Params.l_a_sub[1][3] 	= 	New_Params[59];			//META 1 SUB 4
			Params.l_a_sub[2][0] 	=	New_Params[60]; 		//META 2 SUB 1
			Params.l_a_sub[2][1] 	= 	New_Params[61];			//META 2 SUB 2
			Params.l_a_sub[2][2] 	= 	New_Params[62];			//META 2 SUB 3
			Params.l_a_sub[2][3] 	= 	New_Params[63];			//META 2 SUB 4
			Params.l_a_sub[3][0] 	= 	New_Params[64]; 		//META 3 SUB 1
			Params.l_a_sub[3][1] 	= 	New_Params[65];			//META 3 SUB 2
			Params.l_a_sub[3][2] 	= 	New_Params[66];			//META 3 SUB 3
			Params.l_a_sub[3][3] 	= 	New_Params[67];			//META 3 SUB 4
			//LARVAE FRAC SUCCESSFUL DISP
			Params.l_m_pop			= 	New_Params[68]; 		//POP
			Params.l_m_meta[1]		= 	New_Params[69];			//META 1
			Params.l_m_meta[2]		= 	New_Params[70];			//META 2
			Params.l_m_meta[3]		= 	New_Params[71];			//META 3
			Params.l_m_sub[1][0] 	= 	New_Params[72];			//META 1 SUB 1
			Params.l_m_sub[1][1] 	= 	New_Params[73];			//META 1 SUB 2
			Params.l_m_sub[1][2] 	= 	New_Params[74];			//META 1 SUB 3
			Params.l_m_sub[1][3] 	= 	New_Params[75];			//META 1 SUB 4
			Params.l_m_sub[2][0] 	= 	New_Params[76];			//META 2 SUB 1
			Params.l_m_sub[2][1] 	= 	New_Params[77];			//META 2 SUB 2
			Params.l_m_sub[2][2] 	= 	New_Params[78];			//META 2 SUB 3
			Params.l_m_sub[2][3] 	= 	New_Params[79];			//META 2 SUB 4
			Params.l_m_sub[3][0] 	= 	New_Params[80];			//META 3 SUB 1
			Params.l_m_sub[3][1] 	= 	New_Params[81];			//META 3 SUB 2
			Params.l_m_sub[3][2] 	= 	New_Params[82];			//META 3 SUB 3
			Params.l_m_sub[3][3] 	= 	New_Params[83];			//META 3 SUB 4
			//OBSERVATIONAL
			Params.FITINIT[4][0] 	= 	New_Params[84]; 		//META 4 INITS
			Params.FITINIT[4][4] 	= 	New_Params[85]; 		//META 4 INITV
			Params.FITINIT[4][8] 	= 	New_Params[86]; 		//META 4 INITR
			Params.FITINIT[5][0] 	= 	New_Params[87]; 		//META 5 INITS
			Params.FITINIT[5][4] 	= 	New_Params[88]; 		//META 5 INITV
			Params.FITINIT[6][0] 	= 	New_Params[89];	 		//META 6 INITS
			Params.FITINIT[6][4] 	= 	New_Params[90]; 		//META 6 INITV
			Params.FITINIT[6][8] 	= 	New_Params[91]; 		//META 6 INITR

			//--------MISER CALUCLATE LIKELIHOOD-------
			for (int j = 1; j <= 3; j++)
			{
				for(int i = 0; i < 10; i++)
				{
					Params.lhood_point[j][i] = 0.0;
				}
			}

			lhood_meta = 0; log_lhood_meta = 0; total_loghood_metas_NEW = 0;
			meta_err = 0;

			for (int j = 1; j <= 3; j++)				
			{
				Params.j = j;

				Params.miser_ticker = 1; Params.miser2_flag = 0; 

				gsl_monte_function G = { &likelihood_calc, dim, &Params };	

				double xl[dim];	double xu[dim];	
				for (int jj = 0; jj < dim; jj++)	
				{
					xl[jj] = 0;	
					xu[jj] = 1;
				}

				gsl_monte_miser_state *s = gsl_monte_miser_alloc(dim);
				gsl_monte_miser_integrate (&G, xl, xu, dim, Mcalls, r, s, &lhood_meta, &meta_err); 		//call MISER
				gsl_monte_miser_free(s);
				
				while (Params.miser2_flag > 0)		//indicates that a better likelihood score (or a few) were found
				{ 
					Params.miser2_flag = 0;
					Params.lhood_adjust[j] = -Params.bestlhood[j];
					
					gsl_monte_miser_state *s = gsl_monte_miser_alloc(dim);
					gsl_monte_miser_integrate (&G, xl, xu, dim, Mcalls, r, s, &lhood_meta, &meta_err); 
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
			if (verbose) printf("loghood NEW = %lf posterior NEW = %lf\n", total_loghood_metas_NEW, LogNewPosterior);
		
			//-----------AVERAGE DATA POINT LHOODS-----
			for (int j = 1; j <= 3; j++)
			{
				for(int i = 0; i < 10; i++)
				{
					new_lhood_pointwise[j][i] = Params.lhood_point[j][i]/Mcalls;
				}
			}

			//--------REEVALUATE OLD AND NEW-------
			ProbOfAcceptance = exp((LogNewPosterior + LogJumpToOld) - (LogOldPosterior - LogJumpToNew));  
			if (verbose) printf("prob of acceptance second pass = %lf\n", ProbOfAcceptance);
			//if (isinf(ProbOfAcceptance))
			//{ 
			//	ProbOfAcceptance=1;
			//}
			//--------IF BETTER, ACCEPT-------
			if (ProbOfAcceptance>1 || gsl_rng_uniform_pos (r) < ProbOfAcceptance)
			{
				if (verbose) printf("Accept new param set second pass\n");

				LogOldPosterior = LogNewPosterior;  
				total_loghood_metas_OLD = total_loghood_metas_NEW;

				for (a = 0; a < NUM_PARS; a++)
				{
					if (fit[a]) Old_Params[a] = New_Params[a]; 
				}
				for (int j = 1; j <= 3; j++)
				{
					for(int i = 0; i < 10; i++)
					{
						old_lhood_pointwise[j][i] = new_lhood_pointwise[j][i];
					}
				}
				Accept = Accept+1;
			}
			//--------IF WORSE, REJECT-------
			else
			{ 
				if (verbose) printf("Reject new param set second pass\n");

				for (a = 0; a < NUM_PARS; a++)
				{
					if (fit[a]) New_PC[a] = Old_PC[a];           
				}
				for (int j = 1; j <= 3; j++)
				{
					for(int i = 0; i < 10; i++)
					{
						new_lhood_pointwise[j][i] = old_lhood_pointwise[j][i];
					}
				}
			}
		}
		//--------IF WORSE, REJECT--------
		else
		{ 
			if (verbose) printf("Reject new param set first pass\n");

			for (a = 0; a < NUM_PARS; a++)
			{
				if (fit[a]) New_PC[a] = Old_PC[a];      
			}
			for (int j = 1; j <= 3; j++)
			{
				for(int i = 0; i < 10; i++)
				{
					new_lhood_pointwise[j][i] = old_lhood_pointwise[j][i];
				}
			}
		}
 
		fprintf(fpm, "%i ", LoopNumber); 

		for (int ii = 0; ii < NUM_PARS; ii++)
		{ 
			if (fit[ii]){
				if (log_fit[ii]) fprintf(fpm, "%lf ", log(Old_Params[ii]));
				else fprintf(fpm, "%lf ", Old_Params[ii]);
			} 
		}
		fprintf(fpm, "%lf %lf %i %i ", total_loghood_metas_OLD, LogOldPosterior, Accept, Attempt); 
		
		for (int j = 1; j <= 3; j++)
		{
				for(int i = 0; i < 10; i++)
				{
					fprintf(fpm, "%lf ", log(old_lhood_pointwise[j][i]));
				}
		}

		fprintf(fpm, "\n");		
		fflush(stdout);
		fflush(fpm);
	}	

	fclose(fpm);

}

time_t end = time(NULL);

printf("All iterations took %f seconds\n", difftime(end, start));

return 0;

}

