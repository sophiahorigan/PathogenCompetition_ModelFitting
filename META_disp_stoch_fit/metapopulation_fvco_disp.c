#include "head_meta.h"
gsl_rng *r;

int main(void)
{

int test = 66; //CK// Second test mode.  Like the full program but less runs and less MISER calls

int View = 0;  //CK// turn to 1 to print line search progress.  turn to 0 to run for real.

STRUCTURE Params;

int pro = 1;//atoi(argv[1]);						// pro and argv[1] are the inputs (argv[i] is the i^th input)
//printf("Profile Parameter is %d\n",pro);	fflush(stdout);
// ------------------------------------- Adustable accuracy vs. speed ------------------------------------------------ //
int num_runs	 = 20;
double parm_inc, host_inc, initR_inc;	//int inc_gamma_box= 1;

//if (pro==1)	{	parm_inc=200.0;		host_inc=100.0;	initR_inc=100.0;	}
if (pro==1)	{	parm_inc=50.0;		host_inc=10.0;	initR_inc=15.0;	}
//if (pro==1)	{	parm_inc=34.0;		host_inc=18.0;	initR_inc=20.0;	}
else		{	parm_inc=15.0;		host_inc=10.0;	initR_inc=10.0;	}

//if (test==66)	{	printf("for checking CK MODE2!!!\n");        num_runs=5;} //CK// New test mode!

if (test==66)	{      num_runs=5;	parm_inc=12.0;	host_inc=6.0;	initR_inc=8.0;}

//if (test==66)	{	printf("for checking!!!\n");        num_runs=5;	parm_inc=6.0;	host_inc=4.0;	initR_inc=4.0;	}
//printf("runs=%d\t incs: parm=%2.0f\t S_0=%2.0f\t R_0=%2.0f\n",num_runs,parm_inc,host_inc,initR_inc);

// ------------------------------------------------------------------------------------------------------------------ //
int i=0; int j;int ii; int jj; int k; int l;
int num_adj_pars=29;			// number of adjustable parameters
int pop;
int epi_length = 48;

// -------------------------------------------- MISTER STUFF --------------------------------------------------------- //
inputdata(&Params);				// gets Params.DATA[j][i][0-2] and Params.MAXT[i] from inputdata.h


//int calls=2;					//CK// turned down to run without stochasticity
int calls=50;					// number of stochastic simulations for each parameter and IC set
if (test==99)	calls=50;
if (test==66)	calls=50; //CK// second test mode
//if (test==66)	calls=5; //CK// second test mode
size_t dim;
//size_t dim2;
// --------------------------------------- Name for Output Files ----------------------------------------------------- //
char strFileName[99];					// from filenames.h
GetString(pro,0,strFileName,98);		fflush(stdout);		//getc(stdin);
FILE *fp_results;
// ---------------------------------------- Random Number Stuff ------------------------------------------------------ //
gsl_rng *r_seed;
r_seed=random_setup();
//printf("Random Seed: %f\n", r_seed); //getc(stdin);


double RandNumsPass[100];
for (i=0; i<=100; i++){
	RandNumsPass[i] = 0.05;
}

dim = 48*2;
LHood_Meta(RandNumsPass, dim, &Params);
printf("did it work?\n");

//free_i3tensor(Params.EXPDATA,0,DATA_SETS,0,MAX_WEEKS,0,3);
return 0;
}