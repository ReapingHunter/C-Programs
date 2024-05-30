#include <stdio.h>
#define size 30

int main()
{
	int midGrade [size];
	int x;
	int sum = 0;
	int highest = 0;
	float average;
	for(x = 1; x <= size; x++)
	{
		printf("Midterm grade of no. %d student: ",x);
		scanf("%d",&midGrade[x]);
		if(midGrade[x] > highest)
		{
			highest = midGrade[x];
		}
		sum = sum + midGrade[x];
	}
	average = (float)sum / 30.0;
	printf("\nAverage midterm grade of 30 students: %.2f",average);
	printf("\n\nHighest midterm grade of 30 students: %d",highest);
	return 0;
}
