#include<stdio.h>
float evenOdd(int n);

int main()
{
    int n;
    printf("Enter number: ");
    scanf("%d",&n);
    printf("%.0f",evenOdd(n));
    return 0;
}
float evenOdd(int n)
{
   int rem;
   float equiv;
   int mult = 1;
   while(n != 0)
   {
      rem = n % 10;
       n /= 10;
      if(rem % 2 == 0)
      {
         equiv = equiv + 1;
      }
      else
      { 
         equiv = equiv + 2;      
      }
       equiv /= 10;
       mult *= 10;
   }
    equiv *= mult;
   return equiv;
}
