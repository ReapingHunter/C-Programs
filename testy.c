#include <stdio.h>
int main()
{
    int N;
    printf("Input Number here: ");
	scanf("%d",&N);
	if(N % 2 != 0)
	{
		N=N-1;
	}
	while(N >= 0)
	{
		printf("%d\t",N);
		N=N-2;
	} 
	printf("\n\nI did it !");
  	return 0;
}
