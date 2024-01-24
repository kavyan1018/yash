#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Deque {
    struct Node* front;
    struct Node* rear;
};

struct Deque* initializeDeque() {
    struct Deque* deque = (struct Deque*)malloc(sizeof(struct Deque));
    deque->front = NULL;
    deque->rear = NULL;
    return deque;
}

int isEmpty(struct Deque* deque) {
    return deque->front == NULL;
}

void insertFront(struct Deque* deque, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (isEmpty(deque)) {
        newNode->prev = NULL;
        deque->front = newNode;
        deque->rear = newNode;
    } else {
        newNode->prev = NULL;
        newNode->next = deque->front;
        deque->front->prev = newNode;
        deque->front = newNode;
    }
}

void insertRear(struct Deque* deque, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (isEmpty(deque)) {
        newNode->prev = NULL;
        deque->front = newNode;
        deque->rear = newNode;
    } else {
        newNode->prev = deque->rear;
        deque->rear->next = newNode;
        deque->rear = newNode;
    }
}

int deleteFront(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque underflow\n");
        return -1;
    }

    struct Node* temp = deque->front;
    int data = temp->data;

    if (deque->front == deque->rear) {
        deque->front = NULL;
        deque->rear = NULL;
    } else {
        deque->front = temp->next;
        deque->front->prev = NULL;
    }

    free(temp);
    return data;
}

int deleteRear(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque underflow\n");
        return -1;
    }

    struct Node* temp = deque->rear;
    int data = temp->data;

    if (deque->front == deque->rear) {
        deque->front = NULL;
        deque->rear = NULL;
    } else {
        deque->rear = temp->prev;
        deque->rear->next = NULL;
    }

    free(temp);
    return data;
}

void display(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty\n");
        return;
    }

    struct Node* current = deque->front;
    printf("Deque elements: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Deque* deque = initializeDeque();
    int choice, data;

    do {
        printf("\nChoose operation:\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at Rear\n");
        printf("3. Delete from Front\n");
        printf("4. Delete from Rear\n");
        printf("5. Display Deque\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at front: ");
                scanf("%d", &data);
                insertFront(deque, data);
                break;

            case 2:
                printf("Enter data to insert at rear: ");
                scanf("%d", &data);
                insertRear(deque, data);
                break;

            case 3:
                data = deleteFront(deque);
                if (data != -1) {
                    printf("Deleted element from front: %d\n", data);
                }
                break;

            case 4:
                data = deleteRear(deque);
                if (data != -1) {
                    printf("Deleted element from rear: %d\n", data);
                }
                break;

            case 5:
                display(deque);
                break;

            case 6:
                printf("Exiting program\n");
                break;

            default:
                printf("Invalid choice\n");
        }
    } while (choice != 6);

    struct Node* current = deque->front;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
    free(deque);

    return 0;
}