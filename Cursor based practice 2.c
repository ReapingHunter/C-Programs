#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 9
typedef struct {
	char data;
	int link;
}Node;

typedef struct {
	Node arr[MAX];
	int avail;
}VHeap;

VHeap VH;

void initArray(VHeap *V){
	int k;
	for(k = MAX - 1; k >= 0; k--){
		V->arr[k].link = k - 1;
	}
}

void randomizeArray(VHeap *V){
	V->arr[0].data = 'N';
	V->arr[1].data = 'P';
	V->arr[2].data = 'L';
	V->arr[3].data = 'M';
	V->arr[5].data = 'Y';
	V->arr[6].data = 'O';
	V->arr[7].data = 'O';
	V->arr[8].data = 'O';
	
	V->arr[0].link = 7;
	V->arr[1].link = 6;
	V->arr[2].link = 5;
	V->arr[3].link = 8;
	V->arr[4].link = -1;
	V->arr[5].link = 4;
	V->arr[6].link = 2;
	V->arr[7].link = 1;
	V->arr[8].link = 0;
}

int allocSpace(VHeap *V){
	int avail = V->avail;
	if(avail != -1){
		V->avail = V->arr[avail].link;
	}
	return avail;
}

void deallocSpace(VHeap *V, int ndx){
	if(ndx != -1){
		V->arr[ndx].link = V->avail;
		V->avail = ndx;
	}
}
void printList(VHeap V){
	int k;
	for(k = 3; k != -1; k = V.arr[k].link){
		printf("%c",V.arr[k].data);
	}
}
int main(){
	initArray(&VH);
	randomizeArray(&VH);
	printList(VH);
	return 0;
}
