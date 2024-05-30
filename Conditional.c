#include<stdio.h>

int main()
{
	int x,y;
	printf("Enter 2 integers: ");
	scanf("%d %d", &x, &y);
	if(x>y)
	{
		printf("\ndifference: %d", x-y);
	}
}
