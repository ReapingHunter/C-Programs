#include<stdio.h>
int getInteger();
void displayPosition(int x, int y);

int main()
{
	int x;
	int y;
	x=getInteger();
	y=getInteger();
	displayPosition(x,y);
	return 0;
}
int getInteger()
{
	int num;
	printf("\nEnter a number here: ");
	scanf("%d",&num);
	return num;
}
void displayPosition(int x, int y)
{
	(x==0 && y==0)? printf("\n\nOrigin") : (y==0)? printf("\n\nx-axis") : (x==0)? printf("\n\ny-axis") : (x>0 && y>0)? printf("\n\nFirst Quadrant") : (x<0 && y>0)? printf("\n\nSecond Quadrant") : (x<0 && y<0)? printf("\n\nThird Quadrant") : (x>0 && y<0)? printf("\n\nFourth Quadrant") : 0;	
}

