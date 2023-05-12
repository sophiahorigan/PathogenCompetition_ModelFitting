int inputdata(void *Paramstuff)
{
#define MAX_WEEKS 100	// larger than the number of weeks in any data set
#define MAX_WEEKS2 1000	// larger than the number of weeks in any data set


STRUCTURE* Params;
Params = (STRUCTURE*) Paramstuff;
// loads the data into a matrix and finds the number of weeks in the data set
int Sdata[MAX_WEEKS]; int Vdata[MAX_WEEKS]; int Fdata[MAX_WEEKS]; int FVdata[MAX_WEEKS]; int Ddata[MAX_WEEKS]; int Cdata[MAX_WEEKS]; int D2data[MAX_WEEKS];
int Ddata2[MAX_WEEKS2]; double Rain[MAX_WEEKS2]; double MaxT[MAX_WEEKS2]; double MinT[MAX_WEEKS2]; double AveT[MAX_WEEKS2]; double MaxRH[MAX_WEEKS2]; double MinRH[MAX_WEEKS2]; double AveRH[MAX_WEEKS2];
//double fakeday[SIMU]; double fakerain[SIMU]; double fakemaxt[SIMU]; double fakeavet[SIMU]; double fakerh[SIMU];
int weeks;	int i; int j; int q;
int num_weeks[DATA_SETS+1];			// used for output to file
int num_weeks2[DATA_SETS+1];			//CK// used for output to file
int num_weeks3[DATA_SETS+1];			//CK// used for output to file
int total_days=0;					// the number of days summed over all data sets (for MISER)

int d1[MAX_WEEKS]; int d2[MAX_WEEKS]; int d3[MAX_WEEKS]; int d4[MAX_WEEKS]; //distance array input
double dp1[MAX_WEEKS]; double dp2[MAX_WEEKS]; double dp3[MAX_WEEKS]; double dp4[MAX_WEEKS]; //prob of larval disp 

//SH Need to figure out
//Params->DATA = i3tensor(0,20,0,MAX_WEEKS,0,5);
//Params->EXPDATA = i3tensor(0,20,0,MAX_WEEKS,0,5);  //CK// May need to check this.  Not sure what i3tensor does...
//Params->WDATA = i3tensor(0,20,0,MAX_WEEKS2,0,8);  //SH// Need to ensure this is correct

//printf("just after WDATA...\n");
//Params->CCDATA = d3tensor(0,100,0,MAX_WEEKS2,0,4);  //CK// May need to check this.  Not sure what i3tensor does...
//JL: Change the second number of d3tensor (=number of years)

double rain;
double maxT;
double aveT;
double minRH;

int FlagF;

char *file;
char *file_name="DATA_"; //1-3 EPI, 4-6 OBS
//1 block 1, 2 block 2, 3 block 3, 4 jhn, 5 rob, 6 ysn
char *file_name2="KBS1_weatherdaily";  //SH weather data for one site
char *file_name3="distance_"; 
char *file_name4="distprob_"; 

char *file_type=".txt";

char *code;
char *code_name="ftp";

char numbs[5];
/*------------------------------- Data Sets ---------------------------------*/
/* -------- SH Prob of Distorted Dispersal ------- */

for(j=1;j<=NUM_METASUB;j++){ //Three Blocks with distance data
	weeks=0;	i=0;	FlagF=0;	
	FILE *ftp_data;

	sprintf(numbs, "%d", j);

	file = (char*)calloc((strlen(file_name)+strlen(file_type)+strlen(numbs)+1),sizeof(char)); //SH name multiple weather files in incrementing order
	code = (char*)calloc((strlen(code_name)+strlen(numbs)+1),sizeof(char));

	strcat(file,file_name4);
	strcat(file,numbs);
	strcat(file,file_type);

	strcat(code,code_name);
	strcat(code,numbs);

	ftp_data=fopen(file,"r");
	if (ftp_data==0)	{printf("file %d open error \n",j);		getc(stdin);	}

	while (fscanf(ftp_data,"%lf %lf %lf %lf \n",&dp1[i],&dp2[i],&dp3[i],&dp4[i])!= EOF)			{
		//printf("%i, I am here!!\n", j);
		Params->DISPROB[j][i][0]=dp1[i]; Params->DISPROB[j][i][1]=dp2[i]; Params->DISPROB[j][i][2]=dp3[i]; Params->DISPROB[j][i][3]=dp4[i];  
		//printf("%i\t %e\t %e\t %e\t %e\n",j, Params->DISPROB[j][i][0],Params->DISPROB[j][i][1], Params->DISPROB[j][i][2], Params->DISPROB[j][i][3]);
	
	weeks++; i++;
	}

fclose(ftp_data);

num_weeks3[j]=i;
}

/* -------- SH Distance Array for Blocks ------- */

for(j=1;j<=NUM_METASUB;j++){ //Three Blocks with distance data
	weeks=0;	i=0;	FlagF=0;	
	FILE *ftp_data;

	sprintf(numbs, "%d", j);

	file = (char*)calloc((strlen(file_name)+strlen(file_type)+strlen(numbs)+1),sizeof(char)); //SH name multiple weather files in incrementing order
	code = (char*)calloc((strlen(code_name)+strlen(numbs)+1),sizeof(char));

	strcat(file,file_name3);
	strcat(file,numbs);
	strcat(file,file_type);

	strcat(code,code_name);
	strcat(code,numbs);

	ftp_data=fopen(file,"r");
	if (ftp_data==0)	{printf("file %d open error \n",j);		getc(stdin);	}

	while (fscanf(ftp_data,"%i %i %i %i \n",&d1[i],&d2[i],&d3[i],&d4[i])!= EOF)			{
		//printf("%i, I am here!!\n", j);
		Params->DISTANCE[j][i][0]=d1[i]; Params->DISTANCE[j][i][1]=d2[i]; Params->DISTANCE[j][i][2]=d3[i]; Params->DISTANCE[j][i][3]=d4[i];  
		//printf("%i\t %i\t %i\t %i\t %i\n",j, Params->DISTANCE[j][i][0],Params->DISTANCE[j][i][1], Params->DISTANCE[j][i][2], Params->DISTANCE[j][i][3]);
	
	weeks++; i++;
	}

fclose(ftp_data);

num_weeks3[j]=i;
}


/* -------- SH Experimental Data ------- */
for (j=1;j<=DATA_SETS;j++)	{
	weeks=0;	i=0;	FlagF=0;
	FILE *ftp_data;

	sprintf(numbs,"%d",j); //number in .txt name (incrementing for each dataset)

	file = (char*)calloc((strlen(file_name)+strlen(file_type)+strlen(numbs)+1),sizeof(char)); //SH name multiple weather files in incrementing order
	code = (char*)calloc((strlen(code_name)+strlen(numbs)+1),sizeof(char));

	strcat(file,file_name);
	strcat(file,numbs);
	strcat(file,file_type);

	strcat(code,code_name);
	strcat(code,numbs);


	ftp_data=fopen(file,"r");
	if (ftp_data==0)	{printf("file %d open error \n",j);		getc(stdin);	}

	while (fscanf(ftp_data,"%i %i %i \n",&Sdata[i],&Vdata[i],&Fdata[i])!= EOF)			{
	//block one
		//printf("%i, I am here!!", j);
		Params->DATA[j][i][0]=Sdata[i]; Params->DATA[j][i][1]=Vdata[i]; Params->DATA[j][i][2]=Fdata[i];  

	weeks++; i++;
}

fclose(ftp_data);

num_weeks3[j]=i;

}

/* -------- SH Weather Data ------- */
for (j=1;j<=DATA_SETS_WEATHER;j++)	{
	weeks=0;	i=0;	FlagF=0;
	FILE *ftp_data;

	sprintf(numbs,"%d",j);

	file = (char*)calloc((strlen(file_name2)+strlen(file_type)+strlen(numbs)+1),sizeof(char));
	code = (char*)calloc((strlen(code_name)+strlen(numbs)+1),sizeof(char));

	strcat(file,file_name2);
	strcat(file,numbs);
	strcat(file,file_type);

	strcat(code,code_name);
	strcat(code,numbs);
//printf("within weather data sets \n");

	ftp_data=fopen(file,"r");
	//ftp_data = fopen("weather1.txt","r");
	if (ftp_data==0)	{printf("file %d open error \n",j);		getc(stdin);	}
	//else				{printf("open data %d success \n",j);	fflush(stdout);	}

	//printf("just before while statement...\n");
	while (fscanf(ftp_data,"%d %lf %lf %lf %lf %lf %lf %lf \n",&Ddata2[i],&Rain[i],&MaxT[i],&MinT[i],&AveT[i],&MaxRH[i],&MinRH[i],&AveRH[i])!= EOF)			{
		//printf("inside while statement...\n");getc(stdin);


		// j = site (loop) i = row column 1,2,3 
		Params->WDATA[j][i][0][0]=Ddata2[i]; Params->WDATA[j][i][1][0]=Rain[i]; Params->WDATA[j][i][2][0]=MaxT[i]; Params->WDATA[j][i][3][0]=MinT[i]; //TEMP
		Params->WDATA[j][i][4][0]=AveT[i]; Params->WDATA[j][i][5][0]=MaxRH[i]; Params->WDATA[j][i][6][0]=MinRH[i]; Params->WDATA[j][i][7][0]=AveRH[i]; //TEMP //SH added column to indicate year

        //printf("%lf\t %lf\n",Params->WDATA[j][i][1][0],Params->WDATA[j][i][4][0]);
		weeks++; i++;
		
	}
	fclose(ftp_data);

	num_weeks3[j]=i;
	}
}