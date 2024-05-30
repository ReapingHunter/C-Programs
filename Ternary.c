#include<stdio.h>

int findAnswer(int x, int y);
int main()
{
	int x,y,answer;
	printf("enter 2 integers: ");
	scanf("%d %d", &x, &y);
	printf("Answer is: %d", findAnswer(x,y));
	return 0;
}
int findAnswer(int x, int y)
{
	return x<y? x+y : x-y;
}
