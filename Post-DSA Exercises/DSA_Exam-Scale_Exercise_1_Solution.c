/******************************************************************

 ******************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VH_SIZE 0XC     // size of Virtual Heap
#define CLOSE_DSIZE 0XC // size of Close Hash Table
#define HEAP_SIZE   0XF   //size of heap

/******************************************************************************
 * Data Structure Definition:                                                 *
 ******************************************************************************/
typedef struct {
  char name[24]; // Chocolate name
  int weight;    // Chocolate weight in grams
} chocoDesc;

typedef struct {
  char prodID[8];     //  product ID uniquely identifies the products
  chocoDesc prodDesc; //  product description
  float prodPrice;    //  product price
  int prodQty;        //  product count or quantity
} product;            //  product record

/********************************************
 *  Linked List Implementation of List/Set  *
 ********************************************/
typedef struct node {
	product prod;
	struct node *link;
}*ChocList;

/**********************************************
 * Closed Hashing with 2 pass loading          *
 **********************************************/
#define EMPTY "empty" // stored in product ID field
#define DELETED "del" // stored in product ID field *

typedef product closeDic[CLOSE_DSIZE]; // Definition of the closed hash dictionary

typedef struct {
	product elem;
	int link;
}prodNode;

/************************
 * Virtual Heap         *
 ************************/
typedef struct {
	prodNode VH_node[VH_SIZE];
	int avail;
}VHeap;

/******************************************
 * Cursor-Based Implementation of SET     *
 ******************************************/
typedef struct {
  int elemIndex; // index of the 1st element in the set
  int count;     // holds the actual number of elements in the set
  VHeap *VHptr;  // holds the pointer to the virtual heap
} cursorSet;

/**********************************************
 * Definition of maxHeap 			          *
 **********************************************/
typedef struct {
	product prod[HEAP_SIZE];
	int count; // Number of elements in an array
}maxHeap;

/**********************************************************
 * Function Prototypes                                    *
 *********************************************************/
void displayProduct(product P);
 
//---List to Set ---
void initList(ChocList *C);
ChocList populateList();
void insertProduct(ChocList *C, product P);
void displayList(ChocList C);
void convertListToSet(ChocList *C);

//---Set to Dictionary ---
void initVHeap(VHeap *VH);
void displayVHeap(VHeap V);
cursorSet initCursorSet(VHeap *VH);
int allocSpace(VHeap *VH);
void freeSpace(VHeap *VH, int index);
int closeHash(char *ID);
void initCloseDic(closeDic CD);
closeDic *convertSetToCloseDic(ChocList *C, VHeap *VH); // Assumes that ChocList has unique elements / has been converted to set
void displayCloseDic(closeDic CD);

//---Dictionary to Max Heap ---
void initHeap(maxHeap *H);
maxHeap convertCloseDicToMaxHeap(closeDic *CD);
void swapProduct(product *x, product *y);
void displayHeap(maxHeap H);
void heapify(maxHeap *H);

int main() {
	ChocList A;
	closeDic *B;
	maxHeap C;
	VHeap V;
	
	printf("\n\n========== Problem #1 :: Convert List to Set ==========");
	A = populateList();
	displayList(A);
	convertListToSet(&A);
	printf("\n\n-----After Conversion-----");
	displayList(A);
	printf("\n\n");
	system("pause");
	system("cls");
	
	printf("\n\n========== Problem #2 :: Convert Set to Close Dictionary ==========");
	initVHeap(&V);
	B = convertSetToCloseDic(&A, &V);
	displayList(A);
	printf("\n\n");
	system("pause");
	system("cls");
	
	printf("\n\n========== Problem #3 :: Convert Close Dictionary to Max Heap ==========");
	C = convertCloseDicToMaxHeap(B);
	displayCloseDic(*B);
	displayHeap(C);
	printf("\n\n");
	system("pause");
	
	return 0;
}

void initList(ChocList *C){
	*C = NULL;
}

ChocList populateList(){
	ChocList C;
	initList(&C);
	product data[] = {
		{"1701", {"Toblerone", 135}, 150.75, 20},
		{"1356", {"Ferrero", 200}, 250.75, 85},
		{"1109", {"Patchi", 50}, 99.75, 35},
		{"1550", {"Cadbury", 120}, 200.00, 30},
		{"1807", {"Mars", 100}, 150.75, 20},
		{"1201", {"Kitkat", 50}, 97.75, 40},
		{"1450", {"Ferrero", 100}, 150.50, 50},
		{"1701", {"Toblerone", 50}, 90.75, 80},
		{"1601", {"Meiji", 75}, 75.50, 60},
		{"1310", {"Nestle", 100}, 124.50, 70},
		{"1807", {"Valor", 120}, 149.50, 90},
		{"1455", {"Tango", 75}, 49.50, 100},
		{"1356", {"Toblerone", 100}, 125.75, 60},
		{"1284", {"Lindt", 100}, 250.75, 15},
		{"1109", {"Guylian", 50}, 99.75, 35},
	};
	int COUNT = 15;
	int x;
	for(x = 0; x < COUNT; x++){
		insertProduct(&C, data[x]);
	}
	return C;
}

void insertProduct(ChocList *C, product P){
	ChocList *trav, node;
	node = (ChocList)malloc(sizeof(struct node));
	if(node != NULL){
		for(trav = C; *trav != NULL; trav = &(*trav)->link){}
		node->prod = P;
		node->link = NULL;
		*trav = node;
	}
}

void displayProduct(product P){
	printf("\n%-8s", P.prodID);
    printf("%-10s", P.prodDesc.name);
    printf("%-8d", P.prodDesc.weight);
    printf("%-10.2f", P.prodPrice);
    printf("%-6d", P.prodQty);	
}

void displayList(ChocList C){
	ChocList temp;
	printf("\n\nDetails of the List :: ");
	printf("\n---------------------");
	printf("\n\n%-8s", "ID");
    printf("%-10s", "Name");
    printf("%-8s", "Weight");
    printf("%-10s", "Price");
    printf("%-6s", "Qty");
    printf("\n%-8s%-10s%-8s%-10s%-6s","---","-----","------","------","----");
	for(temp = C; temp != NULL; temp = temp->link){
		displayProduct(temp->prod);
	}
}

void convertListToSet(ChocList *C){
	ChocList *trav, node, temp;
	for(temp = *C; temp != NULL; temp = temp->link){
		for(trav = &temp->link; *trav != NULL;){
			if(strcmp((*trav)->prod.prodID, temp->prod.prodID) == 0){
				node = *trav;
				*trav = (*trav)->link;
				free(node);
			} else {
				trav = &(*trav)->link;
			}
		}
	}
}

void initVHeap(VHeap *VH){
	int x;
	for(x = 0; x < VH_SIZE; x++){
		VH->VH_node[x].link = x - 1;
		strcpy(VH->VH_node[x].elem.prodID,"   ");
	}
	VH->avail = x-1;
}

void displayVHeap(VHeap V) {
  // Variable Declaration here
  int x;

  printf("\n\nDetails of the Virtual Heap :: ");
  printf("\n------------------------------");
  printf("\nAvailable Index  ::  %d", V.avail); // Complete this statement
  printf("\nVHeap Address    ::  %x", V);       // Complete this statement

  printf("\n\n%10s", "Index");
  printf("%10s", "Prod ID");
  printf("%15s", "Next Field");
  printf("\n%10s%10s%15s", "-----", "-------", "----------");

  // Write your code here
  for(x = 0; x < VH_SIZE; x++){
  	printf("\n%8d%10s%12d",x, V.VH_node[x].elem.prodID, V.VH_node[x].link);
  }
  
  
}

cursorSet initCursorSet(VHeap *VH){
	cursorSet C;
	C.count = 0;
	C.elemIndex = -1;
	C.VHptr = VH;
	return C;
}

int allocSpace(VHeap *VH){
	int avail = VH->avail;
	if(avail != -1){
		VH->avail = VH->VH_node[avail].link;
	}
	return avail;
}

void freeSpace(VHeap *VH, int index){
	if(index >= 0 && index < VH_SIZE){
		VH->VH_node[index].link = VH->avail;
		VH->avail = index;
	}
}

int closeHash(char *ID) {
	int sum = 0, x;
	for(x = 0; ID[x]; x++){
		sum = sum + (ID[x] - '0');
	}
	return sum % CLOSE_DSIZE;
}

void initCloseDic(closeDic CD) {
	int x;
	for(x = 0; x < CLOSE_DSIZE; x++){
		strcpy(CD[x].prodID, EMPTY);
		strcpy(CD[x].prodDesc.name, "");
	}
}

closeDic *convertSetToCloseDic(ChocList *C, VHeap *VH) {
	closeDic *CD;
	cursorSet set;
	int hashNdx, *cursorTrav, cursorNode, count;
	ChocList *trav, node;
	
	CD = (closeDic*)malloc(sizeof(closeDic));
	if(CD != NULL){
		initCloseDic(*CD);
		set = initCursorSet(VH);
		printf("\n\n--------Empty Dictionary--------");
		displayCloseDic(*CD);
		// 1st round of insertions
		for(trav = C; *trav != NULL;){
			node = *trav;
			*trav = (*trav)->link;
			hashNdx = closeHash(node->prod.prodID);
			if(strcmp((*CD)[hashNdx].prodID, EMPTY) == 0){
				(*CD)[hashNdx] = node->prod;
			} else{
				cursorNode = allocSpace(set.VHptr);
				if(cursorNode != -1){
					for(cursorTrav = &set.elemIndex; *cursorTrav != -1; cursorTrav = &set.VHptr->VH_node[*cursorTrav].link){}
					set.VHptr->VH_node[cursorNode].elem = node->prod;
					set.VHptr->VH_node[cursorNode].link = -1;
					*cursorTrav = cursorNode;
				}
			}
			free(node);
		}
		
		printf("\n\n--------Without Synonyms--------");
		displayCloseDic(*CD);
		printf("\n\n--------Synonyms in VHeap--------");
		displayVHeap(*set.VHptr);
		
		// 2nd round of insertions
		for(cursorTrav = &set.elemIndex; *cursorTrav != -1;){
			cursorNode = *cursorTrav;
			*cursorTrav = set.VHptr->VH_node[*cursorTrav].link;
			hashNdx = closeHash(set.VHptr->VH_node[cursorNode].elem.prodID);
			for(count = 0; count < CLOSE_DSIZE && strcmp((*CD)[hashNdx].prodID, EMPTY) != 0; count++, hashNdx = (hashNdx + 1) % CLOSE_DSIZE){}
			if(count < CLOSE_DSIZE){
				(*CD)[hashNdx] = set.VHptr->VH_node[cursorNode].elem;
			}
			strcpy(set.VHptr->VH_node[cursorNode].elem.prodID, "");
			freeSpace(set.VHptr, cursorNode);
		}
		
		printf("\n\n--------With Synonyms--------");
		displayCloseDic(*CD);
		printf("\n\n--------Synonyms in VHeap--------");
		displayVHeap(*set.VHptr);
	}
	return CD;
}

void displayCloseDic(closeDic CD) {
  int x;
  printf("\n\nDetails of Closed Hash Dictionary :: ");
  printf("\n-------------------------------------");
  printf("\n\n%-6s", "Index");
  printf("%-10s", "ChocoID");
  printf("%-15s", "Choco Name");
  printf("\n%-6s%-10s%-15s", "-----", "-------", "----------");

  // Write your code here
  for(x = 0; x < CLOSE_DSIZE; x++){
  	printf("\n%-6d%-10s%-15s",x, CD[x].prodID, CD[x].prodDesc.name);
  }
}

void initHeap(maxHeap *H){
	H->count = 0;
}

maxHeap convertCloseDicToMaxHeap(closeDic *CD){
	maxHeap H;
	int x;
	initHeap(&H);
	for(x = 0; x < CLOSE_DSIZE; x++){
		if(strcmp((*CD)[x].prodID, EMPTY) != 0){
			H.prod[H.count++] = (*CD)[x];
			heapify(&H);
			strcpy((*CD)[x].prodID, DELETED);
			strcpy((*CD)[x].prodDesc.name, "");
		}
	}
	return H;
}

void swapProduct(product *x, product *y){
	product temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

void displayHeap(maxHeap H){
	int x;
	printf("\n\nHeap :: %d Elements", H.count);   //Uncomment and COMPLETE this print statement
	printf("\n========================");
	for(x = 0; x < H.count; x++){
		displayProduct(H.prod[x]);
	}
}

void heapify(maxHeap *H){
	int P = (H->count - 2) / 2;
	int subroot;
	int LC;
	int RC;
	int maxNdx;
	for(; P != -1; P--){
		subroot = P;
		LC = 2 * subroot + 1;
		RC = LC + 1;
		maxNdx = (strcmp(H->prod[LC].prodID, H->prod[RC].prodID) > 0 || RC >= H->count)? LC : RC;
		while(LC < H->count && (RC < H->count || H->count % 2 != 0)){
			if(strcmp(H->prod[P].prodID, H->prod[maxNdx].prodID) < 0){
				swapProduct(&H->prod[P], &H->prod[maxNdx]);
			}
			subroot = maxNdx;
			LC = 2 * subroot + 1;
			RC = LC + 1;
			maxNdx = (strcmp(H->prod[LC].prodID, H->prod[RC].prodID) > 0 || RC >= H->count)? LC : RC;
		}
	}
}


