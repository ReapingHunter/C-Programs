#include <stdio.h>

int main(){
  int n = 915040;           //input
  int digit, num=0, mult=1; //initialization
  
  while(n>0){       //loop while there are digits to check
    digit = n % 10; //extracting ones digit
    if(digit > 3){  //if extract digit is > 3
      num = mult * digit + num; //store digit in proper position of output number
      mult = mult * 10; //prepare for the next place value
    }
    n = n / 10;     //remove the rightmost digit
  }
    
  printf("%d",num); //display the result
}
