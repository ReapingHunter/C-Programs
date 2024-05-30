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
	SET *current, node;
	while(X != NULL && Y != NULL){
		node = (SET)malloc(sizeof(struct node));
		if(node != NULL){
			if(X->elem == Y->elem){
				node->elem = X->elem;
				if(*Z == NULL){
					node->link = *Z;
					*Z = node;
				}
				else{
					for(current = Z; *current != NULL && (*current)->elem < node->elem; current = &(*current)->link){}
					node->link = (*current)->link;
					(*current)->link = node;
				}
				if(X != NULL){
					X = X->link;
				}
				if(Y != NULL){
					Y = Y->link;
				}
			}
//			else{
//				node->elem = X->elem;
//				if(*Z == NULL){
//					node->link = *Z;
//					*Z = node;
//				}
//				else{
//					for(current = Z; *current != NULL && (*current)->elem < node->elem; current = &(*current)->link){}
//					node->link = (*current)->link;
//					(*current)->link = node;
//				}
//				if(X != NULL){
//					X = X->link;
//				}
//				node = (SET)malloc(sizeof(struct node));
//				if(node != NULL){
//					node->elem = Y->elem;
//					if(*Z == NULL){
//						node->link = *Z;
//						*Z = node;
//					}
//					else{
//						for(current = Z; *current != NULL && (*current)->elem < node->elem; current = &(*current)->link){}
//						node->link = (*current)->link;
//						(*current)->link = node;
//					}
//					if(Y != NULL){
//						Y = Y->link;
//					}
//				}
//			}
		}
	}
}

void printList(SET X) {
	SET current;
	for(current = X; current != NULL; current = current->link) {
		printf("%d",current->elem);
		if(current != NULL){
			printf(" ");
		}
	}
}
int main() {
	addElem(&A, 1);
	addElem(&A, 4);
	addElem(&A, 10);
	addElem(&A, 3);
	addElem(&A, 5);
	addElem(&A, 6);
	addElem(&B, 1);
    addElem(&B, 4);
    addElem(&B, 10);
    addElem(&B, 3);
    addElem(&B, 5);
    addElem(&B, 6);
//	addElem(&A, 8);
//	addElem(&B, 7);
//	addElem(&B, 3);
//	addElem(&B, 6);
//	addElem(&B, 9);
	Union(A, B, &C);
	printList(C);
}
