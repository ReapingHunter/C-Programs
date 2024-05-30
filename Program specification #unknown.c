#include <stdio.h>

int main()
{
	int A;
	int B;
	int X;
	int Y;
	printf("Input first side of the square: ");
	scanf("%d",&A);
	printf("\n\nInput second side of the squrare: ");
	scanf("%d",&B);
	if(A==B)
	{
		X = A * B;
		printf("\n\nThe area of the square is: %d",X);
	}
	else
	{
		Y = (2*A) + (2*B);
		printf("\n\nThe perimeter is: %d",Y);
	}
	return 0;
}
