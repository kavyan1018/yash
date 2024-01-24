#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int key) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* zig(struct Node* x) {
    struct Node* y = x->left;
    x->left = y->right;
    y->right = x;
    return y;
}

struct Node* zag(struct Node* x) {
    struct Node* y = x->right;
    x->right = y->left;
    y->left = x;
    return y;
}

struct Node* splay(struct Node* root, int key) {
    if (root == NULL || root->key == key) {
        return root;
    }

    if (key < root->key) {
        if (root->left == NULL) {
            return root;
        }

        if (key < root->left->key) {
            root->left->left = splay(root->left->left, key);
            root = zig(root);
        } else if (key > root->left->key) {
            root->left->right = splay(root->left->right, key);
            if (root->left->right != NULL) {
                root->left = zag(root->left);
            }
        }
        return (root->left == NULL) ? root : zig(root);
    }
    else {
        if (root->right == NULL) {
            return root;
        }

        if (key > root->right->key) {
            root->right->right = splay(root->right->right, key);
            root = zag(root);
        } else if (key < root->right->key) {
            root->right->left = splay(root->right->left, key);
            if (root->right->left != NULL) {
                root->right = zig(root->right);
            }
        }

        return (root->right == NULL) ? root : zag(root);
    }
}

struct Node* insert(struct Node* root, int key) {
    if (root == NULL) {
        return createNode(key);
    }

    root = splay(root, key);

    if (root->key == key) {
        return root;
    }

    struct Node* newNode = createNode(key);

    if (key < root->key) {
        newNode->right = root;
        newNode->left = root->left;
        root->left = NULL;
    }
    else {
        newNode->left = root;
        newNode->right = root->right;
        root->right = NULL;
    }

    return newNode;
}

void inOrder(struct Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->key);
        inOrder(root->right);
    }
}

int main() {
    struct Node* root = NULL;

    int keys[] = {15, 25, 2, 4, 3, 1, 50};
    int n = sizeof(keys) / sizeof(keys[0]);

    for (int i = 0; i < n; i++) {
        root = insert(root, keys[i]);
    }

    printf("In-order traversal of the Splay Tree after insertion:\n");
    inOrder(root);
    return 0;
}