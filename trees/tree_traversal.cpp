/* Tree traversal DSA implementation in C++ using recursion */
#include <iostream>
/* Node class */
class Node
{
public:
    int m_data;
    Node *left, *right;
    // Constructor
    Node(int data)
        : m_data(data), left(NULL), right(NULL)
    {
    }
    /* Public member functions */

    // Inorder traversal of the tree
    void inorderTraversal(Node *root)
    {
        // Check if the root is null
        if (!root)
        {
            return;
        }
        // otherwise implement recursion to traverse the tree inorder
        // Traverse the left subtree recursively
        inorderTraversal(root->left);
        // Visit the root node
        std::cout << "The tree: " << root->m_data << " ";
        inorderTraversal(root->right);
    }

    // Preorder traversal of the tree
    void preorderTraversal(Node *root)
    {
        // Check if the root is null
        if (!root)
        {
            return;
        }
        // otherwise implement recursion to traverse the tree preorderly
        // Visit the root node
        std::cout << "The tree: " << root->m_data << " ";
        // Walk the left subtree recursively
        preorderTraversal(root->left);
        // Walk the right subtree recursively
        preorderTraversal(root->right);
    }

    // Postorder traversal of the tree
    void postorderTraversal(Node *root)
    {
        // Check if the root is null
        if (!root)
        {
            return;
        }
        // otherwise implement recursion to traverse the tree postorderly
        // Walk the left subtree recursively
        postorderTraversal(root->left);
        // Walk the right subtree recursively
        postorderTraversal(root->right);
        // Visit the root node
        std::cout << "The tree: " << root->m_data << " ";
    }
};

int main()
{
    // Dynamically allocate memory on the heap for new nodes of our tree
    Node *root = new Node(5);
    root->left = new Node(7);
    root->left->left = new Node(8);
    root->left->right = new Node(20);
    root->left->left->left = new Node(10);
    root->left->left->right = new Node(15);
    root->right = new Node(30);
    root->right->left = new Node(50);
    root->right->right = new Node(65);
    root->right->right->left = new Node(100);
    root->right->right->right = new Node(90);
    root->inorderTraversal(root);
    std::cout << std::endl;
    root->preorderTraversal(root);
    std::cout << std::endl;
    root->postorderTraversal(root);
    std::cout << std::endl;
    // Deallocate the memory on the heap after using it
    delete root;
}