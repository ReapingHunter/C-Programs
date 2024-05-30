#include<stdio.h>
int main()
{
	int EVEN[10];
	int x;
	for(x = 0; x<10; x++)
	{
		EVEN[x] = x * 2;
		printf("\n%d",EVEN[x]);
	}
	return 0;
}
