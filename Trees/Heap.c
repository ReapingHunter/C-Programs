#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define HEAP_MAX 12
typedef struct {
	int heap[HEAP_MAX];
	int last;
}Heap;

void initHeap(Heap *H){
	H->last = -1;
}

void minHeapifyBreadth(Heap *H, int P) {
	int LC; 
	int RC;
	int smallNdx;
	int temp;
	if(P <= H->last / 2){
		LC = 2 * P + 1;
		RC = 2 * P + 2;
		smallNdx = (H->heap[LC] <= H->heap[RC] || RC > H->last)? LC : RC;
		if(H->heap[P] > H->heap[smallNdx] && smallNdx <= H->last){
			temp = H->heap[P];
			H->heap[P] = H->heap[smallNdx];
			H->heap[smallNdx] = temp;
			minHeapifyBreadth(H, (P-1)/2);
		}
		minHeapifyBreadth(H, P+1);
	}
	
}

void maxHeapifyBreadth(Heap *H, int P) {
	int LC; 
	int RC;
	int bigNdx;
	int temp;
	if(P <= H->last / 2){
		LC = 2 * P + 1;
		RC = 2 * P + 2;
		bigNdx = (H->heap[LC] >= H->heap[RC] || RC > H->last)? LC : RC;
		if(H->heap[P] < H->heap[bigNdx] && bigNdx <= H->last){
			temp = H->heap[P];
			H->heap[P] = H->heap[bigNdx];
			H->heap[bigNdx] = temp;
			maxHeapifyBreadth(H, (P-1)/2);
		}
		maxHeapifyBreadth(H, P+1);
	}
	
}

bool isHeapMin(Heap H){
	int P;
	int LC; 
	int RC;
	for(P = 0, LC = P * 2 + 1, RC = P * 2 + 2; P <= (H.last-1)/2 && H.heap[P] <= H.heap[LC] && (H.heap[P] <= H.heap[RC] || RC > H.last); P++, LC = P * 2 + 1, RC = P * 2 + 2){}
	return(P > (H.last-1) / 2)? true : false;
}

bool isHeapMax(Heap H){
	int P;
	int LC; 
	int RC;
	for(P = 0, LC = P * 2 + 1, RC = P * 2 + 2; P >= (H.last-1)/2 && H.heap[P] >= H.heap[LC] && (H.heap[P] >= H.heap[RC] || RC > H.last); P++, LC = P * 2 + 1, RC = P * 2 + 2){}
	return(P > (H.last-1) / 2)? true : false;
}

int deleteMin(Heap *H){
	int min;
	if(H->last != -1){
		min = H->heap[0];
		H->heap[0] = H->heap[H->last];
		H->heap[H->last--] = min;
		if(!isHeapMin(*H)){
			minHeapifyBreadth(H, 0);
		}
		return min;
	}
}

int deleteMax(Heap *H){
	int max;
	if(H->last != -1){
		max = H->heap[0];
		H->heap[0] = H->heap[H->last];
		H->heap[H->last--] = max;
		if(!isHeapMax(*H)){
			maxHeapifyBreadth(H, 0);
		}
		return max;
	}
}

Heap populateHeapMin() {
	Heap H = {{14,9,8,4,7,8,6,9,10,3,1,6}, 11};
	minHeapifyBreadth(&H, 0);
	return H;
}

Heap populateHeapMax() {
	Heap H = {{14,9,8,4,7,8,6,9,10,3,1,6}, 11};
	maxHeapifyBreadth(&H, 0);
	return H;
}

void display(Heap H){
	int x;
	for(x = 0; x <= H.last; x++){
		printf("%d ",H.heap[x]);
	}
	printf("\n");
}

void heapSortMin(Heap *H){
	int oldNdx = H->last;
	while(H->last != 0){
		deleteMin(H);
	}
	H->last = oldNdx;
}

void heapSortMax(Heap *H){
	int oldNdx = H->last;
	while(H->last != 0){
		deleteMax(H);
	}
	H->last = oldNdx;
}

int main() {
	Heap A;
	Heap B;
	A = populateHeapMax();
	B = populateHeapMin();
	display(A);
	display(B);
	printf("\n\n");
	heapSortMax(&A);
	heapSortMin(&B);
	display(A);
	display(B);
	return 0;
}
