#include<stdio.h>

double difference(double x, double y);
double quotient(double x, double y);

int main()
{
	double x, y;
	printf("enter 2 integers: ");
	scanf("%lf %lf",&x,&y);
	printf("\nDifference is: %.0lf",difference(x,y));
	printf("\nQuotient is: %.1lf",quotient(x,y));	
	return 0;
}

double difference(double x, double y)
{
	double result = x-y;
	return result;
}
double quotient(double x, double y)
{
	double result = x/y;
	return result;
}
