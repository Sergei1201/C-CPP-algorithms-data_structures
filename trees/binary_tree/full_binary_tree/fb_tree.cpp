/* Full binary tree implementation in C++ */
// A full binary tree is a data structure (binary tree) where each internal node has two or no children
#include <iostream>

/* Node class */
class Node
{
public:
    int m_data;
    Node *right, *left;

    /* Constructor */

    // Default constructror
    Node() = default;
    // Parameterized constructror
    Node(int data)
        : m_data(data), right(NULL), left(NULL)
    {
    }
    /* Public member function */

    // Check if the tree is a full binary tree
    bool isFullBinaryTree(Node *root)
    {
        // Check if the root is null
        if (!root)
        {
            return true;
        }
        // Check the root or internal nodes do not children at the same time
        if (!root->left && !root->right)
        {
            return true;
        }
        // Check if the root or internal
        if (root->left && root->right)
        {
            return (isFullBinaryTree(root->left) && isFullBinaryTree(root->right));
        }
        return false;
    }
};

int main()
{
    // Dynamically allocate memory on the heap for a new node
    Node *root = new Node(1);
    root->left = new Node(5);
    root->left->left = new Node(20);
    root->left->right = new Node(25);
    root->right = new Node(10);
    root->right->right = new Node(7);
    // root->right->left = new Node(90);
    if (root->isFullBinaryTree(root))
    {
        std::cout << "The binary tree is full\n";
    }
    else
    {
        std::cout << "The binary tree is not full\n";
    }
    // Deallocate memory for objects
    delete root;
}