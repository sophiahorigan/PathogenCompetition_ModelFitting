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
#define NUM_PARS 100		        // number of parameters to be passed from main to hood
#define SIMU 64
//#define DIM 15						// number of differential equations

const double h = 0.01;		        // time step

double muV		= 0.39;		//CK// FUNGUS ONLY MODEL.  MAKE SURE DECAY IS ZERO SO NEGATIVE VIRUS DOESN'T HAPPEN!!
double squareCVV=0.86*0.86;

double exposetime = 16;
double VFtime=10;
double VFPass;

//JL: Long-term survival rates for the pathogens and fecundity
double phivirus=40;
double gammavirus=0.01;
double phifungus=0.25;
double gammafungus=0.95;
double psifungus=0.95;
double eta=100;
double ltf_params[7]={10, 0.66,19.571092,21,1e-6,5.5,1};
double fecundity=74.6;

//JL: Predation parameters
double preda=0.967;           //Predation parameters, for host-pathogen-predator model
double predb=0.14*0.39/0.64;

//Enhanced susceptibility and coinfection parameters
double VFSusF[15]={100,1.5,1.8,2,2.5,3,5,10,15,20,25,50,60,80,100};              //The hosts infected by the virus are more susceptible to the fungus (weaker immune system)
double VFSus;
double coinf_V=0.1; //The fraction of coinfected hosts (taken over by fungus) producing virus OB's


//JL: Recording the status at the end of an epizootic
double SusEnd;
double InfFungusEnd=0;
double InfVirusEnd=0;
double InfFungusNext=0;
double InfVirusNext=0;

double InfFungusWeekbefore=0;
double InfVirusWeekbefore=0;

double InfFungusTwoWeekbefore=0;
double InfVirusTwoWeekbefore=0;

double InfFungusMonthbefore=0;
double InfVirusMonthbefore=0;

double InfFungusAdj=0;
double InfVirusAdj=0;

double VPass;          //variable to pass the value of initialV in each generation



//SH global declaration of global file fp1 to print daily output into
FILE *fp1;


//double vinfected; //SH to hold daily fraction infected
//double finfected; //SH add coinfected eventually
//double survivors; //SH = IF/IV etc divided by initial host density
//double total;


double FakeWDATA[SIMU][5];
int days[47]={365, 365, 365, 366, 365, 365, 365, 366, 365, 365, 365, 366, 365, 365, 365, 366, 365, 365, 365, 366, 365, 365, 365, 366, 365, 365, 365, 366, 365, 365, 365, 366, 365, 365, 365, 365, 365, 365, 365, 365, 365, 365, 365, 366, 365, 365, 364}; //1973-2019
//CK Structure for experimental data!!!

struct dataset{  //  building the structure, to be declared later
	int Date;
	int Tree;
	int Covered;
	double total;
	double fungus;
};

typedef struct
{
	double PARS[NUM_PARS];

	double nuV;
	double nuF;
	double nuR;
	double muF;
	double size_C;
	double indexR;
	double indexV;

	double R_END[DATA_SETS+1];
	double INITS[DATA_SETS+1];
	double POPS[4];
	double EV[400];
	double EF[400];
	double DAY_F[DATA_SETS+1];	    // day where fungal infection first happens
	int MAXT[DATA_SETS+1];		    // number of days in data set (different for each data set)
	int MAXT2[DATA_SETS+1];		    // number of days in EXPERIMENTAL data set (different for each EXPERIMENTAL data set)
	int MAXT3[DATA_SETS+1];		    // number of days in WEATHER data set (different for each WEATHER data set)				   

	//Data Arrays
	//int EXPDATA[DATA_SETS+1][800][4];	// 3-dimensional array that holds all the EXPERIMENTAL data
	//int OBSDATA[DATA_SETS+1][150][4];			    // 3-dimensional array that holds all the OBSERVATIONAL data

	int DATA[DATA_SETS][1000][4]; // array that holds all data, exp and obs
	double MODEL[DATA_SETS][1000][4]; // array for model output
	double WDATA[DATA_SETS_WEATHER+1][366][8][100]; //SH dataset, days, weeks, years

	int numsub;

	//SH Epizootic Data
	//int DATA_BLOCK_1[DATA_SETS+1][192][4]; //192 = 4 x 48 day epi's

	double test_data[1000][36];

	double AcceptedVect[NUM_PARS];
	double LoopVect[NUM_PARS];

	double parm_low[NUM_PARS];
	double parm_high[NUM_PARS];
	double parm_step[NUM_PARS];

	double MLE[NUM_PARS];
	double MLE_host[DATA_SETS+1];
	double MLE_initR[DATA_SETS+1];

	double best_initS[DATA_SETS+1];
	double best_initR[DATA_SETS+1];

	int parm_inc;
	int th_id;
	int pop;

	// ****** DISPERSAL PARAMETERS *********
	//params to hold net daily conidia dispersal, added to ODE's
	double coni_net1; //net for treatment 1
	double coni_net2;
	double coni_net3;
	double coin_net4;

	double distance_array[6]; //d12, d13, d14, d23, d24, d34

	double dispersal; // dispersal parameter for dispersal function. will be fitting.

}STRUCTURE;


#include "inputdataDEMO.h"
#include "random_setup2.h"
#include "filenames4.h"
//#include "bounds_stochWEATHER_dd5.h"
#include "bounds_RAIN+TEMP+RH8.h"
#include "prob_dists.h"
#include "fast_odev_exposed_foverv_alt.h"
//#include "DDEVF_DEMO_disease1.h"
//#include "DDEVF_DEMO_window_logistic3.h"
//#include "DDEVF_demo_onlyW_R+T_PLOT.h"
//#include "DDEVF_storm_wR+T_MvsV2.h"
//#include "DDEVF_storm_BOTHweather_PLOT_window_logistic3.h"
#include "DDEVF_demo_BOTHweatherV_PLOT_day_exposed_foverv_alt.h"
//#include "hood_popsBASICnew3.h"

//#include "experiments.h"
//#include "hood.h"
//#include "uniroot_burnout_solver.h"
