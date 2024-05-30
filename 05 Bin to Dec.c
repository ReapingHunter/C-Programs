#include<stdio.h>
#include<stdlib.h>
int main()
{
    int numOfBin;
    int k;
    long long decimal;
    int length;
    int l;
    long long pow;
    int powCount;
    scanf("%d",&numOfBin);
    char **binary = (char**)malloc(sizeof(char*) * numOfBin);
    for(k = 0; k < numOfBin; k++) //Lets the user input binary numbers in each array of string
    {
    	binary[k] = (char*)malloc(sizeof(char) * 45);
    	scanf("%s",binary[k]);
	}
	for(k = 0; k < numOfBin; k++) //Moves on to the next array of string when incrementing
    {
    	decimal = 0;
    	for(length = 0, l = 0; binary[k][l]; length++,l++){} //Measures the length of the chosen array of string
    	for(l = 0; binary[k][l]; l++) //Moves on to the next character when incrementing
    	{
    		pow = 1;
    		powCount = length - 1;
    		if(binary[k][l] == '1') //If a digit is 1, performs the condition
    		{
    			while(powCount > 0) //Multiplies pow by 2 to the power of powCount where powCount is the placement of the digit - 1
    			{
    				pow *= 2;
    				powCount--;
				}
    			decimal += pow;
			}
			length--;
		}
		printf("%lld",decimal);
		if(k < numOfBin - 1) //To make sure the program will enter a new line when necessary
		{
			printf("\n");
		}
	}
	
    return 0;
}
