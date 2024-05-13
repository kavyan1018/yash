#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* concatenateStrings(const char* s1, const char* s2) {
    size_t len_s1 = strlen(s1);
    size_t len_s2 = strlen(s2);
    size_t len_result = len_s1 + len_s2 + 1; 

    char* result = (char*)malloc(len_result * sizeof(char));

    if (result == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    strcpy(result, s1);

    strcat(result, s2);

    return result;
}
int main() {
    char s1[50], s2[50];

    printf("Enter the first string (s1): ");
    scanf("%s", s1);

    printf("Enter the second string (s2): ");
    scanf("%s", s2);

    char* concatenatedString = concatenateStrings(s1, s2);

    printf("Concatenated String: %s\n", concatenatedString);

    free(concatenatedString);
    return 0;
}
