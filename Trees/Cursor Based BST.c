#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 0XC
typedef struct {
	char data[8];
	int LC;
	int RC;
}TreeNode;

typedef struct {
	TreeNode node[MAX];
	int avail;
}VHeap;
typedef int BST; //header or root;

void initCursorTree(BST *B, VHeap *V);
void insert(BST *B, VHeap *V, char *elem);
void deleteByElem(BST *B, VHeap *V, char *elem);
void displayAscending(BST B, VHeap V);
void displayVHeap(VHeap V);

int main() {
	BST root;
	VHeap VH;
	initCursorTree(&root, &VH);
	displayVHeap(VH);
	insert(&root, &VH, "1100");
	insert(&root, &VH, "1209");
	insert(&root, &VH, "1053");
	insert(&root, &VH, "1158");
	insert(&root, &VH, "1126");
	insert(&root, &VH, "1734");
	insert(&root, &VH, "1454");
	insert(&root, &VH, "1258");
	insert(&root, &VH, "1126");
	insert(&root, &VH, "1440");
	insert(&root, &VH, "1358");
	insert(&root, &VH, "1258");
	insert(&root, &VH, "1990");
	insert(&root, &VH, "1111");
	insert(&root, &VH, "1211");
	displayVHeap(VH);
	displayAscending(root, VH);
	printf("\n\n\n");
	deleteByElem(&root, &VH, "1209");
	displayVHeap(VH);
	displayAscending(root, VH);
	deleteByElem(&root, &VH, "1100");
	displayVHeap(VH);
	displayAscending(root, VH);
	deleteByElem(&root, &VH, "1734");
	displayVHeap(VH);
	displayAscending(root, VH);
	deleteByElem(&root, &VH, "1358");
	displayVHeap(VH);
	displayAscending(root, VH);
	deleteByElem(&root, &VH, "1158");
	displayVHeap(VH);
	displayAscending(root, VH);
	return 0;
}

void initCursorTree(BST *B, VHeap *V){
	int x;
	for(x = 0; x < MAX; x++){
		V->node[x].LC = V->node[x].RC = x-1;
		strcpy(V->node[x].data, "\0");
	}
	V->avail = MAX-1;
	*B = -1;
}

void displayVHeap(VHeap V){
	int x;
	printf("\nAvailable Index :: %d",V.avail);
	printf("\n%s%12s%12s%12s","Index","Elem","LC","RC");
	printf("\n%s%12s%12s%12s","-----","----","--","--");
	for(x = 0; x < MAX; x++){
		printf("\n%d%12s%15d%12d", x, V.node[x].data, V.node[x].LC, V.node[x].RC);
	}
	printf("\n\n");
}

void insert(BST *B, VHeap *V, char *elem){
	BST *trav, node;
	if(V->avail != -1){
		for(trav = B; *trav != -1 && strcmp(V->node[*trav].data, elem) != 0; trav = (strcmp(V->node[*trav].data, elem) > 0)? &V->node[*trav].LC : &V->node[*trav].RC){}
		if(*trav == -1){
			node = V->avail;
			V->avail = V->node[node].RC;
			strcpy(V->node[node].data, elem);
			V->node[node].LC = V->node[node].RC = *trav;
			*trav = node;
		} else{
			printf("\nElement %s already exists. Cannot insert.",elem);
		}
	} else{
		printf("\nVHeap is full. Cannot insert element %s.",elem);
	}
}

void deleteByElem(BST *B, VHeap *V, char *elem){
	BST *trav, node;
	for(trav = B; *trav != -1 && strcmp(V->node[*trav].data, elem) != 0; trav = (strcmp(V->node[*trav].data, elem) > 0)? &V->node[*trav].LC : &V->node[*trav].RC){}
	if(*trav != -1){
		node = *trav;
		if(V->node[node].LC != -1 && V->node[node].RC != -1){
			for(trav = &V->node[*trav].RC; V->node[*trav].LC != -1; trav = &V->node[*trav].LC){}
			strcpy(V->node[node].data, V->node[*trav].data);
			node = *trav;
		}
		*trav = (V->node[*trav].LC != -1)? V->node[*trav].LC : V->node[*trav].RC;
		V->node[node].LC = V->node[node].RC = V->avail;
		V->avail = node;
	}
}

void displayAscending(BST B, VHeap V){
	if(B != -1){
		displayAscending(V.node[B].LC, V);
		printf("%s ",V.node[B].data);
		displayAscending(V.node[B].RC, V);
	}
}
