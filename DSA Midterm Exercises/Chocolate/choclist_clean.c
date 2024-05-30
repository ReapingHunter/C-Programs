/******************************************************************

 ******************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VH_SIZE 0XC     // size of Virtual Heap
#define OPEN_DSIZE 0XA  // size of Open Hash Table
#define CLOSE_DSIZE 0XC // size of Close Hash Table
#define LIST_SIZE 0XF   // size of the array implementation of List
/******************************************************************************
 * Data Structure Definition:                                                 *
 ******************************************************************************/
typedef struct {
  char name[24]; // Chocolate name
  int weight;    // Chocolate weight in grams
} chocoDesc;

typedef struct {
  char prodID[8];     //  product ID uniquely identifies the products; EMPTY or DELETED
  chocoDesc prodDesc; //  product description
  float prodPrice;    //  product price
  int prodQty;        //  product count or quantity
} product;            //  product record

typedef struct {
  product elem;
  int next;
} prodNode; // Product node, used in cursor-based implementation of Set

/************************
 * Virtual Heap         *
 ************************/
typedef struct {
  prodNode VH_node[VH_SIZE];
  int avail;
} VHeap;

/******************************************
 * Cursor-Based Implementation of SET     *
 ******************************************/
typedef struct {
  int elemIndex; // index of the 1st element in the set
  int count;     // holds the actual number of elements in the set
  VHeap *VHptr;  // holds the pointer to the virtual heap
} cursorSet;

/********************************************
 * Open Hashing Implementation of Dictionary*
 ********************************************/
typedef struct {
  int header[OPEN_DSIZE]; // array of sets 
  int count;              // total number of elements in the dictionary
  VHeap *dicVHptr;
} openDic; // holds the pointer to the virtual heap

/**********************************************
 * Closed Hashing with 2 pass loading          *
 **********************************************/
#define EMPTY "empty" // stored in product ID field
#define DELETED "del" // stored in product ID field *

typedef product closeDic[CLOSE_DSIZE]; // Definition of the closed hash dictionary

typedef struct {
  product prod[LIST_SIZE];
  int last; // index of the last element; -1 if list is empty
} List;

/**********************************************************
 * Function Prototypes                                    *
 *********************************************************/
//---Problem #1 ---
void initVHeap(VHeap *VH);
cursorSet initCursorSet(VHeap *VH);
void displayVHeap(VHeap V);
void displaySet(cursorSet A);

//---Problem #2 ---
int mallocInVHeap(VHeap *VH);
void insertSorted(cursorSet *A, product P);
void populateSet(cursorSet *A);

//---Problem #3 ---
int openHash(char *IDen);
openDic initOpenDict(VHeap *VH);
openDic convertToOpenDict(cursorSet *A);
void displayOpenDict(openDic D);

//---Problem #4 ---
void freeInVHeap(VHeap *VH, int ndx);
void deleteDict(openDic *D, char *IDen);

//---Problem #5 ---
int closeHash(char *ID);
void initCloseDict(closeDic CD);
closeDic *convertToCloseDict(openDic *D);
void displayCloseDict(closeDic CD);

/************************************************************************************
 * READ ME FIRST before ANSWERING * 1)  To facilitate the checking of the
 *machine problem, follow the instructions * in each PROBLEM #. * 2)  To
 *accomplish the task for each PROBLEM, a series of function calls may be *
 *       necessary. * 3)  Write you answer BELOW THE COMMENTS. DO NOT DELETE
 *COMMENTS                *
 *                                                                                  *
 ***********************************************************************************/
int main() {
  /*---------------------------------------------------------------------------------
   * 	Problem #1 ::  1) Initializes the virtual heap and the cursor Set * 2)
   *Displays the contents  virtual heap and cursor Set          *
   *--------------------------------------------------------------------------------*/
    printf("\n\n\nProblem #1:: ");
    printf("\n------------");
    // Declare variables needed for Problem #1
    VHeap VH;
    cursorSet A;

    // Function Calls for Problem #1
    initVHeap(&VH);
    A = initCursorSet(&VH);
    displayVHeap(VH);
    displaySet(A);

  /*---------------------------------------------------------------------------------
   * 	Problem #2 ::  
   1) Populates the Cursor set which is sorted in ascending 
   * order 
   * according to ID                                             
   * 2) Displays the Cursor set                                     
   * 
   *--------------------------------------------------------------------------------*/
  printf("\n\n\nProblem #2:: ");
  printf("\n------------");
  // Declare variables needed for Problem #2
    VHeap VH2;
    cursorSet B;

    // Function Calls for Problem #2
    initVHeap(&VH2);
    B = initCursorSet(&VH2);
    populateSet(&B);
    displaySet(B);

  // Function Calls for Problem #2
    populateSet(&A);
    displaySet(A);

  /*---------------------------------------------------------------------------------
   * 	Problem #3 ::  1) Converts the Cursor set into an Open Hash Dictionary *
   *                 2) Displays the Open Hash Dictionary * 3) Displays the
   *empty Cursor set.                              *
   *--------------------------------------------------------------------------------*/
  printf("\n\n\nProblem #3:: ");
  printf("\n------------");
  // Declare variables needed for Problem #3
  openDic myDic = convertToOpenDict(&B);

  // Function Calls for Problem #3
  displayOpenDict(myDic);

  /*---------------------------------------------------------------------------------
   * 	Problem #4 ::  1) Perform 3 delete operations on the Open Hash
   *Dictionary     * 2) Displays the Open Hash Dictionary * 3) Displays the
   *Virtual Heap                                   *
   *--------------------------------------------------------------------------------*/
  printf("\n\n\nProblem #4:: ");
  printf("\n------------");
  // Declare variables needed for Problem #4
  char delete01[] = "1703";
  char delete02[] = "1358";
  char delete03[] = "1601";

  // Function Calls for Problem #4
  deleteDict(&myDic, delete01);
  deleteDict(&myDic, delete02);
  deleteDict(&myDic, delete03);

  displayOpenDict(myDic);
  displayVHeap(*myDic.dicVHptr);

  /*------------------------------------------------------------------------------------
   * 	Problem #5 :: 1) Converts the Open Hash Dictionary into a Closed Hash
   *Dictionary * 2) Displays the Closed Hash Dictionary * 3) Displays the
   *virtual heap                                       *
   *---------------------------------------------------------------------------------*/
  printf("\n\n\nProblem #5:: ");
  printf("\n------------");
  // Declare variables needed for Problem #5
  closeDic *myClosedDic = convertToCloseDict(&myDic);

  // Function Calls for Problem #5
  displayCloseDict(*myClosedDic);
  displayVHeap(VH2);

  return 0;
}

/************************************************************
 *  Problem 1:: Function Definitions                          *
 ************************************************************/
void initVHeap(VHeap *V) {
	int x;
    for(x = 0; x < VH_SIZE; x++){
	  	V->VH_node[x].next = x - 1;
	  	strcpy(V->VH_node[x].elem.prodID,"   ");
	}
	V->avail = x - 1;
}

cursorSet initCursorSet(VHeap *VH) {
    cursorSet C;
    C.VHptr = VH;
    C.count = 0;
    C.elemIndex = -1;
    return C;
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
  	printf("\n%8d%10s%12d",x, V.VH_node[x].elem.prodID, V.VH_node[x].next);
  }
  
  
}

void displaySet(cursorSet A) {
  int trav;
  //product p;

  printf("\n\nDetails of the Set :: ");
  printf("\n---------------------");
  printf("\nNo. of elements ::  %d", A.count); // Complete this code
  printf("\n\n%-7s", "ID");
  printf("%-12s", "Choco Name");
  printf("%-15s", "Choco Weight");
  printf("%-10s", "VHeap Index");
  printf("\n%-7s%-12s%-15s%-10s", "--", "----------", "------------",
         "-----------");

  // Write your code here
  for(trav = A.elemIndex; trav != -1; trav = A.VHptr->VH_node[trav].next){
  	printf("\n%-9s%-12s%-15d%-10d",A.VHptr->VH_node[trav].elem.prodID, A.VHptr->VH_node[trav].elem.prodDesc.name, A.VHptr->VH_node[trav].elem.prodDesc.weight, trav);
  }
    
}

/************************************************************
 *  Problem 2:: Function Definitions                         *
 ************************************************************/
int mallocInVHeap(VHeap *VH) {
    int avail = VH->avail;
    if(avail != -1){
    	VH->avail = VH->VH_node[avail].next;
	}
	return avail;
}

void insertSorted(cursorSet *A, product P) {
    int *trav, node;
    if(A->VHptr->avail != -1){
    	for(trav = &A->elemIndex; *trav != -1 && strcmp(A->VHptr->VH_node[*trav].elem.prodID, P.prodID) < 0; trav = &A->VHptr->VH_node[*trav].next){}
    	if(strcmp(A->VHptr->VH_node[*trav].elem.prodID, P.prodID) != 0){
    		node = mallocInVHeap(A->VHptr);
    		A->VHptr->VH_node[node].elem = P;
    		A->VHptr->VH_node[node].next = *trav;
    		*trav = node;
    		A->count++;
		} else{
			printf("\nProduct with ID: %s already exists in the set.",P.prodID);
		}
	} else{
		printf("\nNo available space. Product with ID: %s cannot be inserted.",P.prodID);
	}
}

void populateSet(cursorSet *A) {
  const int COUNT = 15;
  int x;
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
      {"1703", {"Toblerone", 100}, 125.75, 60},
      {"1284", {"Lindt", 100}, 250.75, 15},
      {"1688", {"Guylian", 50}, 99.75, 35},

  };
  // Inserts each element of the array to the cursor set
  // Write your code here!!
  for(x = 0; x < COUNT; x++){
  	insertSorted(A, data[x]);
  }
    
}

/************************************************************
 *  Problem 3:: Function Definitions                        *
 ************************************************************/
int openHash(char *prodID) {
    int x;
    int sum = 0;
    for(x = 0; prodID[x]; x++){
    	sum = sum + (prodID[x] - '0');
	}
	return sum % OPEN_DSIZE;
}

openDic initOpenDict(VHeap *VH) {
	openDic D;
    int x;
    for(x = 0; x < OPEN_DSIZE; x++){
    	D.header[x] = -1;
	}
	D.count = 0;
	D.dicVHptr = VH;
	return D;
}

openDic convertToOpenDict(cursorSet *A) {
    openDic D = initOpenDict(A->VHptr);
    int *trav, node, *dic;
    int hash;
    for(trav = &A->elemIndex; *trav != -1;){
    	hash = openHash(A->VHptr->VH_node[*trav].elem.prodID);
    	for(dic = &D.header[hash]; *dic != -1 && strcmp(D.dicVHptr->VH_node[*dic].elem.prodID, A->VHptr->VH_node[*trav].elem.prodID) < 0; dic = &D.dicVHptr->VH_node[*dic].next){}
    	node = *trav;
    	*trav = A->VHptr->VH_node[*trav].next;
    	A->VHptr->VH_node[node].next = *dic;
    	*dic = node;
    	A->count--;
    	D.count++;
	}
    return D;
}

void displayOpenDict(openDic D) {
  // Variable declaration here
	int x, trav;
  printf("\n\nDetails of the Open Hash Dictionary:: ");
  printf("\n-------------------------------------");

  printf("\nNo. of elements :: %d", D.count);
  printf("\n\n%-7s", "GROUPS");
  printf("%15s", "ID Numbers");
  printf("\n%-7s%15s", "------", "----------");

  // Write your code here
  for(x = 0; x < OPEN_DSIZE; x++){
  	printf("\nGroup[%d] :: ",x);
  	for(trav = D.header[x]; trav != -1; trav = D.dicVHptr->VH_node[trav].next){
  		printf("%s    ",D.dicVHptr->VH_node[trav].elem.prodID);
	}
  }
   
}

/************************************************************
 *  Problem 4:: Function Definitions                        *
 ************************************************************/
void freeInVHeap(VHeap *VH, int ndx) {
   if(ndx >= 0 && ndx < VH_SIZE){
   	VH->VH_node[ndx].next = VH->avail;
   	VH->avail = ndx;
   }
}

void deleteDict(openDic *D, char *IDen) {
    int hash, *trav, node;
    hash = openHash(IDen);
    for(trav = &D->header[hash]; *trav != -1 && strcmp(D->dicVHptr->VH_node[*trav].elem.prodID, IDen) != 0; trav = &D->dicVHptr->VH_node[*trav].next){}
	if(*trav != -1){
		node = *trav;
		*trav = D->dicVHptr->VH_node[*trav].next;
		strcpy(D->dicVHptr->VH_node[node].elem.prodID, "   ");
		freeInVHeap(D->dicVHptr, node);
		D->count--;
	}
}

/************************************************************
 *  Problem 5:: Function Definitions                        *
 ************************************************************/
int closeHash(char *ID) {
 	int x;
    int sum = 0;
    for(x = 0; ID[x]; x++){
    	sum = sum + (ID[x] - '0');
	}
	return sum % CLOSE_DSIZE;
}

void initCloseDict(closeDic CD) {
	int x;
	for(x = 0; x < CLOSE_DSIZE; x++){
		strcpy(CD[x].prodID, EMPTY);
		strcpy(CD[x].prodDesc.name, "");
	}
 	
}

closeDic *convertToCloseDict(openDic *D) {
	closeDic *C;
	List L;
	int hash, *trav, node, x, check = 0;
	C = (closeDic*)malloc(sizeof(closeDic));
	initCloseDict(*C);
	L.last = -1;
	for(x = 0; x < OPEN_DSIZE; x++){
		for(trav = &D->header[x]; *trav != -1;){
			node = *trav;
			*trav = D->dicVHptr->VH_node[*trav].next;
			freeInVHeap(D->dicVHptr,node);
			hash = closeHash(D->dicVHptr->VH_node[node].elem.prodID);
			if(strcmp((*C)[hash].prodID, EMPTY) == 0){
				(*C)[hash] = D->dicVHptr->VH_node[node].elem;
			} else{
				L.prod[++L.last] = D->dicVHptr->VH_node[node].elem;
			}
			strcpy(D->dicVHptr->VH_node[node].elem.prodID, "   ");
			D->count--;
		}
	}
	for(x = 0; x <= L.last; x++){
		for(hash = closeHash(L.prod[x].prodID); check < CLOSE_DSIZE && strcmp((*C)[hash].prodID, EMPTY) != 0; hash = (hash + 1) % CLOSE_DSIZE){}
		if(check != CLOSE_DSIZE){
			(*C)[hash] = L.prod[x];
		}
	}
	return C;
	
}

void displayCloseDict(closeDic CD) {
  // Variable declaration here
  int x;
  printf("\n\nDetails of Closed Hash Dictionary :: ");
  printf("\n-------------------------------------");
  printf("\n\n%-6s", "Index");
  printf("%-10s", "ChocoID");
  printf("%-15s", "Choco Name");
  printf("\n%-6s%-10s%-15s", "-----", "-------", "----------");

  // Write your code here
  for(x = 0; x < CLOSE_DSIZE; x++){
  	(strcmp(CD[x].prodID, EMPTY) != 0)? printf("\n%-6d%-10s%-15s",x, CD[x].prodID, CD[x].prodDesc.name) : printf("\n%-6d",x);
  }
  
}
