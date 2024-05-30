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

typedef struct node {
	Studtype stud;
	struct node *link;
}*LIST;

LIST A;

void displayHeader();
void displayStudent(LIST L);
void populateList(LIST *A);
void insertSort(LIST *L, Studtype S);
void writeFile(FILE *fp, LIST *L);

int main() {
	FILE *fp;
	fp = fopen("linkedliststudents.dat", "wb");
	if(fp == NULL) {
		printf("Cannot open file...");
	} else {
		writeFile(fp, &A);
		displayHeader();
		displayStudent(A);
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

void displayStudent(LIST L) {
	LIST current;
	for(current = L; current != NULL; current = current->link) {
		printf("\n%-10d", current->stud.ID);
		printf("%-16s", current->stud.name.LN);
		printf("%-24s", current->stud.name.FN);
		printf("%-3c", current->stud.name.MI);
		printf("%-8s", current->stud.course);
		printf("%5d", current->stud.yrLevel);
		printf("\n");
	}
	
}

void populateList(LIST *L) {
	int x;
	Studtype students[] = {
		{{"Marlex Lance", 'A', "Manalili"}, 20103264, "BSCS", 2},
		{{"The", 'K', "Keeper"}, 1, "BSCS", 4},
		{{"The", 'S', "Seeker"}, 2, "BSIT", 3},
		{{"The", 'T', "Teacher"}, 3, "BSCS", 5},
		{{"The", 'W', "Watcher"}, 4, "BSA", 1}
	};
	int len = sizeof(students) / sizeof(students[0]);
	for(x = 0; x < len; x++) {
		insertSort(L, students[x]);
	}
}

void insertSort(LIST *L, Studtype S) {
	LIST *current, node;
	node = (LIST)malloc(sizeof(struct node));
	if(node != NULL) {
		for(current = L; *current != NULL && (*current)->stud.ID < S.ID; current = &(*current)->link){}
		node->stud = S;
		node->link = *current;
		*current = node;
	}
}
void writeFile(FILE *fp, LIST *L) {
	populateList(L);
	LIST current;
	for(current = *L; current != NULL; current = current->link){
		fwrite(&(current->stud), sizeof(Studtype), 1, fp);
	}
	
}
