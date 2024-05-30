#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define VH_MAX 0xff
#define MAX 0xA
typedef struct{
	char FN[24], LN[16], MI;
}nametype;

typedef struct {
	char ID[10];
	nametype name;
	char course[8];
	int yrLevel;
}studRec;

typedef struct{
	studRec stud;
	int link; // -1 if not pointing to any CBnode
}CBnode;

/* Definition of virtual heap */
typedef struct VH{
	CBnode heap[VH_MAX];
	int avail;
}*Vheap;

/*Definition of Cursor List*/
typedef int CursorList;

/*Definition of Array List*/
typedef struct node{
	studRec data[MAX];
	int studCtr;
}*ArrayList;

Vheap initVHeap();
void initCursorList(CursorList *C);
ArrayList initArrayList();
void populateArrayList(ArrayList *A);
void populateCursorList(CursorList *C, Vheap *VH);
int insertCList(ArrayList A, CursorList *C, Vheap *VH);
void displayArrayList(ArrayList A);
void displayCursorList(CursorList C, Vheap VH);
int main(){
	int count;
	Vheap V;
	CursorList head;
	ArrayList studentList;
	V = initVHeap();
	initCursorList(&head);
	studentList = initArrayList();
	populateArrayList(&studentList);
	populateCursorList(&head, &V);
	displayArrayList(studentList);
	displayCursorList(head, V);
	count = insertCList(studentList, &head, &V);
	printf("%d\n", count);
	displayCursorList(head, V);
	return 0;
}

Vheap initVHeap(){
	Vheap VH;
	VH = (Vheap)malloc(sizeof(struct VH));
	int x;
	for(x = 0; x < VH_MAX; x++){
		VH->heap[x].link = x - 1;
	}
	VH->avail = VH_MAX - 1;
	return VH;
}

void initCursorList(CursorList *C){
	*C = -1;
}

ArrayList initArrayList(){
	ArrayList A;
	A = (ArrayList)malloc(sizeof(struct node));
	A->studCtr = 0;
	return A;
}

void populateArrayList(ArrayList *A){
	static int COUNT = 7;
	int x;
	studRec students[] = {{"100", {"Marlex Lance", "Manalili", 'A'}, "BSCS", 2},
						  {"200", {"The", "Keeper", 'K'}, "BSCS", 4},
						  {"150", {"The", "Seeker", 'S'}, "BSIS", 3},
						  {"190", {"John", "Doe", 'D'}, "BSCS", 1},
						  {"133", {"Jane", "Doe", 'D'}, "BSCS", 1},
						  {"190", {"Matthew", "Jones", 'M'}, "BSIT", 3},
						  {"121", {"Timon", "Thy", 'T'}, "BSCS", 1}};
	for(x = 0; x <= COUNT; x++){
		(*A)->data[x] = students[x];
	}
	(*A)->studCtr = COUNT;
}

void populateCursorList(CursorList *C, Vheap *VH){
	static int COUNT = 8;
	studRec students[] = {{"110", {"Marlex Lance", "Manalili", 'A'}, "BSCS", 2},
						  {"220", {"The", "Keeper", 'K'}, "BSCS", 4},
						  {"166", {"The", "Seeker", 'S'}, "BSIS", 3},
						  {"144", {"John", "Doe", 'D'}, "BSCS", 1},
						  {"133", {"Jane", "Doe", 'D'}, "BSCS", 1},
						  {"111", {"Matthew", "Jones", 'M'}, "BSIT", 3},
						  {"125", {"Timon", "Thy", 'T'}, "BSCS", 1},
						  {"178", {"Adam", "Slade", 'B'}, "BSN", 3}};
	CursorList *trav, node;
	int x;
	for(x = 0; x <= COUNT; x++){
		if((*VH)->avail != -1){
			for(trav = C; *trav != -1 && strcmp((*VH)->heap[*trav].stud.ID, students[x].ID) < 0; trav = &(*VH)->heap[*trav].link){}
			if(strcmp((*VH)->heap[*trav].stud.ID, students[x].ID) != 0){
				node = (*VH)->avail;
				(*VH)->avail = (*VH)->heap[node].link;
				(*VH)->heap[node].stud = students[x];
				(*VH)->heap[node].link = *trav;
				*trav = node;
			}
		}
		
	}
}

void displayArrayList(ArrayList A){
	int x;
	for(x = 0; x < A->studCtr; x++){
		printf("%s ",A->data[x].ID);
	}
	printf("\n");
}

void displayCursorList(CursorList C, Vheap VH){
	CursorList trav;
	for(trav = C; VH->heap[trav].link != -1; trav = VH->heap[trav].link){
		printf("%s ",VH->heap[trav].stud.ID);
	}
	printf("\n");
}

int insertCList(ArrayList A, CursorList *C, Vheap *VH){
	CursorList *trav, node;
	int x, insCount = 0;
	if((*VH)->avail != -1){
		for(x = 0; x < A->studCtr; x++){
			for(trav = C; *trav != -1 && strcmp((*VH)->heap[*trav].stud.ID, A->data[x].ID) < 0; trav = &(*VH)->heap[*trav].link){}
			if(strcmp((*VH)->heap[*trav].stud.ID, A->data[x].ID) != 0){
				node = (*VH)->avail;
				(*VH)->avail = (*VH)->heap[node].link;
				(*VH)->heap[node].stud = A->data[x];
				(*VH)->heap[node].link = *trav;
				*trav = node;
				insCount++;
			}
		}
	}
	return insCount;
}


