#include <stdio.h>
#include <string.h>

// Function to combine two strings
void combineStrings(char str1[], char str2[], char result[], int *loopCount, int *comparisonCount) 
{
    int i = 0, j = 0;
    *loopCount = 0;
    *comparisonCount = 0;

    // Copy first string to result
    while (str1[i] != '\0') 
    {
        result[i] = str1[i];
        i++;
        (*loopCount)++;
        (*comparisonCount)++;
    }

    // Copy second string to result
    while (str2[j] != '\0') 
    {
        result[i] = str2[j];
        i++;
        j++;
        (*loopCount)++;
        (*comparisonCount)++;
    }

    result[i] = '\0'; // Null-terminate the combined string
}

int main() 
{
    char str1[] = "Hello, ";
    char str2[] = "World!";
    char result[100]; // Ensure this is large enough to hold the combined string
    int loopCount = 0;
    int comparisonCount = 0;

    combineStrings(str1, str2, result, &loopCount, &comparisonCount);

    printf("Combined String: %s\n", result);
    printf("Number of loop executions: %d\n", loopCount);
    printf("Number of comparison operations: %d\n", comparisonCount);

    return 0;
}
