#include <stdio.h> /*Includes the input and output related functions in the program*/
int repeatAdd(int num1, int num2, int product, int loop); /*Function for determining the product using repeated addition*/
int main() /*Main function*/
{
    int num1,num2; /*Variable for first and second number*/
    int product,loop; /*Variable for product of two entered numbers and number of loops*/
    printf("Enter first number: "); /*Asks the user to enter the first number*/
    scanf("%d",&num1); /*Scans the first number*/
    printf("Enter second number: "); /*Asks the user to enter the second number*/
    scanf("%d",&num2); /*Scans the second number*/
    product=repeatAdd(num1, num2, product, loop); /*Let product be the returned value of the function*/
    printf("Product is: %d\n",product); /*Shows the product of the two numbers*/
    return 0; /*Program is executed successfully and terminates*/
}
int repeatAdd(int num1, int num2, int product, int loop) /*Function for determining the product using repeated addition*/
{
	
    for(loop=1;loop<=num2;loop++) /*Loop to calculate product using repeated addition. Let number of loops be less than or equal to the second entered number. Number of loops determine on how many repeated additions needed to get the product of two numbers.*/
	{
        product += num1; /*Increment product by the first entered number*/
    }
	return product; /*Returns the value*/
}
