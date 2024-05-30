#include<stdio.h>

int difference(int x, int y);
double quotient(int x, int y);

int main()
{
	int x, y;
	printf("Enter 2 integers: ");
	scanf("%d %d",&x,&y);
	printf("\nDifference is: %d",difference(x,y));
	printf("\nQuotient is: %.1lf",quotient(x,y));	
	return 0;
}

int difference(int x, int y)
{
	int result = x-y;
	return result;
}
double quotient(int x, int y)
{
	double result = (double)x/(double)y;
	return result;
}
