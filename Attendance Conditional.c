#include<stdio.h>

int main()
{
	int inputNum;
	printf("Enter integer: ");
	scanf("%d", &inputNum);
	if(inputNum<0){
		printf("\nResult: Negative");
	}
	else if(inputNum==0){
		printf("\nResult: Zero");
	}
	else{
		printf("\nResult: Positive");
	}
	return 0;
}
