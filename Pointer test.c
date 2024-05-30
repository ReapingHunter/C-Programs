#include <stdio.h>
void f2(int *a, int *b);


int main()
{
	int a=4;
	int b=5;
	int c=6;
	f2(&b, &c);
	printf("%d",c-a-b);
	return 0;
}
void f2(int *a, int *b)
{
	int c;
	c = *a; 
	*a = *b;
	*b = c;
}
