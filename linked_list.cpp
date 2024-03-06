#include <iostream>
#include <string>

// Node class
class Node
{
public:
    int data;
    Node *next;
};

// Global variables
Node *head;

// Function prototype & forward declaration
void insertFirst(int data);
void printList();

int main()
{
    // Let's assume that we have an empty list in the beginning
    head = NULL;
    int size;
    int num;
    std::cout << "Enter the number of linked list's elements please: ";
    std::cin >> size;
    for (int i = 0; i < size; i++)
    {
        std::cout << "Enter a number to build a linked list please: ";
        std::cin >> num;
        insertFirst(num);
        printList();
    }
    return 0;
}

// Function definition
void insertFirst(int data)
{
    // Dynamic memory allocation on a heap for a new node
    Node *temp = new Node();
    // Assign values
    temp->data = data;
    temp->next = head;
    head = temp;
}
void printList()
{
    Node *temp = head;
    while (temp->next != NULL)
    {
        std::cout << "Elements of the linked list " << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}