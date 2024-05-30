#include<stdio.h>

int main()
{
    int x;
    int sum;
    printf("JOLIBEE MENU");
    printf("\nOption   Item           Price");
    printf("\n1        Jolly Hotdog   39.00");
    printf("\n2        Burger Steak   89.00");
    printf("\n3        Spaghetti      89.00");
    printf("\n4        Chickenjoy     89.00");
    printf("\n5        Exit");
    printf("\n\nEnter your menu option, one order at a time, or enter 5\nto exit:\n");
    while(x != 5)
    {
        scanf("%d",&x);
        switch(x)
        {
            case 1:
                sum = sum + 39;
                break;
            case 2:
                sum = sum + 89;
                break;
            case 3:
                sum = sum + 89;
                break;
            case 4:
                sum = sum + 89;
                break;
            case 5:
                break;
            default:
                printf("Invalid input, try again.\n");
                break;
        }
    }
    printf("Your total order price is P%.2f",(float)sum);
    return 0;
}
