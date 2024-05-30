#include<stdio.h>
#include<stdlib.h>

typedef struct {
	char FN[24]; //firstname
	char MI; //middle initial
	char LN[16]; //lastname
}Nametype;

typedef struct {
	Nametype name;
	int ID;
	char course[8]; //BSCS, BSIS, BSIT
	int yrLevel;
}Studtype;

void displayHeader();
void displayStudent(Studtype S);
void writeFile(FILE *fp);

int main() {
	FILE *fp;
	fp = fopen("otherstudents.dat", "wb");
	if(fp == NULL) {
		printf("Cannot open file...");
	} else {
		writeFile(fp);
	}
	fclose(fp);
	return 0;
}

void displayHeader() {
	printf("\n\n");
	printf("%-10s", "ID No.");
	printf("%-16s", "Lastname");
	printf("%-24s", "Firstname");
	printf("%-3s", "MI");
	printf("%-8s", "Course");
	printf("%5s", "Year");
	printf("\n");
	printf("%-10s", "======");
	printf("%-16s", "========");
	printf("%-24s", "=========");
	printf("%-3s", "==");
	printf("%-8s", "======");
	printf("%5s", "====");
}

void displayStudent(Studtype S) {
	printf("\n%-10d", S.ID);
	printf("%-16s", S.name.LN);
	printf("%-24s", S.name.FN);
	printf("%-3c", S.name.MI);
	printf("%-8s", S.course);
	printf("%5d", S.yrLevel);
	printf("\n");
}

void writeFile(FILE *fp) {
	Studtype s[] = {
	{{"Marlex Lance", 'A', "Manalili"}, 20103264, "BSCS", 2},
	{{"The", 'K', "Keeper"}, 1, "BSCS", 4},
	{{"The", 'S', "Seeker"}, 2, "BSIT", 3},
	{{"John", 'D', "Doe"}, 12738495, "BSA", 2},
	{{"Jane", 'D', "Doe"}, 22894054, "BSN", 1}
	};
	fwrite(s, sizeof(Studtype), sizeof(s) / sizeof(s[0]), fp);
}
