#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct city {
	int id;
	char name[50];
	char code[4];
	char district[30];
	int population;
};
int main()
{
	FILE *fp;
	char c;
	char tmp[100];
	struct city temp;
	struct city cityLists[5000];
	int i,col,row;
	int j;
	int index;
	fp = fopen("city.csv","r");
	if(fp == NULL)
	{
		printf("Cannot open file!");
		exit;
	}
	i=0; 
	col=0; 
	row=0;
	while((c = fgetc(fp)) != EOF)
	{
		if(c != ',' && c != '\n')
		{
			tmp[i++] = c;
		}
		
		else {
			tmp[i] = '\0';
			i = 0;
			switch(col) {
				case 0:
					cityLists[row].id = atoi(tmp);
					break;
				case 1:
					strncpy(cityLists[row].name,tmp,49);
					break;
				case 2:
					strncpy(cityLists[row].code,tmp,3);
					break;
				case 3:
					strncpy(cityLists[row].district,tmp,29);
					break;
				case 4:
					cityLists[row].population = atoi(tmp);
					break;
			}
			if(c == ',') {
				col++;
			}
			else if(c == '\n') {
				row++;
				col=0;
			}
		}
		
	}
	/*for(i = 0; i < row; i++) //Bubble Sort
	{
		for(j = 0; j < row - 1; j++)
		{
			if(strcmp(cityLists[j].name, cityLists[j + 1].name) > 0 && cityLists[j].id != 0)
			{
				temp = cityLists[j];
				cityLists[j] = cityLists[j+1];
				cityLists[j+1] = temp;
				
			}
		}
	} */
	
	/*for(i = 0; i < row; i++) //Selection Sort
	{
		index = i;
		for(j = i; j < row; j++)
		{
			if(strcmp(cityLists[j].name, cityLists[index].name) < 0 && cityLists[j].id != 0)
			{
				index = j;
			}
		}
		temp = cityLists[i];
		cityLists[i] = cityLists[index];
		cityLists[index] = temp;
	} */
	
	for(i = 1; i < row; i++) //Insertion Sort
	{
		temp = cityLists[i];
		j = i-1;
		while(strcmp(temp.name, cityLists[j].name) < 0 && j >= 0)
		{
			cityLists[j+1] = cityLists[j];
			--j;
		}
		//memmove(&cityLists[j+1], &cityLists[j],(i-j) * sizeof(int));
		cityLists[j+1] = temp;
	}
	
	
	
	
	for(i=0; i<row; i++)
	{
		printf("%4d  %-20s  %-20s  %-20s  %20d\n",cityLists[i].id, cityLists[i].name, cityLists[i].code, cityLists[i].district, cityLists[i].population);
	}
	return 0;
}
