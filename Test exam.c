#include <stdio.h>
void inputArray(float arr[], int element);
int main()
{
	float arr[];
	int element;
	inputArray(arr, element);
	return 0;
}
void inputArray(float arr[], int element)
{
	for(element = 0; element < 10; element++)
	{
		printf("Input Element of an array: ");
		scanf("%f",&arr[element]);
	}
}
