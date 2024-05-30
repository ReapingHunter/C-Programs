#include <stdio.h>
int factorial(int x);

int main()
{
	int x;
    printf("Enter an integer: ");
    scanf("%d", &x);
    return 0;
}
int factorial(int x)
{
	int count = 1;
	double fact = 1;
	if (x < 0)
    {
    	return 0;
	} 
    else
    {
    	while(count <= x) 
		{
            fact = fact * count;
            ++count;
            printf("Factorial of %d = %.0lf", x, fact);
        }
	
	}
	   
}



