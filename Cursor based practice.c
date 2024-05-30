#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 10
typedef struct{
	char data;
	int link;
}Node;

typedef struct{
	Node arr[max];
	int avail;
}VHeap;

typedef int CList;

VHeap V;

void initHeap(VHeap *VH){
	int i;
	for(i =0; i < max; i++){
		VH->arr[i].link = i-1;
	}
	VH->avail = 5;
}

int allocSpace(VHeap *VH){
	int avail;
	avail = VH->avail;
	if(avail != -1){
		VH->avail = VH->arr[avail].link;
	}
	return avail;
}

void deallocSpace(VHeap *VH, int ndx){
	if(ndx < max && ndx > -1){
		VH->arr[ndx].link = VH->avail;
		VH->avail = ndx;
	}
}

int main(){
	int avail;
	initHeap(&V);
	avail = allocSpace(&V);
	return 0;
}
