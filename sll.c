#include <stdio.h>
#include <stdlib.h>

struct node{
	int value;
	struct node *next;
};

struct node *start=NULL;

struct node* sll_new_node(){
	struct node *new_node;
	
	new_node = (struct node*) malloc(sizeof(struct node));
	if (new_node==NULL){
		printf("Out of Memory Space\n");
		exit(1);
	}
	
	return new_node;
}

sll_insert_begin(int value){
	struct node *new_node, *temp;
	
	new_node = sll_new_node();
	new_node->value = value;
	new_node->next = start;
	
	start = new_node;	
}

sll_insert_end(int value){
	struct node *new_node, *temp;
	
	new_node = sll_new_node();
	
	new_node->value = value;
	new_node->next = NULL;
	
	if (start == NULL){
		start = new_node;
	}
	else{
		temp = start;
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = new_node;
	}
}


sll_insert_position(int position, int value){
	struct node *new_node, *temp;
	int i;
	
	if (position < 1) {
		sll_insert_begin(value);
		return;
	}
	
	new_node = sll_new_node();
	new_node->value = value;
	temp = start; i=1;
	while(temp->next != NULL && i<position){
		temp = temp->next;
		i++;
	}
		
	new_node->next = temp->next;
	temp->next = new_node;
}
sll_delete_position(int position){
	struct node *temp, *prev_node;
	int i=1;
	
	if (position < 1) {
		sll_delete_begin();
		return;
	}
	else{
		temp = start->next;
		prev_node = start;
		while(temp->next != NULL && i<position){
			temp = temp->next;
			prev_node = prev_node->next;
			i++;
		}
	}
	printf("DEBUG: The deleted element is: %d\n",temp->value);
	prev_node->next = temp->next;
	free(temp);
}


sll_delete_all(){
	struct node *next, *temp;
	
	temp = start;
	
	while(temp != NULL){
		next = temp->next;
		printf("DEBUG: The deleted element is: %d\n",temp->value);
		free(temp);
		temp = next;
	}
	
	start = NULL;
}

sll_delete_begin(){
	struct node *temp;	
	
	if (start == NULL) return;
	
	temp = start;
	start = start->next;
	printf("DEBUG: The deleted element is: %d\n",temp->value);
	free(temp);
}

sll_delete_end(){
	struct node *temp, *prev_temp;
	
	if (start == NULL) return;
	
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

sll_print_list(){
	struct node *temp;
	
	temp = start;
	
	while (temp != NULL){
		printf("%d ",temp->value);
		temp = temp->next;	
	}
	printf("\n");
}

int main(void)
{
	sll_insert_end(20);
	sll_insert_end(5);
	sll_print_list();
	
	sll_insert_end(10);
	sll_insert_end(7);
	sll_print_list();
	
	sll_insert_begin(100);
	sll_insert_begin(200);
	sll_print_list();
	
	sll_insert_position(2,35);
	sll_insert_position(4,45);
	sll_print_list();
	sll_insert_end(11);
	sll_print_list();
	sll_delete_position(3);
	sll_print_list();
	
	return 0;
}


