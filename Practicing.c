#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void populateList(employeeInfo) ;
typedef struct {
    char lastName[50];
    char firstName[50];
    char middleInitial;
}employeeName;

typedef struct {
    int employeeID;
    employeeName empInfo;
    char position[50];
    int yrsServed;
}companyInfo;

typedef struct{
    companyInfo records[10];
    int count; //keeps track of how many elements in the list
}companyRecord;

int main() {
	companyRecord *employeeInfo;
	populateList(&employeeInfo);
}

/*1
Ask user for how many employee info to input. Max of 10.
- Last Name
- First Name
- Middle Initial
- Employee ID
- Position in Company
- Years Served
*/
void populateList(companyRecord employeeInfo) {
	int numOfEmp;
	int i;
	scanf("%d",&numOfEmp);
	employeeInfo = (employeeInfo*)malloc(sizeof(employeeInfo) * numOfEmp);
	for(i = 0; i < numOfEmp; i++) {
		printf("Employee %d last name: ",i+1);
		scanf("%s",employeeInfo[i].records.empInfo.lastName);
	}
	for(i = 0; i < numOfEmp; i++) {
		printf("Employee %d first name: ",i+1);
		scanf("%s",employeeInfo[i].records.empInfo.firstName);
	}
	for(i = 0; i < numOfEmp; i++) {
		printf("Employee %d middle name: ",i+1);
		scanf("%c",employeeInfo[i].records.empInfo.middleInitial);
	}
	for(i = 0; i < numOfEmp; i++) {
		printf("Employee %d middle name: ",i+1);
		scanf("%d",employeeInfo[i].records.employeeID);
	}
}

/*2
    Display all empoyees based on the yrs served from highest to lowest
*/
void sortYears();

/*3
Get all employees who have served more than 10 years and create a separate list / array for them. Return this back to main.
*/
void getLoyal();

/*4
Display the current list
*/
void displayRecord();

/*5
Display current loyal list
*/
void DisplayLoyal();

/*6
Quit Program
*/
