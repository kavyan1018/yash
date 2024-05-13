// Write a program in ' C ' using linked list to add two polynomials.

#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int coefficient;
    int exponent;
    struct Node* next;
};

struct Node* createNode(int coefficient, int exponent) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) 
    {
        printf("Memory allocation failed\n");
        exit(1); 
    }
    newNode->coefficient = coefficient;
    newNode->exponent = exponent;
    newNode->next = NULL;
    return newNode;
}

void insertTerm(struct Node** head, int coefficient, int exponent) 
{
    struct Node* newNode = createNode(coefficient, exponent);

    if (*head == NULL) 
    {
        *head = newNode;
    } else 
    {
        struct Node* current = *head;
        struct Node* prev = NULL;

        while (current != NULL && current->exponent > exponent) 
        {
            prev = current;
            current = current->next;
        }

        if (current != NULL && current->exponent == exponent) 
        {
            current->coefficient += coefficient;
            free(newNode); 
        } else {
            newNode->next = current;
            if (prev == NULL) 
            {
                *head = newNode;
            } else 
            {
                prev->next = newNode;
            }
        }
    }
}

struct Node* addPolynomials(struct Node* poly1, struct Node* poly2) 
{
    struct Node* result = NULL;

    while (poly1 != NULL || poly2 != NULL) 
    {
        if (poly1 == NULL) 
        {
            insertTerm(&result, poly2->coefficient, poly2->exponent);
            poly2 = poly2->next;
        } else if (poly2 == NULL) 
        {
            insertTerm(&result, poly1->coefficient, poly1->exponent);
            poly1 = poly1->next;
        } else 
        {
            if (poly1->exponent > poly2->exponent) 
            {
                insertTerm(&result, poly1->coefficient, poly1->exponent);
                poly1 = poly1->next;
            } else if (poly1->exponent < poly2->exponent) 
            {
                insertTerm(&result, poly2->coefficient, poly2->exponent);
                poly2 = poly2->next;
            } else 
            {

                insertTerm(&result, poly1->coefficient + poly2->coefficient, poly1->exponent);
                poly1 = poly1->next;
                poly2 = poly2->next;
            }
        }
    }

    return result;
}

void displayPolynomial(struct Node* poly) 
{
    if (poly == NULL) 
    {
        printf("0\n");
        return;
    }

    while (poly != NULL) 
    {
        printf("%dx^%d", poly->coefficient, poly->exponent);
        poly = poly->next;
        if (poly != NULL) 
        {
            printf(" + ");
        }
    }
    printf("\n");
}

void freePolynomial(struct Node* poly) 
{
    struct Node* temp;
    while (poly != NULL) 
    {
        temp = poly;
        poly = poly->next;
        free(temp);
    }
}

int main() 
{
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;
    struct Node* result = NULL;

    int n1, coeff1, exp1;
    printf("Enter the number of terms in the first polynomial: ");
    scanf("%d", &n1);
    printf("Enter the terms (coefficient exponent) for the first polynomial:\n");
    for (int i = 0; i < n1; ++i) 
    {
        scanf("%d %d", &coeff1, &exp1);
        insertTerm(&poly1, coeff1, exp1);
    }

    int n2, coeff2, exp2;
    printf("Enter the number of terms in the second polynomial: ");
    scanf("%d", &n2);
    printf("Enter the terms (coefficient exponent) for the second polynomial:\n");
    for (int i = 0; i < n2; ++i) 
    {
        scanf("%d %d", &coeff2, &exp2);
        insertTerm(&poly2, coeff2, exp2);
    }

    result = addPolynomials(poly1, poly2);

    printf("First Polynomial: ");
    displayPolynomial(poly1);
    printf("Second Polynomial: ");
    displayPolynomial(poly2);
    printf("Sum of the Polynomials: ");
    displayPolynomial(result);

    freePolynomial(poly1);
    freePolynomial(poly2);
    freePolynomial(result);


    return 0;
}
