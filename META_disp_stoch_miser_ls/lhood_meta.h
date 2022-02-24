double LHood_Meta(double *RandNumsPass ,size_t dim ,void *Paramstuff)
{
// calls DDEVF, uses results from DDEVF to calculate and return 'hood'
STRUCTURE* Params;
Params = (STRUCTURE*) Paramstuff;

//---------------//CK// Best fit params and initial conditions from previous run //CK//-------------------------------------------------------//

double bestparams[30]={1.0, 1.0, 0.64, 0.000241071699421562, 0, 0, 0.00962435749864498, 10, 20, 50, 0, 0.37161719994828, 0.913699399999732, 2.2223804999527, 0.945435549999967, 0, 525.015699999847, 8.32036899999904, 0.119701349994476, 267.034499999981, 7.88482749903281, 3.80285399989692, 0.070488499999861, 0.233982799999915, 7.05116449999956, 6.38002749970359, 3.54725448752468, 100.157149999888, 291.2745, 0.166585199947054};

int pop2 = 2;

//---------------//CK// Initial conditions for S from field observations //CK//-------------------------------------------------------//

double initialS[8] = {1, 3, 5, 10, 25, 50, 75, 100};
double initialV=1;
double initial_nuF[8] = {5.0e-6, 5.0e-3, 5.0e-3, 5.0e-3, 5.0e-3, 5.0e-3, 5.0e-3, 5.0e-3};



// ------------------------------------------------------------------------------------------------------------------ //
int i=0;int ii; int jj; int k; int l;
int num_adj_pars=29;			// number of adjustable parameters
int pop;
int epi_length = 48;

//size_t dim2;


// ------------------------------------ Declare Likelidhood Quanitites ----------------------------------------------- //
//double pop_lhood, pop_lhood2, pop_err,post_hood;	// population lhood (and posterior lhood) calculated for each initS and initR
//double pop_best_lhood;					// likelihood and error for best initS and initR
//double total_lhood;						// sum of pop_best_lhood over all patches
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
	Params->PARS[k] = bestparams[k];
	//printf("%e\n",Params.PARS[k]);
}

reps = 1;

int year;
//double sdensity;
//double fdensity;
//double vdensity;



double sdensity;
double fdensity;
double vdensity;
sdensity=100; //SH random pick 
fdensity=0.026; //SH from literature
vdensity=0.01; //SH guesstimate

Params->PARS[30+pop]=sdensity; 
VPass=vdensity;
Params->PARS[50+pop]=fdensity;

int dataset;
dataset = Params->j;

//printf("dataset in lhood meta = %i\n", Params->j);


DDEVF(Params,RandNumsPass,dim,pop,48,0,year,dataset);

int m = 0; int n; double lhood_sub = 0; double lhood_meta = 0; double lhood_meta2;
if (dataset==1 || dataset==2 || dataset==3) { //three block sites with subpopulations
	while (m < epi_length*4){
		for (n = 0; n < epi_length; n++){
			if(Params->DATA[dataset][m][0] != -1){
				lhood_sub = lhood_sub + gsl_ran_multinomial_lnpdf(4, Params->MODEL[dataset][m], Params->DATA[dataset][m]);
				//printf("%lf\n", lhood_sub);
			} 
			m++;
		}
		fprintf(fpl, "END OF SUBPOP. Likelihood sum for subpop = %lf\n", lhood_sub);
		lhood_meta = lhood_meta + lhood_sub;
		n = 0;
		lhood_sub = 0;
			
	}
	//fprintf(fpl, "Likelihood for metapop %i = %lf\n", dataset, lhood_meta);
	}
if (dataset==4 || dataset==5 || dataset==6) { //three observational sites with no subpopulations
	for (n = 0; n < epi_length; n++){
		if(Params->DATA[dataset][n][0] != -1){
			lhood_meta = lhood_meta + gsl_ran_multinomial_lnpdf(4, Params->MODEL[dataset][n], Params->DATA[dataset][n]);
			printf("%lf\n", lhood_meta);
		}
	}
	//fprintf(fpl, "Likelihood for metapop %i = %lf\n", dataset, lhood_meta);
}
//convert out of log for MISER
lhood_meta2 = lhood_meta + lhood_adj;
lhood_meta2 = exp(lhood_meta2);

    
return lhood_meta2;
}
