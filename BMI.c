#include<stdio.h>

int main()
{
	float weight;
	float height;
	float bmi;
	printf("Enter your weight in kg: ");
	scanf("%f",&weight);
	printf("Enter your height in cm: ");
	scanf("%f",&height);
	height = height / 100;
	bmi = weight / (height * height);
	printf("Your BMI: %.2f",bmi);
	if(bmi < 18.5)
	{
		printf("\nCategory: Underweight");
	}
	else if(bmi >= 18.5 && bmi < 25.0)
	{
		printf("\nCategory: Normal");
	}
	else if(bmi >= 25.0 && bmi <= 30.0)
	{
		printf("\nCategory: Overweight");
	}
	else
	{
		printf("\nCategory: Obese");
	}
	return 0;
}
