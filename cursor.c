#include<stdio.h>
#define MAX 12
typedef struct{
	int data;
	int link;
}NodeType;

typedef struct{
	NodeType nodes[MAX];
	int avail;
}VirtualHeap;

typedef int CLIST;

VirtualHeap VH;
CLIST A;

void initHeap(CLIST *C, VirtualHeap *V){
	int x;
	for(x = 0; x < MAX; x++){
		V->nodes[x].link = (x < MAX - 1)? x + 1 : -1;
	}
	V->avail = 0;
	*C = -1;
}

int allocSpace(VirtualHeap *V){
	int avail = V->avail;
	if(avail != -1){
		V->avail = V->nodes[avail].link;
	}
	return avail;
}

void deallocSpace(VirtualHeap *V, int ndx){
	if(ndx > 0 && ndx < MAX){
		V->nodes[ndx].link = V->avail;
		V->avail = ndx;
	}
}

void insertSorted(CLIST *C, VirtualHeap *V, int elem){
	CLIST *trav, node;
	node = allocSpace(V);
	if(node != -1){
		for(trav = C; *trav != -1 && V->nodes[*trav].data < elem; trav = &V->nodes[*trav].link){}
		V->nodes[node].data = elem;
		V->nodes[node].link = *trav;
		*trav = node;
	}
}

void populateCursorList(CLIST *C, VirtualHeap *V){
	int arr[] = {78, 45, 89, 100, 43, 23, 67, 89};
	int x;
	int len = sizeof(arr) / sizeof(arr[0]);
	for(x = 0; x < len; x++){
		insertSorted(C, V, arr[x]);
	}
}

void printCursorList(CLIST C, VirtualHeap V){
	int trav;
	for(trav = C; trav != -1; trav = V.nodes[trav].link){
		printf("%d ",V.nodes[trav].data);
	}
	printf("\n");
}

void delete(CLIST *C, VirtualHeap *V, int elem){
	CLIST *trav, node;
	for(trav = C; *trav != -1 && V->nodes[*trav].data != elem; trav = &V->nodes[*trav].link){}
	if(*trav != -1){
		node = *trav;
		*trav = V->nodes[*trav].link;
		deallocSpace(V, node);
	}
}
int main(){
	initHeap(&A, &VH);
	populateCursorList(&A, &VH);
	printCursorList(A, VH);
	delete(&A, &VH, 89);
	printCursorList(A, VH);
	return 0;
}
