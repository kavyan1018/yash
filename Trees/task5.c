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
int areSameTrees(struct TreeNode* root1, struct TreeNode* root2) {
    if (root1 == NULL && root2 == NULL) {
        return 1;
    }
    if ((root1 == NULL && root2 != NULL) || (root1 != NULL && root2 == NULL)) {
        return 0;
    }
    return (root1->data == root2->data) &&
           areSameTrees(root1->left, root2->left) &&
           areSameTrees(root1->right, root2->right);
}

int main() {
    struct TreeNode* root1 = createNode(1);
    root1->left = createNode(2);
    root1->right = createNode(3);
    root1->left->left = createNode(4);
    root1->left->right = createNode(5);

    struct TreeNode* root2 = createNode(1);
    root2->left = createNode(2);
    root2->right = createNode(3);
    root2->left->left = createNode(4);
    root2->left->right = createNode(5);

    if (areSameTrees(root1, root2)) {
        printf("Both binary trees are the same.\n");
    } else {
        printf("The binary trees are not the same.\n");
    }

    free(root1->left->left);
    free(root1->left->right);
    free(root1->right);
    free(root1->left);
    free(root1);

    free(root2->left->left);
    free(root2->left->right);
    free(root2->right);
    free(root2->left);
    free(root2);

    return 0;
}