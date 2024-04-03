# Full binary tree implementation in Python

# Node class
class Node:
    # Constructor
    def __init__(self, data):
        self.data = data
        self.right = None
        self.left = None


# Check if the binary tree is a full binary tree
def isBinaryTreeFull(root):
    # Check if there's no root, the tree is a full BT
    if (root == None):
        return True
    # Check if the root node or every internal node have no children, we've got a full BT
    if (root.left == None and root.right == None):
        return True
    # Check if the root and every internal node have two children
    if (root.left and root.right):
        return (isBinaryTreeFull(root.left) and isBinaryTreeFull(root.right))
    return False


if __name__ == '__main__':
    # Instantiate the Node class
    root = Node(1)
    root.left = Node(5)
    root.left.left = Node(20)
    root.left.right = Node(25)
    root.right = Node(10)
    root.right.left = Node(90)
    # root.right.right = Node(7)
    if (isBinaryTreeFull(root)):
        print('The binary tree is full')
    else:
        print('The binary tree is not full')
    print()
