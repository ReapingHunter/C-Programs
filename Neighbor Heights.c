#include<stdio.h>
#include<stdlib.h>
#define MAX 100

void getNeighborHeights(int arr[], int size, int target, int *shorterHeight, int *tallerHeight); //get the heights of the next shorter and next taller person
void displayResult(int arr[], int size, int target, int shorterHeight, int tallerHeight);      //display the messages based on the heights obtained

int main(){
	int arr[MAX], size, target;
	int shorterHeight, tallerHeight;
	int i;
	//user inputs
	scanf("%d",&size);
	for(i=0; i<size; i++){
		scanf("%d",&arr[i]);
	}
    scanf("%d",&target);
   getNeighborHeights(arr, size, target, &shorterHeight, &tallerHeight);
   displayResult(arr, size, target, shorterHeight, tallerHeight);
  
    return 0;
	
}

void getNeighborHeights(int arr[], int size, int target, int *shorterHeight, int *tallerHeight){
    int i;
    int j = 0;
   shorterHeight = 0;
    tallerHeight = 0;
    int temp;
    for(i = 0; i < size; i++)
   {
       for(i = j + 1; j < size; j++)
       {
           if(arr[i] > arr[j])
           {
               temp = arr[i];
               arr[i] = arr[j];
               arr[j] = temp;
           }
       }
   }
   for(i = 0; i < size; i++)
   {
       if(*shorterHeight < target)
       {
           *shorterHeight = arr[i];
           break;
       }
       
   }
    for(i = 0; i < size; i++)
   {
       if(target > *tallerHeight)
       {
           *tallerHeight = arr[i];
           
       }
   }
}

void displayResult(int arr[], int size, int target, int shorterHeight, int tallerHeight){
    
   if(shorterHeight != target && target != tallerHeight)
   {
       printf("Height in front: %d cm",shorterHeight);
       printf("\nHeight at the back: %d cm",tallerHeight);
   }
   else if(tallerHeight == target)
   {
       printf("Height in front: %d cm",shorterHeight);
       printf("\nPerson is the last in line!");
   }
    else if(shorterHeight == target)
   {
       printf("Person is the first in line!");
       printf("\nHeight at the back: %d cm",shorterHeight);
       
   }
}
