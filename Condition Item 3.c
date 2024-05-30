#include<stdio.h>

int answerOperation(int num1, int num2,int choice);
char clearOp(int choice, char inv);
int main()
{
	int num1, num2, choice, inv;
	printf("\nEnter 2 Integers: ");
	scanf("%d""%d",&num1,&num2);
	printf("\nType '1' to choose Addition");
	printf("\nType '2' to choose Subtraction");
	printf("\nType '3' to choose Multiplication");
	printf("\nType '4' to choose Division");
	printf("\n\nSelect your choice here (1,2,3,4): ");
	scanf("%d",&choice);
	printf("\n\nAnswer is: %d",answerOperation(num1,num2,choice));
	printf("%c",clearOp(choice, inv));
	return 0;
}
int answerOperation(int num1, int num2, int choice)
{
	if(choice == 1)
	{
		int result = (num1 + num2);
		return result;
	}
	else if(choice == 2)
	{
		int result = (num1 - num2);
		return result;
	}
	else if(choice == 3)
	{
		int result = (num1 * num2);
		return result;
	}
	else if(choice == 4)
	{
		int result = num1 / num2;
		return result;
    }
}
char clearOp(int choice, char inv)
{
	if((choice >4) || (choice ==0))
	{
		system("cls");
	    printf("Invalid Operation",inv);
	}
	return inv;
}

