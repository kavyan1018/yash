// Write a program in ' C ' language to implement doubly linked list. Further, perform deletion operation into it.


#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(int data) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1); 
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertEnd(struct Node** head, int data) 
{
    struct Node* newNode = createNode(data);

    if (*head == NULL) 
    {
        *head = newNode;
    } else 
    {
        struct Node* current = *head;
        while (current->next != NULL) 
        {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}

void displayList(struct Node* head) 
{
    printf("Doubly Linked List: ");
    while (head != NULL) 
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void deleteNode(struct Node** head, int key) 
{
    if (*head == NULL)
    {
        printf("List is empty, deletion not possible\n");
        return;
    }

    struct Node* current = *head;

    while (current != NULL && current->data != key) 
    {
        current = current->next;
    }

    if (current == NULL) 
    {
        printf("Element %d not found in the list\n", key);
        return;
    }

    if (current->prev != NULL) 
    {
        current->prev->next = current->next;
    } else 
    {
        *head = current->next;
    }

    if (current->next != NULL) 
    {
        current->next->prev = current->prev;
    }

    free(current);
    printf("Element %d deleted successfully\n", key);
}

void freeList(struct Node* head) 
{
    struct Node* temp;
    while (head != NULL) 
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() 
{
    struct Node* head = NULL;

    insertEnd(&head, 1);
    insertEnd(&head, 2);
    insertEnd(&head, 3);
    insertEnd(&head, 4);

    displayList(head);

    deleteNode(&head, 2);

    displayList(head);

    freeList(head);

    return 0;
}
