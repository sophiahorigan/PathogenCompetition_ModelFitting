double Hood_Pops(double *RandNumsPass,size_t dim,void *Paramstuff)
{

STRUCTURE* Params;
Params = (STRUCTURE*) Paramstuff;


//------------------------------ Calculate likelihood ------------------------------//

int j = Params->j;
int pop = Params->pop;

DDEVF(&Params,r_seed,dim,pop,48,0,j);

int m = 0; int n; double lhood_sub = 0; double lhood_meta = 0;
	if (j==1 || j==2 || j==3) { //three block sites with subpopulations
		while (m < epi_length*4){
			for (n = 0; n < epi_length; n++){
				if(Params.DATA[j][m][0] != -1){
					lhood_sub = lhood_sub + gsl_ran_multinomial_lnpdf(4, Params.MODEL[j][m], Params.DATA[j][m]);
					printf("%lf\n", lhood_sub);
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
			if(Params.DATA[j][n][0] != -1){
				lhood_meta = lhood_meta + gsl_ran_multinomial_lnpdf(4, Params.MODEL[j][n], Params.DATA[j][n]);
				printf("%lf\n", lhood_meta);
			}
		}
	//printf("Likelihood for metapop %i = %lf\n", j, lhood_meta);
	}


    //double tempor=sdensity;
    //printf("%f\n",SusEnd);

	//---------Predation----------------//
	//SH do I want this on?
    //sdensity=fecundity*SusEnd*(1-(2*preda*predb*sdensity)/(predb*predb+sdensity*sdensity))+1e-5;


  //double stoch=exp(gsl_ran_gaussian(r_seed,0.25));  

//free_i3tensor(Params.EXPDATA,0,DATA_SETS,0,MAX_WEEKS,0,3);
return lhood_meta;
}

