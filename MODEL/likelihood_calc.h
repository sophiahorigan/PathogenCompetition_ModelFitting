double likelihood_calc(double *RandNumsPass ,size_t dim ,void *Paramstuff)
{
// calls DDEVF, uses results from DDEVF to calculate and return 'hood'
STRUCTURE* Params;
Params = (STRUCTURE*) Paramstuff;

int pop;
int epi_length = 48;

int year;

int dataset;
dataset = Params->j;

//printf("pop= %i\t year=%i\t dataset=%i\n", pop, year, dataset);

DDEVF(Params,RandNumsPass,dim,pop,48,0,year,dataset);


int m = 0; int n; int k;
double tmp;
double lhood_meta=0; //since we start indexing datasets at 1 instead of 0
double lhood_meta2=0;

if (dataset==1 || dataset==2 || dataset==3) //three block sites with subpopulations
{ 
	while (m < epi_length*4)
	{
		k = 0; //reset k for each subpopulation
		for (n = 0; n < epi_length; n++)
		{
			if (Params->DATA[dataset][m][0] != -1) //for days with both model and field data
			{
				 tmp = gsl_ran_multinomial_lnpdf(3, Params->MODEL[dataset][m], Params->DATA[dataset][m]);
				//printf("DATA S=%i\t V=%i\t F=%i\n", Params->DATA[dataset][m][0], Params->DATA[dataset][m][1], Params->DATA[dataset][m][2]);
				//printf("MODEL S=%e\t V=%e\t F=%e\n", Params->MODEL[dataset][m][0], Params->MODEL[dataset][m][1], Params->MODEL[dataset][m][2]);
				//printf("lhood sub[%i][%i] = %lf\n", dataset, k, Params->lhood_sub[dataset][k]);

				if(tmp)
				{
					Params->lhood_point[dataset][k] += exp(tmp); // average over likelihood not log likelihood, easier to exp here than main .c
					lhood_meta += tmp;			
				} else {
					Params->lhood_point[dataset][k] = exp(-700); 
					lhood_meta -= 700;
				}
				k++; //index for days with data
			} 
			m++;
		} 
	}
}

// observational data //not updated
/*
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
*/


//save first likelihood in stochastic set as adjustment value
//save first likelihood as best


if(Params->miser_ticker==1){
	Params->lhood_adjust[dataset] = -lhood_meta;
	Params->bestlhood[dataset] = lhood_meta;
	//printf("SET ADJ: dataset = %i\t adj = %lf\t best = %lf\n", dataset, Params->lhood_adjust[dataset], Params->bestlhood[dataset]);
}
Params->miser_ticker++; 


if(lhood_meta > (10 + Params->bestlhood[dataset])){ //if it's 10 points greater or more //avoids re-dos for small gains
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

//printf("pre adj = %lf\n", lhood_meta);
//printf("adj = %lf\n", Params->lhood_adjust[dataset]);
lhood_meta2 = lhood_meta + Params->lhood_adjust[dataset];
//printf("post adj = %lf\n", lhood_meta2);
/*
if(lhood_meta2 > 750 || lhood_meta2 < -750){
	printf("bad lhood tripped! assigning 600\n");
	lhood_meta2 = 600;
}*/

//printf("j = %i\t lhood = %lf\t adj = %lf\t post adj = %lf\n", dataset, lhood_meta, Params->lhood_adjust[dataset], lhood_meta2);

//printf("miser ticker = %i\t miser flag = %i\n", Params->miser_ticker, Params->miser2_flag);


//printf("lhood meta2 [%i] = %lf\n", dataset, lhood_meta2);

lhood_meta2 = exp(lhood_meta2);

//printf("exp Lhood meta2 [%i] = %lf\n", dataset, lhood_meta2);

return lhood_meta2;
}
