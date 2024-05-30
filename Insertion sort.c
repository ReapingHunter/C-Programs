#include<stdio.h>
#include<string.h>
int main()
{
    int store[] = {53, 40, 49, 23, 19, 72, 85, 61, 69, 99};
    int k;
    int l;
    int m;
    int temp = 0;
    for(k = 1; k < 10; k++)
    {
        temp = store[k];
        l = k-1;
        while(temp < store[l] && l >= 0)
        {
            store[l+1] = store[l];
            l--;
        }
//      memmove(&store[l+1], &store[l], (k-l)*sizeof(int));
        store[l+1] = temp;
        
		for(m = 0; m < 10; m++)
        {
        	printf("%d ",store[m]);
            
    	}
    	printf("\n");
    }

    return 0;
}
