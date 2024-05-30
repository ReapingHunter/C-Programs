#include<stdio.h>

int main()
{
    int x;
    int y;
    int product;
    int countx;
    int county = 1;
    printf("Enter 2 numbers here: ");
    scanf("%d %d",&x,&y);
    product = x*y;
    while(countx < x)
    {
        printf("%d",product,countx++);
        while(county < y && countx == x)
        {
            countx = 0;
            printf("\n",++county);
        }
    }
    if(x == y)
    {
        printf("\nNice");
    }
    return 0;
}
