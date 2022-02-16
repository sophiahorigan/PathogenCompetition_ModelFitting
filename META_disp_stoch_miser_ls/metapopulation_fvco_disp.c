#include "head_meta.h"
gsl_rng *r;

int main(void)
{

int test = 66; //CK// Second test mode.  Like the full program but less runs and less MISER calls

int View = 0;  //CK// turn to 1 to print line search progress.  turn to 0 to run for real.

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

// ----------------------------------------Set Up-------------------------------------------------------------------- //
int i=0; int j;int ii; int jj; int k; int l;
int num_adj_pars = 50;			// number of adjustable parameters
int epi_length = 48;

inputdata(&Params);				// gets Params.DATA[j][i][0-2] and Params.MAXT[i] from inputdata.h

// --------------------------------------- Name for Output Files ----------------------------------------------------- //
char strFileName[99];					// from filenames.h
GetString(pro,0,strFileName,98);		fflush(stdout);		//getc(stdin);
FILE *fp_results;
// ---------------------------------------- Random Number Stuff ------------------------------------------------------ //
gsl_rng *r_seed;
r_seed=random_setup();
//printf("Random Seed: %f\n", r_seed); //getc(stdin);

// ---------------------------------------------- Initial Conditions -------------------------------------------------- //

//dispersal parameters
Params.con_mrg = 0.05;
Params.a = 0.1;
Params.lar_disp = 0.05;

//coifection parameters
Params.coinf_V = 0.5;
Params.VFSus = 0.05;

//metapopulation one
//init S
Params.FITINIT[1][0] = 100; Params.FITINIT[1][1] = 100; Params.FITINIT[1][2] = 100; Params.FITINIT[1][3] = 100;
//printf("DEFINTION FItINIT[1][0] = %lf\n",Params->FITINIT[1][0]);
//init V
Params.FITINIT[1][4] = 0.2; Params.FITINIT[1][5] = 0.2; Params.FITINIT[1][6] = 0.2; Params.FITINIT[1][7] = 0.2;
//init R
Params.FITINIT[1][8] = 0.0236; Params.FITINIT[1][9] = 0.0236; Params.FITINIT[1][10] = 0.0236; Params.FITINIT[1][11] = 0.0236;

//metapopulation two
//init S
Params.FITINIT[2][0] = 100; Params.FITINIT[2][1] = 100; Params.FITINIT[2][2] = 100; Params.FITINIT[2][3] = 100;
//init V
Params.FITINIT[2][4] = 0.2; Params.FITINIT[2][5] = 0.2; Params.FITINIT[2][6] = 0.2; Params.FITINIT[2][7] = 0.2;
//init R
Params.FITINIT[2][8] = 0.0236; Params.FITINIT[2][9] = 0.0236; Params.FITINIT[2][10] = 0.0236; Params.FITINIT[2][11] = 0.0236;

//metapopulation three
//init S
Params.FITINIT[3][0] = 100; Params.FITINIT[3][1] = 100; Params.FITINIT[3][2] = 100; Params.FITINIT[3][3] = 100;
//init V
Params.FITINIT[3][4] = 0.2; Params.FITINIT[3][5] = 0.2; Params.FITINIT[3][6] = 0.2; Params.FITINIT[3][7] = 0.2;
//init R
Params.FITINIT[3][8] = 0.0236; Params.FITINIT[3][9] = 0.0236; Params.FITINIT[3][10] = 0.0236; Params.FITINIT[3][11] = 0.0236;

//metapopulation four
//init S
Params.FITINIT[4][0] = 100;
//init V
Params.FITINIT[4][4] = 0.2;
//init R
Params.FITINIT[4][8] = 0.0236;

//metapopulation five
//init S
Params.FITINIT[5][0] = 100;
//init V
Params.FITINIT[5][4] = 0.2;
//init R
Params.FITINIT[5][8] = 0.0236;

//metapopulation four
//init S
Params.FITINIT[6][0] = 100;
//init V
Params.FITINIT[6][4] = 0.2;
//init R
Params.FITINIT[6][8] = 0.0236;

//----------------------------------Line Search------------------------//

int Sreps = 1;
int reps = 200;
int searches=10;
int num_ltfparams=50;
double ltf_params[50]={0};      //Parameters to fit for the long-term model and their initial values
double init_ltfparams[50]={0};

for (i=0;i<num_ltfparams;i++){ //give random initial value for each parameter
    double randn=gsl_rng_uniform_pos(r_seed);
    //printf("%lf\n",randn);
    if (i==0){ltf_params[i]=3+randn*1;}
    else if (i==1){ltf_params[i]=0.1+randn*0.1;}
    else if (i==2){ltf_params[i]=2+randn*3;}
    else if (i==3){ltf_params[i]=0.2+randn*0.2;}
    else if (i==4){ltf_params[i]=1+randn*0.5;}
    else if (i==5){ltf_params[i]=pow(10,randn-2.5);}
    else if (i==6){ltf_params[i]=pow(10,randn-3);}
    else if (i==7){ltf_params[i]=pow(10,randn-3);}
    else if (i==8){ltf_params[i]=pow(10,randn-2.5);}
    else if (i==9){ltf_params[i]=pow(10,randn-2.5);}
	else if (i==10){ltf_params[i]=pow(10,randn-2.5);}
	else if (i==11){ltf_params[i]=pow(10,randn-2.5);}
	else if (i==12){ltf_params[i]=pow(10,randn-2.5);}
	else if (i==13){ltf_params[i]=pow(10,randn-2.5);}
	else if (i==14){ltf_params[i]=pow(10,randn-2.5);}
	else if (i==15){ltf_params[i]=pow(10,randn-2.5);}
	else if (i==16){ltf_params[i]=pow(10,randn-2.5);}
	else if (i==17){ltf_params[i]=pow(10,randn-2.5);}
	else if (i==18){ltf_params[i]=pow(10,randn-2.5);}
	else if (i==19){ltf_params[i]=pow(10,randn-2.5);}
	else if (i==20){ltf_params[i]=pow(10,randn-2.5);}
	else if (i==21){ltf_params[i]=pow(10,randn-2.5);}
	else if (i==22){ltf_params[i]=pow(10,randn-2.5);}
	else if (i==23){ltf_params[i]=pow(10,randn-2.5);}
	else if (i==24){ltf_params[i]=pow(10,randn-2.5);}
	else if (i==25){ltf_params[i]=pow(10,randn-2.5);}
	else if (i==26){ltf_params[i]=pow(10,randn-2.5);}
	else if (i==27){ltf_params[i]=pow(10,randn-2.5);}
	else if (i==28){ltf_params[i]=pow(10,randn-2.5);}
	else if (i==29){ltf_params[i]=pow(10,randn-2.5);}
	else if (i==30){ltf_params[i]=pow(10,randn-2.5);}
	else if (i==31){ltf_params[i]=pow(10,randn-2.5);}
	else if (i==32){ltf_params[i]=pow(10,randn-2.5);}
	else if (i==33){ltf_params[i]=pow(10,randn-2.5);}
	else if (i==34){ltf_params[i]=pow(10,randn-2.5);}
	else if (i==35){ltf_params[i]=pow(10,randn-2.5);}
	else if (i==36){ltf_params[i]=pow(10,randn-2.5);}
	else if (i==37){ltf_params[i]=pow(10,randn-2.5);}
	else if (i==38){ltf_params[i]=pow(10,randn-2.5);}
	else if (i==39){ltf_params[i]=pow(10,randn-2.5);}
	else if (i==40){ltf_params[i]=pow(10,randn-2.5);}
	else if (i==41){ltf_params[i]=pow(10,randn-2.5);}
	else if (i==42){ltf_params[i]=pow(10,randn-2.5);}
	else if (i==43){ltf_params[i]=pow(10,randn-2.5);}
	else if (i==44){ltf_params[i]=pow(10,randn-2.5);}
	else if (i==45){ltf_params[i]=pow(10,randn-2.5);}
	else if (i==46){ltf_params[i]=pow(10,randn-2.5);}
	else if (i==47){ltf_params[i]=pow(10,randn-2.5);}
	else if (i==48){ltf_params[i]=pow(10,randn-2.5);}
	else if (i==49){ltf_params[i]=pow(10,randn-2.5);}
    init_ltfparams[i]=ltf_params[i]; //fill both 
    printf("%lf\t %lf\n",init_ltfparams[i],ltf_params[i]);
}

double localmax_params[50]={0};         //Array to record param values for the local max likelihood in line search
int a,b,c;
double localmax_lhood;
for (c=0;c<num_ltfparams;c++){
    localmax_params[c]=ltf_params[c];
}

int r;
//for (Params.pop=1;Params.pop<=DATA_SETS;Params.pop++)	{

FILE *fpl;
char namel[50];
int pid;
pid=getpid();
//sprintf(name,"pred_row_%d_col_%d.txt",row,col);
sprintf(namel,"~/line_search%d.txt",pid);
//sprintf(name,"fv_bf_%f_row_%d_col_%d.txt",bfungus[bbf],row,col);

fpl=fopen(namel,"a+");    //a+ for reading and appending! Could only get the output of the last year with w+.


double sigma;
double stoch2;
int threshold=-1;
int maxt=200;
double county;
double countv;
double sum_Smitley;
double sum_defo;
double fracv_likelihood;
double sum_fracv;
double v_outbreak;
double weight;
double scale1=(-1)*(log(gsl_ran_gaussian_pdf(0,6.3))+log(gsl_ran_gaussian_pdf(0,7))+log(gsl_ran_gaussian_pdf(0,4.5))+log(gsl_ran_gaussian_pdf(0,3.9))+log(gsl_ran_gaussian_pdf(0,2.6))+log(gsl_ran_gaussian_pdf(0,4.8))+log(gsl_ran_gaussian_pdf(0,2.5))+log(gsl_ran_gaussian_pdf(0,2.5))+log(gsl_ran_gaussian_pdf(0,10))+log(gsl_ran_gaussian_pdf(0,9.6)));
double scale2=(-1)*(log(gsl_ran_poisson_pdf(28, 28)) + (log(gsl_ran_poisson_pdf(5, 5))+log(gsl_ran_poisson_pdf(12, 12)))/2 +  (log(gsl_ran_poisson_pdf(5, 5))+log(gsl_ran_poisson_pdf(6, 6))+log(gsl_ran_poisson_pdf(6, 6)))/3 + log(gsl_ran_poisson_pdf(28, 28))+log(gsl_ran_poisson_pdf(27, 27)));
double scale3=(-1)*(log(gsl_ran_binomial_pdf(3, 3.0/13.0, 13)));

sigma=3;
alpha_gammafungus=1;
double specific_stoch[100];
double specific_stoch_95p;
double temp;
/*
for (i=0;i<100;i++){
    specific_stoch[i]=gsl_ran_gaussian(r_seed,sigma);
}
for (i=0;i<99;i++){
    for (j=0;j<99-i;j++){
        if (specific_stoch[j]>specific_stoch[j+1]){
            temp=specific_stoch[j];
            specific_stoch[j]=specific_stoch[j+1];;
            specific_stoch[j+1]=temp;
        }
    }
}
specific_stoch_95p=specific_stoch[94];
printf("%lf\n",specific_stoch_95p);
*/
srand ( time(NULL) );
for (i=0;i<maxt;i++){
    randyeararr[i]=rand() % (wdata_length[2]);
    //printf("%d\t",randyeararr[i]);
}
//printf("\n");

int round;
int numround=5;
for (round=0;round<numround;round++){

localmax_lhood=-9999;
a=0;
//count=0;
while (a<num_ltfparams){            //Start line search, loop over parameters
if (round>0){
if (maxlhood==-9999 && a==0){
        ltf_params[0]=ltf_params[0]+1;
        //ltf_params[1]=ltf_params[a]+0.01;
        ltf_params[2]=ltf_params[2]+1;
        //ltf_params[3]=ltf_params[a]+1;
        localmax_params[0]=ltf_params[0];
        localmax_params[2]=ltf_params[2];
}
else {
    if (a==0){          //phifungus
        ltf_params[a]=ltf_params[a]-2*0.5*searches;   //Originally 0.05
    }
    else if (a==1){     //gammafungus
        ltf_params[a]=ltf_params[a]-0.02*0.5*searches;  //Originally 0.025
    }
    else if (a==2){     //additional susceptibility to fungus in virus-infected hosts
        ltf_params[a]=ltf_params[a]-2*0.5*searches;
    	if (ltf_params[a]<1){ltf_params[a]=1;}
    }
    else if (a==3){     //alpha for stochasticity in gammafungus
        ltf_params[a]=ltf_params[a]-0.1*0.5*searches;
    }
    else if (a==4){
        ltf_params[a]=ltf_params[a]-0.1*0.5*searches;
    }
    else if (a==5){     //Initial fungus density
        //ltf_params[a]=pow(10,log10(ltf_params[a])-0.04*0.5*searches);      //Originally 0.08
    }
    else if (a==6){     //Initial fungus density
        ltf_params[a]=pow(10,log10(ltf_params[a])-0.04*0.5*searches);
        if (ltf_params[a]>1){ltf_params[a]=1;}
    }
    else if (a==7){     //Initial fungus density
        ltf_params[a]=pow(10,log10(ltf_params[a])-0.04*0.5*searches);
        if (ltf_params[a]>1){ltf_params[a]=1;}
    }
    else if (a==8){     //Initial fungus density
        ltf_params[a]=pow(10,log10(ltf_params[a])-0.04*0.5*searches);
        if (ltf_params[a]>1){ltf_params[a]=1;}
    }
    else if (a==9){     //Initial fungus density
        ltf_params[a]=pow(10,log10(ltf_params[a])-0.04*0.5*searches);
        if (ltf_params[a]>1){ltf_params[a]=1;}
    }
    if (ltf_params[a]<init_ltfparams[a]){
        ltf_params[a]=init_ltfparams[a];
        //count=count+1;
    }
}
}
for (b=0;b<searches;b++){
    if (b>0){

    if (a==0){          //phifungus
        ltf_params[a]=ltf_params[a]+2;  //Originally 0.05
        //ltf_params[a]=pow(10,log10(ltf_params[a])+0.07);
        //if (ltf_params[a]>100){ltf_params[a]=100;}
    }
    else if (a==1){     //gammafungus
        ltf_params[a]=ltf_params[a]+0.02;    //Originally 0.025
        if (ltf_params[a]>0.99){ltf_params[a]=0.99;}
    }
    else if (a==2){     //additional susceptibility to fungus in virus-infected hosts
        ltf_params[a]=ltf_params[a]+2;
        //ltf_params[a]=pow(10,log10(ltf_params[a])+0.06);
        //if (ltf_params[a]>5000){ltf_params[a]=5000;}
    }
    else if (a==3){     //alpha for stochasticity in gammafungus
        ltf_params[a]=ltf_params[a]+0.1;
    //    if (ltf_params[a]>25){ltf_params[a]=25;}
    }
    else if (a==4){
        //printf("%d\t %e\n",a,ltf_params[a]);
        ltf_params[a]=ltf_params[a]+0.1;
        //if (ltf_params[a]>1e-3){ltf_params[a]=1e-3;}
        //printf("%d\t %e\n",a,ltf_params[a]);
    }
    //else if (a==5){     //Initial fungus density
        //ltf_params[a]=pow(10,log10(ltf_params[a])+0.04);        //Originally 0.08
        //if (ltf_params[a]>1){ltf_params[a]=1;}
    //}
    //else if (a==6){     //Initial fungus density
        //ltf_params[a]=pow(10,log10(ltf_params[a])+0.04);
        //if (ltf_params[a]>1){ltf_params[a]=1;}
    //}
    //else if (a==7){     //Initial fungus density
        //ltf_params[a]=pow(10,log10(ltf_params[a])+0.04);
        //if (ltf_params[a]>1){ltf_params[a]=1;}
    //}
    //else if (a==8){     //Initial fungus density
        //ltf_params[a]=pow(10,log10(ltf_params[a])+0.04);
        //if (ltf_params[a]>1){ltf_params[a]=1;}
    //}
    //else if (a==9){     //Initial fungus density
        //ltf_params[a]=pow(10,log10(ltf_params[a])+0.04);
        //if (ltf_params[a]>1){ltf_params[a]=1;}
    //}
    }
    phifungus=ltf_params[0];
    gammafungus=ltf_params[1];
    VFSus=ltf_params[2];
    alpha_gammafungus=ltf_params[3];
    sigma=ltf_params[4];
    RSPtime=21;
    immi=1e-6;
    //initial_nuF[0]=ltf_params[5];

    //printf("%e\n",immi);

sum_lhood=0;
sum_Smitley=0;
sum_defo=0;
sum_fracv=0;
for (i=0;i<100;i++){
    specific_stoch[i]=gsl_ran_gaussian(r_seed,sigma);
}
for (i=0;i<99;i++){
    for (j=0;j<99-i;j++){
        if (specific_stoch[j]>specific_stoch[j+1]){
            temp=specific_stoch[j];
            specific_stoch[j]=specific_stoch[j+1];;
            specific_stoch[j+1]=temp;
        }
    }
}
specific_stoch_95p=specific_stoch[94];

r_seed=random_setup();
for (r=0;r<reps;r++){


//-----------------------------------MISER------------------------------//

int calls=10;					// number of stochastic simulations for each parameter and IC set

size_t dim;

for(j=1; j<=DATA_SETS; j++){

	Params.j = j;

	dim = 48*2; //eventually need dim to be bigger //right now same stoch for each metapop

	double lhood_meta=0; double log_lhood_meta=0;
	double meta_err=0;
	double lhood_total=0;

	//define function
	gsl_monte_function G = { &LHood_Meta, dim, &Params };	// declares function calling Hood_Pops.h
	double xl[dim];	double xu[dim];	// need to redeclare xl and xu since the size changes
	for (jj=0;jj<=dim;jj++)	{
		xl[jj]=0;	
		xu[jj]=1;
	}

	gsl_monte_miser_state *s = gsl_monte_miser_alloc(dim);
	gsl_monte_miser_integrate (&G,xl,xu,dim,calls,r_seed,s,&lhood_meta,&meta_err); //call MISER, pop_lhood is output from .h (likelihood value)
	gsl_monte_miser_free(s);

	printf("For dataset %i, lhood = %lf\t, err = %lf\n", j, lhood_meta, meta_err);

	log_lhood_meta = log(lhood_meta)-700.0; 

	lhood_total += lhood_meta;
	printf("Lhood total = %lf\n", lhood_total);
}
//free_i3tensor(Params.EXPDATA,0,DATA_SETS,0,MAX_WEEKS,0,3);
return 0;
}