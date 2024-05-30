#include <stdio.h>
int main()
{
	int num1, num2, ans;
	printf("enter 2 integers: ");
	scanf("%d %d",&num1,&num2);
	if(num1>num2)
	{
		ans = num1+num2;
		printf("\nsum is: %d",ans);
	}
	else
	{
		ans = num1*num2;
		printf("\nproduct is: %d",ans);
	}
	return 0;
}
