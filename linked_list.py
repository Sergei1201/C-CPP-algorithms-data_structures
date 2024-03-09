# Node class
class Node:
    # Constructor
    def __init__(self, data):
        self.data = data
        self.next = None

# Linked list class


class Linked_List:
    # Constructor
    def __init__(self):
        self.head = None

    # Insert an element at the beginning of the list
    def insert_first(self, new_data):
        # Create a new node with data tha's passed in as an agrument
        new_node = Node(new_data)
        new_node.next = self.head
        self.head = new_node

    # Print list
    def print_list(self):
        temp = self.head
        while (temp):
            print(f'The linked list: {temp.data} ')

            temp = temp.next


if __name__ == '__main__':
    # Instantiate linked list class
    linked_list = Linked_List()

    # Insert elements
    linked_list.insert_first(5)
    linked_list.insert_first(10)
    linked_list.insert_first(20)
    linked_list.insert_first(30)

    # Print list
    linked_list.print_list()
