/*
 FILE : Number 5
 AUTHORS : Arien Del mar , Marlex Manalili
 Description : Computing the circumference, area and the diameter of a circle
 Date: 29/09/2021
*/
#include<stdio.h>
#define PI 3.14
 
int main()
{
  float radius;
  float diameter;
  float circumference;
  float area;
         
 
  printf("\n Please Enter the radius of a circle : ");
  scanf("%f",&radius);
 
  diameter = 2 * radius;
  circumference = 2 * PI * radius;
  area = PI * radius * radius; 
 
  printf("\n Area Of a Circle = %.2f\n", area);
  printf("\n Circumference Of a Circle = %.2f\n", circumference);
  printf("\n Diameter Of a Circle = %.2f\n", diameter);
  
 
  return 0;
}



