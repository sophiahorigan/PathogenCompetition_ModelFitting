double LHood_Meta(double *RandNumsPass,size_t dim,void *Paramstruct)
{

// --------------------------------- Set Up -------------------------------------//
STRUCTURE* Params;
Params = (STRUCTURE*) Paramstruct;

//local variables
int j = Params->j; 			//metapop number
double lhood_sub = 0;		//log likehood of subpopulation
double lhood_meta = 0;		//log likelihood of metapopulation


//------------------------------ Generate Model Output ------------------------------//

DDEVF(&Params,RandNumsPass,dim,j);

//------------------------------ Calculate likelihood ------------------------------//

if (j==1 || j==2 || j==3) { //three block sites with subpopulations
	while (m < epi_length*4){
		for (n = 0; n < epi_length; n++){
			if(Params->DATA[j][m][0] != -1){
				lhood_sub = lhood_sub + gsl_ran_multinomial_lnpdf(4, Params->MODEL[j][m], Params->DATA[j][m]);
				//printf("%lf\n", lhood_sub);
			} 
			m++;
		}
		//printf("END OF SUBPOP. Likelihood sum for subpop = %lf\n", lhood_sub);
		lhood_meta = lhood_meta + lhood_sub;
		n = 0;
		lhood_sub = 0;
			
	}
	//printf("Likelihood for metapop %i = %lf\n", j, lhood_meta);
	}
if (j==4 || j==5 || j==6) { //three observational sites with no subpopulations
	for (n = 0; n < epi_length; n++){
		if(Params->DATA[j][n][0] != -1){
			lhood_meta = lhood_meta + gsl_ran_multinomial_lnpdf(4, Params->MODEL[j][n], Params->DATA[j][n]);
			//printf("%lf\n", lhood_meta);
		}
	}
//printf("Likelihood for metapop %i = %lf\n", j, lhood_meta);
}

lhood_meta = lhood_meta + 700;
lhood_meta = exp(lhood_meta);

//printf("made it into lhood_meta, lhood = %lf", lhood_meta);
return lhood_meta;
}

