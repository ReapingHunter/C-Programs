#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 26
typedef struct node {
	char data[30];
	struct node *link;
}*Dictionary[MAX];

Dictionary A;

int hash(char name[]) {
	return toupper(name[0]) - 'A';
}

void insertSorted(Dictionary *D, char elem[]) {
	struct node **current, *node, *scan;
	int hashNdx = hash(elem);
	node = (struct node*)malloc(sizeof(struct node));
	if(node != NULL) {
		strcpy(node->data, elem);
		if((*D)[hashNdx] == NULL) {
			node->link = (*D)[hashNdx];
			(*D)[hashNdx] = node;
		} else {
			for(scan = (*D)[hashNdx]; scan != NULL && strcmp(scan->data, elem) != 0; scan = scan->link){}
			if(scan == NULL) {
				for(current = &(*D)[hashNdx]; *current != NULL && strcmp((*current)->data, elem) < 0; current = &(*current)->link) {}
				node->link = *current;
				*current = node;
			}			
		}
	}
}

void deleteNode(Dictionary *D, char elem[]) {
	struct node **current, *node;
	int hashNdx = hash(elem);
	if((*D)[hashNdx] != NULL) {
		for(current = &(*D)[hashNdx]; current != NULL && strcmp((*current)->data, elem) != 0; current = &(*current)->link) {}
		if(*current != NULL) {
			node = *current;
			*current = (*current)->link;
			free(node);
		}
	}
}

void displayList(Dictionary D) {
	struct node *current;
	int ndx;
	for(ndx = 0; ndx < MAX; ndx++) {
		for(current = D[ndx]; current != NULL; current = current->link) {
			printf("%s\n",current->data);
		}
	}
	
}

int main(){
	insertSorted(&A, "Alpha");
	insertSorted(&A, "Beta");
	insertSorted(&A, "Gamma");
	insertSorted(&A, "Delta");
	insertSorted(&A, "Baa");
	insertSorted(&A, "Bu");
	insertSorted(&A, "Echo");
	insertSorted(&A, "Dio");
	insertSorted(&A, "Pi");
	insertSorted(&A, "Pho");
	insertSorted(&A, "Bo");
	insertSorted(&A, "Zeta");
	insertSorted(&A, "Foxtrot");
	insertSorted(&A, "Victor");
	insertSorted(&A, "Gilead");
	insertSorted(&A, "Delta");
	insertSorted(&A, "Fah");
	insertSorted(&A, "Gold");
	displayList(A);
	printf("\n");
	deleteNode(&A, "Baa");
	deleteNode(&A, "Pho");
	deleteNode(&A, "Pi");
	displayList(A);
	return 0; 
}
