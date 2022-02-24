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

double lhood_meta; double log_lhood_meta;
double meta_err;
double lhood_total;
double ave_lhood;

// --------------------------------------- Name for Output Files ----------------------------------------------------- //
char strFileName[99];					// from filenames.h
GetString(pro,0,strFileName,98);		fflush(stdout);		//getc(stdin);
FILE *fp_results;
// ---------------------------------------- Random Number Stuff ------------------------------------------------------ //
gsl_rng *r_seed;
r_seed=random_setup();
//printf("Random Seed: %f\n", r_seed); //getc(stdin);

// ---------------------------------------------- Initial Conditions -------------------------------------------------- //
/*
//dispersal parameters
Params.con_mrg = 0.05;
Params.a = 0.1;
Params.lar_disp = 0.05;

//coifection parameters
Params.coinf_V = 0.5;
Params.VFSus = 0.05;
*/
//metapopulation one
//init S
//Params.FITINIT[1][0] = 100; Params.FITINIT[1][1] = 100; Params.FITINIT[1][2] = 100; Params.FITINIT[1][3] = 100;
//printf("DEFINTION FItINIT[1][0] = %lf\n",Params->FITINIT[1][0]);
//init V
Params.FITINIT[1][4] = 0; Params.FITINIT[1][5] = 0.2; Params.FITINIT[1][6] = 0.2; Params.FITINIT[1][7] = 0;
//init R
//Params.FITINIT[1][8] = 0.0236; Params.FITINIT[1][9] = 0.0236; Params.FITINIT[1][10] = 0.0236; Params.FITINIT[1][11] = 0.0236;

//metapopulation two
//init S
//Params.FITINIT[2][0] = 100; Params.FITINIT[2][1] = 100; Params.FITINIT[2][2] = 100; Params.FITINIT[2][3] = 100;
//init V
Params.FITINIT[2][4] = 0; Params.FITINIT[2][5] = 0.2; Params.FITINIT[2][6] = 0.2; Params.FITINIT[2][7] = 0;
//init R
//Params.FITINIT[2][8] = 0.0236; Params.FITINIT[2][9] = 0.0236; Params.FITINIT[2][10] = 0.0236; Params.FITINIT[2][11] = 0.0236;

//metapopulation three
//init S
//Params.FITINIT[3][0] = 100; Params.FITINIT[3][1] = 100; Params.FITINIT[3][2] = 100; Params.FITINIT[3][3] = 100;
//init V
Params.FITINIT[3][4] = 0; Params.FITINIT[3][5] = 0.2; Params.FITINIT[3][6] = 0.2; Params.FITINIT[3][7] = 0;
//init R
//Params.FITINIT[3][8] = 0.0236; Params.FITINIT[3][9] = 0.0236; Params.FITINIT[3][10] = 0.0236; Params.FITINIT[3][11] = 0.0236;

//metapopulation four
//init S
//Params.FITINIT[4][0] = 100;
//init V
//Params.FITINIT[4][4] = 0.2;
//init R
//Params.FITINIT[4][8] = 0.0236;

//metapopulation five
//init S
//Params.FITINIT[5][0] = 100;
//init V
//Params.FITINIT[5][4] = 0.2;
//init R
//Params.FITINIT[5][8] = 0.0236;

//metapopulation six
//init S
//Params.FITINIT[6][0] = 100;
//init V
//Params.FITINIT[6][4] = 0.2;
//init R
//Params.FITINIT[6][8] = 0.0236;

//----------------------------------Set-Up Line Search------------------------//

int searches = 10; //number of iterations for each specific parameter

int num_ltfparams = 50;	//number of parameters to fit
double ltf_params[50] = {0};      //arrays to hold different parameter values
double init_ltfparams[50]={0};

for (i=0;i<num_ltfparams;i++){ //give random initial value for each parameter
    double randn=gsl_rng_uniform_pos(r_seed); //random creates multuple starting points within bounds
    //printf("%lf\n",randn);
    if (i==0){ltf_params[i]=10+randn*140;} 			//initS 	10 - 200
    else if (i==1){ltf_params[i]=10+randn*190;} 	//initS 	10 - 200
    else if (i==2){ltf_params[i]=10+randn*190;}		//initS		10 - 200
    else if (i==3){ltf_params[i]=10+randn*190;}		//initS		10 - 200
    else if (i==4){ltf_params[i]=1+randn*0.5;}		//initV		0 - 1
    else if (i==5){ltf_params[i]=0+randn*1;}		//initV		0 - 1
    else if (i==6){ltf_params[i]=0+randn*1;}		//initV		0 - 1
    else if (i==7){ltf_params[i]=0+randn*1;}		//initV		0 - 1
    else if (i==8){ltf_params[i]=0+randn*0.1;}		//initR		0 - 0.1
    else if (i==9){ltf_params[i]=0+randn*0.1;}		//initR		0 - 0.1
	else if (i==10){ltf_params[i]=0+randn*0.1;}		//initR		0 - 0.1
	else if (i==11){ltf_params[i]=0+randn*0.1;}		//initR		0 - 0.1
	else if (i==12){ltf_params[i]=10+randn*190;}	//initS 	10 - 200
	else if (i==13){ltf_params[i]=10+randn*190;}	//initS 	10 - 200
	else if (i==14){ltf_params[i]=10+randn*190;}	//initS 	10 - 200
	else if (i==15){ltf_params[i]=10+randn*190;}	//initS 	10 - 200
	else if (i==16){ltf_params[i]=0+randn*1;}		//initV		0 - 1
	else if (i==17){ltf_params[i]=0+randn*1;}		//initV		0 - 1
	else if (i==18){ltf_params[i]=0+randn*1;}		//initV		0 - 1
	else if (i==19){ltf_params[i]=0+randn*1;}		//initV		0 - 1
	else if (i==20){ltf_params[i]=0+randn*0.1;}		//initR		0 - 0.1
	else if (i==21){ltf_params[i]=0+randn*0.1;}		//initR		0 - 0.1
	else if (i==22){ltf_params[i]=0+randn*0.1;}		//initR		0 - 0.1
	else if (i==23){ltf_params[i]=0+randn*0.1;}		//initR		0 - 0.1
	else if (i==24){ltf_params[i]=10+randn*190;}	//initS		10 - 150
	else if (i==25){ltf_params[i]=10+randn*190;}	//initS		10 - 150
	else if (i==26){ltf_params[i]=10+randn*190;}	//initS		10 - 150
	else if (i==27){ltf_params[i]=10+randn*190;}	//initS		10 - 150
	else if (i==28){ltf_params[i]=0+randn*1;}		//initV		0 - 1
	else if (i==29){ltf_params[i]=0+randn*1;}		//initV		0 - 1
	else if (i==30){ltf_params[i]=0+randn*1;}		//initV		0 - 1
	else if (i==31){ltf_params[i]=0+randn*1;}		//initV		0 - 1
	else if (i==32){ltf_params[i]=0+randn*0.1;}		//initR		0 - 0.1
	else if (i==33){ltf_params[i]=0+randn*0.1;}		//initR		0 - 0.1
	else if (i==34){ltf_params[i]=0+randn*0.1;}		//initR		0 - 0.1
	else if (i==35){ltf_params[i]=0+randn*0.1;}		//initR		0 - 0.1
	else if (i==36){ltf_params[i]=10+randn*140;}	//initS		10 - 150
	else if (i==37){ltf_params[i]=0+randn*1;}		//initV		0 - 1
	else if (i==38){ltf_params[i]=0+randn*0.1;}		//initR		0 - 0.1
	else if (i==39){ltf_params[i]=10+randn*140;}	//initS		10 - 150
	else if (i==40){ltf_params[i]=0+randn*1;}		//initV		0 - 1
	else if (i==41){ltf_params[i]=0+randn*0.1;}		//initR		0 - 0.1
	else if (i==42){ltf_params[i]=10+randn*140;}	//initS		10 - 150
	else if (i==43){ltf_params[i]=0+randn*1;}		//initV		0 - 1
	else if (i==44){ltf_params[i]=0+randn*0.1;}		//initR		0 - 0.1
	else if (i==45){ltf_params[i]=0+randn*1;}		//con_mrg	0 - 1
	else if (i==46){ltf_params[i]=0+randn*1;}		//a			???? what values can a take
	else if (i==47){ltf_params[i]=0+randn*1;}		//lar_disp	0 - 1
	else if (i==48){ltf_params[i]=0+randn*1;}		//coinf_V	0 - 1
	else if (i==49){ltf_params[i]=0+randn*500;}		//VFSus		0 - 500
    init_ltfparams[i]=ltf_params[i]; //fill both 
    //printf("%lf\t %lf\n",init_ltfparams[i],ltf_params[i]);
	//printf("i = %i\t, lft_params = %lf\n %lf\n",i, init_ltfparams[i]);
}

double localmax_params[50]={0};         //Array to record param values for the local max likelihood in line search
int a,b,c;								//indexing loops
double localmax_lhood; double maxlhood;
for (c=0;c<num_ltfparams;c++){			//initial parameters begin as 'best' parameters
    localmax_params[c]=ltf_params[c];
}

int r;

//----------------------------------------------------Print Output to File-------------------------------------------//
char namel[50];
//int pid;
//pid=getpid();
//sprintf(namel,"~/line_search%d.txt",pid);
sprintf(namel,"line_search");
fpl=fopen(namel,"a+");    //a+ for reading and appending! Could only get the output of the last year with w+.
//fprintf(fpl, "hello, world!");

//---------------------------------------------- Line-Search -------------------------------------------------------//
//specify parameter bounds and increments
int round;
int numround=5;
for (round=0;round<numround;round++){
	localmax_lhood=-9999;
	a=0;
	while (a<num_ltfparams){            //Start line search, loop over parameters
		if (round>0){					//this loop to help bounds if likelihood is horrible
		if (maxlhood==-9999 && a==0){		//if likelihood is super bad, in next round change some of parameter values //optional
		}
		else { 	//fix low bound of parameter, based on searches
			if (a==0){          //initS //10 is step increment //searches: number of param values testing
				ltf_params[a]=ltf_params[a]-10*searches;
			}
			else if (a==1){     //initS
				ltf_params[a]=ltf_params[a]-10*searches;
			}
			else if (a==2){     //initS
				ltf_params[a]=ltf_params[a]-10*searches;
			}
			else if (a==3){     //initS
				ltf_params[a]=ltf_params[a]-10*searches;
			}
			else if (a==4){		//initV
				ltf_params[a]=ltf_params[a]-0.05*searches;
				if (ltf_params[a]>1){ltf_params[a]=1;}
			}
			else if (a==5){     //initV
				ltf_params[a]=ltf_params[a]-0.05*searches;
				if (ltf_params[a]>1){ltf_params[a]=1;}		//upper bound
			}
			else if (a==6){     //initV
				ltf_params[a]=ltf_params[a]-0.05*searches;
				if (ltf_params[a]>1){ltf_params[a]=1;}
			}
			else if (a==7){     //initV
				ltf_params[a]=ltf_params[a]-0.05*searches;
				if (ltf_params[a]>1){ltf_params[a]=1;}
			}
			else if (a==8){     //initR
				ltf_params[a]=ltf_params[a]-0.0005*searches;
				if (ltf_params[a]>0.5){ltf_params[a]=0.5;}
			}
			else if (a==9){     //initR
				ltf_params[a]=ltf_params[a]-0.0005*searches;
				if (ltf_params[a]>0.5){ltf_params[a]=0.5;}
			}
			else if (a==10){     //initR
				ltf_params[a]=ltf_params[a]-0.0005*searches;
				if (ltf_params[a]>0.5){ltf_params[a]=0.5;}
			}
			else if (a==11){     //initR
				ltf_params[a]=ltf_params[a]-0.0005*searches;
				if (ltf_params[a]>0.5){ltf_params[a]=0.5;}
			}
			else if (a==12){     //initS
				ltf_params[a]=ltf_params[a]-10*searches;
			}
			else if (a==13){     //initS
				ltf_params[a]=ltf_params[a]-10*searches;
			}
			else if (a==14){     //initS
				ltf_params[a]=ltf_params[a]-10*searches;
			}
			else if (a==15){     //initS
				ltf_params[a]=ltf_params[a]-10*searches;
			}
			else if (a==16){     //initV
				ltf_params[a]=ltf_params[a]-0.05*searches;
				if (ltf_params[a]>1){ltf_params[a]=1;}
			}
			else if (a==17){     //initV
				ltf_params[a]=ltf_params[a]-0.05*searches;
				if (ltf_params[a]>1){ltf_params[a]=1;}
			}
			else if (a==18){     //initV
				ltf_params[a]=ltf_params[a]-0.05*searches;
				if (ltf_params[a]>1){ltf_params[a]=1;}
			}
			else if (a==19){     //initV
				ltf_params[a]=ltf_params[a]-0.05*searches;
				if (ltf_params[a]>1){ltf_params[a]=1;}
			}
			else if (a==20){     //initR
				ltf_params[a]=ltf_params[a]-0.0005*searches;
				if (ltf_params[a]>0.5){ltf_params[a]=0.5;}		
			}
			else if (a==21){     //initR
				ltf_params[a]=ltf_params[a]-0.0005*searches;
				if (ltf_params[a]>0.5){ltf_params[a]=0.5;}
			}
			else if (a==22){     //initR
				ltf_params[a]=ltf_params[a]-0.0005*searches;
				if (ltf_params[a]>0.5){ltf_params[a]=0.5;}
			}
			else if (a==23){     //initR
				ltf_params[a]=ltf_params[a]-0.0005*searches;
				if (ltf_params[a]>0.5){ltf_params[a]=0.5;}
			}
			else if (a==24){     //initS
				ltf_params[a]=ltf_params[a]-10*searches;
			}
			else if (a==25){     //initS
				ltf_params[a]=ltf_params[a]-10*searches;
			}
			else if (a==26){     //initS
				ltf_params[a]=ltf_params[a]-10*searches;
			}
			else if (a==27){     //initS
				ltf_params[a]=ltf_params[a]-10*searches;
			}
			else if (a==28){     //initV
				ltf_params[a]=ltf_params[a]-0.05*searches;
				if (ltf_params[a]>1){ltf_params[a]=1;}
			}
			else if (a==29){     //initV
				ltf_params[a]=ltf_params[a]-0.05*searches;
				if (ltf_params[a]>1){ltf_params[a]=1;}
			}
			else if (a==30){     //initV
				ltf_params[a]=ltf_params[a]-0.05*searches;
				if (ltf_params[a]>1){ltf_params[a]=1;}
			}
			else if (a==31){     //initV
				ltf_params[a]=ltf_params[a]-0.05*searches;
				if (ltf_params[a]>1){ltf_params[a]=1;}
			}
			else if (a==32){     //initR
				ltf_params[a]=ltf_params[a]-0.0005*searches;
				if (ltf_params[a]>0.5){ltf_params[a]=0.5;}
			}
			else if (a==33){     //initR
				ltf_params[a]=ltf_params[a]-0.0005*searches;
				if (ltf_params[a]>0.5){ltf_params[a]=0.5;}
			}
			else if (a==34){     //initR
				ltf_params[a]=ltf_params[a]-0.0005*searches;
				if (ltf_params[a]>0.5){ltf_params[a]=0.5;}
			}
			else if (a==35){     //initR
				ltf_params[a]=ltf_params[a]-0.0005*searches;
				if (ltf_params[a]>0.5){ltf_params[a]=0.5;}
			}
			else if (a==36){     //initS
				ltf_params[a]=ltf_params[a]-10*searches;
			}
			else if (a==37){     //initV
				ltf_params[a]=ltf_params[a]-0.05*searches;
				if (ltf_params[a]>1){ltf_params[a]=1;}
			}
			else if (a==38){     //initR
				ltf_params[a]=ltf_params[a]-0.0005*searches;
				if (ltf_params[a]>0.5){ltf_params[a]=0.5;}
			}
			else if (a==39){     //initS
				ltf_params[a]=ltf_params[a]-10*searches;
			}
			else if (a==40){     //initV
				ltf_params[a]=ltf_params[a]-0.05*searches;
				if (ltf_params[a]>1){ltf_params[a]=1;}
			}
			else if (a==41){     //initR
				ltf_params[a]=ltf_params[a]-0.0005*searches;
				if (ltf_params[a]>0.5){ltf_params[a]=0.5;}
			}
			else if (a==42){     //initS
				ltf_params[a]=ltf_params[a]-10*searches;
			}
			else if (a==43){     //initV
				ltf_params[a]=ltf_params[a]-0.05*searches;
				if (ltf_params[a]>1){ltf_params[a]=1;}
			}
			else if (a==44){     //initR
				ltf_params[a]=ltf_params[a]-0.0005*searches;
				if (ltf_params[a]>0.5){ltf_params[a]=0.5;}
			}
			else if (a==45){     //con_mgr
				ltf_params[a]=ltf_params[a]-0.05*searches;
				if (ltf_params[a]>1){ltf_params[a]=1;}
			}
			else if (a==46){     //a
				ltf_params[a]=ltf_params[a]-0.05*searches;
				if (ltf_params[a]>1){ltf_params[a]=1;}
			}
			else if (a==47){     //lar_disp
				ltf_params[a]=ltf_params[a]-0.05*searches;
				if (ltf_params[a]>1){ltf_params[a]=1;}
			}
			else if (a==48){     //coinf_V
				ltf_params[a]=ltf_params[a]-0.05*searches;
				if (ltf_params[a]>1){ltf_params[a]=1;}
			}
			else if (a==49){     //VFSus
				ltf_params[a]=ltf_params[a]-10*searches;
			}
			if (ltf_params[a]<init_ltfparams[a]){
				ltf_params[a]=init_ltfparams[a];  //initial values are lowest bound
			}
		}
		}
		for (b=0;b<searches;b++){ //step though increments back up to initial proposed value
		if (b>0){
			if (a==0){          //initS
				ltf_params[a]=ltf_params[a]+10;  // 10 is step size, same as in a loop
			}
			else if (a==1){     //initS
				ltf_params[a]=ltf_params[a]+10; 
			}
			else if (a==2){     //initS
				ltf_params[a]=ltf_params[a]+10; 
			}
			else if (a==3){     //initS
				ltf_params[a]=ltf_params[a]+10; 
			}
			else if (a==4){		//initV
				ltf_params[a]=ltf_params[a]+0.05;
				if (ltf_params[a]>1){ltf_params[a]=1;}		//upper bound
			}
			else if (a==5){     //initV
				ltf_params[a]=ltf_params[a]+0.05;
				if (ltf_params[a]>1){ltf_params[a]=1;}
			}
			else if (a==6){     //initV
				ltf_params[a]=ltf_params[a]+0.05;
				if (ltf_params[a]>1){ltf_params[a]=1;}
			}
			else if (a==7){     //initV
				ltf_params[a]=ltf_params[a]+0.05;
				if (ltf_params[a]>1){ltf_params[a]=1;}
			}
			else if (a==8){     //initR
				ltf_params[a]=ltf_params[a]+0.0005;
				if (ltf_params[a]>0.5){ltf_params[a]=0.5;}
			}
			else if (a==9){     //initR
				ltf_params[a]=ltf_params[a]+0.0005;
				if (ltf_params[a]>0.5){ltf_params[a]=0.5;}
			}
			else if (a==10){     //initR
				ltf_params[a]=ltf_params[a]+0.0005;
				if (ltf_params[a]>0.5){ltf_params[a]=0.5;}
			}
			else if (a==11){     //initR
				ltf_params[a]=ltf_params[a]+0.0005;
				if (ltf_params[a]>0.5){ltf_params[a]=0.5;}
			}
			else if (a==12){          //initS
				ltf_params[a]=ltf_params[a]+10;  // 10 is step size, same as in a loop
			}
			else if (a==13){     //initS
				ltf_params[a]=ltf_params[a]+10; 
			}
			else if (a==14){     //initS
				ltf_params[a]=ltf_params[a]+10; 
			}
			else if (a==15){     //initS
				ltf_params[a]=ltf_params[a]+10; 
			}
			else if (a==16){		//initV
				ltf_params[a]=ltf_params[a]+0.05;
				if (ltf_params[a]>1){ltf_params[a]=1;}		//upper bound
			}
			else if (a==17){     //initV
				ltf_params[a]=ltf_params[a]+0.05;
				if (ltf_params[a]>1){ltf_params[a]=1;}
			}
			else if (a==18){     //initV
				ltf_params[a]=ltf_params[a]+0.05;
				if (ltf_params[a]>1){ltf_params[a]=1;}
			}
			else if (a==19){     //initV
				ltf_params[a]=ltf_params[a]+0.05;
				if (ltf_params[a]>1){ltf_params[a]=1;}
			}
			else if (a==20){     //initR
				ltf_params[a]=ltf_params[a]+0.0005;
				if (ltf_params[a]>0.5){ltf_params[a]=0.5;}
			}
			else if (a==21){     //initR
				ltf_params[a]=ltf_params[a]+0.0005;
				if (ltf_params[a]>0.5){ltf_params[a]=0.5;}
			}
			else if (a==22){     //initR
				ltf_params[a]=ltf_params[a]+0.0005;
				if (ltf_params[a]>0.5){ltf_params[a]=0.5;}
			}
			else if (a==23){     //initR
				ltf_params[a]=ltf_params[a]+0.0005;
				if (ltf_params[a]>0.5){ltf_params[a]=0.5;}
			}
			else if (a==24){          //initS
				ltf_params[a]=ltf_params[a]+10;  // 10 is step size, same as in a loop
			}
			else if (a==25){     //initS
				ltf_params[a]=ltf_params[a]+10; 
			}
			else if (a==26){     //initS
				ltf_params[a]=ltf_params[a]+10; 
			}
			else if (a==27){     //initS
				ltf_params[a]=ltf_params[a]+10; 
			}
			else if (a==28){		//initV
				ltf_params[a]=ltf_params[a]+0.05;
				if (ltf_params[a]>1){ltf_params[a]=1;}		//upper bound
			}
			else if (a==29){     //initV
				ltf_params[a]=ltf_params[a]+0.05;
				if (ltf_params[a]>1){ltf_params[a]=1;}
			}
			else if (a==30){     //initV
				ltf_params[a]=ltf_params[a]+0.05;
				if (ltf_params[a]>1){ltf_params[a]=1;}
			}
			else if (a==31){     //initV
				ltf_params[a]=ltf_params[a]+0.05;
				if (ltf_params[a]>1){ltf_params[a]=1;}
			}
			else if (a==32){     //initR
				ltf_params[a]=ltf_params[a]+0.0005;
				if (ltf_params[a]>0.5){ltf_params[a]=0.5;}
			}
			else if (a==33){     //initR
				ltf_params[a]=ltf_params[a]+0.0005;
				if (ltf_params[a]>0.5){ltf_params[a]=0.5;}
			}
			else if (a==34){     //initR
				ltf_params[a]=ltf_params[a]+0.0005;
				if (ltf_params[a]>0.5){ltf_params[a]=0.5;}
			}
			else if (a==35){     //initR
				ltf_params[a]=ltf_params[a]+0.0005;
				if (ltf_params[a]>0.5){ltf_params[a]=0.5;}
			}
			else if (a==36){     //initS
				ltf_params[a]=ltf_params[a]+10; 
			}
			else if (a==37){     //initV
				ltf_params[a]=ltf_params[a]+0.05;
				if (ltf_params[a]>1){ltf_params[a]=1;}
			}
			else if (a==38){     //initR
				ltf_params[a]=ltf_params[a]+0.0005;
				if (ltf_params[a]>0.5){ltf_params[a]=0.5;}
			}
			else if (a==39){     //initS
				ltf_params[a]=ltf_params[a]+10; 
			}
			else if (a==40){     //initV
				ltf_params[a]=ltf_params[a]+0.05;
				if (ltf_params[a]>1){ltf_params[a]=1;}
			}
			else if (a==41){     //initR
				ltf_params[a]=ltf_params[a]+0.0005;
				if (ltf_params[a]>0.5){ltf_params[a]=0.5;}
			}
			else if (a==42){     //initS
				ltf_params[a]=ltf_params[a]+10; 
			}
			else if (a==43){     //initV
				ltf_params[a]=ltf_params[a]+0.05;
				if (ltf_params[a]>1){ltf_params[a]=1;}
			}
			else if (a==44){     //initR
				ltf_params[a]=ltf_params[a]+0.0005;
				if (ltf_params[a]>0.5){ltf_params[a]=0.5;}
			}
			else if (a==45){     //con_mrg
				ltf_params[a]=ltf_params[a]+0.05;
				if (ltf_params[a]>1){ltf_params[a]=1;}
			}
			else if (a==46){     //a
				ltf_params[a]=ltf_params[a]+0.05;
				if (ltf_params[a]>1){ltf_params[a]=1;}
			}
			else if (a==47){     //lar_disp
				ltf_params[a]=ltf_params[a]+0.05;
				if (ltf_params[a]>1){ltf_params[a]=1;}
			}
			else if (a==48){     //coinf_V
				ltf_params[a]=ltf_params[a]+0.05;
				if (ltf_params[a]>1){ltf_params[a]=1;}
			}
			else if (a==49){     //VFSus
				ltf_params[a]=ltf_params[a]+10; 
			}
		} 

			//Send new parameter values into code
			//metapopulation one
			Params.FITINIT[1][0] = ltf_params[0]; //initS
			Params.FITINIT[1][1] = ltf_params[1]; //initS
			Params.FITINIT[1][2] = ltf_params[2]; //initS
			Params.FITINIT[1][3] = ltf_params[3]; //initS
			//Params.FITINIT[1][4] = ltf_params[4]; //initV
			//Params.FITINIT[1][5] = ltf_params[5]; //initV
			//Params.FITINIT[1][6] = ltf_params[6]; //initV
			//Params.FITINIT[1][7] = ltf_params[7]; //initV
			Params.FITINIT[1][8] = ltf_params[8]; //initR
			//Params.FITINIT[1][9] = ltf_params[8]; //initR //same R across all sites
			//Params.FITINIT[1][10] = ltf_params[8]; //initR
			//Params.FITINIT[1][11] = ltf_params[8]; //initR
			Params.FITINIT[1][9] = ltf_params[9]; //initR
			Params.FITINIT[1][10] = ltf_params[10]; //initR
			Params.FITINIT[1][11] = ltf_params[11]; //initR

			//metapopulation two
			Params.FITINIT[2][0] = ltf_params[12]; //initS
			Params.FITINIT[2][1] = ltf_params[13]; //initS
			Params.FITINIT[2][2] = ltf_params[14]; //initS
			Params.FITINIT[2][3] = ltf_params[15]; //initS
			//Params.FITINIT[2][4] = ltf_params[16]; //initV
			//Params.FITINIT[2][5] = ltf_params[17]; //initV
			//Params.FITINIT[2][6] = ltf_params[18]; //initV
			//Params.FITINIT[2][7] = ltf_params[19]; //initV
			//Params.FITINIT[2][8] = ltf_params[8]; //initR //same R across all sites
			//Params.FITINIT[2][9] = ltf_params[8]; //initR
			//Params.FITINIT[2][10] = ltf_params[8]; //initR
			//Params.FITINIT[2][11] = ltf_params[8]; //initR
			Params.FITINIT[2][8] = ltf_params[20]; //initR
			Params.FITINIT[2][9] = ltf_params[21]; //initR
			Params.FITINIT[2][10] = ltf_params[22]; //initR
			Params.FITINIT[2][11] = ltf_params[23]; //initR

			//metapopulation three
			Params.FITINIT[3][0] = ltf_params[24]; //initS
			Params.FITINIT[3][1] = ltf_params[25]; //initS
			Params.FITINIT[3][2] = ltf_params[26]; //initS
			Params.FITINIT[3][3] = ltf_params[27]; //initS
			//Params.FITINIT[3][4] = ltf_params[28]; //initV
			//Params.FITINIT[3][5] = ltf_params[29]; //initV
			//Params.FITINIT[3][6] = ltf_params[30]; //initV
			//Params.FITINIT[3][7] = ltf_params[31]; //initV
			//Params.FITINIT[3][8] = ltf_params[8]; //initR
			//Params.FITINIT[3][9] = ltf_params[8]; //initR
			//Params.FITINIT[3][10] = ltf_params[8]; //initR
			//Params.FITINIT[3][11] = ltf_params[8]; //initR
			Params.FITINIT[3][8] = ltf_params[32]; //initR
			Params.FITINIT[3][9] = ltf_params[33]; //initR
			Params.FITINIT[3][10] = ltf_params[34]; //initR
			Params.FITINIT[3][11] = ltf_params[35]; //initR

			//metapopultion four
			Params.FITINIT[4][0] = ltf_params[36]; //initS
			Params.FITINIT[4][4] = ltf_params[37]; //initV
			//Params.FITINIT[4][8] = ltf_params[8]; //initR
			Params.FITINIT[4][8] = ltf_params[38]; //initR

			//metapopultion five
			Params.FITINIT[5][0] = ltf_params[39]; //initS
			Params.FITINIT[5][4] = ltf_params[40]; //initV
			//Params.FITINIT[5][8] = ltf_params[8]; //initR
			Params.FITINIT[5][8] = ltf_params[41]; //initR

			//metapopultion six
			Params.FITINIT[6][0] = ltf_params[42]; //initS
			Params.FITINIT[6][4] = ltf_params[43]; //initV
			//Params.FITINIT[6][8] = ltf_params[8]; //initR
			Params.FITINIT[6][8] = ltf_params[44]; //initR

			//dispersal parameters
			Params.con_mrg 		= ltf_params[45];
			Params.a 			= ltf_params[46];
			Params.lar_disp 	= ltf_params[47];
			//coinfection parameters
			Params.coinf_V		= ltf_params[48];
			Params.VFSus		= ltf_params[49];
			
			//-------------------MISER CALCULATE LIKELIHOOD------------------------------//
		double lhood_meta=0; double log_lhood_meta=0;
		double meta_err=0;
		double lhood_total=0;
		double lhood_reps=0;

		int calls=10;					// number of stochastic simulations for each parameter and IC set

		size_t dim;

		//for(j=1; j<=DATA_SETS; j++){
		for(j=1; j<2; j++){
			Params.j = j;

			dim = 48*2; //eventually need dim to be bigger //right now same stoch for each metapop

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

			//fprintf(fpl, "For dataset %i, lhood = %lf\t, err = %lf\n", j, lhood_meta, meta_err);

			log_lhood_meta = log(lhood_meta)-lhood_adj; //convert back to log likelihood
		}//j 

		if (log_lhood_meta>localmax_lhood){ //compare likelihood //sum - one you just generated //local max - best you've seen
			localmax_lhood=log_lhood_meta;
			//printf("Local max lhood = %lf", localmax_lhood);
			for (c=0;c<num_ltfparams;c++){
				localmax_params[c]=ltf_params[c]; //save best param set from each individual search
			}
		}
	}  //best param set from within searches
	for (c=0;c<num_ltfparams;c++){
		ltf_params[c]=localmax_params[c];
	}
	maxlhood=localmax_lhood;
	//fprintf(fpl, "a = %i\t, maxlhood = %lf\n", a, maxlhood);
	a++; //move to next parameter
	} //a
}
fclose(fpl);
//free_i3tensor(Params.EXPDATA,0,DATA_SETS,0,MAX_WEEKS,0,3);
return 0;
}
