#include <stdio.h>

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bubbleSort(int arr[], int size) {
    int outer_loop_count = 0;
    int inner_loop_count = 0;
    int temp;

    for (int i = 0; i < size - 1; i++) {
        outer_loop_count++;
        for (int j = 0; j < size - i - 1; j++) {
            inner_loop_count++;
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
            // Print array after each inner loop iteration
            printArray(arr, size);
        }
    }

    printf("Total outer loop executions: %d\n", outer_loop_count);
    printf("Total inner loop executions: %d\n", inner_loop_count);
}

int main() {
    int arr[10] = {25, 15, 10, 5, 4, 8, 16, 13, 7, 9};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, size);

    bubbleSort(arr, size);

    printf("Sorted array: ");
    printArray(arr, size);

    return 0;
}
