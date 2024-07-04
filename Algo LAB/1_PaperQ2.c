#include <stdio.h>

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int insertionSort(int arr[], int n) {
    int i, j, key;
    int comparisons = 0;

    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        // Move elements of arr[0..i-1], that are greater than key,
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
            comparisons++;
        }
        arr[j + 1] = key;

        // Print the array after each step
        printArray(arr, n);

        // If j did not go into the loop, count one comparison for the while check
        if (j != i - 1) {
            comparisons++;
        }
    }
    return comparisons;
}

int main() {
    int arr[] = {15, 10, 2, 4, 7, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Initial array:\n");
    printArray(arr, n);

    int totalComparisons = insertionSort(arr, n);

    printf("\nSorted array:\n");
    printArray(arr, n);

    printf("\nTotal comparisons: %d\n", totalComparisons);

    return 0;
}