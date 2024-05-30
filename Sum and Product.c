#include<stdio.h>
void sumProduct(int *x, int y);

int main()
{
    int x = 4;
    int y = 5;
    sumProduct(&y,x);
    sumProduct(&x,y);
    return 0;
    
}

void sumProduct(int *x, int y)
{
    if(*x < y)
    {
    	*x = *x + y;
	}
	else
	{
		*x = *x * y;
	}
	printf("\n%d",*x);
}
