#include<stdio.h>
double calculateP(double p, int C, int x, int n);
int main()
{
	double p;
	int C;
	int x;
	int n;
	printf("Input first number: ");
	scanf("%d",&x);
	printf("Input second number: ");
	scanf("%d",&n);
	p=calculateP(p,C,x,n);
	printf("p = %.0lf",p);
	return 0;
}
double calculateP(double p, int C, int x, int n)
{
	for(p=1,C=1;C<=n;C++)
	{
		p=p*(double)x;
	}
	return p;
}
