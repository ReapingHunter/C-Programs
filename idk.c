
typedef struct node {
	char data;
	struct node *link;
}*LIST;
typedef struct {
	char data[];
	int count;
}ArrayList;
typedef enum {TRUE, FALSE}Boolean;
void displayElem(LIST L) {
	LIST L;
	
}

void displayElem(ArrayList A) {
	int x;
	for(x = 0; x < A.count; x++) {
		printf("%c", A.data[x]);
	}
}

Boolean findElement(LIST L, char elem) {
	LIST current;
	for(current = L; current != NULL && current->data = elem; current = current->link) {}
	return(current != NULL)? TRUE : FALSE;
}

Boolean findElement(ArrayList A, char elem) {
	int x;
	for(x = 0; x < count && A.data[x] != elem; x++) {}
	return (x != count)? TRUE : FALSE;
}

void deleteFirstOccurence(LIST *L, char elem) {
	LIST *current, node;
	for(current = L; *current != NULL && (*current)->data != elem; current = &(*current)->link){}
	if(*current != NULL) {
		node = *current;
		*current = (*current)->link;
		free(node);
	}
}

void deleteAllOccurence(LIST *L, char elem) {
	LIST *current, node;
	for(current = L; *current != NULL;) {
		if((*current)->data == elem) {
			node = *current;
			*current = node->link;
			free(node);
		} else {
			current = &(*current)->link;
		}
	}
}

