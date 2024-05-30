#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 8

typedef struct {
	char elem[MAX];
	int top;
}Stack;

Stack S;

void initializeStack(Stack *A) {
	A->top = MAX;
}

bool isEmpty(Stack A) {
	return(A.top == MAX)? true:false;
}

bool isFull(Stack A) {
	return(A.top == 0)? true:false;
}

void PUSH(Stack *A, char data) {
	if(!isFull(*A)) {
		A->top -= 1;
		A->elem[A->top] = data;
	}
}

void POP(Stack *A) {
	if(!isEmpty(*A)) {
		A->top += 1;
	}
}

char TOP(Stack A) {
	return A.elem[A.top];
}

int main() {
	initializeStack(&S);
	PUSH(&S, 'S');
	PUSH(&S, 'T');
	PUSH(&S, 'A');
	PUSH(&S, 'C');
	PUSH(&S, 'K');
	PUSH(&S, 'E');
	PUSH(&S, 'R');
	PUSH(&S, 'S');
	printf("%d",isEmpty(S));
	return 0;
}
