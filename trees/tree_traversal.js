/* Tree traversal algorithms using recursion in JavaScript */

/* Node class */
class Node {
    // Constructor
    constructor(data) {
        this.data = data
        this.left = null
        this.right = null
    }
    /* Methods */

    // Inorder traversal algorithm
    inorderTraversal(root) {
        // Check if there's no root, simply return
        if (!root) {
            return
        }
        // Otherwise, implement the inorder traversal algorithm using recursion
        this.inorderTraversal(root.left)
        console.log(`The tree is: ${root.data}`)
        this.inorderTraversal(root.right)
    }

    // Preorder traversal algorithm
    preorderTraversal(root) {
        // Check if there's no root, simply return
        if (!root) {
            return
        }
        // Otherwise, implement the preorder traversal algorithm using recursion
        console.log(`The tree is: ${root.data}`)
        this.preorderTraversal(root.left)
        this.preorderTraversal(root.right)
    }
    // Postorder traversal algorithm
    postorderTraversal(root) {
        // Check if there's no root, simply return
        if (!root) {
            return
        }
        // Otherwise, implement the postorder traversal algorithm using recursion
        this.postorderTraversal(root.left)
        this.postorderTraversal(root.right)
        console.log(`The tree is: ${root.data}`)

    }
}

// Instantiate the node class by creating a few instances
root = new Node(5)
root.left = new Node(7)
root.left.right = new Node(20)
root.left.left = new Node(8)
root.left.left.right = new Node(15)
root.left.left.left = new Node(10)
root.right = new Node(30)
root.right.left = new Node(50)
root.right.right = new Node(65)
root.right.right.left = new Node(100)
root.right.right.right = new Node(90)
root.inorderTraversal(root)
root.preorderTraversal(root)
root.postorderTraversal(root)
