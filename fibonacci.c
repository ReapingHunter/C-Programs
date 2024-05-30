#include<stdio.h>
void displayFibonacci(int N);

int main()
{
	int N;
	printf("Enter the number of terms here: ");
	scanf("%d",&N);
	displayFibonacci(N);
	return 0;
}
void displayFibonacci(int N)
{
   int fibonacci;
   int a;
   int b=1;
   int term;
   while(term<N)
   {
      printf("\n%d",fibonacci);
      term++;
      a=b;
      b=fibonacci;
      fibonacci = a + b;
   }
}
