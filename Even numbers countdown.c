#include<stdio.h>

int main()
{
    int n1;
    int n2;
    printf("Enter 2 numbers here: ");
    scanf("%d %d",&n1,&n2);
    while(n1<n2)
    {
        (n2 % 2 == 0)? printf("%d ",n2), n2-- : n2--;
    }
    return 0;
}
