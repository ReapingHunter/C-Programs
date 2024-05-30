#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void toBitPattern(int num) {
	int bin = sizeof(num) * 8;
	int bit;
	int j; //For Spacing
	int k;
	for(k = bin - 1, j = 1; k >= 0; k--, j++){
		bit = (num >> k) & 1;
		printf("%d",bit);
		if(j % 4 == 0){
			printf(" ");
		}
	}
}

int main(){
	toBitPattern(123);
	return 0;
}
