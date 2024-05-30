#include<stdio.h>
#include<math.h>

// Program that turns binary to decimal and checks if the decimal is an armstrong number

int isArmstrong(int num);
int toDecimal(unsigned long long bin);
int main() {
	unsigned long long x;
	printf("Enter a number: ");
	scanf("%lld",&x);
	printf("\nDecimal equivalent is %d", toDecimal(x));
	if(isArmstrong(toDecimal(x))) {
		printf("\n\nWelcome! You have been permitted entry.");
	} else {
		printf("\n\nYou are not welcome here! Get Out!!!");
	}
	return 0;
}

int toDecimal(unsigned long long bin) {
	int dec;
	int digCount;
	for(dec = 0, digCount = 0; bin > 0; bin /= 10, digCount++) {
		dec += (bin & 1) * pow(2, digCount);
	}
	return dec;
}
int isArmstrong(int num) {
	int dummy;
	int digCount;
	int sum;
	for(digCount = 0, dummy = num; dummy > 0; dummy /= 10, digCount++) {}
	for(dummy = num; dummy > 0; dummy /= 10) {
		sum += pow(dummy % 10, digCount); 
	}
	return (sum == num)? 1 : 0;
}
