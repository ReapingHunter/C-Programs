#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
	int value;
	struct node *link;
};
struct node *head = NULL;
int numOfNodes = 1;
struct node *createNode(){
	struct node *newNode = (struct node*)malloc(sizeof(struct node));
	if(newNode == NULL){
		printf("Out of memory space!");
		exit(1);
	}
	return newNode;
}

int Input(int value){
	printf("First Input: ");
	scanf("%d",&value);
	return value;
}

int node_input(int value){
	printf("Node %d: ",numOfNodes++);
	scanf("%d",&value);
	return value;
}

void createDiffNode(int FirstInput){
	struct node *newNode, *nextNode, *current;
	int input; 
	do{
		newNode = createNode();
		nextNode = createNode();
		input = node_input(input);
		newNode->value = input;
		nextNode->value = FirstInput - input;
		newNode->link = nextNode;
		nextNode->link = NULL;
		if(head == NULL){
			head = newNode;
		}
		else{
			current = head;
			while(current->link != NULL){
				current = current->link;
			}
			current->link = newNode;
		}

		printf("Node %d: %d\n",numOfNodes++, nextNode->value);

	}while(input != 0);
	
	
}

void printNode(){
	struct node *current;
	int i = 1;
	current = head;
	while(current != NULL){
		if(current->value >= 0){
			printf("\nNode %d: %d",i++,current->value);
		}
		current = current->link;
	}
}

void sortNodeDescending(){
	struct node *i, *j;
	int temp;
	for(i = head; i != NULL; i = i->link){
		for(j=i; j!= NULL; j = j->link){
			if(i->value < j->value){
				temp = i->value;
				i->value = j->value;
				j->value = temp;
			}
		}
	}
}
int main(){
	int firstInput = Input(firstInput);
	createDiffNode(firstInput);
	sortNodeDescending();
	printNode();
	return 0;
}


