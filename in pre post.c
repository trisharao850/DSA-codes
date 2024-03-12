#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Function to generate random numbers in a given range
int generateRandomNumber(int min, int max) {
    return min + rand() % (max - min + 1);
}

// Function to insert a new node into a BST
Node* insert(Node* root, int data) {
    if (root == NULL) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }

    return root;
}

// Function to perform inorder traversal of a BST and store the output in a file
void inorderTraversalToFile(Node* root, FILE* fp) {
    if (root != NULL) {
        inorderTraversalToFile(root->left, fp);
        fprintf(fp, "%d\n", root->data);
        inorderTraversalToFile(root->right, fp);
    }
}

// Function to perform preorder traversal of a BST and store the output in a file
void preorderTraversalToFile(Node* root, FILE* fp) {
    if (root != NULL) {
        fprintf(fp, "%d\n", root->data);
        preorderTraversalToFile(root->left, fp);
        preorderTraversalToFile(root->right, fp);
    }
}

// Function to perform postorder traversal of a BST and store the output in a file
void postorderTraversalToFile(Node* root, FILE* fp) {
    if (root != NULL) {
        postorderTraversalToFile(root->left, fp);
        postorderTraversalToFile(root->right, fp);
        fprintf(fp, "%d\n", root->data);
    }
}

int main() {
    // Seed the random number generator with current time
    srand(time(0));

    int min, max, num;
    printf("Enter the minimum value: ");
    scanf("%d", &min);
    printf("Enter the maximum value: ");
    scanf("%d", &max);
    printf("Enter the number of random numbers to generate: ");
    scanf("%d", &num);

    // Create a file pointer for random numbers
    FILE* fpRandom;

    // Open a file in write mode for random numbers
    fpRandom = fopen("random_numbers.txt", "w");

    if (fpRandom == NULL) {
        printf("Error opening file for random numbers!");
        return 1;
    }

    // Generate random numbers and write them to the file
    int i;
    for (i = 0; i < num; i++) {
        int randomNum = generateRandomNumber(min, max);
        fprintf(fpRandom, "%d\n", randomNum);
    }

    printf("%d random numbers generated and saved to file 'random_numbers.txt'\n", num);

    // Close the file for random numbers
    fclose(fpRandom);

    // Create an empty BST
    Node* root = NULL;

    // Open file pointers for BST traversals
    FILE* fpInorder;
    FILE* fpPreorder;
    FILE* fpPostorder;

    // Open files in write mode for BST traversals
    fpInorder = fopen("bst_inorder_traversal.txt", "w");
    fpPreorder = fopen("bst_preorder_traversal.txt", "w");
    fpPostorder = fopen("bst_postorder_traversal.txt", "w");

    if (fpInorder == NULL || fpPreorder == NULL || fpPostorder == NULL) {
        printf("Error opening files for BST traversals!");
        return 1;
    }

    // Read random numbers from the file and insert them into the BST
    fpRandom = fopen("random_numbers.txt", "r");

    if (fpRandom == NULL) {
        printf("Error opening file 'random_numbers.txt'!");
        return 1;
    }

    int number;
    while (fscanf(fpRandom, "%d", &number) != EOF) {
        root = insert(root, number);
    }

    // Close the file for random numbers
    fclose(fpRandom);

    // Perform inorder traversal of the BST and store the output in a file
    inorderTraversalToFile(root, fpInorder);

    // Perform preorder traversal of the BST and store the output in a file
    preorderTraversalToFile(root, fpPreorder);

    // Perform postorder traversal of the BST and store the output in a file
    postorderTraversalToFile(root, fpPostorder);

    // Close the files for BST traversals
    fclose(fpInorder);
    fclose(fpPreorder);
    fclose(fpPostorder);

    printf("Inorder, preorder, and postorder traversals of the BST saved to files.\n");

    return 0;
}
