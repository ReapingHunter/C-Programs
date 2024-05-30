#include<stdio.h>

int main()
{
    int rows;
    int count;
    int pattern;
    printf("Enter number of rows: ");
    scanf("%d",&rows);
    for(count = 0 ; count < rows ; count++)
    {
        for(pattern = 0 ; pattern < count ; pattern++)
        {
            printf(" ");
        }
        printf("^\n");
        pattern = 0;
    }
    return 0;
}
