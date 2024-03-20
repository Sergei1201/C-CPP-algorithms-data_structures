/* Stack implementation with arrays in C++ using OOP principals */
#include <iostream>

/* Stack class */
class Stack
{
public:
    // Static data members
    static const int MAX = 5;
    static int count;

    // Default constructor
    Stack()
        : top(-1)
    {
    }
    /* Public member functions */

    // Check if the stack is empty
    bool isEmpty()
    {
        // If top is equal to -1, the stack is empty
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // Check if the stack is full
    bool isFull()
    {
        // If the top is equal to MAX - 1, the stack is full
        if (top == MAX - 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // Push a new element onto the stack
    void pushElement(int element)
    {
        // Check if the stack is full before pushing a new element to it
        if (isFull())
        {
            std::cout << "The stack is full" << std::endl;
            return;
        }
        else
        {
            // Increase the index of the array by 1 and assign the values at that index to the data that's passed in. This is going to be the top of the stack
            top++;
            items[top] = element;
        }
        // Increment the number of elements in the stack by 1
        count++;
    }

    // Pop an element from the top of the stack
    void popElement()
    {
        // Check if the stack is empty
        if (isEmpty())
        {
            std::cout << "The stack is empty" << std::endl;
            return;
        }
        else
        {
            // Get the top element of the stack
            std::cout << "The popped element: " << items[top] << std::endl;
            // Decrease the index of the current element
            top--;
        }
        // Decrement the number of elements in the stack by 1
        count--;
    }

    // Print the stack
    void printStack()
    {
        std::cout << "The stack: ";
        for (int i = 0; i < count; i++)
        {
            std::cout << items[i] << " ";
        }
        std::cout << std::endl;
    }

    // Private data members
private:
    int items[MAX];
    int top;
};
// Initialize static members outside a class
int Stack::count = 0;

int main()
{
    // Dynamically allocate memory on the heap for a new object
    Stack *st = new Stack();
    std::cout << st->isEmpty() << std::endl;
    st->pushElement(2);
    st->pushElement(10);
    st->pushElement(35);
    st->pushElement(50);
    st->printStack();
    st->popElement();
    st->popElement();
    st->printStack();
    st->popElement();
    st->popElement();
    st->popElement();
    // Free memory from the heap after finishing
    delete st;
    return 0;
}