#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    int level; 
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->level = 1;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* skew(struct Node* root) {
    if (root == NULL || root->left == NULL) {
        return root;
    }

    if (root->level == root->left->level) {
        struct Node* temp = root;
        root = root->left;
        temp->left = root->right;
        root->right = temp;
    }

    return root;
}

struct Node* split(struct Node* root) {
    if (root == NULL || root->right == NULL || root->right->right == NULL) {
        return root;
    }

    if (root->level == root->right->right->level) {
        struct Node* temp = root;
        root = root->right;
        temp->right = root->left;
        root->left = temp;
        root->level++;
    }

    return root;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    } else {
        return root;
    }

    root = skew(root);
    root = split(root);

    return root;
}

struct Node* findMin(struct Node* root) {
    if (root == NULL) {
        return NULL;
    }

    while (root->left != NULL) {
        root = root->left;
    }

    return root;
}

struct Node* delete(struct Node* root, int data) {
    if (root == NULL) {
        return NULL;
    }

    if (data < root->data) {
        root->left = delete(root->left, data);
    } else if (data > root->data) {
        root->right = delete(root->right, data);
    } else {

        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        } else if (root->left == NULL) {
            struct Node* temp = root;
            root = root->right;
            free(temp);
        } else {
            struct Node* minRight = findMin(root->right);
            root->data = minRight->data;
            root->right = delete(root->right, minRight->data);
        }
    }

    root = skew(root);
    root = split(root);

    return root;
}

void inOrder(struct Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("(%d, %d) ", root->data, root->level);
        inOrder(root->right);
    }
}

void printTree(struct Node* root) {
    printf("AA-Tree (In-order): ");
    inOrder(root);
    printf("\n");
}

int main() {
    struct Node* root = NULL;

    int keys[] = {15, 25, 2, 4, 3, 1, 50};
    int n = sizeof(keys) / sizeof(keys[0]);

    printf("Inserting elements into the AA-Tree:\n");
    for (int i = 0; i < n; i++) {
        root = insert(root, keys[i]);
        printf("Inserted %d: ", keys[i]);
        printTree(root);
    }

    printf("\nDeleting elements from the AA-Tree:\n");
    for (int i = 0; i < n; i++) {
        root = delete(root, keys[i]);
        printf("Deleted %d: ", keys[i]);
        printTree(root);
    }
    return 0;
}