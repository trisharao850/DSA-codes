#include <stdio.h>
#include <stdlib.h>

// Structure for a node in AVL tree
struct Node {
    int key;
    struct Node *left;
    struct Node *right;
    int height;
};

// Function to get the height of a node
int getHeight(struct Node *node) {
    if (node == NULL)
        return 0;
    return node->height;
}

// Function to get the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to create a new node
struct Node *newNode(int key) {
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

// Function to right rotate subtree rooted with y
struct Node *rightRotate(struct Node *y) {
    struct Node *x = y->left;
    struct Node *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    // Return new root
    return x;
}

// Function to left rotate subtree rooted with x
struct Node *leftRotate(struct Node *x) {
    struct Node *y = x->right;
    struct Node *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    // Return new root
    return y;
}

// Get the balance factor of a node
int getBalance(struct Node *node) {
    if (node == NULL)
        return 0;
    return getHeight(node->left) - getHeight(node->right);
}

// Recursive function to insert a key in the subtree rooted with node
struct Node *insert(struct Node *node, int key) {
    // Perform the normal BST insertion
    if (node == NULL)
        return newNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else // Duplicate keys not allowed
        return node;

    // Update the height of the ancestor node
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    // Check the balance factor and rebalance if needed
    int balance = getBalance(node);

    // Left Left case
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // Right Right case
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // Left Right case
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left case
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // No imbalance, return the original node pointer
    return node;
}

// Function to print the inorder traversal of the tree
void inorderTraversal(struct Node *root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->key);
        inorderTraversal(root->right);
    }
}

// Function to delete the tree
void deleteTree(struct Node *node) {
    if (node != NULL) {
        deleteTree(node->left);
        deleteTree(node->right);
        free(node);
    }
}

int main() {
    struct Node *root = NULL;

    // Insert nodes into the AVL tree
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    // Print the inorder traversal of the AVL tree
    printf("Inorder traversal of the AVL tree: ");
    inorderTraversal(root);

    // Delete the AVL tree
    deleteTree(root);

    return 0;
}
