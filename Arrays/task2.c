#include <stdio.h>
#include <stdlib.h>
struct Node {
    int row, col, value;
    struct Node* next;
};

struct Node* multiplySparseMatrices(struct Node* mat1, struct Node* mat2) 
{

    struct Node* result = NULL;

    while (mat1 != NULL) 
    {
        struct Node* tempMat2 = mat2;
        while (tempMat2 != NULL) 
        {
            if (mat1->col == tempMat2->row) 
            {
                int product = mat1->value * tempMat2->value;

                struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
                newNode->row = mat1->row;
                newNode->col = tempMat2->col;
                newNode->value = product;
                newNode->next = result;
                result = newNode;
            }

            tempMat2 = tempMat2->next;
        }

        mat1 = mat1->next;
    }

    return result;
}

void displaySparseMatrix(struct Node* mat) 
{
    while (mat != NULL) {
        printf("(%d, %d, %d) ", mat->row, mat->col, mat->value);
        mat = mat->next;
    }
    printf("\n");
}

void freeSparseMatrix(struct Node* mat) 
{
    struct Node* temp;
    while (mat != NULL) 
    {
        temp = mat;
        mat = mat->next;
        free(temp);
    }
}

int main() 
{
    struct Node* mat1 = NULL;
    struct Node* mat2 = NULL;

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->row = 0;
    newNode->col = 0;
    newNode->value = 1;
    newNode->next = mat1;
    mat1 = newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->row = 1;
    newNode->col = 1;
    newNode->value = 2;
    newNode->next = mat1;
    mat1 = newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->row = 2;
    newNode->col = 2;
    newNode->value = 3;
    newNode->next = mat1;
    mat1 = newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->row = 0;
    newNode->col = 0;
    newNode->value = 4;
    newNode->next = mat2;
    mat2 = newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->row = 1;
    newNode->col = 1;
    newNode->value = 5;
    newNode->next = mat2;
    mat2 = newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->row = 2;
    newNode->col = 2;
    newNode->value = 6;
    newNode->next = mat2;
    mat2 = newNode;

    printf("Matrix 1:\n");
    displaySparseMatrix(mat1);

    printf("Matrix 2:\n");
    displaySparseMatrix(mat2);

    struct Node* result = multiplySparseMatrices(mat1, mat2);

    printf("Result Matrix:\n");
    displaySparseMatrix(result);

    freeSparseMatrix(mat1);
    freeSparseMatrix(mat2);
    freeSparseMatrix(result);

    return 0;
}
