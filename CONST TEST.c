#include<stdio.h>
#define PI 3.14159
int main()
{
	float radius;
	float area;
	float circumference;
	printf("Input radius of the circle: ");
	scanf("%f",&radius);
	area = PI * (radius * radius);
	circumference = 2 * (PI * radius);
	printf("\n\nArea of the circle is: %f",area);
	printf("\n\nCircumference of the circle is: %f",circumference);
	return 0;
}
