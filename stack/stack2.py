# Stack DSA using linked lists in Python

# Node class
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

# Linked list class


class LinkedList:
    def __init__(self):
        self.head = None

    # Methods

    # Push a new element onto the stack
    def push_element(self, data):
        # Create a new node
        newNode = Node(data)
        newNode.next = self.head
        self.head = newNode

    # Pop the top element from the stack
    def pop_element(self):
        # Check if the stack is empty, there's nothing to pop
        if (not self.head):
            print('The stack is empty!')
            return
        # otherwise shift the head to the next node
        temp = self.head
        self.head = temp.next
        temp = None

    # Print the stack
    def print_stack(self):
        # Traverse the linked list starting at the head
        temp = self.head
        while (temp):
            print(f'{temp.data} ', end='')
            temp = temp.next
        print()


if __name__ == '__main__':
    # Instantiate the linked list class
    ll = LinkedList()
    ll.push_element(5)
    ll.push_element(55)
    ll.push_element(65)
    ll.push_element(75)
    ll.push_element(87)
    ll.print_stack()
    ll.pop_element()
    ll.pop_element()
    ll.pop_element()
    ll.pop_element()
    ll.pop_element()
    ll.pop_element()
    ll.print_stack()
