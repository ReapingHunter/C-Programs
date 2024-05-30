#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node{
	int elem;
	struct node *link;
}*SET;

SET A;
SET B;
SET C;

void addElem(SET *X, int data) {
	SET scan, *current, node;
	for(scan = *X; scan != NULL && scan->elem != data; scan = scan->link) {}
	if(scan == NULL) {
		node = (SET)malloc(sizeof(struct node));
		node->elem = data;
		if(*X == NULL) {
			node->link = *X;
			*X = node;
		}
		else {
			for(current = X; *current != NULL && (*current)->elem < data; current = &(*current)->link){}
			node->link = *current;
			*current = node;
		}
	}
}

void Union(SET X, SET Y, SET *Z) {
	SET *current, node, trav;
	for(trav = X; trav != NULL; trav = trav->link){
		node = (SET)malloc(sizeof(struct node));
		if(*Z == NULL){
			node->link = *Z;
			node->elem = trav->elem;
			*Z = node;
		}
		else {
			for(current = Z; *current != NULL && (*current)->elem < trav->elem; current = &(*current)->link){}
			node->link = *current;
			*current = node;
		}
	}

}
int main() {
	addElem(&A, 1);
	addElem(&A, 4);
	addElem(&A, 7);
	addElem(&A, 3);
	addElem(&A, 5);
	Union(A, B, &C);
}
