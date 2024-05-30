#include<stdio.h>
#include<stdlib.h>
int main()
{
	int k;
	int l;
	int index;
	int temp;
	int num;
	scanf("%d",&num);
	int *arr = (int*)malloc(sizeof(int) * num);
	for(k = 0; k < num; k++)
	{
		scanf("%d",&arr[k]);
	}
	for(k = 0; k < num; k++)
	{
		index = k;
		for(l = k; l < num; l++)
		{
			if(arr[index] > arr[l])
			{
				index = l;
			}
		}
		temp = arr[index];
		arr[index] = arr[k];
		arr[k] = temp;
		printf("%d",arr[k]);
		if(k < num - 1)
		{
			printf("\n");
		}
		
	}
	return 0;
}
