#include<stdio.h>

int main()
{
	int x;
    int answer = 0;
    printf("Enter number here: ");
    scanf("%d",&x);
    while(x != 0)
	{
        answer = answer * 10 + (x % 10);
        x = x / 10;
    }
    printf("%d",answer);
}
