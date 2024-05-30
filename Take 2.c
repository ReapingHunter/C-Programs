#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct {
   int ID;
   char  LN[16], FN[24], MI;  //Lastname, Firstname, Middle Initial
   char course[8];          
   int yearLevel;
}Studrec;
typedef struct node {
    Studrec stud;
    struct node *link;
}StudList;   //Definition of the List

StudList *head;

void insertFirstUnique(int id, char firstname[], char lastname[], char middle, char program[], int year){
	StudList *current, *node;
	if(head == NULL){
		node = malloc(sizeof(StudList));
		node->stud.ID = id;
		strcpy(node->stud.FN, firstname);
		strcpy(node->stud.LN, lastname);
		node->stud.MI = middle;
		strcpy(node->stud.course, program);
		node->stud.yearLevel = year;
		head = node;
	}
	else{
//		for(current = head; current != NULL; current = current->link){}	
		if(current == NULL){
			node = malloc(sizeof(StudList));
			node->stud.ID = id;
			strcpy(node->stud.FN, firstname);
			strcpy(node->stud.LN, lastname);
			node->stud.MI = middle;
			strcpy(node->stud.course, program);
			node->stud.yearLevel = year;
			node->link = head;
			head = node;
		}
	}
}
void printList(){
	StudList *current;
	for(current = head; current->link != NULL; current = current->link){
		printf("%d, %s, %s, %c, %s, %d\n",
		current->stud.ID, 
		current->stud.LN, 
		current->stud.FN, 
		current->stud.MI, 
		current->stud.course, 
		current->stud.yearLevel);
	}
}
int main(){
	insertFirstUnique(1, "Manalili", "Mar", 'A', "BSCS", 2);
	insertFirstUnique(2, "Manalili", "Mar", 'A', "BSCS", 2);
	insertFirstUnique(3, "Manalili", "Mar", 'A', "BSCS", 2);
	insertFirstUnique(4, "Manalili", "Mar", 'A', "BSCS", 2);
	printList();
	
	return 0;
}
