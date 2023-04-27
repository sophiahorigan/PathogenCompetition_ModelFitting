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

#define DATA_SETS 6		        // number of epizootic data sets //one for each metapop
#define DATA_SETS_WEATHER 1		// number of weather data sets
#define NUM_METASUB 3			//number of metapopulations with subpopulations
#define NUM_PARS 110		        // number of parameters to be passed from main to hood



FILE *fpls; //line-search parameter value output
FILE *fpr; //model realizations

//FIXED PARS
const double h = 0.01;		      
const double exposetime = 16; //what is this
const double VFPass = 125.31; //check

const int n = 20; //fungus exposed classes
const int n1 = 0.39; //
const int n2 = 19.61; //
const int m = 50; //virus exposed classes
const int DIM = 508;  

const double specific_muF = 0.00962435749864498; //conidia decay rate
const double Cend = 525.015699999847;
const double DDstart = 100.157149999888;
const double DDstop = 267.034499999981;

const int beta = 10;
const int theta = 1;
const double rain_P = 3.80285399989692;
const double rain_P2 = 3.54725448752468;
const double rain_P3 = 0.166585199947054;
const double RH_P = 0.070488499999861;
const double temp_P = 0.233982799999915;

const double fourth_size = 291.2745;

const double epsilon = 1e-6;

const double lambdaF = 0.119701349994476; //transmission rate between funugs exposed classes
const double lambdaV = 1/16; //transmission rate between virus exposed classes

const int sub_index[4] = {0, 127, 254, 381};

//PLACEHOLDER VALUES
const double size_C = 1; //1: host produce conidia
const double indexR = 0; //1: host produce resting spores
const double indexV = 0; //1: host produce virus

typedef struct //FIT PARS
{
	//double PARS[NUM_PARS];

	double nuV;
	double nuF;
	double nuR;
	double muF;

	double EV[400];
	double EF[400];
	int MAXT3[DATA_SETS+1];		    // number of days in WEATHER data set (different for each WEATHER data set)	//rename			   

	int DATA[DATA_SETS][1000][4]; // array that holds all data, exp and obs
	double MODEL[DATA_SETS][1000][4]; // array for model output
	double WDATA[DATA_SETS_WEATHER+1][366][8][100]; //SH dataset, days, weeks, years
	int DISTANCE[NUM_METASUB][100][100];
	double DISPROB[NUM_METASUB][100][100];

	//indexing and dispersal params
	int numsub;

	int j; //dataset number

	double FITINIT[DATA_SETS][NUM_PARS]; 	//initial conditions across subpopulations
	double FITMETA[NUM_PARS];	//dispersal and coinfection parameters fit across all datasets

	//dispersal
	double m_c_pop; //0
	double a_c_pop;		//1

	double m_l_pop;
	double a_l_pop;

	double m_c_sub[DATA_SETS][4];	//2
	double a_c_sub[DATA_SETS][4];

	double m_l_sub[DATA_SETS][4];	//2
	double a_l_sub[DATA_SETS][4];

	double muV;
	//heterogeneity
	double CV;
	//fungus transmission
	double specific_nuF;

	//coinfection
	double VFSus;
	double coinf_V;

	//stochasticity
	double Rsd_exp;
	double Fsd_exp;
	double Rsd_obs;
	double Fsd_obs;

	//lhood_adjust
	double lhood_adjust[DATA_SETS+1];
	double bestlhood[DATA_SETS+1];
	int miser_ticker;
	double miser2_flag;


}STRUCTURE;


#include "data_input.h"
#include "random_setup.h"
#include "bounds.h"
#include "ode_fvco_disp.h"
#include "DDEVF_meta_fvco_disp.h"
#include "lhood_meta.h"
