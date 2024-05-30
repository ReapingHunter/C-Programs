#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	char randString[30];
	int i;
	int null;
	int bigOrSmall;
	while(1){
		for(i = 0; i < 29; i++){
			bigOrSmall = rand() % 2;
			if(bigOrSmall % 2 == 0){
				if(i < 15){
					randString[i] = 65 + rand() % 26;
				}
				else{
					null = rand() % 30 - i;
					if(null % 2 == 0){
						randString[i] = '\0';
					}
					else{
						randString[i] = 65 + rand() % 26;
					}
				}	
			}
			else{
				if(i < 15){
					randString[i] = 97 + rand() % 26;
				}
				else{
					null = rand() % 30 - i;
					if(null % 2 == 0){
						randString[i] = '\0';
						break;
					}
					else{
						randString[i] = 97 + rand() % 26;
					}
				}	
			}	
		}
		randString[29] = '\0';
		system("cls");
		printf("\n\n\n\t%s",randString);
		printf("\e[?25l");
	}
	return 0;
}
