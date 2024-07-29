// Write a program in ' C ' language to implement doubly linked list. Further, perform deletion operation into it.


#include <stdio.h>
#include <stdlib.h>

// Structure for a node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to insert a node at the beginning of the list
void insertAtBeginning(struct Node** head, int data) {
    // Create a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = (*head);

    // Update the previous pointer of the head node
    if ((*head) != NULL) {
        (*head)->prev = newNode;
    }

    // Update the head pointer
    (*head) = newNode;
}

// Function to delete a node from the list
void deleteNode(struct Node** head, struct Node* delNode) {
    // Base case
    if ((*head) == NULL || delNode == NULL) {
        return;
    }

    // If the node to be deleted is the head node
    if ((*head) == delNode) {
        (*head) = delNode->next;
    }

    // Update the next pointer of the previous node
    if (delNode->prev != NULL) {
        delNode->prev->next = delNode->next;
    }

    // Update the previous pointer of the next node
    if (delNode->next != NULL) {
        delNode->next->prev = delNode->prev;
    }

    // Free the memory occupied by the node
    free(delNode);
}

// Function to print the doubly linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// Main function
int main() {
    struct Node* head = NULL;

    // Insert nodes at the beginning of the list
    insertAtBeginning(&head, 3);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 1);

    printf("Original list: ");
    printList(head);

    // Delete the second node
    deleteNode(&head, head->next);

    printf("List after deletion: ");
    printList(head);

    return 0;
}