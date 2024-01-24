#include <stdio.h>
#include <stdlib.h>

struct StackNode {
    int data;
    struct StackNode* next;
};

struct Stack {
    struct StackNode* top;
};

struct Stack* initializeStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = NULL;
    return stack;
}

int isStackEmpty(struct Stack* stack) {
    return stack->top == NULL;
}

void push(struct Stack* stack, int data) {
    struct StackNode* newNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
}

int pop(struct Stack* stack) {
    if (isStackEmpty(stack)) {
        printf("Stack underflow\n");
        return -1;
    }

    struct StackNode* temp = stack->top;
    int data = temp->data;
    stack->top = temp->next;
    free(temp);

    return data;
}

struct Queue {
    struct Stack* stack1; 
    struct Stack* stack2; 
};

struct Queue* initializeQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->stack1 = initializeStack();
    queue->stack2 = initializeStack();
    return queue;
}

void enqueue(struct Queue* queue, int data) {
    push(queue->stack1, data);
}

int dequeue(struct Queue* queue) {
    if (isStackEmpty(queue->stack1) && isStackEmpty(queue->stack2)) {
        printf("Queue underflow\n");
        return -1;
    }

    if (isStackEmpty(queue->stack2)) {
        while (!isStackEmpty(queue->stack1)) {
            push(queue->stack2, pop(queue->stack1));
        }
    }

    return pop(queue->stack2);
}

void display(struct Queue* queue) {
    if (isStackEmpty(queue->stack1) && isStackEmpty(queue->stack2)) {
        printf("Queue is empty\n");
        return;
    }

    struct StackNode* current = queue->stack2->top;
    printf("Queue elements: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    current = queue->stack1->top;
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
        printf("\nChoose operation:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
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
                display(queue);
                break;

            case 4:
                printf("Exiting program\n");
                break;

            default:
                printf("Invalid choice\n");
        }
    } while (choice != 4);

    free(queue->stack1);
    free(queue->stack2);
    free(queue);

    return 0;
}