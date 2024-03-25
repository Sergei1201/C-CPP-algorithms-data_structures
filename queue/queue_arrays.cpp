/* Queue DSA using arrays in C++ with OOP */
#include <iostream>

/* Queue class */
class Queue
{
    /* Public data members, member functions, and the default constructor */
public:
    // Setting front and back of the queue to -1, thus making it an empty queue at the beginning
    Queue()
        : front(-1), rear(-1)
    {
    }
    // The maximum size of the queue
    static const int SIZE = 5;

    // Check if the queue is empty
    bool isEmpty()
    {
        // If the rear and front indices equal to -1, then the queue is empty
        if (rear == -1 && front == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // Check if the queue is full
    bool isFull()
    {
        // If the front index is equal to 0 and the rear index is equal to SIZE - 1 of the array, then the queue is full
        if (front == 0 && rear == SIZE - 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // Enqueue
    void enqueue(int data)
    {
        // Check if the queue is full
        if (isFull())
        {
            std::cout << "The queue is full!" << std::endl;
            return;
        }
        else
        {
            // Push a new element at the back of the queue
            rear++;
            front = 0;
            queue[rear] = data;
        }
    }

    // Dequeue
    int dequeue()
    {
        // Declare a variable to store the popped element of the queue
        int element;
        // Check if the queue is empty
        if (isEmpty())
        {
            std::cout << "The queue is empty" << std::endl;
            return (-1);
        }
        else
        {
            // Pop out the first element of the queue
            element = queue[front];
            // Increment the index of the current element
            front++;
        }
        // If the front index is greater than the rear index, this means we've reached the end of the queue - just reset the queue to its initial state
        if (front > rear)
        {
            front = rear = -1;
        }
        // Return the popped element
        return element;
    }

    // Print the queue
    void printQueue()
    {
        std::cout << "The queue: ";
        for (int i = front; i <= rear; i++)
        {
            std::cout << queue[i] << " ";
        }
        std::cout << std::endl;
    }
    /* Private data members */
private:
    int front;
    int rear;
    int queue[SIZE];
};

int main()
{
    // Instantiate the Queue class by creating an object
    Queue q;
    q.enqueue(5);
    q.enqueue(10);
    q.enqueue(25);
    q.enqueue(35);
    q.enqueue(50);
    q.printQueue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.printQueue();
    return 0;
}