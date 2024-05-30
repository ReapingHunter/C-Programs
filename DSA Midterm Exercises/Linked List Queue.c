#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

//LINKED LIST QUEUE
typedef struct node{
	char elem;
	struct node *next;
}*Node;

typedef struct {
	Node front;
	Node rear;
}Queue;

Queue Q;

void initQueue(Queue *A) {
	A->front = A->rear = NULL;
}

void enqueue(Queue *A, char data) {
	Node node;
	node = (Node)malloc(sizeof(struct node));
	if(node != NULL) {
		node->elem = data;
		node->next = NULL;
		if(A->front == NULL) {
			A->front = node;
		} else {
			A->rear->next = node;
		}
		A->rear = node;
	}
}

void dequeue(Queue *A) {
	Node node;
	if(A->front != NULL) {
		node = A->front;
		A->front = node->next;
		free(node);
		if(A->front == NULL) {
			A->rear = NULL;
		}
	}
	
}

char front(Queue A) {
	return (A.front != NULL)? A.front->elem : '\0';
}

int main() {
	initQueue(&Q);
	enqueue(&Q, 'A');
	enqueue(&Q, 'B');
	enqueue(&Q, 'C');
	enqueue(&Q, 'D');
	enqueue(&Q, 'E');
	enqueue(&Q, 'F');
	dequeue(&Q);
	dequeue(&Q);
	dequeue(&Q);
	printf("%c",front(Q));
	return 0;
}
