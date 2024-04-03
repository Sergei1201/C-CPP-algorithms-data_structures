/* Full binary tree is a tree where every parent/internal has two or no children */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Struct node */
struct Node
{
    int data;
    struct Node *left, *right;
};

/* Function prototyping */

// Create a new node
struct Node *createNode(int data);

// Check if the tree is a full binary tree
bool isFullBinaryTree(struct Node *root);

int main()
{
    // Let's assume that the tree is empty to get started with
    struct Node *root = NULL;
    root = createNode(1);
    root->left = createNode(5);
    root->left->left = createNode(20);
    root->left->right = createNode(25);
    root->right = createNode(10);
    root->right->right = createNode(7);
    root->right->left = createNode(99);

    if (isFullBinaryTree(root))
    {
        printf("The binary tree is full\n");
    }
    else
    {
        printf("The binary tree is not full\n");
    }

    return 0;
}

/* Function definition */

struct Node *createNode(int data)
{
    // Dynamic memory allocation on the heap for a new node
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    // Assign values
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

bool isFullBinaryTree(struct Node *root)
{
    // Check if there's no node
    if (!root)
    {
        return true;
    }
    // If the root has no children, our tree is a full binary tree
    if (!root->left && !root->right)
    {
        return true;
    }
    // Check if each internal node has two children
    if (root->left && root->right)
    {
        return (isFullBinaryTree(root->left) && isFullBinaryTree(root->right));
    }
    return false;
}
