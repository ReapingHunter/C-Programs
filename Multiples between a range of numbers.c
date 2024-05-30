#include<stdio.h>

int main()
{
    int a;
    int b;
    int c;
    int rem;
    printf("Input : ");
    scanf("%d %d %d",&a,&b,&c);
    printf("Output: ");
    rem = b % c;
    b -= rem;
    while(b >= a)
    {
    	printf("%d ",b);
        b-=c;
    }
    return 0;
}
