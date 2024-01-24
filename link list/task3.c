#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insertBegin(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void insertInSortedOrder(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL || data < (*head)->data) {
        newNode->next = *head;
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next != NULL && current->next->data < data) {
            current = current->next;
        }

        newNode->next = current->next;
        current->next = newNode;
    }
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* list = NULL;
    int num;

    printf("Enter elements of the linked list (enter -1 to stop):\n");
    while (1) {
        scanf("%d", &num);
        if (num == -1) {
            break;
        }
        insertInSortedOrder(&list, num);
    }

    printf("Original Linked List: ");
    printList(list);

    printf("Enter an integer to insert: ");
    scanf("%d", &num);

    insertInSortedOrder(&list, num);

    printf("Updated Linked List: ");
    printList(list);

    return 0;
}
