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


//****************loops through initial conditions for each treatment********************//
//prints output to file

char name1[50];
sprintf(name1, "sim_output_block1");
fp1=fopen(name1,"a+"); 

int i_tmt; 
for (i_tmt = 1; i_tmt < 5; i_tmt++){
	if (i_tmt = 1){ //FUNGUS ONLY
		VFSus=2; 
		sdensity=100; 
		fdensity=0.026; 
		vdensity=0; 
		Params.PARS[30+pop]=sdensity; 
		VPass=vdensity;
		Params.PARS[50+pop]=fdensity;
		DDEVF(&Params,r_seed,dim,pop,48,0,year, 1);
	}
	if (i_tmt =2){ //VIRUS ONLY
		VFSus=2; 
		sdensity=100; 
		fdensity=0;
		vdensity=0.05; 
		Params.PARS[30+pop]=sdensity; 
		VPass=vdensity;
		Params.PARS[50+pop]=fdensity;
		DDEVF(&Params,r_seed,dim,pop,48,0,year, 2);
	}
	if (i_tmt = 3){ //FUNGUS-VIRUS
		VFSus=2; 
		sdensity=100; 
		fdensity=0.0236; 
		vdensity=0.05; 
		Params.PARS[30+pop]=sdensity; 
		VPass=vdensity;
		Params.PARS[50+pop]=fdensity;
		DDEVF(&Params,r_seed,dim,pop,48,0,year, 3);
	}
	if (i_tmt = 4){ //CONTROL
		VFSus=2; 
		sdensity=100; 
		fdensity=0; 
		vdensity=0; 
		Params.PARS[30+pop]=sdensity; 
		VPass=vdensity;
		Params.PARS[50+pop]=fdensity;
		DDEVF(&Params,r_seed,dim,pop,48,0,year, 4);
	}
fclose(fp1);
}

//************* SH hard code data **********/
const int BlockOne_exp[200][4] = {
	{-1, -1, -1, -1}, //Treatment 1: Fungus-only
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
	{50, 0, 0, 0}, //13
	{-1, -1, -1, -1},
	{-1, -1, -1, -1},
	{-1, -1, -1, -1},
	{-1, -1, -1, -1},
	{48, 0, 0, 0}, //18
	{-1, -1, -1, -1},
	{-1, -1, -1, -1},
	{-1, -1, -1, -1},
	{50, 0, 0, 0}, //22
	{-1, -1, -1, -1},
	{-1, -1, -1, -1},
	{49, 0, 0, 0}, //25
	{-1, -1, -1, -1},
	{-1, -1, -1, -1},
	{50, 0, 0, 0}, //28
	{-1, -1, -1, -1},
	{-1, -1, -1, -1},
	{50, 0, 0, 0}, //31
	{-1, -1, -1, -1},
	{-1, -1, -1, -1},
	{-1, -1, -1, -1},
	{50, 0, 0, 0}, //35
	{-1, -1, -1, -1},
	{-1, -1, -1, -1},
	{47, 1, 0, 0}, //38
	{-1, -1, -1, -1},
	{-1, -1, -1, -1},
	{-1, -1, -1, -1},
	{49, 0, 1, 0}, //42
	{-1, -1, -1, -1},
	{-1, -1, -1, -1},
	{48, 0, 2, 0}, //45 
	{-1, -1, -1, -1},
	{-1, -1, -1, -1},
	{-1, -1, -1, -1}, //END OF FUNGUS TREATMENT
	{-1, -1, -1, -1}, //Treatment 2: Virus-only
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
	{48, 0, 0, 0}, //13
	{-1, -1, -1, -1},
	{-1, -1, -1, -1},
	{-1, -1, -1, -1},
	{-1, -1, -1, -1},
	{49, 1, 0, 0}, //18
	{-1, -1, -1, -1},
	{-1, -1, -1, -1},
	{-1, -1, -1, -1},
	{46, 2, 0, 0}, //22
	{-1, -1, -1, -1},
	{-1, -1, -1, -1},
	{45, 5, 0, 0}, //25
	{-1, -1, -1, -1},
	{-1, -1, -1, -1},
	{47, 3, 0, 0}, //28
	{-1, -1, -1, -1},
	{-1, -1, -1, -1},
	{50, 0, 0, 0}, //31
	{-1, -1, -1, -1},
	{-1, -1, -1, -1},
	{-1, -1, -1, -1},
	{49, 1, 0, 0}, //35
	{-1, -1, -1, -1},
	{-1, -1, -1, -1},
	{50, 0, 0, 0}, //38
	{-1, -1, -1, -1},
	{-1, -1, -1, -1},
	{-1, -1, -1, -1},
	{45, 5, 0, 0}, //42
	{-1, -1, -1, -1},
	{-1, -1, -1, -1},
	{50, 0, 0, 0}, //45 
	{-1, -1, -1, -1},
	{-1, -1, -1, -1},
	{-1, -1, -1, -1}, //END OF VIRUS-ONLY TREATMENT
	{-1, -1, -1, -1}, //Treatment 3: Fungus-Virus
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
	{36, 0, 0, 0}, //13
	{-1, -1, -1, -1},
	{-1, -1, -1, -1},
	{-1, -1, -1, -1},
	{-1, -1, -1, -1},
	{7, 0, 0, 0}, //18
	{-1, -1, -1, -1},
	{-1, -1, -1, -1},
	{-1, -1, -1, -1},
	{13, 0, 0, 0}, //22
	{-1, -1, -1, -1},
	{-1, -1, -1, -1},
	{49, 1, 0, 0}, //25
	{-1, -1, -1, -1},
	{-1, -1, -1, -1},
	{16, 1, 0, 0}, //28
	{-1, -1, -1, -1},
	{-1, -1, -1, -1},
	{35, 0, 0, 0}, //31
	{-1, -1, -1, -1},
	{-1, -1, -1, -1},
	{-1, -1, -1, -1},
	{47, 1, 0, 0}, //35
	{-1, -1, -1, -1},
	{-1, -1, -1, -1},
	{49, 1, 0, 0}, //38
	{-1, -1, -1, -1},
	{-1, -1, -1, -1},
	{-1, -1, -1, -1},
	{15, 1, 0, 0}, //42
	{-1, -1, -1, -1},
	{-1, -1, -1, -1},
	{20, 0, 0, 0}, //45 
	{-1, -1, -1, -1},
	{-1, -1, -1, -1},
	{-1, -1, -1, -1}, //END OF FUNGUS-VIRUS TREATMENT
	{-1, -1, -1, -1}, //Treatment 4: Control
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
	{42, 0, 0, 0}, //13
	{-1, -1, -1, -1},
	{-1, -1, -1, -1},
	{-1, -1, -1, -1},
	{-1, -1, -1, -1},
	{49, 1, 0, 0}, //18
	{-1, -1, -1, -1},
	{-1, -1, -1, -1},
	{-1, -1, -1, -1},
	{21, 0, 0, 0}, //22
	{-1, -1, -1, -1},
	{-1, -1, -1, -1},
	{46, 0, 0, 0}, //25
	{-1, -1, -1, -1},
	{-1, -1, -1, -1},
	{16, 1, 0, 0}, //28
	{-1, -1, -1, -1},
	{-1, -1, -1, -1},
	{14, 0, 0, 0}, //31
	{-1, -1, -1, -1},
	{-1, -1, -1, -1},
	{-1, -1, -1, -1},
	{16, 1, 0, 0}, //35
	{-1, -1, -1, -1},
	{-1, -1, -1, -1},
	{20, 0, 0, 0}, //38
	{-1, -1, -1, -1},
	{-1, -1, -1, -1},
	{-1, -1, -1, -1},
	{14, 0, 0, 0}, //42
	{-1, -1, -1, -1},
	{-1, -1, -1, -1},
	{16, 2, 0, 0}, //45 
	{-1, -1, -1, -1},
	{-1, -1, -1, -1},
	{-1, -1, -1, -1}, //END OF CONTROL TREATMENT
};
//int (*ptr_JHN_NoCo)[55][3]; 


//*************** SH let's calculate a likelihood!! ******************//

int m; int n; double lhood_tmt = 0; double lhood_block = 0;

for (m = 0; m < 192; m++){
	for (n = 0; n < 48; n++){
		if(BlockOne_exp[m][0] != -1){
			lhood_tmt = lhood_tmt + gsl_ran_multinomial_lnpdf(4, sim_output[m], BlockOne_exp[m]);
			printf("%lf\n", lhood_tmt);
		}
		printf("END OF TREATMENT. Likelihood sum for treatment = %lf\n", lhood_tmt);
		lhood_block = lhood_block + lhood_tmt;
		n = 0;
		lhood_tmt = 0;
	}
		else{
		}
}
printf("Likelihood sum across treamtments = %lf\n", lhood_block);



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
