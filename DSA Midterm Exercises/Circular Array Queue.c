#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define MAX 8

typedef struct {
	char data[MAX];
	int front;
	int rear;
}Queue;

Queue Q;

void initQueue(Queue *A) {
	A->front = 0;
	A->rear = MAX-1;
}

bool isFull(Queue A) {
	return(A.front == (A.rear + 2) % MAX)? true : false;
}

bool isEmpty(Queue A) {
	return(A.front == (A.rear + 1) % MAX)? true : false;
}

void enqueue(Queue *A, char elem) {
	if(!isFull(*A)) {
		A->rear = (A->rear + 1) % MAX;
		A->data[A->rear] = elem;
	}
}

void dequeue(Queue *A) {
	if(!isEmpty(*A)) {
		A->front = (A->front + 1) % MAX;
	}
}

char front(Queue A) {
	return(!isEmpty(A))? A.data[A.front] : '\0';
}
int main() {
	initQueue(&Q);
	enqueue(&Q, 'M');
	enqueue(&Q, 'N');
	enqueue(&Q, 'O');
	enqueue(&Q, 'P');
	enqueue(&Q, 'Q');
	enqueue(&Q, 'R');
	enqueue(&Q, 'S');
	enqueue(&Q, 'T');
	enqueue(&Q, 'U');
	enqueue(&Q, 'V');
	dequeue(&Q);
	dequeue(&Q);
	dequeue(&Q);
	dequeue(&Q);
	dequeue(&Q);
	dequeue(&Q);
	printf("%c",front(Q));
	return 0;
}
