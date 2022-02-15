double LHood_Meta(double RandNumsPass[] ,size_t dim ,void *Paramstuff)
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

double distance_array[6] = {5, 5, 5, 5, 5, 5};

// ------------------------------------------------------------------------------------------------------------------ //
int i=0; int j;int ii; int jj; int k; int l;
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
double sdensity;
double fdensity;
double vdensity;

//INITIAL CONDITIONS
VFSus=0.01; //SH random pick 
sdensity=100; //SH random pick 
fdensity=0.026; //SH from literature
vdensity=0.01; //SH guesstimate

Params->PARS[30+pop]=sdensity; 
VPass=vdensity;
Params->PARS[50+pop]=fdensity;


for (j=1;j<=DATA_SETS;j++)	{
//for (j=1;j<2;j++)	{

	//printf("THIS IS J IN MAIN LOOP = %i\n", j);

DDEVF(Params,RandNumsPass,dim,pop,48,0,year,j);

int m = 0; int n; double lhood_sub = 0; double lhood_meta = 0;
	if (j==1 || j==2 || j==3) { //three block sites with subpopulations
		while (m < epi_length*4){
			for (n = 0; n < epi_length; n++){
				if(Params->DATA[j][m][0] != -1){
					lhood_sub = lhood_sub + gsl_ran_multinomial_lnpdf(4, Params->MODEL[j][m], Params->DATA[j][m]);
					printf("%lf\n", lhood_sub);
				} 
				m++;
			}
			printf("END OF SUBPOP. Likelihood sum for subpop = %lf\n", lhood_sub);
			lhood_meta = lhood_meta + lhood_sub;
			n = 0;
			lhood_sub = 0;
				
		}
		printf("Likelihood for metapop %i = %lf\n", j, lhood_meta);
		}
	if (j==4 || j==5 || j==6) { //three observational sites with no subpopulations
		for (n = 0; n < epi_length; n++){
			if(Params->DATA[j][n][0] != -1){
				lhood_meta = lhood_meta + gsl_ran_multinomial_lnpdf(4, Params->MODEL[j][n], Params->DATA[j][n]);
				printf("%lf\n", lhood_meta);
			}
		}
	printf("Likelihood for metapop %i = %lf\n", j, lhood_meta);
	}
}


/*char name1[50];
sprintf(name1, "sim_output_");
fp1=fopen(name1,"a+"); //or a+, not sure which
DDEVF(&Params,r_seed,dim,pop,48,0,year);
fclose(fp1);*/


//**************SH prints content of sim_output******************//
/*
int loop3, loop4;
for(loop3 = 0; loop3 < 192; loop3++){
	for (loop4 = 0; loop4 < 4; loop4++){
		printf("sim_output[%i][%i] = %e\n", loop3, loop4, sim_output[loop3][loop4]);
	}	
}
*/

//**************SH prints output at end of week****************//
   // FILE *fp;
   // char name[50];
    // sprintf(name,"typethree_Vall_Cthreeweek_fut_immi_VFSus_alt_%lf_1.txt",VFSusF[bbf]);
    //sprintf(name,"fv_bf_%f_row_%d_col_%d.txt",bfungus[bbf],row,col);
	//sprintf(name, "JHN_KBS1daily_15_10000_0.026_0.2"); //SH attempt at naming output based on above lines

   // fp=fopen(name,"a+");    //a+ for reading and appending! Could only get the output of the last year with w+.



	// INFECTED = 1.0 - (Params.survivors/Params.total); //SH need to modify to add two infection classes (V/F)

	//printf("%lf\t %lf\t %lf\t %lf\t %lf\n", Params.PARS[30+pop], Params.PARS[50+pop], INFECTED, Params.survivors, Params.total);
	// fprintf(fp,"%d\t %e\t %e\t %e\t %e\t %e\t %e\t %e\n",year,Params.PARS[30+pop],Params.PARS[50+pop],VPass,InfFungusNext,InfFungusEnd,InfVirusNext,InfVirusEnd); //After dispersal
	//year, initial s, initial f, initial v, end f to next epi, f at end, v to next epi, v at end

    //printf("After an epizootic: %e\t %e\t %e\n",SusEnd,InfFungusEnd,InfVirusEnd); //getc(stdin);
    //printf("SusEnd=%e, N*(1-if-iv)=%e\n",SusEnd,sdensity-InfFungusEnd-InfVirusEnd);
    //double stoch=exp(gsl_ran_gaussian(r_seed,0.25));
    //double tempor=sdensity;
    //printf("%f\n",SusEnd);
    //sdensity=fecundity*SusEnd*(1-(2*preda*predb*sdensity)/(predb*predb+sdensity*sdensity))+1e-5;
    
return 0;
}
