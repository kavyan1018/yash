#include <stdio.h>
#define MAX_SIZE 10

struct SparseMatrix 
{
    int row;
    int col;
    int value;
};

void multiplySparseMatrices(struct SparseMatrix matrix1[], int size1, struct SparseMatrix matrix2[], int size2, struct SparseMatrix result[]) 
{
    int resultIndex = 0;

    for (int i = 0; i < size1; ++i) 
    {
        for (int j = 0; j < size2; ++j) 
        {
            if (matrix1[i].col == matrix2[j].row) 
            {
                result[resultIndex].row = matrix1[i].row;
                result[resultIndex].col = matrix2[j].col;
                result[resultIndex].value = matrix1[i].value * matrix2[j].value;
                resultIndex++;
            }
        }
    }
}

void printSparseMatrix(struct SparseMatrix matrix[], int size) 
{
    printf("Row\tColumn\tValue\n");
    for (int i = 0; i < size; ++i) 
    {
        printf("%d\t%d\t%d\n", matrix[i].row, matrix[i].col, matrix[i].value);
    }
}

int main() 
{
    int size1, size2;

    printf("Enter the size of the first sparse matrix: ");
    scanf("%d", &size1);

    struct SparseMatrix matrix1[MAX_SIZE];
    printf("Enter elements of the first sparse matrix (Row Column Value):\n");
    for (int i = 0; i < size1; ++i) 
    {
        scanf("%d %d %d", &matrix1[i].row, &matrix1[i].col, &matrix1[i].value);
    }

    printf("Enter the size of the second sparse matrix: ");
    scanf("%d", &size2);

    struct SparseMatrix matrix2[MAX_SIZE];
    printf("Enter elements of the second sparse matrix (Row Column Value):\n");
    for (int i = 0; i < size2; ++i) 
    {
        scanf("%d %d %d", &matrix2[i].row, &matrix2[i].col, &matrix2[i].value);
    }

    if (matrix1[0].col != matrix2[0].row) 
    {
        printf("Matrix multiplication is not possible.\n");
        return 1;
    }

    struct SparseMatrix result[MAX_SIZE];
    multiplySparseMatrices(matrix1, size1, matrix2, size2, result);

    printf("\nResultant Sparse Matrix:\n");
    printSparseMatrix(result, size1 * size2);

    return 0;
}
