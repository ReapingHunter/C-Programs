#include<stdio.h>
int main()
{
	int Age;
	printf("Please Input Age here: ");
	scanf("%d",&Age);
	if(Age<18)
	{
		printf("\nVoting Eligibility: Not Eligible");
	}
	else
	{
		printf("\nVoting Eligibility: Eligible");
	}
	return 0;
}
