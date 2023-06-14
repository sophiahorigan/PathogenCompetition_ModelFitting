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

// --------------------------------------- Name for Output Files ----------------------------------------------------- //
char strFileName[99];					// from filenames.h
GetString(pro,0,strFileName,98);		fflush(stdout);		//getc(stdin);
FILE *fp_results;
// ---------------------------------------- Random Number Stuff ------------------------------------------------------ //
gsl_rng *r_seed;
r_seed=random_setup();
//printf("Random Seed: %f\n", r_seed); //getc(stdin);

// ---------------------------------------------- Initial Conditions -------------------------------------------------- //

//dispersal parameters
Params.con_mrg = 0.05;
Params.a = 0.1;
Params.lar_disp = 0.05;

//coifection parameters
Params.coinf_V = 0.5;
Params.VFSus = 0.05;

//metapopulation one
//init S
Params.FITINIT[1][0] = 100; Params.FITINIT[1][1] = 100; Params.FITINIT[1][2] = 100; Params.FITINIT[1][3] = 100;
//printf("DEFINTION FItINIT[1][0] = %lf\n",Params->FITINIT[1][0]);
//init V
Params.FITINIT[1][4] = 0.2; Params.FITINIT[1][5] = 0.2; Params.FITINIT[1][6] = 0.2; Params.FITINIT[1][7] = 0.2;
//init R
Params.FITINIT[1][8] = 0.0236; Params.FITINIT[1][9] = 0.0236; Params.FITINIT[1][10] = 0.0236; Params.FITINIT[1][11] = 0.0236;

//metapopulation two
//init S
Params.FITINIT[2][0] = 100; Params.FITINIT[2][1] = 100; Params.FITINIT[2][2] = 100; Params.FITINIT[2][3] = 100;
//init V
Params.FITINIT[2][4] = 0.2; Params.FITINIT[2][5] = 0.2; Params.FITINIT[2][6] = 0.2; Params.FITINIT[2][7] = 0.2;
//init R
Params.FITINIT[2][8] = 0.0236; Params.FITINIT[2][9] = 0.0236; Params.FITINIT[2][10] = 0.0236; Params.FITINIT[2][11] = 0.0236;

//metapopulation three
//init S
Params.FITINIT[3][0] = 100; Params.FITINIT[3][1] = 100; Params.FITINIT[3][2] = 100; Params.FITINIT[3][3] = 100;
//init V
Params.FITINIT[3][4] = 0.2; Params.FITINIT[3][5] = 0.2; Params.FITINIT[3][6] = 0.2; Params.FITINIT[3][7] = 0.2;
//init R
Params.FITINIT[3][8] = 0.0236; Params.FITINIT[3][9] = 0.0236; Params.FITINIT[3][10] = 0.0236; Params.FITINIT[3][11] = 0.0236;

//metapopulation four
//init S
Params.FITINIT[4][0] = 100;
//init V
Params.FITINIT[4][4] = 0.2;
//init R
Params.FITINIT[4][8] = 0.0236;

//metapopulation five
//init S
Params.FITINIT[5][0] = 100;
//init V
Params.FITINIT[5][4] = 0.2;
//init R
Params.FITINIT[5][8] = 0.0236;

//metapopulation four
//init S
Params.FITINIT[6][0] = 100;
//init V
Params.FITINIT[6][4] = 0.2;
//init R
Params.FITINIT[6][8] = 0.0236;


//--------------------------------MISER-------------------------//
inputdata(&Params);				// gets Params.DATA[j][i][0-2] and Params.MAXT[i] from inputdata.h

//int calls=2;					//CK// turned down to run without stochasticity
int calls=10;					// number of stochastic simulations for each parameter and IC set

//if (test==66)	calls=5; //CK// second test mode
size_t dim;

for(j=1; j<=DATA_SETS; j++){

	Params.j = j;

	dim = 48*2; //eventually need dim to be bigger //right now same stoch for each metapop

	double lhood_meta=0; double log_lhood_meta=0;
	double meta_err=0;
	double lhood_total=0;

	//define function
	gsl_monte_function G = { &LHood_Meta, dim, &Params };	// declares function calling Hood_Pops.h
	double xl[dim];	double xu[dim];	// need to redeclare xl and xu since the size changes
	for (jj=0;jj<=dim;jj++)	{
		xl[jj]=0;	
		xu[jj]=1;
	}

	gsl_monte_miser_state *s = gsl_monte_miser_alloc(dim);
	gsl_monte_miser_integrate (&G,xl,xu,dim,calls,r_seed,s,&lhood_meta,&meta_err); //call MISER, pop_lhood is output from .h (likelihood value)
	gsl_monte_miser_free(s);

	printf("For dataset %i, lhood = %lf\t, err = %lf\n", j, lhood_meta, meta_err);

	log_lhood_meta = log(lhood_meta)-700.0; 

	lhood_total += lhood_meta;
	printf("Lhood total = %lf\n", lhood_total);
}
//free_i3tensor(Params.EXPDATA,0,DATA_SETS,0,MAX_WEEKS,0,3);
return 0;
}