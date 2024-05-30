#include<stdio.h>
char getAChar(int s);


int main() {
  int a;
  a = getAChar(5) % getAChar(6);
  printf("%c", a);
  return 0;
}
char getAChar(int s)
{
   char val = 'A';
   switch (s) {
      case 3:
         val = 'C';
         break;
      case 5:
         val = 'E';
         break;
      case 6:
         val = 'F';
         break;
      } 
   return val;
}
