#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 10

typedef struct{
	char elem[SIZE];
	int count;
}LISTv1;

typedef struct{
	char elem[SIZE];
	int count;
}*LISTv2, Listv2;

typedef struct{
	char *elemptr;
	int count;
}LISTv3;

typedef struct{
	char *elemptr;
	int count;
}*LISTv4, Listv4;

LISTv1 Lv1;
LISTv2 Lv2;
LISTv3 Lv3;
LISTv4 Lv4;

void initListV1(LISTv1 *L){
	L->count = 0;
}
void initListV2(LISTv2 *L){
	if(*L == NULL)
		*L = calloc(sizeof(Listv2), 1);
}
void initListV3(LISTv3 *L){
	L->elemptr = malloc(SIZE);
	L->count = 0;
}
void initListV4(LISTv4 *L){
	if(*L == NULL){
		*L = calloc(sizeof(Listv4), 1);
		(*L)->elemptr = malloc(SIZE);
	}
}

void insertSorted(LISTv4 *A, char elem){
	int k;
	if((*A)->elemptr != NULL && (*A)->count < SIZE){
		for(k = 0; k < (*A)->count && (*A)->elemptr[k] < elem; k++){}
		memmove(&(*A)->elemptr[k+1],&(*A)->elemptr[k],(*A)->count++ - k);
		(*A)->elemptr[k] = elem;
	}
}
int main(){
	initListV4(&Lv4);
	insertSorted(&Lv4, 'B');
	insertSorted(&Lv4, 'F');
	insertSorted(&Lv4, 'C');
	insertSorted(&Lv4, 'A');
	insertSorted(&Lv4, 'A');
	insertSorted(&Lv4, 'D');
	insertSorted(&Lv4, 'E');
	insertSorted(&Lv4, 'B');
	insertSorted(&Lv4, 'G');
	insertSorted(&Lv4, 'A');
	insertSorted(&Lv4, 'Z');
	
	
	return 0;
}
