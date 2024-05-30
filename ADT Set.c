#include<stdio.h>
#include<stdlib.h>
#define MAX 10

typedef int SET[MAX];

SET A = {0, 1, 1, 0, 1, 0, 0, 0, 1, 0};
SET B = {0, 0, 0, 0, 1, 0, 1, 0, 1, 1};

SET *Union(SET X, SET Y) {
	int i;
	SET *Z;
	Z = (SET*)malloc(sizeof(SET));
	if(*Z != NULL) {
		for(i = 0; i < MAX; i++) {
			(*Z)[i] = X[i] | Y[i];
		}
	}
	return Z;
}

SET *Intersection(SET X, SET Y) {
	int i;
	SET *Z;
	Z = (SET*)malloc(sizeof(SET));
	if(*Z != NULL) {
		for(i = 0; i < MAX; i++) {
			(*Z)[i] = X[i] & Y[i];
		}
	}
	return Z;
}

SET *Difference(SET X, SET Y) { //WIP
	int i;
	SET *Z;
	Z = (SET*)malloc(sizeof(SET));
	if(*Z != NULL) {
		for(i = 0; i < MAX; i++) {
			(*Z)[i] = X[i]  Y[i];
		}
	}
	return Z;
}

void printSet(SET X) {
	int i;
	for(i = 0; i < MAX; i++) {
		printf("%d",X[i]);
		if(i != MAX-1) {
			printf(", ");
		}
	}
	printf("\n");
}
int main(){
	SET *C;
	SET *D;
	SET *E;
	C = Union(A, B);
	D = Intersection(A, B);
	E = Difference(A, B);
	printSet(*C);
	printSet(*D);
	printSet(*E);
	return 0;
}
