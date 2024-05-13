#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 50

struct WordInfo 
{
    char word[MAX_WORD_LENGTH];         
    int occurrences;
};


int isSeparator(char ch) 
{
    return ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r' || ch == ',' || ch == '.' || ch == ';' || ch == '!';
}

void countOccurrences(char paragraph[], struct WordInfo wordList[], int *wordCount) 
{
    char buffer[MAX_WORD_LENGTH];
    int bufferIndex = 0;

    for (int i = 0; paragraph[i] != '\0'; ++i) 
    {
        if (!isSeparator(paragraph[i])) 
        {
            buffer[bufferIndex++] = tolower(paragraph[i]);
        } else 
        {
            if (bufferIndex > 0) 
            {
                buffer[bufferIndex] = '\0';

                int found = 0;
                for (int j = 0; j < *wordCount; ++j) 
                {
                    if (strcmp(wordList[j].word, buffer) == 0) 
                    {
                        wordList[j].occurrences++;
                        found = 1;
                        break;
                    }
                }

                if (!found && *wordCount < MAX_WORDS) 
                {
                    strcpy(wordList[*wordCount].word, buffer);
                    wordList[*wordCount].occurrences = 1;
                    (*wordCount)++;
                }

                bufferIndex = 0;
            }
        }
    }
}

void printWordOccurrences(struct WordInfo wordList[], int wordCount) {
    printf("Word\t\tOccurrences\n");
    for (int i = 0; i < wordCount; ++i) 
    {
        printf("%-15s%d\n", wordList[i].word, wordList[i].occurrences);
    }
}

int main() {
    char paragraph[1000];
    struct WordInfo wordList[MAX_WORDS];
    int wordCount = 0;

    printf("Enter a paragraph of text:\n");
    fgets(paragraph, sizeof(paragraph), stdin);

    countOccurrences(paragraph, wordList, &wordCount);

    printf("\nWord Occurrences in the Paragraph:\n");
    printWordOccurrences(wordList, wordCount);

    return 0;
}
