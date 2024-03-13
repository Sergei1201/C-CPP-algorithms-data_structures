# Full implementation of the linked list algorithm in the Python programming language

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

    # Insert a node at the beginning of the linked list
    def insert_first(self, data):
        # Create a new node to be inserted first
        new_node = Node(data)
        # Point the new node to the head
        new_node.next = self.head
        # Change the pointer of the new node to the head to adjust links
        self.head = new_node

    # Insert after a certain node in the linked list
    def insert_after(self, prev_node, data):
        # Check if the previous node is equal to None
        if not prev_node:
            print('The previous node cannot be null')
            return
        # Create a new node to be inserted after the previous one
        new_node = Node(data)
        # Point the new node to the next node after the previous one
        new_node.next = prev_node.next
        # Point the previous node to the new node to change links
        prev_node.next = new_node

    # Insert the last node in the linked list
    def insert_last(self, data):
        # Create a new node to be inserted last
        new_node = Node(data)
        # Check if there's no head in the linked list, point the new node to the head and return
        if not self.head:
            self.head = new_node
            return
        # Traverse the linked list until the last node points to None, point the last node to the new node
        temp = self.head
        while (temp.next):
            temp = temp.next
        temp.next = new_node

    # Delete a node
    def delete_node(self, position):
        # Check if there's no head
        if not self.head:
            return
        # Check if the deleted node is in the head on the linked list, move the head pointer to the next node, thus deleting it from the liked list
        temp = self.head
        if position == 0:
            self.head = temp.next
            temp = None
        # Find the key to be deleted from the linked list
        for i in range(position - 1):
            temp = temp.next
            if temp == None:
                return

        # Check if the key is not present in the linked list
        if not temp:
            return
        if not temp.next:
            return
        # Delete a node
        next = temp.next.next
        temp.next = None
        temp.next = next

  # Search for a node in the linked list
    def search_node(self, key):
        # Set the current node to the head to get started with
        current = self.head
        # Traverse the linked list till the end and compare data on each iteration to the key that's passed in as an argument to the method
        while (current):
            if current.data == key:
                return True
            current = current.next
        return False

    # Sort linked list
    def sort_list(self):
        # Set the current node to the head to get started with
        current = self.head
        # Set the index that points to the next node to null at the beginning
        index = None
        # Check if there's no head in the linked list
        if not self.head:
            return
        # Traverse the linked list and on each iteration compare the value of the current node to the value of the next node
        # If the current value is greater than the next one, swap the two adjacent nodes
        while (current):
            index = current.next
            while (index):
                if current.data > index.data:
                    current.data, index.data = index.data, current.data
                index = index.next
            current = current.next

    # Print the linked list
    def print_list(self):
        # Traverse the linked list till the end and print values on each iteration
        temp = self.head
        while (temp):
            print(f'Linked list: {temp.data} ', end='')
            temp = temp.next
        print()


if __name__ == '__main__':
    # Instantiate the linked list class => create an object
    ll = LinkedList()
    ll.insert_first(10)
    ll.insert_first(20)
    ll.insert_first(50)
    ll.insert_after(ll.head.next, 120)
    ll.insert_after(ll.head.next.next, 160)
    ll.insert_last(209)
    ll.insert_first(306)
    ll.delete_node(5)
    searched_node = 305
    if ll.search_node(searched_node):
        print(f'The node with value {searched_node} has been found')
        print()
    else:
        print(f'The node with the value {searched_node} has not been found')
        print()
    ll.print_list()
    ll.sort_list()
    ll.print_list()
