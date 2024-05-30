#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define SIZE 10
typedef struct node {
	int data;
	struct node *link;
}*Node;
typedef Node Dictionary[SIZE];
typedef int Set[];
typedef enum{FALSE, TRUE}boolean;
Set A = {0, 13, 20, 28, 30, 33, 45, 48, 108};
Dictionary D;

int hash(int elem);
void initDic(Dictionary *D);
void displayDic(Dictionary D);
void insert(Dictionary *D, int elem); //Sorted
void populateDic(Set S, Dictionary *D, int size);
void delete(Dictionary *D, int elem);
boolean isMember(Dictionary D, int elem);

int main() {
	//Task 1
	
	initDic(&D);
	displayDic(D);
	//Task 2
	
	insert(&D, 31);
	insert(&D, 64);
	insert(&D, 44);
	insert(&D, 23);
	insert(&D, 48);
	insert(&D, 29);
	insert(&D, 44);
	insert(&D, 17);
	displayDic(D);
	//Task 3
	
	populateDic(A, &D, sizeof(A) / sizeof(A[0]));
	displayDic(D);
	//Task 4
	
	delete(&D, 20);
	delete(&D, 44);
	delete(&D, 17);
	delete(&D, 17);
	displayDic(D);
	//Task 5
	
	printf("%d\n",isMember(D, 108));
	printf("%d",isMember(D, 47));
	
	return 0;
}

int hash(int elem) {
	return elem % 10;
}

void initDic(Dictionary *D) {
	int x;
	for(x = 0; x < SIZE; x++) {
		(*D)[x] = NULL;
	}
}

void displayDic(Dictionary D) {
	int x;
	Node current;
	printf("============================================================\n");
	for(x = 0; x < SIZE; x++) {
		printf("[%d] => ",x);
		if(D[x] != NULL) {
			for(current = D[x]; current != NULL; current = current->link) {
				printf("%5d",current->data);
			}
		}
		printf("\n");
	}
}

void insert(Dictionary *D, int elem) {
	Node *current, node, scan;
	int hashNdx;
	hashNdx = hash(elem);
	for(scan = (*D)[hashNdx]; scan != NULL && scan->data != elem; scan = scan->link) {}
	if(scan == NULL) {
		node = (Node)malloc(sizeof(struct node));
		if(node != NULL) {	
			node->data = elem;
			if((*D)[hashNdx] == NULL) {
				node->link = (*D)[hashNdx];
				(*D)[hashNdx] = node;
			} else {
				for(current = &(*D)[hashNdx]; *current != NULL && (*current)->data < elem; current = &(*current)->link) {}
				node->link = *current;
				*current = node;
			}
		}
	}
		
}

void populateDic(Set S, Dictionary *D, int size) {
	int x;
	for(x = 0; x < size; x++) {
		insert(D, S[x]);
	}
}


void delete(Dictionary *D, int elem) {
	Node *current, node;
	int hashNdx;
	hashNdx = hash(elem);
	if((*D)[hashNdx] != NULL) {
		for(current = &(*D)[hashNdx]; *current != NULL && (*current)->data != elem; current = &(*current)->link){}
		if(current != NULL) {
			node = *current;
			*current = (*current)->link;
			free(node);
		}
	}
}

boolean isMember(Dictionary D, int elem) {
	Node current;
	int hashNdx;
	hashNdx = hash(elem);
	for(current = D[hashNdx]; current != NULL && current->data != elem; current = current->link) {}
	return(current != NULL)? TRUE : FALSE;
}












