#include<stdio.h>

int main()
{
	float x;
	float sum;
	float average;
	float inputValue=0;
	printf("\nInput number here: ");
	scanf("%f",&x);
	sum = sum + x;
	inputValue=inputValue+1;
	while(x>=1 && x<=99)
	{
		printf("\nInput number here: ");
	    scanf("%f",&x);
	    sum = sum + x;
	    inputValue=inputValue+1;
	}
	printf("\nTotal Input Value: %.0f",inputValue);
	average = sum/inputValue;
	printf("\n\nAverage: %.1f",average);
	return 0;
}
