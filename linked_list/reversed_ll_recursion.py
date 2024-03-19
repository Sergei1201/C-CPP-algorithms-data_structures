# Full implementation of the reversed linked list DSA in Python using recursion

# Node class
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

# Linked list class


class LinkedList:
    def __init__(self):
        self.head = None

    # Public methods

    # Push a new node to the linked list
    def push_node(self, data):
        # Create a new node
        new_node = Node(data)
        # Point the next to the head
        new_node.next = self.head
        # Point the head to the new node
        self.head = new_node

    # Reverse linked list
    def reverse_list(self, head):
        # Check if there's no head or next node
        if (head is None or head.next is None):
            return head
        # Divide the linked list in two parts: the first node and the rest of the list, then recursively reverse the rest of the list for the rest
        rest = self.reverse_list(head.next)
        # Put the first element at the end
        head.next.next = head
        head.next = None
        # Fix the head pointer
        return rest

    # Print linked list
    def print_list(self):
        # Traverse the linked list from the head and print values of every node on each iteration
        temp = self.head
        while (temp):
            print(f'Linked list: {temp.data} ', end='')
            temp = temp.next
        print()


if __name__ == '__main__':
    # Instantiate the ll class and make a new object of that class
    ll = LinkedList()
    ll.push_node(2)
    ll.push_node(5)
    ll.push_node(11)
    ll.print_list()
    ll.head = ll.reverse_list(ll.head)
    ll.print_list()
