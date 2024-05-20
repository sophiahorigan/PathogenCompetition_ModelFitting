#include "head.h"
gsl_rng *r;

int main(int argc, char *argv[])
{
///////////////////////////////////////////////////SET-UP///////////////////////////////////////////////////

STRUCTURE Params;

time_t start = time(NULL);

Params.PRINT_INTRA = 0;			// select 1 to print intra annual epizootic dynamics (daily)
Params.PRINT_INTER = 0;			// select 1 to print inter annual epizootic dynamics (yearly)

//--------RANDOM NUMBERS--------
const gsl_rng * r;
gsl_rng_env_setup();
const gsl_rng_type * K;
K = gsl_rng_default;
r = gsl_rng_alloc (K);

long seed;
srand((unsigned) time(NULL));
seed = time(NULL)*(int)getpid();
gsl_rng_set(r, seed);

//-------GENERAL SETUP-------
int year; int sub; int i;

//-------TEST MODE--------
Params.num_sub = 4; Params.num_year = 1; Params.grid_length = 2; //sqrt of num_sub 

int num_sub = Params.num_sub;
int num_year = Params.num_year;

//-------DECLARATIONS--------
printf("Running %i subs for %i years.\n", num_sub, num_year);

if(SIM == 1 && VERBOSE)
{
	printf("Simulation type: HISTORICAL\n");
}
if(SIM == 2 && VERBOSE)
{
	printf("Simulation type: FUTURE\n");
}

//--------LOAD WEATHER DATA-----
inputdata(&Params);	

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

//---------GENERATE DISTANCE MATRIX--------- // IS THIS WHY THERE"S A SEG FAULT WHEN SUBPOP = 100?
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
	if (year == 0){ // first year, randomly generate initial parameters

		if (VERBOSE) printf("Year 0, assigning initial state variables.\n");

		for (sub = 0; sub < num_sub; sub++) 
		{	
			/*
			// RANDOM		
			// S
			Params.STATEVARS[1][sub] = sdensity[sub] = generate_param(0);
			// R 
			Params.STATEVARS[2][sub] = fdensity[sub] = generate_param(1);
			// V
			Params.STATEVARS[3][sub] = vdensity[sub] = generate_param(2);
			*/

			// FIXED
			// S // larvae per sq m 
			Params.STATEVARS[1][sub] = sdensity[sub] = 100; // made up
			// R // resting spore (per sq m?)
			Params.STATEVARS[2][sub] = fdensity[sub] = 0.00045; // made up
			// V // init fraction infected
			Params.STATEVARS[3][sub] = vdensity[sub] = 0.2; // made up

			if (VERBOSE) printf("subpop %i: INITS = %lf INITR = %lf INITV = %lf\n", sub, Params.STATEVARS[1][sub], Params.STATEVARS[2][sub], Params.STATEVARS[3][sub]);

			// RANDOM
			//Params.c_a[sub] = generate_param(3);
			//Params.l_a[sub] = generate_param(4);

			// FIXED
			Params.c_a[sub] = 0.05; // made up
			Params.l_a[sub] = 0.05; // made up

			if (VERBOSE) printf("subpop %i: c_a = %lf l_a = %lf\n", sub, Params.c_a[sub], Params.l_a[sub]);

			// RANDOM
			//Params.R_stoch = generate_param();
			//Params.F_stoch = generate_param();

			// FIXED
			Params.R_stoch[sub] = 0.004; // made up 
			Params.F_stoch[sub] = 0.2;	// made up

			if (VERBOSE) printf("subpop %i: R_stoch = %lf F_stoch = %lf\n", sub, Params.R_stoch[sub], Params.F_stoch[sub]);


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
		if (VERBOSE) printf("Sub: %i\n", sub);
		// FIX THIS MAYHEM // random draw year 1-10
		/*
		gsl_rng_max() = 9;
		gsl_rng_min() = 0;
		unsigned long int gsl_rng_get(const gsl_rng *r) randyear; */

		randyear = 0; // tmp

		if (VERBOSE) printf("Rand year for weather draw = %i\n", randyear);

		for (i = 0; i < 365; i++)
		{
			if (SIM == 1) // HISTORICAL
			{
				Params.WEATHER[sub][i][0] = Params.HIST_WEATHER[randyear][sub][i][0]; // rain	
				Params.WEATHER[sub][i][1] = Params.HIST_WEATHER[randyear][sub][i][1]; // rh	
				Params.WEATHER[sub][i][2] = Params.HIST_WEATHER[randyear][sub][i][2]; // maxt
				Params.WEATHER[sub][i][3] = Params.HIST_WEATHER[randyear][sub][i][3]; // avet	
				//printf("%lf %lf %lf %lf\n", Params.WEATHER[sub][i][0], Params.WEATHER[sub][i][1], Params.WEATHER[sub][i][2], Params.WEATHER[sub][i][3]);
			}
			if (SIM == 2) // FUTURE
			{
				Params.WEATHER[sub][i][0] = Params.CC_WEATHER[randyear][sub][i][0]; // rain	
				Params.WEATHER[sub][i][1] = Params.CC_WEATHER[randyear][sub][i][1]; // rh	
				Params.WEATHER[sub][i][2] = Params.CC_WEATHER[randyear][sub][i][2]; // maxt
				Params.WEATHER[sub][i][3] = Params.CC_WEATHER[randyear][sub][i][3]; // avet			
			}
		}
		printf("%lf\n", Params.WEATHER[sub][200][0]);
	}
	if (VERBOSE) printf("Weather set.\n");


	//----------CALCULATE HATCH AND PUPATION DAYS BASED ON TEMPERATURE---------

	for (sub = 0; sub < num_sub; sub++)
	{

		if (VERBOSE) printf("For sub %i:\n", sub);

		// Hatch
		DD10 = 0.0;
		test_day = 0;
		Params.S_start[sub] = test_day;
		limit = 361; //CHECK THIS

		while(DD10 <= hatch & test_day < limit) // is this right?
		{
			DDtemp_now = Params.WEATHER[sub][test_day][3] - Hlim1; // avet
			if (DDtemp_now < 0.0) {DDtemp_now = 0.0;}
			if (DDtemp_now > Hlim2) {DDtemp_now = Hlim2;}
			DD10 = DD10 + DDtemp_now;		
			Params.S_start[sub]++;
			test_day++;
		}
		if (VERBOSE) printf("Hatch day: %i\n", Params.S_start[sub]);

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
		if (VERBOSE) printf("Pupation day: %i\n", Params.S_end[sub]);

		// Epi Length
		Params.EPI_LENGTH[sub] = Params.S_end[sub] - Params.S_start[sub];

		if (VERBOSE) printf("Epi length: %i\n", Params.EPI_LENGTH[sub]);

	} //sub
	// earliest epi start
	Params.EARLIEST_EPI_START = 365;
	for (sub = 0; sub < num_sub; sub++)
	{
		if (Params.S_start[sub] < Params.EARLIEST_EPI_START)
		{
			Params.EARLIEST_EPI_START = Params.S_start[sub];
		}
	}
	if (VERBOSE) printf("Earliest epi start: %i\n", Params.EARLIEST_EPI_START);

	// Latest epi end
	Params.LATEST_EPI_END = 0;
	for (sub = 0; sub < num_sub; sub++)
	{
		if (Params.S_end[sub] > Params.LATEST_EPI_END)
		{
			Params.LATEST_EPI_END = Params.S_end[sub];
		}
	}
	if (VERBOSE) printf("Latest epi end: %i\n", Params.LATEST_EPI_END);

	// Max epi length
	Params.MAX_EPI_LENGTH = 0; 
	for (sub = 0; sub < num_sub; sub++)
	{
		if (Params.EPI_LENGTH[sub] > Params.MAX_EPI_LENGTH)
		{
			Params.MAX_EPI_LENGTH = Params.EPI_LENGTH[sub];
		}
	}
	if (VERBOSE) printf("Max epi length: %i\n", Params.MAX_EPI_LENGTH);

	//------RUN SINGLE EPIZOOTIC MODEL------

	if (VERBOSE) printf("All initial conditions set. Beginning single epizootic ode\n");

	DDEVF(&Params,r,year); 

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

		stoch = exp(gsl_ran_gaussian(r, sto_fec)); //every subpop has some stochasticity in fecundity // should I add stochasticity in predation also?
		//predation // WHAT IS LTPARAMS[4]?
		sdensity[sub] = stoch * fecundity * Params.SusEnd[sub] * (1 - (2 * preda * predb * sdensity[sub]) / (predb * predb + sdensity[sub] * sdensity[sub])) + 1e-6;
		//no predation
		//sdensity[sub] = stoch * fecundity * SusEnd[sub] + lt_params[4];

		fdensity[sub] = f_max / (1 + exp(-x1 * (log10(Params.InfFungusNext[sub]) - x0)))+ gammafungus * fdensity[sub];

		vdensity[sub] = eta * (phivirus / eta * Params.InfVirusNext[sub] + gammavirus * vdensity[sub] / eta) + 1e-6;
	
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
