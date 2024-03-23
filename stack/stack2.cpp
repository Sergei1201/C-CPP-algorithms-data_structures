/* Stack implementation using linked lists in C++ with OOP principles */
#include <iostream>

/* Node class */
class Node
{
    /* Private data members */
public:
    int data;
    Node *next;
    /* Default public constructor */
public:
    Node()
        : data(), next(NULL)
    {
    }
};

/* Linked list class */
class LinkedList
{
    /* Private data members */
private:
    Node *head;
    /* Public constructor and member functions */
public:
    LinkedList()
        : head(NULL)
    {
    }

    // Push a new element onto the stack
    void pushElement(int data)
    {
        // Dynamic memory allocation on the heap for a new node
        Node *newNode = new Node();
        newNode->data = data;
        newNode->next = head;
        head = newNode;
    }

    // Pop the top element from the stack
    void popElement()
    {
        // Check if the stack is empty, there's nothing to pop
        if (!head)
        {
            std::cout << "The stack is empty!" << std::endl;
            return;
        }
        // Create a temp variable to store the top node
        Node *temp = head;
        // Shift the head to the next node and deallocate memory for the popped node
        head = temp->next;
        delete temp;
    }

    // Print the stack
    void printStack()
    {
        // Traverse the linked list (our stack) and print values of every node on each iteration
        Node *temp = head;
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
    // Instantiate the linked list class
    LinkedList ll;
    ll.pushElement(5);
    ll.pushElement(6);
    ll.pushElement(10);
    ll.pushElement(65);
    ll.pushElement(66);
    ll.printStack();
    ll.popElement();
    ll.popElement();
    ll.popElement();
    ll.popElement();
    ll.popElement();
    ll.popElement();
    ll.printStack();
}