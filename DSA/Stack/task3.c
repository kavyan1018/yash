#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

struct Stack {
    int top;
    int capacity;
    int* array;
};

struct Stack* initializeStack(int capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (int*)malloc(capacity * sizeof(int));
    return stack;
}

int isFull(struct Stack* stack) {
    return stack->top == stack->capacity - 1;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

void push(struct Stack* stack, int data) {
    if (isFull(stack)) {
        printf("Stack overflow\n");
        return;
    }

    stack->array[++stack->top] = data;
}

int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        return -1;
    }

    return stack->array[stack->top--];
}

int main() {
    int numStacks, capacity, choice, stackIndex, data;

    printf("Enter the number of stacks: ");
    scanf("%d", &numStacks);

    capacity = MAX_SIZE / numStacks;

    struct Stack** stacks = (struct Stack**)malloc(numStacks * sizeof(struct Stack*));

    for (int i = 0; i < numStacks; i++) {
        stacks[i] = initializeStack(capacity);
    }

    do {
        printf("\nChoose operation:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter stack index (0 to %d): ", numStacks - 1);
                scanf("%d", &stackIndex);

                if (stackIndex < 0 || stackIndex >= numStacks) {
                    printf("Invalid stack index\n");
                    break;
                }

                printf("Enter data to push: ");
                scanf("%d", &data);

                push(stacks[stackIndex], data);
                break;

            case 2:
                printf("Enter stack index (0 to %d): ", numStacks - 1);
                scanf("%d", &stackIndex);

                if (stackIndex < 0 || stackIndex >= numStacks) {
                    printf("Invalid stack index\n");
                    break;
                }

                data = pop(stacks[stackIndex]);

                if (data != -1) {
                    printf("Popped element: %d\n", data);
                }
                break;

            case 3:
                printf("Exiting program\n");
                break;

            default:
                printf("Invalid choice\n");
        }
    } while (choice != 3);

    for (int i = 0; i < numStacks; i++) {
        free(stacks[i]->array);
        free(stacks[i]);
    }
    free(stacks);

    return 0;
}