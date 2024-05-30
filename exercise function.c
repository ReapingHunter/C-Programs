#include<stdio.h>
int findArea(int length, int width);

int main()
{
	int length;
	int width;
	printf("Find length and width: ");
	scanf("%d""%d",&length,&width);
	printf("\n\n%d",findArea(length, width));
	return 0;
}
int findArea(int length, int width)
{
	int area;
    if(length > 0 && width > 0)
    {
    	area = length*width;
    	return area;
    }
    else
    {
    	return -1;
	}
}

