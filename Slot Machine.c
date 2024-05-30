#include<stdio.h>
#include <stdlib.h>
void slotMachine(int x);
int main()
{
	int x;
	printf("Select how many times you want to spin: ");
	scanf("%d",&x);
	slotMachine(x);
	return 0;
}

void slotMachine(int x)
{
	int a;
	int b;
	int c;
	int reward;
	while(x>0)
	{
		a = rand() % 10;
    	b = rand() % 10;
    	c = rand() % 10;
		printf("\n%d %d %d",a,b,c);
		x--;	
	}
	
}

