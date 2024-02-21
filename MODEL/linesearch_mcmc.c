#include "head.h"
gsl_rng *r;

///////////////////////////////////////////////////DOT-PRODUCT///////////////////////////////////////////////////
float dot_product (int len, double (*holder)[len], double *pca)
{
	double answer = 0.0;
	int i;
	for(i = 0; i < len; i++)
	{
		answer += pca[i] * (*holder)[i];
	}
	return(answer);
}

int main(int argc, char *argv[])
{
///////////////////////////////////////////////////SET-UP///////////////////////////////////////////////////

#define VERBOSE 0 				//select 1 for detailed output
#define MAXITNLS 3				// number of linesearch full parameter sweeps to run
#define MAXITNMCMC 5000			// number of mcmc iterations to run

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

			par_sto = ls_bound(model, i, 1) + (ls_bound(model,i,2) - ls_bound(model,i,1)) * jumper;

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
					jumps[i] = (ls_bound(model, i, 2) - ls_bound(model, i, 1)) / jumper;
				}
			}

			old_posterior = -6666666666666;
		}
		for (int j = 0; j < NUM_PARS; j++) 
		{ 
			if (fit[j])
			{
				if (verbose) printf("staring with %d until ls_tmp = %lf\n", j, ls_bound(model, j, 2));

				for (ls_tmp = ls_bound(model, j, 1) + jumps[j], j_iter = 0; ls_tmp <= ls_bound(model, j, 2); ls_tmp += jumps[j])
				{
					if (verbose) printf("tmp param[%i] = %lf from exp(%lf)\n", j, exp(ls_tmp), ls_tmp);

					par_sto = new_params[j]; //store old value of param

					if (log_fit[j])
					{
						new_params[j] = exp(ls_tmp); //tweak param		
					} else {
						new_params[j] = ls_tmp;
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
								lprior = log(gsl_ran_flat_pdf(new_params[k], exp(ls_bound(model,k,1)), (exp(ls_bound(model,k,1)) + exp(ls_bound(model,k,2)))));

							} else {

								lprior = log(gsl_ran_flat_pdf(new_params[k], ls_bound(model,k,1), (ls_bound(model,k,1) + ls_bound(model,k,2))));
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
				printf("%lf ", log(new_params[j]));
			}
		}
		printf("\n");
	}

	for (int j = 0; j < NUM_PARS; j++)
	{
		if (fit[j])
		{
			fprintf(fpls, "%lf ", log(new_params[j]));
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
/*
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

		FILE *fileR;

		//---------PARAMS----------
		double new_log_prior = 0;
		double log_prior = 0;
		double real_params[num_ltfparams];
		for(int a; a < num_ltfparams; a++)
		{
			real_params[a] = 0.0;
		}

		//------READ IN PARAMS-----
		fileR = fopen(RealParams, "r");         
		for (a = 0; a < (num_ltfparams); a++)
		{
			if (fit[a] == 1) fscanf(fileR, "%lf\n", &real_params[a]);
		}
		fclose(fileR);

		//HOW DO I SUBSET TO RUN THIS FOR ONE PARAM SET AT A TIME????? //try with one set then expand
		//maybe use a while loop -- while something != EOF

		//----------CALCULATE PRIORS-------
		for (int k = 0; k < num_ltfparams; k++)
		{
			if (fit[k] == 1)
			{
				if (log_fit[k] == 1)	//log fit
				{ 
					new_log_prior = log(gsl_ran_flat_pdf(exp(real_params[k]), exp(ls_bound(model,k,1)), (exp(ls_bound(model,k,1)) + exp(ls_bound(model,k,2)))));
					//printf("param %i = %lf\n", k, ltf_params[k]);
					//printf("newlog prior = %lf\n", new_log_prior);
				}
				else 					//non-log fit
				{ 
					new_log_prior = log(gsl_ran_flat_pdf(real_params[k], ls_bound(model,k,1), (ls_bound(model,k,1) + ls_bound(model,k,2))));
					//printf("param %i = %lf\n", k, ltf_params[k]);
					//printf("newlog prior = %lf\n", new_log_prior);
				}
				if (isnan(new_log_prior) || isinf(new_log_prior)) 	//outside of bounds
				{ 
					printf("PROBLEM WITH PRIORS\n k=%i\t new log prior = %lf\n", k, new_log_prior);
					new_log_prior = -999999;	//assign bad score
				}
				log_prior =+ new_log_prior;
			}
		}
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
		Params.FITINIT[1][0] 	= 	real_params[0];			//META 1 SUB 1
		Params.FITINIT[1][1] 	= 	real_params[0];			//META 1 SUB 2
		Params.FITINIT[1][2] 	= 	real_params[0];			//META 1 SUB 3
		Params.FITINIT[1][3] 	= 	real_params[0];			//META 1 SUB 4
		Params.FITINIT[2][0] 	= 	real_params[0];			//META 2 SUB 1
		Params.FITINIT[2][1] 	= 	real_params[0];			//META 2 SUB 2
		Params.FITINIT[2][2] 	= 	real_params[0];			//META 2 SUB 3
		Params.FITINIT[2][3] 	= 	real_params[0];			//META 2 SUB 4
		Params.FITINIT[3][0] 	= 	real_params[0];			//META 3 SUB 1
		Params.FITINIT[3][1] 	= 	real_params[0];			//META 3 SUB 2
		Params.FITINIT[3][2] 	= 	real_params[0];			//META 3 SUB 3
		Params.FITINIT[3][3] 	= 	real_params[0];			//META 3 SUB 4
		//INITR
		Params.r_pop 			= 	real_params[1];			//POP
		Params.r_meta[1] 		= 	real_params[2];			//META 1
		Params.r_meta[2] 		= 	real_params[3];			//META 2
		Params.r_meta[3] 		=	real_params[4];			//META 3
		Params.FITINIT[1][8] 	= 	real_params[5]; 		//META 1 SUB 1
		Params.FITINIT[2][8] 	= 	real_params[6];			//META 2 SUB 1
		Params.FITINIT[2][9] 	= 	real_params[7]; 		//META 2 SUB 2 
		Params.FITINIT[2][10] 	= 	real_params[8];			//META 2 SUB 3
		Params.FITINIT[2][11] 	= 	real_params[9];			//META 2 SUB 4
		Params.FITINIT[3][8] 	= 	real_params[10]; 		//META 3 SUB 1
		Params.FITINIT[3][9] 	= 	real_params[11];		//META 3 SUB 2
		Params.FITINIT[3][10] 	= 	real_params[12]; 		//META 3 SUB 3
		Params.FITINIT[3][11] 	= 	real_params[13]; 		//META 3 SUB 4
		//RSTOCH
		Params.R_stoch 			=	real_params[18];		//POP
		//FSTOCH
		Params.F_stoch			= 	real_params[19];		//POP
		//CONIDIA 1/AVG DIST DISP
		Params.c_a_pop 			= 	real_params[20];		//POP
		Params.c_a_meta[1] 		= 	real_params[21];		//META 1
		Params.c_a_meta[2] 		= 	real_params[22];		//META 2
		Params.c_a_meta[3] 		= 	real_params[23];		//META 3
		Params.c_a_sub[1][0] 	= 	real_params[24]; 		//META 1 SUB 1
		Params.c_a_sub[1][1] 	= 	real_params[25];		//META 1 SUB 2
		Params.c_a_sub[1][2] 	= 	real_params[26];		//META 1 SUB 3
		Params.c_a_sub[1][3] 	= 	real_params[27];		//META 1 SUB 4
		Params.c_a_sub[2][0] 	= 	real_params[28]; 		//META 2 SUB 1
		Params.c_a_sub[2][1] 	= 	real_params[29];		//META 2 SUB 2
		Params.c_a_sub[2][2] 	= 	real_params[30];		//META 2 SUB 3
		Params.c_a_sub[2][3] 	= 	real_params[31];		//META 2 SUB 4
		Params.c_a_sub[3][0] 	= 	real_params[32]; 		//META 3 SUB 1
		Params.c_a_sub[3][1] 	= 	real_params[33];		//META 3 SUB 2
		Params.c_a_sub[3][2] 	= 	real_params[34];		//META 3 SUB 3
		Params.c_a_sub[3][3] 	= 	real_params[35];		//META 3 SUB 4
		//CONIDIA FRAC SUCCESSFUL DISP
		Params.c_m_pop			= 	real_params[36]; 		//POP
		Params.c_m_meta[1]		= 	real_params[37];		//META 1
		Params.c_m_meta[2]		= 	real_params[38];		//META 2
		Params.c_m_meta[3]		= 	real_params[39];		//META 3
		Params.c_m_sub[1][0] 	= 	real_params[40];		//META 1 SUB 1
		Params.c_m_sub[1][1] 	= 	real_params[41];		//META 1 SUB 2
		Params.c_m_sub[1][2]	= 	real_params[42];		//META 1 SUB 3
		Params.c_m_sub[1][3] 	= 	real_params[43];		//META 1 SUB 4
		Params.c_m_sub[2][0] 	= 	real_params[44];		//META 2 SUB 1
		Params.c_m_sub[2][1] 	= 	real_params[45];		//META 2 SUB 2
		Params.c_m_sub[2][2] 	= 	real_params[46];		//META 2 SUB 3
		Params.c_m_sub[2][3] 	= 	real_params[47];		//META 2 SUB 4
		Params.c_m_sub[3][0] 	= 	real_params[48];		//META 3 SUB 1
		Params.c_m_sub[3][1] 	= 	real_params[49];		//META 3 SUB 2
		Params.c_m_sub[3][2] 	= 	real_params[50];		//META 3 SUB 3
		Params.c_m_sub[3][3] 	= 	real_params[51];		//META 3 SUB 4
		//LARVAE 1/AVG DIST DISP
		Params.l_a_pop 			= 	real_params[52];		//POP
		Params.l_a_meta[1] 		= 	real_params[53];		//META 1
		Params.l_a_meta[2] 		= 	real_params[54];		//META 2
		Params.l_a_meta[3] 		= 	real_params[55];		//META 3
		Params.l_a_sub[1][0] 	= 	real_params[56];		//META 1 SUB 1
		Params.l_a_sub[1][1] 	= 	real_params[57];		//META 1 SUB 2
		Params.l_a_sub[1][2] 	= 	real_params[58];		//META 1 SUB 3
		Params.l_a_sub[1][3] 	= 	real_params[59];		//META 1 SUB 4
		Params.l_a_sub[2][0] 	=	real_params[60]; 		//META 2 SUB 1
		Params.l_a_sub[2][1] 	= 	real_params[61];		//META 2 SUB 2
		Params.l_a_sub[2][2] 	= 	real_params[62];		//META 2 SUB 3
		Params.l_a_sub[2][3] 	= 	real_params[63];		//META 2 SUB 4
		Params.l_a_sub[3][0] 	= 	real_params[64]; 		//META 3 SUB 1
		Params.l_a_sub[3][1] 	= 	real_params[65];		//META 3 SUB 2
		Params.l_a_sub[3][2] 	= 	real_params[66];		//META 3 SUB 3
		Params.l_a_sub[3][3] 	= 	real_params[67];		//META 3 SUB 4
		//LARVAE FRAC SUCCESSFUL DISP
		Params.l_m_pop			= 	real_params[68]; 		//POP
		Params.l_m_meta[1]		= 	real_params[69];		//META 1
		Params.l_m_meta[2]		= 	real_params[70];		//META 2
		Params.l_m_meta[3]		= 	real_params[71];		//META 3
		Params.l_m_sub[1][0] 	= 	real_params[72];		//META 1 SUB 1
		Params.l_m_sub[1][1] 	= 	real_params[73];		//META 1 SUB 2
		Params.l_m_sub[1][2] 	= 	real_params[74];		//META 1 SUB 3
		Params.l_m_sub[1][3] 	= 	real_params[75];		//META 1 SUB 4
		Params.l_m_sub[2][0] 	= 	real_params[76];		//META 2 SUB 1
		Params.l_m_sub[2][1] 	= 	real_params[77];		//META 2 SUB 2
		Params.l_m_sub[2][2] 	= 	real_params[78];		//META 2 SUB 3
		Params.l_m_sub[2][3] 	= 	real_params[79];		//META 2 SUB 4
		Params.l_m_sub[3][0] 	= 	real_params[80];		//META 3 SUB 1
		Params.l_m_sub[3][1] 	= 	real_params[81];		//META 3 SUB 2
		Params.l_m_sub[3][2] 	= 	real_params[82];		//META 3 SUB 3
		Params.l_m_sub[3][3] 	= 	real_params[83];		//META 3 SUB 4
		//OBSERVATIONAL
		Params.FITINIT[4][0] 	= 	real_params[84]; 		//META 4 INITS
		Params.FITINIT[4][4] 	= 	real_params[85]; 		//META 4 INITV
		Params.FITINIT[4][8] 	= 	real_params[86]; 		//META 4 INITR
		Params.FITINIT[5][0] 	= 	real_params[87]; 		//META 5 INITS
		Params.FITINIT[5][4] 	= 	real_params[88]; 		//META 5 INITV
		Params.FITINIT[6][0] 	= 	real_params[89];	 	//META 6 INITS
		Params.FITINIT[6][4] 	= 	real_params[90]; 		//META 6 INITV
		Params.FITINIT[6][8] 	= 	real_params[91]; 		//META 6 INITR

		//--------GENERATE REALIZATIONS USING MISER-------
		double lhood_meta; double log_lhood_meta; double total_loghood_metas = 0;
		double new_posterior = 0;
		double meta_err = 0;

		for (int j = 1; j <= 3; j++)
		{
			Params.j = j;
			//TEST
			Params.miser_ticker = 1; Params.miser2_flag = 0;

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

			while (Params.miser2_flag > 0)		//indicates that a better likelihood score (or a few) were found
			{ 
				Params.miser2_flag = 0;
				Params.lhood_adjust[j] = -Params.bestlhood[j];
				
				gsl_monte_miser_state *s = gsl_monte_miser_alloc(dim);
				gsl_monte_miser_integrate (&G, xl, xu, dim, LScalls, r, s, &lhood_meta, &meta_err); 
				gsl_monte_miser_free(s);
			}
			
			log_lhood_meta = log(lhood_meta) - Params.lhood_adjust[j];
			//printf("lhood meta = %lf\n", lhood_meta);
			//printf("loghood [%i] = %lf\n", j, log(lhood_meta));

			if (isnan(log_lhood_meta) || isinf(log_lhood_meta))
			{
				log_lhood_meta = -99999999;
			}
			
			total_loghood_metas += log_lhood_meta;
		}
		new_posterior = total_loghood_metas + log_prior;

		fprintf(fpr, "%lf %lf\n", total_loghood_metas, new_posterior);

		fclose(fpr); 
		fclose(fpme);
	}
*/
///////////////////////////////////////////////////MCMC//////////////////////////////////////////////////////////
if (mcmc == 1)
{
	#define THIN 1 

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

	double rotations[NUM_PARS][NUM_PARS];
	double scale[NUM_PARS], center[NUM_PARS], sd[NUM_PARS];
	int var_import[NUM_PARS];

	for (i = 0; i < NUM_PARS; i++)
	{
		scale[i] = center[i] = sd[i] = 0.0;
		for (int j = 0; j < NUM_PARS; j++)
		{
			rotations[i][j] = 0.0;
		}
	}

	//--------READ IN LINESEARCH RESULTS-----
	file = fopen(rotsfp, "r");       
  
	for (i = 0; i < NUM_PARS; i++)
		if (fit[i])
		{
			for(k = 0; k < NUM_PARS; k++)
			{
				if (fit[k]) fscanf(file, "%lf ", &rotations[i][k]);
				if (verbose && fit[k]) printf("i,j:%d%d Rotation:%e\n", i, k, rotations[i][k]);
			}
			fscanf(file,"\n");
		}
	fclose(file);

	file = fopen(sclsfp, "r");  
	for (i = 0; i < NUM_PARS; i++)
	{
		if (fit[i]) fscanf(file, "%lf ", &scale[i]);
		if (verbose && fit[i]) printf("i:%d Scale:%e\n", i, scale[i]);
	}
	fclose(file);

	file = fopen(ctrsfp, "r");       
	for (i = 0; i < NUM_PARS; i++)
	{
		if (fit[i]) fscanf(file, "%lf ", &center[i]);
		if (verbose && fit[i]) printf("i:%d Center:%e\n", i, scale[i]);
	}
	fclose(file);

	file = fopen(sdsfp, "r");      
	for (i = 0; i < NUM_PARS; i++)
	{
		if (fit[i]) fscanf(file, "%lf ", &sd[i]);
		if (verbose && fit[i]) printf("i:%d SD:%e\n", i, scale[i]);
	}
	fclose(file);

	file = fopen(imptfp, "r");      
	for (i = 0; i < NUM_PARS; i++)
	{
		if (fit[i]) fscanf(file, "%d ", &var_import[i]);
		if (verbose && fit[i]) printf("i:%d Impt:%d\n", i, var_import[i]);
	}
	fclose(file);

	double pca[NUM_PARS], old_pca[NUM_PARS];
	double old_params[NUM_PARS], new_params[NUM_PARS];
	double var_scale = 1.2;
	double criterion, mc_temp;
	float dot_holder;
	double rejection;
	int thin = THIN;
	int burnin = MAXITNMCMC; //itertion step after which to propose for every PC each iteration. Set to MAXINT to avoid.
	size_t max_itn = MAXITNMCMC;

	double meta_err;

	double new_posterior, old_posterior;
	double lprior, old_lprior, new_lprior;
	double new_prop_adj, old_prop_adj;

	double new_lhood = 0.0;
	double old_lhood = 1e+10;
	double new_lhood_meta, old_lhood_meta;
	double new_lhood_pop, old_lhood_pop;

	double new_lhood_pointwise[DATA_SETS+1][NUM_POINTWISE];
	double old_lhood_pointwise[DATA_SETS+1][NUM_POINTWISE];

	new_posterior = old_posterior = 0.0;	
	new_lhood = old_lhood = 0.0;

	int stop = 0;
	int stop_counter = 0;
	int redo = 0;
	int check_last_par = 0;
	int accept = 0;
	int attempt = 0;
	int recent_a = 0;
	int accept_hall_pass = 0;
	
	//-------GENERATE INITIAL PCS--------
	stop = 1;

	while (stop && stop_counter < NUM_PARS)
	{
		if (verbose) printf("Generating first PC set\n");

		for (a = 0; a < NUM_PARS; a++)
		{
			if (fit[a])
			{
				old_pca[a] = pca[a] = gsl_ran_gaussian(r, var_scale * sd[a]);
				if (verbose) printf("PC %d = %e\n", a, pca[a]);
			} else {
				old_pca[a] = pca[a] = 0.0;
			}
		}

		stop = 0;

		for (a = 0; a < NUM_PARS; a++)
		{
			if (fit[a])
			{
				dot_holder = dot_product(NUM_PARS, rotations + a, pca);
				new_params[a] = old_params[a] = exp(dot_holder * var_scale * scale[a] + center[a]);
				if (verbose) printf("init value param %i = %lf\n", a, old_params[a]);

				if (log_fit[a])
				{
					if(log(old_params[a]) > ls_bound(model, a, 2) || log(old_params[a]) < ls_bound(model, a, 1))
					{
						stop = 1;
						stop_counter++;
					}

				} else {

					if(old_params[a] > ls_bound(model, a, 2) || old_params[a] < ls_bound(model, a, 1))
					{
						stop = 1;
						stop_counter++;
					}
				}

			} else {
				new_params[a] = old_params[a] = 0.0;
			}
		}
	}

	if (verbose) printf("Generating set took %d attempts\n", stop_counter);

	//------CALCULATE INITIAL LIKELIHOOD----
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
	Params.FITINIT[1][0] 	= 	old_params[0]; 			//META 1 SUB 1
	Params.FITINIT[1][1] 	= 	old_params[0]; 			//META 1 SUB 2
	Params.FITINIT[1][2] 	= 	old_params[0]; 			//META 1 SUB 3
	Params.FITINIT[1][3] 	= 	old_params[0]; 			//META 1 SUB 4
	Params.FITINIT[2][0] 	= 	old_params[0]; 			//META 2 SUB 1
	Params.FITINIT[2][1] 	= 	old_params[0]; 			//META 2 SUB 2
	Params.FITINIT[2][2] 	= 	old_params[0]; 			//META 2 SUB 3
	Params.FITINIT[2][3] 	= 	old_params[0]; 			//META 2 SUB 4
	Params.FITINIT[3][0] 	= 	old_params[0]; 			//META 3 SUB 1
	Params.FITINIT[3][1] 	= 	old_params[0]; 			//META 3 SUB 2
	Params.FITINIT[3][2] 	= 	old_params[0]; 			//META 3 SUB 3
	Params.FITINIT[3][3] 	= 	old_params[0]; 			//META 3 SUB 4
	//INITR
	Params.r_pop 			= 	old_params[1];			//POP
	Params.r_meta[1] 		= 	old_params[2];			//META 1
	Params.r_meta[2] 		= 	old_params[3];			//META 2
	Params.r_meta[3] 		=	old_params[4];			//META 3
	Params.FITINIT[1][8] 	= 	old_params[5]; 			//META 1 SUB 1
	Params.FITINIT[2][8] 	= 	old_params[6]; 			//META 2 SUB 1
	Params.FITINIT[2][9] 	= 	old_params[7]; 			//META 2 SUB 2 
	Params.FITINIT[2][10] 	= 	old_params[8]; 			//META 2 SUB 3
	Params.FITINIT[2][11] 	= 	old_params[9]; 			//META 2 SUB 4
	Params.FITINIT[3][8] 	= 	old_params[10]; 		//META 3 SUB 1
	Params.FITINIT[3][9] 	= 	old_params[11]; 		//META 3 SUB 2
	Params.FITINIT[3][10] 	= 	old_params[12]; 		//META 3 SUB 3
	Params.FITINIT[3][11] 	= 	old_params[13]; 		//META 3 SUB 4
	//RSTOCH
	Params.R_stoch 			= 	old_params[18];			//POP
	//FSTOCH
	Params.F_stoch			= 	old_params[19];			//POP
	//CONIDIA 1/AVG DIST DISP
	Params.c_a_pop 			= 	old_params[20];			//POP
	Params.c_a_meta[1] 		= 	old_params[21];			//META 1
	Params.c_a_meta[2] 		= 	old_params[22];			//META 2
	Params.c_a_meta[3] 		= 	old_params[23];			//META 3
	Params.c_a_sub[1][0] 	= 	old_params[24]; 		//META 1 SUB 1
	Params.c_a_sub[1][1] 	= 	old_params[25];			//META 1 SUB 2
	Params.c_a_sub[1][2] 	= 	old_params[26];			//META 1 SUB 3
	Params.c_a_sub[1][3] 	= 	old_params[27];			//META 1 SUB 4
	Params.c_a_sub[2][0] 	= 	old_params[28]; 		//META 2 SUB 1
	Params.c_a_sub[2][1] 	= 	old_params[29];			//META 2 SUB 2
	Params.c_a_sub[2][2] 	= 	old_params[30];			//META 2 SUB 3
	Params.c_a_sub[2][3] 	= 	old_params[31];			//META 2 SUB 4
	Params.c_a_sub[3][0] 	= 	old_params[32]; 		//META 3 SUB 1
	Params.c_a_sub[3][1] 	= 	old_params[33];			//META 3 SUB 2
	Params.c_a_sub[3][2] 	= 	old_params[34];			//META 3 SUB 3
	Params.c_a_sub[3][3] 	= 	old_params[35];			//META 3 SUB 4
	//CONIDIA FRAC SUCCESSFUL DISP
	Params.c_m_pop			= 	old_params[36]; 		//POP
	Params.c_m_meta[1]		= 	old_params[37];			//META 1
	Params.c_m_meta[2]		= 	old_params[38];			//META 2
	Params.c_m_meta[3]		= 	old_params[39];			//META 3
	Params.c_m_sub[1][0] 	= 	old_params[40];			//META 1 SUB 1
	Params.c_m_sub[1][1] 	= 	old_params[41];			//META 1 SUB 2
	Params.c_m_sub[1][2]	= 	old_params[42];			//META 1 SUB 3
	Params.c_m_sub[1][3] 	= 	old_params[43];			//META 1 SUB 4
	Params.c_m_sub[2][0] 	= 	old_params[44];			//META 2 SUB 1
	Params.c_m_sub[2][1] 	= 	old_params[45];			//META 2 SUB 2
	Params.c_m_sub[2][2] 	= 	old_params[46];			//META 2 SUB 3
	Params.c_m_sub[2][3] 	= 	old_params[47];			//META 2 SUB 4
	Params.c_m_sub[3][0] 	= 	old_params[48];			//META 3 SUB 1
	Params.c_m_sub[3][1] 	= 	old_params[49];			//META 3 SUB 2
	Params.c_m_sub[3][2] 	= 	old_params[50];			//META 3 SUB 3
	Params.c_m_sub[3][3] 	= 	old_params[51];			//META 3 SUB 4
	//LARVAE 1/AVG DIST DISP
	//TEMP
	Params.l_a_pop 			= 	old_params[52];			//POP
	Params.l_a_meta[1] 		= 	old_params[53];			//META 1
	Params.l_a_meta[2] 		= 	old_params[54];			//META 2
	Params.l_a_meta[3] 		= 	old_params[55];			//META 3
	Params.l_a_sub[1][0] 	= 	old_params[56];			//META 1 SUB 1
	Params.l_a_sub[1][1] 	= 	old_params[57];			//META 1 SUB 2
	Params.l_a_sub[1][2] 	= 	old_params[58];			//META 1 SUB 3
	Params.l_a_sub[1][3] 	= 	old_params[59];			//META 1 SUB 4
	Params.l_a_sub[2][0] 	=	old_params[60]; 		//META 2 SUB 1
	Params.l_a_sub[2][1] 	= 	old_params[61];			//META 2 SUB 2
	Params.l_a_sub[2][2] 	= 	old_params[62];			//META 2 SUB 3
	Params.l_a_sub[2][3] 	= 	old_params[63];			//META 2 SUB 4
	Params.l_a_sub[3][0] 	= 	old_params[64]; 		//META 3 SUB 1
	Params.l_a_sub[3][1] 	= 	old_params[65];			//META 3 SUB 2
	Params.l_a_sub[3][2] 	= 	old_params[66];			//META 3 SUB 3
	Params.l_a_sub[3][3] 	= 	old_params[67];			//META 3 SUB 4
	//LARVAE FRAC SUCCESSFUL DISP
	Params.l_m_pop			= 	old_params[68]; 		//POP
	Params.l_m_meta[1]		= 	old_params[69];			//META 1
	Params.l_m_meta[2]		= 	old_params[70];			//META 2
	Params.l_m_meta[3]		= 	old_params[71];			//META 3
	Params.l_m_sub[1][0] 	= 	old_params[72];			//META 1 SUB 1
	Params.l_m_sub[1][1] 	= 	old_params[73];			//META 1 SUB 2
	Params.l_m_sub[1][2] 	= 	old_params[74];			//META 1 SUB 3
	Params.l_m_sub[1][3] 	= 	old_params[75];			//META 1 SUB 4
	Params.l_m_sub[2][0] 	= 	old_params[76];			//META 2 SUB 1
	Params.l_m_sub[2][1] 	= 	old_params[77];			//META 2 SUB 2
	Params.l_m_sub[2][2] 	= 	old_params[78];			//META 2 SUB 3
	Params.l_m_sub[2][3] 	= 	old_params[79];			//META 2 SUB 4
	Params.l_m_sub[3][0] 	= 	old_params[80];			//META 3 SUB 1
	Params.l_m_sub[3][1] 	= 	old_params[81];			//META 3 SUB 2
	Params.l_m_sub[3][2] 	= 	old_params[82];			//META 3 SUB 3
	Params.l_m_sub[3][3] 	= 	old_params[83];			//META 3 SUB 4
	//OBSERVATIONAL
	Params.FITINIT[4][0] 	= 	old_params[84]; 		//META 4 INITS
	Params.FITINIT[4][4] 	= 	old_params[85]; 		//META 4 INITV
	Params.FITINIT[4][8] 	= 	old_params[86]; 		//META 4 INITR
	Params.FITINIT[5][0] 	= 	old_params[87]; 		//META 5 INITS
	Params.FITINIT[5][4] 	= 	old_params[88]; 		//META 5 INITV
	Params.FITINIT[6][0] 	= 	old_params[89];	 		//META 6 INITS
	Params.FITINIT[6][4] 	= 	old_params[90]; 		//META 6 INITV
	Params.FITINIT[6][8] 	= 	old_params[91]; 		//META 6 INITR

	//--------MISER CALUCLATE LIKELIHOOD-------
	for (int j = 1; j <= 3; j++)
	{
		for(int i = 0; i < 10; i++)
		{
			Params.lhood_point[j][i] = 0.0;
		}
	}

	old_lhood_pop = 0;

	for (int j = 1; j <= 3; j++)				
	{
		old_lhood_meta = old_lhood = meta_err = 0;

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
		gsl_monte_miser_integrate (&G, xl, xu, dim, LScalls, r, s, &old_lhood, &meta_err); 		//call MISER
		gsl_monte_miser_free(s);
		
		while (Params.miser2_flag > 0)		//indicates that a better likelihood score (or a few) were found
		{ 
			Params.miser2_flag = 0;
			Params.lhood_adjust[j] = -Params.bestlhood[j];
			
			gsl_monte_miser_state *s = gsl_monte_miser_alloc(dim);
			gsl_monte_miser_integrate (&G, xl, xu, dim, LScalls, r, s, &old_lhood, &meta_err); 
			gsl_monte_miser_free(s);
		}

		old_lhood_meta = log(old_lhood) - Params.lhood_adjust[j];
		//printf("old lhood = %lf old lhood meta = %lf\n", old_lhood, old_lhood_meta);

		if (isnan(old_lhood_meta) || isinf(old_lhood_meta))			//assign bad score to errors
		{ 
			old_lhood_meta = -99999;
		}
		
		old_lhood_pop += old_lhood_meta;
		//printf("old lhood pop = %lf\n", old_lhood_pop);
	}
	//-----------AVERAGE DATA POINT LHOODS-----
	for (int j = 1; j <= 3; j++)
	{
		for(int i = 0; i < 10; i++)
		{
			old_lhood_pointwise[j][i] = Params.lhood_point[j][i]/LScalls;
		}
	}
	//------------CALCULATE AND ADD PRIOR----------
	old_posterior = old_lprior = lprior = 0;

	for (int k = 0; k < NUM_PARS; k++)
	{
		if (fit[k])
		{
			if (log_fit[k])
			{ 
				lprior = log(gsl_ran_flat_pdf(old_params[k], exp(ls_bound(model,k,1)), (exp(ls_bound(model,k,1)) + exp(ls_bound(model,k,2)))));
				if (verbose) printf("old prior for param %i log value %lf = %lf\n", k, old_params[k], lprior);

			} else {

				lprior = log(gsl_ran_flat_pdf(old_params[k], ls_bound(model,k,1), (ls_bound(model,k,1) + ls_bound(model,k,2))));
				if (verbose) printf("old prior for param %i value %lf = %lf\n", k, old_params[k], lprior);

			}
			if (isnan(lprior) || isinf(lprior)) 	//outside of bounds
			{ 
				lprior = -750;	//assign bad score
			}
			old_lprior += lprior;
			//printf("old l prior = %lf\n", old_lprior);
		}
	}

	old_posterior = old_lhood_pop + old_lprior;
	//printf("old post = %lf old lhood pop = %lf old prior = %lf\n", old_posterior, old_lhood_pop, old_lprior);

	//-------BEGIN PCA-ADJ MH-MCMC--------
	for (j_iter = 0; j_iter < max_itn; j_iter++)
	{

		check_last_par = 1;
		attempt = 0;

		for (a = 0; a < NUM_PARS; a++)
		{
			if (fit[a] && (j_iter > burnin || j_iter % var_import[a] == 0))
			{
				recent_a = a;
				old_prop_adj = log( gsl_ran_gaussian_pdf(old_pca[a], var_scale * sd[a]) );

				if (redo)
				{
					if (verbose) printf("Recalcuating posterior for par %d\n", a);

					if(!check_last_par)
					{
						if (verbose) printf("This recalculation is part of an end of iteration check. Setting PCA to stored OLD PCA.\n");
					
						for (b = 0; b < NUM_PARS; b++)
						{
							pca[b] = old_pca[b];
						}
						for (b = 0; b < NUM_PARS; b++)
						{
							if (fit[b])
							{
								dot_holder = dot_product(NUM_PARS, rotations + b, pca);
								new_params[b] = exp(dot_holder * scale[b] + center[b]);
							}
						}
					}
				} else {
					attempt++;
					stop = 1;
					while(stop)
					{
						pca[a] = gsl_ran_gaussian(r, var_scale * sd[a]);
						stop = 0;
						for (b = 0; b < NUM_PARS; b++)
						{
							if (fit[b])
							{
								dot_holder = dot_product(NUM_PARS, rotations + b, pca);
								new_params[b] = exp(dot_holder * scale[b] + center[b]);

								if (log_fit[b])
								{
									if(log(new_params[b]) > ls_bound(model, b, 2) || log(new_params[b]) < ls_bound(model, b, 1))
									{
										stop = 1;
										if (verbose) printf("%lf is an invalid value for par %d. Trying again...\n", new_params[b], b);
									}
								} else {
									if(new_params[b] > ls_bound(model, b, 2) || new_params[b] < ls_bound(model, b, 1))
									{
										stop = 1;
										if (verbose) printf("%lf is an invalid value for par %d. Trying again...\n", new_params[b], b);
									}
								}

							}
						}
					}
				}
				new_prop_adj = 0;
				new_prop_adj = log(gsl_ran_gaussian_pdf(pca[a], var_scale * sd[a]));
				//printf("PROP ADJ = %lf pca[%i] = %lf varscale = %lf sd[%i] = %lf\n", new_prop_adj, a, pca[a], var_scale, a, sd[a]);
				if (verbose) printf("Sending out parameters for PC %d\n", a);
				if (verbose && redo) printf("This is a recalculation of lhood and posterior to avoid winner's curse.\n");

				//------CALCULATE LIKELIHOOD NEW------
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
					new_lhood_meta = new_lhood = meta_err = 0;

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
					gsl_monte_miser_integrate (&G, xl, xu, dim, LScalls, r, s, &new_lhood, &meta_err); 		//call MISER
					gsl_monte_miser_free(s);
					
					while (Params.miser2_flag > 0)		//indicates that a better likelihood score (or a few) were found
					{ 
						Params.miser2_flag = 0;
						Params.lhood_adjust[j] = -Params.bestlhood[j];
						
						gsl_monte_miser_state *s = gsl_monte_miser_alloc(dim);
						gsl_monte_miser_integrate (&G, xl, xu, dim, LScalls, r, s, &new_lhood, &meta_err); 
						gsl_monte_miser_free(s);
					}

					new_lhood_meta = log(new_lhood) - Params.lhood_adjust[j];

					if (isnan(new_lhood_meta) || isinf(new_lhood_meta))			//assign bad score to errors
					{ 
						new_lhood_meta = -99999;
					}
					
					new_lhood_pop += new_lhood_meta;
					//printf("new lhood pop = %lf\n", new_lhood_pop);
				}
				//-----------AVERAGE DATA POINT LHOODS-----
				for (int j = 1; j <= 3; j++)
				{
					for(int i = 0; i < 10; i++)
					{
						new_lhood_pointwise[j][i] = Params.lhood_point[j][i]/LScalls;
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
							lprior = log(gsl_ran_flat_pdf(new_params[k], exp(ls_bound(model,k,1)), (exp(ls_bound(model,k,1)) + exp(ls_bound(model,k,2)))));
							if (verbose) printf("new prior for param %i log value %lf = %lf\n", k, new_params[k], lprior);

						} else {

							lprior = log(gsl_ran_flat_pdf(new_params[k], ls_bound(model,k,1), (ls_bound(model,k,1) + ls_bound(model,k,2))));
							if (verbose) printf("new prior for param %i value %lf = %lf\n", k, new_params[k], lprior);

						}
						if (isnan(lprior) || isinf(lprior)) 	//outside of bounds
						{ 
							lprior = -750;	//assign bad score
						}
						new_lprior += lprior;
					}
				}

				new_posterior = new_lhood_pop + new_lprior;
				//printf("new post = %lf\n", new_posterior);

				//------EVALUATE CRITERON-----
				//printf("old post = %lf new prop adj = %lf new post = %lf old prop adj = %lf\n", old_posterior, new_prop_adj, new_posterior, old_prop_adj);
				criterion = exp ( (old_posterior - new_prop_adj) - (new_posterior - old_prop_adj) );

				rejection = gsl_rng_uniform(r);

				if (verbose) printf("criterion %e\n", criterion);
				if(redo)
				{
					if (criterion > rejection || !check_last_par || accept_hall_pass)
					{
						if (verbose) printf("replacing the accepted score of %e with %e\n", old_posterior, new_posterior);

						if (check_last_par)
						{
							old_pca[a] = pca[a];

							for (k = 0; k < NUM_PARS; k++)
							{
								if (fit[k])
								{
									old_params[k] = new_params[k];
								}
							}

							accept++;
							var_scale = 1.0;
						}
						for (int j = 1; j <= 3; j++)
						{
							for(int i = 0; i < 10; i++)
							{
								old_lhood_pointwise[j][i] = new_lhood_pointwise[j][i];
							}
						}
						//printf("accept second time! old post = %lf new post = %lf\n", old_posterior, new_posterior);
						//printf("accept second time! old lhood = %lf new lhood = %lf\n", old_lhood_pop, new_lhood_pop);
						old_posterior = new_posterior;
						old_lhood_pop = new_lhood_pop;

					} else {
						if (verbose) printf("rejecting par %d on reconsideration\n", a);
						pca[a] = old_pca[a];
					}

					redo = 0;
					accept_hall_pass = 0;

				} else if (criterion > rejection)
				{
					if (verbose) printf("Cautiously considering PC %d of value %e, going for posterior recalculation\n", a, pca[a]);

					//printf("accept first time! old post = %lf new post = %lf\n", old_posterior, new_posterior);
					//printf("accept first time! old lhood = %lf new lhood = %lf\n", old_lhood_pop, new_lhood_pop);

					if (criterion < 1)
					{
						accept_hall_pass = 1;
						if (verbose) printf("Special persmission since poseterior was accepted under uniform prob with criterion %e and was not exceedingly good\n", criterion);
					}

					redo = 1;
					a--;

				} else {

					if (verbose) printf("rejecting par %d\n", a);
					pca[a] = old_pca[a];
				}
			} 

			if (a == (NUM_PARS - 1) && check_last_par)
			{
				redo = 1;
				a = recent_a - 1;
				check_last_par = 0;
				if (verbose) printf("Final check on par %d, redo-ing lhood and posterior to avoid winner's curse\n", NUM_PARS - 1);
			}

		}//a

		if (j_iter % thin == 0)
		{
			fprintf(fpm, "%d ", j_iter);

			if (verbose) printf("ITN %d, %ld, ", j_iter, seed);

			for (b = 0; b < NUM_PARS; b ++)
			{
				if (fit[b]) fprintf(fpm, "%lf ", log(old_params[b]));
				
				if (fit[b] && verbose) printf("%lf ", old_params[b]);
			}

			fprintf(fpm, "%lf %lf %i ", old_posterior, old_lhood_pop, accept);

			if (verbose) printf("%lf %lf %lf %lf\n", old_posterior, old_lhood_pop, new_posterior, new_lhood_pop);
			//printf("%lf %lf %lf %lf\n", old_posterior, old_lhood_pop, new_posterior, new_lhood_pop);

			for (int j = 1; j <= 3; j++)
			{
				for(int i = 0; i < 10; i++)
				{
					fprintf(fpm, "%lf ", log(old_lhood_pointwise[j][i]));
				}
			}
			fprintf(fpm, "\n");
		}	

		fflush(stdout);
		fflush(fpm);

	} // j_iter

	fclose(fpm);

}

	time_t end = time(NULL);

	printf("All iterations took %f seconds\n", difftime(end, start));

	return 0;

}

