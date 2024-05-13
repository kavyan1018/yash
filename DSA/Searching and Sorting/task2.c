#include <stdio.h>

int* binarySearch(int* arr, int size, int key) {
    int* left = arr;
    int* right = arr + size - 1;
    int* mid;

    while (left <= right) {
        mid = left + (right - left) / 2;

        if (*mid == key) {
            return mid;  
        } else if (*mid < key) {
            left = mid + 1;  
        } else {
            right = mid - 1;  
        }
    }

    return NULL;  
}

int main() {
    int arr[] = {5, 8, 12, 15, 17, 23, 30};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key;

    printf("Enter the element to search: ");
    scanf("%d", &key);

    int* result = binarySearch(arr, size, key);

    if (result != NULL) {
        printf("Element %d found at index %ld\n", key, result - arr);
    } else {
        printf("Element %d not found in the array\n", key);
    }

    return 0;
}
