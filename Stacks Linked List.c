#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node{
	char data;
	struct node *link;
}*Stack;

Stack head;

void push(Stack *S, char elem){
	Stack node;
	node = (Stack)malloc(sizeof(struct node));
	if(node != NULL){
		node->data = elem;
		node->link = *S;
		*S = node;
	}
}

void pop(Stack *S){
	Stack node;
	if(*S != NULL){
		node = *S;
		*S = node->link;
		free(node);
	}
}

int main(){
	push(&head, 'M');
	push(&head, 'O');
	push(&head, 'N');
	push(&head, 'O');
	push(&head, 'P');
	push(&head, 'O');
	push(&head, 'L');
	push(&head, 'Y');
	push(&head, 'D');
	pop(&head);
	return 0;
	
}
