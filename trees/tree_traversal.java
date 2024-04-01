/* Tree traversal implementation using recursion in Java */

/* Node class */
class Node {
    int m_data;
    Node left, right;
    // Constructor
    public Node(int data) {
        m_data = data;
        left = right = null;
    }
}

/* Tree traversal class */
class TreeTraversal {
    Node root;
    // Constructor 
    TreeTraversal() {
        root = null;
    }

    /* Public methods */

    // Preorder traversal
void preorderTraversal(Node node) {
    // Check if the root is null
    if (node == null) {
        return;
    }
    System.out.print(node.m_data + "->");
    preorderTraversal(node.left);
    preorderTraversal(node.right);
}

// Postorder traversal
void postorderTraversal(Node node) {
    if (node == null) {
        return;
    }
    postorderTraversal(node.left);
    postorderTraversal(node.right);
    System.out.print(node.m_data + "->");
}

// Inorder traversal
void inorderTraversal(Node node) {
    if (node == null) {
        return;
    }
    inorderTraversal(node.left);
    System.out.print(node.m_data + "->");
    inorderTraversal(node.right);
}



public static void main(String[] args) {
    TreeTraversal tree = new TreeTraversal();
    tree.root = new Node(5);
    tree.root.left = new Node(7);
    tree.root.left.right = new Node(20);
    tree.root.left.left = new Node(8);
    tree.root.left.left.left = new Node(10);
    tree.root.left.left.right = new Node(15);
    tree.root.right = new Node(30);
    tree.root.right.left = new Node(50);
    tree.root.right.right = new Node(65);
    tree.root.right.right.left = new Node(100);
    tree.root.right.right.right = new Node(90);
    tree.inorderTraversal(tree.root);
    System.out.println();
    tree.postorderTraversal(tree.root);
    System.out.println();
    tree.preorderTraversal(tree.root);
    System.out.println();
}
}