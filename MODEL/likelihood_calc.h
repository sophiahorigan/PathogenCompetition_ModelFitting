double likelihood_calc(double *RandNumsPass ,size_t dim ,void *Paramstuff)
{
// calls DDEVF, uses results from DDEVF to calculate and return 'hood'
STRUCTURE* Params;
Params = (STRUCTURE*) Paramstuff;

int i=0;int ii; int jj; int k; int l;
int pop;
int epi_length = 48; //CHANGE

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
			if(Params->DATA[dataset][m][0] != -1){
				//calculate likelihood
				lhood_sub += gsl_ran_multinomial_lnpdf(3, Params->MODEL[dataset][m], Params->DATA[dataset][m]);
				//printf("DATA S=%i\t V=%i\t F=%i\n", Params->DATA[dataset][m][0], Params->DATA[dataset][m][1], Params->DATA[dataset][m][2]);
				//printf("MODEL S=%e\t V=%e\t F=%e\n", Params->MODEL[dataset][m][0], Params->MODEL[dataset][m][1], Params->MODEL[dataset][m][2]);
				//printf("lhood sub = %lf\n", lhood_sub);
			} 
			m++;
		} 
		//printf("DATASET %i\t. Likelihood sum for subpop = %lf\n", dataset, lhood_sub);
		lhood_meta += lhood_sub;
		n = 0;
		lhood_sub = 0;	
	}
	//printf("likelikhood for metapop %i = %lf\n", dataset, lhood_meta);
}

//binomial for entire dataset because only virus infection
if (dataset==5){
	for (n = 0; n < epi_length; n++){
		if(Params->DATA[dataset][n][0] != -1){
			//virus infected data, virus infected model, total population (S+V)
			lhood_meta += log(gsl_ran_binomial_pdf(Params->DATA[dataset][n][1], Params->MODEL[dataset][n][1], Params->DATA[dataset][n][1]+Params->DATA[dataset][n][0]));
			//printf("dataset = %i\t lhood = %lf\n", dataset, lhood_meta);
		}
	}
	//printf("likelihood for metapop %i = %lf\n", dataset, lhood_meta);
}

if (dataset==4 || dataset==6) { 
	for (n = 0; n < epi_length; n++){
		if(Params->DATA[dataset][n][0] != -1){
			lhood_meta += gsl_ran_multinomial_lnpdf(3, Params->MODEL[dataset][n], Params->DATA[dataset][n]);
			//printf("dataset = %i\t lhood = %lf\n", dataset, lhood_meta);
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

//printf("lhood meta 2 = %lf\n", lhood_meta2);

lhood_meta2 = lhood_meta + Params->lhood_adjust[dataset];


//printf("lhood = %lf\t adj = %lf\t post adj = %lf\n", lhood_meta, Params->lhood_adjust[dataset], lhood_meta2);

//printf("miser ticker = %i\t miser flag = %i\n", Params->miser_ticker, Params->miser2_flag);

lhood_meta2 = exp(lhood_meta2);
//printf("exp lhood adj = %lf\n", lhood_meta2);
//printf("done\n");

return lhood_meta2;
}
