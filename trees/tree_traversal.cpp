/* Tree traversal DSA implementation in C++ */
#include <iostream>

/* Node class */
class Node
{
    // Private data members
public:
    int m_data;
    Node *left;
    Node *right;
    /* Public constructors */
public:
    // Default constructor
    Node() = default;
    // Parameterized constructor
    Node(int data)
        : m_data(data), left(NULL), right(NULL)
    {
    }

    /* Public member functions */

    // Preorder traversal (Root - > Left subtree - > Right subtree)
    void preorderTraversal(Node *root)
    {
        // Check if the root is null, else traverse recursively
        if (!root)
        {
            return;
        }
        std::cout << "The tree: " << root->m_data << " ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }

    // Inorder traversal (Left subtree - > Root - > Right subtree)
    void inorderTraversal(Node *root)
    {
        // Check if the root is null, else traverse recursively
        if (!root)
        {
            return;
        }
        inorderTraversal(root->left);
        std::cout << "The tree: " << root->m_data << " ";
        inorderTraversal(root->right);
    }

    // Postorder traversal (Left subtree - > Right subtree - > Root)
    void postorderTraversal(Node *root)
    {
        // Check if the root is null, otherwise traverse the tree recursively
        if (!root)
        {
            return;
        }
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        std::cout << "The tree: " << root->m_data << " ";
    }

    // Create a new node
    Node *createNewNode(int data)
    {
        // Dynamic memory allocation on the heap for a new node
        Node *newNode = new Node;
        // Assign values
        newNode->m_data = data;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }

    // Insert a new node to the left subtree
    void insertLeft(Node *root, int data)
    {
        root->left = createNewNode(data);
    }

    // Insert a new node to the right subtree
    void insertRight(Node *root, int data)
    {
        root->right = createNewNode(data);
    }
};

int main()
{
    // Instantiate the Node class
    Node root{};
    Node *newRoot = root.createNewNode(60);
    root.insertLeft(newRoot, 55);
    root.insertRight(newRoot, 22);
    root.insertLeft(newRoot->left, 35);
    root.insertLeft(newRoot->left->left, 66);
    root.insertRight(newRoot->right, 100);
    root.inorderTraversal(newRoot);
    std::cout << std::endl;
    root.preorderTraversal(newRoot);
    std::cout << std::endl;
    root.postorderTraversal(newRoot);
    std::cout << std::endl;
}