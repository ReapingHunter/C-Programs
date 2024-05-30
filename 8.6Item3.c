#include<stdio.h> /*Includes the input and output related functions in the program*/
double calculateP(double p, int C, int x, int n); /*Function for calculating p*/
int main() /*Main function*/
{
	int C; /*Variable of the counter that increments by 1 whenever function calculateP is executed*/
	int x; /*Variable of the first number that will be multiplied by itself*/
	int n; /*Variable of the second number that determines how many times the first number multiplies by itself*/
	double p; /*Variable of the calculated product*/
	printf("Enter your number here: "); /*Asks the user the number that will be multiplied by itself*/
	scanf("%d",&x); /*Scans the number that will be multiplied by itself*/
	printf("\nEnter how many times the number multiplies by itself: "); /*Asks the user the number that determines how many times the first number multiplies by itself*/
	scanf("%d",&n); /*Scans the number that determines how many times the first number multiplies by itself*/
	p=calculateP(p,C,x,n); /*Let p be the returned value of the function*/
	printf("\np = %.0lf",p); /*Shows the resultant product*/
	return 0; /*Program is executed successfully and terminates*/
}
double calculateP(double p, int C, int x, int n) /*Function for calculating p*/
{
	for(p=1,C=1;C<=n;C++) /*Loop that multiplies p by variable n as long as the counter is less than or equal to the number that determines how many times the variable n multiplies by itself*/
	{
		p=p*(double)x; /*Formula of p*/
	}
	return p; /*Returns the value*/
}
