#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node {
	struct node *left;
	int data;
	struct node *right;
}*Tree;

Tree A;

void initTree(Tree *T) {
	*T = NULL;
}

//Recursion
//void insert(Tree *T, int elem) {
//	Tree *current, node;
//	node = (Tree)malloc(sizeof(struct node));
//	if(node != NULL) {
//		current = T;
//		if(*current != NULL) {
//			((*current)->data > elem)? insert(&(*current)->left, elem) : insert(&(*current)->right, elem);
//		} else {
//			node->data = elem;
//			node->left = *current;
//			node->right = *current;
//			*current = node;
//		}
//	}
//	
//}

//For loop
void insert(Tree *T, int elem) {
	Tree *current, node;
	node = (Tree)malloc(sizeof(struct node));
	if(node != NULL) {
		for(current = T; *current != NULL && (*current)->data != elem; current = ((*current)->data > elem)? &(*current)->left : &(*current)->right){}
		if(*current == NULL) {
			node->data = elem;
			node->left = node->right = *current;
			*current = node;
		}
	}
}

void delete(Tree *T, int elem) {
	Tree *current, node;
	for(current = T; *current != NULL && (*current)->data != elem;){
		current = ((*current)->data > elem)? &(*current)->left : &(*current)->right;
	}
	if(*current != NULL) {
		node = *current;
		if((*current)->left != NULL && (*current)->right != NULL){
			for(current = &(*current)->right; (*current)->left != NULL; current = &(*current)->left){}
			node->data = (*current)->data;
			node = *current;
		}
		*current = ((*current)->left != NULL)? (*current)->left : (*current)->right;
		free(node);
	}
}


int isMember(Tree T, int elem) {
	Tree current;
	for(current = T; current != NULL && current->data != elem; current = (current->data > elem)? current->left : current->right){}
	return (current != NULL)? 1 : 0;
}
void displayInorder(Tree T) {
	if(T != NULL) {
		displayInorder(T->left);
		printf("%d ",T->data);
		displayInorder(T->right);
	}
}

void displayPreorder(Tree T) {
	if(T != NULL) {
		printf("%d ",T->data);
		displayPreorder(T->left);
		displayPreorder(T->right);
	}
}

void displayPostorder(Tree T) {
	if(T != NULL) {
		displayPostorder(T->left);
		displayPostorder(T->right);
		printf("%d ",T->data);
	}
}

int main() {
	int x;
	initTree(&A);
	insert(&A, 70);
	insert(&A, 30);
	insert(&A, 20);
	insert(&A, 40);
	insert(&A, 60);
	insert(&A, 50);
	insert(&A, 80);
	insert(&A, 110);
	insert(&A, 150);
	insert(&A, 120);
	insert(&A, 115);
	insert(&A, 170);
	insert(&A, 200);
	insert(&A, 180);
	insert(&A, 175);
	insert(&A, 90);
	insert(&A, 310);
	insert(&A, 140);
	displayInorder(A);
	printf("\n");
	displayPreorder(A);
	printf("\n");
	displayPostorder(A);
	printf("\n");
	printf("\n");
	displayInorder(A);
	printf("\n");
	delete(&A, 50);
	displayInorder(A);
	printf("\n");
	delete(&A, 115);
	displayInorder(A);
	printf("\n");
	delete(&A, 170);
	displayInorder(A);
	printf("\n");
	delete(&A, 80);
	displayInorder(A);
	printf("\n");
	delete(&A, 180);
	displayInorder(A);
	printf("\n");
	
	delete(&A, 150);
	displayInorder(A);
	printf("\n");
	
	delete(&A, 110);
	displayInorder(A);
	printf("\n");
	
	delete(&A, 70);
	displayInorder(A);
	printf("\n");
	return 0;
}
