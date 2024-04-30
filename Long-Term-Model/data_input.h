int inputdata(void *Paramstuff)
{
#define MAX_WEEKS 100	// larger than the number of weeks in any data set
#define MAX_WEEKS2 1000	// larger than the number of weeks in any data set


STRUCTURE* Params;
Params = (STRUCTURE*) Paramstuff;

int Ddata2[MAX_WEEKS2]; double Rain[MAX_WEEKS2]; double MaxT[MAX_WEEKS2]; double MinT[MAX_WEEKS2]; double AveT[MAX_WEEKS2]; double MaxRH[MAX_WEEKS2]; double MinRH[MAX_WEEKS2]; double AveRH[MAX_WEEKS2];
int weeks;	int i; int j; int q;
int num_weeks[DATA_SETS+1];			// used for output to file
int num_weeks2[DATA_SETS+1];			//CK// used for output to file
int num_weeks3[DATA_SETS+1];			//CK// used for output to file
int total_days=0;					// the number of days summed over all data sets (for MISER)

double rain;
double maxT;
double aveT;
double minRH;

int FlagF;

char *file;
char *file_name2="weather_";  

char *file_type=".txt";

char *code;
char *code_name="ftp";

char numbs[5];


/* -------- SH Weather Data ------- */
for (j=1;j<=MAX_SUBS;j++)	{
	weeks=0;	i=0;	FlagF=0;
	FILE *ftp_data;

	sprintf(numbs,"%d",j); // as is, each subpop needs its own file with its weather input

	file = (char*)calloc((strlen(file_name2)+strlen(file_type)+strlen(numbs)+1),sizeof(char));
	code = (char*)calloc((strlen(code_name)+strlen(numbs)+1),sizeof(char));

	strcat(file,file_name2);
	strcat(file,numbs);
	strcat(file,file_type);

	strcat(code,code_name);
	strcat(code,numbs);

	ftp_data=fopen(file,"r");

	if (ftp_data==0)	{printf("file %d open error \n",j);		getc(stdin);	}

	while (fscanf(ftp_data,"%d %lf %lf %lf %lf %lf %lf %lf \n",&Ddata2[i],&Rain[i],&MaxT[i],&MinT[i],&AveT[i],&MaxRH[i],&MinRH[i],&AveRH[i])!= EOF)			{

		Params->WDATA[j][i][0][0]=Ddata2[i]; Params->WDATA[j][i][1][0]=Rain[i]; Params->WDATA[j][i][2][0]=MaxT[i]; Params->WDATA[j][i][3][0]=MinT[i]; //TEMP
		Params->WDATA[j][i][4][0]=AveT[i]; Params->WDATA[j][i][5][0]=MaxRH[i]; Params->WDATA[j][i][6][0]=MinRH[i]; Params->WDATA[j][i][7][0]=AveRH[i]; //TEMP //SH added column to indicate year

		weeks++; i++;
		
	}
	fclose(ftp_data);

	num_weeks3[j]=i;
	}
}