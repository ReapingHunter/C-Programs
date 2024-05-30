#include<stdio.h>
int sumInt();

int main()
{
	printf("\nSum: %d",sumInt());
	return 0;
}
int sumInt()
{
   int n;
   int sum;
   while(n>=0)
   {
      printf("\nEnter a number: ");
      scanf("%d",&n);
      (n>=0)? sum = sum + n : 0;
   }
   return sum;
}
