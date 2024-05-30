#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *link;

};
struct node *head = NULL;
struct node *create_node() {
	struct node *newNode = (struct node*)malloc(sizeof(struct node));
	if(newNode == NULL) {
		printf("Out of Memory Space!\n");
		exit(1);
	}
	return newNode;
}

void insert_node_end(int num_Of_Nodes) {
	struct node *newNode, *current;
	int value;
	int i;
	for(i = 0; i < num_Of_Nodes; i++) {
		scanf("%d",&value);
		newNode = create_node();
		newNode->data = value;
		newNode->link = NULL;
		if(head == NULL) {
			head = newNode;
		}
		else {
			current = head;
			while(current->link != NULL) {
				current = current->link;
			}
			current->link = newNode;
		}
	}
}

void insert_node_start(int value) {
	struct node *newNode, *current;
	newNode = create_node();
	newNode->data = value;
	newNode->link = head;
	head = newNode;
}

void insert_node_position(int position, int value) {
	struct node *newNode, *current;
	int i = 1;
	if(position == 0) {
		insert_node_start(value);
		return;
	}
	newNode = create_node();
	newNode->data = value;
	if(head == NULL) {
		head = newNode;
		head->link = NULL;
	}
	else {
		current = head;
		while(current->link != NULL && i < position) {
			current = current->link;
			i++;
		}
		newNode->link = current->link;
		current->link = newNode;
	}
}
void print_nodes() {
	struct node *current;
	current = head;
	while(current != NULL) {
		printf("%d",current->data);
		current = current -> link;
		printf(" ");
	}
	printf("\n");
	
}
int main() {
	int nodeNum;
	scanf("%d",&nodeNum);
	insert_node_end(nodeNum);
	print_nodes();
	insert_node_start(7);
	print_nodes();
	insert_node_position(5, 10);
	print_nodes();
	return 0;
}
