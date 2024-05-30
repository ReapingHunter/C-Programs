#include<stdio.h>

int main()
{
	int arr[] = {10, 7, 23, 19, 20, 9, 7, 100, 94, 98};
	int k;
	int l;
	int index;
	int temp;
	for(k = 0; k < (sizeof(arr) / sizeof(arr[0])); k++)
	{
		index = k;
		for(l = k; l < (sizeof(arr) / sizeof(arr[0])); l++)
		{
			if(arr[index] > arr[l])
			{
				index = l;
			}
		}
		temp = arr[index];
		arr[index] = arr[k];
		arr[k] = temp;
		
	}
	for(k = 0; k < sizeof(arr) / sizeof(arr[0]); k++)
	{
		printf("%d ",arr[k]);
	}
	return 0;
}
