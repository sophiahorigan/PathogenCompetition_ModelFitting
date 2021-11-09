#include "headDEMO_exposed_foverv_alt.h"

int main(int argc, char *argv[])
{

int test = 66; //CK// Second test mode.  Like the full program but less runs and less MISER calls

int View = 0;  //CK// turn to 1 to print line search progress.  turn to 0 to run for real.

//VERSION OF BIG MODEL TO PRINT OUTPUTS!


////////////
///NOTE:  Going to try to change nuF to a site-specific parameter and make R(0) a general parameter
////////// Just going to try making a new parameter for average R(0).  Make it number 23.
////////// Comment out param #3 (general nuF) but leave structure in place if we go back to it
////////// Pipe param #23 into R for all populations
////////// Make it fit nuF, rather than R(0), for each population.  Sounds simple enough....

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
// -------------------- parameter high/low values and increments and fixed parameter values ------------------------- //
global_fixed_parms(&Params);  // gets Params.PARS[i] for fixed parameters from bounds.h
parm_range_inc(&Params,parm_inc,host_inc,initR_inc,num_adj_pars); // gets Params.parm_set,low,high,R_END from bounds.h

// ------------------------------------ Declare Likelidhood Quanitites ----------------------------------------------- //
//double pop_lhood, pop_lhood2, pop_err,post_hood;	// population lhood (and posterior lhood) calculated for each initS and initR
//double pop_best_lhood;					// likelihood and error for best initS and initR
double total_lhood;						// sum of pop_best_lhood over all patches
//double best_post_hood;	double best_lhood=0;		// best post_hood and lhood
//double prior[num_adj_pars];



// -----------------------Declaring things for CC simulation------------------------------------ //

double DD10=0.0;		double S_start = 0.0;	double S_end = 0.0;
int test_day;
//int line_ticker;
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
	//printf("%e\n",Params.PARS[k]);
}

reps = 1;

int year;
double sdensity;
double fdensity;
double vdensity;

//int bbf;
//for (bbf=0;bbf<15;bbf++){ //SH removed for now, just set VfSus to something
//VFPass=VFtime;
// SH need to set initial conditions
VFSus=15; //SH random pick 
sdensity=100; //SH random pick 
fdensity=0.026; //SH from literature
vdensity=0.2; //SH guesstimate

//SH KEEP brings initial values into structure
Params.PARS[30+pop]=sdensity; 
VPass=vdensity;
Params.PARS[50+pop]=fdensity;



//************SH prints output each day into file******************//

char name1[50];
sprintf(name1, "sim_output_");
fp1=fopen(name1,"a+"); //or a+, not sure which
//for(j=0; j<reps; j++){ //SH add loop back in when doing multiple years
DDEVF(&Params,r_seed,dim,pop,48,0,year);
fclose(fp1);



//*****************************SH saves output into array without printing file**************//
/*
DDEVF(&Params,r_seed,dim,pop,48,0,year);
printf("%e\t %e\t %e\t", sim_output[12][1], sim_output[12][2], sim_output[12][3]);
*/



//************* SH hard code data **********/
const int JHN_Co[55][4] = {
	{-1, -1, -1, -1},
	{-1, -1, -1, -1},
	{-1, -1, -1, -1},
	{-1, -1, -1, -1},
	{-1, -1, -1, -1},
	{-1, -1, -1, -1},
	{-1, -1, -1, -1},
	{-1, -1, -1, -1},
	{-1, -1, -1, -1},
	{-1, -1, -1, -1},
	{-1, -1, -1, -1},
	{-1, -1, -1, -1},
	{-1, -1, -1, -1},
	{-1, -1, -1, -1},
	{42, 7, 0, 0},
	{-1, -1, -1, -1},
	{-1, -1, -1, -1},
	{-1, -1, -1, -1},
	{-1, -1, -1, -1},
	{-1, -1, -1, -1},
	{29, 18, 1, 0},
	{-1, -1, -1, -1},
	{-1, -1, -1, -1},
	{33, 15, 0, 0},
	{-1, -1, -1, -1},
	{-1, -1, -1, -1},
	{36, 11, 1, 0},
	{-1, -1, -1, -1},
	{-1, -1, -1, -1},
	{38, 10, 1, 0},
	{-1, -1, -1, -1},
	{-1, -1, -1, -1},
	{-1, -1, -1, -1},
	{25, 21, 4, 0},
	{-1, -1, -1, -1},
	{-1, -1, -1, -1},
	{19, 30, 2, 0},
	{-1, -1, -1, -1},
	{-1, -1, -1, -1},
	{-1, -1, -1, -1},
	{11, 33, 2, 5},
	{-1, -1, -1, -1},
	{-1, -1, -1, -1},
	{7, 41, 1, 1},
	{-1, -1, -1, -1},
	{-1, -1, -1, -1},
	{-1, -1, -1, -1},
	{-1, -1, -1, -1}
};
//int (*ptr_JHN_NoCo)[55][3]; 

//**************SH prints content of JHN_NoCo******************//
/*
int loop3, loop4;
for(loop3 = 0; loop3 < 48; loop3++){
	for (loop4 = 0; loop4 < 3; loop4++){
		printf("JHN_NoCo[%i][%i] = %i\n", loop3, loop4, JHN_NoCo[loop3][loop4]);
	}	
}
*/



//*************** SH let's calculate a likelihood!! ******************//

int m; double lhood_JHN = 0;

for (m = 0; m < 48; m++){
	if (JHN_Co[m][0] != -1) {	
		lhood_JHN = lhood_JHN + gsl_ran_multinomial_lnpdf(4, sim_output[m], JHN_Co[m]);
		printf("%lf\n", lhood_JHN);
	}
	else{

	}
}
printf("%lf\n", lhood_JHN);






//**************SH prints output at end of week****************//
   // FILE *fp;
   // char name[50];
    // sprintf(name,"typethree_Vall_Cthreeweek_fut_immi_VFSus_alt_%lf_1.txt",VFSusF[bbf]);
    //sprintf(name,"fv_bf_%f_row_%d_col_%d.txt",bfungus[bbf],row,col);
	//sprintf(name, "JHN_KBS1daily_15_10000_0.026_0.2"); //SH attempt at naming output based on above lines

   // fp=fopen(name,"a+");    //a+ for reading and appending! Could only get the output of the last year with w+.



	// INFECTED = 1.0 - (Params.survivors/Params.total); //SH need to modify to add two infection classes (V/F)

	//printf("%lf\t %lf\t %lf\t %lf\t %lf\n", Params.PARS[30+pop], Params.PARS[50+pop], INFECTED, Params.survivors, Params.total);
	// fprintf(fp,"%d\t %e\t %e\t %e\t %e\t %e\t %e\t %e\n",year,Params.PARS[30+pop],Params.PARS[50+pop],VPass,InfFungusNext,InfFungusEnd,InfVirusNext,InfVirusEnd); //After dispersal
	//year, initial s, initial f, initial v, end f to next epi, f at end, v to next epi, v at end

    //printf("After an epizootic: %e\t %e\t %e\n",SusEnd,InfFungusEnd,InfVirusEnd); //getc(stdin);
    //printf("SusEnd=%e, N*(1-if-iv)=%e\n",SusEnd,sdensity-InfFungusEnd-InfVirusEnd);
    double stoch=exp(gsl_ran_gaussian(r_seed,0.25));
    double tempor=sdensity;
    //printf("%f\n",SusEnd);
    sdensity=fecundity*SusEnd*(1-(2*preda*predb*sdensity)/(predb*predb+sdensity*sdensity))+1e-5;
    

free_i3tensor(Params.DATA,0,DATA_SETS,0,MAX_WEEKS,0,3);
return 0;
}
