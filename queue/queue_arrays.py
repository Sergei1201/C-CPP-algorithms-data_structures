# Queue implementation in Python using arrays

# Queue class
class Queue:
    # Default constructor
    def __init__(self):
        self.queue = []

    # Methods

    # Check if the queue is empty
    def is_empty(self):
        if len(self.queue) == 0:
            return True
        else:
            return False

    # Enqueue
    def enqueue(self, data):
        return self.queue.append(data)

    # Dequeue
    def dequeue(self):
        # Check if the queue is empty
        if (self.is_empty()):
            print('The queue is empty!')
            return
        return self.queue.pop(0)

    # Print the queue
    def print_queue(self):
        for i in range(len(self.queue)):
            print(self.queue[i], end=' ')
        print()


if __name__ == '__main__':
    # Instantiate the Queue class
    q = Queue()
    q.enqueue(5)
    q.enqueue(10)
    q.enqueue(20)
    q.print_queue()
    q.dequeue()
    q.dequeue()
    q.dequeue()
    q.dequeue()
    q.print_queue()
