#include<stdio.h>
#include<math.h>
float computeCompoundInterest(float p, int rate, int years);

int main(){
   float p;
   int rate, years;
   float answer;

   printf("Input principal: ");
   scanf("%f",&p);
   printf("Input rate (percent): ");
   scanf("%d",&rate);
   printf("Input number of years: ");
   scanf("%d",&years);


   answer = computeCompoundInterest(p, rate, years);
   
   printf("Total interest in %d years: %.2f",abs(years), answer);
   
   return 0;
}

float computeCompoundInterest(float p, int rate, int years)
{
	float interest;
    interest = abs(p) * pow(1 + abs((float)rate) / 100.00,abs(years)) - abs(p);
    return interest;
}

