#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int num;
	int k;
	int l;
	char temp[50];
	scanf("%d",&num);
	char **store = (char**)malloc(sizeof(char*) * num);
	for(k = 0; k < num; k++)
	{
		store[k] = (char*)malloc(sizeof(char) * 50);
		scanf("%s",store[k]);
	}
	for(k = 0; k < num; k++)
	{
		for(l = 0; l < (num - 1); l++)
		{
			if(strcmp(store[l], store[l+1]) > 0)
			{
				strcpy(temp, store[l]);
				strcpy(store[l], store[l+1]);
				strcpy(store[l+1], temp);
			}
		}
	}
	for(k = 0; k < num; k++)
	{
		printf("%s",store[k]);
		if(k < (num - 1))
		{
			printf("\n");
		}
	}
	return 0;
}
