#include <stdio.h>

int* linearSearch(int* arr, int size, int key) {
    int* ptr = NULL;  

    for (int i = 0; i < size; i++) {
        if (*arr == key) {
            ptr = arr;  
            break;
        }
        arr++;  
    }

    return ptr;
}

int main() {
    int arr[] = {10, 23, 5, 17, 8, 12, 15};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key;

    printf("Enter the element to search: ");
    scanf("%d", &key);

    int* result = linearSearch(arr, size, key);

    if (result != NULL) {
        printf("Element %d found at index %ld\n", key, result - arr);
    } else {
        printf("Element %d not found in the array\n", key);
    }

    return 0;
}