#include <stdio.h>
#include <string.h>

void findSubstring(char *S1, char *S2) 
{
    int len1 = strlen(S1);
    int len2 = strlen(S2);
    int start = -1;
    
    for (int i = 0; i <= len1 - len2; i++) {
        int j;
        for (j = 0; j < len2; j++) {
            if (S1[i + j] != S2[j])
                break;
        }
        
        if (j == len2) {
            start = i;
            break;
        }
    }

    if (start != -1) {
        printf("Substring found at positions %d to %d\n", start, start + len2 - 1);
    } else {
        printf("Substring not found in the given string.\n");
    }
}

int main() {
    char S1[100], S2[100];

    printf("Enter the main string S1: ");
    scanf("%s", S1);

    printf("Enter the substring S2: ");
    scanf("%s", S2);

    findSubstring(S1, S2);

    return 0;
}
