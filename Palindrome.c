#include<stdio.h>

int main()
{
	int num;
	int reverse;
	int k;
	int control;
	int rem;
	scanf("%d",&num);
	control = num;
	while(control != 0)
	{
		reverse *= 10;
		rem = control % 10;
		reverse += rem;
		control /= 10;
	}
	if(num == reverse)
	{
		printf("Is a palindrome.");
	}
	else
	{
		printf("Is not a palindrome.");
	}
	return 0;
}
