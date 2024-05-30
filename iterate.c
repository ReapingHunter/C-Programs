#include<stdio.h>
void intCheck(int N);

int main()
{
	int N;
	printf("Choose a number: ");
	scanf("%d",&N);
	intCheck(N);
	return 0;
}
void intCheck(int N)
{
   int count;
   if(N<0)
   {
      while(N<=0)
      {
         printf("\n%d",N);
         N++;
      }
   }
   else
   {
      while(N>=0)
      {
         printf("\n%d",N);
         N--;
      }
   }
}
