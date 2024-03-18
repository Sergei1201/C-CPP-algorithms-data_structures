# Full implementation of the reversed linked list data structure using iteration in the Python programming language

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

    # Push a new node to the linked list (at the beginning of the linked list)
    def push_node(self, data):
        # Create a new node
        new_node = Node(data)
        # Change the next pointer of the new node to the head pointer
        new_node.next = self.head
        # Shift the head pointer to the new node thus making it the head node
        self.head = new_node

    # Reverse the linked list
    def reverse_list(self):
        # Consider the case where there's no head or no next node. In this case there's nothing to reverse, just return and that's it
        if (not self.head or not self.head.next):
            return
        # Create some pointers to traverse the linked list
        current = self.head
        next = None
        prev = None
        # Traverse the linked list changing its pointers to the opposite direction using iteration
        while (current):
            next = current.next
            current.next = prev
            prev = current
            current = next
        # Shift the head pointer to the last node (prev)
        self.head = prev

    # Print the linked list
    def print_list(self):
        # Assign a temp variable to the head to start traversing the linked list
        temp = self.head
        # Start traversing the linked list printing values of every node on each iteration
        while (temp):
            print(f'Linked list: {temp.data} ', end='')
            temp = temp.next
        print()


if __name__ == '__main__':
    # Instantiate the linked list class
    ll = LinkedList()
    # Push new nodes to the linked list
    ll.push_node(35)
    ll.push_node(45)
    ll.push_node(50)
    ll.push_node(65)
    ll.push_node(70)
    # Print the linked list after inserting nodes in it
    ll.print_list()
    # Reverse the linked list
    ll.reverse_list()
    # Print the linked list after reversing
    ll.print_list()
