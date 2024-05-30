#include <stdio.h>
#include<stdlib.h>
int main()
{
	char *name1;
	char name2[16];
	name1 = (char*) malloc(sizeof(char) * 16);
	printf("Enter name 1");
	scanf("%s",name1);
	printf("Enter name 2");
	scanf("%s",name2);
	printf("%s",name1);
	printf("%s",name2);
	return 0;
}
