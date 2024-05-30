#include<stdio.h>
#include<stdlib.h>

int main()
{
	int num;
	int *arr;
	int k;
	int l;
	int m;
	int temp = 0;
	scanf("%d",&num);
	arr = (int*)malloc(num * sizeof(int));
	for(k = 0; k < num; k++)
	{
		scanf("%d",&arr[k]);
	}
	for(k = 0; k < num - 1; k++)
	{
		for(l = 0; l < (num - 1); l++)
		{
			if(arr[l] > arr[l + 1])
			{
				temp = arr[l];
		    	arr[l] = arr[l + 1];
		    	arr[l + 1] = temp;
			}
		}
		m++;
	}
	for(k = 0; k < num; k++)
	{
		printf("%d",arr[k]);
		if(k < num - 1)
		{
			printf("\n");
		}
	}
	return 0;
}
