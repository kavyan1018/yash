#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node* front;
    struct Node* rear;
};

struct Stack {
    struct Node* top;
};

struct Queue* initializeQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

struct Stack* initializeStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = NULL;
    return stack;
}

int isEmpty(struct Queue* queue) {
    return queue->front == NULL;
}

void enqueue(struct Queue* queue, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (isEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue underflow\n");
        return -1;
    }

    struct Node* temp = queue->front;
    int data = temp->data;

    if (queue->front == queue->rear) {
        queue->front = NULL;
        queue->rear = NULL;
    } else {
        queue->front = temp->next;
    }

    free(temp);
    return data;
}

void push(struct Stack* stack, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
}

int pop(struct Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack underflow\n");
        return -1;
    }

    struct Node* temp = stack->top;
    int data = temp->data;
    stack->top = temp->next;
    free(temp);

    return data;
}

void reverseQueue(struct Queue* queue) {
    struct Stack* stack = initializeStack();

    while (!isEmpty(queue)) {
        push(stack, dequeue(queue));
    }

    while (stack->top != NULL) {
        enqueue(queue, pop(stack));
    }

    free(stack);
}

void display(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }

    struct Node* current = queue->front;
    printf("Queue elements: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Queue* queue = initializeQueue();
    int choice, data;

    do {
        // Menu
        printf("\nChoose operation:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Reverse Queue\n");
        printf("4. Display Queue\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to enqueue: ");
                scanf("%d", &data);
                enqueue(queue, data);
                break;

            case 2:
                data = dequeue(queue);
                if (data != -1) {
                    printf("Dequeued element: %d\n", data);
                }
                break;

            case 3:
                reverseQueue(queue);
                printf("Queue reversed\n");
                break;

            case 4:
                display(queue);
                break;

            case 5:
                printf("Exiting program\n");
                break;

            default:
                printf("Invalid choice\n");
        }
    } while (choice != 5);

    struct Node* current = queue->front;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
    free(queue);

    return 0;
}
