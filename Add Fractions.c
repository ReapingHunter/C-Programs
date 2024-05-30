#include<stdio.h>

int main()
{
	int Anum;
	int Bnum;
	int Aden;
	int Bden;
	int sumNum;
	int sumDen;
	int gcd;
	int smallDen;
	int count = 1;
	
	printf("\nEnter numerator of the first fraction: ");
	scanf("%d",&Anum);
	printf("\nEnter denominator of the first fraction: ");
	scanf("%d",&Aden);
	printf("\nEnter numerator of the second fraction: ");
	scanf("%d",&Bnum);
	printf("\nEnter denominator of the second fraction: ");
	scanf("%d",&Bden);
	sumNum = (Anum*Bden) + (Aden*Bnum);
	sumDen = Aden*Bden;
	while(count<=sumNum && count<=sumDen)
	{
		if(sumNum%count == 0 && sumDen%count == 0)
		{
			gcd = count;
		}
		++count;
	}
	printf("\n\n(%d/%d) + (%d/%d) = (%d/%d)",Anum, Aden, Bnum, Bden, sumNum/gcd, sumDen/gcd);
	return 0;
}
