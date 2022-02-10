//------------------------------------ External Program Dependencies -------------------------------------//
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <omp.h>
#include <unistd.h>

//gsl dependencies
#include <gsl/gsl_rng.h>
#include <gsl/gsl_randist.h>
#include <gsl/gsl_cdf.h>
#include <gsl/gsl_sf_gamma.h>
#include <gsl/gsl_complex.h>
#include <gsl/gsl_complex_math.h>
#include <gsl/gsl_monte_miser.h>
#include <gsl/gsl_monte.h>
#include <gsl/gsl_errno.h>	
#include <gsl/gsl_odeiv.h>	
#include <gsl/gsl_types.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_vector.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_min.h>

//------------------------------------ File Output -------------------------------------//
FILE *fp1;
char *strFileNameDate;

//------------------------------------ Constants -------------------------------------//
#define DATA_SETS 6		        // number of epizootic data sets //one for each metapop
#define DATA_SETS_WEATHER 1		// number of weather data sets
#define NUM_METASUB 3			// number of metapopulations with subpopulations
#define NUM_PARS 50		    // number of parameters to be passed from main to hood
#define epi_length 48			// length of epizootic (days)

//------------------------------------ Global Fixed Params -------------------------------------//
//virus transmission
double nuV = 0.4607038;
double muV = 0.4102453;
int n = 27; 					// number of exposed classes
double squareCVV = 0.86*0.86;
double exposetime = 16;

//fungus transmission
double nuF = 0.000241071699421562;
double muF = 0.00962435749864498;
double nuR;
int m = 50;						// number of exposed classes
double sdR = 0.37161719994828;	//standard deviation for gaussian random impact on resting spore transmission
double sdC = 0.913699399999732;	//standard deviation for gaussian random impact on conidia transmission
double C_end = 525.015699999847;
double R_start = 100.157149999888;
double R_end = 267.034499999981;
double lambdaF = 0.119701349994476;

double size_S = 291.2745; 		//effect of size on susceptibility //???

//weather
double beta = 10; 				//size of accumulated rainfall window
double scale_R1 = 3.80285399989692;
double scale_R2 = 3.54725448752468;
double scale_R3 = 0.166585199947054;
double scale_RH = 0.070488499999861;
double scale_temp = 0.233982799999915;
//double epsilon = pow(10,-6);

//structure
int max_class = 50+27+7+50;		//total possible fungus, virus, coinfected classes //m+n+7+m
const double h = 0.01;		    // time step

//long-term dynamics
double indexR = 0; 		//turn to 1 to store long-term F and V cadavers
double indexV = 0;

//------------------------------------ Structure with Fitting Params -------------------------------------//
typedef struct
{
	//parameter array
	double FITINIT[DATA_SETS][NUM_PARS]; 	//initial conditions across subpopulations
	double FITMETA[NUM_PARS];	//dispersal and coinfection parameters fit across all datasets

	//initial conditions
	double INITS[4]; 			//4 subpops X 3 metapops + 3 obs = 15
	double INITV[4];
	double INITR[4];

	//dispersal
	double con_mrg; //0
	double a;		//1
	double lar_disp;//2

	//coinfection
	double coinf_V;	//3
	double VFSus;	//4

	//DATA AND MODEL ARRAYS
	int DATA[DATA_SETS][1000][4]; 			// array that holds all data, exp and obs
	double MODEL[DATA_SETS][1000][4]; 		// array for model output
	double WDATA[DATA_SETS_WEATHER+1][366][8][100]; //SH dataset, days, weeks, years
	int DISTANCE[NUM_METASUB][100][100]; 	//distance (m) between each subpop
	double DISPROB[NUM_METASUB][100][100];	 //prob of larval dispersal between each subpop, based on wind/distance

	//INDEXING
	int numsub;
	int j; //dataset number

}STRUCTURE;

//------------------------------------ File Dependencies -------------------------------------//
#include "data_input.h"
#include "random_setup.h"
#include "filenames.h"
//#include "bounds.h"
#include "prob_dists.h"
#include "ode_fvco_disp.h"
#include "DDEVF_meta_fvco_disp.h"
#include "lhood_meta.h"
#include "nrutil.c"
