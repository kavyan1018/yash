#include <stdio.h>
#include <string.h>

struct Student 
{
    char enrolmentNumber[20];
    char name[50];
    float aggregateMarks;
    int rank;
};

void assignRanks(struct Student students[], int n) 
{
    for (int i = 0; i < n; ++i) 
    {
        students[i].rank = 1;
        for (int j = 0; j < n; ++j) 
        {
            if (j != i && students[j].aggregateMarks > students[i].aggregateMarks) 
            {
                students[i].rank++;
            }
        }
    }
}

void printStudentDetails(struct Student students[], int n) 
{
    printf("Enrollment Number\tName\t\tAggregate Marks\tRank\n");
    for (int i = 0; i < n; ++i) 
    {
        printf("%s\t\t\t%s\t\t%.2f\t\t%d\n", students[i].enrolmentNumber, students[i].name, students[i].aggregateMarks, students[i].rank);
    }
}

int main() 
{
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);

    struct Student students[n];

    for (int i = 0; i < n; ++i) 
    {
        printf("Enter details for student %d:\n", i + 1);
        printf("Enrollment Number: ");
        scanf("%s", students[i].enrolmentNumber);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Aggregate Marks: ");
        scanf("%f", &students[i].aggregateMarks);
    }

    assignRanks(students, n);

    for (int i = 0; i < n - 1; ++i) 
    {
        for (int j = 0; j < n - i - 1; ++j) 
        {
            if (students[j].rank > students[j + 1].rank) 
            {
                struct Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }

    printf("\nStudent Ranks in Ascending Order:\n");
    printStudentDetails(students, n);
    
    return 0;
}