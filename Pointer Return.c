#include <stdio.h>
int *findMid(int a[], int s);

int main()
{
	int arr[]={1,2,3,4,5,6,7,8,9,10};
	int size = sizeof(arr) / sizeof(int);
	int *mid = findMid(arr, size);
	printf("%d",*mid);
	return 0;
}
int *findMid(int a[], int s)
{
	return &a[s/2];
}



