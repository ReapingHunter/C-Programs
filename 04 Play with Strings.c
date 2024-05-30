#include <stdio.h>
#include <string.h>
#include <ctype.h>

char* strlwr(char* s)
{
    char* tmp = s;

    for (;*tmp;++tmp) {
        *tmp = tolower((unsigned char) *tmp);
    }

    return s;
}

char* strupr(char* s)
{
    char* tmp = s;

    for (;*tmp;++tmp) {
        *tmp = toupper((unsigned char) *tmp);
    }

    return s;
}


int main()
{
	char string[200][30];
	int i,j,num,ret;
	int len = 0;
	char text[4000];
	
	ret = 1; num = 0;
	do{
		ret = scanf("%s",string[num]);	
		num++;
		
	}while (ret != EOF);

	num--;
	
	for(i=0;i<num;i++){
		for(j = 0; string[i][j]; j++,len++){}
		printf ("str[%d]=%s len=%d\n",i,string[i],len);
		len = 0;
	}
	printf("##########\n");
	for(i=0;i<num;i++){
		for(j = 0; string[i][j]; j++,len++){}
		printf ("%s",string[i]);
		printf (" ");
		len++;
	}
	printf("len=%d\n",len-1);
	printf("##########\n");
	for(i=0;i<num;i++){
		strupr(string[i]);
		printf ("%s",string[i]);
		if(i < num-1)
		{
			printf (" ");
		}
	}
	printf("\n##########\n");
	for(i=0;i<num;i++){
		strlwr(string[i]);
		printf ("%s",string[i]);
		if(i < num-1)
		{
			printf (" ");
		}
	}
	return 0;

}
