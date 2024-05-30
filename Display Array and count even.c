#include <stdio.h>
void displayArray(int arr[], int x);
int countEven(int arr[], int x);

int main()
{
	int arr[] = {1, 2, 3, 5, 6, 7, 8, 10, 11, 12, 13, 15, 16, 17, 18, 20};
	int x;
	displayArray(arr, x);
	printf("\nEven num: %d",countEven(arr, x));
	return 0;
}

void displayArray(int arr[], int x)
{
	for(x = 0; x < 16; x++)
	{
		printf("%d ",arr[x]);
	}
}
int countEven(int arr[], int x)
{
	int countEven;
	for(x = 0; x < 16; x++)
	{
		if(arr[x] % 2 == 0)
		{
			countEven++;
		}
	}
	return countEven++;
}
