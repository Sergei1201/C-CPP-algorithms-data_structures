# Full implementation of a double linked list DSA in Python

# Node class
class Node:
    # Constructor
    def __init__(self, data):
        self.data = data
        self.next = None
        self.prev = None

# Linked list class


class LinkedList:
    # Constructor
    def __init__(self):
        self.head = None

    # Methods
    # Insert first in the list
    def insert_first(self, data):
        # Create a new node
        newNode = Node(data)
        # Point the next link to the head
        newNode.next = self.head
        # Point the previous link to NULL
        newNode.prev = None
        # Check if the head is null, readjust the head with a new node
        if self.head == None:
            self.head = newNode
            newNode.prev = None
        else:
            self.head.prev = newNode
            self.head = newNode

    # Insert after
    def insert_after(self, prev_node, data):
        # Check if the previous node is null
        if not prev_node:
            print('The previous node cannot be null!')
            return
        # Create a new node
        newNode = Node(data)
        # Point the next link of the new node to the next link of the previous node
        newNode.next = prev_node.next
        # Point the previous link of the new node to the previous node
        newNode.prev = prev_node
        # Point the next link of the previous node to the new node to readjust links
        prev_node.next = newNode
        # Check if the new node is not the last one, connect the last node to the new node
        if newNode.next:
            newNode.next.prev = newNode

    # Insert last
    def insert_last(self, data):
        # Create a temp variable to traverse the list
        temp = self.head
        # Create a new node
        newNode = Node(data)
        # Point the next link to null since it's going to be the last node in the list
        newNode.next = None
        # Checkf if there's no head, set the new node to the head and return
        if self.head == None:
            self.head = newNode
            self.head.prev = None
        # Traverse the list till the end and point the last node to the new node, then point the new node to the previous one to readjust the links
        while temp.next:
            temp = temp.next
        temp.next = newNode
        newNode.prev = temp

    # Delete node
    def delete_node(self, del_node):
        # Check if there's no head or no del_node
        if not self.head or not del_node:
            print('There\'s nothing to be deleted')
            return
        # Checkf if the del_node is in the head, shift the head to the next node
        if self.head == del_node:
            self.head = del_node.next
        # Checkf if the del_node is not the last node in the list change the pointers to delete the node and readjust the links
        if del_node.next:
            del_node.next.prev = del_node.prev
        # Check if the del_node is not in the head
        if del_node.prev:
            del_node.prev.next = del_node.next

    # Print the double linked list
    def print_list(self):
        # Traverse the list and on each iteration print values of the nodes
        temp = self.head
        while (temp):
            print(f'Linked list: {temp.data} ', end='')
            temp = temp.next
        print()


if __name__ == '__main__':
    # Instantiate the Linked list class
    ll = LinkedList()
    ll.insert_first(25)
    ll.insert_first(30)
    ll.insert_first(45)
    ll.insert_first(11)
    ll.insert_after(ll.head, 110)
    ll.insert_after(ll.head.next.next, 250)
    ll.insert_last(295)
    ll.insert_last(333)
    ll.insert_first(555)
    ll.delete_node(ll.head.next)
    ll.print_list()
