#include<stdio.h>
void triangle();

int main()
{
    triangle();
    return 0;
}
void triangle()
{
	int a;
    int b;
    int c;
    printf("Input: ");
    scanf("%d %d %d",&a,&b,&c);
    (a > 0 && b > 0 && c > 0 && a + b + c == 180)? printf("Output: It's a triangle!") : printf("Output: The triangle is not valid!");
}
