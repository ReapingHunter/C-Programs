#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

typedef char Set;
typedef enum{TRUE, FALSE}boolean;

Set A = 149;

boolean isMember(Set S, int elem) {
	return (S & (sizeof(Set) << elem))? TRUE : FALSE;
}

void insert(Set *S, int elem) {
	*S |= sizeof(Set) << elem;
}

void delete(Set *S, int elem) {
	*S &= ~(sizeof(Set) << elem);
}

void print(Set S) {
	int mask;
	for(mask = sizeof(Set) << 8-1; mask != 0; mask >>= 1) {
		printf("%d",(mask & S)? 1:0);
	}
	printf("\n");
}

int main() {
	print(A);
	insert(&A, 5);
	print(A);
	insert(&A, 6);
	print(A);
	delete(&A, 7);
	print(A);
	return 0;
}
