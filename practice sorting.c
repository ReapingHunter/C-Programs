#include<stdio.h>

int main()
{
	int arr[] = {77, 55, 99, 34, 21, 8, 100, 88, 70, 90};
	int i;
	int j;
	int temp;
	int index;
	int size = sizeof(arr)/sizeof(arr[0]);
	for(i = 0; i < size; i++) { // bubble sort
		for(j = 0; j < size - 1 - i; j++) {
			if(arr[j] > arr[j+1]) {
				temp = arr[j];
		    	arr[j] = arr[j+1];
		    	arr[j+1] = temp;
			}
		}
	}
	for(i = 0; i < size; i++) { // selection sort
		index = i;
		for(j = i; j < size; j++) {
			if(arr[j] < arr[index]) {
				index = j;
			}
		}
		temp = arr[index];
		arr[index] = arr[i];
		arr[i] = temp;
	}
	
	for(i = 1; i < size; i++) { //insertion sort
		temp = arr[i];
		j = i-1;
		while(j >= 0 && arr[j] > temp) {
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = temp;
	}
	
	for(i = 0; i < size; i++) {
		printf("%d ",arr[i]);
	}
	return 0;
}
