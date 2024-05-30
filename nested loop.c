#include<stdio.h>
int main()
{
	int i, j, N;
	printf("Enter N: ");
	scanf("%d",&N);
	for(i=1;i<N;i++)
	{
		for(j=0;j<i;j++)
		{
			sleep(1);
			printf("%3d",i);
		}
		printf("\n");
	}
	return 0;
}
