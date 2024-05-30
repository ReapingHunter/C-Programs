#include<stdio.h>
int main()
{
	double Fahrenheit, Celsius;
	int  Choice;
	printf("Type '0' to convert temperature from Fahrenheit to Celsius");
	printf("\n\nType any number to convert temperature from Celsius to Fahrenheit");
	printf("\n\nPlease Enter your choice: ");
	scanf("%d",&Choice);
	if((Choice>=1))
	{
		printf("\n\nYou selected: Fahrenheit");
		printf("\n\n\nEnter the Celsius: ");
		scanf("%lf", &Celsius);
		Fahrenheit = (Celsius*9/5)+32;
		printf("\n\nTemperature in Fahrenheit is: %.1lf ",Fahrenheit);
	}
	else
	{
		printf("\n\nYou selected: Celsius");
		printf("\n\n\nEnter the Fahrenheit: ");
		scanf("%lf", &Fahrenheit);
		Celsius = (Fahrenheit-32)*5/9;
		printf("\n\nTemperature in Celsius is: %.1lf ",Celsius);
	}
	return 0;
	
}
