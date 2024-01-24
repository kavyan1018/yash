#include <stdio.h>
#include <stdlib.h>
struct AVLNode {
    int data;
    int height;
    struct AVLNode* left;
    struct AVLNode* right;
};
struct AVLNode* createNode(int value) {
    struct AVLNode* newNode = (struct AVLNode*)malloc(sizeof(struct AVLNode));
    newNode->data = value;
    newNode->height = 1; 
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
int getHeight(struct AVLNode* node) {
    if (node == NULL) {
        return 0;
    }
    return node->height;
}

int getBalanceFactor(struct AVLNode* node) {
    if (node == NULL) {
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}
struct AVLNode* rightRotate(struct AVLNode* y) {
    struct AVLNode* x = y->left;
    struct AVLNode* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + fmax(getHeight(y->left), getHeight(y->right));
    x->height = 1 + fmax(getHeight(x->left), getHeight(x->right));

    return x;
}

struct AVLNode* leftRotate(struct AVLNode* x) {
    struct AVLNode* y = x->right;
    struct AVLNode* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + fmax(getHeight(x->left), getHeight(x->right));
    y->height = 1 + fmax(getHeight(y->left), getHeight(y->right));

    return y;
}

struct AVLNode* insert(struct AVLNode* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    } else {
        return root;
    }

    root->height = 1 + fmax(getHeight(root->left), getHeight(root->right));

    int balance = getBalanceFactor(root);

    if (balance > 1 && value < root->left->data) {
        return rightRotate(root);
    }

    if (balance < -1 && value > root->right->data) {
        return leftRotate(root);
    }
    if (balance > 1 && value > root->left->data) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (balance < -1 && value < root->right->data) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}
void inorderTraversal(struct AVLNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main() {
    struct AVLNode* avlRoot = NULL;
    avlRoot = insert(avlRoot, 15);
    avlRoot = insert(avlRoot, 25);
    avlRoot = insert(avlRoot, 2);
    avlRoot = insert(avlRoot, 4);
    avlRoot = insert(avlRoot, 3);
    avlRoot = insert(avlRoot, 1);
    avlRoot = insert(avlRoot, 50);

    printf("Inorder traversal of AVL tree: ");
    inorderTraversal(avlRoot);
    printf("\n");

    free(avlRoot->left->left);
    free(avlRoot->left->right);
    free(avlRoot->right->left);
    free(avlRoot->left);
    free(avlRoot->right);
    free(avlRoot);

    return 0;
}