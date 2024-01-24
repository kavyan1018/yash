#include <stdio.h>
#include <stdlib.h>

// Node structure for Red-Black Tree
struct Node {
    int data;
    char color; // 'R' for Red, 'B' for Black
    struct Node* parent;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node for the Red-Black Tree
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->color = 'R'; // New nodes are initially red
    newNode->parent = newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to perform left rotation in the Red-Black Tree
void leftRotate(struct Node** root, struct Node* x) {
    struct Node* y = x->right;
    x->right = y->left;

    if (y->left != NULL)
        y->left->parent = x;

    y->parent = x->parent;

    if (x->parent == NULL)
        *root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;

    y->left = x;
    x->parent = y;
}

// Function to perform right rotation in the Red-Black Tree
void rightRotate(struct Node** root, struct Node* y) {
    struct Node* x = y->left;
    y->left = x->right;

    if (x->right != NULL)
        x->right->parent = y;

    x->parent = y->parent;

    if (y->parent == NULL)
        *root = x;
    else if (y == y->parent->left)
        y->parent->left = x;
    else
        y->parent->right = x;

    x->right = y;
    y->parent = x;
}

// Function to fix the Red-Black Tree after insertion
void fixInsert(struct Node** root, struct Node* z) {
    while (z != *root && z->parent != NULL && z->parent->color == 'R') {
        if (z->parent == z->parent->parent->left) {
            struct Node* y = z->parent->parent->right;
            if (y != NULL && y->color == 'R') {
                z->parent->color = 'B';
                y->color = 'B';
                z->parent->parent->color = 'R';
                z = z->parent->parent;
            } else {
                if (z == z->parent->right) {
                    z = z->parent;
                    leftRotate(root, z);
                }
                z->parent->color = 'B';
                z->parent->parent->color = 'R';
                rightRotate(root, z->parent->parent);
            }
        } else {
            struct Node* y = z->parent->parent->left;
            if (y != NULL && y->color == 'R') {
                z->parent->color = 'B';
                y->color = 'B';
                z->parent->parent->color = 'R';
                z = z->parent->parent;
            } else {
                if (z == z->parent->left) {
                    z = z->parent;
                    rightRotate(root, z);
                }
                z->parent->color = 'B';
                z->parent->parent->color = 'R';
                leftRotate(root, z->parent->parent);
            }
        }
    }
    (*root)->color = 'B';
}

// Function to insert a node into the Red-Black Tree
void insert(struct Node** root, int data) {
    struct Node* z = createNode(data);
    struct Node* y = NULL;
    struct Node* x = *root;

    while (x != NULL) {
        y = x;
        if (z->data < x->data)
            x = x->left;
        else
            x = x->right;
    }

    z->parent = y;

    if (y == NULL)
        *root = z;
    else if (z->data < y->data)
        y->left = z;
    else
        y->right = z;

    fixInsert(root, z);
}

// Function to find the node with the minimum value in the Red-Black Tree
struct Node* findMinimum(struct Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Function to fix the Red-Black Tree after deletion
void fixDelete(struct Node** root, struct Node* x) {
    while (x != *root && (x == NULL || x->color == 'B')) {
        if (x == x->parent->left) {
            struct Node* w = x->parent->right;
            if (w->color == 'R') {
                w->color = 'B';
                x->parent->color = 'R';
                leftRotate(root, x->parent);
                w = x->parent->right;
            }
            if ((w->left == NULL || w->left->color == 'B') &&
                (w->right == NULL || w->right->color == 'B')) {
                w->color = 'R';
                x = x->parent;
            } else {
                if (w->right == NULL || w->right->color == 'B') {
                    if (w->left != NULL)
                        w->left->color = 'B';
                    w->color = 'R';
                    rightRotate(root, w);
                    w = x->parent->right;
                }
                w->color = x->parent->color;
                x->parent->color = 'B';
                if (w->right != NULL)
                    w->right->color = 'B';
                leftRotate(root, x->parent);
                x = *root; // Terminate the loop
            }
        } else {
            struct Node* w = x->parent->left;
            if (w->color == 'R') {
                w->color = 'B';
                x->parent->color = 'R';
                rightRotate(root, x->parent);
                w = x->parent->left;
            }
            if ((w->right == NULL || w->right->color == 'B') &&
                (w->left == NULL || w->left->color == 'B')) {
                w->color = 'R';
                x = x->parent;
            } else {
                if (w->left == NULL || w->left->color == 'B') {
                    if (w->right != NULL)
                        w->right->color = 'B';
                    w->color = 'R';
                    leftRotate(root, w);
                    w = x->parent->left;
                }
                w->color = x->parent->color;
                x->parent->color = 'B';
                if (w->left != NULL)
                    w->left->color = 'B';
                rightRotate(root, x->parent);
                x = *root; // Terminate the loop
            }
        }
    }
    if (x != NULL)
        x->color = 'B';
}

// Function to delete a node from the Red-Black Tree
void delete(struct Node** root, int data) {
    struct Node* z = *root;
    while (z != NULL) {
        if (data < z->data) {
            z = z->left;
        } else if (data > z->data) {
            z = z->right;
        } else {
            struct Node* y = z;
            struct Node* x;
            char yOriginalColor = y->color;

            if (z->left == NULL) {
                x = z->right;
                transplant(root, z, z->right);
            } else if (z->right == NULL) {
                x = z->left;
                transplant(root, z, z->left);
            } else {
                y = findMinimum(z->right);
                yOriginalColor = y->color;
                x = y->right;

                if (y->parent == z) {
                    if (x != NULL)
                        x->parent = y;
                } else {
                    transplant(root, y, y->right);
                    y->right = z->right;
                    if (y->right != NULL)
                        y->right->parent = y;
                }

                transplant(root, z, y);
                y->left = z->left;
                y->left->parent = y;
                y->color = z->color;
            }

            free(z);

            if (yOriginalColor == 'B') {
                fixDelete(root, x);
            }
            return;
        }
    }
    printf("Node with data %d not found in the Red-Black Tree.\n", data);
}

// Function to transplant a subtree in the Red-Black Tree
void transplant(struct Node** root, struct Node* u, struct Node* v) {
    if (u->parent == NULL) {
        *root = v;
    } else if (u == u->parent->left) {
        u->parent->left = v;
    } else {
        u->parent->right = v;
    }
    if (v != NULL) {
        v->parent = u->parent;
    }
}

// Function to perform in-order traversal of the Red-Black Tree
void inOrder(struct Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("(%d, %c) ", root->data, root->color);
        inOrder(root->right);
    }
}

// Function to print the Red-Black Tree
void printTree(struct Node* root) {
    printf("Red-Black Tree (In-order): ");
    inOrder(root);
    printf("\n");
}

int main() {
    struct Node* root = NULL;

    int keys[] = {15, 25, 2, 4, 3, 1, 50};
    int n = sizeof(keys) / sizeof(keys[0]);

    printf("Inserting elements into the Red-Black Tree:\n");
    for (int i = 0; i < n; i++) {
        insert(&root, keys[i]);
        printf("Inserted %d: ", keys[i]);
        printTree(root);
    }

    printf("\nDeleting elements from the Red-Black Tree:\n");
    for (int i = 0; i < n; i++) {
        delete(&root, keys[i]);
        printf("Deleted %d: ", keys[i]);
        printTree(root);
    }
    return 0;
}
