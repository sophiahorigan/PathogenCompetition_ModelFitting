#include "head_meta.h"

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

STRUCTURE Params;
// ---------------------------------------- Random Number Seed ------------------------------------------------------ //

gsl_rng *r_seed;
r_seed=random_setup();
//printf("Random Seed: %f\n", r_seed); getc(stdin);

// ---------------------------------------------- Dataset Selection -------------------------------------------------- //

int dataset;

dataset = 1; //see dataset details in ReadMe.h

Params.j = dataset;

//printf("j = %i", Params.j); 	fflush(stdout);

// ---------------------------------------------- Testing Parameter Set -------------------------------------------------- //
//metapopulation one
//init S
Params.FITINIT[1][0] = 100; Params.FITINIT[1][1] = 100; Params.FITINIT[1][2] = 100; Params.FITINIT[1][3] = 100;
//init V
Params.FITINIT[1][4] = 0; Params.FITINIT[1][5] = 0.2; Params.FITINIT[1][6] = 0.2; Params.FITINIT[1][7] = 0.2;
//init R
Params.FITINIT[1][8] = 0.0236; Params.FITINIT[1][9] = 0.0236; Params.FITINIT[1][10] = 0.0236; Params.FITINIT[1][11] = 0.0236;

//metapopulation two
//init S
Params.FITINIT[2][0] = 100; Params.FITINIT[2][1] = 100; Params.FITINIT[2][2] = 100; Params.FITINIT[2][3] = 100;
//init V
Params.FITINIT[2][4] = 0; Params.FITINIT[2][5] = 0.2; Params.FITINIT[2][6] = 0.2; Params.FITINIT[2][7] = 0.2;
//init R
Params.FITINIT[2][8] = 0.0236; Params.FITINIT[2][9] = 0.0236; Params.FITINIT[2][10] = 0.0236; Params.FITINIT[2][11] = 0.0236;

//metapopulation three
//init S
Params.FITINIT[3][0] = 100; Params.FITINIT[3][1] = 100; Params.FITINIT[3][2] = 100; Params.FITINIT[3][3] = 100;
//init V
Params.FITINIT[3][4] = 0; Params.FITINIT[3][5] = 0.2; Params.FITINIT[3][6] = 0.2; Params.FITINIT[3][7] = 0.2;
//init R
Params.FITINIT[3][8] = 0.0236; Params.FITINIT[3][9] = 0.0236; Params.FITINIT[3][10] = 0.0236; Params.FITINIT[3][11] = 0.0236;

//metapopulation four
//init S
Params.FITINIT[4][0] = 100;
//init V
Params.FITINIT[4][4] = 0;
//init R
Params.FITINIT[4][8] = 0.0236;

//metapopulation five
//init S
Params.FITINIT[5][0] = 100;
//init V
Params.FITINIT[5][4] = 0;
//init R
Params.FITINIT[5][8] = 0.0236;

//metapopulation four
//init S
Params.FITINIT[6][0] = 100;
//init V
Params.FITINIT[6][4] = 0;
//init R
Params.FITINIT[6][8] = 0.0236;

//dispersal parameters
Params.con_mrg = 0.05;
Params.a = 0.1;
Params.lar_disp = 0.05;

//coifection parameters
Params.coinf_V = 0.5;
Params.VFSus = 50;

//-------------------------------------------------- Fitting Specifications -----------------------------------------//

int num_fit_params = 50;	

// -------------------------------------------- MISER --------------------------------------------------------- //

// -------------------------------------------- Set-up --------------------------------------------------------- //
//local variables
double meta_lhood, meta_err;
int jj;
size_t dim;
dim = 2*epi_length; 			//to hold random values for both nuR and nuF concatenated
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
gsl_monte_miser_integrate (&G,xl,xu,dim,calls,r_seed,s,&meta_lhood,&meta_err);
gsl_monte_miser_free (s);
}

printf("for dataset = %i, calls =  %i, lhood_meta = %lf, meta_err = %lf", Params.j, calls, meta_lhood, meta_err); 	fflush(stdout);

meta_lhood = log(meta_lhood)-700.0;

//free_i3tensor(Params.DATA,0,DATA_SETS,0,MAX_WEEKS,0,3);

printf("DONE!!!\n");
return 0;
}
