#include <stdio.h>

void insertionSort(int arr[], int n) {
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        
        // Move elements of arr[0..i-1], that are greater than key,
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int findMedian(int arr[], int n) {
    if (n != 5) {
        printf("The input array must contain exactly five integers.\n");
        return -1; // Return an invalid value to indicate an error
    }

    // Sort the array using insertionSort
    insertionSort(arr, n);

    // Return the middle element (median)
    return arr[2];
}

int main() {
    int number[5];

    printf("Enter five integers: ");
    for (int i = 0; i < 5; i++) {
        scanf("%d", &number[i]);
    }
    
    int median = findMedian(number, 5);

    if (median != -1) {
        printf("The median is: %d\n", median);
    }

    return 0;
}
