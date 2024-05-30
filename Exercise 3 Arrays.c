#include<stdio.h>
#define SIZE 10
int countNegative(int arr[], int size);
void copyArray(float arrA[], float arrB[], int size);
int isSorted(char arrChar[], int size);

int main()
{
	int arr[SIZE] = {-3, 2, 6, 10, 9, -6, -8, -5, 7, 4};
	float arrA[SIZE] = {3.02, 4.90, 2.001, 5.5, 6,9, 9.01, 8.2, 7, 10};
	float arrB[SIZE];
	char arrChar[SIZE] = {'a','b','c','d','e','f','g','h','i','j'};
	int size;
	countNegative(arr, size);
	copyArray(arrA, arrB, size);	
	isSorted(arrChar, size);
}

int countNegative(int arr[], int size)
{
	int negCount = 0;
	for(size = 0; size < SIZE; size++)
	{
		if(arr[size] < 0)
		{
			arr[size] = 0;
			negCount = negCount + 1;
		}
	}
    return negCount;
}

void copyArray(float arrA[], float arrB[], int size)
{
	for(size = 0; size < SIZE; size++)
	{
		arrB[size] = arrA[size];
	}
}

int isSorted(char arrChar[], int size)
{
	for(size = 0; size < SIZE; size++)
	{
		if(arrChar[size] < arrChar[size+1])
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
}
