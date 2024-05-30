#include <stdio.h>

 int checkIfLowestTerms(int num, int den);
 void simplifyFraction(int *num, int *den);

 int main(void){
    int num, den, isSimplified;      //num - numerator, den - denominator (which cannot be 0)
    scanf("%d %d",&num,&den);     //get numerator and denominator
    isSimplified = checkIfLowestTerms(num, den);
    
    if (isSimplified == 0){
        printf("NOT SIMPLIFIED");
    } else {
        printf("SIMPLIFIED");
    }
//    if(isSimplified == 0) {
//         simplifyFraction(&num,&den);
//    }
//    printf("\nSimplified fraction: %d/%d",num,den); //displays the simplified fraction
    return 0;
 }

 int checkIfLowestTerms(int num, int den){
    int x,y,simplified=1;
    y=(num<den)?num:den;
    for(x=2;x<=y&&simplified==1;x++){
        if(num%x==0 && den%x==0){
            simplified=0;
        }
    }
    return simplified;
 }
