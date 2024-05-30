#include<stdio.h>

double determineBill(double waterCons);
int main()
{
	int waterCons;
	double waterBill;
	printf("\nEnter Water Consumption (per cubic meter) here: ");
	scanf("%d",&waterCons);
	waterBill=determineBill(waterCons);
	printf("Water Bill is: %.2lf",waterBill);
	return 0;
}
double determineBill(double waterCons)
{
	if(waterCons <= 10)
	{
		return waterCons*20;
	}
	else if(waterCons <= 20)
	{
		return 10*20 +(waterCons-10)*30;
	}
	else if(waterCons <= 30)
	{
		return 10*20 + 10*30 +(waterCons-20)*40;
	}
	else
	{
		return 10*20 + 10*30 + 10*40+(waterCons-30)*50;
	}
}
