#include<stdio.h>


double meter(int lengthCentimeter);
double kilometer(int lengthCentimeter);

int main()
{
	int lengthCentimeter;
	printf("Enter length in centimeter: ");
	scanf("%d",&lengthCentimeter);
	printf("\nLength in meter: %.2lf m",meter(lengthCentimeter));
	printf("\nLength in kilometer: %.2lf km",kilometer(lengthCentimeter));	
	return 0;
}

double meter(int lengthCentimeter)
{
	double result = (double)lengthCentimeter/100;
	return result;
}
double kilometer(int lengthCentimeter)
{
	double result = (double)lengthCentimeter/100000;
	return result;
}
