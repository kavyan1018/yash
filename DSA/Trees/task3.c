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

struct TreeNode* convertToBinaryTree(struct TreeNode* treeRoot) {
    if (treeRoot == NULL) {
        return NULL;
    }

    struct Stack* stack = initializeStack();
    struct TreeNode* binaryRoot = NULL;

    push(stack, treeRoot);
    binaryRoot = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    binaryRoot->data = treeRoot->data;
    binaryRoot->left = NULL;
    binaryRoot->right = NULL;

    while (!isStackEmpty(stack)) {
        struct TreeNode* current = pop(stack);

        if (current->right != NULL) {
            struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
            newNode->data = current->right->data;
            newNode->left = NULL;
            newNode->right = NULL;
            binaryRoot->right = newNode;
            push(stack, current->right);
        }

        if (current->left != NULL) {
            struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
            newNode->data = current->left->data;
            newNode->left = NULL;
            newNode->right = NULL;
            binaryRoot->left = newNode;
            push(stack, current->left);
        }
    }

    free(stack);
    return binaryRoot;
}

void printBinaryTree(struct TreeNode* root) {
    if (root != NULL) {
        printBinaryTree(root->left);
        printf("%d ", root->data);
        printBinaryTree(root->right);
    }
}

int main() {
    struct TreeNode* treeRoot = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    treeRoot->data = 1;
    treeRoot->left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    treeRoot->left->data = 2;
    treeRoot->left->left = NULL;
    treeRoot->left->right = NULL;
    treeRoot->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    treeRoot->right->data = 3;
    treeRoot->right->left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    treeRoot->right->left->data = 4;
    treeRoot->right->left->left = NULL;
    treeRoot->right->left->right = NULL;
    treeRoot->right->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    treeRoot->right->right->data = 5;
    treeRoot->right->right->left = NULL;
    treeRoot->right->right->right = NULL;

    struct TreeNode* binaryRoot = convertToBinaryTree(treeRoot);

    printf("Resultant Binary Tree (Inorder Traversal): ");
    printBinaryTree(binaryRoot);
    printf("\n");

    return 0;
}