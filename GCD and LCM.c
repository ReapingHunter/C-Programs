#include<stdio.h>

int main()
{
	int num1;
	int num2;
	int gcd;
	int lcm;
	int r;
	int greater;
	int smaller;
	
	printf("\nEnter 2 Integers: ");
	scanf("%d%d",&num1, &num2);
	greater = (num1>num2)? num1 : num2;
	smaller = (num1<num2)? num1 : num2;
	r = greater%smaller;
	while(r!=0)
	{
		greater=smaller;
		smaller=r;
		r = greater%smaller;
	}
	gcd = smaller;
	lcm = (greater*smaller) / gcd;
	printf("\nGCD: %d",gcd);
	printf("\nLCM: %d",lcm);
	return 0;
}
