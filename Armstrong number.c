#include<stdio.h>

int main()
{
    int num;
    int remNum;
    int digNum;
    int rem = 0;
    int numDigits = 0;
    int sum = 0;
    int count = 0;
    int remPower;
    printf("Enter a number here: ");
    scanf("%d",&num);
    for(digNum = num ; digNum > 0 ; numDigits++)
    {
        digNum = digNum / 10;
    }
    for(remNum = num ; remNum > 0 ; sum += remPower)
    {
        rem = remNum % 10;
        for(remPower = 1 , count = 0 ; numDigits > count ; count++)
        {
            remPower *= rem;
        }
        remNum = remNum / 10;
    }
    if(num == sum)
    {
        printf("%d is an armstrong number.",num);
    }
    else
    {
        printf("%d is not an armstrong number.",num);
    }
    return 0;
}
