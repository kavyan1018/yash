// Write a program in ' C ' language to implement a queue using two stacks.

#include <stdio.h>
#include <stdlib.h>

struct Stack 
{
    int capacity;
    int top;
    int* array;
};

struct Stack* createStack(int capacity) 
{
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

int isEmpty(struct Stack* stack) 
{
    return (stack->top == -1);
}

int isFull(struct Stack* stack) 
{
    return (stack->top == stack->capacity - 1);
}

void push(struct Stack* stack, int item) 
{
    if (isFull(stack)) 
    {
        printf("Stack Overflow\n");
        return;
    }
    stack->array[++stack->top] = item;
}

int pop(struct Stack* stack) 
{
    if (isEmpty(stack)) 
    {
        printf("Stack Underflow\n");
        return -1; 
    }
    return stack->array[stack->top--];
}

void enqueue(struct Stack* stack1, struct Stack* stack2, int item) 
{
    
    push(stack1, item);
}

int dequeue(struct Stack* stack1, struct Stack* stack2) 
{
    int item;

    if (isEmpty(stack1) && isEmpty(stack2)) 
    {
        printf("Queue is empty\n");
        return -1; 
    }

    if (isEmpty(stack2)) 
    {
        while (!isEmpty(stack1)) 
        {
            item = pop(stack1);
            push(stack2, item);
        }
    }

    item = pop(stack2);
    return item;
}

int main() 
{
    struct Stack* stack1 = createStack(100);
    struct Stack* stack2 = createStack(100);

    enqueue(stack1, stack2, 1);
    enqueue(stack1, stack2, 2);
    enqueue(stack1, stack2, 3);

    printf("Dequeued element: %d\n", dequeue(stack1, stack2));
    printf("Dequeued element: %d\n", dequeue(stack1, stack2));
    printf("Dequeued element: %d\n", dequeue(stack1, stack2));

    return 0;
}
