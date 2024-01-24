#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insertEnd(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void findCommonElements(struct Node* listA, struct Node* listB) {
    struct Node* result = NULL;

    while (listA != NULL && listB != NULL) {
        if (listA->data == listB->data) {
            insertEnd(&result, listA->data);
            listA = listA->next;
            listB = listB->next;
        } else if (listA->data < listB->data) {
            listA = listA->next;
        } else {
            listB = listB->next;
        }
    }

    printf("Common elements: ");
    printList(result);
}

int main() 
{
    struct Node* listA = NULL;
    struct Node* listB = NULL;

    insertEnd(&listA, 1);
    insertEnd(&listA, 3);
    insertEnd(&listA, 5);
    insertEnd(&listA, 7);

    insertEnd(&listB, 3);
    insertEnd(&listB, 7);
    insertEnd(&listB, 9);

    printf("List A: ");
    printList(listA);

    printf("List B: ");
    printList(listB);

    findCommonElements(listA, listB);

    return 0;
}
