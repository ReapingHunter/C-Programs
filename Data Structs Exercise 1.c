#include<stdlib.h>
#include<stdio.h>
#include<string.h>

/*Write the code of the function that will insert a given element at the first 
position of the given list if the element does not yet exist. Elements are uniquely 
identified through the ID number. */

typedef struct {
   int ID;
   char  LN[16], FN[24], MI;  //Lastname, Firstname, Middle Initial
   char course[8];          
   int yearLevel;
}Studrec;
typedef struct node {
    Studrec stud;
    struct node *link;
}*StudList;   //Definition of the List

StudList head;

void insertFirstUnique(StudList *head, int id, char firstname[], char lastname[], char middle, char course[], int year){
	StudList *current, node;
	for(current = head; (*current) != NULL && (*current)->stud.ID != id; current = &(*current)->link){}
	if((*current) == NULL){
		node = malloc(sizeof(struct node));
		node->stud.ID = id;
		strcpy(node->stud.FN, firstname);
		strcpy(node->stud.LN, lastname);
		node->stud.MI = middle;
		strcpy(node->stud.course, course);
		node->stud.yearLevel = year;
		node->link = *head;
		*head = node;
	}
}

StudList deleteElemID(StudList *head, int id){
	StudList *current, node;
	for(current = head; (*current) != NULL && (*current)->stud.ID != id; current = &(*current)->link){}
	if((*current) == NULL){
		node = malloc(sizeof(struct node));
		node->stud.ID = 0;
		strcpy(node->stud.FN, "XXXXX");
		strcpy(node->stud.LN, "XXXXX");
		node->stud.MI = 0;
		strcpy(node->stud.course, "XXXXX");
		node->stud.yearLevel = 0;
	}
	else{
		node = *current;
		(*current) = (*current)->link;
		node->link = NULL;
	}
	return node;
}
void printList(StudList *head){
	StudList *current;
	for(current = head; (*current) != NULL; current = &(*current)->link){
		printf("%d, %s, %s, %c, %s, %d\n",
		(*current)->stud.ID,
		(*current)->stud.FN,
		(*current)->stud.LN,
		(*current)->stud.MI,
		(*current)->stud.course,
		(*current)->stud.yearLevel);
	}
}
int main(){
	StudList node;
	insertFirstUnique(&head, 1, "Marlex Lance", "Manalili", 'A', "BSCS", 2);
	insertFirstUnique(&head, 2, "The", "Keeper", 'K', "???", 4);
	insertFirstUnique(&head, 3, "The", "Seeker", 'S', "???", 4);
	insertFirstUnique(&head, 4, "The", "Watcher", 'W', "???", 4);
	node = deleteElemID(&head, 2);
	printList(&head);

	return 0;
}
