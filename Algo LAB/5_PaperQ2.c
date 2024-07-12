#include <stdio.h>

int linearSearch(int arr[], int size, int target, int *comparisonCount) 
{
    *comparisonCount = 0; 

    for (int i = 0; i < size; i++) 
    {
        (*comparisonCount)++; 
        if (arr[i] == target) 
        {
            return i; 
        }
    }
    return -1; 
}

int main() 
{
    int arr[] = {9, 15, 22, 5, 4, 25, 28}; 
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 28;
    int comparisonCount = 0;

    int result = linearSearch(arr, size, target, &comparisonCount);

    if (result != -1) 
    {
        printf("Element %d found at index %d\n", target, result);
    } else 
    {
        printf("Element %d not found in the array\n", target);
    }

    printf("Number of comparison operations required: %d\n", comparisonCount);

    return 0;
}
