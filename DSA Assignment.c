#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define MAX 10
typedef struct node{
	char data;
	struct node *link;
}*LISTL;

typedef struct{
	char data[MAX];
	int count;
}LISTA;

LISTL L;
LISTA A;
void insertNodeUniqueLL(char data, LISTL *head){
	LISTL *current, node;
	for(current = head; (*current) != NULL && (*current)->data != data; current = &(*current)->link){}
	if((*current) == NULL){
		node = malloc(sizeof(LISTL));
		node->data = data;
		node->link = NULL;
		*current = node;
	}
	
}

void insertNodeLL(char data, LISTL *head){
	LISTL *current, node;
	for(current = head; (*current) != NULL; current = &(*current)->link){}
	if((*current) == NULL){
		node = malloc(sizeof(LISTL));
		node->data = data;
		node->link = NULL;
		*current = node;
	}
	
}
void insertNodeUniqueA(LISTA A[], char data){
	int i;
	if(A->count < MAX){
		for(i = 0; i < A->count && A->data[i] != data; i++){}
		if(i == A->count)
		A->data[A->count++] = data;
	}
}

void insertNodeA(LISTA A[], char data){
	int i;
	if(A->count < MAX){
		for(i = 0; i < A->count; i++){}
		if(i == A->count)
			A->data[A->count++] = data;
	}	
}
void printListL(LISTL *head){
	LISTL *current;
	int i;
	for(current = head; (*current) != NULL; current = &(*current)->link){
		printf("[%0d] -> %c\n",i++, (*current)->data);
	}
}

void printListA(LISTA A){
	int i;
	for(i = 0; i < A.count; i++){
		printf("[%0d] %c\n",i, A.data[i]);
	}
}

void deleteNodeSameLL(LISTL *head, char data){
	LISTL *current, node;
	for(current = head; (*current) != NULL;){
		if((*current)->data == data){
			node = *current;
			*current = (*current)->link;
			free(node);
		}
		else
			current = &(*current)->link;
	}
}

void deleteNodeSameA(LISTA A[], char data){
	int i;
	for(i = 0; i < A->count; i++){
		if(A->data[i] == data)
			memmove(&A->data[i], &A->data[i+1], A->count-- - i);
	}
}

int main(){
	insertNodeLL('A', &L);
	insertNodeLL('B', &L);
	insertNodeLL('C', &L);
	insertNodeLL('D', &L);
	insertNodeLL('B', &L);
	insertNodeLL('C',&L);
	insertNodeLL('C',&L);
	insertNodeLL('D',&L);
	insertNodeLL('A',&L);
	insertNodeA(&A, 'A');
	insertNodeA(&A, 'B');
	insertNodeA(&A, 'C');
	insertNodeA(&A, 'D');
	insertNodeA(&A, 'B');
	insertNodeA(&A, 'A');
	insertNodeA(&A, 'B');
	insertNodeA(&A, 'C');
	insertNodeA(&A, 'D');
	insertNodeA(&A, 'B');
	insertNodeA(&A, 'A');
	insertNodeA(&A, 'B');
	insertNodeA(&A, 'C');
	insertNodeA(&A, 'D');
	printListL(&L);
	printListA(A);
	deleteNodeSameLL(&L, 'C');
	printListL(&L);
	deleteNodeSameA(&A, 'D');
	printListA(A);
	return 0;
}
