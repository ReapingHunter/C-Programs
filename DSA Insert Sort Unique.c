#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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

void insertSortUnique(StudList *head, int id, char FN[], char LN[], char MI, char course[], int year){
	StudList *current, *check, node;
	for(check = head; (*check) != NULL && (*check)->stud.ID != id; check = &(*check)->link){}
	if((*check) == NULL){
		for(current = head; (*current) != NULL && (*current)->stud.ID < id; current = &(*current)->link){}
		node = malloc(sizeof(struct node));
		node->stud.ID = id;
		strcpy(node->stud.FN, FN);
		strcpy(node->stud.LN, LN);
		node->stud.MI = MI;
		strcpy(node->stud.course, course);
		node->stud.yearLevel = year;
		node->link = *current;
		*current = node;
	}
}

void printList(StudList *head){
	StudList *current;
	for(current = head; (*current) != NULL; current = &(*current)->link){
		printf("%d, %s, %s %c. %s, %d\n",
		(*current)->stud.ID,
		(*current)->stud.LN,
		(*current)->stud.FN,
		(*current)->stud.MI,
		(*current)->stud.course,
		(*current)->stud.yearLevel);
	}
}
int main(){
	insertSortUnique(&head, 5, "Marlex Lance", "Manalili", 'A', "BSCS", 2);
	insertSortUnique(&head, 1, "Keeper", "The", 'K', "BSCS", 4);
	insertSortUnique(&head, 2, "Seeker", "The", 'S', "BSCS", 4);
	insertSortUnique(&head, 6, "Jester", "The", 'J', "BSCS", 4);
	printList(&head);
	return 0;
}
