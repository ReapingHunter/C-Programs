#include <stdio.h>
void foundationArray(int x, int SIZE, int arr[]);
void sortArray(int x, int SIZE, int arr[]);

int main()
{
	int SIZE;
	int x;
	int arr[SIZE];
	printf("Input size of the array (MAX 10): ");
	scanf("%d",&SIZE);
	if(SIZE > 10)
	{
		SIZE = 10;
	}
	printf("\nEnter a number: ");
	scanf("%d",&x);
	if(x < 0)
	{
		x *= -1;
	}
	foundationArray(x, SIZE, arr);
	sortArray(x, SIZE, arr);
	return 0; 
}
void foundationArray(int x, int SIZE, int arr[])
{
	int count;
	int rem;
	printf("Foundation Codes:\n");
	for(count = 0; count < SIZE; count++)
	{
		rem = x % 10;
		arr[count] = rem;
		x /= 10;
		printf("%d   ",arr[count]);
   }
}
void sortArray(int x, int SIZE, int arr[])
{
	int outer;
	int inner;
	int temp;
	printf("\nSorted Codes:\n");
	for(outer = 0; outer < SIZE; outer++)
	{
		for(inner = 0; inner < (SIZE - 1 - outer); inner++)
		{
			temp = arr[inner];
			arr[inner] = arr[inner + 1];
			arr[inner + 1] = temp;
		}
		printf("%d   ",arr[inner]);
	}
	
}

