# Full implementation of the reversed linked list DSA with recursion in Python

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
        # Set the next pointer to the head
        new_node.next = self.head
        # Shift the head to the new node
        self.head = new_node

    # Reverse the linked list using recursion
    def reverse_list(self, head):
        # Check if there's no head, then we've reached the end of the list, return the last node
        if (head is None or head.next is None):
            return head
        # Divide the linked list in two parts: the first node and the rest of the list
        # Reverse the rest of the list, then put the first element at the end
        rest = self.reverse_list(head.next)
        head.next.next = head
        head.next = None  # Repeat this process recursively for the whole linked list
        # Fix the head to the rest
        return rest

    # Print the linked list
    def print_list(self):
        # Traverse the list till the end and print values of nodes on each iteration starting from the head
        temp = self.head
        while (temp):
            print(f'Linked list: {temp.data} ', end='')
            temp = temp.next
        print()


if __name__ == '__main__':
    # Instantiate the linkes list class creating a new object
    ll = LinkedList()
    ll.push_node(1)
    ll.push_node(2)
    ll.push_node(5)
    ll.push_node(6)
    ll.push_node(11)
    ll.print_list()
    ll.head = ll.reverse_list(ll.head)
    ll.print_list()
