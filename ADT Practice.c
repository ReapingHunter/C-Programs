#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct{
	char lname[20];
	char fname[20];
	char MI;
}empName;

typedef struct{
	int empId;
	empName empInfo;
	char position[20];
	int yrsServed;
}companyInfo;

typedef struct{
	companyInfo employeeList[10];
	int count;
}companyRecord;

companyRecord initializeCompanyRecord();
companyRecord displayAll(companyRecord compRecord);
void sortyears(companyRecord compRecord);
int main(){
	companyRecord compRecord = initializeCompanyRecord();
	displayAll(compRecord);
	return 0;
}

companyRecord initializeCompanyRecord(){
	
	companyRecord compRecord = {{{20103264, {"Manalili", "Marlex Lance", 'A'}, "Student", 1}, 
								 {19023924, {"Keeper", "The", 'F'},"Creator", 8},
								 {20932134, {"Jackson", "Johnny", 'Y'}, "Teacher", 5},
								 {19230458, {"Mark", "Paul", 'K'}, "Janitor", 3}},4};
	return compRecord;
}

companyRecord displayAll(companyRecord compRecord){
	int i;
	for(i = 0; i < compRecord.count; i++){
		printf("\nEmployee ID: %d",compRecord.employeeList[i].empId);
		printf("\nEmployee Name: %s, %s %c.",compRecord.employeeList[i].empInfo.lname, compRecord.employeeList[i].empInfo.fname, compRecord.employeeList[i].empInfo.MI);
		printf("\nEmployee Position: %s",compRecord.employeeList[i].position);
		printf("\nEmployee served for %d years\n",compRecord.employeeList[i].yrsServed);
	}
}
void sortyears(companyRecord compRecord){
	int i;
}
