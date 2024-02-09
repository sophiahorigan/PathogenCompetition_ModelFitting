#include "head.h"
gsl_rng *r;

///////////////////////////////////////////////////DOT-PRODUCT///////////////////////////////////////////////////
float DotProduct (int len, double (*holder)[len], double *pca)
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
if (model > 45 || model < 0){
	printf("INACCURATE MODEL. Model options range from 0 - 45. See Read Me for model options.\n");
}

//-------TEST MODE--------
int TEST = 0;
if(TEST)
{
	LScalls = 10; Rcalls = 10; Mcalls = 10; Realizations = 500;		//Reals needs to be num params *2 to get all params
} else {
	LScalls = 50; Rcalls = 10; Mcalls = 50; Realizations = 15000;
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
	size_t ls_itns = MAXITN;
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
					//INITV
					Params.FITINIT[1][4] 	= 	0; 						//META 1 SUB 1
					Params.FITINIT[1][5] 	= 	0.2; 					//META 1 SUB 2
					Params.FITINIT[1][6] 	= 	0.2;					//META 1 SUB 3
					Params.FITINIT[1][7] 	= 	0; 						//META 1 SUB 4
					Params.FITINIT[2][4] 	= 	0; 						//META 2 SUB 1
					Params.FITINIT[2][5] 	= 	0.2; 					//META 2 SUB 2
					Params.FITINIT[2][6] 	= 	0.2; 					//META 2 SUB 3
					Params.FITINIT[2][7] 	= 	0; 						//META 2 SUB 4
					Params.FITINIT[3][4] 	= 	0; 						//META 3 SUB 1
					Params.FITINIT[3][5] 	= 	0.2; 					//META 3 SUB 2
					Params.FITINIT[3][6] 	= 	0.2; 					//META 3 SUB 3
					Params.FITINIT[3][7] 	= 	0; 						//META 3 SUB 4
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
///////////////////////////////////////////////////MCMC//////////////////////////////////////////////////////////
	if (mcmc == 1)
	{
		//-------FILES--------
		int pid;
		pid = getpid();

		char namem[50];
		sprintf(namem, "M%i_mcmc_%i", model, pid);
		fpm = fopen(namem, "a+");
		setbuf(fpm, NULL);

		//-------VARIABLES--------
		double LogJumpToNew;
		double LogJumpToOld;
		double ProbOfAcceptance;

		double LogOldPosterior;
		double LogNewPosterior;
		double LogNewPrior;
		double PreviousLogOldPosterior = -100000000000000;

		double SDpca[NumberOfParams];
		double Rotations[NumberOfParams][NumberOfParams];
		double Center[NumberOfParams];
		double Scale[NumberOfParams];
		double New_PC[NumberOfParams];
		double Old_PC[NumberOfParams];
		double Holder[NumberOfParams];
		double New_Params[NumberOfParams];
		double Old_Params[NumberOfParams];

		for (int i = 0; i < NumberOfParams; i++)
		{
			SDpca[i] = Center[i] = Scale[i] = 0.0;

			for (int j = 0; j < NumberOfParams; j++)
			{
				Rotations[i][j] = 0.0;
			}
		}
		int stop = 0;
		int stop_counter = 0;
		float dot_holder;
		int Accept = 0;
		int Attempt = 0;

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

		file = fopen(PCAsd, "r");         
		for (a = 0; a < (NumberOfParams); a++)
		{
			if (fit[a] == 1) fscanf(file, "%lf\n", &SDpca[a]);
		}
		fclose(file);

		file = fopen(PCArotations, "r");  
		for (a = 0; a < (NumberOfParams); a++)
		{
			if (fit[a] == 1)
			{
				for(int k = 0; k < NumberOfParams; k++)
				{
					if (fit[k] == 1) fscanf(file, "%lf\n", &Rotations[a]);
				}
			}
		}
		fclose(file);

		file = fopen(PCAscale, "r");       
		for (a = 0; a < NumberOfParams; a++)
		{
			if (fit[a] == 1) fscanf(file, "%lf\n", &Scale[a]);
		}
		fclose(file);

		file = fopen(PCAcenter, "r");      
		for (a = 0; a < NumberOfParams; a++)
		{
			if (fit[a] == 1) fscanf(file, "%lf\n", &Center[a]);
		}
		fclose(file);
	
		//-------GENERATE INITIAL PCS--------
		for (a = 0; a < NumberOfParams; a++)
		{
			sigma[a] = SigmaInflation * SDpca[a]; 
		}
		//-------RECONSTRUCT PARAMS FROM PCS AND BOUND CHECK--------
		stop = 1;

		while (stop && stop_counter < NumberOfParams);
		{
			for (a = 0; a < NumberOfParams; a++)
			{
				if (fit[a] == 1) 
				{
					Old_PC[a] = New_PC[a] = gsl_ran_gaussian (r, sigma[a]);  
				} else {
					Old_PC[a] = New_PC[a] = 0.0;
				}
			}

			stop = 0;

			for (a = 0; a < NumberOfParams; a++)
			{							
				if (fit[a] == 1)
				{
					dot_holder = DotProduct(NumberOfParams, Rotations + a, New_PC);
					New_Params[a] = exp(dot_holder * sigma[a] + Center[a]);

					if (New_Params[a] < mcmc_bound(model, a, 1) || New_Params[a] > mcmc_bound(model, a, 2))
					{
						stop = 1;
						stop_counter++;
					}
				} else {
					New_Params[a] = 0.0;
				}       
			}
		}
		if(verbose) printf("Generating set took %d attempts\n", stop_counter);

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
			//for (a = 0; a < NumberOfParams; a++)

			//-------METROPOLIS SAMPLING STEP--------
			LogJumpToNew = -log(gsl_ran_gaussian_pdf(New_PC[Case], sigma[Case])); 
			LogJumpToOld = -log(gsl_ran_gaussian_pdf(Old_PC[Case], sigma[Case]));
			
			//-------CALCULATE LIKELIHOOD NEW PARAM SET--------
			//--------PASS FIXED PARAMS-------
			//INITV
			Params.FITINIT[1][4] 	= 	0; 						//META 1 SUB 1
			Params.FITINIT[1][5] 	= 	0.2; 					//META 1 SUB 2
			Params.FITINIT[1][6] 	= 	0.2;					//META 1 SUB 3
			Params.FITINIT[1][7] 	= 	0; 						//META 1 SUB 4
			Params.FITINIT[2][4] 	= 	0; 						//META 2 SUB 1
			Params.FITINIT[2][5] 	= 	0.2; 					//META 2 SUB 2
			Params.FITINIT[2][6] 	= 	0.2; 					//META 2 SUB 3
			Params.FITINIT[2][7] 	= 	0; 						//META 2 SUB 4
			Params.FITINIT[3][4] 	= 	0; 						//META 3 SUB 1
			Params.FITINIT[3][5] 	= 	0.2; 					//META 3 SUB 2
			Params.FITINIT[3][6] 	= 	0.2; 					//META 3 SUB 3
			Params.FITINIT[3][7] 	= 	0; 						//META 3 SUB 4
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
			meta_err = 0; LogNewPosterior = 0.0;


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
				gsl_monte_miser_integrate (&G, xl, xu, dim, Mcalls, r, s, &lhood_meta, &meta_err); 
				gsl_monte_miser_free(s);
				
				while (Params.miser2_flag > 0)
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

			}
			//---------ADD PRIOR----------
			LogNewPosterior = total_loghood_metas_NEW + log_prior_NEW;

			//printf("MCMC PASS 1\n");
			//printf("loghood metas = %lf\n", total_loghood_metas_NEW);
			//printf("prior = %lf\n", log_prior_NEW);
			//printf("new_posterior = %lf\n", LogNewPosterior);

			//-----------AVERAGE DATA POINT LHOODS-----
			for (int j = 1; j <= 3; j++)
			{
				for(int i = 0; i < 10; i++)
				{
					Params.NEW_lhood_point[j][i] = exp(Params.lhood_point[j][i])/Mcalls;
				}
			}
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
				meta_err = 0; LogOldPosterior = 0.0;

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
					gsl_monte_miser_integrate (&G, xl, xu, dim, Mcalls, r, s, &lhood_meta, &meta_err); 
					gsl_monte_miser_free(s);
					
					while (Params.miser2_flag > 0)
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
				}
				//---------ADD PRIOR----------
				LogOldPosterior = total_loghood_metas_OLD + log_prior_OLD;
				//printf("MCMC PASS OLD\n");
				//printf("loghood metas = %lf\n", total_loghood_metas_OLD);
				//printf("prior = %lf\n", log_prior_OLD);
				//printf("new_posterior = %lf\n", LogOldPosterior);

				//-----------AVERAGE DATA POINT LHOODS-----
				for (int j = 1; j <= 3; j++)
				{
					for(int i = 0; i < 10; i++)
					{
						Params.OLD_lhood_point[j][i] = exp(Params.lhood_point[j][i])/Mcalls;
					}
				}

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
				meta_err = 0; LogNewPosterior = 0.0;

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
					gsl_monte_miser_integrate (&G, xl, xu, dim, Mcalls, r, s, &lhood_meta, &meta_err);
					gsl_monte_miser_free(s);
					
					while (Params.miser2_flag > 0)
					{ 
						Params.miser2_flag = 0;
						Params.lhood_adjust[j] = -Params.bestlhood[j];
						
						gsl_monte_miser_state *s = gsl_monte_miser_alloc(dim);
						gsl_monte_miser_integrate (&G, xl, xu, dim, Mcalls, r, s, &lhood_meta, &meta_err); 
						gsl_monte_miser_free(s);
					}
					
					log_lhood_meta = log(lhood_meta) - Params.lhood_adjust[j];

					if (isnan(log_lhood_meta) || isinf(log_lhood_meta)){ 
						log_lhood_meta = -100000000000000;
					}

					total_loghood_metas_NEW = total_loghood_metas_NEW + log_lhood_meta;
				}
				//----------ADD PRIOR------
				LogNewPosterior = total_loghood_metas_NEW + log_prior_NEW;

				//printf("MCMC PASS NEW 2\n");
				//printf("loghood metas = %lf\n", total_loghood_metas_NEW);
				//printf("prior = %lf\n", log_prior_NEW);
				//printf("new_posterior = %lf\n", LogNewPosterior);

				//-----------AVERAGE DATA POINT LHOODS-----
				for (int j = 1; j <= 3; j++)
				{
					for(int i = 0; i < 10; i++)
					{
						Params.NEW_lhood_point[j][i] = exp(Params.lhood_point[j][i])/Mcalls;
					}
				}

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

					for (int j = 1; j <= 3; j++)
					{
						for(int i = 0; i < 10; i++)
						{
							Params.OLD_lhood_point[j][i] = Params.NEW_lhood_point[j][i];
						}
					}	
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

			fprintf(fpm, "%i ", LoopNumber); //mcmc iteration

			for (int ii = 0; ii < NumberOfParams; ii++)
			{ 
				fprintf(fpm, "%5.3f ", Old_Params[ii]);
			}
			fprintf(fpm, "%5.3f %5.3f %i %i ", total_loghood_metas_OLD, LogOldPosterior, Accept, Attempt);
			for (int j = 1; j <= 3; j++){
				for(int i = 0; i<10; i++){
					fprintf(fpm, "%5.3f ", Params.OLD_lhood_point[j][i]);
				}
			}
			fprintf(fpm, "\n"); 
			fflush(stdout);
			fflush(fpm);
		}
		fclose(fpm);
	}
*/
	time_t end = time(NULL);

	printf("All iterations took %f seconds\n", difftime(end, start));

	return 0;
}
