#include <stdio.h>

void selectionSort(int arr[], int n, int *comparison_count) {
    int i, j, min_index, temp;
    *comparison_count = 0;
    for (i = 0; i < n-1; i++) {
        
        min_index = i;
        for (j = i + 1; j < n; j++) {
            (*comparison_count)++;
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        
        temp = arr[min_index];
        arr[min_index] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    int arr[] = {17, 7, 8, 15, 6, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int comparison_count;
    
    selectionSort(arr, n, &comparison_count);
    
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    printf("Total number of comparisons: %d\n", comparison_count);
    
    return 0;
}