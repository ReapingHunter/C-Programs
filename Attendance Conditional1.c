#include <stdio.h>
int main()
{
	int a = 5, b = 5, c = 10, result;
	
	result = ( a == b) && (c > b); 
	printf("(a == b) && (c > b) is %d \n", result); // Result is 1 because both are true
	result = ( a == b) && (c < b); 
	printf("(a == b) && (c < b) is %d \n", result); // Result is 0 because "c is lesser than b statement" is false and logical operator is "and"
	result = ( a == b) || (c < b); 
	printf("(a == b) || (c < b) is %d \n", result); // Result is 1 because only "a equals b" statement is true and logical operator is "or"
	result = ( a != b) || (c < b);
	printf("(a != b) || (c < b) is %d \n", result); // Result is 0 because none of them are true
	result = !( a != b);
	printf("!(a != b) is %d \n", result); // Result is 1 because " not(a is not b)" is true
	result = !( a == b);
	printf("!(a == b) is %d \n", result); // Result is 0 because "not(a is equal to b)" is false
}
