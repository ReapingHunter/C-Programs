#include <stdio.h>
void swapVal(int *x, int *y, int *z);

int main()
{
	int x;
	int y;
	int z;
	printf("Input value of 1st element: ");
	scanf("%d",&x);
	printf("Input value of 2nd element: ");
	scanf("%d",&y);
	printf("Input value of 3rd element: ");
	scanf("%d",&z);
	swapVal(&x,&y,&z);
	printf("\nelement 1 = %d",x);
	printf("\nelement 2 = %d",y);
	printf("\nelement 3 = %d",z);
	return 0;
}

void swapVal(int *x, int *y, int *z)
{
	int temp;
	temp = *y;
	*y = *x;
	*x = *z;
	*z = temp;
}

