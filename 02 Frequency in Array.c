#include<stdio.h>
#include<stdlib.h>
int main()
{
	int *num;
	int k = 0;
	int count = 0;
	int limit;
	int l;
	int repeat;
	scanf("%d",&limit);
	num = (int*)malloc(sizeof(int) * limit);
	while(count < limit)
	{
		scanf("%d",&num[count]);
		count++;
	}
	for(l = 0; l < limit; l++)
	{
		if(num[l]== 0)
		{
			continue;
		}
		repeat = 1;
		for(k = l + 1; k < limit; k++)
		{
			if(num[l] == num[k])
			{
				repeat++;
				num[k] = 0;
			}
		}
		printf("Number %d repeats %d times\n",num[l],repeat);
	}
	return 0;
}
