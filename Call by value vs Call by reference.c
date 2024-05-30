#include <stdio.h>
int funVal(int x, int y);
int funRef(int *x, int *y); // or int funRef(int *a, int *b) or int funRef(int *ptr1, int *ptr2)
int main()
{
	int x = 10;
	int y = 20;
	funVal(x,y);
	funRef(&x, &y);
	printf("x = %d, y = %d",x,y);
	return 0;
}
int funVal(int x, int y) //call by value (changes on formal parameters WILL NOT get reflected to actual parameters)
{
	x = 20;
	y = 10;
} 
int funRef(int *x, int *y) //call by reference (changes on formal parameters WILL get reflected to actual parameters) Here, we PASS ADDRESS.
{
	*x = 20;
	*y = 10;
}
