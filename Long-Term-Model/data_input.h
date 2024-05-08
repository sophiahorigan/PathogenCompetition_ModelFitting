int inputdata(void *Paramstuff)
{
#define MAX_WEEKS 100	// larger than the number of weeks in any data set
#define MAX_WEEKS2 1000	// larger than the number of weeks in any data set

STRUCTURE* Params;
Params = (STRUCTURE*) Paramstuff;

// loads the data into a matrix and finds the number of weeks in the data set

double Rain[MAX_WEEKS2]; double MaxT[MAX_WEEKS2]; double MinT[MAX_WEEKS2]; double AveT[MAX_WEEKS2]; double MaxRH[MAX_WEEKS2]; double MinRH[MAX_WEEKS2]; double AveRH[MAX_WEEKS2];
int year;int i; int j; 

double rain;
double maxT;
double aveT;
double minRH;

int FlagF;

char *file;
char *file_name1 = "weather_hist";  
char *file_name2 = "weather_cc";  
char *file_type = ".txt"; 

char *code;
char *code_name="ftp";

char numbs[5];

/*------------------------------- Historical Weather ---------------------------------*/
for (j=0; j<Params->num_sub; j++)
{
	year=0;	i=0; FlagF=0;
	FILE *ftp_data;

	sprintf(numbs,"%d",j);

	file = (char*)calloc((strlen(file_name1)+strlen(file_type)+strlen(numbs)+1),sizeof(char));
	code = (char*)calloc((strlen(code_name)+strlen(numbs)+1),sizeof(char));

	strcat(file,file_name1);
	strcat(file,numbs);
	strcat(file,file_type);

	strcat(code,code_name);
	strcat(code,numbs);

	ftp_data = fopen(file,"r");

	if (ftp_data==0)	{printf("file %d open error \n",j);		getc(stdin);	}

	while (fscanf(ftp_data, "%lf %lf %lf %lf \n", &rain, &minRH, &maxT, &aveT) != EOF){

	    Params->HIST_WEATHER[year][j][i][0]=rain;
        Params->HIST_WEATHER[year][j][i][1]=minRH*100;
        Params->HIST_WEATHER[year][j][i][2]=maxT;
        Params->HIST_WEATHER[year][j][i][3]=aveT;

		i++;

		if (i == 364){
			year++;
			i = 0;
		}

	}
	fclose(ftp_data);
}

/*------------------------------- Climate Change Weather ---------------------------------*/
for (j=0; j<Params->num_sub; j++)
{
	year=0;	i=0; FlagF=0;
	FILE *ftp_data;

	sprintf(numbs,"%d",j);

	file = (char*)calloc((strlen(file_name2)+strlen(file_type)+strlen(numbs)+1),sizeof(char));
	code = (char*)calloc((strlen(code_name)+strlen(numbs)+1),sizeof(char));

	strcat(file,file_name2);
	strcat(file,numbs);
	strcat(file,file_type);

	strcat(code,code_name);
	strcat(code,numbs);

	ftp_data = fopen(file,"r");

	if (ftp_data==0)	{printf("file %d open error \n",j);		getc(stdin);	}

	while (fscanf(ftp_data, "%lf %lf %lf %lf \n", &rain, &minRH, &maxT, &aveT) != EOF){ // is this all we've got? I use a lot more than that.

	    Params->CC_WEATHER[year][j][i][0]=rain;
        Params->CC_WEATHER[year][j][i][1]=minRH*100;
        Params->CC_WEATHER[year][j][i][2]=maxT;
        Params->CC_WEATHER[year][j][i][3]=aveT;

		i++;

		if (i == 364){
			year++;
			i = 0;
		}

	}
	fclose(ftp_data);
}


return 0;
}
