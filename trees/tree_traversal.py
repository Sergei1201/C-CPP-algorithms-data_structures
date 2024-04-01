# Tree traversal algorithm in Python using recursino

# Node class
class Node:
    # Constructor
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

    # Methods

    # Inorder traversal
    def inorder_traversal(self, root):
        # Check if the root is None
        if root == None:
            return
        # Otherwise implement the inorder traversal algorithm recursively
        self.inorder_traversal(root.left)
        print(f'The tree is: {root.data}', end=' ')
        self.inorder_traversal(root.right)

    # Preorder traversal
    def preorder_traversal(self, root):
        # Check if the root is None
        if root == None:
            return
        # Otherwise implement the preorder traversal algorithm recursively
        print(f'The tree is: {root.data}', end=' ')
        self.preorder_traversal(root.left)
        self.preorder_traversal(root.right)

    # Postorder traversal
    def postorder_traversal(self, root):
        # Check if the root is None
        if root == None:
            return
        # Otherwise implement the postorder algorithm recursively
        self.postorder_traversal(root.left)
        self.postorder_traversal(root.right)
        print(f'The tree is: {root.data}', end=' ')


if __name__ == '__main__':
    # Instantiate the node class by creating objects (nodes)
    node = Node(5)
    node.left = Node(7)
    node.left.right = Node(20)
    node.left.left = Node(8)
    node.left.left.right = Node(15)
    node.left.left.left = Node(10)
    node.left.left.right = Node(15)
    node.right = Node(30)
    node.right.left = Node(50)
    node.right.right = Node(65)
    node.right.right.left = Node(100)
    node.right.right.right = Node(90)
    node.inorder_traversal(node)
    print()
    node.preorder_traversal(node)
    print()
    node.postorder_traversal(node)
    print()
