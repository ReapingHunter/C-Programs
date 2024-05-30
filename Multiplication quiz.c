#include<stdio.h>

int main()
{
    int x;
    int ans;
    int count=2;
    int nextx;
    int correct=0;
    printf("Enter a positive number: ");
    scanf("%d",&x);
    nextx = ans;
    if(x>0)
    { 
        printf("Enter the succeeding multiples of %d:\n",x);
        while(ans == nextx)
        {
            nextx = x*count;
            scanf("%d",&ans);
            if(ans == nextx)
            {
                correct++;
                count++;
            }
        }
        if(ans != nextx)
        {
            printf("Sorry, the next multiple is %d.",nextx);
            printf("\nYou have obtained %d correct answers.",correct);
        }
        
    }
    else
    {
        printf("Error: Invalid input. Please try again.");
    }
    return 0;
}
