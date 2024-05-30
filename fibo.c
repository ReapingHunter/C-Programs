#include<stdio.h>
void printFibonacci(int);

int main(){

    int n;

    printf("Enter the range of the Fibonacci series: ");
    scanf("%d",&n);

    printf("Fibonacci Series: ");

    printFibonacci(n);
    printf("%d %d ",1,0);
    return 0;
}

void printFibonacci(int n){

    static long int first=0,second=1;
    int sum;

    if(n>0){
         sum = first + second;
         first = second;
         second = sum;
         printFibonacci(n-1);
         printf("%ld ",sum);
    }

}
