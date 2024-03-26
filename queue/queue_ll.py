# Queue DSA in Python using liked lists

# Node class
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

# Queue class


class Queue:
    def __init__(self):
        self.front = None
        self.rear = None

    # Methods

    # Enqueue
    def enqueue(self, data):
        # Create a new node
        new_node = Node(data)
        new_node.next = None
        # Check if the queue is empty
        if (not self.front):
            # Assign the new node to the front and the back of the queue
            self.front = self.rear = new_node
            return
        # Point the rear node to the new node
        self.rear.next = new_node
        # Shift the rear pointer to the new node
        self.rear = new_node

    # Dequeue
    def dequeue(self):
        # Check if the queue is empty, return
        if (not self.front):
            print('The queue is empty!')
            return
        # Shift the front to the next node and free memory allocated for the previous node
        temp = self.front
        self.front = self.front.next
        temp = None
        # If the front is greater than the rear, reset the queue
        if (self.front == None):
            self.rear = None

    # Print the queue
    def print_queue(self):
        # Set a temp variable to traverse the queue (linked list) starting at the head
        temp = self.front
        while (temp):
            print(temp.data, end=' ')
            temp = temp.next
        print()


if __name__ == '__main__':
    # Instantiate the queue class
    q = Queue()
    q.enqueue(5)
    q.enqueue(10)
    q.enqueue(20)
    q.print_queue()
    q.dequeue()
    q.dequeue()
    q.print_queue()
