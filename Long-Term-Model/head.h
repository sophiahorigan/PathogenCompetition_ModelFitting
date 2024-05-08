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
#define MAX_SIM_YEARS 100			// maximum number of simulation years 
#define MAX_WEATHER_YEARS 10		// max years of weather data
#define NUM_STATES 3				// S, F, V
#define MAX_EPI_DAYS 75				// max days for a single epizootic (overestimate)
#define NUM_RAIN_PARAMS 4			// rain, rh, avet, maxt
#define DAYS_IN_YEAR 365			// self-explanatory

FILE *fpintra;
FILE *fpinter;

//LARVAL DISPERSAL
int larval_dispersal;
//CONIDIA DISPERSAL
int conidia_dispersal; 

//FIXED PARAMS
const double Rstoch = 0.0005; // INPUT MY ESTIMATES!!
const double Fstoch = 0.0002;

const int beta = 10;
const int theta = 1;
const double rain_P = 3.80285399989692;
const double rain_P2 = 3.54725448752468;
const double rain_P3 = 0.166585199947054;
const double RH_P = 0.070488499999861;
const double temp_P = 0.233982799999915;
const double epsilon = 1e-6;
const double fourth_size = 291.2745;
const int n = 27; 
const int m = 50; //fungus exposed classes

const double specific_muF = 0.00962435749864498; //conidia decay rate
const double Cend = 525.015699999847;
const double DDstart = 100.157149999888; // CHECK THIS
const double DDstop = 267.034499999981;	// CHECK THIS
const double VDDstart = 75.104413;	// CHECK THIS
			
const int EPI_DIM = 83; //S(1) + C(1) + V(1) + R(1) + Vinf(27) + Finf(50) + Fkill(1) + Vkill(1) 
const double h = 0.01;

const double lambdaF = 0.119701349994476; //transmission rate between funugs exposed classes
const double lambdaV = 0.0625; //transmission rate between virus exposed classes
const double muV = 0.4102453; //virus decay // from Dwyer et al 2022
const double CV = 0.86; //heterogeneity in virus susceptibility
const double nuV = 0.4607038; //virus transmission
const double specific_nuF = 0.000241071699421562; 

// long term model
const double fecundity = 15;
const double preda = 0.967;
const double predb = 0.14 * 0.39 / 0.64;
const double phivirus = 40;
const double gammavirus = 0.001;
const double eta = 100;
const double f_max = 0.02;
const double x1 = 0.5;
const double x0 = -2;
const double gammafungus = 0.144683;
const double sto_fec = 0.190515361873207;

const double hatch = 317.0;       //From Russo et al 1993
const double Hlim1 = 3.0;
const double Hlim2 = 40.0 - Hlim1;
const double pupate = 586.5;     //From Carter et al 1992
const double Plim1 = 7.65;
const double Plim2 = 41.0 - Plim1;

double SusEnd[MAX_SUBS];
double InfFungusEnd[MAX_SUBS];
double InfVirusEnd[MAX_SUBS];
double InfFungusNext[MAX_SUBS];
double InfVirusNext[MAX_SUBS];
double lateinstar[MAX_SUBS];
int Vstartday[MAX_SUBS];
int Rstartday[MAX_SUBS];
int Rendday[MAX_SUBS];
int lateinstarday[MAX_SUBS];

typedef struct //FIT PARS
{
	double nuV[MAX_SUBS];
	double nuF[MAX_SUBS];
	double nuR[MAX_SUBS];
	double muF[MAX_SUBS];

	double EV[400]; 
	double EF[400]; 

	double EPI_LENGTH[MAX_SUBS];   	// number of days from hatch to pupation
	int MAX_EPI_LENGTH;				// longest epi length

	double SINGLE_EPI_MODEL[MAX_SIM_YEARS][MAX_SUBS][MAX_EPI_DAYS][NUM_STATES]; // year, sub, day, state variable
	double LONG_TERM_MODEL[MAX_SIM_YEARS][MAX_SUBS][NUM_STATES]; // year, sub, state variable (NEED TO UPDATE. more than 3.)

	double HIST_WEATHER[MAX_WEATHER_YEARS][MAX_SUBS][DAYS_IN_YEAR][NUM_RAIN_PARAMS]; // year, sub, day, parameter
	double CC_WEATHER[MAX_WEATHER_YEARS][MAX_SUBS][DAYS_IN_YEAR][NUM_RAIN_PARAMS];  // year, sub, day, parameter
	double WEATHER[MAX_SUBS][DAYS_IN_YEAR][NUM_RAIN_PARAMS]; //sub, day, parameter

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

	int S_start[MAX_SUBS];
	int S_end[MAX_SUBS];

	int R_start[MAX_SUBS];
	int V_start[MAX_SUBS];

	int MAX_EPI_LENGTH;

	double size_C;
	double indexR;

	double INITS[MAX_SUBS];
	double INITV[MAX_SUBS];
	double INITR[MAX_SUBS];

	double ode_output[MAX_SUBS][MAX_EPI_DAYS][EPI_DIM];

}STRUCTURE;


#include "data_input.h"
#include "random_setup.h"
#include "generate_param.h"
#include "ode.h"
#include "daily_statevars.h"
