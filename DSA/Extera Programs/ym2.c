// Write a program in ' C ' language to convert a prefix expression to a postfix expression using appropriate Data Structure.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct Stack 
{
    int top;
    char array[MAX_SIZE];
};

void initializeStack(struct Stack* stack) 
{
    stack->top = -1;
}

int isEmpty(struct Stack* stack) 
{
    return stack->top == -1;
}

void push(struct Stack* stack, char item) 
{
    if (stack->top == MAX_SIZE - 1) 
    {
        printf("Stack Overflow\n");
        exit(1); 
    }
    stack->array[++stack->top] = item;
}

char pop(struct Stack* stack) 
{
    if (isEmpty(stack)) 
    {
        printf("Stack Underflow\n");
        exit(1); 
    }
    return stack->array[stack->top--];
}

int isOperand(char ch) 
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

void prefixToPostfix(char prefixExpression[]) 
{
    int length = strlen(prefixExpression);
    struct Stack stack;
    initializeStack(&stack);

    for (int i = length - 1; i >= 0; i--) 
    {
        char symbol = prefixExpression[i];

        if (isOperand(symbol)) 
        {
            push(&stack, symbol);
        } else 
        {
            char operand1 = pop(&stack);
            char operand2 = pop(&stack);
            char postfixExpression[3] = {operand1, operand2, symbol};
            strcat(postfixExpression, "");
            push(&stack, postfixExpression[0]);
        }
    }

    char postfixExpression = pop(&stack);

    printf("Postfix Expression: %c\n", postfixExpression);
}

int main() 
{
    char prefixExpression[MAX_SIZE];

    printf("Enter the prefix expression: ");
    scanf("%s", prefixExpression);

    prefixToPostfix(prefixExpression);

    return 0;
}