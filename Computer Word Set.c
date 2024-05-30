#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef unsigned char SET;

SET A;
SET B = 149;
SET C;
SET D = 150;

void initSet(SET *X) {
	*X = 0;
}

void displayBitPattern(SET X) {
	int mask;
	for(mask = sizeof(SET) << 8 - 1; mask != 0; mask >>= 1) {
		printf("%d",((mask & X) != 0)? 1:0);
	}
	printf("\n");
}

void displayElement(SET X){
	int mask;
	int j;
	for(mask = sizeof(SET) << 8 - 1, j = sizeof(SET) * 8 - 1; mask != 0; mask >>= 1, j--) {
		if((mask & X) != 0) {
			printf("%d ",j);
		}
	}
	printf("\n");
}

void insert(SET *X, int elem) {
	*X |= sizeof(SET) << elem;
}

void Delete(SET *X, int elem) {
	*X &= ~(sizeof(SET) << elem);
}

int member(SET X, int elem) {
	return ((X & sizeof(SET) << elem) != 0)? 1:0;
}

SET Union(SET X, SET Y) {
	return X | Y;
}

SET Intersection(SET X, SET Y) {
	return X & Y;
}

SET Difference(SET X, SET Y) {
	return X & ~Y;
}

int main(){
	printf("%c\n",B);
	displayBitPattern(B);
	displayElement(B);
	insert(&B, 5);
	insert(&B, 6);
	displayBitPattern(B);
	displayElement(B);
	Delete(&B, 4);
	displayBitPattern(B);
	displayElement(B);
	printf("%d\n",member(B, 4));
	insert(&A, 1);
	insert(&A, 2);
	insert(&A, 6);
	displayBitPattern(A);
	displayBitPattern(B);
	C = Union(A,B);
	displayBitPattern(C);
	displayElement(C);
	C = Intersection(A,B);
	displayBitPattern(C);
	displayElement(C);
	displayBitPattern(B);
	displayBitPattern(A);
	C = Difference(B,A);
	displayBitPattern(C);
	displayElement(B);
	displayElement(A);
	displayElement(C);
	initSet(&D);
	displayElement(D);
	return 0;
}
