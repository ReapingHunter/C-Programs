#include<stdio.h>
void swap(int *x, int *y);
void quicksort(int array[], int length);
void quicksortRecursion(int array[], int low, int high);
int partition(int array[], int low, int high);

int main() {
	
	int arr[] = {77, 50, 43, 57, 89, 19, 90, 80, 45, 71};
	int length = sizeof(arr)/sizeof(arr[0]);
	int i;
	quicksort(arr, length);
	for(i = 0; i < length; i++) {
		printf("%d ",arr[i]);
	}
	printf("\n");
	return 0;
}
void quicksort(int array[], int length) {
	quicksortRecursion(array, 0, length - 1);
}
void swap(int *x, int *y) {
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}
void quicksortRecursion(int array[], int low, int high) {
	if(low < high) {
		int pivot = partition(array, low, high);
    	quicksortRecursion(array, low, pivot - 1);
    	quicksortRecursion(array, pivot + 1, high);
	}
}
int partition(int array[], int low, int high) {
	int pivotValue = array[high];
	int i = low;
	int j;
	for(j = low; j < high; j++) {
		if(array[j] <= pivotValue) {
			swap(&array[i], &array[j]);
			i++;
		}
	}
	swap(&array[i], &array[high]);
	return i;
}





