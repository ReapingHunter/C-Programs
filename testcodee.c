#include<stdio.h>

int main()
{
	int value;
	int ctr;
	for(value = ctr = 0 ; ctr<5 ; ctr++) {
   if(ctr % 3 == 0) {
      break;
   }
   value += ctr;
}
printf("%d", value);
   return 0;
}




