#include "head.h"
gsl_rng *r;

int main(int argc, char *argv[])
{
///////////////////////////////////////////////////SET-UP///////////////////////////////////////////////////
STRUCTURE Params;
inputdata(&Params);	

time_t start = time(NULL);

#define VERBOSE 1				// select 1 for detailed output
#define SIM 1					// 1 for historical, 2 for future

Params.PRINT_INTRA = 0;			// select 1 to print intra annual epizootic dynamics (daily)
Params.PRINT_INTER = 1;			// select 1 to print inter annual epizootic dynamics (yearly)

//--------SET RANDOM SEED------
gsl_rng *r_seed;
r_seed = random_setup();

printf("R is %lf\n", r); 

//--------SIM INPUT--------
char *y = argv[1]; char *z = argv[2];
Params.num_sub = atoi(y); Params.num_year = atoi(z);

//-------GENERAL SETUP-------
int verbose = VERBOSE;
int year; int sub; int i;

//-------TEST MODE--------
int TEST = 1;
if(TEST)
{
	Params.num_sub = 4; Params.num_year = 1;
} else {
	Params.num_sub = 100; Params.num_year = 100;	 
}

int num_sub = Params.num_sub;
int num_year = Params.num_year;

printf("Running %i subs for %i years.\n", num_sub, num_year);

//-------FILES--------
int pid;
pid = getpid();

char nameintra[50];
sprintf(nameintra, "inter_%i_numsub%i_numyears%i", pid, num_sub, num_year);
fpintra = fopen(nameintra, "a+");
setbuf(fpintra, NULL);

char nameinter[50];
sprintf(nameinter, "intra_%i_numsub%i_numyears%i", pid, num_sub, num_year);
fpinter = fopen(nameinter, "a+");
setbuf(fpinter, NULL);

//---------GENERATE DISTANCE MATRIX---------
// go with 12km squares - 12000m
// starting with 4 of them
Params.DISTANCE_MAT[0][0] = Params.DISTANCE_MAT[1][1] = Params.DISTANCE_MAT[2][2] = Params.DISTANCE_MAT[3][3] = 0;
Params.DISTANCE_MAT[0][1] = Params.DISTANCE_MAT[0][2] = Params.DISTANCE_MAT[1][0] = Params.DISTANCE_MAT[1][3] = Params.DISTANCE_MAT[3][1] = Params.DISTANCE_MAT[3][2] = Params.DISTANCE_MAT[2][3] = Params.DISTANCE_MAT[2][0] = 12000; // M
Params.DISTANCE_MAT[0][3] = Params.DISTANCE_MAT[1][2] = Params.DISTANCE_MAT[2][1] = Params.DISTANCE_MAT[2][0] = 16970; // sqrt 288000

//--------------- CC SIMULATION VARIABLES------//
int test_day;
double DDtemp_now; double DD10;
int limit;
int randyear;

double sdensity[MAX_SUBS] = {0.0};
double fdensity[MAX_SUBS] = {0.0};
double vdensity[MAX_SUBS] = {0.0};

double stoch;

//-----LOOP THROUGH YEARS-------
for (year = 0; year < num_year; year++)
{
	if (VERBOSE) printf("year = %i\n", year);

	//-------UPDATE PARAMS--------
	if (year = 0){ // first year, randomly generate initial parameters

		if (VERBOSE) printf("Year 0, assigning initial state variables.\n");

		for (sub = 0; sub < num_sub; sub++) 
		{	
			/*
			// RANDOM		
			// S
			Params.STATEVARS[1][sub] = generate_param(0);
			// R 
			Params.STATEVARS[2][sub] = generate_param(1);
			// V
			Params.STATEVARS[3][sub] = generate_param(2);
			*/

			// FIXED
			// S // larvae per sq m 
			Params.STATEVARS[1][sub] = 100; // made up
			// R // resting spore (per sq m?)
			Params.STATEVARS[2][sub] = 0.00045; // made up
			// V // init fraction infected
			Params.STATEVARS[3][sub] = 0.2; // made up

			if (VERBOSE) printf("subpop %i: INITS = %lf INITR = %lf INITV = %lf\n", sub, Params.STATEVARS[1][sub], Params.STATEVARS[2][sub], Params.STATEVARS[3][sub]);

			// RANDOM
			//Params.c_a[sub] = generate_param(3);
			//Params.l_a[sub] = generate_param(4);

			// FIXED
			Params.c_a[sub] = 0.05; // made up
			Params.l_a[sub] = 0.05; // made up

			if (VERBOSE) printf("subpop %i: c_a = %lf l_a = %lf\n", sub, Params.c_a[sub], Params.l_a[sub]);
		
		}
	}
	else {
		for (sub = 0; sub < num_sub; sub++)
		{	
			// S
			Params.STATEVARS[1][sub] = sdensity[sub];
			// R // have R start all the same?
			Params.STATEVARS[2][sub] = fdensity[sub];
			// V
			Params.STATEVARS[3][sub] = vdensity[sub];

			if (VERBOSE) printf("subpop %i: INITS = %lf INITR = %lf INITV = %lf\n", sub, Params.STATEVARS[1][sub], Params.STATEVARS[2][sub], Params.STATEVARS[3][sub]);

			// RANDOM
			//Params.c_a[sub] = generate_param(3);
			//Params.l_a[sub] = generate_param(4);

			// FIXED
			Params.c_a[sub] = 0.05; // made up
			Params.l_a[sub] = 0.05; // made up

			if (VERBOSE) printf("subpop %i: c_a = %lf l_a = %lf\n", sub, Params.c_a[sub], Params.l_a[sub]);
		}

	}
	//----------DRAW ANNUAL WEATHER FOR EACH SUBPOP------------------------
	for (sub = 0; sub < num_sub; sub++)
	{	
		// FIX THIS MAYHEM // random draw year 1-10
		/*
		gsl_rng_max() = 9;
		gsl_rng_min() = 0;
		unsigned long int gsl_rng_get(const gsl_rng *r_seed) randyear; */

		randyear = 2; // tmp

		for (i = 0; i < 365; i++)
		{

			// do I want rand draw here? // each day from a different year

			if (SIM == 1) // HISTORICAL
			{
				Params.WEATHER[sub][i][0] = Params.HIST_WEATHER[randyear][sub][i][0]; // rain	
				Params.WEATHER[sub][i][1] = Params.HIST_WEATHER[randyear][sub][i][1]; // rh	
				Params.WEATHER[sub][i][2] = Params.HIST_WEATHER[randyear][sub][i][2]; // maxt
				Params.WEATHER[sub][i][3] = Params.HIST_WEATHER[randyear][sub][i][3]; // avet	
			}
			if (SIM == 2) // FUTURE
			{
				Params.WEATHER[sub][i][0] = Params.CC_WEATHER[randyear][sub][i][0]; // rain	
				Params.WEATHER[sub][i][1] = Params.CC_WEATHER[randyear][sub][i][1]; // rh	
				Params.WEATHER[sub][i][2] = Params.CC_WEATHER[randyear][sub][i][2]; // maxt
				Params.WEATHER[sub][i][3] = Params.CC_WEATHER[randyear][sub][i][3]; // avet			
			}
		}
	}

	//----------CALCULATE HATCH AND PUPATION DAYS BASED ON TEMPERATURE---------

	for (sub = 0; sub < num_sub; sub++)
	{
		// Hatch
		DD10 = 0.0;
		test_day = 0;
		Params.S_start[sub] = test_day;
		limit = 361; //CHECK THIS

		while(DD10 <= hatch & test_day < limit)
		{
			DDtemp_now = Params.WEATHER[sub][test_day][3] - Hlim1; // avet
			if (DDtemp_now < 0.0) {DDtemp_now = 0.0;}
			if (DDtemp_now > Hlim2) {DDtemp_now = Hlim2;}
			DD10 = DD10 + DDtemp_now;		
			Params.S_start[sub]++;
			test_day++;
		}
		// Pupation
		DD10 = 0.0;
		test_day = Params.S_start[sub];
		Params.S_end[sub] = test_day;

		while (DD10 <= pupate & test_day < limit)
		{
			DDtemp_now = Params.WEATHER[sub][test_day][3] - Plim1; // avet
			if (DDtemp_now < 0.0) {DDtemp_now = 0.0;}
			if (DDtemp_now > Plim2) {DDtemp_now = Plim2;}
			DD10 = DD10 + DDtemp_now;		
			Params.S_end[sub]++;
			test_day++;
		}

		// Epi Length
		Params.EPI_LENGTH[sub] = Params.S_end[sub] - Params.S_start[sub];

		Params.MAX_EPI_LENGTH = 0; 
		for (sub = 0; sub < num_sub; sub++)
		{
			if (Params.EPI_LENGTH[sub] > Params.MAX_EPI_LENGTH)
			{
				Params.MAX_EPI_LENGTH = Params.EPI_LENGTH[sub];
			}
		}

	} //sub

	//------RUN SINGLE EPIZOOTIC MODEL------

	DDEVF(&Params,r_seed,year); //

	//------UPDATE PARAMS INTER-ANNUAL MODEL-------

	for (sub = 0; sub < num_sub; sub++) 
	{	
		Params.LONG_TERM_MODEL[year][sub][0] = Params.Vkill[sub] + Params.Fkill[sub]; // CumFracInf
		Params.LONG_TERM_MODEL[year][sub][1] = Params.Vkill[sub]; // CumFracInfV
		Params.LONG_TERM_MODEL[year][sub][2] = Params.Fkill[sub]; // CumFracInfF
		Params.LONG_TERM_MODEL[year][sub][3] = sdensity[sub]; // sdensity //pre or post adjustment? both?
		Params.LONG_TERM_MODEL[year][sub][4] = fdensity[sub]; // fdensity
		Params.LONG_TERM_MODEL[year][sub][5] = vdensity[sub]; // vdensity
		Params.LONG_TERM_MODEL[year][sub][6] = Params.S_start[sub]; // S_start // hatch
		Params.LONG_TERM_MODEL[year][sub][7] = Params.S_end[sub]; // S_end // pupation
		Params.LONG_TERM_MODEL[year][sub][8] = Params.R_start[sub]; // 
		Params.LONG_TERM_MODEL[year][sub][9] = Params.V_start[sub]; // 
		Params.LONG_TERM_MODEL[year][sub][10] = Params.EPI_LENGTH[sub]; // Epi_length // pupation - hatch
		Params.LONG_TERM_MODEL[year][sub][11] = Params.c_a[sub]; // a
		Params.LONG_TERM_MODEL[year][sub][12] = Params.l_a[sub]; // a

		if (Params.PRINT_INTER)
		{
			//fprintf(fpinter, )
		}
	}
	//------RUN INTER-ANNUAL MODEL-------
	// UPDATE TO BE FOR EACH PATCH 
	for (sub = 0; sub < num_sub; sub ++)
	{
		if (VERBOSE) printf("Pre-long term states for subpop %i: S: %lf, F: %lf, V:%lf\n", sub, sdensity[sub], fdensity[sub], vdensity[sub]);

		stoch = exp(gsl_ran_gaussian(r_seed, sto_fec)); //every subpop has some stochasticity in fecundity // should I add stochasticity in predation also?
		//predation // WHAT IS LTPARAMS[4]?
		sdensity[sub] = stoch * fecundity * SusEnd[sub] * (1 - (2 * preda * predb * sdensity[sub]) / (predb * predb + sdensity[sub] * sdensity[sub])) + 1e-6;
		//no predation
		//sdensity[sub] = stoch * fecundity * SusEnd[sub] + lt_params[4];

		fdensity[sub] = f_max / (1 + exp(-x1 * (log10(InfFungusNext[sub]) - x0)))+ gammafungus * fdensity[sub];

		vdensity[sub] = eta * (phivirus / eta * InfVirusNext[sub] + gammavirus * vdensity[sub] / eta) + 1e-6;
	
		if (sdensity == 0){ // do I want this?
			//sdensity = 1e-8;
			if (VERBOSE) printf("Subpopulation %i went extinct.\n", sub);
		}
		
		if (VERBOSE) printf("Post-long term states for subpop %i: S: %lf, F: %lf, V:%lf\n", sub, sdensity[sub], fdensity[sub], vdensity[sub]);
	}

} // year


fclose(fpintra);
fclose(fpinter);

}
