#include<stdio.h>

int compAndReturnAve(int N);
int main()
{
	int N;
	printf("Enter a number here: ");
	scanf("%d",&N);
	printf("Average is: %d",compAndReturnAve(N));
	return 0;
}
int compAndReturnAve(int N)
{
	int ave;
	ave = (N + 2) / 2;
	return ave;
}
