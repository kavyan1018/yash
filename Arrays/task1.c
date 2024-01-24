#include <stdio.h>
#include <stdlib.h>

struct Student 
{
    int enrollmentNum;
    char name[50];
    float aggregateMarks;
    int rank;
};

int compareStudents(const void *a, const void *b) 
{
    return ((struct Student *)b)->aggregateMarks - ((struct Student *)a)->aggregateMarks;
}

int main() 
{
    int n;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    struct Student *students = (struct Student *)malloc(n * sizeof(struct Student));

    for (int i = 0; i < n; i++) 
    {
        printf("\nEnter details for student %d:\n", i + 1);
        printf("Enrollment Number: ");
        scanf("%d", &students[i].enrollmentNum);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Aggregate Marks: ");
        scanf("%f", &students[i].aggregateMarks);
    }

    qsort(students, n, sizeof(struct Student), compareStudents);

    for (int i = 0; i < n; i++) 
    {
        students[i].rank = i + 1;
    }

    qsort(students, n, sizeof(struct Student), compareStudents);

    printf("\nEnrollment Number\tName\t\tRank\n");
    for (int i = 0; i < n; i++) 
    {
        printf("%d\t\t\t%s\t\t\t%d\n", students[i].enrollmentNum, students[i].name, students[i].rank);
    }


    return 0;
}
