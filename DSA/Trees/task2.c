#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct StackNode {
    struct TreeNode* data;
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

void push(struct Stack* stack, struct TreeNode* data) {
    struct StackNode* newNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
}

struct TreeNode* pop(struct Stack* stack) {
    if (isStackEmpty(stack)) {
        return NULL;
    }

    struct StackNode* temp = stack->top;
    struct TreeNode* data = temp->data;
    stack->top = temp->next;
    free(temp);

    return data;
}

void iterativePreorder(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }

    struct Stack* stack = initializeStack();
    push(stack, root);

    while (!isStackEmpty(stack)) {
        struct TreeNode* current = pop(stack);
        printf("%d ", current->data);

        if (current->right != NULL) {
            push(stack, current->right);
        }

        if (current->left != NULL) {
            push(stack, current->left);
        }
    }

    free(stack);
}

void iterativeInorder(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }

    struct Stack* stack = initializeStack();
    struct TreeNode* current = root;

    while (current != NULL || !isStackEmpty(stack)) {
        while (current != NULL) {
            push(stack, current);
            current = current->left;
        }

        current = pop(stack);
        printf("%d ", current->data);

        current = current->right;
    }

    free(stack);
}

void iterativePostorder(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }

    struct Stack* stack1 = initializeStack();
    struct Stack* stack2 = initializeStack();

    push(stack1, root);

    while (!isStackEmpty(stack1)) {
        struct TreeNode* current = pop(stack1);
        push(stack2, current);

        if (current->left != NULL) {
            push(stack1, current->left);
        }

        if (current->right != NULL) {
            push(stack1, current->right);
        }
    }

    while (!isStackEmpty(stack2)) {
        struct TreeNode* current = pop(stack2);
        printf("%d ", current->data);
    }

    free(stack1);
    free(stack2);
}
int main() {
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->data = 1;
    root->left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->left->data = 2;
    root->left->left = NULL;
    root->left->right = NULL;
    root->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->right->data = 3;
    root->right->left = NULL;
    root->right->right = NULL;

    printf("Non-Recursive Pre-order Traversal: ");
    iterativePreorder(root);
    printf("\n");

    printf("Non-Recursive In-order Traversal: ");
    iterativeInorder(root);
    printf("\n");

    printf("Non-Recursive Post-order Traversal: ");
    iterativePostorder(root);
    printf("\n");

    free(root->left);
    free(root->right);
    free(root);

    return 0;
}