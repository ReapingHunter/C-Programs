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
	for(k = 1; k < num; k++)
	{
		strcpy(temp, store[k]);
		l = k - 1;
		while(l >= 0 && strcmp(temp, store[l]) < 0)
		{
			strcpy(store[l+1],store[l]);
			l--;
		}
		strcpy(store[l+1], temp);
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
