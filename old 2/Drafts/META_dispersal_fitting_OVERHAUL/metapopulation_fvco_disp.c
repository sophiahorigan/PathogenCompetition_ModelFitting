#include "head_meta.h"
gsl_rng *r;

float DotProduct (int Length, double *Holder, double *PCA)
{
  double answer = 0;

  int i;
  for(i=0;i<Length;i++)
    answer += PCA[i]*Holder[i];   //JL: Used in the reconstruction of parameter values from PCA

  return(answer);

}

int main(void)
{
  //printf("I'm here line 18!\n"); fflush(stdout);

STRUCTURE Params;

// ---------------------------------------- Random Number Seed ------------------------------------------------------ //
  //printf("I'm here line 23!\n"); fflush(stdout);

gsl_rng *r_seed;
r_seed=random_setup();
//printf("Random Seed: %f\n", r_seed); getc(stdin);
 //printf("I'm here line 28!\n"); fflush(stdout);

//-------------------------------------------------- Fitting Specifications -----------------------------------------//

int num_fit_params = 50;	

// -------------------------------------------- MISER --------------------------------------------------------- //

// -------------------------------------------- Set-up --------------------------------------------------------- //

inputdata(&Params);				//gets Params.DATA from inputdata.h

//local variables
double epi_length = 48;
double meta_lhood, meta_err;
int jj;
size_t dim;
dim = 2*epi_length; 			//need to make larger
double xl[dim];	double xu[dim];	//set stochastic values
for (jj=0;jj<=dim;jj++)	{
	xl[jj]=0;
	xu[jj]=1;
} 

//random number
const gsl_rng_type * T;
gsl_rng * r;

//define function
gsl_monte_function G = { &LHood_Meta, dim, &Params };	// declares function calling Hood_Pops.h

//run specifications
size_t calls = 100;					// number of stochastic simulations for each parameter and IC set

gsl_rng_env_setup();

T = gsl_rng_default;
r = gsl_rng_alloc (T);
// -------------------------------------------- Integration --------------------------------------------------------- //

{
gsl_monte_miser_state *s = gsl_monte_miser_alloc(dim);
printf("I'm here line 136!\n"); fflush(stdout); getc(stdin);
gsl_monte_miser_integrate (&G,xl,xu,dim,calls,r_seed,s,&meta_lhood,&meta_err);
printf("I'm here line 138!\n"); fflush(stdout); getc(stdin);
gsl_monte_miser_free (s);
}
printf("I'm here line 138!\n"); fflush(stdout); getc(stdin);
//printf("for dataset = %i, calls =  %i, lhood_meta = %lf, meta_err = %lf", Params.j, calls, meta_lhood, meta_err); 	fflush(stdout);

meta_lhood = log(meta_lhood)-700.0;

//free_i3tensor(Params.DATA,0,DATA_SETS,0,MAX_WEEKS,0,3);

printf("DONE!!!\n");
return 0;
}
