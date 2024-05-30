#include<stdio.h>
#include<string.h>
int main(int argc, char *argv[])
{
	int ans = *argv[2];
	switch(ans)
	{
		case '+':
            ans = atoi(argv[1]) + atoi(argv[3]);
            break;
        case '-':
        	ans = atoi(argv[1]) - atoi(argv[3]);
            break;
        case '*':
        	ans = atoi(argv[1]) * atoi(argv[3]);
            break;
        case '/':
        	ans = atoi(argv[1]) / atoi(argv[3]);
            break;
	}
	printf("%d",ans);
	return 0;
}
