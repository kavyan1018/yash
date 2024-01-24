#include <stdio.h>
#include <stdlib.h>

struct QueueNode {
    int data;
    struct QueueNode* next;
};

struct Queue {
    struct QueueNode* front;
    struct QueueNode* rear;
};

struct Queue* initializeQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

int isQueueEmpty(struct Queue* queue) {
    return queue->front == NULL;
}

void enqueue(struct Queue* queue, int data) {
    struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    newNode->data = data;
    newNode->next = NULL;

    if (isQueueEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

int dequeue(struct Queue* queue) {
    if (isQueueEmpty(queue)) {
        printf("Queue underflow\n");
        return -1;
    }

    struct QueueNode* temp = queue->front;
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

struct Stack {
    struct Queue* q1; // Main queue for push operation
    struct Queue* q2; // Auxiliary queue for pop operation
};

struct Stack* initializeStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->q1 = initializeQueue();
    stack->q2 = initializeQueue();
    return stack;
}

void push(struct Stack* stack, int data) {
    enqueue(stack->q1, data);
}

int pop(struct Stack* stack) {
    if (isQueueEmpty(stack->q1)) {
        printf("Stack underflow\n");
        return -1;
    }

    while (stack->q1->front->next != NULL) {
        enqueue(stack->q2, dequeue(stack->q1));
    }

    int data = dequeue(stack->q1);

    struct Queue* temp = stack->q1;
    stack->q1 = stack->q2;
    stack->q2 = temp;

    return data;
}

void display(struct Stack* stack) {
    if (isQueueEmpty(stack->q1)) {
        printf("Stack is empty\n");
        return;
    }

    struct QueueNode* current = stack->q1->front;
    printf("Stack elements: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Stack* stack = initializeStack();
    int choice, data;

    do {
        printf("\nChoose operation:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display Stack\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to push: ");
                scanf("%d", &data);
                push(stack, data);
                break;

            case 2:
                data = pop(stack);
                if (data != -1) {
                    printf("Popped element: %d\n", data);
                }
                break;

            case 3:
                display(stack);
                break;

            case 4:
                printf("Exiting program\n");
                break;

            default:
                printf("Invalid choice\n");
        }
    } while (choice != 4);

    free(stack->q1);
    free(stack->q2);
    free(stack);

    return 0;
}