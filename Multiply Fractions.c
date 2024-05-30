#include<stdio.h>

int main()
{
	int Anum;
	int Bnum;
	int Aden;
	int Bden;
	int productNum;
	int productDen;
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
	productNum = Anum*Bnum;
	productDen = Aden*Bden;
	while(count<=productNum && count<=productDen)
	{
		if(productNum%count == 0 && productDen%count == 0)
		{
			gcd = count;
		}
		++count;
	}
	printf("\n\n(%d/%d) + (%d/%d) = (%d/%d)",Anum, Aden, Bnum, Bden, productNum/gcd, productDen/gcd);
	return 0;
}
