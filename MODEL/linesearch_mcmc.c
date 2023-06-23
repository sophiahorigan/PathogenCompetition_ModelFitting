#include "head.h"
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

int main(int argc, char *argv[])
{
if(argc!=3){
	printf("Requires 3 arguments: .c name, model #, algorithm #");
}

STRUCTURE Params;
inputdata(&Params);				
gsl_rng *r_seed;
r_seed=random_setup();

char *y = argv[1]; char *z = argv[2];
Params.model = atoi(y); Params.algorithm = atoi(z);

int model = Params.model;
int algorithm = Params.algorithm;

int VERBOSE = 0;
int TEST = 1;

// --------------------------------------------------Set Up-------------------------------------------------------------------- //


//ALGORITHM
if(algorithm==1){
	linesearch=1;reals=0;mcmc=0;
}
if(algorithm==2){
	linesearch=0;reals=1;mcmc=0;
}
if(algorithm==3){
	linesearch=0;reals=0;mcmc=1;
}
//DISPERSAL
int *p;
p = dispersal_fit(model);
larval_dispersal = p[0]; l_a_pop_fit = p[1]; l_a_meta_fit = p[2]; l_a_sub_fit = p[3]; l_m_pop_fit = p[4]; l_m_meta_fit = p[5]; l_m_sub_fit = p[6]; 
conidia_dispersal = p[7]; c_a_pop_fit = p[8]; c_a_meta_fit = p[9]; c_a_sub_fit = p[10]; c_m_pop_fit = p[11]; c_m_meta_fit = p[12]; c_m_sub_fit = p[13];
//FIT LIST
static int fit_params[92] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91};
int *f; 
f = which_fit(model);
for(int i=0;i<92;i++){
	fit[i] = f[i];
}
//TEST MODE
if(VERBOSE==1){
	LScalls=100; Rcalls=10; Mcalls=100; Realizations=2000;
	numround=5;searches=10;
}
if(TEST==1){
	LScalls=5; Rcalls=10; Mcalls=5; Realizations=10;
	numround=1;searches=1;
}

//----------------------------------Generate Inital Parameter Values------------------------//
int num_ltfparams = 92;
double ltf_params[92] = {0};   
double init_ltfparams[92] = {0};
double step_size[92] = {0};
double temp[92] = {0};

double log_prior = 0;

for (int i=0;i<num_ltfparams;i++){
    double randn = gsl_rng_uniform_pos(r_seed);
  	temp[i] = exp(ls_bound(i,1)) + randn * exp(ls_bound(i,2)); //propose initial values in exp space to avoid issue with negative numbers
	ltf_params[i] = log(temp[i]); //re-log since we will be taking steps in log space
    init_ltfparams[i] = ltf_params[i];
	step_size[i] = (ls_bound(i,2)-ls_bound(i,1))/(searches*3); //step size in log space
}

double localmax_params[92]={0};         //Array to record param values for the local max likelihood in line search
int a,b,c;								//indexing loops
double best_posterior;
double total_loghood_metas;
for (c=0;c<num_ltfparams;c++){			//initial parameters begin as 'best' parameters
    localmax_params[c]=ltf_params[c];
}
//calculate priors
for (int k=0; k<num_ltfparams; k++){
	log_prior = log_prior + log(gsl_ran_flat_pdf(exp(ltf_params[k]), prior_bound(k,1), (prior_bound(k,2)+prior_bound(k,1))));
}

///////////////////////////////////////////////////LINE-SEARCH///////////////////////////////////////////////////
if(linesearch==1){
int pid;
pid=getpid();

char namels[50];
sprintf(namels, "LS_s%i_r%i_m%i", searches, numround, model );
fpls=fopen(namels, "a+");

for (int round=0;round<numround;round++){
	best_posterior=-66666666666666;
	a=0;
	int i=0;

	for(int i=0;i<num_ltfparams;i++){ 
		if(fit[i] == 1){
			a = i;

			if (round>0){		
				ltf_params[a] = ltf_params[a] - (step_size[a] * searches);
				if(ltf_params[a] < ls_bound(a,1)){ //param and bound in log space
					ltf_params[a] = ls_bound(a,1);
				}
			}
			for (b=0;b<searches;b++){ //I think my ls only wanders up
				if (b>0){
					ltf_params[a] = ltf_params[a] + step_size[a]; //param and step size in log space
					if(ltf_params[a] > ls_bound(a,2)){ //param and bound in log space
						ltf_params[a] = ls_bound(a,2);
					}
				}
			//********FIXED PARAMS***********
			//INITIAL CONDITIONS
			//meta1
			Params.FITINIT[1][4] = 0; //initV //fonly //FX
			Params.FITINIT[1][5] = 0.2; //initV  //FX
			Params.FITINIT[1][6] = 0.2; //initV //FX
			Params.FITINIT[1][7] = 0; //initV //control //FX
			Params.FITINIT[1][9] = 0; //initR //vonly  //FX
			Params.FITINIT[1][10] = 0; //initR //fv //FX
			Params.FITINIT[1][11] = 0; //initR //control //FX
			//meta2
			Params.FITINIT[2][4] = 0; //initV //fonly //FX
			Params.FITINIT[2][5] = 0.2; //initV  //FX
			Params.FITINIT[2][6] = 0.2; //initV //FX
			Params.FITINIT[2][7] = 0; //initV //control //FX
			//meta3
			Params.FITINIT[3][4] = 0; //initV //f only //FX
			Params.FITINIT[3][5] = 0.2; //initV //FX
			Params.FITINIT[3][6] = 0.2; //initV //FX
			Params.FITINIT[3][7] = 0; //initV //control //FX
			//meta5
			Params.FITINIT[5][8] = 0; //initR

			//************FIT PARAMS*******************
			//S -- pop fit
			Params.FITINIT[1][0] = exp(ltf_params[0]); //initS //send in exponentiated param
			Params.FITINIT[1][1] = exp(ltf_params[0]); //initS 
			Params.FITINIT[1][2] = exp(ltf_params[0]); //initS 
			Params.FITINIT[1][3] = exp(ltf_params[0]); //initS 
			Params.FITINIT[2][0] = exp(ltf_params[0]); //initS  
			Params.FITINIT[2][1] = exp(ltf_params[0]); //initS 
			Params.FITINIT[2][2] = exp(ltf_params[0]); //initS 
			Params.FITINIT[2][3] = exp(ltf_params[0]); //initS 
			Params.FITINIT[3][0] = exp(ltf_params[0]); //initS 
			Params.FITINIT[3][1] = exp(ltf_params[0]); //initS 
			Params.FITINIT[3][2] = exp(ltf_params[0]); //initS 
			Params.FITINIT[3][3] = exp(ltf_params[0]); //initS 

			//INIT R
			//POP
			Params.r_pop = exp(ltf_params[1]);
			//META
			Params.r_meta[1] = exp(ltf_params[2]);;
			Params.r_meta[2] = exp(ltf_params[3]);;
			Params.r_meta[3] = exp(ltf_params[4]);;
			//SUB
			//meta1
			Params.FITINIT[1][8] = exp(ltf_params[5]); //initR
			//meta2
			Params.FITINIT[2][8] = exp(ltf_params[6]); //initR //fonly 
			Params.FITINIT[2][9] = exp(ltf_params[7]); //initR //vonly 
			Params.FITINIT[2][10] = exp(ltf_params[8]); //initR //fv
			Params.FITINIT[2][11] = exp(ltf_params[9]); //initR //control
			//meta3
			Params.FITINIT[3][8] = exp(ltf_params[10]); //initR //fonly
			Params.FITINIT[3][9] = exp(ltf_params[11]); //initR //vonly
			Params.FITINIT[3][10] = exp(ltf_params[12]); //initR //fv
			Params.FITINIT[3][11] = exp(ltf_params[13]); //initR //control

			//VIRUS //3
			Params.muV			= exp(ltf_params[14]); //Fuller 2012 //virus decay //0.39
			Params.CV			= exp(ltf_params[15]); //hetereogeneity to virus infection //previously 0.86
			Params.nuV    		= exp(ltf_params[16]); //virus transmission

			//FUNGUS //1
			Params.specific_nuF	= exp(ltf_params[17]); //fungus transmission

			//STOCHASTICITY //2
			Params.R_stoch 		= exp(ltf_params[18]);
			Params.F_stoch		= exp(ltf_params[19]);

			//CONIDIA DISPERSAL
			//c_a - pop //1
			Params.c_a_pop = exp(ltf_params[20]);
			//c_a - meta //3
			Params.c_a_meta[1] = exp(ltf_params[21]);
			Params.c_a_meta[2] = exp(ltf_params[22]);
			Params.c_a_meta[3] = exp(ltf_params[23]);
			//c_a - sub //12
			//meta 1
			Params.c_a_sub[1][0] = exp(ltf_params[24]); 
			Params.c_a_sub[1][1] = exp(ltf_params[25]);
			Params.c_a_sub[1][2] = exp(ltf_params[26]);
			Params.c_a_sub[1][3] = exp(ltf_params[27]);
			//meta 2
			Params.c_a_sub[2][0] = exp(ltf_params[28]); 
			Params.c_a_sub[2][1] = exp(ltf_params[29]);
			Params.c_a_sub[2][2] = exp(ltf_params[30]);
			Params.c_a_sub[2][3] = exp(ltf_params[31]);
			//meta 3
			Params.c_a_sub[3][0] = exp(ltf_params[32]); 
			Params.c_a_sub[3][1] = exp(ltf_params[33]);
			Params.c_a_sub[3][2] = exp(ltf_params[34]);
			Params.c_a_sub[3][3] = exp(ltf_params[35]);
			//c_m - pop //1
			Params.c_m_pop		= exp(ltf_params[36]); 
			//c_m - meta //3
			Params.c_m_meta[1]	= exp(ltf_params[37]);
			Params.c_m_meta[2]	= exp(ltf_params[38]);
			Params.c_m_meta[3]	= exp(ltf_params[39]);
			//c_m - sub //12
			//meta1
			Params.c_m_sub[1][0] = exp(ltf_params[40]);
			Params.c_m_sub[1][1] = exp(ltf_params[41]);
			Params.c_m_sub[1][2] = exp(ltf_params[42]);
			Params.c_m_sub[1][3] = exp(ltf_params[43]);
			//meta2	
			Params.c_m_sub[2][0] = exp(ltf_params[44]);
			Params.c_m_sub[2][1] = exp(ltf_params[45]);
			Params.c_m_sub[2][2] = exp(ltf_params[46]);
			Params.c_m_sub[2][3] = exp(ltf_params[47]);
			//meta3
			Params.c_m_sub[3][0] = exp(ltf_params[48]);
			Params.c_m_sub[3][1] = exp(ltf_params[49]);
			Params.c_m_sub[3][2] = exp(ltf_params[50]);
			Params.c_m_sub[3][3] = exp(ltf_params[51]);

			//LARVAL DISPERSAL
			//l_a - pop //1
			Params.l_a_pop = exp(ltf_params[52]);
			//l_a - meta //3
			Params.l_a_meta[1] = exp(ltf_params[53]);
			Params.l_a_meta[2] = exp(ltf_params[54]);
			Params.l_a_meta[3] = exp(ltf_params[55]);
			//l_a - sub //12
			//meta 1
			Params.l_a_sub[1][0] = exp(ltf_params[56]); 
			Params.l_a_sub[1][1] = exp(ltf_params[57]);
			Params.l_a_sub[1][2] = exp(ltf_params[58]);
			Params.l_a_sub[1][3] = exp(ltf_params[59]);
			//meta 2
			Params.l_a_sub[2][0] = exp(ltf_params[60]); 
			Params.l_a_sub[2][1] = exp(ltf_params[61]);
			Params.l_a_sub[2][2] = exp(ltf_params[62]);
			Params.l_a_sub[2][3] = exp(ltf_params[63]);
			//meta 3
			Params.l_a_sub[3][0] = exp(ltf_params[64]); 
			Params.l_a_sub[3][1] = exp(ltf_params[65]);
			Params.l_a_sub[3][2] = exp(ltf_params[66]);
			Params.l_a_sub[3][3] = exp(ltf_params[67]);
			//l_m - pop //1
			Params.l_m_pop		= exp(ltf_params[68]); 
			//l_m - meta //3
			Params.l_m_meta[1]	= exp(ltf_params[69]);
			Params.l_m_meta[2]	= exp(ltf_params[70]);
			Params.l_m_meta[3]	= exp(ltf_params[71]);
			//l_m - sub //12
			//meta1
			Params.l_m_sub[1][0] = exp(ltf_params[72]);
			Params.l_m_sub[1][1] = exp(ltf_params[73]);
			Params.l_m_sub[1][2] = exp(ltf_params[74]);
			Params.l_m_sub[1][3] = exp(ltf_params[75]);
			//meta2	
			Params.l_m_sub[2][0] = exp(ltf_params[76]);
			Params.l_m_sub[2][1] = exp(ltf_params[77]);
			Params.l_m_sub[2][2] = exp(ltf_params[78]);
			Params.l_m_sub[2][3] = exp(ltf_params[79]);
			//meta3
			Params.l_m_sub[3][0] = exp(ltf_params[80]);
			Params.l_m_sub[3][1] = exp(ltf_params[81]);
			Params.l_m_sub[3][2] = exp(ltf_params[82]);
			Params.l_m_sub[3][3] = exp(ltf_params[83]);
			//OBS INIT CONDITIONS //8
			//meta4
			Params.FITINIT[4][0] = exp(ltf_params[84]); //initS
			Params.FITINIT[4][4] = exp(ltf_params[85]); //initV
			Params.FITINIT[4][8] = exp(ltf_params[86]); //initR
			//meta5
			Params.FITINIT[5][0] = exp(ltf_params[87]); //initS
			Params.FITINIT[5][4] = exp(ltf_params[88]); //initV
			//meta6
			Params.FITINIT[6][0] = exp(ltf_params[89]); //initS
			Params.FITINIT[6][4] = exp(ltf_params[90]); //initV
			Params.FITINIT[6][8] = exp(ltf_params[91]); //initR

				//-------------------MISER CALCULATE LIKELIHOOD------------------------------//
			double lhood_meta=0; double log_lhood_meta=0; total_loghood_metas = 0;
			double new_posterior=0;
			double meta_err=0;
			double lhood_total=0;
			double lhood_reps=0;

			for(int j=1; j<=3; j++){
				Params.j = j;

				Params.miser_ticker = 1; Params.miser2_flag = 0; 

				gsl_monte_function G = { &likelihood_calc, dim, &Params };	// declares function calling lhood_meta.h
				double xl[dim];	double xu[dim];	// need to redeclare xl and xu since the size changes
				for (int jj=0;jj<dim;jj++)	{
					xl[jj]=0;	
					xu[jj]=1;
				}

				gsl_monte_miser_state *s = gsl_monte_miser_alloc(dim);
				gsl_monte_miser_integrate (&G,xl,xu,dim,LScalls,r_seed,s,&lhood_meta,&meta_err); //call MISER, pop_lhood is output from .h (likelihood value)
				gsl_monte_miser_free(s);
				
				while(Params.miser2_flag > 0){ //indicates that a better likelihood score (or a few) were found
					Params.miser2_flag = 0;
					Params.lhood_adjust[j] = -Params.bestlhood[j];
					
					gsl_monte_miser_state *s = gsl_monte_miser_alloc(dim);
					gsl_monte_miser_integrate (&G,xl,xu,dim,LScalls,r_seed,s,&lhood_meta,&meta_err); //call MISER, pop_lhood is output from .h (likelihood value)
					gsl_monte_miser_free(s);
				}

				log_lhood_meta = log(lhood_meta) - Params.lhood_adjust[j];
				if(isnan(log_lhood_meta) || isinf(log_lhood_meta)){ 
					log_lhood_meta = -9999;
				}
				
				total_loghood_metas = total_loghood_metas + log_lhood_meta;

				new_posterior = total_loghood_metas + log_prior;
			}
			if (new_posterior>best_posterior){ //compare likelihood //sum - one you just generated //local max - best you've seen
				best_posterior=new_posterior;
				for (c=0;c<num_ltfparams;c++){
					localmax_params[c]=ltf_params[c]; //save best param set from each individual search
				}
			}
		}  //best param set from within searches
		for (c=0;c<num_ltfparams;c++){
			ltf_params[c]=localmax_params[c];
		}
		i++;
		}
	} 
	int index;
	for(int ii=0; ii<num_ltfparams; ii++){
		if(fit[ii]==1){
			printf("printing param %i\n", ii);
			fprintf(fpls, "%lf\t", exp(ltf_params[ii]));
		}
	}
	fprintf(fpls, "%lf\t", total_loghood_metas);
	fprintf(fpls, "%lf\t", best_posterior);
	fprintf(fpls, "\n");
}

//fclose(fpl);
fclose(fpls); //parameter values
}
///////////////////////////////////////////////////REALIZATIONS///////////////////////////////////////////////////

if(reals==1){

	char name1[50];
	sprintf(name1, "REALS_c%i_m%i", Rcalls,  model );
	fpr=fopen(name1, "a+");

	char nameme[50];
	sprintf(nameme, "meta_err_m%i", Params.model );
	fpme=fopen(nameme, "a+");

	//********FIXED PARAMS***********
		//INITIAL CONDITIONS
		//meta1
		Params.FITINIT[1][4] = 0; //initV //fonly //FX
		Params.FITINIT[1][5] = 0.2; //initV  //FX
		Params.FITINIT[1][6] = 0.2; //initV //FX
		Params.FITINIT[1][7] = 0; //initV //control //FX
		Params.FITINIT[1][9] = 0; //initR //vonly  //FX
		Params.FITINIT[1][10] = 0; //initR //fv //FX
		Params.FITINIT[1][11] = 0; //initR //control //FX
		//meta2
		Params.FITINIT[2][4] = 0; //initV //fonly //FX
		Params.FITINIT[2][5] = 0.2; //initV  //FX
		Params.FITINIT[2][6] = 0.2; //initV //FX
		Params.FITINIT[2][7] = 0; //initV //control //FX
		//meta3
		Params.FITINIT[3][4] = 0; //initV //f only //FX
		Params.FITINIT[3][5] = 0.2; //initV //FX
		Params.FITINIT[3][6] = 0.2; //initV //FX
		Params.FITINIT[3][7] = 0; //initV //control //FX
		//meta5
		Params.FITINIT[5][8] = 0; //initR

		//************FIT PARAMS*******************
		//S -- pop fit
		Params.FITINIT[1][0] = exp(ltf_params[0]); //initS 
		Params.FITINIT[1][1] = exp(ltf_params[0]); //initS 
		Params.FITINIT[1][2] = exp(ltf_params[0]); //initS 
		Params.FITINIT[1][3] = exp(ltf_params[0]); //initS 
		Params.FITINIT[2][0] = exp(ltf_params[0]); //initS  
		Params.FITINIT[2][1] = exp(ltf_params[0]); //initS 
		Params.FITINIT[2][2] = exp(ltf_params[0]); //initS 
		Params.FITINIT[2][3] = exp(ltf_params[0]); //initS 
		Params.FITINIT[3][0] = exp(ltf_params[0]); //initS 
		Params.FITINIT[3][1] = exp(ltf_params[0]); //initS 
		Params.FITINIT[3][2] = exp(ltf_params[0]); //initS 
		Params.FITINIT[3][3] = exp(ltf_params[0]); //initS 

		//INIT R
		//POP
		Params.r_pop = exp(ltf_params[1]);
		//META
		Params.r_meta[1] = exp(ltf_params[2]);;
		Params.r_meta[2] = exp(ltf_params[3]);;
		Params.r_meta[3] = exp(ltf_params[4]);;
		//SUB
		//meta1
		Params.FITINIT[1][8] = exp(ltf_params[5]); //initR
		//meta2
		Params.FITINIT[2][8] = exp(ltf_params[6]); //initR //fonly 
		Params.FITINIT[2][9] = exp(ltf_params[7]); //initR //vonly 
		Params.FITINIT[2][10] = exp(ltf_params[8]); //initR //fv
		Params.FITINIT[2][11] = exp(ltf_params[9]); //initR //control
		//meta3
		Params.FITINIT[3][8] = exp(ltf_params[10]); //initR //fonly
		Params.FITINIT[3][9] = exp(ltf_params[11]); //initR //vonly
		Params.FITINIT[3][10] = exp(ltf_params[12]); //initR //fv
		Params.FITINIT[3][11] = exp(ltf_params[13]); //initR //control

		//VIRUS //3
		Params.muV			= 0.000040; //Fuller 2012 //virus decay //0.39
		Params.CV			= 0.375311; //hetereogeneity to virus infection //previously 0.86
		Params.nuV    		= 0.069059; //virus transmission

		//FUNGUS //1
		Params.specific_nuF	= 0.000068; //fungus transmission

		//STOCHASTICITY //2
		Params.R_stoch 		= 1.356527;
		Params.F_stoch		= 0.888823;

		//CONIDIA DISPERSAL
		//c_a - pop //1
		Params.c_a_pop = exp(ltf_params[20]);
		//c_a - meta //3
		Params.c_a_meta[1] = exp(ltf_params[21]);
		Params.c_a_meta[2] = exp(ltf_params[22]);
		Params.c_a_meta[3] = exp(ltf_params[23]);
		//c_a - sub //12
		//meta 1
		Params.c_a_sub[1][0] = exp(ltf_params[24]); 
		Params.c_a_sub[1][1] = exp(ltf_params[25]);
		Params.c_a_sub[1][2] = exp(ltf_params[26]);
		Params.c_a_sub[1][3] = exp(ltf_params[27]);
		//meta 2
		Params.c_a_sub[2][0] = exp(ltf_params[28]); 
		Params.c_a_sub[2][1] = exp(ltf_params[29]);
		Params.c_a_sub[2][2] = exp(ltf_params[30]);
		Params.c_a_sub[2][3] = exp(ltf_params[31]);
		//meta 3
		Params.c_a_sub[3][0] = exp(ltf_params[32]); 
		Params.c_a_sub[3][1] = exp(ltf_params[33]);
		Params.c_a_sub[3][2] = exp(ltf_params[34]);
		Params.c_a_sub[3][3] = exp(ltf_params[35]);
		//c_m - pop //1
		Params.c_m_pop		= exp(ltf_params[36]); 
		//c_m - meta //3
		Params.c_m_meta[1]	= exp(ltf_params[37]);
		Params.c_m_meta[2]	= exp(ltf_params[38]);
		Params.c_m_meta[3]	= exp(ltf_params[39]);
		//c_m - sub //12
		//meta1
		Params.c_m_sub[1][0] = exp(ltf_params[40]);
		Params.c_m_sub[1][1] = exp(ltf_params[41]);
		Params.c_m_sub[1][2] = exp(ltf_params[42]);
		Params.c_m_sub[1][3] = exp(ltf_params[43]);
		//meta2	
		Params.c_m_sub[2][0] = exp(ltf_params[44]);
		Params.c_m_sub[2][1] = exp(ltf_params[45]);
		Params.c_m_sub[2][2] = exp(ltf_params[46]);
		Params.c_m_sub[2][3] = exp(ltf_params[47]);
		//meta3
		Params.c_m_sub[3][0] = exp(ltf_params[48]);
		Params.c_m_sub[3][1] = exp(ltf_params[49]);
		Params.c_m_sub[3][2] = exp(ltf_params[50]);
		Params.c_m_sub[3][3] = exp(ltf_params[51]);

		//LARVAL DISPERSAL
		//l_a - pop //1
		Params.l_a_pop = exp(ltf_params[52]);
		//l_a - meta //3
		Params.l_a_meta[1] = exp(ltf_params[53]);
		Params.l_a_meta[2] = exp(ltf_params[54]);
		Params.l_a_meta[3] = exp(ltf_params[55]);
		//l_a - sub //12
		//meta 1
		Params.l_a_sub[1][0] = exp(ltf_params[56]); 
		Params.l_a_sub[1][1] = exp(ltf_params[57]);
		Params.l_a_sub[1][2] = exp(ltf_params[58]);
		Params.l_a_sub[1][3] = exp(ltf_params[59]);
		//meta 2
		Params.l_a_sub[2][0] = exp(ltf_params[60]); 
		Params.l_a_sub[2][1] = exp(ltf_params[61]);
		Params.l_a_sub[2][2] = exp(ltf_params[62]);
		Params.l_a_sub[2][3] = exp(ltf_params[63]);
		//meta 3
		Params.l_a_sub[3][0] = exp(ltf_params[64]); 
		Params.l_a_sub[3][1] = exp(ltf_params[65]);
		Params.l_a_sub[3][2] = exp(ltf_params[66]);
		Params.l_a_sub[3][3] = exp(ltf_params[67]);
		//l_m - pop //1
		Params.l_m_pop		= exp(ltf_params[68]); 
		//l_m - meta //3
		Params.l_m_meta[1]	= exp(ltf_params[69]);
		Params.l_m_meta[2]	= exp(ltf_params[70]);
		Params.l_m_meta[3]	= exp(ltf_params[71]);
		//l_m - sub //12
		//meta1
		Params.l_m_sub[1][0] = exp(ltf_params[72]);
		Params.l_m_sub[1][1] = exp(ltf_params[73]);
		Params.l_m_sub[1][2] = exp(ltf_params[74]);
		Params.l_m_sub[1][3] = exp(ltf_params[75]);
		//meta2	
		Params.l_m_sub[2][0] = exp(ltf_params[76]);
		Params.l_m_sub[2][1] = exp(ltf_params[77]);
		Params.l_m_sub[2][2] = exp(ltf_params[78]);
		Params.l_m_sub[2][3] = exp(ltf_params[79]);
		//meta3
		Params.l_m_sub[3][0] = exp(ltf_params[80]);
		Params.l_m_sub[3][1] = exp(ltf_params[81]);
		Params.l_m_sub[3][2] = exp(ltf_params[82]);
		Params.l_m_sub[3][3] = exp(ltf_params[83]);

		//OBS INIT CONDITIONS //8
		//meta4
		Params.FITINIT[4][0] = 8.816404; //initS
		Params.FITINIT[4][4] = 0.078705; //initV
		Params.FITINIT[4][8] = 0.000884; //initR
		//meta5
		Params.FITINIT[5][0] = 4.310543; //initS
		Params.FITINIT[5][4] = 0.138899; //initV
		//meta6
		Params.FITINIT[6][0] = 6.254701; //initS
		Params.FITINIT[6][4] = 0.003656; //initV
		Params.FITINIT[6][8] = 0.003448; //initR

	//start realizations. In this case, calls = # realizations
	double lhood_meta=0; double log_lhood_meta=0; double total_loghood_metas = 0;
	double new_posterior=0;
	double meta_err=0;
	double lhood_total=0;
	double lhood_reps=0;

	//for(j=1; j<=3; j++){
	for(int j=4; j<=6; j++){
		Params.j = j;

		Params.miser_ticker = 1; Params.miser2_flag = 0;

		gsl_monte_function G = { &likelihood_calc, dim, &Params };	// declares function calling lhood_meta.h
		double xl[dim];	double xu[dim];	// need to redeclare xl and xu since the size changes
		for (int jj=0;jj<dim;jj++)	{
			xl[jj]=0;	
			xu[jj]=1;
		}

		gsl_monte_miser_state *s = gsl_monte_miser_alloc(dim);
		gsl_monte_miser_integrate (&G,xl,xu,dim,Rcalls,r_seed,s,&lhood_meta,&meta_err); //call MISER, pop_lhood is output from .h (likelihood value)
		gsl_monte_miser_free(s);

		log_lhood_meta = log(lhood_meta) - Params.lhood_adjust[j];
		if(isnan(log_lhood_meta) || isinf(log_lhood_meta)){
			log_lhood_meta = -9999; //very bad score
		}
		
		total_loghood_metas = total_loghood_metas + log_lhood_meta;

		new_posterior = total_loghood_metas + log_prior;
	}
	//}
	fclose(fpr); 
	fclose(fpme);

}
//----------------------------------------------------Print Output to File-----------------------------

if(mcmc==1){
	//CUSTOMIZATIONS	
	//1. change PCA .txt names

	//FITTING ROUTINE
	int NumberOfParams = NumFitParams(model);    

	//FILE OUTPUT
	int pid;
	pid=getpid();

	char namem[50];
	sprintf(namem, "mcmc_results_%i_model%i", pid, model);
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

	int run; //CHECK maybe don't need
	int changer; //CHECK maybe don't need
	
	double pop_lhood, pop_lhood2, pop_err,post_hood;	// population lhood (and posterior lhood) calculated for each initS and initR
	double pop_best_lhood;					// likelihood and error for best initS and initR
	double best_post_hood;	double best_lhood=0;		// best post_hood and lhood
	//ouble prior[num_ltfparams]; //

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

	int a;
	int b;
	int ticker;
	int ticker2;

	int Case;

	int Accepted=0;
	signed int LoopNumber=-1;

	int ParCnt2 = NumberOfParams;

	double SigmaInflation=1.20;

	double sigma[NumberOfParams];

	run=1;	changer=1;	best_post_hood=-10000000000;


//---------------------------------Read in PCA-----------------------------------//
//MOVE READING IN PCA TO DATA_INPUT.H, then can make the file size flexible
//UPDATE MCMC FOR SKIP FIT
	FILE *file;

	file=fopen("PCAsd_0.txt", "r");          //Reading in the standard deviations of PCA.
	for (a=0; a<(NumberOfParams); a++)
	{
		fscanf(file, "%lf\n", &SDpca[a]);
		//printf("%lf\n", SDpca[a]);
	}
	fclose(file);


	file=fopen("PCArotations_0.txt", "r");   //Reading in the rotations (coefficients between PC's and parameters)
	for (a=0; a<(NumberOfParams*NumberOfParams); a++)
	{
		fscanf(file, "%lf\n", &Coefficients[a]);
		//printf("%lf\n", Coefficients[a]);
	}
	fclose(file);

	file=fopen("PCAscale_0.txt", "r");        //Reading in the scales to reconstruct parameter values from PC's.
	for (a=0; a<NumberOfParams; a++)
	{
		fscanf(file, "%lf\n", &Scale[a]);
		//printf("%lf\n", Scale[a]);
	}
	fclose(file);

	file=fopen("PCAcenter_0.txt", "r");       //Reading in the centers of parameters. Used in the reconstruction of parameters.

	for (a=0; a<NumberOfParams; a++)
	{
		fscanf(file, "%lf\n", &Center[a]);
		//printf("%lf\n", Center[a]);
	}
	fclose(file);

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
		
		//mcmc_assign_new(model);
		if(model==0){ //OBS PRIORS //14
		//CORE SET
			Params.muV			= PCAparams[0]; //virus decay
			Params.CV			= PCAparams[1];//hetereogeneity to virus infection 
			Params.nuV    		= PCAparams[2]; //virus transmission
			Params.specific_nuF	= PCAparams[3]; //fungus transmissison
			Params.R_stoch 		= PCAparams[4];
			Params.F_stoch		= PCAparams[5];
			//meta 4
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
		//-------------------assign old parameter values-----------------------//
		
		//mcmc_assign_old(model);
		if(model==0){ //OBS PRIORS //14
		//CORE SET
			Params.muV			= Old_Params[0]; //virus decay
			Params.CV			= Old_Params[1];//hetereogeneity to virus infection 
			Params.nuV    		= Old_Params[2]; //virus transmission
			Params.specific_nuF	= Old_Params[3]; //fungus transmissison
			Params.R_stoch 		= Old_Params[4];
			Params.F_stoch		= Old_Params[5];
			//meta 4
			Params.FITINIT[4][0] = Old_Params[6]; //initS
			Params.FITINIT[4][4] = Old_Params[7]; //initV
			Params.FITINIT[4][8] = Old_Params[8]; //initR
			//meta5
			Params.FITINIT[5][0] = Old_Params[9]; //initS
			Params.FITINIT[5][4] = Old_Params[10]; //initV
			//meta6
			Params.FITINIT[6][0] = Old_Params[11];//initS
			Params.FITINIT[6][4] = Old_Params[12]; //initV
			Params.FITINIT[6][8] = Old_Params[13]; //initR
		}			

		//-------------------MISER likelihood new------------------------------//
		double lhood_meta=0; double log_lhood_meta=0; double total_loghood_metas = 0;
		double new_posterior=0;
		double meta_err=0;
		double lhood_total=0;
		double lhood_reps=0;	

		for(int j=4; j<=6; j++){ //??? DO I WANT TO USE MY TICKER ALGORITHM HERE

			Params.miser_ticker = 1; Params.miser2_flag = 0; 
			
			Params.j = j;

			gsl_monte_function G = { &likelihood_calc, dim, &Params };	// declares function calling lhood_meta.h
			double xl[dim];	double xu[dim];	// need to redeclare xl and xu since the size changes
			for (int jj=0;jj<dim;jj++)	{
				xl[jj]=0;	
				xu[jj]=1;
			}

			gsl_monte_miser_state *s = gsl_monte_miser_alloc(dim);
			gsl_monte_miser_integrate (&G,xl,xu,dim,Mcalls,r_seed,s,&lhood_meta,&meta_err); //call MISER, pop_lhood is output from .h (likelihood value)
			gsl_monte_miser_free(s);
			
			while(Params.miser2_flag > 0){ //indicates that a better likelihood score (or a few) were found
				Params.miser2_flag = 0;
				Params.lhood_adjust[j] = -Params.bestlhood[j];
				
				gsl_monte_miser_state *s = gsl_monte_miser_alloc(dim);
				gsl_monte_miser_integrate (&G,xl,xu,dim,Mcalls,r_seed,s,&lhood_meta,&meta_err); //call MISER, pop_lhood is output from .h (likelihood value)
				gsl_monte_miser_free(s);
			}
			
			log_lhood_meta = log(lhood_meta) - Params.lhood_adjust[j];
			if(isnan(log_lhood_meta) || isinf(log_lhood_meta)){ 
				log_lhood_meta = -9999;
			}

			total_loghood_metas = total_loghood_metas + log_lhood_meta;
			LogNewPosterior = 0.0;
			LogNewPosterior = total_loghood_metas + log_prior;
		}//j
		
		if(LoopNumber==1){ //Initial calcualtion to get the ball rolling on likelihood comparison
			//-------------------MISER likelihood old------------------------------//
			lhood_meta=0; log_lhood_meta=0; total_loghood_metas = 0;
			new_posterior=0;
			meta_err=0;
			lhood_total=0;
			lhood_reps=0;

			for(int j=4; j<=6; j++){ //??? DO I WANT TO USE MY TICKER ALGORITHM HERE

				Params.miser_ticker = 1; Params.miser2_flag = 0; 
				
				Params.j = j;

				gsl_monte_function G = { &likelihood_calc, dim, &Params };	// declares function calling lhood_meta.h
				double xl[dim];	double xu[dim];	// need to redeclare xl and xu since the size changes
				for (int jj=0;jj<dim;jj++)	{
					xl[jj]=0;	
					xu[jj]=1;
				}

				gsl_monte_miser_state *s = gsl_monte_miser_alloc(dim);
				gsl_monte_miser_integrate (&G,xl,xu,dim,Mcalls,r_seed,s,&lhood_meta,&meta_err); //call MISER, pop_lhood is output from .h (likelihood value)
				gsl_monte_miser_free(s);
				
				while(Params.miser2_flag > 0){ //indicates that a better likelihood score (or a few) were found
					Params.miser2_flag = 0;
					Params.lhood_adjust[j] = -Params.bestlhood[j];
					
					gsl_monte_miser_state *s = gsl_monte_miser_alloc(dim);
					gsl_monte_miser_integrate (&G,xl,xu,dim,Mcalls,r_seed,s,&lhood_meta,&meta_err); //call MISER, pop_lhood is output from .h (likelihood value)
					gsl_monte_miser_free(s);
				}
				
				log_lhood_meta = log(lhood_meta) - Params.lhood_adjust[j];
				if(isnan(log_lhood_meta) || isinf(log_lhood_meta)){ //change to zero of inf or nan, only update lhood adj if not
					log_lhood_meta = -9999;
				}

				total_loghood_metas = total_loghood_metas + log_lhood_meta;
				LogOldPosterior = 0.0;
				LogOldPosterior = total_loghood_metas + log_prior;
			}//j

		}

		//----------compare new parm set with old parm set----------------
		
		ProbOfAcceptance=exp(LogNewPosterior+LogJumpToOld - LogOldPosterior-LogJumpToNew);    //Probability of accepting the new PC

		Params.LoopVect[Case] = Params.LoopVect[Case] + 1;

		if (ProbOfAcceptance>1 || gsl_rng_uniform_pos (r) < ProbOfAcceptance){   //ACCEPT PASS 1

			//-------------------MISER likelihood old------------------------------// //DOUBLE CHECK
			lhood_meta=0; log_lhood_meta=0; total_loghood_metas = 0;
			new_posterior=0;
			meta_err=0;
			lhood_total=0;
			lhood_reps=0;

			for(int j=4; j<=6; j++){ //??? DO I WANT TO USE MY TICKER ALGORITHM HERE

				Params.miser_ticker = 1; Params.miser2_flag = 0; 
				
				Params.j = j;

				gsl_monte_function G = { &likelihood_calc, dim, &Params };	// declares function calling lhood_meta.h
				double xl[dim];	double xu[dim];	// need to redeclare xl and xu since the size changes
				for (int jj=0;jj<dim;jj++)	{
					xl[jj]=0;	
					xu[jj]=1;
				}

				gsl_monte_miser_state *s = gsl_monte_miser_alloc(dim);
				gsl_monte_miser_integrate (&G,xl,xu,dim,Mcalls,r_seed,s,&lhood_meta,&meta_err); //call MISER, pop_lhood is output from .h (likelihood value)
				gsl_monte_miser_free(s);
				
				while(Params.miser2_flag > 0){ //indicates that a better likelihood score (or a few) were found
					Params.miser2_flag = 0;
					Params.lhood_adjust[j] = -Params.bestlhood[j];
					
					gsl_monte_miser_state *s = gsl_monte_miser_alloc(dim);
					gsl_monte_miser_integrate (&G,xl,xu,dim,Mcalls,r_seed,s,&lhood_meta,&meta_err); //call MISER, pop_lhood is output from .h (likelihood value)
					gsl_monte_miser_free(s);
				}
				
				log_lhood_meta = log(lhood_meta) - Params.lhood_adjust[j];
				if(isnan(log_lhood_meta) || isinf(log_lhood_meta)){ //change to zero of inf or nan, only update lhood adj if not
					log_lhood_meta = -9999;
				}

				total_loghood_metas = total_loghood_metas + log_lhood_meta;
				LogOldPosterior = 0.0;
				LogOldPosterior = total_loghood_metas + log_prior;
			}//j
			if (ProbOfAcceptance>1 || gsl_rng_uniform_pos (r) < ProbOfAcceptance){ //ACCEPT FINAL

				LogOldPosterior=LogNewPosterior;  //Accept the new parameter values.
				//Accepted=Accepted+1;
				//printf("Accepted\n");
				Params.AcceptedVect[Case] = Params.AcceptedVect[Case] + 1;
				SigmaInflation = 1; //only to sample in overdispersed space for initial sampling
			}
			else{ //REJECTED FINAL
				for (a=0; a<NumberOfParams; a++){
					PC[a]=Old_PC[a];            //Keep the old parameter values.
				}
				//printf("Rejected\n");
			}
		
		}
		else{ //REJECTED PASS 1
			for (a=0; a<NumberOfParams; a++){
				PC[a]=Old_PC[a];            //Keep the old parameter values.
			}
			//printf("Rejected\n");
		}

		// ------------------------------------------ output results to file  --------------------------------------- //
		if (LoopNumber % 10 == 0)   	//CK// output results every 10 loops (probably not best plan but we'll see)
		{
			//printf("printing! loop number = %i\n", LoopNumber);
			for(int ii=0; ii<NumberOfParams; ii++){
				fprintf(fpm, "%lf\t", PCAparams[ii]);
			}
			fprintf(fpm, "\n");
			//fflush(stdout);
		}
	}
	fclose(fpm);
}

return 0;
}
