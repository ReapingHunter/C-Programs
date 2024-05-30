#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define SIZE 10

typedef struct {
	int data;
	int link;
}Node;

typedef int Dictionary[SIZE];
typedef enum{FALSE, TRUE}boolean;
typedef int Set[];
Set A = {0, 13, 20, 28, 30, 33, 45, 48, 108};
Dictionary D;

int hash(int elem);
void initDic(Dictionary *D);
void displayDic(Dictionary D);
void insert(Dictionary *D, int elem); //Sorted
void populateDic(Set S, Dictionary *D, int size);
void delete(Dictionary *D, int elem);
boolean isMember(Dictionary D, int elem);

int main() {
	return 0;
}

int hash(int elem) {
	return elem % SIZE;
}

void initDic(Dictionary *D) {
	int x;
	for(x = 0; x < SIZE; x++) {
		(*D)[x] = -1;
	}
}

void displayDic(Dictionary D) {
	int x;
	int y;
	for(x = 0; x < SIZE; x++) {
		for(y = D[x]; y != -1; y = D[])
	}
}
