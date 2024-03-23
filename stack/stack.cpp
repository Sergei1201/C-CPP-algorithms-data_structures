/* Stack DSA implementation using arrays in C++ with OOP */
#include <iostream>

/* Stack class */
class Stack
{
    /* Public data members and member functions */
public:
    static const int MAX = 5;
    static int count;
    // Default constructor (empty stack at the beginning)
    Stack()
        : top(-1)
    {
    }

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
        // If top is equal to the maximum number of elements in the stack, the stack is full
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
        // Check if the stack is full
        if (isFull())
        {
            std::cout << "The stack is full!" << std::endl;
            return;
        } // otherwise increase the top by 1 and assign the current element to the element that's passed in as an argument
        else
        {
            top++;
            stack[top] = element;
        } // Increment the number of elements in the stack by 1
        count++;
    }

    // Pop the top element from the stack
    void popElement()
    {
        // Check if the stack is empty
        if (isEmpty())
        {
            std::cout << "The stack is empty!" << std::endl;
            return;
        } // otherwise return the popped element and decrement the top by 1
        else
        {
            std::cout << "The popped element: " << stack[top] << std::endl;
            top--;
        }
        // Decrement the numbere of elements in the stack by 1
        count--;
    }

    // Print the stack
    void printStack()
    {
        std::cout << "The stack elements: ";
        for (int i = 0; i < count; i++)
        {
            std::cout << stack[i] << " ";
        }
        std::cout << std::endl;
    }

    /* Private data members */
private:
    int stack[MAX];
    int top;
};
// Count initialization
int Stack::count = 0;

int main()
{
    // Instantiate the stack class creating a new object by dynamically allocating memory on the heap
    Stack *st = new Stack();
    st->pushElement(5);
    st->pushElement(10);
    st->pushElement(20);
    st->pushElement(30);
    st->pushElement(40);
    st->printStack();
    st->popElement();
    st->popElement();
    st->popElement();
    st->popElement();
    st->popElement();
    st->popElement();
    st->printStack();
    // Deallocate memory after using it
    delete st;
}