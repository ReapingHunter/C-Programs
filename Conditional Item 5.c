#include<stdio.h>
char Verdict(int ave, char ver);
int average(int p, int c, int b, int m, int com, int ave);
int main()
{
	int p,c,b,m,com,ave,ver;
	printf("\nEnter grade in Physics (in percentage): ");
	scanf("%d",&p);
	printf("\nEnter grade in Chemistry (in percentage): ");
	scanf("%d",&c);
	printf("\nEnter grade in Biology (in percentage): ");
	scanf("%d",&b);
	printf("\nEnter grade in Mathematics (in percentage): ");
	scanf("%d",&m);
	printf("\nEnter grade in Computer (in percentage): ");
	scanf("%d",&com);
	printf("\n\nAverage: %d",average(p, c, b, m, com, ave));
	ave = average(p,c,b,m,com,ave);
	printf("%c",Verdict(ave, ver));
    return 0;
}
int average(int p, int c, int b, int m, int com, int ave)
{
	ave = (p+c+b+m+com)/5;
	return ave;
}
char Verdict(int ave, char ver)
{

	if(ave >= 90)
	{
		printf("\n\nVerdict: Excellent",ver);
		return ver;
	}
	else if(ave >= 80)
	{
		printf("\n\nVerdict: Very Good",ver);
		return ver;
	}
	else if(ave >= 70)
	{
		printf("\n\nVerdict: Good",ver);
		return ver;
	}
	else if(ave >= 60)
	{
		printf("\n\nVerdict: Fair",ver);
		return ver;
	}
	else if(ave >= 50)
	{
		printf("\n\nVerdict: Poor",ver);
		return ver;
	}
	else
	{
		printf("\n\nVerdict: Very Poor",ver);
		return ver;
	}

}


