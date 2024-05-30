#include <stdio.h>
#include <stdlib.h> 
#define MAX 10

/* Unnecessary */
typedef struct {
    int elem;
} PriorityQueue;

typedef struct {
    int LC;
    int elem;
    int RC;
} Nodetype;

typedef struct {
    Nodetype Nodes[MAX];
    int avail;
} VirtualHeap;

typedef int BST;

typedef struct{
	int array[MAX];
	int last;
}POT;

void initializeBST(BST *tae, VirtualHeap *heap);
void insert(BST *root, VirtualHeap *heap, int elem);
void print(BST root, VirtualHeap heap);
int search(VirtualHeap VH, BST B, int key);
void delNode(BST *B, VirtualHeap *VH, int data);
void deallocSpace(VirtualHeap *heap, int elem);
void heapifySubTree(POT *A, int x);
void heapify(POT *A);
POT delandStore(BST *B, VirtualHeap *VH);
void printArray(POT arr, char string[]);
void heapsort(POT *A);

int main() {
    BST bst;
    VirtualHeap heap;
    int indx;
    initializeBST(&bst, &heap);

    insert(&bst, &heap, 5);
    insert(&bst, &heap, 11);
    insert(&bst, &heap, 9);
    insert(&bst, &heap, 6);
    insert(&bst, &heap, 2);
    insert(&bst, &heap, 1);
    insert(&bst, &heap, 3);

    printf("Original Binary Search Tree:\n");
    print(bst, heap);
    
 	delNode(&bst, &heap, 3);
    printf("Delete:\n");
    print(bst, heap);
    
    POT arr = delandStore(&bst, &heap);

	printf("\n");
	printArray(arr,"Delete All and store in Heap");
	
	heapify(&arr);
	printf("\n");
	printArray(arr,"MinHeap");
	heapsort(&arr);
	printf("\n");
	printArray(arr,"Heapsorted");
	
    return 0;
}

void printArray(POT arr, char string[]){
	printf("\n %s \n",string);
	int x;
	for(x = 0; x<=arr.last;x++){
		printf("%5d",x);
	}
	printf("\n");
	for(x = 0; x<=arr.last;x++){
		printf("%5d",arr.array[x]);
	}
}

void initializeBST(BST *tae, VirtualHeap *heap) {
    int x;
    heap->avail = 0;
    for (x = 0; x < MAX - 1; x++) {
        heap->Nodes[x].LC = x + 1;
        heap->Nodes[x].RC = -1;
    }
    *tae = -1;
}

int allocSpace(VirtualHeap *heap) {
    int retval = heap->avail;

    if (heap->avail != -1) {
        heap->avail = heap->Nodes[heap->avail].LC;
        heap->Nodes[retval].LC = -1;
        heap->Nodes[retval].RC = -1;
    }

    return retval;
}

void insert(BST *root, VirtualHeap *heap, int elem) {
//    int newIndex = allocSpace(heap);
//    int *trav;
//    for (trav = &(*root); *trav != -1; trav = (heap->Nodes[*trav].elem > elem)? &heap->Nodes[*trav].LC:&heap->Nodes[*trav].RC) {}
//    *trav = newIndex;
	BST *trav, node;
	if(heap->avail != -1){
		for (trav = &(*root); *trav != -1;) {
			trav = (heap->Nodes[*trav].elem > elem)? &heap->Nodes[*trav].LC:&heap->Nodes[*trav].RC;
		}
		if(*trav == -1){
			node = allocSpace(heap);
			heap->Nodes[node].elem = elem;
			heap->Nodes[node].LC = heap->Nodes[node].RC = -1;
			*trav = node;
		}
	}
    
    
}

int search(VirtualHeap VH, BST B, int key) {
    if (VH.Nodes[B].elem == key) {
        return B;
    } else if (B == -1) {
        return B;
    } else if (VH.Nodes[B].elem < key) {
        return search(VH, VH.Nodes[B].RC, key);
    } else {
        return search(VH, VH.Nodes[B].LC, key);
    }
}

void print(BST root, VirtualHeap heap) {
    if (root != -1) {
        print(heap.Nodes[root].LC, heap);
        printf("Index: %d, Element: %d, Left Child Index: %d, Right Child Index: %d\n",
               root, heap.Nodes[root].elem, heap.Nodes[root].LC, heap.Nodes[root].RC);
        print(heap.Nodes[root].RC, heap);
    }
}



void delNode(BST *B, VirtualHeap *VH, int data) { 
//    BST *x, temp;
//    for (x = B; *x != -1 && VH->Nodes[*x].elem != data;) {
//        x = (data > VH->Nodes[*x].elem) ? &VH->Nodes[*x].RC : &VH->Nodes[*x].LC;
//    }
//
//    if (*x != -1) {
//        temp = *x;
//        if (VH->Nodes[temp].LC == -1) {
//            *x = VH->Nodes[temp].RC;
//        } else if (VH->Nodes[temp].RC == -1) {
//            *x = VH->Nodes[temp].LC;
//            
//        } else {
//            BST *search;
//            for (search = &VH->Nodes[temp].RC; VH->Nodes[*search].LC != -1; search = &VH->Nodes[*search].LC) {}
//            temp = *search;
//            *search = VH->Nodes[temp].RC;
//            VH->Nodes[*x].elem =  VH->Nodes[temp].elem;
//
//        }
//        deallocSpace(VH, temp);
//    }

	BST *trav, node;
	for(trav = B; *trav != -1 && VH->Nodes[*trav].elem != data;){
		trav = (data > VH->Nodes[*trav].elem) ? &VH->Nodes[*trav].RC : &VH->Nodes[*trav].LC;
	}

	if(*trav != -1){
		node = *trav;
		if(VH->Nodes[node].LC != -1 && VH->Nodes[node].RC != -1){
			for(trav = &VH->Nodes[*trav].RC; VH->Nodes[*trav].LC != -1; trav = &VH->Nodes[*trav].LC){}
			VH->Nodes[node].elem = VH->Nodes[*trav].elem;
			node = *trav;
		}
		
		*trav = (VH->Nodes[*trav].LC != -1)? VH->Nodes[*trav].LC : VH->Nodes[*trav].RC;
		deallocSpace(VH, node);
	}
}


void deallocSpace(VirtualHeap *heap, int elem){
	if(elem >= 0 && elem < MAX){
		heap->Nodes[elem].LC = heap->avail;
		heap->Nodes[elem].RC = -1;
		heap->avail = elem;
	}
	
}

POT delandStore(BST *B, VirtualHeap *VH) { 
//	POT tae;
//    BST temp, *x;
//	tae.last = -1;
//    while (*B != -1) {
//    	x = B;
//        temp = *x;
//        tae.array[++tae.last] = VH->Nodes[temp].elem;
//        
//        if (VH->Nodes[temp].LC == -1) {
//            *x = VH->Nodes[temp].RC;
//        } else if (VH->Nodes[temp].RC == -1) {
//            *x = VH->Nodes[temp].LC;
//            
//        } else {
//            BST *search;
//            for (search = &VH->Nodes[temp].RC; VH->Nodes[*search].LC != -1; search = &VH->Nodes[*search].LC) {}
//            temp = *search;
//            *search = VH->Nodes[temp].RC;
//            VH->Nodes[*x].elem =  VH->Nodes[temp].elem;
//
//        }
//        deallocSpace(VH, temp);
//    }

	POT H;
	BST *trav, node;
	H.last = -1;	
	while(*B != -1){
		trav = B;
		H.array[++H.last] = VH->Nodes[*B].elem;
		delNode(B, VH, VH->Nodes[*B].elem);
	}
    
    return H;
}

void heapify(POT *A){
	int x;
	for(x = (A->last -1) / 2; x != -1; x--){
		heapifySubTree(A,x);
		
	}
}

void heapifySubTree(POT *A, int x) {
	// minheap;
//	int done = 0;
//	do{
//	int small = (x*2) + 2; //RC;
//	if(small  > A->last){ // small<= A->last
//		done = 1;
//	}else{
//		if(A->array[small] > A->array[small-1]){
//			small = small-1; // small becomes left child;
//		}
//		if(A->array[small] > A->array[x]){
//			done == 1;
//		}else{
//			int temp; 
//			temp = A->array[x];
//			A->array[x] = A->array[small];
//			A->array[small] = temp;
//			x = small;
//		}
//		
//	}
//	}while(done == 0);

	int LC, RC, SC, temp;
    LC = 2*x+1;
    RC = 2*x+2;
    SC = (A->array[LC] <= A->array[RC] || RC > A->last)? LC: RC; 
    while(LC <= A->last && (RC <= A->last|| A->last % 2 != 0)){
    	if(A->array[x] > A->array[SC]){
    		temp = A->array[x];
    		A->array[x] = A->array[SC];
    		A->array[SC] = temp;
		}
		LC = 2*SC+1;
		RC = 2*SC+2;
		x = SC;
		SC = (A->array[LC] <= A->array[RC] || RC > A->last)? LC: RC;
	}
}

void heapsort(POT *A){
	int x;
	int oldLast = A->last;
	for(; A->last >=0;A->last--){
		int min = A->array[0];
		A->array[0] = A->array[A->last];
		heapifySubTree(A,0);
		A->array[A->last] = min;
//		A->last--;
	}
	A->last = oldLast;
}



