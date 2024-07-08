#include<stdio.h>

int main()
{
    char str[100];
    int length = 0;
    int loop_count = 0;
    int comprision_count = 0;

    printf("Enter the String :-");
    gets(str);

    while (str[length] != '\0')
    {
        loop_count++;
        comprision_count++;     // Each iteration involes one comparsion 
        length++;
    }
    comprision_count++;     // one final comparsion when str[length] =='\0'

    printf("\nLength of the String : %d",length);
    printf("\nNumber of loop iteration : %d",loop_count);
    printf("\nNumber of comprision count: %d",comprision_count);
   
}