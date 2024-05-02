int inputdata(void *Paramstuff)
{
#define MAX_WEEKS 100	// larger than the number of weeks in any data set
#define MAX_WEEKS2 1000	// larger than the number of weeks in any data set

STRUCTURE* Params;
Params = (STRUCTURE*) Paramstuff;

// loads the data into a matrix and finds the number of weeks in the data set
 int Ddata[MAX_WEEKS]; 
int D2data[MAX_WEEKS];
int Ddata2[MAX_WEEKS2]; double Rain[MAX_WEEKS2]; double MaxT[MAX_WEEKS2]; double MinT[MAX_WEEKS2]; double AveT[MAX_WEEKS2]; double MaxRH[MAX_WEEKS2]; double MinRH[MAX_WEEKS2]; double AveRH[MAX_WEEKS2];
double fakeday[SIMU]; double fakerain[SIMU]; double fakemaxt[SIMU]; double fakeavet[SIMU]; double fakerh[SIMU];
int weeks;	int i; int j; int q;
int num_weeks[DATA_SETS+1];			// used for output to file
int num_weeks2[DATA_SETS+1];			//CK// used for output to file
int num_weeks3[DATA_SETS+1];			//CK// used for output to file
int total_days=0;					// the number of days summed over all data sets (for MISER)

//Params->WDATA = i3tensor(0,20,0,MAX_WEEKS2,0,8);  //CK// May need to check this.  Not sure what i3tensor does...

//printf("just after WDATA...\n");
Params->CCDATA = d3tensor(0,1000,0,MAX_WEEKS2,0,4);  //CK// May need to check this.  Not sure what i3tensor does...
//JL: Change the second number of d3tensor (=number of years)

double rain;
double maxT;
double aveT;
double minRH;

int FlagF;

char *file_name4="weather_station";  //CK// name for inputing the rain data
char *file_type=".txt";

char *code;
char *code_name="ftp";

char numbs[5];

/*-------------------------------Realistic Weather Data Sets ---------------------------------*/
rawweather = (double (*)[4][states])malloc(100000*4*sizeof(double));
for (j=0;j<states;j++)	{

	weeks=0;	i=0;	FlagF=0; 	q=0;
	FILE *ftp_data;

	sprintf(numbs,"%d",j);

	file = (char*)calloc((strlen(file_name4)+strlen(file_type)+strlen(numbs)+1),sizeof(char));
	code = (char*)calloc((strlen(code_name)+strlen(numbs)+1),sizeof(char));

	strcat(file,file_name4);
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
	while (fscanf(ftp_data,"%lf %lf %lf %lf \n",&rain,&minRH,&maxT,&aveT)!= EOF){

	    rawweather[i][0][j]=rain;
        rawweather[i][1][j]=minRH*100;
        rawweather[i][2][j]=maxT;
        rawweather[i][3][j]=aveT;
        //printf("%lf\t %lf\t %lf\t %lf\n",rawweather[i][0][j],rawweather[i][1][j],rawweather[i][2][j],rawweather[i][3][j]);

		i++;


		//printf("weeks: %d i:%d \n",weeks,i);

	}
    wlast[j]=i;
    //printf("%d\t",wlast[j]);
	fclose(ftp_data);

	}


/*----------------------------end of data sets------------------------------*/
FILE *fp_weeks;
fp_weeks=fopen("weeks.dat","w");

for (j=1;j<=DATA_SETS;j++)	{
	fprintf(fp_weeks,"%d\t",num_weeks[j]);
}
fclose(fp_weeks);

return 0;
}
