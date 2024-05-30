#include<stdio.h>
#include<stdlib.h>
struct node {
	int value;
	struct node *next;
};
struct node *start = NULL;
struct node *singleLinkedList_new_node() {
	struct node *newNode;
	newNode = (struct node*)malloc(sizeof(struct node));
	if(newNode == NULL) {
		printf("Out of Memory Space\n");
		exit(1);
	}
	return newNode;
}

void singleLinkedList_end(int value) {
	struct node *newNode, *temp;
	newNode = singleLinkedList_new_node();
	newNode->value = value;
	newNode->next = NULL;
	if(start == NULL) {
		start = newNode;
	}
	else {
		temp = start;
		while(temp->next != NULL) {
			temp = temp -> next;
		}
		temp->next = newNode;
	}
}

void singleLinkedList_print_list() {
	struct node *temp;
	temp = start;
	while(temp != NULL) {
		printf("%d\n",temp->value);
		temp = temp -> next;
	}
}



void singleLinkedList_beginning(int value) {
	struct node *newNode, *temp;
	newNode = (struct node*)malloc(sizeof(struct node));
	if(newNode == NULL) {
		printf("Out of Memory Space\n");
		exit(1);
	}
	newNode->value = value;
	newNode->next = start;
	start = newNode;
	
}

void singleLinkedList_insertion(int position, int value) {
	struct node *newNode, *temp;
	int i;
	if(position < 1) {
		singleLinkedList_beginning(value);
		return;
	}
	newNode = singleLinkedList_new_node();
	newNode->value = value;
	
	if(start == NULL) {
		start = newNode;
		start->next = NULL;
	}
	else {
		temp = start;
		i = 1;
		while(temp->next != NULL && i<position) {
			temp = temp -> next;
			i++;
		}
		newNode->next = temp->next;
		temp->next = newNode;
		
	}
}

void singleLinkedList_delete_all() {
	struct node *next, *temp;
	temp = start;
	while(temp != NULL) {
		next = temp -> next;
		printf("DEBUG: The deleted element is: %d\n",temp->value);
		free(temp);
		temp = next;
	}
	start = NULL;
		
}

void singleLinkedList_delete_beginning() {
	struct node *temp;	
	if (start == NULL) {
		return;
	}
	temp = start;
	start = start->next;
	printf("DEBUG: The deleted element is: %d\n",temp->value);
	free(temp);
}

void singleLinkedList_delete_end() {
	struct node *temp, *prev_temp;
	if(start == NULL) {
		return;
	}
	temp = start;
	if (temp->next == NULL){
		start = NULL;
		printf("DEBUG: The deleted element is: %d\n",temp->value);
		free(temp);	
		return;
	}
	
	while(temp->next != NULL){
		prev_temp = temp;
		temp = temp->next;
	}
	
	prev_temp->next = NULL;
	printf("DEBUG: The deleted element is: %d\n",temp->value);
	free(temp);
}

void singleLinkedList_delete_position(int position) {
	struct node *temp, *prev_temp;
	int i;
	if(start == NULL) {
		return;
	}
	temp = start;
	if (temp->next == NULL){
		start = NULL;
		printf("DEBUG: The deleted element is: %d\n",temp->value);
		free(temp);	
		return;
	}
	i = 0;
	while(temp->next != NULL && i < position){
		prev_temp = temp;
		temp = temp->next;
		i++;
	}
	
	prev_temp->next = temp->next;
	printf("DEBUG: The deleted element is: %d\n",temp->value);
	free(temp);
}
int main()
{
	singleLinkedList_end(20);
	singleLinkedList_end(5);
	singleLinkedList_end(10);
	singleLinkedList_end(30);
	singleLinkedList_end(55);
	singleLinkedList_end(70);
	singleLinkedList_end(45);
	singleLinkedList_insertion(3, 35);
	singleLinkedList_print_list();
	singleLinkedList_delete_beginning();
	singleLinkedList_print_list();
	singleLinkedList_delete_end();
	singleLinkedList_print_list();
	singleLinkedList_delete_position(2);
	singleLinkedList_print_list();

	return 0;
}
