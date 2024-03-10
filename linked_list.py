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

    # Insert at the beginning of the linked list
    def insert_first(self, data):
        # Create a new node
        new_node = Node(data)

        # Point the newly created node to the head
        new_node.next = self.head

        # Point the head to the newly created node
        self.head = new_node

    # Insert after a certain node in the linked list
    def insert_after(self, prev_node, data):

        # Check if the previous node is equal to null
        if prev_node == None:
            print("The previous node cannot be null")
            return

        # Create a new node
        new_node = Node(data)

        # Point the newly created node to the next node after the previous node
        new_node.next = prev_node.next

        # Point the previous node to the newly created node
        prev_node.next = new_node

    # Insert at the end of the linked list
    def insert_last(self, data):

        # Create a new node
        new_node = Node(data)

        # Check if there's no head, point the inserted element to the head and return
        if self.head == None:
            self.head = new_node
            return

        # Create a temp variable to traverse the linked list
        temp = self.head
        while (temp.next):
            temp = temp.next
        temp.next = new_node

   # Delete an element from the linked list at a certain position
    def delete_node(self, position):

        # Check if the node is empty
        if (self.head == None):
            return

        # Initialize temp variable to traverse the linked list
        temp = self.head

        # Check if the head is marked for deleting, move the head to the next node
        if position == 0:
            self.head = temp.next
            return

        # Traverse the linked list
        for i in range(position - 1):
            temp = temp.next
            if temp == None:
                return

        # Check if there's no match
        if temp == None:
            return
        if temp.next == None:
            return

        # Delete an element from the list
        next = temp.next.next
        temp.next = None
        temp.next = next

    # Print linked list

    def print_list(self):
        # Initialize temp variable that points to the next to traverse the linked list
        temp = self.head
        while (temp):
            print(f'Linked list: {temp.data} ', end='')
            temp = temp.next
        print()


if __name__ == '__main__':

    # Create an empty linked list
    ll = LinkedList()

    ll.insert_first(50)
    ll.insert_first(60)
    ll.insert_first(70)
    ll.insert_after(ll.head.next, 150)
    ll.insert_last(250)
    ll.delete_node(2)
    ll.delete_node(1)
    ll.print_list()

    for i in range(2-1):
        print(i)
