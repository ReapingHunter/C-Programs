#include<stdio.h>
#include<stdlib.h>

struct node{
	int value;
	struct node *link;
};
struct node *header = NULL;
struct node *create_node() {
	struct node *newNode;
	newNode = (struct node*)malloc(sizeof(struct node));
	if(newNode == NULL) {
		printf("Out of Memory Space!\n");
		exit(1);
	}
	
	
	return newNode;
}

void single_linked_list_end(int numOfNodes) {
	struct node *newNode;
	struct node *current;
	int i;
	int value;
	if(numOfNodes == 0) {
		printf("Number of Nodes cannot be zero!");
		exit(1);
	}
	for(i = 0; i < numOfNodes; i++) {
		scanf("%d",&value);
		newNode = create_node();
		newNode->value = value;
		newNode->link = NULL;
		if(header == NULL) {
			header = newNode;
		}
		else {
			current = header;
			while(current->link != NULL) {
				current = current->link;
			}
			current->link = newNode;
		}
	}
}

void print_nodes() {
	struct node *current;
	current = header;
	while(current != NULL) {
		printf("%d ",current->value);
		current = current->link;
	}
}

void swap(int *x, int *y) {
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
	
}

void selection_sort_node(int numOfNodes) {
	struct node *i, *j;
	for(i = header; i->link != NULL; i = i->link) {
		for(j=i->link; j != NULL; j = j->link) {
			if(i->value > j->value) {
				swap(&i->value, &j->value);
			}
		}
	}
}


int main() {
	int numOfNodes;
	scanf("%d",&numOfNodes);
	single_linked_list_end(numOfNodes);
	print_nodes();
	printf("\n");
	selection_sort_node(numOfNodes);
	print_nodes();
	return 0;
}
