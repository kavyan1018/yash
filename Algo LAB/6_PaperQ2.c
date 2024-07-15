#include <stdio.h>

void printArray(int arr[], int size) 
{
    for (int i = 0; i < size; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void selectionSort(int arr[], int n, int *innerLoopCount, int *comparisonCount) 
{
    int i, j, minIdx;
    *innerLoopCount = 0;
    *comparisonCount = 0;

    for (i = 0; i < n-1; i++) 
    {
        minIdx = i;
        for (j = i+1; j < n; j++) 
        {
            (*comparisonCount)++;
            (*innerLoopCount)++;
            if (arr[j] < arr[minIdx]) 
            {
                minIdx = j;
            }
        }

        // Swap the found minimum element with the first element
        if (minIdx != i) 
        {
            int temp = arr[minIdx];
            arr[minIdx] = arr[i];
            arr[i] = temp;
        }

        // Print intermediate steps
        printf("Step %d: ", i + 1);
        printArray(arr, n);
    }
}

int main() 
{
    int arr[] = {35, 25, 15, 5, 14, 18, 16, 13, 17, 19};
    int n = sizeof(arr) / sizeof(arr[0]);
    int innerLoopCount = 0;
    int comparisonCount = 0;

    printf("Original array: ");
    printArray(arr, n);

    selectionSort(arr, n, &innerLoopCount, &comparisonCount);

    printf("Sorted array: ");
    printArray(arr, n);

    printf("Number of inner loop executions: %d\n", innerLoopCount);
    printf("Number of key comparisons: %d\n", comparisonCount);

    return 0;
}
