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
Params.model = atoi(y); Params.numyears = atoi(z);

int model = Params.model;
int numyears = Params.numyearss;

if (model > 48 || model < 0){
	printf("INACCURATE MODEL. Model options range from 0 - 47. See Read Me for model options.\n");
}

printf("Running model %i for %i years...\n", model, numyears);

//-------DISPERSAL-------- //-- update to only have model 43---
int *p;
p = dispersal_fit(model);		//function returns 1 for fitting dispersal, 0 for not fitting dispersal
larval_dispersal = p[0]; l_a_pop_fit = p[1]; l_a_meta_fit = p[2]; l_a_sub_fit = p[3]; l_m_pop_fit = p[4]; l_m_meta_fit = p[5]; l_m_sub_fit = p[6]; 
conidia_dispersal = p[7]; c_a_pop_fit = p[8]; c_a_meta_fit = p[9]; c_a_sub_fit = p[10]; c_m_pop_fit = p[11]; c_m_meta_fit = p[12]; c_m_sub_fit = p[13];
r_pop_fit = p[14]; r_meta_fit = p[15]; r_sub_fit = p[16];

//-------GENERAL SETUP-------
int verbose = VERBOSE;

int year;

//-------TEST MODE--------
int TEST = 0;
if(TEST)
{
	Params.num_sub = 4; Params.num_years = 1;
} else {
	Params.num_sub = 100; Params.num_years = 100;	 
}

//-------FILES--------
int pid;
pid = getpid();

char namesim[50];
sprintf(namesim, "M%i_SIM_numsub%i_numyears%i", model, num_subs, numyears);
fpsims = fopen(namesim, "a+");
setbuf(fpsims, NULL);

//---------GENERATE DISTANCE MATRIX---------

//-----LOOP THROUGH YEARS-------
for (int i = 0; i < Params.num_years; i++)
{
	year = i;


	//-------UPDATE PARAMS--------
	if (year = 0){ //first year, randomly generate initial parameters
		for (int j = 0; j < num_sub; j++)
		{	
			// S
			Params.STATEVARS[1][j] = NEW RANDOM VALUE;
			// R // have R start all the same?
			Params.STATEVARS[2][j] = NEW RANDOM VALUE;
			// V
			Params.STATEVARS[3][j] = NEW RANDOM VALUE;
		}
	}
	else {
		for (int j = 0; j < num_sub; j++)
		{	
			// S
			Params.STATEVARS[1][j] = END VALUE OF LAST EPI;
			// R // have R start all the same?
			Params.STATEVARS[2][j] = END VALUE OF LAST EPI;
			// V
			Params.STATEVARS[3][j] = END VALUE OF LAST EPI;
		}
		// c_a_sub
		Params.c_a_sub[j] = NEW RANDOM VALUE;
		// l_a_sub
		Params.l_a_sub[j] = NEW RANDOM VALUE;
		Params.R_stoch = NEW RANDOM VALUE;
		Params.F_stoch = NEW RANDOM VALUE;

	}

	//------RUN SINGLE EPIZOOTIC MODEL------
	// change dim
	// what is pop

	DDEVF(Params,RandNumsPass,dim,pop,48,0,year,dataset);

	//------RUN INTER-ANNUAL MODEL-------

}

fclose(fpsims);

}



