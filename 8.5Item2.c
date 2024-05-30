#include<stdio.h>
int main()
{
	int numQ, sum=0, count=0, quizGrade;
	printf("Enter number of quizzes: ");
	scanf("%d",&numQ);
	while(count<numQ)
	{
		printf("Get quiz grade: ");
		scanf("%d",&quizGrade);
		sum += quizGrade;
		count++;
	}
	float average=(float)sum/numQ;
	printf("Average = %.1f",average);
	return 0;
}
