#include<stdio.h>

int main()
{
	int x, y, z;
	printf("Enter 2 integers: ");
	scanf("%d %d", &x, &y);
	if(x<y){
		z = x+y;	
	}
	else{
		z = x-y;
	}
	printf("\nanswer: %d", z);
	return 0;
}
