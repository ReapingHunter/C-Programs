#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define UNIVERSAL 10

typedef int SET[UNIVERSAL];

SET A = {1, 0, 0, 1, 1, 0, 0, 1, 0, 1};
SET B = {0, 0, 1, 1, 1, 1};
SET *C;

SET *Union(SET X, SET Y) {
	SET *Z;
	int x;
	Z = (SET*)malloc(sizeof(int) * UNIVERSAL);
	for(x = 0; x < UNIVERSAL; x++) {
		(*Z)[x] = X[x] | Y[x];
	}
	return Z;
}

void printSet(SET X) {
	int x;
	for(x = 0; x < UNIVERSAL; x++) {
		printf("%d ",X[x]);
	}
}
int main() {
	C = Union(A, B);
	printSet(*C);
	return 0;
}
