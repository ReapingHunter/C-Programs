#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char FN[24];
	char MI;
	char LN[16];
} Nametype;

typedef struct{
	Nametype name;
	int ID;
	char course[8];
	int yrLevel;
} Studtype;

typedef struct node {
	Studtype stud;
	struct node *link;
} *LIST;

LIST A;

void displayHeader();
void displayStudent(LIST S);
void insertSort(LIST *L, Studtype elem);
void readFile(FILE *F, LIST *L);

int main() {
	FILE *fp;
	
	fp = fopen("linkedliststudents.dat", "rb");
	if(fp == NULL) {
		printf("Cannot open file...");
	} else {
		readFile(fp, &A);
		displayHeader();
		displayStudent(A);
	}
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
	int x;
	for(x = 1, current = L; current != NULL; current = current->link, x++) {
		printf("\n%-10d", current->stud.ID);
		printf("%-16s", current->stud.name.LN);
		printf("%-24s", current->stud.name.FN);
		printf("%-3c", current->stud.name.MI);
		printf("%-8s", current->stud.course);
		printf("%5d", current->stud.yrLevel);
		printf("\n");
		if(x % 20 == 0) {
			system("pause");
		}
	}
	

}

void insertSort(LIST *L, Studtype elem) {
	LIST *current, node;
	node = (LIST)malloc(sizeof(struct node));
	if(node != NULL) {
		for(current = L; *current != NULL && (*current)->stud.ID < elem.ID; current = &(*current)->link){}
		node->stud = elem;
		node->link = *current;
		*current = node;
	}
}

void readFile(FILE *F, LIST *L) {
	Studtype temp;
	while(fread(&temp, sizeof(Studtype), 1, F)) {
		insertSort(L, temp);
	}
	
}
