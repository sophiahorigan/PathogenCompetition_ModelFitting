double LHood_Meta(double *RandNumsPass ,size_t dim ,void *Paramstuff)
{
// calls DDEVF, uses results from DDEVF to calculate and return 'hood'
STRUCTURE* Params;
Params = (STRUCTURE*) Paramstuff;

//---------------//CK// Best fit params and initial conditions from previous run //CK//-------------------------------------------------------//

//double bestparams[30]={1.0, 1.0, 0.04, 0.000241071699421562, 0, 0, 0.00962435749864498, 10, 20, 50, 0, 0.37161719994828, 0.913699399999732, 2.2223804999527, 0.945435549999967, 0, 525.015699999847, 8.32036899999904, 0.119701349994476, 267.034499999981, 7.88482749903281, 3.80285399989692, 0.070488499999861, 0.233982799999915, 7.05116449999956, 6.38002749970359, 3.54725448752468, 100.157149999888, 291.2745, 0.166585199947054};

// ------------------------------------------------------------------------------------------------------------------ //
int i=0;int ii; int jj; int k; int l;
int num_adj_pars=29;			// number of adjustable parameters //get rid of this structure, only there to make sure best pars get set
int pop;
int epi_length = 48;


//---------------------Write over the initial params with known fit params --------------------------//
/*for (k=0;k<=num_adj_pars;k++)	{
	Params->PARS[k] = bestparams[k];
	//printf("%e\n",Params.PARS[k]);
}*/


double the_outer_rim = 1e-5;

double dummy = 1.0 - the_outer_rim;

int year;

int dataset;
dataset = Params->j;

//printf("pop= %i\t year=%i\t dataset=%i\n", pop, year, dataset);
DDEVF(Params,RandNumsPass,dim,pop,48,0,year,dataset);



int m = 0; int n; double lhood_sub = 0; double lhood_meta = 0; double lhood_meta2;
if (dataset==1 || dataset==2 || dataset==3) { //three block sites with subpopulations
	while (m < epi_length*4){
		for (n = 0; n < epi_length; n++){
			//printf("mvalue=%i\t m = %i\n", m, Params->DATA[dataset][m][0]);
			if(Params->DATA[dataset][m][0] != -1){
			//if(Params->DATA[dataset][m][0] == 10000){
				//use binomial likelihood function for situations with single infection
				if(Params->DATA[dataset][m-1][1] == -2){ //virus infection
					//printf("binomial V \n");
					//virus infected data, virus infected model, total population (S+V)
					lhood_sub += log(gsl_ran_binomial_pdf(Params->DATA[dataset][m][1], Params->MODEL[dataset][m][1], Params->DATA[dataset][m][1]+Params->DATA[dataset][m][0]));
					//printf("DATA S=%i\t V=%i\t F=%i\t FV=%i\n", Params->DATA[dataset][m][0], Params->DATA[dataset][m][1], Params->DATA[dataset][m][2], Params->DATA[dataset][m][3]);
					//printf("MODEL S=%e\t V=%e\t F=%e\t FV=%e\n", Params->MODEL[dataset][m][0], Params->MODEL[dataset][m][1], Params->MODEL[dataset][m][2], Params->MODEL[dataset][m][3]);
					//printf("lhood sub = %lf\n", lhood_sub);
				}

				if(Params->DATA[dataset][m-1][1] == -3){ //fungus infection
					//printf("binomial F \n");
					//fungus infected data, fungus infected model, total population (S+F)
					lhood_sub += log(gsl_ran_binomial_pdf(Params->DATA[dataset][m][2], Params->MODEL[dataset][m][2], Params->DATA[dataset][m][2]+Params->DATA[dataset][m][0]));
					//printf("DATA S=%i\t V=%i\t F=%i\t FV=%i\n", Params->DATA[dataset][m][0], Params->DATA[dataset][m][1], Params->DATA[dataset][m][2], Params->DATA[dataset][m][3]);
					//printf("MODEL S=%e\t V=%e\t F=%e\t FV=%e\n", Params->MODEL[dataset][m][0], Params->MODEL[dataset][m][1], Params->MODEL[dataset][m][2], Params->MODEL[dataset][m][3]);
					//printf("lhood sub = %lf\n", lhood_sub);
				}

				//use multinomial for A) no infection, b) fungus and virus infection
				if(Params->DATA[dataset][m-1][1] == -1){ 
					//printf("multinomial\n");
					if(Params->MODEL[dataset][m][1] > dummy){ //if virus = 1
						Params->MODEL[dataset][m][1] -= 2*epsilon; //take 2* epsilon off
						Params->MODEL[dataset][m][0] += epsilon; //give 1 epsilon to susceptible
						Params->MODEL[dataset][m][2] += epsilon; //give 1 epsilon to fungus
						//printf("post-adjustment, V tripped. S=%e\t V=%e\t F=%e\n", Params->MODEL[dataset][m][0], Params->MODEL[dataset][m][1], Params->MODEL[dataset][m][2]);
						//getc(stdin);
					}
				
					if(Params->MODEL[dataset][m][2] > dummy){ //if fungus = 1
						Params->MODEL[dataset][m][2] -= 2*epsilon; //take 2* epsilon off
						Params->MODEL[dataset][m][0] += epsilon; //give 1 epsilon to susceptible
						Params->MODEL[dataset][m][1] += epsilon; //give 1 epsilon to virus
						//printf("post-adjustment, F tripped. S=%e\t V=%e\t F=%e\n", Params->MODEL[dataset][m][0], Params->MODEL[dataset][m][1], Params->MODEL[dataset][m][2]);
						//printf("woohoo!");
						//getc(stdin);
					}

					if(Params->MODEL[dataset][m][0] < 1 - dummy){ //if susceptible = 0
						Params->MODEL[dataset][m][0] += epsilon; //add epsilon 
						//not taken from others to prevent negative numbers
						//printf("post-adjustment, S tripped. S=%e\t V=%e\t F=%e\n", Params->MODEL[dataset][m][0], Params->MODEL[dataset][m][1], Params->MODEL[dataset][m][2]);
						//printf("woohoo!");
						//getc(stdin);
					}
					if(Params->DATA[dataset][m][0] != -1){
					//calculate likelihood
					lhood_sub += gsl_ran_multinomial_lnpdf(4, Params->MODEL[dataset][m], Params->DATA[dataset][m]);
					//printf("DATA S=%i\t V=%i\t F=%i\t FV=%i\n", Params->DATA[dataset][m][0], Params->DATA[dataset][m][1], Params->DATA[dataset][m][2], Params->DATA[dataset][m][3]);
					//printf("MODEL S=%e\t V=%e\t F=%e\t FV=%e\n", Params->MODEL[dataset][m][0], Params->MODEL[dataset][m][1], Params->MODEL[dataset][m][2], Params->MODEL[dataset][m][3]);
					//printf("lhood sub = %lf\n", lhood_sub);
					}
				}
			} 
			m++;
		} 
		//printf("DATASET %i. END OF SUBPOP. Likelihood sum for subpop = %lf\n", dataset, lhood_sub);
		//fprintf(fpl, "END OF SUBPOP. Likelihood sum for subpop = %lf\n", lhood_sub);
		lhood_meta += lhood_sub;
		n = 0;
		lhood_sub = 0;	
	}
	//printf("likelikhood for metapop %i = %lf\n", dataset, lhood_meta);
	//fprintf(fpl, "Likelihood for metapop %i = %lf\n", dataset, lhood_meta);
}

//binomial for entire dataset because only virus infection
if (dataset==5){
	for (n = 0; n < epi_length; n++){
		if(Params->DATA[dataset][n][0] != -1){
					//virus infected data, virus infected model, total population (S+V)
					lhood_meta += log(gsl_ran_binomial_pdf(Params->DATA[dataset][n][1], Params->MODEL[dataset][n][1], Params->DATA[dataset][n][1]+Params->DATA[dataset][n][0]));
					//printf("V inf = %i\t Model V inf = %lf\t total N = %i\n",Params->DATA[dataset][m][1], Params->MODEL[dataset][m][1], Params->DATA[dataset][m][1]+Params->DATA[dataset][m][0]);	
				}
	}
	//printf("likelihood for metapop %i = %lf\n", dataset, lhood_meta);
}

if (dataset==4 || dataset==6) { 
	for (n = 0; n < epi_length; n++){
		if(Params->DATA[dataset][n-1][1] == -2){ //virus infection
			lhood_meta += log(gsl_ran_binomial_pdf(Params->DATA[dataset][n][1], Params->MODEL[dataset][n][1], Params->DATA[dataset][n][1]+Params->DATA[dataset][n][0]));
		}
		if(Params->DATA[dataset][n-1][1] == -3){ //fungus infection
			lhood_meta += log(gsl_ran_binomial_pdf(Params->DATA[dataset][n][2], Params->MODEL[dataset][n][2], Params->DATA[dataset][n][1]+Params->DATA[dataset][n][0]));
		}
		if(Params->DATA[dataset][n-1][1] != -1){
				if(Params->MODEL[dataset][m][1] > dummy){ //if virus = 1
					Params->MODEL[dataset][m][1] -= 3*epsilon; //take 2* epsilon off
					Params->MODEL[dataset][m][0] += epsilon; //give 1 epsilon to susceptible
					Params->MODEL[dataset][m][2] += epsilon; //give 1 epsilon to fungus
					Params->MODEL[dataset][m][3] += epsilon; //give 1 epsilon to fungusvirus
					//printf("in virus 1");
				}
				if(Params->MODEL[dataset][m][2] > dummy){ //if fungus = 1
					Params->MODEL[dataset][m][2] -= 3*epsilon; //take 2* epsilon off
					Params->MODEL[dataset][m][0] += epsilon; //give 1 epsilon to susceptible
					Params->MODEL[dataset][m][1] += epsilon; //give 1 epsilon to virus
					Params->MODEL[dataset][m][3] += epsilon; //give 1 epsilon to fungusvirus
					//printf("in fungus 1");
				}	
				if(Params->MODEL[dataset][m][3] > dummy){ //if virus-fungus = 1
					Params->MODEL[dataset][m][3] -= 3*epsilon; //take 3* epsilon off
					Params->MODEL[dataset][m][0] += epsilon; //give 1 epsilon to susceptible
					Params->MODEL[dataset][m][1] += epsilon; //give 1 epsilon to virus
					Params->MODEL[dataset][m][2] += epsilon; //give 1 epsilon to fungus
					//printf("in virus fungus 1");
				}
				if(Params->MODEL[dataset][m][0] < 1 - dummy){ //if susceptible = 0
					Params->MODEL[dataset][m][0] += epsilon; //add epsilon
					//printf("in susceptible 0");
				}

				lhood_meta += gsl_ran_multinomial_lnpdf(4, Params->MODEL[dataset][n], Params->DATA[dataset][n]);
		}
	}
	//printf("likelihood for metapop %i = %lf\n", dataset, lhood_meta);
	//fprintf(fpl, "Likelihood for metapop %i = %lf\n", dataset, lhood_meta);
}

//save first likelihood in stochastic set as adjustment value
//save first likelihood as best

if(Params->miser_ticker==1){
	Params->lhood_adjust[dataset] = -lhood_meta;
	Params->bestlhood[dataset] = lhood_meta;
	//printf("dataset = %i\t adj = %lf\t best = %lf\n", dataset, Params->lhood_adjust[dataset], Params->bestlhood[dataset]);
}
Params->miser_ticker++;

//printf("first lhood adj = %lf\n", Params->bestlhood[dataset]);

if(lhood_meta > Params->bestlhood[dataset]){
	//printf("better one detected\n");
	//printf("dataset = %i\t better lhood = %lf\t old lhood = %lf\n", dataset, lhood_meta, Params->bestlhood[dataset]);
	//Params->miser2_flag++; //if adding all
	Params->miser2_flag = 1;
	Params->bestlhood[dataset] = lhood_meta; //only save best on the second round so it isn't stuck in an infinite loop
	//printf("better lhood found! = %lf\n", Params->bestlhood[dataset]);
	//printf("tripped in lhoodmeta\n");
	//printf("flag in loop = %i\n", Params->miser2_flag);
}

//printf("lhood = %lf\n", lhood_meta);
//printf("best lhood = %lf\n", Params->bestlhood[dataset]);
//printf("flag = %i\t, lhood = %e\n", Params->miser2_flag, lhood_meta);
//printf("flag out of loop = %i\n", Params->miser2_flag);

lhood_meta2 = lhood_meta + Params->lhood_adjust[dataset];


//printf("lhood = %lf\t adj = %lf\t post adj = %lf\n", lhood_meta, Params->lhood_adjust[dataset], lhood_meta2);

//printf("miser ticker = %i\t miser flag = %i\n", Params->miser_ticker, Params->miser2_flag);

lhood_meta2 = exp(lhood_meta2);

//printf("exp lhood adj = %lf\n", lhood_meta2);
//printf("done\n");
return lhood_meta2;
}
