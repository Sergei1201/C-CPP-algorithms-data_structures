#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Node struct */
struct Node
{
    int data;
    struct Node *left, *right;
};

/* Function prototyping */

// Create a new node for our tree
struct Node *createNewNode(int data);

// Check if the binary tree is full
bool isBinaryTreeFull(struct Node *root);

int main()
{
    // Let's assume that our tree is empty to get started with
    struct Node *root = NULL;
    root = createNewNode(1);
    root->left = createNewNode(5);
    root->left->left = createNewNode(20);
    root->left->right = createNewNode(25);
    root->right = createNewNode(10);
    root->right->left = createNewNode(30);
    // root->right->right = createNewNode(7);
    if (isBinaryTreeFull(root))
    {
        printf("The binary tree is full\n");
    }
    else
    {
        printf("The binary tree is not full\n");
    }

    /*
                1

            5       10

        20    25  30     7

    */

    return 0;
}

/* Function definition */

struct Node *createNewNode(int data)
{
    // Dynamically allocate memory on the heap for a new node
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    // Assign values
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

bool isBinaryTreeFull(struct Node *root)
{
    // Check if there's no root
    if (!root)
    {
        return true;
    }
    // Check if the root has not children
    if (!root->left && !root->right)
    {
        return true;
    }
    // Check if our root has two children and all internal nodes have two children
    if (root->left && root->right)
    {
        return (isBinaryTreeFull(root->left) && isBinaryTreeFull(root->right));
    }
    return false;
}