#include<stdio.h>

int main()
{
	int a, b, c;
	printf("enter 3 integers: ");
	scanf("%d %d %d",&a,&b,&c);
	if ((a>b) && (a>c))
	{
		printf("\nthe largest: %d",a);	
	}
	else if ((b>a) && (b>c))
	{
		printf("\nthe largest: %d",b);
	}
	else
	{
		printf("\nthe largest: %d",c);
	}
	return 0;
}
