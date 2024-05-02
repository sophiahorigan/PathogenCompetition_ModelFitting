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

//--------------- CC SIMULATION VARIABLES------//
// how does this fuck with what I've already declared?
double DD10=0.0;		double S_start = 0.0;	double S_end = 0.0;
int test_day;
//int line_ticker;
double DDtemp_now;
double hatch = 317.0;       //From Russo et al 1993
double Hlim1 = 3.0;
double Hlim2 = 40.0 - Hlim1;
double pupate = 586.5;     //From Carter et al 1992
double Plim1 = 7.65;
double Plim2 = 41.0 - Plim1;

int limit;
int MAXT4;
int cumday;
double serain[MAX_SUBS][MAX_YEARS];      //Average weather for single epizootic
double serh[MAX_SUBS][MAX_YEARS];
double semaxt[MAX_SUBS][MAX_YEARS];
double seavet[MAX_SUBS][MAX_YEARS];

double lt_params[7]={0.5, 0.6,80,21,1e-6,30,1};


int reps;	//number of stochastic simulations to do per
int Sreps;
double INFECTED;


//-----------VARIABLES-----//

Sreps = 1;
reps = 100;
int r;

double sdensity;
double fdensity;
double vdensity;
double finfF;
double finfV;

double stoch;

int bbf;
int pl,ql;
int rl;
double *hostarr;
double *fungusarr;
double *finfFarr;
double *finfVarr;
double hostave;
double fungusave;
double sum_fungusave;
double hostmax;
int simupeakn;
int *simupeak;
int *simupeak1;
int *simufpt;
int pintv;
hostarr=(double (*))malloc(1000*sizeof(double));
fungusarr=(double (*))malloc(1000*sizeof(double));
finfFarr=(double (*))malloc(1000*sizeof(double));
finfVarr=(double (*))malloc(1000*sizeof(double));

sdensity = 0;
fdensity = 0;
vdensity = 0;

//-------- GET CLIMATE DATA SORTED --------//
// do I want to do the random draw thing Jiawei does? or just use annual input?

//-----LOOP THROUGH YEARS-------
for (year = 0; year < num_year; year++)
{
	if (VERBOSE) print("year = %i\n", year);

	for (sub = 0; sub < num_sub; sub++)
	{
		seavet[sub][year] = 0.0;
    	semaxt[sub][year] = 0.0;
    	serh[sub][year] = 0.0;
    	serain[sub][year] = 0.0;
	}

	//--------- CALCULATE INSECT TIME BASED ON WEATHER-----//
	// need to do for each subpop






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
			Params.STATEVARS[1][sub] = sdensity[sub];
			// R // have R start all the same?
			Params.STATEVARS[2][sub] = fdensity[sub];
			// V
			Params.STATEVARS[3][sub] = vdensity[sub];

			if (VERBOSE) printf("subpop %i: INITS = %lf INITR = %lf INITV = %lf\n", sub, Params.STATEVARS[1][sub], Params.STATEVARS[2][sub], Params.STATEVARS[3][sub]);

				Params.c_a[sub] = generate_param(3);
				Params.l_a[sub] = generate_param(4);
				Params.R_stoch = generate_param(5);
				Params.F_stoch = generate_param(6);

				if (VERBOSE) printf("subpop %i: c_a = %lf l_a = %lf Rstoch = %lf Fstoch = %lf\n", sub, Params.c_a[sub], Params.l_a[sub], Params.R_stoch, Params.F_stoch);
		}

	}
	//----------CALCULATE HATCH AND PUTATION DAYS BASED ON WEATHER---------

	for (sub = 0; sub < num_sub, sub++)
	{
		// Hatch
		DD10 = 0.0;
		test_day = 0;
		S_start[sub] = test_day;
		limit = 361; //CHECK THIS

		while(DD10 <= hatch & test_day < limit)
		{
			DDtemp_now = Params.CCDATA[year][sub][test_day][3] - Hlim1; 
			if (DDtemp_now < 0.0) {DDtemp_now = 0.0;}
			if (DDtemp_now > Hlim2) {DDtemp_now = Hlim2;}
			DD10 = DD10 + DDtemp_now;		
			S_start[sub]++;
			test_day++;
		}
		// Pupation
		DD10 = 0.0;
		test_day = S_start[sub];
		S_end[sub] = test_day;

		while (DD10 <= pupate & test_day < limit)
		{
			DDtemp_now = Params.CCDATA[year][sub][test_day][3] - Plim1;
			if (DDtemp_now < 0.0) {DDtemp_now = 0.0;}
			if (DDtemp_now > Plim2) {DDtemp_now = Plim2;}
			DD10 = DD10 + DDtemp_now;		
			S_end[sub]++;
			test_day++;
		}

		// Epi Length
		Params.EPI_LENGTH[sub] = S_end[sub] - S_start[sub];
		Params.EPI_DIM[sub] = Params.EPI_LENGTH[sub]*2;

		Params.MAX_EPI_LENGTH = Params.MAX_EPI_DIM = 0;
		for (sub = 0; sub < num_sub; sub++)
		{
			if (Params.EPI_LENGTH[sub] > Params.MAX_EPI_LENGTH)
			{
				Params.MAX_EPI_LENGTH = Params.EPI_LENGTH[sub];
			}
		}
		Params.MAX_EPI_DIM = Params.MAX_EPI_LENGTH * 2;

		//----- POTENTIALLY update, or at least trim, weather, based on epi season--------//
		
		for (test_day = S_start[sub]; test_day <= S_end[sub]; test_day++)
		{
				seavet[year][sub] += Params.CCDATA[year][sub][test_day][3];
				semaxt[year][sub] += Params.CCDATA[year][sub][test_day][2];
				serh[year][sub] += Params.CCDATA[year][sub][test_day][1];
				serain[year][sub] += Params.CCDATA[year][sub][test_day][0];
		}

		seavet[year][sub] = seavet[year][sub] / (Params.EPI_LENGTH[sub] + 1);
		semaxt[year][sub] = semaxt[year][sub]/ (Params.EPI_LENGTH[sub] + 1);
		serh[year][sub] = serh[year][sub] / (Params.EPI_LENGTH[sub] + 1);
		serain[year][sub] = serain[year][sub] / (Params.EPI_LENGTH[sub] + 1);
	} //sub

	//------RUN SINGLE EPIZOOTIC MODEL------

	DDEVF(Params,r,year); //figure out dim 

	//------UPDATE PARAMS INTER-ANNUAL MODEL-------

	for (sub = 0; sub < num_sub; sub++) 
	{	
		Params.LONG_TERM_MODEL[year][sub][0] = ; // CumFracInf
		Params.LONG_TERM_MODEL[year][sub][0] = ; // CumFracInfV
		Params.LONG_TERM_MODEL[year][sub][1] = ; // CumFracInfF
		Params.LONG_TERM_MODEL[year][sub][2] = sdensity[sub]; // sdensity //pre or post adjustment? both?
		Params.LONG_TERM_MODEL[year][sub][4] = fdensity[sub]; // fdensity
		Params.LONG_TERM_MODEL[year][sub][4] = vdensity[sub]; // vdensity
		Params.LONG_TERM_MODEL[year][sub][5] = S_start[sub]; // S_start // hatch
		Params.LONG_TERM_MODEL[year][sub][6] = S_end[sub]; // S_end // pupation
		Params.LONG_TERM_MODEL[year][sub][6] = R_start[sub]; // 
		Params.LONG_TERM_MODEL[year][sub][6] = V_start[sub]; // 
		Params.LONG_TERM_MODEL[year][sub][7] = Params.EPI_LENGTH[sub]; // Epi_length // pupation - hatch
		Params.LONG_TERM_MODEL[year][sub][7] = ; // a

		if (Params.PRINT_INTER)
		{
			//fprintf(fpinter, )
		}
	}
	//------RUN INTER-ANNUAL MODEL-------
	// UPDATE TO BE FOR EACH PATCH 
	for (sub = 0; sub < num_sub, sub ++)
	{
		if (VERBOSE) printf("Pre-long term states for subpop %i: S: %lf, F: %lf, V:%lf\n", sub, sdensity[sub], fdensity[sub], vdensity[sub]);

		stoch = exp(gsl_ran_gaussian(r, sto_fec)); //every subpop has some stochasticity in fecundity // should I add stochasticity in predation also?
		//predation // WHAT IS LTPARAMS[4]?
		sdensity[sub] = stoch * fecundity * SusEnd[sub] * (1 - (2 * preda * predb * sdensity[sub]) / (predb * predb + sdensity[sub] * sdensity[sub])) + lt_params[4];
		//no predation
		//sdensity[sub] = stoch * fecundity * SusEnd[sub] + lt_params[4];

		fdensity[sub] = f_max / (1 + exp(-x1 * (log10(InfFungusNext[sub]) - x0)))+ gammafungus * fdensity[sub];

		vdensity[sub] = eta * (phivirus / eta * InfVirusNext[sub] + gammavirus * vdensity[sub] / eta) + 1e-6;
	
		if (sdensity == 0){ // do I want this?
			sdensity = 1e-8;
			if (VERBOSE) printf("Subpopulation %i went extinct.\n", sub);
		}
		
		if (VERBOSE) printf("Post-long term states for subpop %i: S: %lf, F: %lf, V:%lf\n", sub, sdensity[sub], fdensity[sub], vdensity[sub]);
	}

} // year



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



