#include "head_single_epi_FV.h"

int main(int argc, char *argv[])
{

	int test = 66; //CK// Second test mode.  Like the full program but less runs and less MISER calls

	int View = 0;  //CK// turn to 1 to print line search progress.  turn to 0 to run for real.

	STRUCTURE Params;
	int pro = 1;//atoi(argv[1]);						// pro and argv[1] are the inputs (argv[i] is the i^th input)

	// ------------------------------------- Adustable accuracy vs. speed ------------------------------------------------ //
	int num_runs	 = 20;
	double parm_inc, host_inc, initR_inc;	//int inc_gamma_box= 1;

	if (pro==1)	{	parm_inc=50.0;		host_inc=10.0;	initR_inc=15.0;	}
	else		{	parm_inc=15.0;		host_inc=10.0;	initR_inc=10.0;	}
	if (test==66)	{      num_runs=5;	parm_inc=12.0;	host_inc=6.0;	initR_inc=8.0;}

	//---------------//CK// Best fit params and initial conditions from previous run //CK//-------------------------------------------------------//

	double bestparams[30]={1.0, 1.0, 0.64, 0.000241071699421562, 0, 0, 0.00962435749864498, 10, 20, 50, 0, 0.37161719994828, 0.913699399999732, 2.2223804999527, 0.945435549999967, 0, 525.015699999847, 8.32036899999904, 0.119701349994476, 267.034499999981, 7.88482749903281, 3.80285399989692, 0.070488499999861, 0.233982799999915, 7.05116449999956, 6.38002749970359, 3.54725448752468, 100.157149999888, 291.2745, 0.166585199947054};
	int pop2 = 2;

	//---------------//CK// Initial conditions for S from field observations //CK//-------------------------------------------------------//

	double initialS[8] = {1, 3, 5, 10, 25, 50, 75, 100};
	double initialV=1;
	double initial_nuF[8] = {5.0e-6, 5.0e-3, 5.0e-3, 5.0e-3, 5.0e-3, 5.0e-3, 5.0e-3, 5.0e-3};

	// ------------------------------------------------------------------------------------------------------------------ //
	int i=0; int j;int ii; int jj; int k; int l;
	int num_adj_pars=29;			// number of adjustable parameters
	int pop;

	// -------------------------------------------- MISER STUFF --------------------------------------------------------- //
	inputdata(&Params);				// gets Params.DATA[j][i][0-2] and Params.MAXT[i] from inputdata.h


	int calls=50;					// number of stochastic simulations for each parameter and IC set
	if (test==99)	calls=50;
	if (test==66)	calls=50; //CK// second test mode
	size_t dim;
	// --------------------------------------- Name for Output Files ----------------------------------------------------- //
	char strFileName[99];					// from filenames.h
	GetString(pro,0,strFileName,98);		fflush(stdout);		//getc(stdin);
	FILE *fp_results;
	// ---------------------------------------- Random Number Stuff ------------------------------------------------------ //
	gsl_rng *r_seed;
	r_seed=random_setup();
	// -------------------- parameter high/low values and increments and fixed parameter values ------------------------- //
	global_fixed_parms(&Params);  // gets Params.PARS[i] for fixed parameters from bounds.h
	parm_range_inc(&Params,parm_inc,host_inc,initR_inc,num_adj_pars); // gets Params.parm_set,low,high,R_END from bounds.h
	
	// ------------------------------------ Declare Likelidhood Quanitites ----------------------------------------------- //
	double total_lhood;						// sum of pop_best_lhood over all patches


	// -----------------------Declaring things for CC simulation------------------------------------ //

	double DD10=0.0;		double S_start = 0.0;	double S_end = 0.0;
	int test_day;
	double DDtemp_now;
	double hatch =317.0;       //From Russo et al 1993
	double Hlim1 = 3.0;
	double Hlim2 = 40.0-Hlim1;
	double pupate = 586.5;     //From Carter et al 1992
	double Plim1=7.65;
	double Plim2=41.0-Plim1;
	int MAXT3;
	int limit;
	int MAXT4;
	int reps;	//number of stochastic simulations to do per
	double INFECTED;

	//---------------------Write over the initial params with known fit params --------------------------//

	for (k=0;k<=num_adj_pars;k++)	{
		Params.PARS[k] = bestparams[k];
	}

	reps = 1;

	int year;
	double sdensity;
	double fdensity;
	double vdensity;

	// SH need to set initial conditions
	VFSus=50; //SH random pick 
	sdensity=1000; //SH random pick 
	fdensity=0.026; //SH from literature
	vdensity=0.2; //SH guesstimate

	//SH KEEP brings initial values into structure
	Params.PARS[30+pop]=sdensity; 
	VPass=vdensity;
	Params.PARS[50+pop]=fdensity;

	DDEVF(&Params,r_seed,dim,pop,48,0,year); // SH change S_start to 0 and MAXT3 to 48 (length of epizootic) to just run for one year


    FILE *fp;
    char name[50];
	sprintf(name, "JHN_KBS1daily_test1"); //SH attempt at naming output based on above lines

    fp=fopen(name,"a+");    //a+ for reading and appending! Could only get the output of the last year with w+.

	Params.total = reps*Params.PARS[30+pop];

	INFECTED = 1.0 - (Params.survivors/Params.total);

	fprintf(fp,"%d\t %e\t %e\t %e\t %e\t %e\t %e\t %e\n",year,Params.PARS[30+pop],Params.PARS[50+pop],VPass,InfFungusNext,InfFungusEnd,InfVirusNext,InfVirusEnd); //After dispersal


    double stoch=exp(gsl_ran_gaussian(r_seed,0.25));
    double tempor=sdensity;
    sdensity=fecundity*SusEnd*(1-(2*preda*predb*sdensity)/(predb*predb+sdensity*sdensity))+1e-5;
    

	// ----------- Use MISER to call function pop_lhood --------------------------------- //
	gsl_monte_miser_state *s = gsl_monte_miser_alloc(dim);
	gsl_monte_miser_integrate (&G,xl,xu,dim,calls,r_seed,s,&pop_lhood,&pop_err);
	gsl_monte_miser_free(s);

	// ------------------- check to see if these ICs are better  ------------------------ //
	pop_lhood2=log(pop_lhood)-700.0;  //CK// Converting back to log likelihoods for MCMC

		if (pop_lhood2>pop_best_lhood) {
			pop_best_lhood = pop_lhood2;
			Params.best_initR[pop] = Params.PARS[50+pop];
		}

	total_lhood += pop_best_lhood;
	} 


prior[6]=log(prior_dist(6,log10(Params.PARS[6])));	//printf("prior[6]=%f\n",prior[6]);
post_hood=total_lhood;
				
return 0;
}
