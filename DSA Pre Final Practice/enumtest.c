#include<stdio.h>
typedef enum{Alpha, Beta, Gamma}Level;

typedef struct{
	Level lev;
	int count;
}LEVEL;
int main(){
	LEVEL L[] = {{0, 3}, {2,9},{1,2}};
	if(L[0].lev == Alpha){
		printf("Alpha");
	}
}
