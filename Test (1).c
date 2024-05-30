#include<stdio.h>

int add(int a, int b);

int main()
{
	int x, y;
	printf("enter two integers: ");
	scanf("%d %d",&x,&y);
	printf("\nSum is: %d",add(x,y));
	return 0;
}

int add(int a, int b)
{
	return a+b;
}
