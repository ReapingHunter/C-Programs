#include<stdio.h>

int main()
{
    float fare = 40;
    float km;
    float minute;
    printf("Kilometers: ");
    scanf("%f",&km);
    printf("Minutes: ");
    scanf("%f",&minute);
    km = (int)km*13.50;
    minute = (int)minute*2;
    fare = fare + km + minute;
    printf("Taxi Fare: P%.2f",fare);
    return 0;
}
