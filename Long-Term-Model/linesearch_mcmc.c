#include "head.h"
gsl_rng *r;

int main(int argc, char *argv[])
{
///////////////////////////////////////////////////SET-UP///////////////////////////////////////////////////
STRUCTURE Params;
inputdata(&Params);	

time_t start = time(NULL);

#define VERBOSE 1				// select 1 for detailed output

Params.PRINT_INTRA = 1;			// select 1 to print intra annual epizootic dynamics (daily)
Params.PRINT_INTER = 1;			// select 1 to print inter annual epizootic dynamics (yearly)

//--------RANDOM NUMBERS--------
gsl_rng * r;
gsl_rng_env_setup();
const gsl_rng_type * K;
K = gsl_rng_default;
r = gsl_rng_alloc (K);

long seed;
srand((unsigned) time(NULL));
seed = time(NULL)*(int)getpid();
gsl_rng_set(r, seed);

//--------SIM INPUT--------
char *y = argv[1]; char *z = argv[2];
Params.num_sub = atoi(y); Params.num_year = atoi(z);

int num_sub = Params.num_sub;
int num_year = Params.num_year;

printf("Running %i subs for %i years.\n", num_sub, num_year);

//-------GENERAL SETUP-------
int verbose = VERBOSE;
int year; int sub;

//-------TEST MODE--------
int TEST = 1;
if(TEST)
{
	Params.num_sub = 4; Params.num_years = 1;
} else {
	Params.num_sub = 100; Params.num_years = 100;	 
}

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
// go with 100 2km squares

//-----LOOP THROUGH YEARS-------
for (year = 0; year < num_year; year++)
{
	if (VERBOSE) print("year = %i\n", year);

	//-------UPDATE PARAMS--------
	if (year = 0){ //first year, randomly generate initial parameters

		if (VERBOSE) printf("Year 0, assigning initial state variables.\n");

		for (sub = 0; sub < num_sub; sub++)
		{	
			// S
			Params.STATEVARS[1][sub] = generate_param(0);
			// R // have R start all the same?
			Params.STATEVARS[2][sub] = generate_param(1);
			// V
			Params.STATEVARS[3][sub] = generate_param(2);

			if (VERBOSE) printf("subpop %i: INITS = %lf INITR = %lf INITV = %lf\n", sub, Params.STATEVARS[1][sub], Params.STATEVARS[2][sub], Params.STATEVARS[3][sub]);
		}
	}
	else {
		for (sub = 0; sub < num_sub; sub++)
		{	
			// S
			Params.STATEVARS[1][sub] = END VALUE OF LAST EPI;
			// R // have R start all the same?
			Params.STATEVARS[2][sub] = END VALUE OF LAST EPI;
			// V
			Params.STATEVARS[3][sub] = END VALUE OF LAST EPI;

			if (VERBOSE) printf("subpop %i: INITS = %lf INITR = %lf INITV = %lf\n", sub, Params.STATEVARS[1][sub], Params.STATEVARS[2][sub], Params.STATEVARS[3][sub]);

				Params.c_a[sub] = generate_param(3);
				Params.l_a[sub] = generate_param(4);
				Params.R_stoch = generate_param(5);
				Params.F_stoch = generate_param(6);

				if (VERBOSE) printf("subpop %i: c_a = %lf l_a = %lf Rstoch = %lf Fstoch = %lf\n", sub, Params.c_a[sub], Params.l_a[sub], Params.R_stoch, Params.F_stoch);
		}

	}
	//------RUN SINGLE EPIZOOTIC MODEL------
	// change dim
	// what is pop

	int hatch = 0; //do i need this?

	DDEVF(Params,r,dim,epi_length,hatch,year);

	//------UPDATE PARAMS INTER-ANNUAL MODEL-------

	for (sub = 0; sub < num_sub; sub++) 
	{	
		Params->SINGLE_EPI_MODEL[year][sub][day-1][0] = S[sub]/(S[sub]+IV[sub]+IF[sub]); //Saving daily fraction uninfected S 
		Params->SINGLE_EPI_MODEL[year][sub][day-1][1] = IV[sub]/(S[sub]+IV[sub]+IF[sub]); //Saving daily fraction infected V 
		Params->SINGLE_EPI_MODEL[year][sub][day-1][2] = IF[sub]/(S[sub]+IV[sub]+IF[sub]); //Saving daily fraction infected F

		if (Params.PRINT_INTER)
		{
			//fprintf(fpinter, )
		}
	}
	//------RUN INTER-ANNUAL MODEL-------



}

fclose(fpintra);
fclose(fpinter);

}


// inter annual complications
// when does hatch start?
	// check jiawei's long term model
// how to vary weather for each subpop
	// check jiawei's long term model
// can I pass a 2D array to the ode solver? or do I need to loop through the subpops with the ode solver?
	// check colin's patch structure
// if I have to loop, how do I handle the 'timing' array in the daily_statevars.h? initate the subpop loop out there?
// that means that I wouldn't be able to do continuous condia dispersal within ode.h, bc would have to process one subpop at a time
	// check colin's patch structure



