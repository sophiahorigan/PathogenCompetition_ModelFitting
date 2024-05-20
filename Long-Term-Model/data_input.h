int inputdata(void *Paramstuff)
{

#define WEATHER_ARRAY 3650 // 10 years of daily data

STRUCTURE* Params;
Params = (STRUCTURE*) Paramstuff;

printf("Loading weather data\n");

// loads the data into a matrix and finds the number of weeks in the data set

double Rain[WEATHER_ARRAY]; double MaxT[WEATHER_ARRAY]; double MinT[WEATHER_ARRAY]; double AveT[WEATHER_ARRAY]; double MaxRH[WEATHER_ARRAY]; double MinRH[WEATHER_ARRAY]; double AveRH[WEATHER_ARRAY];
int year; int i; int ii; int j; 

int FlagF;

char *file;
char *file_name1 = "weather_hist_";  
char *file_name2 = "weather_cc_";  
char *file_type = ".txt"; 

char *code;
char *code_name = "ftp";

char numbs[15]; // might need to increase?

/*------------------------------- Historical Weather ---------------------------------*/
if (SIM == 1)
{
	for (j = 0; j < Params->num_sub; j++)
	{
		year = 0; i = 0; ii = 0; FlagF = 0;

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

		while (fscanf(ftp_data, "%lf %lf %lf %lf \n", &Rain[ii], &MinRH[ii], &MaxT[ii], &AveT[ii]) != EOF){

			Params->HIST_WEATHER[year][j][i][0] = Rain[ii];
			Params->HIST_WEATHER[year][j][i][1] = MinRH[ii]*100;
			Params->HIST_WEATHER[year][j][i][2] = MaxT[ii];
			Params->HIST_WEATHER[year][j][i][3] = AveT[ii];

			i++;
			ii++;

			if (i == 364){
				year++;
				i = 0;
			}
		}
		fclose(ftp_data);
	}
}

/*------------------------------- Climate Change Weather ---------------------------------*/
if (SIM == 2)
{
	for (j = 0; j < Params->num_sub; j++)
	{
		year = 0; i = 0; ii = 0; FlagF = 0;

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

		while (fscanf(ftp_data, "%lf %lf %lf %lf \n", &Rain[ii], &MinRH[ii], &MaxT[ii], &AveT[ii]) != EOF){ 

			Params->CC_WEATHER[year][j][i][0] = Rain[ii];
			Params->CC_WEATHER[year][j][i][1] = MinRH[ii] * 100;
			Params->CC_WEATHER[year][j][i][2] = MaxT[ii];
			Params->CC_WEATHER[year][j][i][3] = AveT[ii];

			ii++;
			i++;

			if (i == 364)
			{
				year++;
				i = 0;
			}
		}
		fclose(ftp_data);
	}
}

return 0;
}
