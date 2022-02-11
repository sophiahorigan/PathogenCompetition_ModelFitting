double LHood_Meta(double *RandNumsPass,size_t dim,void *Paramstuff)
{

// --------------------------------- Set Up -------------------------------------//
STRUCTURE *Params;
Params = (STRUCTURE*) Paramstuff;

//local variables
double lhood_sub = 0;		//log likehood of subpopulation
double lhood_meta = 0;		//log likelihood of metapopulation

//dataset selection
int j = 1; 			//metapop number
Params->j = j;

//testing parameter set
// ---------------------------------------------- Testing Parameter Set -------------------------------------------------- //
//metapopulation one
//init S
/*
Params->FITINIT[1][0] = 100; Params->FITINIT[1][1] = 100; Params->FITINIT[1][2] = 100; Params->FITINIT[1][3] = 100;
//printf("DEFINTION FItINIT[1][0] = %lf\n",Params->FITINIT[1][0]);
//init V
Params->FITINIT[1][4] = 0; Params->FITINIT[1][5] = 0.2; Params->FITINIT[1][6] = 0.2; Params->FITINIT[1][7] = 0.2;
//init R
Params->FITINIT[1][8] = 0.0236; Params->FITINIT[1][9] = 0.0236; Params->FITINIT[1][10] = 0.0236; Params->FITINIT[1][11] = 0.0236;
*/
//Params->FITINIT[0] = 100; Params->FITINIT[1] = 100; Params->FITINIT[2] = 100; Params->FITINIT[3] = 100;
//printf("DEFINTION FItINIT[1][0] = %lf\n",Params->FITINIT[1][0]);
//init V
//Params->FITINIT[4] = 0; Params->FITINIT[5] = 0.2; Params->FITINIT[6] = 0.2; Params->FITINIT[7] = 0.2;
//init R
//Params->FITINIT[8] = 0.0236; Params->FITINIT[9] = 0.0236; Params->FITINIT[10] = 0.0236; Params->FITINIT[11] = 0.0236;
/*
/*
//metapopulation two
//init S
Params->FITINIT[2][0] = 100; Params->FITINIT[2][1] = 100; Params->FITINIT[2][2] = 100; Params->FITINIT[2][3] = 100;
//init V
Params->FITINIT[2][4] = 0; Params->FITINIT[2][5] = 0.2; Params->FITINIT[2][6] = 0.2; Params->FITINIT[2][7] = 0.2;
//init R
Params->FITINIT[2][8] = 0.0236; Params->FITINIT[2][9] = 0.0236; Params->FITINIT[2][10] = 0.0236; Params->FITINIT[2][11] = 0.0236;

//metapopulation three
//init S
Params->FITINIT[3][0] = 100; Params->FITINIT[3][1] = 100; Params->FITINIT[3][2] = 100; Params->FITINIT[3][3] = 100;
//init V
Params->FITINIT[3][4] = 0; Params->FITINIT[3][5] = 0.2; Params->FITINIT[3][6] = 0.2; Params->FITINIT[3][7] = 0.2;
//init R
Params->FITINIT[3][8] = 0.0236; Params->FITINIT[3][9] = 0.0236; Params->FITINIT[3][10] = 0.0236; Params->FITINIT[3][11] = 0.0236;

//metapopulation four
//init S
Params->FITINIT[4][0] = 100;
//init V
Params->FITINIT[4][4] = 0;
//init R
Params->FITINIT[4][8] = 0.0236;

//metapopulation five
//init S
Params->FITINIT[5][0] = 100;
//init V
Params->FITINIT[5][4] = 0;
//init R
Params->FITINIT[5][8] = 0.0236;

//metapopulation four
//init S
Params->FITINIT[6][0] = 100;
//init V
Params->FITINIT[6][4] = 0;
//init R
Params->FITINIT[6][8] = 0.0236;
*/
//dispersal parameters
Params->con_mrg = 0.05;
Params->a = 0.1;
Params->lar_disp = 0.05;

//coifection parameters
Params->coinf_V = 0.5;
Params->VFSus = 50;

//------------------------------ Generate Model Output ------------------------------//

DDEVF(&Params,RandNumsPass,dim,j);

//------------------------------ Calculate likelihood ------------------------------//
int m=0; int n;
if (j==1 || j==2 || j==3) { //three block sites with subpopulations
	while (m < epi_length*4){
		for (n = 0; n < epi_length; n++){
			if(Params->DATA[j][m][0] != -1){
				lhood_sub = lhood_sub + gsl_ran_multinomial_lnpdf(4, Params->MODEL[j][m], Params->DATA[j][m]);
				//printf("%lf, %i\n", Params->MODEL[j][m][0], Params->DATA[j][m][0]);
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

