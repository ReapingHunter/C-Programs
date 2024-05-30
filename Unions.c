#include<stdio.h>

struct alfa {
	int a;
	float b;
};

union beta {
	int a;
	float b;
};

int main () {
	
	struct alfa x;
	union beta y;
	x.a = 5;
	x.b = 2.7;
	y.a = 5;
	y.b = 2.7;
	printf("%d\n",sizeof(x));
	printf("%d\n\n",sizeof(y));
	printf("%d\n",x.a);
	printf("%f\n",x.b);
	printf("%d\n",y.a);
	printf("%f\n",y.b);
	
	return 0;
}
