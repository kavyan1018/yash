#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct StackNode {
    char data;
    struct StackNode* next;
};

struct StackNode* initializeStack() {
    return NULL;
}

int isEmpty(struct StackNode* top) {
    return top == NULL;
}

void push(struct StackNode** top, char data) {
    struct StackNode* newNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    newNode->data = data;
    newNode->next = *top;
    *top = newNode;
}

char pop(struct StackNode** top) {
    if (isEmpty(*top)) {
        printf("Error: Stack is empty\n");
        exit(EXIT_FAILURE);
    }

    char data = (*top)->data;
    struct StackNode* temp = *top;
    *top = (*top)->next;
    free(temp);

    return data;
}

void prefixToPostfix(char* prefix) {
    struct StackNode* stack = initializeStack();

    int length = strlen(prefix);

    for (int i = length - 1; i >= 0; i--) {
        if (isalnum(prefix[i])) {
            push(&stack, prefix[i]);
        } else {
            char operand1 = pop(&stack);
            char operand2 = pop(&stack);

            char result[3];
            result[0] = operand1;
            result[1] = operand2;
            result[2] = prefix[i];

            for (int j = 0; j < 3; j++) {
                push(&stack, result[j]);
            }
        }
    }

    printf("Postfix Expression: ");
    while (!isEmpty(stack)) {
        printf("%c", pop(&stack));
    }
    printf("\n");
}

int main() {
    char prefix[100];

    printf("Enter the prefix expression: ");
    scanf("%s", prefix);

    prefixToPostfix(prefix);
    return 0;
}