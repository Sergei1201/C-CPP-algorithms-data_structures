# Full implementation of a reversed linked list data structure in the Python programming language

# Node class
class Node:
    # Constructor
    def __init__(self, data):
        self.data = data
        self.next = None

# Linked list class


class LinkedList:
    # Constructor
    def __init__(self):
        self.head = None

    # Methods

    # Push a new node to the linked list
    def push_node(self, data):
        # Create a new node
        new_node = Node(data)
        # Assign values
        new_node.next = self.head
        # Change the head to the new node
        self.head = new_node

    # Reverse linked list
    def reverse_list(self):
        # Create some pointers to traverse the linked list
        current = self.head
        next = None
        prev = None
        # Traverse the linked list, reverse pointers on each iteration and finally shift the head to the last node of the linked list
        while (current):
            next = current.next
            current.next = prev
            prev = current
            current = next
        self.head = prev

    # Print linked list
    def print_list(self):
        # Set a temporary variable to traverse the linked list and print values of all nodes on each iteration starting from the head
        temp = self.head
        while (temp):
            print(f'Linked list {temp.data} ', end='')
            temp = temp.next
        print()


if __name__ == '__main__':
    # Instantiate the linked list class
    ll = LinkedList()
    ll.push_node(50)
    ll.push_node(60)
    ll.push_node(70)
    ll.push_node(80)
    ll.push_node(90)
    ll.print_list()
    ll.reverse_list()
    ll.print_list()
