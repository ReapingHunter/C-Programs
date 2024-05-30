#include <stdio.h>

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void permute(int arr[], int start, int end) {
	int i;
    if (start == end) {
        // Print the current permutation
        for (i = 0; i <= end; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    } else {
        for (i = start; i <= end; i++) {
            // Swap the current element with itself and all other elements
            swap(&arr[start], &arr[i]);

            // Recursively generate permutations for the remaining elements
            permute(arr, start + 1, end);

            // Restore the original order of the array (backtracking)
            swap(&arr[start], &arr[i]);
        }
    }
}

int main() {
	int i;
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("All permutations of the array:\n");
    permute(arr, 0, n - 1);

    return 0;
}
