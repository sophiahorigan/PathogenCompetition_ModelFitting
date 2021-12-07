int inputdata(void *Paramstuff)
{
#define MAX_WEEKS 100	// larger than the number of weeks in any data set
#define MAX_WEEKS2 1000	// larger than the number of weeks in any data set


STRUCTURE* Params;
Params = (STRUCTURE*) Paramstuff;
// loads the data into a matrix and finds the number of weeks in the data set
int Sdata[MAX_WEEKS]; int Vdata[MAX_WEEKS]; int Fdata[MAX_WEEKS]; int FVdata[MAX_WEEKS]; int Ddata[MAX_WEEKS]; int Cdata[MAX_WEEKS]; int D2data[MAX_WEEKS];
int Ddata2[MAX_WEEKS2]; double Rain[MAX_WEEKS2]; double MaxT[MAX_WEEKS2]; double MinT[MAX_WEEKS2]; double AveT[MAX_WEEKS2]; double MaxRH[MAX_WEEKS2]; double MinRH[MAX_WEEKS2]; double AveRH[MAX_WEEKS2];
double fakeday[SIMU]; double fakerain[SIMU]; double fakemaxt[SIMU]; double fakeavet[SIMU]; double fakerh[SIMU];
int weeks;	int i; int j; int q;
int num_weeks[DATA_SETS+1];			// used for output to file
int num_weeks2[DATA_SETS+1];			//CK// used for output to file
int num_weeks3[DATA_SETS+1];			//CK// used for output to file
int total_days=0;					// the number of days summed over all data sets (for MISER)
Params->DATA = i3tensor(0,20,0,MAX_WEEKS,0,5); //SH could use i3tensor 
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
char *file_name="JHN_Co"; // SH modified for one observational site
char *file_name2="KBS1_weatherdaily";  //SH weather data for one site
// char *file_name3="DEMOweather";  //CK// name for inputing the rain data
// char *file_name4="CDO_Roscommon_APT_long";  //CK// name for inputing the rain data
// char *fakeweather="fakeweather";
char *file_type=".txt";

char *code;
char *code_name="ftp";

char numbs[5];
/*------------------------------- Data Sets ---------------------------------*/
/* -------- SH Observational Data ------- */
/* //SH bring back if you ever decide not to just hard code.
//SH when adding in more datasets, increase DATA_SETS value and that will loop through all
for (j=1;j<=DATA_SETS;j++)	{
	weeks=0;	i=0;	FlagF=0;
	FILE *ftp_data;

//printf("just before numbs...\n");
	sprintf(numbs,"%d",j);

	file = (char*)calloc((strlen(file_name)+strlen(file_type)+strlen(numbs)+1),sizeof(char)); //SH name multiple weather files in incrementing order
	code = (char*)calloc((strlen(code_name)+strlen(numbs)+1),sizeof(char));

	strcat(file,file_name);
	strcat(file,numbs);
	strcat(file,file_type);

	strcat(code,code_name);
	strcat(code,numbs);

//printf("just before fopen...\n");

	ftp_data=fopen(file,"r");
	if (ftp_data==0)	{printf("file %d open error \n",j);		getc(stdin);	}
	//else				{printf("open data %d success \n",j);	fflush(stdout);	}

	while (fscanf(ftp_data,"%d %d %d %d\n",&Sdata[i],&Vdata[i],&Fdata[i], &FVdata[i], &Ddata[i])!= EOF)			{ //SH when dealing with years add another input
		Params->DATA[j][i][0]=Sdata[i]; Params->DATA[j][i][1]=Vdata[i]; Params->DATA[j][i][2]=Fdata[i]; Params->DATA[j][i][3]=FVdata[i]; Params->DATA[j][i][4]=Ddata[i];  
		//printf("FERALS: i=%d\t pop:%d\t healthy:%d\t viral:%d\t fungal:%d\t week:%d\t week2:%d\n",i,j,Params->DATA[j][i][0],Params->DATA[j][i][1],Params->DATA[j][i][2], Params->DATA[j][i][3], Params->DATA[j][i][4]);
		//if ((Fdata[i]>0) && (FlagF<1))	{
		//	FlagF=2;
		//	Params->DAY_F[j]=7*i;
		//}

		weeks++; i++;
	}
	fclose(ftp_data);

	Params->DAY_F[j]=0.0;  //CK// making resting spores start blooming on first day

	Params->MAXT[j]=7*(weeks-1);				// number of days
	total_days += Params->MAXT[j];
	//printf("data set %d has %d days\t total=%d\n",j,Params->MAXT[j],total_days);getc(stdin);
	num_weeks[j]=i;

	//if (FlagF==0)	Params->DAY_F[j]=Params->MAXT[j];
}
//printf("Params->DATA[1][0][4]=%d\n",Params->DATA[1][0][4]);
//getc(stdin);

//printf("just before Experimental Data...\n");getc(stdin);
*/


/*-------------------------------Weather Data Sets ---------------------------------*/
/* -------- SH Weather Data ------- */
for (j=1;j<=DATA_SETS;j++)	{
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



