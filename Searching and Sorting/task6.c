#include <stdio.h>

void bubbleSort(int* arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (*(arr + j) > *(arr + j + 1)) {
                int temp = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = temp;
            }
        }
    }
}

int main() {
    int arr[] = {12, 4, 5, 6, 7, 3, 1, 15};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    bubbleSort(arr, size);

    printf("\nSorted Array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}