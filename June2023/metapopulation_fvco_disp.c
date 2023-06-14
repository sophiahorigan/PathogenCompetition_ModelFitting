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
//ROUTINES
//algorithm
linesearch = 0;
reals = 1;
mcmc = 0;
//lhood details
int searches = 10;
int round;
int numround = 5;

//dispersal
//LARVAL DISPERSAL
larval_dispersal = 1;
//a
l_a_pop_fit = 0; 
l_a_meta_fit = 0;
l_a_sub_fit = 1; 
//m
l_m_pop_fit = 0; 
l_m_meta_fit = 0;
l_m_sub_fit = 1; 

//CONIDIA DISPERSAL
conidia_dispersal = 1;
//a
c_a_pop_fit = 0;
c_a_meta_fit = 0;
c_a_sub_fit = 1;
//m
c_m_pop_fit = 0;
c_m_meta_fit = 0;
c_m_sub_fit = 1;

//FIT PARAMS
//******OBS PRIORS*****
//virus(3), fungus(1), stoch(2), obs init conditions(8))
//int fit_length = 14;
//int fit_list[14] = {4, 5, 6, 7, 9, 10, 75, 76, 77, 78, 79, 80, 81, 82};

//******L POP FIT*******
 //init R (1,2,3), muv(4), CV(5), nuV(6), nuF(7), Rstoch(9), Fstoch(10), l_a_pop(1), l_m_pop(1)
//int fit_length = 11;
//int fit_list[11] = {1, 2, 3, 4, 5, 6, 7, 9, 10, 43, 59};

//******L META FIT*****
//exp init R (1,2,3), muv(4), CV(5), nuV(6), nuF(7), Rstoch(9), Fstoch(10), l_a_pop(44-46), l_m_pop(60-62)
//int fit_length = 15;
//int fit_list[15] = {1, 2, 3, 4, 5, 6, 7, 9, 10, 44, 45, 46, 60, 61, 62};

//*****L SUB FIT*****
//exp init R (1,2,3), muv(4), CV(5), nuV(6), nuF(7), Rstoch(9), Fstoch(10) l_a_sub(47-58), l_m_sub(63-74)
//int fit_length = 33;
//int fit_list[33] = {1, 2, 3, 4, 5, 6, 7, 9, 10, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73 ,74};

//****L SUB FIT, C POP FIT*****
//exp init R (1,2,3), muv(4), CV(5), nuV(6), nuF(7), Rstoch(9), Fstoch(10), c_a_pop(11), c_m_pop(27) l_a_sub(47-58), l_m_sub(63-74)
//int fit_length = 35;
//int fit_list[35] = {1, 2, 3, 4, 5, 6, 7, 9, 10, 11, 27, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73 ,74};

//****L SUB FIT, C META FIT*****
//exp init R (1,2,3), muv(4), CV(5), nuV(6), nuF(7), Rstoch(9), Fstoch(10), c_a_meta(12-14), c_m_pop(28-30) l_a_sub(47-58), l_m_sub(63-74)
//int fit_length = 39;
//int fit_list[39] = {1, 2, 3, 4, 5, 6, 7, 9, 10, 12, 13, 14, 28, 29, 30, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73 ,74};

//****L SUB FIT, C SUB FIT*****
//exp init R (1,2,3), muv(4), CV(5), nuV(6), nuF(7), Rstoch(9), Fstoch(10), c_a_sub(15-26), c_m_sub(31-42) l_a_sub(47-58), l_m_sub(63-74)
int fit_length = 57;
int fit_list[57] = {1, 2, 3, 4, 5, 6, 7, 9, 10, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73 ,74};


STRUCTURE Params;
// ----------------------------------------Set Up-------------------------------------------------------------------- //
int i=0; int j;int ii; int jj; int k; int l; 
int epi_length = 48; //CHANGE 48
inputdata(&Params);				
// ---------------------------------------- Random Number Stuff ------------------------------------------------------ //
gsl_rng *r_seed;
r_seed=random_setup();

//----------------------------------Set-Up Line Search------------------------//
int calls;
size_t dim;

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
		Params.FITINIT[1][0] = 100; //initS //FX
		Params.FITINIT[1][1] = 100; //initS //FX
		Params.FITINIT[1][2] = 100; //initS //FX
		Params.FITINIT[1][3] = 100; //initS //FX

		Params.FITINIT[1][4] = 0; //initV //fonly //FX
		Params.FITINIT[1][5] = 0.2; //initV  //FX
		Params.FITINIT[1][6] = 0.2; //initV //FX
		Params.FITINIT[1][7] = 0; //initV //control //FX

		Params.FITINIT[1][9] = 0; //initR //vonly  //FX
		Params.FITINIT[1][10] = 0; //initR //fv //FX
		Params.FITINIT[1][11] = 0; //initR //control //FX

		//meta2
		Params.FITINIT[2][0] = 100; //initS  //FX
		Params.FITINIT[2][1] = 100; //initS //FX
		Params.FITINIT[2][2] = 100; //initS //FX
		Params.FITINIT[2][3] = 100; //initS //FX
		Params.FITINIT[2][4] = 0; //initV //fonly //FX
		Params.FITINIT[2][5] = 0.2; //initV  //FX
		Params.FITINIT[2][6] = 0.2; //initV //FX
		Params.FITINIT[2][7] = 0; //initV //control //FX
		//meta3
		Params.FITINIT[3][0] = 100; //initS //FX
		Params.FITINIT[3][1] = 100; //initS //FX
		Params.FITINIT[3][2] = 100; //initS //FX
		Params.FITINIT[3][3] = 100; //initS //FX
		Params.FITINIT[3][4] = 0; //initV //f only //FX
		Params.FITINIT[3][5] = 0.2; //initV //FX
		Params.FITINIT[3][6] = 0.2; //initV //FX
		Params.FITINIT[3][7] = 0; //initV //control //FX
		//meta5
		Params.FITINIT[5][8] = 0; //initR

		//************FIT PARAMS*******************
		//META SPECIFIC INIT R //3
		//meta1
		Params.FITINIT[1][8] = 0.000041; //initR //fonly  //FT* //0.000726
		//meta2
		Params.FITINIT[2][8] = 	0.000262; //initR //fonly //FX //0.001749
		Params.FITINIT[2][9] = 0.000262; //initR //vonly //FX
		Params.FITINIT[2][10] = 0.000262; //initR //fv //FX
		Params.FITINIT[2][11] = 0.000262;//initR //control //FX
		//meta3
		Params.FITINIT[3][8] = 0.000956; //initR //fonly //0.00226
		Params.FITINIT[3][9] = 0.000956; //initR //vonly
		Params.FITINIT[3][10] = 0.000956; //initR //fv
		Params.FITINIT[3][11] = 0.000956; //initR //control

		//VIRUS //3
		Params.muV			= 0.000172; //Fuller 2012 //virus decay //0.39
		Params.CV			= 0.503251; //hetereogeneity to virus infection //previously 0.86
		Params.nuV    		= 0.046016; //virus transmission //0.46

		//FUNGUS //1
		Params.specific_nuF	= 0.001909; //fungus transmissison

		//STOCHASTICITY //2
		Params.R_stoch 		= 1.182461;
		Params.F_stoch		= 0.166756;

		//CONIDIA DISPERSAL
		//c_a - pop //1
		Params.c_a_pop = 0.010052;
		//c_a - meta //3
		Params.c_a_meta[1] = 0.067599;
		Params.c_a_meta[2] = 0.055827;
		Params.c_a_meta[3] = 0.081391;
		//c_a - sub //12
		//meta 1
		Params.c_a_sub[1][0] = 0.022222; 
		Params.c_a_sub[1][1] = 0.021276;
		Params.c_a_sub[1][2] = 0.203540;
		Params.c_a_sub[1][3] = 0.107618;
		//meta 2
		Params.c_a_sub[2][0] = 0.174201; 
		Params.c_a_sub[2][1] = 0.084102;
		Params.c_a_sub[2][2] = 0.239030;
		Params.c_a_sub[2][3] = 0.304113;
		//meta 3
		Params.c_a_sub[3][0] = 0.017715; 
		Params.c_a_sub[3][1] = 0.149685;
		Params.c_a_sub[3][2] = 0.040142;
		Params.c_a_sub[3][3] = 0.149622;
		//c_m - pop //1
		Params.c_m_pop		= 0.748822; 
		//c_m - meta //3
		Params.c_m_meta[1]	= 0.584010;
		Params.c_m_meta[2]	= 0.441620;
		Params.c_m_meta[3]	= 0.511878;
		//c_m - sub //12
		//meta1
		Params.c_m_sub[1][0] = 0.118430;
		Params.c_m_sub[1][1] = 0.013755;
		Params.c_m_sub[1][2] = 0.249894;
		Params.c_m_sub[1][3] = 0.263176;
		//meta2	
		Params.c_m_sub[2][0] = 0.193099;
		Params.c_m_sub[2][1] = 0.713678;
		Params.c_m_sub[2][2] = 0.079351;
		Params.c_m_sub[2][3] = 0.371225;
		//meta3
		Params.c_m_sub[3][0] = 0.321930;
		Params.c_m_sub[3][1] = 0.139502;
		Params.c_m_sub[3][2] = 0.638262;
		Params.c_m_sub[3][3] = 0.995418;

		//LARVAL DISPERSAL
		//l_a - pop //1
		Params.l_a_pop = 0.171910;
		//l_a - meta //3
		Params.l_a_meta[1] = 0.212464;
		Params.l_a_meta[2] = 0.038558;
		Params.l_a_meta[3] = 0.027468;
		//l_a - sub //12
		//meta 1
		Params.l_a_sub[1][0] = 0.188038; 
		Params.l_a_sub[1][1] = 0.060255;
		Params.l_a_sub[1][2] = 0.085268;
		Params.l_a_sub[1][3] = 0.275744;
		//meta 2
		Params.l_a_sub[2][0] = 0.033046; 
		Params.l_a_sub[2][1] = 0.078716;
		Params.l_a_sub[2][2] = 0.114819;
		Params.l_a_sub[2][3] = 0.301194;
		//meta 3
		Params.l_a_sub[3][0] = 0.226995; 
		Params.l_a_sub[3][1] = 0.064621;
		Params.l_a_sub[3][2] = 0.068035;
		Params.l_a_sub[3][3] = 0.108199;
		//l_m - pop //1
		Params.l_m_pop		= 0.839535; 
		//l_m - meta //3
		Params.l_m_meta[1]	= 0.430600;
		Params.l_m_meta[2]	= 0.363371;
		Params.l_m_meta[3]	= 0.109152;
		//l_m - sub //12
		//meta1
		Params.l_m_sub[1][0] = 0.286003;
		Params.l_m_sub[1][1] = 0.237779;
		Params.l_m_sub[1][2] = 0.773442;
		Params.l_m_sub[1][3] = 0.407169;
		//meta2	
		Params.l_m_sub[2][0] = 0.045130;
		Params.l_m_sub[2][1] = 0.460734;
		Params.l_m_sub[2][2] = 0.348192;
		Params.l_m_sub[2][3] = 0.030742;
		//meta3
		Params.l_m_sub[3][0] = 0.333772;
		Params.l_m_sub[3][1] = 0.317186;
		Params.l_m_sub[3][2] = 0.913329;
		Params.l_m_sub[3][3] = 0.491009;

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

	calls=30;

	//for(j=1; j<=DATA_SETS; j++){
		for(j=1; j<4; j++){
			Params.j = j;

			//printf("in j\n");

			Params.miser_ticker = 1; //used to set initial adjustment

			Params.miser2_flag = 0; //used to run MISER on parameter set a second time with better adjustment 

			dim = 48*2; //CHANGE 48*2

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
		Params.FITINIT[1][4] = 0; //initV //fonly //FX
		Params.FITINIT[1][5] = 0.2; //initV  //FX
		Params.FITINIT[1][6] = 0.2; //initV //FX
		Params.FITINIT[1][7] = 0; //initV //control //FX
		Params.FITINIT[1][9] = 0; //initR //vonly  //FX
		Params.FITINIT[1][10] = 0; //initR //fv //FX
		Params.FITINIT[1][11] = 0; //initR //control //FX
		//meta2
		Params.FITINIT[2][0] = 100; //initS  //FX
		Params.FITINIT[2][1] = 100; //initS //FX
		Params.FITINIT[2][2] = 100; //initS //FX
		Params.FITINIT[2][3] = 100; //initS //FX
		Params.FITINIT[2][4] = 0; //initV //fonly //FX
		Params.FITINIT[2][5] = 0.2; //initV  //FX
		Params.FITINIT[2][6] = 0.2; //initV //FX
		Params.FITINIT[2][7] = 0; //initV //control //FX
		//meta3
		Params.FITINIT[3][0] = 100; //initS //FX
		Params.FITINIT[3][1] = 100; //initS //FX
		Params.FITINIT[3][2] = 100; //initS //FX
		Params.FITINIT[3][3] = 100; //initS //FX
		Params.FITINIT[3][4] = 0; //initV //f only //FX
		Params.FITINIT[3][5] = 0.2; //initV //FX
		Params.FITINIT[3][6] = 0.2; //initV //FX
		Params.FITINIT[3][7] = 0; //initV //control //FX
		//meta5
		Params.FITINIT[5][8] = 0; //initR

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
		Params.nuV    		= exp(ltf_params[6]); //virus transmission

		//FUNGUS //1
		Params.specific_nuF	= exp(ltf_params[7]); //fungus transmission

		//STOCHASTICITY //2
		Params.R_stoch 		= exp(ltf_params[9]);
		Params.F_stoch		= exp(ltf_params[10]);

		//CONIDIA DISPERSAL
		//c_a - pop //1
		Params.c_a_pop = exp(ltf_params[11]);
		//c_a - meta //3
		Params.c_a_meta[1] = exp(ltf_params[12]);
		Params.c_a_meta[2] = exp(ltf_params[13]);
		Params.c_a_meta[3] = exp(ltf_params[14]);
		//c_a - sub //12
		//meta 1
		Params.c_a_sub[1][0] = exp(ltf_params[15]); 
		Params.c_a_sub[1][1] = exp(ltf_params[16]);
		Params.c_a_sub[1][2] = exp(ltf_params[17]);
		Params.c_a_sub[1][3] = exp(ltf_params[18]);
		//meta 2
		Params.c_a_sub[2][0] = exp(ltf_params[19]); 
		Params.c_a_sub[2][1] = exp(ltf_params[20]);
		Params.c_a_sub[2][2] = exp(ltf_params[21]);
		Params.c_a_sub[2][3] = exp(ltf_params[22]);
		//meta 3
		Params.c_a_sub[3][0] = exp(ltf_params[23]); 
		Params.c_a_sub[3][1] = exp(ltf_params[24]);
		Params.c_a_sub[3][2] = exp(ltf_params[25]);
		Params.c_a_sub[3][3] = exp(ltf_params[26]);
		//c_m - pop //1
		Params.c_m_pop		= exp(ltf_params[27]); 
		//c_m - meta //3
		Params.c_m_meta[1]	= exp(ltf_params[28]);
		Params.c_m_meta[2]	= exp(ltf_params[29]);
		Params.c_m_meta[3]	= exp(ltf_params[30]);
		//c_m - sub //12
		//meta1
		Params.c_m_sub[1][0] = exp(ltf_params[31]);
		Params.c_m_sub[1][1] = exp(ltf_params[32]);
		Params.c_m_sub[1][2] = exp(ltf_params[33]);
		Params.c_m_sub[1][3] = exp(ltf_params[34]);
		//meta2	
		Params.c_m_sub[2][0] = exp(ltf_params[35]);
		Params.c_m_sub[2][1] = exp(ltf_params[36]);
		Params.c_m_sub[2][2] = exp(ltf_params[37]);
		Params.c_m_sub[2][3] = exp(ltf_params[38]);
		//meta3
		Params.c_m_sub[3][0] = exp(ltf_params[39]);
		Params.c_m_sub[3][1] = exp(ltf_params[40]);
		Params.c_m_sub[3][2] = exp(ltf_params[41]);
		Params.c_m_sub[3][3] = exp(ltf_params[42]);

		//LARVAL DISPERSAL
		//l_a - pop //1
		Params.l_a_pop = exp(ltf_params[43]);
		//l_a - meta //3
		Params.l_a_meta[1] = exp(ltf_params[44]);
		Params.l_a_meta[2] = exp(ltf_params[45]);
		Params.l_a_meta[3] = exp(ltf_params[46]);
		//l_a - sub //12
		//meta 1
		Params.l_a_sub[1][0] = exp(ltf_params[47]); 
		Params.l_a_sub[1][1] = exp(ltf_params[48]);
		Params.l_a_sub[1][2] = exp(ltf_params[49]);
		Params.l_a_sub[1][3] = exp(ltf_params[50]);
		//meta 2
		Params.l_a_sub[2][0] = exp(ltf_params[51]); 
		Params.l_a_sub[2][1] = exp(ltf_params[52]);
		Params.l_a_sub[2][2] = exp(ltf_params[53]);
		Params.l_a_sub[2][3] = exp(ltf_params[54]);
		//meta 3
		Params.l_a_sub[3][0] = exp(ltf_params[55]); 
		Params.l_a_sub[3][1] = exp(ltf_params[56]);
		Params.l_a_sub[3][2] = exp(ltf_params[57]);
		Params.l_a_sub[3][3] = exp(ltf_params[58]);
		//l_m - pop //1
		Params.l_m_pop		= exp(ltf_params[59]); 
		//l_m - meta //3
		Params.l_m_meta[1]	= exp(ltf_params[60]);
		Params.l_m_meta[2]	= exp(ltf_params[61]);
		Params.l_m_meta[3]	= exp(ltf_params[62]);
		//l_m - sub //12
		//meta1
		Params.l_m_sub[1][0] = exp(ltf_params[63]);
		Params.l_m_sub[1][1] = exp(ltf_params[64]);
		Params.l_m_sub[1][2] = exp(ltf_params[65]);
		Params.l_m_sub[1][3] = exp(ltf_params[66]);
		//meta2	
		Params.l_m_sub[2][0] = exp(ltf_params[67]);
		Params.l_m_sub[2][1] = exp(ltf_params[68]);
		Params.l_m_sub[2][2] = exp(ltf_params[69]);
		Params.l_m_sub[2][3] = exp(ltf_params[70]);
		//meta3
		Params.l_m_sub[3][0] = exp(ltf_params[71]);
		Params.l_m_sub[3][1] = exp(ltf_params[72]);
		Params.l_m_sub[3][2] = exp(ltf_params[73]);
		Params.l_m_sub[3][3] = exp(ltf_params[74]);

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

		calls=300;					//number of stochastic simulations for each parameter and IC set //100-300

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
if(mcmc==1){

	//FITTING ROUTINE
	int fit_routine = 6;
	int NumberOfParams;

	//******OBS PRIORS***** 
	if(fit_routine==0){
		NumberOfParams = 14;
	}
	//muv(4), CV(5), nuV(6), nuF(7), fungus(1), Rstoch(9), Fstoch(10), obs init conditions(8))

	//******L POP FIT*******
	if(fit_routine==1){
		NumberOfParams = 11;
	}
	//exp init R (1,2,3), muv(4), CV(5), nuV(6), nuF(7), stoch(2), l_a_pop(1), l_m_pop(1)

	//******L META FIT*****
	if(fit_routine==2){
		NumberOfParams = 15;
	}
	//exp init R (1,2,3), muv(4), CV(5), nuV(6), nuF(7), Rstoch(9), Fstoch(10), l_a_pop(44-46), l_m_pop(60-62)

	//*****L SUB FIT*****
	if(fit_routine==3){
		NumberOfParams = 33;
	}
	//exp init R (1,2,3), muv(4), CV(5), nuV(6), nuF(7), Rstoch(9), Fstoch(10) l_a_sub(47-58), l_m_sub(63-74)

	//****L SUB FIT, C POP FIT*****
	if(fit_routine==4){
		NumberOfParams = 35;
	}
	//exp init R (1,2,3), muv(4), CV(5), nuV(6), nuF(7), Rstoch(9), Fstoch(10), c_a_pop(11), c_m_pop(27) l_a_sub(47-58), l_m_sub(63-74)

	//****L SUB FIT, C META FIT*****
	if(fit_routine==5){
		NumberOfParams = 39;
	}
	//exp init R (1,2,3), muv(4), CV(5), nuV(6), nuF(7), Rstoch(9), Fstoch(10), c_a_meta(12-14), c_m_pop(28-30) l_a_sub(47-58), l_m_sub(63-74)

	//****L SUB FIT, C SUB FIT*****
	if(fit_routine==6){
		NumberOfParams = 57;
	}
	//exp init R (1,2,3), muv(4), CV(5), nuV(6), nuF(7), Rstoch(9), Fstoch(10), c_a_sub(15-26), c_m_sub(31-42) l_a_sub(47-58), l_m_sub(63-74)

	//REALIZATIONS
	int Realizations=100;       

	//FILE OUTPUT
	int pid;
	pid=getpid();

	char namem[50];
	sprintf(namem, "mcmc_results_%d", pid);
	fpm=fopen(namem, "a+");

	//RANDOM NUMBER
	const gsl_rng_type * T;

	gsl_rng * r;
	gsl_rng_env_setup();
	T = gsl_rng_default;
	r = gsl_rng_alloc (T);
	gsl_rng_set(r, time(NULL)*(int)getpid());     //JL: Include the process id to avoid taking the same random number at the beginning stage (multiple jobs submitted together at the same time).
	srand(time(NULL));

	//SET-UP
	double delta=0;

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

	//Arrays
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

	double SigmaInflation=1.20;  //CK// Dave had 4 as his sigma inflation factor - FORMERLY WAS 0.5, WHICH IS A BAD THING //@ is this something I need to watch

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
		if(fit_routine==0){ //OBS PRIORS
			//VIRUS 3
			Params.muV			= PCAparams[0]; //virus decay
			Params.CV			= PCAparams[1];//hetereogeneity to virus infection 
			Params.nuV    		= PCAparams[2]; //virus transmission
			//FUNGUS //1
			Params.specific_nuF	= PCAparams[3]; //fungus transmissison
			//STOCHASTICITY //2
			Params.R_stoch 		= PCAparams[4];
			Params.F_stoch		= PCAparams[5];
			//OBS INIT CONDITIONS //8
			//meta4
			Params.FITINIT[4][0] = PCAparams[6]; //initS
			Params.FITINIT[4][4] = PCAparams[7]; //initV
			Params.FITINIT[4][8] = PCAparams[8]; //initR
			//meta5
			Params.FITINIT[5][0] = PCAparams[9]; //initS
			Params.FITINIT[5][4] = PCAparams[10]; //initV
			//meta6
			Params.FITINIT[6][0] = PCAparams[11];//initS
			Params.FITINIT[6][4] = PCAparams[12]; //initV
			Params.FITINIT[6][8] = PCAparams[13]; //initR

		}
		if(fit_routine==1){ //L POP FIT
			Params.FITINIT[1][8] = 	PCAparams[0]; //initR //fonly
			//meta2
			Params.FITINIT[2][8] = 	PCAparams[1]; //initR //fonly 
			Params.FITINIT[2][9] = 	PCAparams[1];//initR //vonly 
			Params.FITINIT[2][10] = PCAparams[1]; //initR //fv
			Params.FITINIT[2][11] = PCAparams[1];//initR //control 
			//meta3
			Params.FITINIT[3][8] =  PCAparams[2]; //initR //fonly 
			Params.FITINIT[3][9] =  PCAparams[2];//initR //vonly
			Params.FITINIT[3][10] = PCAparams[2]; //initR //fv
			Params.FITINIT[3][11] = PCAparams[2];//initR //control
			//VIRUS //3
			Params.muV			= PCAparams[3]; //virus decay
			Params.CV			= PCAparams[4];//hetereogeneity to virus infection 
			Params.nuV    		= PCAparams[5]; //virus transmission
			//FUNGUS //1
			Params.specific_nuF	= PCAparams[6]; //fungus transmissison
			//STOCHASTICITY //2
			Params.R_stoch 		= PCAparams[7];
			Params.F_stoch		= PCAparams[8];
			//LARVAL DISPERSAL
			Params.l_a_pop = PCAparams[9]; 
			Params.l_m_pop	= PCAparams[10];  

		}
		if(fit_routine==2){ //L META FIT
			Params.FITINIT[1][8] = 	PCAparams[0]; //initR //fonly
			//meta2
			Params.FITINIT[2][8] = 	PCAparams[1]; //initR //fonly  
			Params.FITINIT[2][9] = 	PCAparams[1];//initR //vonly 
			Params.FITINIT[2][10] = PCAparams[1]; //initR //fv
			Params.FITINIT[2][11] = PCAparams[1];//initR //control 
			//meta3
			Params.FITINIT[3][8] =  PCAparams[2]; //initR //fonly 
			Params.FITINIT[3][9] =  PCAparams[2];//initR //vonly
			Params.FITINIT[3][10] = PCAparams[2]; //initR //fv
			Params.FITINIT[3][11] = PCAparams[2];//initR //control
			//VIRUS //3
			Params.muV			= PCAparams[3]; //virus decay
			Params.CV			= PCAparams[4];//hetereogeneity to virus infection 
			Params.nuV    		= PCAparams[5]; //virus transmission
			//FUNGUS //1
			Params.specific_nuF	= PCAparams[6]; //fungus transmissison
			//STOCHASTICITY //2
			Params.R_stoch 		= PCAparams[7];
			Params.F_stoch		= PCAparams[8];
			//DISPERSAL
			Params.l_a_meta[1] = PCAparams[9]; 
			Params.l_a_meta[2] = PCAparams[10]; 
			Params.l_a_meta[3] = PCAparams[11]; 
			Params.l_m_meta[1]	= PCAparams[12]; 
			Params.l_m_meta[2]	= PCAparams[13]; 
			Params.l_m_meta[3]	= PCAparams[14]; 
		}
		if(fit_routine==3){ //L SUB FIT
			Params.FITINIT[1][8] = 	PCAparams[0]; //initR //fonly
			//meta2
			Params.FITINIT[2][8] = 	PCAparams[1]; //initR //fonly
			Params.FITINIT[2][9] = 	PCAparams[1];//initR //vonly 
			Params.FITINIT[2][10] = PCAparams[1]; //initR //fv
			Params.FITINIT[2][11] = PCAparams[1];//initR //control 
			//meta3
			Params.FITINIT[3][8] =  PCAparams[2]; //initR //fonly 
			Params.FITINIT[3][9] =  PCAparams[2];//initR //vonly
			Params.FITINIT[3][10] = PCAparams[2]; //initR //fv
			Params.FITINIT[3][11] = PCAparams[2];//initR //control
			//VIRUS //3
			Params.muV			= PCAparams[3]; //virus decay
			Params.CV			= PCAparams[4];//hetereogeneity to virus infection 
			Params.nuV    		= PCAparams[5]; //virus transmission
			//FUNGUS //1
			Params.specific_nuF	= PCAparams[6]; //fungus transmissison
			//STOCHASTICITY //2
			Params.R_stoch 		= PCAparams[7];
			Params.F_stoch		= PCAparams[8];
			//LARVAL DISPERSAL
			Params.l_a_sub[1][0] = PCAparams[9]; 
			Params.l_a_sub[1][1] = PCAparams[10]; 
			Params.l_a_sub[1][2] = PCAparams[11]; 
			Params.l_a_sub[1][3] = PCAparams[12]; 
			Params.l_a_sub[2][0] = PCAparams[13]; 
			Params.l_a_sub[2][1] = PCAparams[14]; 
			Params.l_a_sub[2][2] = PCAparams[15]; 
			Params.l_a_sub[2][3] = PCAparams[16]; 
			Params.l_a_sub[3][0] = PCAparams[17]; 
			Params.l_a_sub[3][1] = PCAparams[18]; 
			Params.l_a_sub[3][2] = PCAparams[19]; 
			Params.l_a_sub[3][3] = PCAparams[20]; 
			Params.l_m_sub[1][0] = PCAparams[21]; 
			Params.l_m_sub[1][1] = PCAparams[22]; 
			Params.l_m_sub[1][2] = PCAparams[23]; 
			Params.l_m_sub[1][3] = PCAparams[24]; 
			Params.l_m_sub[2][0] = PCAparams[25]; 
			Params.l_m_sub[2][1] = PCAparams[26]; 
			Params.l_m_sub[2][2] = PCAparams[27]; 
			Params.l_m_sub[2][3] = PCAparams[28]; 
			Params.l_m_sub[3][0] = PCAparams[29]; 
			Params.l_m_sub[3][1] = PCAparams[30]; 
			Params.l_m_sub[3][2] = PCAparams[31]; 
			Params.l_m_sub[3][3] = PCAparams[32]; 
		}
		if(fit_routine==4){ //L SUB FIT C POP FIT
			Params.FITINIT[1][8] = 	PCAparams[0]; //initR //fonly
			//meta2
			Params.FITINIT[2][8] = 	PCAparams[1]; //initR //fonly  
			Params.FITINIT[2][9] = 	PCAparams[1];//initR //vonly 
			Params.FITINIT[2][10] = PCAparams[1]; //initR //fv
			Params.FITINIT[2][11] = PCAparams[1];//initR //control 
			//meta3
			Params.FITINIT[3][8] =  PCAparams[2]; //initR //fonly 
			Params.FITINIT[3][9] =  PCAparams[2];//initR //vonly
			Params.FITINIT[3][10] = PCAparams[2]; //initR //fv
			Params.FITINIT[3][11] = PCAparams[2];//initR //control
			//VIRUS //3
			Params.muV			= PCAparams[3]; //virus decay
			Params.CV			= PCAparams[4];//hetereogeneity to virus infection 
			Params.nuV    		= PCAparams[5]; //virus transmission
			//FUNGUS //1
			Params.specific_nuF	= PCAparams[6]; //fungus transmissison

			//STOCHASTICITY //2
			Params.R_stoch 		= PCAparams[7];
			Params.F_stoch		= PCAparams[8];
			//CONIDIA DISPERSAL
			Params.c_a_pop 		= PCAparams[9];
			Params.c_m_pop		= PCAparams[10]; 
			//LARVAL DISPERSAL
			Params.l_a_sub[1][0] = PCAparams[11]; 
			Params.l_a_sub[1][1] = PCAparams[12]; 
			Params.l_a_sub[1][2] = PCAparams[13]; 
			Params.l_a_sub[1][3] = PCAparams[14]; 
			Params.l_a_sub[2][0] = PCAparams[15]; 
			Params.l_a_sub[2][1] = PCAparams[16]; 
			Params.l_a_sub[2][2] = PCAparams[17]; 
			Params.l_a_sub[2][3] = PCAparams[18]; 
			Params.l_a_sub[3][0] = PCAparams[19]; 
			Params.l_a_sub[3][1] = PCAparams[20]; 
			Params.l_a_sub[3][2] = PCAparams[21]; 
			Params.l_a_sub[3][3] = PCAparams[22]; 
			Params.l_m_sub[1][0] = PCAparams[23]; 
			Params.l_m_sub[1][1] = PCAparams[24]; 
			Params.l_m_sub[1][2] = PCAparams[25]; 
			Params.l_m_sub[1][3] = PCAparams[26]; 
			Params.l_m_sub[2][0] = PCAparams[27]; 
			Params.l_m_sub[2][1] = PCAparams[28]; 
			Params.l_m_sub[2][2] = PCAparams[29]; 
			Params.l_m_sub[2][3] = PCAparams[30]; 
			Params.l_m_sub[3][0] = PCAparams[31]; 
			Params.l_m_sub[3][1] = PCAparams[32]; 
			Params.l_m_sub[3][2] = PCAparams[33]; 
			Params.l_m_sub[3][3] = PCAparams[34]; 
		}
		if(fit_routine==5){ //L SUB FIT C META FIT
			Params.FITINIT[1][8] = 	PCAparams[0]; //initR //fonly
			//meta2
			Params.FITINIT[2][8] = 	PCAparams[1]; //initR //fonly 
			Params.FITINIT[2][9] = 	PCAparams[1];//initR //vonly 
			Params.FITINIT[2][10] = PCAparams[1]; //initR //fv
			Params.FITINIT[2][11] = PCAparams[1];//initR //control 
			//meta3
			Params.FITINIT[3][8] =  PCAparams[2]; //initR //fonly 
			Params.FITINIT[3][9] =  PCAparams[2];//initR //vonly
			Params.FITINIT[3][10] = PCAparams[2]; //initR //fv
			Params.FITINIT[3][11] = PCAparams[2];//initR //control
			//VIRUS //3
			Params.muV			= PCAparams[3]; //virus decay
			Params.CV			= PCAparams[4];//hetereogeneity to virus infection 
			Params.nuV    		= PCAparams[5]; //virus transmission
			//FUNGUS //1
			Params.specific_nuF	= PCAparams[6]; //fungus transmissison
			//STOCHASTICITY //2
			Params.R_stoch 		= PCAparams[7];
			Params.F_stoch		= PCAparams[8];
			//CONIDIA DISPERSAL
			Params.c_a_meta[1] = PCAparams[0];
			Params.c_a_meta[2] = PCAparams[10];
			Params.c_a_meta[3] = PCAparams[11];
			Params.c_m_meta[1]	= PCAparams[12]; 
			Params.c_m_meta[2]	= PCAparams[13]; 
			Params.c_m_meta[3]	= PCAparams[14]; 
			//LARVAL DISPERSAL
			Params.l_a_sub[1][0] = PCAparams[15]; 
			Params.l_a_sub[1][1] = PCAparams[16]; 
			Params.l_a_sub[1][2] = PCAparams[17]; 
			Params.l_a_sub[1][3] = PCAparams[18]; 
			Params.l_a_sub[2][0] = PCAparams[19]; 
			Params.l_a_sub[2][1] = PCAparams[20]; 
			Params.l_a_sub[2][2] = PCAparams[21]; 
			Params.l_a_sub[2][3] = PCAparams[22]; 
			Params.l_a_sub[3][0] = PCAparams[23]; 
			Params.l_a_sub[3][1] = PCAparams[24]; 
			Params.l_a_sub[3][2] = PCAparams[25]; 
			Params.l_a_sub[3][3] = PCAparams[26]; 
			Params.l_m_sub[1][0] = PCAparams[27]; 
			Params.l_m_sub[1][1] = PCAparams[28]; 
			Params.l_m_sub[1][2] = PCAparams[29]; 
			Params.l_m_sub[1][3] = PCAparams[30]; 
			Params.l_m_sub[2][0] = PCAparams[31]; 
			Params.l_m_sub[2][1] = PCAparams[32]; 
			Params.l_m_sub[2][2] = PCAparams[33]; 
			Params.l_m_sub[2][3] = PCAparams[34]; 
			Params.l_m_sub[3][0] = PCAparams[35]; 
			Params.l_m_sub[3][1] = PCAparams[36]; 
			Params.l_m_sub[3][2] = PCAparams[37]; 
			Params.l_m_sub[3][3] = PCAparams[38]; 
		}
		if(fit_routine==6){ //L Sub FIT C SUB FIT
			Params.FITINIT[1][8] = 	PCAparams[0]; //initR //fonly
			//meta2
			Params.FITINIT[2][8] = 	PCAparams[1]; //initR //fonly 
			Params.FITINIT[2][9] = 	PCAparams[1];//initR //vonly 
			Params.FITINIT[2][10] = PCAparams[1]; //initR //fv
			Params.FITINIT[2][11] = PCAparams[1];//initR //control 
			//meta3
			Params.FITINIT[3][8] =  PCAparams[2]; //initR //fonly 
			Params.FITINIT[3][9] =  PCAparams[2];//initR //vonly
			Params.FITINIT[3][10] = PCAparams[2]; //initR //fv
			Params.FITINIT[3][11] = PCAparams[2];//initR //control
			//VIRUS //3
			Params.muV			= PCAparams[3]; //virus decay
			Params.CV			= PCAparams[4];//hetereogeneity to virus infection 
			Params.nuV    		= PCAparams[5]; //virus transmission
			//FUNGUS //1
			Params.specific_nuF	= PCAparams[6]; //fungus transmissison
			//STOCHASTICITY //2
			Params.R_stoch 		= PCAparams[7];
			Params.F_stoch		= PCAparams[8];
			//CONIDIA DISPERSAL
			Params.c_a_sub[1][0] = PCAparams[9]; 
			Params.c_a_sub[1][1] = PCAparams[10];
			Params.c_a_sub[1][2] = PCAparams[11];
			Params.c_a_sub[1][3] = PCAparams[12];
			Params.c_a_sub[2][0] = PCAparams[13];
			Params.c_a_sub[2][1] = PCAparams[14];
			Params.c_a_sub[2][2] = PCAparams[15];
			Params.c_a_sub[2][3] = PCAparams[16];
			Params.c_a_sub[3][0] = PCAparams[17];
			Params.c_a_sub[3][1] = PCAparams[18];
			Params.c_a_sub[3][2] = PCAparams[19];
			Params.c_a_sub[3][3] = PCAparams[20];
			Params.c_m_sub[1][0] = PCAparams[21]; 
			Params.c_m_sub[1][1] = PCAparams[22]; 
			Params.c_m_sub[1][2] = PCAparams[23]; 
			Params.c_m_sub[1][3] = PCAparams[24]; 
			Params.c_m_sub[2][0] = PCAparams[25]; 
			Params.c_m_sub[2][1] = PCAparams[26]; 
			Params.c_m_sub[2][2] = PCAparams[27]; 
			Params.c_m_sub[2][3] = PCAparams[28]; 
			Params.c_m_sub[3][0] = PCAparams[29]; 
			Params.c_m_sub[3][1] = PCAparams[30]; 
			Params.c_m_sub[3][2] = PCAparams[31]; 
			Params.c_m_sub[3][3] = PCAparams[32]; 
			//LARVAL DISPERSAL
			Params.l_a_sub[1][0] = PCAparams[33]; 
			Params.l_a_sub[1][1] = PCAparams[34]; 
			Params.l_a_sub[1][2] = PCAparams[35]; 
			Params.l_a_sub[1][3] = PCAparams[36]; 
			Params.l_a_sub[2][0] = PCAparams[37]; 
			Params.l_a_sub[2][1] = PCAparams[38]; 
			Params.l_a_sub[2][2] = PCAparams[39]; 
			Params.l_a_sub[2][3] = PCAparams[40]; 
			Params.l_a_sub[3][0] = PCAparams[41]; 
			Params.l_a_sub[3][1] = PCAparams[42]; 
			Params.l_a_sub[3][2] = PCAparams[43]; 
			Params.l_a_sub[3][3] = PCAparams[44]; 
			Params.l_m_sub[1][0] = PCAparams[45]; 
			Params.l_m_sub[1][1] = PCAparams[46]; 
			Params.l_m_sub[1][2] = PCAparams[47]; 
			Params.l_m_sub[1][3] = PCAparams[48]; 
			Params.l_m_sub[2][0] = PCAparams[49]; 
			Params.l_m_sub[2][1] = PCAparams[50]; 
			Params.l_m_sub[2][2] = PCAparams[51]; 
			Params.l_m_sub[2][3] = PCAparams[52]; 
			Params.l_m_sub[3][0] = PCAparams[53]; 
			Params.l_m_sub[3][1] = PCAparams[54]; 
			Params.l_m_sub[3][2] = PCAparams[55]; 
			Params.l_m_sub[3][3] = PCAparams[56]; 
		}


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
}
*/
return 0;
}
