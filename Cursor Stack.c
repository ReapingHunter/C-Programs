/*
-=x=-=x=-=x=-=x=-=x=-=x=-=x=-=x=-=x=-=x=-=x=-=x=-=x=-=x=-=x=-

PROGRAM: 
	Header file for Cursor-based implementation of stack ADT

DESCRIPTION:
	Contains: data struct def'ns, function prototypes and def'ns.
	All for the cursor-based implementation.

AUTHORS:
	CALAYCAY, Matthew Cedric
	DURAN, Sean Stefan Louis
	MANALILI, Marlex Lance
	PUMAR, Angelo
	SCHULZ, Jared

-=x=-=x=-=x=-=x=-=x=-=x=-=x=-=x=-=x=-=x=-=x=-=x=-=x=-=x=-=x=-
*/

#include <stdio.h>
#include <stdlib.h>

#define STACK_H
#define MAX 10

typedef int NodePtr;

typedef struct{
	char data;
	NodePtr link;
} Node;

typedef struct {
	Node elements[MAX];
	NodePtr avail;
}VHeap;

typedef struct {
	VHeap *heap;
	NodePtr top;
} Stack;

Stack S;

// PROTOTYPES

// -> Mngment fns
void initHeap(VHeap *vh);
int alloc(VHeap *vh);
void dealloc(VHeap *vh, NodePtr ptr);

// -> Stack operations
void initStack(Stack *s);
int isEmpty(Stack s);
char getTop(Stack s);
void push(Stack *s, char elem);
void pop(Stack *s);
void makeNull(Stack *s);
void displayStack(Stack s);

// DEFINITIONS

// -> Mngment fns
void initHeap(VHeap *vh){
	int ndx;
	
	vh->avail = MAX-1;
    for(ndx=MAX-1; ndx>=0; ndx--){
    	vh->elements[ndx].link = ndx-1;
	}
}

NodePtr alloc(VHeap *vh){
	NodePtr temp;
	temp = vh->avail;
	if(temp!=-1){
		vh->avail = vh->elements[temp].link;
	}
	
	return temp;
}

void dealloc(VHeap *vh, NodePtr ptr){
	if(ptr < MAX && ptr >-1){
		vh->elements[ptr].link = vh->avail;
		vh->avail = ptr;
	}
}

// -> Stack operations
void initStack(Stack *s){
    s->top = -1;
    s->heap = (VHeap*) malloc(sizeof(VHeap));
    initHeap(s->heap);
}

void push(Stack *s, char elem){
	NodePtr temp = alloc(s->heap);
	if(temp != -1){
		s->heap->elements[temp].data = elem;
		s->heap->elements[temp].link = s->top;
		s->top = temp;
	}
}

void pop(Stack *s){
	NodePtr temp;
	
	temp = s->top;
	if(temp != -1){
		s->top = s->heap->elements[temp].link;
		dealloc(s->heap, temp);
	}
}

void makeNull(Stack *s){
	for(;!isEmpty(*s);pop(s)){}
}

int isEmpty(Stack s){
	return s.top == -1;
}

int isFull(Stack s){
	return s.top == MAX-1;
}

char getTop(Stack s){
	char retVal; 
	if(!isEmpty(s)){
		retVal = s.heap->elements[s.top].data;
	}else{
		retVal = '\0';
	}
	
	return retVal;
}


void displayStack(Stack s){
	Stack b;
	
	if(isEmpty(s)){
		printf("Empty stack\n");
	}else{
		initStack(&b);
		printf("[TOP] ");
		while(!isEmpty(s)){
			printf("%c ", getTop(s));
			push(&b, getTop(s));
			pop(&s);
		}
		while(!isEmpty(b)){
			push(&s, getTop(b));
			pop(&b);
		}
		printf("[BOTTOM]\n");
	}
}

int main(){
	char K;
	initStack(&S);
	push(&S, 'M');
	push(&S, 'O');
	push(&S, 'N');
	push(&S, 'O');
	push(&S, 'P');
	push(&S, 'O');
	push(&S, 'L');
	push(&S, 'Y');
	K = getTop(S);
	displayStack(S);
	return 0;
}
