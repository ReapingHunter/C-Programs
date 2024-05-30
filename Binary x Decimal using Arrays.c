#include<stdio.h>
#include<stdlib.h>
int *intoBinary(int arr[], int i);
int *intoDecimal(int arr[]);

int main()
{
	int num;
	int arr[30];
	int i;
	int j;
	int test;
	scanf("%d",num);
	int countNum = num;
	for(i = 0; countNum != 0; i++)
	{
		countNum /= 10;
	}
	for(j = i - 1; j >= 0; j--)
	{
		arr[j] = num % 10;
		num /= 10;
	}
	for(j = i - 1; j >= 0; j--)
	{
		if(arr[j] > 1)
		{
			test = 1;
			break;
		}
		else
		{
			test = 0;
		}
	}
	if(test == 1)
	{
		int *num = intoBinary(arr, i);
		for(j = i - 1; j != 0; j--)
		{
			//printf("%d",num[j]);
		}
		j = 0;
	}
}

int *intoBinary(int arr[], int i)
{
	static int binary[30];
	for(i = i - 1; i >= 0; i--)
	{
		if(arr[i] % 2 == 1)
		{
			binary[i] = 1;
		}
		else
		{
			binary[i] = 0;
		}
	}
	return binary;
}

int *intoDecimal(int arr[])
{
	static int decimal[30];
	return decimal;
}
