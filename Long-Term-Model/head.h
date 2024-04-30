#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <omp.h>
#include <unistd.h>

#include <gsl/gsl_rng.h>
#include <gsl/gsl_randist.h>
#include <gsl/gsl_cdf.h>
#include <gsl/gsl_sf_gamma.h>
#include <gsl/gsl_complex.h>
#include <gsl/gsl_complex_math.h>
#include <gsl/gsl_monte_miser.h>
#include <gsl/gsl_errno.h>	// GSL_SUCCESS ...
#include <gsl/gsl_odeiv.h>	// ODE solver

#include <gsl/gsl_types.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_vector.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_min.h>

#include "nrutil.c"

char *strFileNameDate;

#define MAX_SUBS 100		    	// maximum number of subpopulations
#define MAX_YEARS 100				// maximum number of years 
#define NUM_STATES 3				// S, F, V
#define EPI_LENGTH 48				// length of single epizootic - should this be flexible I think so.

FILE *fpintra;
FILE *fpinter;

//LARVAL DISPERSAL
int larval_dispersal;
int l_a_pop_fit; 
int l_a_meta_fit;
int l_a_sub_fit;
int l_m_pop_fit; 
int l_m_meta_fit;
int l_m_sub_fit; 
//CONIDIA DISPERSAL
int conidia_dispersal; 
int c_a_pop_fit; 
int c_a_meta_fit;
int c_a_sub_fit; 
int c_m_pop_fit; 
int c_m_meta_fit; 
int c_m_sub_fit; 
//RESTING SPORE DENSITY
int r_pop_fit;
int r_meta_fit;
int r_sub_fit;

//FIXED PARAMS
//SINGLE EPIZOOTIC
const int epi_length = 48;
size_t dim = 48*2;

const int beta = 10;
const int theta = 1;
const double rain_P = 3.80285399989692;
const double rain_P2 = 3.54725448752468;
const double rain_P3 = 0.166585199947054;
const double RH_P = 0.070488499999861;
const double temp_P = 0.233982799999915;
const double epsilon = 1e-6;
const double fourth_size = 291.2745;
const int n = 27; //virus exposed classes
const int m = 50; //fungus exposed classes

const double specific_muF = 0.00962435749864498; //conidia decay rate
const double Cend = 525.015699999847;
const double DDstart = 100.157149999888;
const double DDstop = 267.034499999981;
			
const double exposetime = 16; //what is this
const double VFPass = 125.31; //check

const int EPI_DIM = 80; //S(1) + C(1) + Vcadav(1) + Vinf(27) + Finf(50)
const double h = 0.01;

const double lambdaF = 0.119701349994476; //transmission rate between funugs exposed classes
const double lambdaV = 0.0625; //transmission rate between virus exposed classes
const double muV = 0.4102453; //virus decay
const double CV = 0.86; //heterogeneity in virus susceptibility
const double nuV = 0.4607038; //virus transmission
const double specific_nuF = 0.000241071699421562; 

//LONG TERM

typedef struct //FIT PARS
{
	double nuV[MAX_SUBS];
	double nuF[MAX_SUBS];
	double nuR[MAX_SUBS];
	double muF[MAX_SUBS];

	double EV[400]; 
	double EF[400]; 
	int MAXT3[MAX_SUBS];		    // number of days in weather data	 //??	   

	double SINGLE_EPI_MODEL[MAX_YEARS][MAX_SUBS][EPI_LENGTH][NUM_STATES]; // year, sub, day, state variable
	double LONG_TERM_MODEL[MAX_YEARS][MAX_SUBS][NUM_STATES]; // year, sub, state variable (NEED TO UPDATE. more than 3.)
	double WDATA[MAX_YEARS][MAX_SUBS][52][365]; // year, sub, week, day //UPDATE TO REFLECT JIAWEIS

	int model; //model number
	int num_sub;
	int num_year;

	double STATEVARS[NUM_STATES][MAX_SUBS]; 	//initial conditions across subpopulations

	//dispersal
	double c_a[MAX_SUBS];
	double l_a[MAX_SUBS];

	//stochasticity
	double R_stoch;
	double F_stoch;

	//printing
	int PRINT_INTRA;
	int PRINT_INTER;

}STRUCTURE;


#include "data_input.h"
#include "random_setup.h"
#include "generate_param.h"
#include "ode.h"
#include "daily_statevars.h"
