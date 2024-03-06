# Node class
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

# Linked list class


class Linked_List:
    def __init__(self):
        self.head = None

    # Insert first
    def insert_first(self, new_data):
        new_node = Node(new_data)
        new_node.next = self.head
        self.head = new_node

    # Print list
    def print_list(self):
        temp = self.head
        while (temp):
            print(f'Linked list: {temp.data} ')
            temp = temp.next


if __name__ == '__main__':
    # Initialize empty list
    linked_list = Linked_List()

    # Assign values

    linked_list.insert_first(10)
    linked_list.insert_first(20)
    linked_list.insert_first(30)
    linked_list.insert_first(40)

   # Print list
    linked_list.print_list()
