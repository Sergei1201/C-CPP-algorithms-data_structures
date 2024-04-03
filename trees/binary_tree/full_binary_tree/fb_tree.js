/* Full binary tree implemeentation in JavaScript */

/* Node class */
class Node {
    // Let's construct a new node
    constructor(data) {
        this.data = data
        this.left = null
        this.right = null
    }
    /* Public methods */

    // Check if the tree is full BT
    isTreeFull(root) {
        // Check if the root is empty, then our tree is indeed a full binary tree
        if (!root) {
            return true
        }
        // Check if the root and all internal nodes have no children, then the tree is a full BT
        if (!root.left && !root.right) {
            return true
        }
        // Check if the root and all internal nodes have exactly two children, then the tree is a full BT
        if (root.left && root.right) {
            return (this.isTreeFull(root.left) && this.isTreeFull(root.right))
        }
        return false
    }

}
// Instantiate the Node class, create objects - nodes
root = new Node(1)
root.left = new Node(5)
root.left.right = new Node(25)
root.left.left = new Node (20)
root.right = new Node(10)
root.right.left = new Node(90)
//root.right.right = new Node(7)
if (root.isTreeFull(root)) {
    console.log('The tree is full')
} else {
    console.log('The tree is not full')
}