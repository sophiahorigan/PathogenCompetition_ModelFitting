#include "head_meta.h"
gsl_rng *r;
//-----------------------Dot Product-----------------------//
float DotProduct (int Length, double *Holder, double *PCA)
{
  double answer = 0;

  int i;
  for(i=0;i<Length;i++)
    answer += PCA[i]*Holder[i];   //JL: Used in the reconstruction of parameter values from PCA

  return(answer);

}

//-----------------------line-search mcmc-------------------------//

int main(void)
{
int linesearch = 0;
int reals = 1;
int mcmc = 0;

STRUCTURE Params;
// ----------------------------------------Set Up-------------------------------------------------------------------- //
int i=0; int j;int ii; int jj; int k; int l; 
int epi_length = 48;
inputdata(&Params);				
// ---------------------------------------- Random Number Stuff ------------------------------------------------------ //
gsl_rng *r_seed;
r_seed=random_setup();

//----------------------------------Set-Up Line Search------------------------//

//set initial likelihood adjustment values
int searches = 5;
int round;
int numround = 2;
int calls;
size_t dim;
//determine fit parameters
//OBS PRIORS*****
//virus(3), fungus(1), EnhSus(1), stoch(2), obs init conditions(8))
//int fit_length = 15;
//int fit_list[15] = {4, 5, 6, 7, 8, 9, 10, 75, 76, 77, 78, 79, 80, 81, 82};

//L POP FIT*******
 //exp init R (3), virus(3), fungus(1), EnhSus(1), stoch(2), a_l_pop(1), m_l_pop(1)
int fit_length = 12;
int fit_list[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 43, 59};

//L META FIT*****
//exp init R (3), virus(3), fungus(1), EnhSus(1), stoch(2), a_l_pop(3), m_l_pop(3)
//int fit_length = 16;
//int fit_list[16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 44, 45, 46, 60, 61, 62};

//L SUB FIT*****
//exp init R (3), virus(3), fungus(1), EnhSus(1), stoch(2), a_l_sub(12), m_l_sub(12)
//int fit_length = 34;
//int fit_list[34] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73 ,74};


//generate initial parameter values for all parameters
int num_ltfparams = 82;
double ltf_params[82] = {0};   
double init_ltfparams[82] = {0};
double step_size[82] = {0};
double temp[82] = {0};

double log_prior = 0;

for (i=0;i<num_ltfparams;i++){ 
    double randn = gsl_rng_uniform_pos(r_seed);
	//printf("i=%i\t rand=%lf\n", i, randn);
    temp[i] = exp(ls_bound(i,1)) + randn * exp(ls_bound(i,2)); //this should be between 0 and 1
	ltf_params[i] = log(temp[i]);
    init_ltfparams[i] = ltf_params[i]; 
    //printf("%lf\n",init_ltfparams[i]);
	//printf("i = %i\t, temp = %lf\t, lft_params = %lf\n",i, temp[i], init_ltfparams[i]);
	step_size[i] = (ls_bound(i,2)-ls_bound(i,1))/(searches*3);
	//printf("i = %i\t, step size = %lf\n",i, step_size[i]);
}

double localmax_params[82]={0};         //Array to record param values for the local max likelihood in line search
int a,b,c;								//indexing loops
double best_posterior;
for (c=0;c<num_ltfparams;c++){			//initial parameters begin as 'best' parameters
    localmax_params[c]=ltf_params[c];
}
//calculate priors
for (k=0; k<num_ltfparams; k++){
	log_prior = log_prior + log(gsl_ran_flat_pdf(exp(ltf_params[k]), prior_bound(k,1), (prior_bound(k,2)+prior_bound(k,1))));
	//printf("k = %i\t param = %lf\t log prior = %lf\n", k, exp(ltf_params[k]), log_prior);
}

//-------------------------------------------------Realizations-----------------------------------------------//
if(reals==1){

	char name1[50];
	sprintf(name1, "model_realizations");
	fpr=fopen(name1, "a+");

	//********FIXED PARAMS***********
		//INITIAL CONDITIONS
		//meta1
		Params.FITINIT[1][0] = 30; //initS //FX
		Params.FITINIT[1][1] = 30; //initS //FX
		Params.FITINIT[1][2] = 30; //initS //FX
		Params.FITINIT[1][3] = 30; //initS //FX

		Params.FITINIT[1][4] = 1e-100; //initV //fonly //FX
		Params.FITINIT[1][5] = 0.0009; //initV  //FX
		Params.FITINIT[1][6] = 0.0009; //initV //FX
		Params.FITINIT[1][7] = 1e-100; //initV //control //FX

		Params.FITINIT[1][9] = 1e-100; //initR //vonly  //FX
		Params.FITINIT[1][10] = 1e-100; //initR //fv //FX
		Params.FITINIT[1][11] = 1e-100; //initR //control //FX

		//meta2
		Params.FITINIT[2][0] = 30; //initS  //FX
		Params.FITINIT[2][1] = 30; //initS //FX
		Params.FITINIT[2][2] = 30; //initS //FX
		Params.FITINIT[2][3] = 30; //initS //FX
		Params.FITINIT[2][4] = 1e-100; //initV //fonly //FX
		Params.FITINIT[2][5] = 0.0009; //initV  //FX
		Params.FITINIT[2][6] = 0.0009; //initV //FX
		Params.FITINIT[2][7] = 1e-100; //initV //control //FX
		//meta3
		Params.FITINIT[3][0] = 30; //initS //FX
		Params.FITINIT[3][1] = 30; //initS //FX
		Params.FITINIT[3][2] = 30; //initS //FX
		Params.FITINIT[3][3] = 30; //initS //FX
		Params.FITINIT[3][4] = 1e-100; //initV //f only //FX
		Params.FITINIT[3][5] = 0.0009; //initV //FX
		Params.FITINIT[3][6] = 0.0009; //initV //FX
		Params.FITINIT[3][7] = 1e-100; //initV //control //FX
		//meta5
		Params.FITINIT[5][8] = 1e-100; //initR

		//************FIT PARAMS*******************
		//META SPECIFIC INIT R //3
		//meta1
		Params.FITINIT[1][8] = 0.000726; //initR //fonly  //FT* //0.000726
		//meta2
		Params.FITINIT[2][8] = 	0.001749; //initR //fonly //FX //0.001749
		Params.FITINIT[2][9] = 0.001749; //initR //vonly //FX
		Params.FITINIT[2][10] = 0.001749; //initR //fv //FX
		Params.FITINIT[2][11] = 0.001749; //initR //control //FX
		//meta3
		Params.FITINIT[3][8] = 0.00226; //initR //fonly //0.00226
		Params.FITINIT[3][9] = 0.00226; //initR //vonly
		Params.FITINIT[3][10] = 0.00226; //initR //fv
		Params.FITINIT[3][11] = 0.00226; //initR //control

		//VIRUS //3
		Params.muV			= 0.039; //Fuller 2012 //virus decay //0.39
		Params.CV			= 0.086; //hetereogeneity to virus infection //previously 0.86
		Params.nuV    		= 0.5;

		//FUNGUS //1
		Params.specific_nuF	= 0.0001; //fungus transmissison

		//ENHANCED SUSEPTIBILITY //1
		Params.VFSus		= 0;

		//STOCHASTICITY //2
		Params.R_stoch 		= 1.092307;
		Params.F_stoch		= 0.000912;

		//CONIDIA DISPERSAL
		//a_c - pop //1
		Params.a_c_pop = exp(ltf_params[11]);
		//a_c - meta //3
		Params.a_c_meta[1] = exp(ltf_params[12]);
		Params.a_c_meta[2] = exp(ltf_params[13]);
		Params.a_c_meta[3] = exp(ltf_params[14]);
		//a_c - sub //12
		//meta 1
		Params.a_c_sub[1][0] = exp(ltf_params[15]); 
		Params.a_c_sub[1][1] = exp(ltf_params[16]);
		Params.a_c_sub[1][2] = exp(ltf_params[17]);
		Params.a_c_sub[1][3] = exp(ltf_params[18]);
		//meta 2
		Params.a_c_sub[2][0] = exp(ltf_params[19]); 
		Params.a_c_sub[2][1] = exp(ltf_params[20]);
		Params.a_c_sub[2][2] = exp(ltf_params[21]);
		Params.a_c_sub[2][3] = exp(ltf_params[22]);
		//meta 3
		Params.a_c_sub[3][0] = exp(ltf_params[23]); 
		Params.a_c_sub[3][1] = exp(ltf_params[24]);
		Params.a_c_sub[3][2] = exp(ltf_params[25]);
		Params.a_c_sub[3][3] = exp(ltf_params[26]);
		//m_c - pop //1
		Params.m_c_pop		= exp(ltf_params[27]); 
		//m_c - meta //3
		Params.m_c_meta[1]	= exp(ltf_params[28]);
		Params.m_c_meta[2]	= exp(ltf_params[29]);
		Params.m_c_meta[3]	= exp(ltf_params[30]);
		//m_c - sub //12
		//meta1
		Params.m_c_sub[1][0] = exp(ltf_params[31]);
		Params.m_c_sub[1][1] = exp(ltf_params[32]);
		Params.m_c_sub[1][2] = exp(ltf_params[33]);
		Params.m_c_sub[1][3] = exp(ltf_params[34]);
		//meta2	
		Params.m_c_sub[2][0] = exp(ltf_params[35]);
		Params.m_c_sub[2][1] = exp(ltf_params[36]);
		Params.m_c_sub[2][2] = exp(ltf_params[37]);
		Params.m_c_sub[2][3] = exp(ltf_params[38]);
		//meta3
		Params.m_c_sub[3][0] = exp(ltf_params[39]);
		Params.m_c_sub[3][1] = exp(ltf_params[40]);
		Params.m_c_sub[3][2] = exp(ltf_params[41]);
		Params.m_c_sub[3][3] = exp(ltf_params[42]);

		//LARVAL DISPERSAL
		//a_l - pop //1
		Params.a_l_pop = 0.013895;
		//a_l - meta //3
		Params.a_l_meta[1] = exp(ltf_params[44]);
		Params.a_l_meta[2] = exp(ltf_params[45]);
		Params.a_l_meta[3] = exp(ltf_params[46]);
		//a_l - sub //12
		//meta 1
		Params.a_l_sub[1][0] = exp(ltf_params[47]); 
		Params.a_l_sub[1][1] = exp(ltf_params[48]);
		Params.a_l_sub[1][2] = exp(ltf_params[49]);
		Params.a_l_sub[1][3] = exp(ltf_params[50]);
		//meta 2
		Params.a_l_sub[2][0] = exp(ltf_params[51]); 
		Params.a_l_sub[2][1] = exp(ltf_params[52]);
		Params.a_l_sub[2][2] = exp(ltf_params[53]);
		Params.a_l_sub[2][3] = exp(ltf_params[54]);
		//meta 3
		Params.a_l_sub[3][0] = exp(ltf_params[55]); 
		Params.a_l_sub[3][1] = exp(ltf_params[56]);
		Params.a_l_sub[3][2] = exp(ltf_params[57]);
		Params.a_l_sub[3][3] = exp(ltf_params[58]);
		//m_l - pop //1
		Params.m_l_pop		= 0.8; 
		//m_l - meta //3
		Params.m_l_meta[1]	= 0.8;
		Params.m_l_meta[2]	= 0.4;
		Params.m_l_meta[3]	= 0.8;
		//m_l - sub //12
		//meta1
		Params.m_l_sub[1][0] = exp(ltf_params[63]);
		Params.m_l_sub[1][1] = exp(ltf_params[64]);
		Params.m_l_sub[1][2] = exp(ltf_params[65]);
		Params.m_l_sub[1][3] = exp(ltf_params[66]);
		//meta2	
		Params.m_l_sub[2][0] = exp(ltf_params[67]);
		Params.m_l_sub[2][1] = exp(ltf_params[68]);
		Params.m_l_sub[2][2] = exp(ltf_params[69]);
		Params.m_l_sub[2][3] = exp(ltf_params[70]);
		//meta3
		Params.m_l_sub[3][0] = exp(ltf_params[71]);
		Params.m_l_sub[3][1] = exp(ltf_params[72]);
		Params.m_l_sub[3][2] = exp(ltf_params[73]);
		Params.m_l_sub[3][3] = exp(ltf_params[74]);

		//OBS INIT CONDITIONS //8
		//meta4
		Params.FITINIT[4][0] = exp(ltf_params[75]); //initS
		Params.FITINIT[4][4] = exp(ltf_params[76]); //initV
		Params.FITINIT[4][8] = exp(ltf_params[77]); //initR
		//meta5
		Params.FITINIT[5][0] = exp(ltf_params[78]); //initS
		Params.FITINIT[5][4] = exp(ltf_params[79]); //initV
		//meta6
		Params.FITINIT[6][0] = exp(ltf_params[80]); //initS
		Params.FITINIT[6][4] = exp(ltf_params[81]); //initV
		Params.FITINIT[6][8] = exp(ltf_params[82]); //initR
	//virus transmission
	
	

	//start realizations. In this case, calls = # realizations
	double lhood_meta=0; double log_lhood_meta=0; double total_loghood_metas = 0;
	double new_posterior=0;
	double meta_err=0;
	double lhood_total=0;
	double lhood_reps=0;

	calls=5;					//number of stochastic simulations for each parameter and IC set //100-300

	//for(j=1; j<=DATA_SETS; j++){
		for(j=1; j<4; j++){
			Params.j = j;

			//printf("in j\n");

			Params.miser_ticker = 1; //used to set initial adjustment

			Params.miser2_flag = 0; //used to run MISER on parameter set a second time with better adjustment 

			dim = 48*2; 

			//define function
			gsl_monte_function G = { &LHood_Meta, dim, &Params };	// declares function calling lhood_meta.h
			double xl[dim];	double xu[dim];	// need to redeclare xl and xu since the size changes
			for (jj=0;jj<dim;jj++)	{
				xl[jj]=0;	
				xu[jj]=1;
			}

			gsl_monte_miser_state *s = gsl_monte_miser_alloc(dim);
			gsl_monte_miser_integrate (&G,xl,xu,dim,calls,r_seed,s,&lhood_meta,&meta_err); //call MISER, pop_lhood is output from .h (likelihood value)
			gsl_monte_miser_free(s);

			log_lhood_meta = log(lhood_meta) - Params.lhood_adjust[j];
			if(isnan(log_lhood_meta) || isinf(log_lhood_meta)){
				log_lhood_meta = -9999; //very bad score
			}
			
			total_loghood_metas = total_loghood_metas + log_lhood_meta;

			new_posterior = total_loghood_metas + log_prior;
			//printf("dataset = %i\t likelihood = %lf\n", j, new_posterior);
	}
	fclose(fpr); 

}
//----------------------------------------------------Print Output to File-------------------------------------------//

if(linesearch==1){
int pid;
pid=getpid();

char namels[50];
sprintf(namels, "allmeta_s%i_r%i_%d", searches, numround, pid);
fpls=fopen(namels, "a+");

///////////////////////////////////////////////////LINE-SEARCH///////////////////////////////////////////////////
for (round=0;round<numround;round++){
	//printf("round=%i\n", round);
	best_posterior=-66666666666666;
	a=0;
	int i=0;

	while (i<fit_length){
		a = fit_list[i];

		if (round>0){		
			ltf_params[a] = ltf_params[a] - (step_size[a] * searches);
			//printf("ltf round 0=%lf\n", ltf_params[a]);
			if(exp(ltf_params[a]) < exp(ls_bound(a,1))){
				//printf("hit lower bound i=%i\n", a);
				ltf_params[a] = ls_bound(a,1);
			}
		}
		for (b=0;b<searches;b++){ //I think my ls only wanders up
			if (b>0){
				ltf_params[a] = ltf_params[a] + step_size[a];
				//printf("ltf round b=%lf\n", ltf_params[a]);
				if(exp(ltf_params[a]) > exp(ls_bound(a,2))){
					ltf_params[a] = ls_bound(a,2);
					//printf("hit upper bound i=%i\n", a);
				}
			}
		//********FIXED PARAMS***********
		//INITIAL CONDITIONS
		//meta1
		Params.FITINIT[1][0] = 100; //initS //FX
		Params.FITINIT[1][1] = 100; //initS //FX
		Params.FITINIT[1][2] = 100; //initS //FX
		Params.FITINIT[1][3] = 100; //initS //FX
		Params.FITINIT[1][4] = 1e-10; //initV //fonly //FX
		Params.FITINIT[1][5] = 0.2; //initV  //FX
		Params.FITINIT[1][6] = 0.2; //initV //FX
		Params.FITINIT[1][7] = 1e-10; //initV //control //FX
		Params.FITINIT[1][9] = 1e-15; //initR //vonly  //FX
		Params.FITINIT[1][10] = 1e-15; //initR //fv //FX
		Params.FITINIT[1][11] = 1e-15; //initR //control //FX
		//meta2
		Params.FITINIT[2][0] = 100; //initS  //FX
		Params.FITINIT[2][1] = 100; //initS //FX
		Params.FITINIT[2][2] = 100; //initS //FX
		Params.FITINIT[2][3] = 100; //initS //FX
		Params.FITINIT[2][4] = 1e-10; //initV //fonly //FX
		Params.FITINIT[2][5] = 0.2; //initV  //FX
		Params.FITINIT[2][6] = 0.2; //initV //FX
		Params.FITINIT[2][7] = 1e-10; //initV //control //FX
		//meta3
		Params.FITINIT[3][0] = 100; //initS //FX
		Params.FITINIT[3][1] = 100; //initS //FX
		Params.FITINIT[3][2] = 100; //initS //FX
		Params.FITINIT[3][3] = 100; //initS //FX
		Params.FITINIT[3][4] = 1e-10; //initV //f only //FX
		Params.FITINIT[3][5] = 0.2; //initV //FX
		Params.FITINIT[3][6] = 0.2; //initV //FX
		Params.FITINIT[3][7] = 1e-10; //initV //control //FX
		//meta5
		Params.FITINIT[5][8] = 1e-15; //initR

		//************FIT PARAMS*******************
		//META SPECIFIC INIT R //3
		//meta1
		Params.FITINIT[1][8] = exp(ltf_params[1]); //initR //fonly  //FT*
		//meta2
		Params.FITINIT[2][8] = exp(ltf_params[2]); //initR //fonly //FX
		Params.FITINIT[2][9] = exp(ltf_params[2]); //initR //vonly //FX
		Params.FITINIT[2][10] = exp(ltf_params[2]); //initR //fv //FX
		Params.FITINIT[2][11] = exp(ltf_params[2]); //initR //control //FX
		//meta3
		Params.FITINIT[3][8] = exp(ltf_params[3]); //initR //fonly
		Params.FITINIT[3][9] = exp(ltf_params[3]); //initR //vonly
		Params.FITINIT[3][10] = exp(ltf_params[3]); //initR //fv
		Params.FITINIT[3][11] = exp(ltf_params[3]); //initR //control

		//VIRUS //3
		Params.muV			= exp(ltf_params[4]); //Fuller 2012 //virus decay //0.39
		Params.CV			= exp(ltf_params[5]); //hetereogeneity to virus infection //previously 0.86
		Params.nuV    		= exp(ltf_params[6]);

		//FUNGUS //1
		Params.specific_nuF	= exp(ltf_params[7]); //fungus transmission

		//ENHANCED SUSEPTIBILITY //1
		Params.VFSus		= exp(ltf_params[8]);

		//STOCHASTICITY //2
		Params.R_stoch 		= exp(ltf_params[9]);
		Params.F_stoch		= exp(ltf_params[10]);

		//CONIDIA DISPERSAL
		//a_c - pop //1
		Params.a_c_pop = exp(ltf_params[11]);
		//a_c - meta //3
		Params.a_c_meta[1] = exp(ltf_params[12]);
		Params.a_c_meta[2] = exp(ltf_params[13]);
		Params.a_c_meta[3] = exp(ltf_params[14]);
		//a_c - sub //12
		//meta 1
		Params.a_c_sub[1][0] = exp(ltf_params[15]); 
		Params.a_c_sub[1][1] = exp(ltf_params[16]);
		Params.a_c_sub[1][2] = exp(ltf_params[17]);
		Params.a_c_sub[1][3] = exp(ltf_params[18]);
		//meta 2
		Params.a_c_sub[2][0] = exp(ltf_params[19]); 
		Params.a_c_sub[2][1] = exp(ltf_params[20]);
		Params.a_c_sub[2][2] = exp(ltf_params[21]);
		Params.a_c_sub[2][3] = exp(ltf_params[22]);
		//meta 3
		Params.a_c_sub[3][0] = exp(ltf_params[23]); 
		Params.a_c_sub[3][1] = exp(ltf_params[24]);
		Params.a_c_sub[3][2] = exp(ltf_params[25]);
		Params.a_c_sub[3][3] = exp(ltf_params[26]);
		//m_c - pop //1
		Params.m_c_pop		= exp(ltf_params[27]); 
		//m_c - meta //3
		Params.m_c_meta[1]	= exp(ltf_params[28]);
		Params.m_c_meta[2]	= exp(ltf_params[29]);
		Params.m_c_meta[3]	= exp(ltf_params[30]);
		//m_c - sub //12
		//meta1
		Params.m_c_sub[1][0] = exp(ltf_params[31]);
		Params.m_c_sub[1][1] = exp(ltf_params[32]);
		Params.m_c_sub[1][2] = exp(ltf_params[33]);
		Params.m_c_sub[1][3] = exp(ltf_params[34]);
		//meta2	
		Params.m_c_sub[2][0] = exp(ltf_params[35]);
		Params.m_c_sub[2][1] = exp(ltf_params[36]);
		Params.m_c_sub[2][2] = exp(ltf_params[37]);
		Params.m_c_sub[2][3] = exp(ltf_params[38]);
		//meta3
		Params.m_c_sub[3][0] = exp(ltf_params[39]);
		Params.m_c_sub[3][1] = exp(ltf_params[40]);
		Params.m_c_sub[3][2] = exp(ltf_params[41]);
		Params.m_c_sub[3][3] = exp(ltf_params[42]);

		//LARVAL DISPERSAL
		//a_l - pop //1
		Params.a_l_pop = exp(ltf_params[43]);
		//a_l - meta //3
		Params.a_l_meta[1] = exp(ltf_params[44]);
		Params.a_l_meta[2] = exp(ltf_params[45]);
		Params.a_l_meta[3] = exp(ltf_params[46]);
		//a_l - sub //12
		//meta 1
		Params.a_l_sub[1][0] = exp(ltf_params[47]); 
		Params.a_l_sub[1][1] = exp(ltf_params[48]);
		Params.a_l_sub[1][2] = exp(ltf_params[49]);
		Params.a_l_sub[1][3] = exp(ltf_params[50]);
		//meta 2
		Params.a_l_sub[2][0] = exp(ltf_params[51]); 
		Params.a_l_sub[2][1] = exp(ltf_params[52]);
		Params.a_l_sub[2][2] = exp(ltf_params[53]);
		Params.a_l_sub[2][3] = exp(ltf_params[54]);
		//meta 3
		Params.a_l_sub[3][0] = exp(ltf_params[55]); 
		Params.a_l_sub[3][1] = exp(ltf_params[56]);
		Params.a_l_sub[3][2] = exp(ltf_params[57]);
		Params.a_l_sub[3][3] = exp(ltf_params[58]);
		//m_l - pop //1
		Params.m_l_pop		= exp(ltf_params[59]); 
		//m_l - meta //3
		Params.m_l_meta[1]	= exp(ltf_params[60]);
		Params.m_l_meta[2]	= exp(ltf_params[61]);
		Params.m_l_meta[3]	= exp(ltf_params[62]);
		//m_l - sub //12
		//meta1
		Params.m_l_sub[1][0] = exp(ltf_params[63]);
		Params.m_l_sub[1][1] = exp(ltf_params[64]);
		Params.m_l_sub[1][2] = exp(ltf_params[65]);
		Params.m_l_sub[1][3] = exp(ltf_params[66]);
		//meta2	
		Params.m_l_sub[2][0] = exp(ltf_params[67]);
		Params.m_l_sub[2][1] = exp(ltf_params[68]);
		Params.m_l_sub[2][2] = exp(ltf_params[69]);
		Params.m_l_sub[2][3] = exp(ltf_params[70]);
		//meta3
		Params.m_l_sub[3][0] = exp(ltf_params[71]);
		Params.m_l_sub[3][1] = exp(ltf_params[72]);
		Params.m_l_sub[3][2] = exp(ltf_params[73]);
		Params.m_l_sub[3][3] = exp(ltf_params[74]);

		//OBS INIT CONDITIONS //8
		//meta4
		Params.FITINIT[4][0] = exp(ltf_params[75]); //initS
		Params.FITINIT[4][4] = exp(ltf_params[76]); //initV
		Params.FITINIT[4][8] = exp(ltf_params[77]); //initR
		//meta5
		Params.FITINIT[5][0] = exp(ltf_params[78]); //initS
		Params.FITINIT[5][4] = exp(ltf_params[79]); //initV
		//meta6
		Params.FITINIT[6][0] = exp(ltf_params[80]); //initS
		Params.FITINIT[6][4] = exp(ltf_params[81]); //initV
		Params.FITINIT[6][8] = exp(ltf_params[82]); //initR

			//-------------------MISER CALCULATE LIKELIHOOD------------------------------//
		double lhood_meta=0; double log_lhood_meta=0; double total_loghood_metas = 0;
		double new_posterior=0;
		double meta_err=0;
		double lhood_total=0;
		double lhood_reps=0;

		calls=50;					//number of stochastic simulations for each parameter and IC set //100-300

		//for(j=1; j<=DATA_SETS; j++){
		for(j=1; j<4; j++){
			Params.j = j;
			//printf("big loop j=%i\n", j);

			Params.miser_ticker = 1; //used to set initial adjustment

			Params.miser2_flag = 0; //used to run MISER on parameter set a second time with better adjustment 

			dim = 48*2; 

			//define function
			gsl_monte_function G = { &LHood_Meta, dim, &Params };	// declares function calling lhood_meta.h
			double xl[dim];	double xu[dim];	// need to redeclare xl and xu since the size changes
			for (jj=0;jj<dim;jj++)	{
				xl[jj]=0;	
				xu[jj]=1;
			}

			gsl_monte_miser_state *s = gsl_monte_miser_alloc(dim);
			gsl_monte_miser_integrate (&G,xl,xu,dim,calls,r_seed,s,&lhood_meta,&meta_err); //call MISER, pop_lhood is output from .h (likelihood value)
			gsl_monte_miser_free(s);


			//re-do until best lhood score is found
			
			while(Params.miser2_flag > 0){ //indicates that a better likelihood score (or a few) were found
				//printf("FLAG TRIPPED! round two\n"); //this one for greg
				Params.miser2_flag = 0;
				//printf("FLAG TRIPPED! miser ticker = %i\n", Params.miser_ticker);
				//printf("old adj = %lf\t new adj = %lf\n", Params.lhood_adjust[j], Params.bestlhood[j]);
				//printf("bestlhood meta = %lf\t prev adj = %lf\n", Params.bestlhood[j], Params.lhood_adjust[j]); //this one for greg
				Params.lhood_adjust[j] = -Params.bestlhood[j];
				
				gsl_monte_miser_state *s = gsl_monte_miser_alloc(dim);
				gsl_monte_miser_integrate (&G,xl,xu,dim,calls,r_seed,s,&lhood_meta,&meta_err); //call MISER, pop_lhood is output from .h (likelihood value)
				gsl_monte_miser_free(s);
				//printf("a = %i\t repeat!\n", a);
			}

			log_lhood_meta = log(lhood_meta) - Params.lhood_adjust[j];
			//printf("log_lhood in main = %lf\n", log_lhood_meta);
			if(isnan(log_lhood_meta) || isinf(log_lhood_meta)){ //that means it was a really bad value
			//printf("nan or inf adjustment didn't work\n");
				log_lhood_meta = -9999; //shouldn't this be a really bad score? //a zero? //log(0) is undefined so I need to declare badness after it's logged via this catch
			}
			
			total_loghood_metas = total_loghood_metas + log_lhood_meta;

			new_posterior = total_loghood_metas + log_prior;
			//printf("dataset = %i\t new posterior = %lf\n", j, new_posterior);
			//printf("posterior = %lf\t total_loghood_metas = %lf\t log_prior=%lf\n", new_posterior, total_loghood_metas, log_prior);
		}
		if (new_posterior>best_posterior){ //compare likelihood //sum - one you just generated //local max - best you've seen
			best_posterior=new_posterior;
			//printf("best posterior = %lf\n", best_posterior);
			for (c=0;c<num_ltfparams;c++){
				localmax_params[c]=ltf_params[c]; //save best param set from each individual search
			}
		}

	}  //best param set from within searches
	for (c=0;c<num_ltfparams;c++){
		ltf_params[c]=localmax_params[c];
	}
	i++;
	} //while loop

	int index;
	for(ii=0; ii<fit_length; ii++){
		index = fit_list[ii];
		fprintf(fpls, "%lf\t", exp(ltf_params[index]));
	}
	//prints all
	/*
	for(ii=0; ii<num_ltfparams; ii++){
		fprintf(fpls, "%lf\t", ltf_params[ii]);
	}*/

	fprintf(fpls, "%lf\t", best_posterior);
	//printf("final best posterior = %lf\n", best_posterior);
	fprintf(fpls, "\n");
}

//fclose(fpl);
fclose(fpls); //parameter values
}

///////////////////////////////////////////////////MCMC///////////////////////////////////////////////////

/*
if(mcmc==1){ //not updated for new larval/fungal dispersal parms //or fungus transmission //or heterogeneity

	int pid;
	pid=getpid();

	char namem[50];
	sprintf(namem, "mcmc_results_%d", pid);
	fpm=fopen(namem, "a+");

	int NumberOfParams=56;		

	int Realizations=100;         //JL: Number of realizations in the MCMC step

	double RandomNumber;

	double LogJumpToNew;
	double LogJumpToOld;
	double ProbOfAcceptance;

	double LogOldPosterior;
	double LogNewPosterior;
	double LogNewPrior;

	int run;
	int changer;
	
	double pop_lhood, pop_lhood2, pop_err,post_hood;	// population lhood (and posterior lhood) calculated for each initS and initR
	double pop_best_lhood;					// likelihood and error for best initS and initR
	double best_post_hood;	double best_lhood=0;		// best post_hood and lhood
	double prior[num_adj_pars];


	const gsl_rng_type * T;

	gsl_rng * r;
	gsl_rng_env_setup();
	T = gsl_rng_default;
	r = gsl_rng_alloc (T);
	gsl_rng_set(r, time(NULL)*(int)getpid());     //JL: Include the process id to avoid taking the same random number at the beginning stage (multiple jobs submitted together at the same time).
	srand(time(NULL));

	double delta=0;

	//Some variables for recording the PCA results//
	double SDpca[NumberOfParams];
	double Coefficients[NumberOfParams*NumberOfParams];
	double Center[NumberOfParams];
	double Scale[NumberOfParams];
	double PC[NumberOfParams];
	double Old_PC[NumberOfParams];
	double Holder[NumberOfParams];
	double PCAparams[NumberOfParams];
	double Old_Params[NumberOfParams];

	//double AcceptedVect[NumberOfParams]={0.0};
	//double LoopVect[NumberOfParams]={0.0};

	int a;
	int b;
	int ticker;
	int ticker2;

	int Case;

	int Accepted=0;
	signed int LoopNumber=-1;

	int ParCnt2 = NumberOfParams;

	double SigmaInflation=1.20;  //CK// Dave had 4 as his sigma inflation factor - FORMERLY WAS 0.5, WHICH IS A BAD THING

	double sigma[NumberOfParams];

	run=1;	changer=1;	best_post_hood=-10000000000;


//---------------------------------Read in PCA-----------------------------------//

	FILE *file;

	file=fopen("PCAsd_test.txt", "r");          //Reading in the standard deviations of PCA.
	for (a=0; a<(NumberOfParams); a++)
	{
		fscanf(file, "%lf\n", &SDpca[a]);
		//printf("%lf\n", SDpca[a]);
	}
	fclose(file);


	file=fopen("PCArotations_test.txt", "r");   //Reading in the rotations (coefficients between PC's and parameters)
	for (a=0; a<(NumberOfParams*NumberOfParams); a++)
	{
		fscanf(file, "%lf\n", &Coefficients[a]);
		//printf("%lf\n", Coefficients[a]);
	}
	fclose(file);

	file=fopen("PCAscale_test.txt", "r");        //Reading in the scales to reconstruct parameter values from PC's.
	for (a=0; a<NumberOfParams; a++)
	{
		fscanf(file, "%lf\n", &Scale[a]);
		//printf("%lf\n", Scale[a]);
	}
	fclose(file);

	file=fopen("PCAcenter_test.txt", "r");       //Reading in the centers of parameters. Used in the reconstruction of parameters.

	for (a=0; a<NumberOfParams; a++)
	{
		fscanf(file, "%lf\n", &Center[a]);
		//printf("%lf\n", Center[a]);
	}
	fclose(file);

	//getc(stdin);

//-------------------------generate PCs---------------------//
//start out by inflating variance to make overdispersed, then see if var goes down with time.
		//as variance goes down, that's evidence that chains are converging
	for(a=0; a<NumberOfParams; a++){
		sigma[a]=SigmaInflation*SDpca[a];
		//printf("%lf\n", sigma[a]);
	}


	for (a=0; a<NumberOfParams; a++){
		PC[a]=gsl_ran_gaussian (r, sigma[a]);    //CK//  PC contains current set of PC values
		//printf("%lf\n", PC[a]);
	}
	//getc(stdin);

//------------------------begin loop---------------------------------//
while (LoopNumber<=Realizations) {     
		//printf("loop number = %i\n", LoopNumber);
		LoopNumber=LoopNumber+1;

		Case=LoopNumber%NumberOfParams;					//Determines which PC to change
		//printf("CASE = %i\n");

		for (a=0; a<NumberOfParams; a++)
		{
			Old_PC[a]=PC[a];							//Store old PC values
		}

		//--------------------------draw new PC------------------------------//
		PC[Case]=gsl_ran_gaussian (r, sigma[Case]);

		//---------------------------------reconstruct PCA---------------------//
		for (a=0;a<NumberOfParams; a++)								//Back transform PC's into model parameters
		{
			for (b=0; b<NumberOfParams; b++){
				Holder[b]=Coefficients[a*NumberOfParams+b];         //Store the coefficients between a certain parameter and all the PC's
			}

			//reconstruct PCA into parameter values
			PCAparams[a]=exp(DotProduct(ParCnt2, Holder, PC)*Scale[a]+Center[a]);            //Reconstruct the parameter value after tweaking one PC
			Old_Params[a]=exp(DotProduct(ParCnt2, Holder, Old_PC)*Scale[a]+Center[a]);       //Reconstruct the parameter value before tweaking that PC

		    //printf("%f\n", PC[a]);
		    //printf("PCAparams: %e\n", PCAparams[a]);  
			//getc(stdin);

		}

		LogJumpToNew= -log(gsl_ran_gaussian_pdf(PC[Case], sigma[Case]));		//Metropolis sampling step: LATER YOU WILL USE THIS TO CORRECT FOR PROPOSAL
		LogJumpToOld= -log(gsl_ran_gaussian_pdf(Old_PC[Case], sigma[Case]));

		//------------------assign new parameter values----------------------//
			Params.FITINIT[1][0] = PCAparams[0]; //initS
			Params.FITINIT[1][1] = PCAparams[1]; //initS
			Params.FITINIT[1][2] = PCAparams[2]; //initS
			Params.FITINIT[1][3] = PCAparams[3]; //initS
			Params.FITINIT[1][4] = PCAparams[4]; 				//initV //fonly
			Params.FITINIT[1][5] = PCAparams[5]; //initV
			Params.FITINIT[1][6] = PCAparams[6]; //initV
			Params.FITINIT[1][7] = PCAparams[7]; 				//initV //control
			Params.FITINIT[1][8] = PCAparams[8]; //initR
			Params.FITINIT[1][9] = PCAparams[9]; //initR
			Params.FITINIT[1][10] = PCAparams[10]; //initR
			Params.FITINIT[1][11] = PCAparams[11]; //initR

			//metapopulation two
			Params.FITINIT[2][0] = PCAparams[12]; //initS
			Params.FITINIT[2][1] = PCAparams[13]; //initS
			Params.FITINIT[2][2] = PCAparams[14]; //initS
			Params.FITINIT[2][3] = PCAparams[15]; //initS
			Params.FITINIT[2][4] = PCAparams[16]; 				//initV //fonly
			Params.FITINIT[2][5] = PCAparams[17]; //initV
			Params.FITINIT[2][6] = PCAparams[18]; //initV
			Params.FITINIT[2][7] = PCAparams[19]; 				//initV //control
			Params.FITINIT[2][8] = PCAparams[20]; //initR
			Params.FITINIT[2][9] = PCAparams[21]; //initR
			Params.FITINIT[2][10] = PCAparams[22]; //initR
			Params.FITINIT[2][11] = PCAparams[23]; //initR

			//metapopulation three
			Params.FITINIT[3][0] = PCAparams[24]; //initS
			Params.FITINIT[3][1] = PCAparams[25]; //initS
			Params.FITINIT[3][2] = PCAparams[26]; //initS
			Params.FITINIT[3][3] = PCAparams[27]; //initS
			Params.FITINIT[3][4] = PCAparams[28]; 				//initV //f only
			Params.FITINIT[3][5] = PCAparams[29]; //initV
			Params.FITINIT[3][6] = PCAparams[30]; //initV
			Params.FITINIT[3][7] = PCAparams[31];				 //initV //control
			Params.FITINIT[3][8] = PCAparams[32]; //initR
			Params.FITINIT[3][9] = PCAparams[33]; //initR
			Params.FITINIT[3][10] = PCAparams[34]; //initR
			Params.FITINIT[3][11] = PCAparams[35]; //initR

			//metapopultion four
			Params.FITINIT[4][0] = PCAparams[36]; //initS
			Params.FITINIT[4][4] = PCAparams[37]; //initV
			Params.FITINIT[4][8] = PCAparams[38]; //initR

			//metapopultion five
			Params.FITINIT[5][0] = PCAparams[39]; //initS
			Params.FITINIT[5][4] = PCAparams[40]; //initV
			Params.FITINIT[5][8] = PCAparams[41]; //initR

			//metapopultion six
			Params.FITINIT[6][0] = PCAparams[42]; //initS
			Params.FITINIT[6][4] = PCAparams[43]; //initV
			Params.FITINIT[6][8] = PCAparams[44]; //initR

			//dispersal parameters
			//NEED TO UPDATE
			Params.con_mgr[1][1] 		= PCAparams[45];
			Params.a[1][1] 			= PCAparams[46];
			Params.lar_mgr[1][1] 		= PCAparams[47];
			Params.a2[1][1]			= PCAparams[48];
			//coinfection parameters
			Params.coinf_V		= PCAparams[49];
			Params.VFSus		= PCAparams[50];
			//stochasticity parameters
			Params.Rsd_exp 		= PCAparams[51];
			Params.Fsd_exp		= PCAparams[52];
			Params.Rsd_obs		= PCAparams[53];
			Params.Fsd_obs		= PCAparams[54];

			Params.muV			= ltf_params[55];
		
		//-------------------MISER likelihood new------------------------------//
		double lhood_meta=0; double log_lhood_meta=0; double total_loghood_metas = 0;
		double new_posterior=0;
		double meta_err=0;
		double lhood_total=0;
		double lhood_reps=0;

		calls=10;					//number of stochastic simulations for each parameter and IC set //100-300

		for(j=1; j<=DATA_SETS; j++){
		//for(j=1; j<2; j++){
			Params.j = j;

			dim = 48*2; 

			//define function
			gsl_monte_function G = { &LHood_Meta, dim, &Params };	// declares function calling lhood_meta.h
			double xl[dim];	double xu[dim];	// need to redeclare xl and xu since the size changes
			for (jj=0;jj<dim;jj++)	{
				xl[jj]=0;	
				xu[jj]=1;
			}

			gsl_monte_miser_state *s = gsl_monte_miser_alloc(dim);
			gsl_monte_miser_integrate (&G,xl,xu,dim,calls,r_seed,s,&lhood_meta,&meta_err); //call MISER, pop_lhood is output from .h (likelihood value)
			gsl_monte_miser_free(s);

			//fprintf(fpl, "For dataset %i, lhood = %lf\t, err = %lf\n", j, lhood_meta, meta_err);
			//fprintf(fpl, "For dataset %i, lhood = %lf\n", j, lhood_meta);
			//printf("lhood post MISER = %lf\n", lhood_meta);
			
			log_lhood_meta = log(lhood_meta) - Params.lhood_adjust[j];
			if(isnan(log_lhood_meta) || isinf(log_lhood_meta)){ //change to zero of inf or nan, only update lhood adj if not
				log_lhood_meta = 0;
			}
			else{
				Params.lhood_adjust[j] = -1*log_lhood_meta; //update lhood adj based on average so it is dynamic
				//printf("ELSE adj = %lf\n", Params.lhood_adjust[j]);
			}
			total_loghood_metas = total_loghood_metas + log_lhood_meta;
			//printf("total = %lf\n", total_loghood_metas);
			LogNewPosterior = 0.0;
			LogNewPosterior = total_loghood_metas + log_prior;
			//printf("new posterior = %lf\n", LogNewPosterior);
		}//j 

		//-------------------assign old parameter values-----------------------//
			Params.FITINIT[1][0] = Old_Params[0]; //initS
			Params.FITINIT[1][1] = Old_Params[1]; //initS
			Params.FITINIT[1][2] = Old_Params[2]; //initS
			Params.FITINIT[1][3] = Old_Params[3]; //initS
			Params.FITINIT[1][4] = Old_Params[4]; 				//initV //fonly
			Params.FITINIT[1][5] = Old_Params[5]; //initV
			Params.FITINIT[1][6] = Old_Params[6]; //initV
			Params.FITINIT[1][7] = Old_Params[7]; 				//initV //control
			Params.FITINIT[1][8] = Old_Params[8]; //initR
			Params.FITINIT[1][9] = Old_Params[9]; //initR
			Params.FITINIT[1][10] = Old_Params[10]; //initR
			Params.FITINIT[1][11] = Old_Params[11]; //initR

			//metapopulation two
			Params.FITINIT[2][0] = Old_Params[12]; //initS
			Params.FITINIT[2][1] = Old_Params[13]; //initS
			Params.FITINIT[2][2] = Old_Params[14]; //initS
			Params.FITINIT[2][3] = Old_Params[15]; //initS
			Params.FITINIT[2][4] = Old_Params[16]; 				//initV //fonly
			Params.FITINIT[2][5] = Old_Params[17]; //initV
			Params.FITINIT[2][6] = Old_Params[18]; //initV
			Params.FITINIT[2][7] = Old_Params[19]; 				//initV //control
			Params.FITINIT[2][8] = Old_Params[20]; //initR
			Params.FITINIT[2][9] = Old_Params[21]; //initR
			Params.FITINIT[2][10] = Old_Params[22]; //initR
			Params.FITINIT[2][11] = Old_Params[23]; //initR

			//metapopulation three
			Params.FITINIT[3][0] = Old_Params[24]; //initS
			Params.FITINIT[3][1] = Old_Params[25]; //initS
			Params.FITINIT[3][2] = Old_Params[26]; //initS
			Params.FITINIT[3][3] = Old_Params[27]; //initS
			Params.FITINIT[3][4] = Old_Params[28]; 				//initV //f only
			Params.FITINIT[3][5] = Old_Params[29]; //initV
			Params.FITINIT[3][6] = Old_Params[30]; //initV
			Params.FITINIT[3][7] = Old_Params[31];				 //initV //control
			Params.FITINIT[3][8] = Old_Params[32]; //initR
			Params.FITINIT[3][9] = Old_Params[33]; //initR
			Params.FITINIT[3][10] = Old_Params[34]; //initR
			Params.FITINIT[3][11] = Old_Params[35]; //initR

			//metapopultion four
			Params.FITINIT[4][0] = Old_Params[36]; //initS
			Params.FITINIT[4][4] = Old_Params[37]; //initV
			Params.FITINIT[4][8] = Old_Params[38]; //initR

			//metapopultion five
			Params.FITINIT[5][0] = Old_Params[39]; //initS
			Params.FITINIT[5][4] = Old_Params[40]; //initV
			Params.FITINIT[5][8] = Old_Params[41]; //initR

			//metapopultion six
			Params.FITINIT[6][0] = Old_Params[42]; //initS
			Params.FITINIT[6][4] = Old_Params[43]; //initV
			Params.FITINIT[6][8] = Old_Params[44]; //initR

			//dispersal parameters
			Params.con_mgr[1][1] 	= Old_Params[45];
			Params.a[1][1] 			= Old_Params[46];
			Params.lar_mgr[1][1]	= Old_Params[47];
			Params.a2[1][1]			= Old_Params[48];
			//coinfection parameters
			Params.coinf_V		= Old_Params[49];
			Params.VFSus		= Old_Params[50];
			//stochasticity parameters
			Params.Rsd_exp 		= Old_Params[51];
			Params.Fsd_exp		= Old_Params[52];
			Params.Rsd_obs		= Old_Params[53];
			Params.Fsd_obs		= Old_Params[54];

			Params.muV			= ltf_params[55];

		//-------------------MISER likelihood old------------------------------//
		lhood_meta=0; log_lhood_meta=0; total_loghood_metas = 0;
		new_posterior=0;
		meta_err=0;
		lhood_total=0;
		lhood_reps=0;

		calls=10;					//number of stochastic simulations for each parameter and IC set //100-300

		for(j=1; j<=DATA_SETS; j++){
		//for(j=1; j<2; j++){
			Params.j = j;

			dim = 48*2; 
			//printf("in the old loop\n");
			//define function
			gsl_monte_function G = { &LHood_Meta, dim, &Params };	// declares function calling lhood_meta.h
			double xl[dim];	double xu[dim];	// need to redeclare xl and xu since the size changes
			for (jj=0;jj<dim;jj++)	{
				xl[jj]=0;	
				xu[jj]=1;
			}

			gsl_monte_miser_state *s = gsl_monte_miser_alloc(dim);
			gsl_monte_miser_integrate (&G,xl,xu,dim,calls,r_seed,s,&lhood_meta,&meta_err); //call MISER, pop_lhood is output from .h (likelihood value)
			gsl_monte_miser_free(s);

			//fprintf(fpl, "For dataset %i, lhood = %lf\t, err = %lf\n", j, lhood_meta, meta_err);
			//fprintf(fpl, "For dataset %i, lhood = %lf\n", j, lhood_meta);
			//printf("out of the old\n");l
			
			log_lhood_meta = log(lhood_meta) - Params.lhood_adjust[j];
			if(isnan(log_lhood_meta) || isinf(log_lhood_meta)){ //change to zero of inf or nan, only update lhood adj if not
				log_lhood_meta = 0;
			}
			else{
				Params.lhood_adjust[j] = -1*log_lhood_meta; //update lhood adj based on average so it is dynamic
				//printf("ELSE adj = %lf\n", Params.lhood_adjust[j]);
			}
			//printf("MADE IT OUT: log_lhood_meta = %lf\n", log_lhood_meta);
			total_loghood_metas = total_loghood_metas + log_lhood_meta;
			//printf("total = %lf\n", total_loghood_metas);
			LogOldPosterior=0.0;
			LogOldPosterior = total_loghood_metas + log_prior;
			//printf("old posterior = %lf\n", LogOldPosterior);
		}//j 


		//----------compare new parm set with old parm set----------------
		
		ProbOfAcceptance=exp(LogNewPosterior+LogJumpToOld - LogOldPosterior-LogJumpToNew);    //Probability of accepting the new PC

		Params.LoopVect[Case] = Params.LoopVect[Case] + 1;

		if (ProbOfAcceptance>1 || gsl_rng_uniform_pos (r) < ProbOfAcceptance)   //MH-MCMC algorithm
		{
			LogOldPosterior=LogNewPosterior;  //Accept the new parameter values.
			//Accepted=Accepted+1;
			printf("Accepted\n");
			Params.AcceptedVect[Case] = Params.AcceptedVect[Case] + 1;
		}

		else
		{
			for (a=0; a<NumberOfParams; a++)
			{
				PC[a]=Old_PC[a];            //Keep the old parameter values.
			}

			printf("Rejected\n");

		}

		// ------------------------------------------ output results to file  --------------------------------------- //
		if (LoopNumber % 10 == 0)   	//CK// output results every 10 loops (probably not best plan but we'll see)
		{
			printf("printing! loop number = %i\n", LoopNumber);
			for(ii=0; ii<NumberOfParams; ii++){
				fprintf(fpm, "%lf\t", PCAparams[ii]);
			}
			fprintf(fpm, "\n");
			//fflush(stdout);
		}
	}
	fclose(fpm);
}*/

return 0;
}
