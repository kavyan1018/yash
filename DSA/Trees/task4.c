#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int isFullBinaryTree(struct TreeNode* root) {
    if (root == NULL) {
        return 1;
    }
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }
    if ((root->left == NULL && root->right != NULL) || (root->left != NULL && root->right == NULL)) {
        return 0;
    }
    return isFullBinaryTree(root->left) && isFullBinaryTree(root->right);
}

int main() {
    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);

    if (isFullBinaryTree(root)) {
        printf("The binary tree is a full binary tree.\n");
    } else {
        printf("The binary tree is not a full binary tree.\n");
    }

    free(root->left->left);
    free(root->left->right);
    free(root->right->left);
    free(root->left);
    free(root->right);
    free(root);

    return 0;
}