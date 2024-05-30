#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 10
typedef struct{
	char data;
	int link;
}Array;

typedef struct{
	Array nodes[MAX];
	int avail;
}VHeap;

VHeap C;

void initHeap(VHeap *A){
	int k;
	for(k = 0; k < MAX; k++){
		A->nodes[k].link = k - 1;
	}
	A->avail = 0;
}

void allocSpace(VHeap *A, int p){
	int k;
	if(p >= 0 && p < MAX){
		for(k = 0; k < MAX && A->nodes[k].link != -1; k++){}
		A->nodes[k].link = p;
		A->nodes[p].link = -1;
		A->avail = p;
	}
	
	
}

void deallocSpace(VHeap *A, int p){
	A->nodes[p].link = -1;
	A->avail = p;
}

int main(){
	initHeap(&C);
	allocSpace(&C, 5);
	allocSpace(&C, 3);
	allocSpace(&C, 7);
	allocSpace(&C, 9);
	deallocSpace(&C, 4);
	deallocSpace(&C, 2);
	deallocSpace(&C, 6);
	return 0;
}
