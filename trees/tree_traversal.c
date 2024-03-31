/* Tree traversal DSA using recursion in C */
#include <stdio.h>
#include <stdlib.h>

/* Node struct with two pointers */
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

/* Function forward declaration & prototyping */

// Inorder traversal (1. Visit the left subtee. 2. Visit the root 3. Visit the right subtree)
void inorderTraversal(struct Node *root);

// Preorder traversal (The root - > The left subtree - > The right subtree
void preorderTraversal(struct Node *root);

// Postorder traversal (The left subtree - > The right subtree - > The root)
void postorderTraversal(struct Node *root);

// Separate function to create a new node
struct Node *createNewNode(int data);

// Insert a node to the left
struct Node *insertLeft(struct Node *root, int data);

// Insert a node to the right 
struct Node *insertRight(struct Node *root, int data);


int main() {
    // Create a new node
    struct Node *root = createNewNode(100);
    insertLeft(root, 10);
    insertLeft(root->left, 20);
    insertLeft(root->left->left, 30);
    insertRight(root->left->left, 19);
    insertRight(root, 35);
    insertRight(root->right, 55);
    insertLeft(root->right, 65);
    inorderTraversal(root);
    printf("\n");
    preorderTraversal(root);
    printf("\n");
    postorderTraversal(root);
    printf("\n");

    return 0;
}

/* Function definition */

void inorderTraversal(struct Node *root) {
    // Check if the root is null
    if (!root) {
        return;
    }
    inorderTraversal(root->left);
    printf("The node -> %d ", root->data);
    inorderTraversal(root->right);
}

void preorderTraversal(struct Node *root) {
    // Check if the root is null (the tree is empty)
    if (!root) {
        return;
    }
    printf("The node -> %d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(struct Node *root) {
    // Check if the root is null
    if (!root) {
        return;
    }
    postorderTraversal(root->left);
    preorderTraversal(root->right);
    printf("The node -> %d ", root->data);
}

struct Node *createNewNode(int data) {
    // Dynamic memory allocation on the heap for a new node
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    // Assign values
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node *insertLeft(struct Node *root, int data) {
   root->left = createNewNode(data);
   return root->left;
}

struct Node *insertRight(struct Node *root, int data) {
   root->right = createNewNode(data);
   return root->right;
}