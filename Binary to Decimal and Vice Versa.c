#include<stdio.h>

int main()
{
	int num;
	int binary[30];
	int decimal = 0;
	int k = 0;
	int sum;
	int mult = 1;
	int l;
	scanf("%d",&num);
	while(num != 0)
	{
		if(num % 2 == 1)
		{
			binary[k] = 1;
		}
		else
		{
			binary[k] = 0;
		}
		num /= 2;
		if(num > 0)
		{
			*binary >> 1;
		}
		else
		{
			l = k;
			while(k >= 0)
			{
				printf("%d",binary[k]);
				k--;
			}
			
		}
		k++;
	}
	while(k <= l)
	{
        sum = binary[k]* mult;
 		mult *= 2;	
		decimal += sum;
		k++;
    }
   	printf("\n%d",decimal);
   	return 0;
	
}
