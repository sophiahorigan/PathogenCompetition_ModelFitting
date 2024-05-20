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

#define MAX_SUBS 4		    		// maximum number of subpopulations // STACK OVERFLOW WHEN VALUE IS 100... what will I want it to be...
#define MAX_SIM_YEARS 10			// maximum number of simulation years // 10 historial, 10 future
#define MAX_WEATHER_YEARS 10		// max years of weather data
#define NUM_STATES 3				// S, F, V
#define MAX_EPI_DAYS 100			// max days for a single epizootic (overestimate)
#define NUM_RAIN_PARAMS 4			// rain, rh, avet, maxt
#define DAYS_IN_YEAR 365			// self-explanatory
#define EPI_DIM 83					// S(1) + C(1) + V(1) + R(1) + Vinf(27) + Finf(50) + Fkill(1) + Vkill(1)
#define m 27						// virus exposed classes
#define n 50						// fungus exposed classes
#define SIM 1						// 1 for historical, 2 for future
#define VERBOSE 1					// 2 for detailed printing output

FILE *fpintra;
FILE *fpinter;
FILE *ftp_data;

int larval_dispersal = 0;			// 1 for dispersal, 0 for none
int conidia_dispersal = 0; 			// 1 for dispersal, 0 for none

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

const double specific_muF = 0.00962435749864498; //conidia decay rate
const double Cend = 525.015699999847;
const double DDstart = 100.157149999888; // CHECK THIS
const double DDstop = 267.034499999981;	// CHECK THIS
const double VDDstart = 75.104413;	// CHECK THIS
		
const double lambdaF = 0.119701349994476; //transmission rate between funugs exposed classes
const double lambdaV = 0.0625; //transmission rate between virus exposed classes
const double muV = 0.4102453; //virus decay // from Dwyer et al 2022
const double CV = 0.86; //heterogeneity in virus susceptibility
const double nuV = 0.4607038; //virus transmission
const double specific_nuF = 0.000241071699421562; // baseline fungus transmission (not influenced by weather)
const double squareCVV = 0.86*0.86; // heterogenetity in susceptibility to virus infection

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

typedef struct 
{
	double SusEnd[MAX_SUBS]; 
	double InfFungusNext[MAX_SUBS];
	double InfVirusNext[MAX_SUBS];
	double lateinstar[MAX_SUBS];
	int Vstartday[MAX_SUBS];
	int Rstartday[MAX_SUBS];
	int Rendday[MAX_SUBS];
	int lateinstarday[MAX_SUBS];

	double nuV[MAX_SUBS];
	double nuF[MAX_SUBS];
	double nuR[MAX_SUBS];
	double muF[MAX_SUBS];

	double Vkill[MAX_SUBS];
	double Fkill[MAX_SUBS];

	double EV[n]; 
	double EF[m]; 

	int EPI_LENGTH[MAX_SUBS];   	// number of days from hatch to pupation
	int MAX_EPI_LENGTH;				// longest epi length
	int LATEST_EPI_END;				// latest day in the year for an epi to still be going 
	int EARLIEST_EPI_START;			// earliest day in the year for hatch

	double SINGLE_EPI_MODEL[MAX_SIM_YEARS][MAX_SUBS][MAX_EPI_DAYS][NUM_STATES]; // year, sub, day, state variable
	double LONG_TERM_MODEL[MAX_SIM_YEARS][MAX_SUBS][30]; // year, sub

	double HIST_WEATHER[MAX_WEATHER_YEARS][MAX_SUBS][DAYS_IN_YEAR][NUM_RAIN_PARAMS]; // year, sub, day, parameter
	double CC_WEATHER[MAX_WEATHER_YEARS][MAX_SUBS][DAYS_IN_YEAR][NUM_RAIN_PARAMS];  // year, sub, day, parameter
	double WEATHER[MAX_SUBS][DAYS_IN_YEAR][NUM_RAIN_PARAMS]; //sub, day, parameter

	int DISTANCE_MAT[MAX_SUBS][MAX_SUBS]; // pairwise distance between each subpop

	int model; //model number
	int num_sub;
	int num_year;
	int grid_length;

	double STATEVARS[NUM_STATES][MAX_SUBS]; 	//initial conditions across subpopulations

	//dispersal
	double c_a[MAX_SUBS];
	double l_a[MAX_SUBS];

	//stochasticity
	double R_stoch[MAX_SUBS];
	double F_stoch[MAX_SUBS];

	//printing
	int PRINT_INTRA;
	int PRINT_INTER;

	int S_start[MAX_SUBS];
	int S_end[MAX_SUBS];

	int R_start[MAX_SUBS];
	int R_end[MAX_SUBS];
	int V_start[MAX_SUBS];

	double size_C[MAX_SUBS];
	double indexR[MAX_SUBS];

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
