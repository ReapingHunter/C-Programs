#include<stdio.h>

void compAndDisplayAve(int N);
int main()
{
	int N;
	printf("Enter a number here: ");
	scanf("%d",&N);
	compAndDisplayAve(N);
	return 0;
}
void compAndDisplayAve(int N)
{
	int ave;
	ave = (N + 2) / 2;
	printf("Average is: %d",ave);
}
