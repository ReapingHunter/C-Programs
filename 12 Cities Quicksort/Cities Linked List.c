#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
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
}CityData;

typedef struct citynode{
	CityData Cities;
	struct citynode *node;
}City;
struct citynode *head = NULL;

City *new_node(){
	City *newNode;
	newNode = (City*)malloc(sizeof(City));
	if(newNode == NULL){
		exit;
	}
	return newNode;
}

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

void newCity(FILE *fp, char *data[], char string[]){
	City *citynode, *current;
	
	
	
	citynode = new_node();
	
	getcsv(data,string,',');
		
		citynode->Cities.id = atoi(data[0]);
		strncpy(citynode->Cities.name,data[1],49);
		citynode->Cities.state_id = atoi(data[2]);
		strncpy(citynode->Cities.state_code,data[3],3);
		strncpy(citynode->Cities.state_name,data[4],49);;
		citynode->Cities.country_id = atoi(data[5]);
		strncpy(citynode->Cities.country_code,data[6],2);
		strncpy(citynode->Cities.country_name,data[7],49);
		citynode->Cities.latitude = atof(data[8]);
		citynode->Cities.longitude = atof(data[9]);
		strncpy(citynode->Cities.wikiDataId,data[10],9);
		citynode->Cities.wikiDataId[strlen(citynode->Cities.wikiDataId)-1] = 0;
	
	citynode->node = NULL;
	if(head == NULL){
		head = citynode;
	}
	else{
		current = head;
		while(current->node != NULL){
			current = current->node;
		}
		current->node = citynode;
	}
}

void displayCity(){
	City *current;
	while(current != NULL){
		current = head;
		printf("%7d %-50s %5d %3s %-50s %5d %2s %-20s %5.3f %5.3f %-9s\n",
		current->Cities.id,
		current->Cities.name,
		current->Cities.state_id,
		current->Cities.state_code,
		current->Cities.state_name,
		current->Cities.country_id,
		current->Cities.country_code,
		current->Cities.country_name,
		current->Cities.latitude,
		current->Cities.longitude,
		current->Cities.wikiDataId);
		current = current->node;
	}
}
int main(){
	FILE *fp;
	int i;
	char *data[12];
	char string[200];
	char *ret;
	fp = fopen("cities2.csv","r");	
	if (fp == NULL){
		printf("Can not open file!\n");
		exit;	
	}
	while((ret = fgets(string,200,fp)) != NULL){
		newCity(fp, data, string);
	}
	
	
	
	displayCity();
	return 0;
}
