#include<stdio.h>

int main()
{
	int  var[] = {10, 100, 200};
int  i, *ptr;
ptr = var; 
for ( i = 0; i < 3; i++) {
    printf("Address of var[%d] = %x\n", i, ptr );
    printf("Value of var[%d] = %d\n", i, *ptr );
    ptr++;
}
}
