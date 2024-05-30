#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 7

typedef struct node {
	char data;
	struct node *link;
}*List;

typedef struct {
	char elem;
	int link;
}Nodetype;

typedef struct {
	Nodetype Nodes[SIZE];
	int avail; //Holds the index of the 1st available node
}VirtualHeap;

typedef int CList;

List A;
CList C;
VirtualHeap VH;
void insertFirstLL(List *L, char elem) {
	List node;
	node = (List)malloc(sizeof(struct node));
	if(node != NULL) {
		node->data = elem;
		node->link = *L;
		*L = node;
	}
}

void initCursorList(CList *C, VirtualHeap *V) {
	int x;
	V->Nodes[SIZE-1].link = -1;
	for(x = 0; x < SIZE-1; x++) {
		V->Nodes[x].link = x + 1;
	}
	V->avail = 0;
	*C = -1;
}

int allocSpace(VirtualHeap *V) {
	int avail;
	avail = V->avail;
	if(avail != -1) {
		V->avail = V->Nodes[avail].link;
	}
	return avail;
}

void insertFirstCursor(VirtualHeap *V, CList *C, char data) {
	CList node;
	node = allocSpace(V);
	if(node != -1) {
		V->Nodes[node].elem = data;
		V->Nodes[node].link = *C;
		*C = node;
	}
	printf("%d ",*C);
}

void printLL(List L) {
	List current;
	for(current = L; current != NULL; current = current->link) {
		printf("%c",current->data);
	}
}

void printCursorList(CList C, VirtualHeap V) {
	CList current;
	for(current = C; current != -1; current = V.Nodes[current].link) {
		printf("%c",V.Nodes[current].elem);
	}
}
int main() {
	initCursorList(&C, &VH);
	insertFirstCursor(&VH, &C, 'B');
	insertFirstCursor(&VH, &C, 'A');
	insertFirstCursor(&VH, &C, 'C');
	insertFirstCursor(&VH, &C, 'K');
	insertFirstCursor(&VH, &C, 'G');
	insertFirstCursor(&VH, &C, 'A');
	insertFirstCursor(&VH, &C, 'M');
	insertFirstCursor(&VH, &C, 'O');
	insertFirstCursor(&VH, &C, 'N');
	insertFirstCursor(&VH, &C, 'S');
	printCursorList(C, VH);
	return 0;
}
