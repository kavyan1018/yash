#include <stdio.h>

void bubbleSort(int arr[], int n, int *outerCount, int *innerCount, int *swapCount) 
{
    int i, j, temp;
    *outerCount = 0;
    *innerCount = 0;
    *swapCount = 0;

    for (i = 0; i < n-1; i++) 
    {
        (*outerCount)++;
        for (j = 0; j < n-i-1; j++) 
        {
            (*innerCount)++;
            if (arr[j] > arr[j+1]) 
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                (*swapCount)++;
            }
        }
    }
}

int main() 
{
    int arr[] = {15, 27, 5, 2, 85, 45, 30};
    int n = sizeof(arr)/sizeof(arr[0]);
    int outerCount, innerCount, swapCount;

    bubbleSort(arr, n, &outerCount, &innerCount, &swapCount);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Outer loop executions: %d\n", outerCount);
    printf("Inner loop executions: %d\n", innerCount);
    printf("Swap operations: %d\n", swapCount);

    return 0;
}
