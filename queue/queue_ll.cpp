/* Queue DSA implementation using linked lists in C++ witn OOP */
#include <iostream>

/* Node struct */
struct Node
{
public:
    /* Data members */
    int data;
    Node *next;

    /* Default constructor */
    Node()
        : data(), next(NULL)
    {
    }
};

/* Queue class */
class Queue
{
    /* Data members */
private:
    Node *front, *rear;
    /* Default constructor - empty queue */
public:
    Queue()
        : front(NULL), rear(NULL)
    {
    }
    /* Public member functions */

    // Create a new node
    Node *createNewNode(int data)
    {
        // Dynamic memory allocation on the heap for a new node
        Node *newNode = new Node();
        // Assign values
        newNode->data = data;
        // Point the next pointer to null since we're going to be push a new node at the back of the queue
        newNode->next = NULL;
        return newNode;
    }

    // Enqueue
    void enqueue(int data)
    {
        // Create a new node for the queue
        Node *newNode = createNewNode(data);
        // Check if the queue is empty
        if (!front)
        {
            front = rear = newNode;
            return;
        }
        // Point the last node to the new node
        rear->next = newNode;
        // Shift the rear pointer to the new node
        rear = newNode;
    }

    // Dequeue
    void dequeue()
    {
        // Check if the queue is empty
        if (!front)
        {
            std::cout << "The queue is empty!";
            return;
        }
        // Assign a temp variable to the front of the queue
        Node *temp = front;
        // Shift the front pointer to the next node
        front = front->next;
        // If front is greater than rear, reset the queue
        if (front > rear)
        {
            front = rear = NULL;
        }
        // Deallocate memory for the temp variable to pop out the first node
        delete temp;
    }

    // Print queue
    void printQueue()
    {
        // Traverse the queue from the start and print the value of each node on each iteration
        Node *temp = front;
        while (temp)
        {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

int main()
{
    // Instantiate the queue class (create an empty queue)
    Queue q;
    q.enqueue(5);
    q.enqueue(10);
    q.enqueue(25);
    q.printQueue();
    q.dequeue();
    q.dequeue();
    q.printQueue();

    return 0;
}