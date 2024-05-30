#include<stdio.h>
#include<stdlib.h>

int main()
{
	int numCount;
	int *binary = (int*)calloc(30,sizeof(int));
	int *decimal;
	int k;
	int l = 0;
	scanf("%d",&numCount);
	decimal = (int*)calloc(numCount, sizeof(int));
	for(k = 0; k < numCount; k++)
	{
		scanf("%d",&decimal[k]);
	}
	for(k = 0; k < numCount; k++)
	{
		if(decimal[k] == 0)
		{
			printf("%d",decimal[k]);
			
		}
		while(decimal[k] != 0)
		{
			if(decimal[k] % 2 == 1)
			{
				binary[l] = 1;
			}
			else
			{
				binary[l] = 0;
			}
			decimal[k] /= 2;
			if(decimal[k] != 0)
			{
				*binary >> 1;
			}
			else
			{
	 		    while(l >= 0)
	            {
		            printf("%d",binary[l]);
	        	    l--;
    	        }
			}
			l++;
		}
		printf("\n");
	}
	return 0;
}
