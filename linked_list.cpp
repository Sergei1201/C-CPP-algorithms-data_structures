#include <iostream>
#include <string>

// Node struct
struct Node
{
public:
    int data;
    Node *next;
};

// Global variables
Node *head;

// Function prototype & forward declaration
void insertFirstNode(int data);
void printNode();

int main()
{
    // Empty list
    head = NULL;
    int size;
    int data;
    std::cout << "How many numbers do you want to enter into the linked list? ";
    std::cin >> size;
    std::cout << "Linked list: " << std::endl;
    for (int i = 0; i < size; i++)
    {
        std::cin >> data;
        insertFirstNode(data);
        printNode();
    }
    return 0;
}

// Function definition
void insertFirstNode(int data)
{
    // Dynamic memory allocation for a new node
    Node *temp = new Node;
    temp->data = data;
    temp->next = head;
    head = temp;
    delete temp;
}
void printNode()
{
    Node *temp1 = head;
    while (temp1->next != NULL)
    {
        std::cout << temp1->data << " ";
    }
    std::cout << std::endl;
}