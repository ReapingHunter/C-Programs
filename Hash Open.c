#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX 26
typedef struct node{
	char data[30];
	struct node *link;
}*Set, *Dictionary[MAX];

Dictionary A;

int hash(char elem[]) {
	return toupper(elem[0]) - 'A';
}

void initList(Dictionary *D) {
	int x;
	for(x = 0; x < MAX; x++) {
		(*D)[x] = NULL;
	}
}

void insertSorted(Dictionary *D, char elem[]) {
	Set *current, node, scan;
	int hashNdx;
	node = (Set)malloc(sizeof(struct node));
	if(node != NULL) {
		hashNdx = hash(elem);
		strcpy(node->data, elem);
		if((*D)[hashNdx] == NULL) {
			node->link = (*D)[hashNdx];
			(*D)[hashNdx] = node;
		} else {
			for(scan = (*D)[hashNdx]; scan != NULL && strcmp(scan->data, elem) != 0; scan = scan->link) {}
			if(scan == NULL) {
				for(current = &(*D)[hashNdx]; *current != NULL && strcmp((*current)->data, elem) < 0; current = &(*current)->link){}
				node->link = *current;
				*current= node;
			}
			
		}
	}
}

void printList(Dictionary D) {
	Set current;
	int x;
	for(x = 0; x < MAX; x++) {
		for(current = D[x]; current != NULL; current = current->link) {
			printf("%s\n",current->data);
		}
	}
}

int main() {
	initList(&A);
	insertSorted(&A, "Marlex");
	insertSorted(&A, "Nae");
	insertSorted(&A, "Ced");
	insertSorted(&A, "Simone");
	insertSorted(&A, "Dictionary");
	insertSorted(&A, "Duran");
	insertSorted(&A, "Schulz");
	insertSorted(&A, "Armageddon");
	insertSorted(&A, "Jared");
	insertSorted(&A, "Pumar");
	insertSorted(&A, "David");
	insertSorted(&A, "Samuel");
	insertSorted(&A, "Armageddon");
	insertSorted(&A, "Mono");
	insertSorted(&A, "Poly");
	insertSorted(&A, "Devonia");
	insertSorted(&A, "Triclops");
	insertSorted(&A, "Defection");
	printList(A);
	return 0;
}
