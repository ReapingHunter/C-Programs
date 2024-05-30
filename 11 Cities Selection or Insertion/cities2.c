#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct City{
	int id;
	char name[50];
	int state_id;
	char state_code[4];
	char state_name[50];
	int country_id;
	char country_code[3];
	char country_name[50];
	float latitude;
	float longitude;
	char wikiDataId[10];
};

void getcsv(char *separated_data[], char *string, char separator){
		
	char *tmp;	
	int i;
		
	if (string == NULL){
		separated_data[0] = NULL;
		return;	
	}

	tmp = string;
	separated_data[0] = string;
	i=1;
				
	while ((tmp = strchr(tmp,separator)) != NULL){
		*tmp = '\0';
		tmp++;
		separated_data[i] = tmp;
		i++;
	}
	
	separated_data[i] = NULL;
}

int main (void){
	FILE *fp;
	
	char string[200];
	char *ret,*part;
	struct City *Cities, tmpEntry;
	int i, j, row, k;
	char *data[12];
	struct City temp;
	
	Cities = (struct City*) malloc(150711*sizeof(struct City));

	if (Cities == NULL){
		printf("Can not allocate Memory!\n");
		exit;		
	}
	
	fp = fopen("cities2.csv","r");	
	if (fp == NULL){
		printf("Can not open file!\n");
		exit;	
	}

	row=0;
	while ((ret = fgets(string,200,fp)) != NULL){

		getcsv(data,string,',');

		(Cities+row)->id = atoi(data[0]);
		strncpy(Cities[row].name,data[1],49);
		Cities[row].state_id = atoi(data[2]);
		strncpy(Cities[row].state_code,data[3],3);
		strncpy(Cities[row].state_name,data[4],49);;
		Cities[row].country_id = atoi(data[5]);
		strncpy(Cities[row].country_code,data[6],2);
		strncpy(Cities[row].country_name,data[7],49);
		Cities[row].latitude = atof(data[8]);
		Cities[row].longitude = atof(data[9]);
		strncpy(Cities[row].wikiDataId,data[10],9);
		Cities[row].wikiDataId[strlen(Cities[row].wikiDataId)-1] = 0;
		row++;
	
	}
	
	//Write here your part of code
	for(i = 1; i < row; i++) {
		temp = Cities[i];
		j = i - 1;
		while(j >= 0 && strcmp(Cities[j].name, temp.name) > 0) {
			Cities[j+1] = Cities[j];
			j--;
		}
		Cities[j+1] = temp;
	}
	//4.8 minutes
	
	
	
	for(j = 0; j < row; j++)
	{
		printf("%7d %-50s %5d %3s %-50s %5d %2s %-20s %5.3f %5.3f %-9s\n",
		Cities[j].id,
		Cities[j].name,
		Cities[j].state_id,
		Cities[j].state_code,
		Cities[j].state_name,
		Cities[j].country_id,
		Cities[j].country_code,
		Cities[j].country_name,
		Cities[j].latitude,
		Cities[j].longitude,
		Cities[j].wikiDataId);
	}

	return 0;
}
