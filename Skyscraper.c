#include<stdio.h>

int main()
{
    int width;
    int height;
    int countw;
    int counth;
    printf("Enter width of skyscraper: ");
    scanf("%d",&width);
    printf("Enter height of skyscraper: ");
    scanf("%d",&height);
    printf("\n");
    for(countw = 0 ; countw < (width/2) ; countw++)
   	{
    	printf(" ");
   	}
   	if(width % 2 == 0)
   	{
       	printf("**");
   	}
   	else
    {
   		printf(" *");
   	}
   	printf("\n");
    for(counth = 2 ; counth < height ; counth++)
	{
		printf(" ");
		for(countw = 0 ; countw < width ; countw++)
		{
			printf("*");
		}
		printf("\n");
	}
	for(countw = 0 ; countw < (width+2) ; countw++)
	{
		printf("*");
	}
    return 0;
}
