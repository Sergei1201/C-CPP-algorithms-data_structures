/* Full implementation of the reversed linked list data structure in the C++ programming language */
#include <iostream>
#include <stdlib.h>

/* Node class */
class Node
{
    // Private data members
public:
    int m_data;
    Node *next;

public:
    // Default constructor
    Node() = default;
    // // Parameterized constructor
    Node(int data)
        : m_data(data), next(NULL)
    {
    }
};

/* Linked list class */
class LinkedList
{
    // Private data members
private:
    Node *head;

public:
    // Default constructor
    LinkedList()
        : head(NULL)
    {
    }
    /* Public member functions */

    // Reverse linked list
    void reverseList()
    {
        // Create some pointers to traverse a linked list
        Node *current = head;
        Node *next = NULL;
        Node *prev = NULL;
        // Traverse the linked list and change pointers to the opposite direction and finally change the head to the last node
        while (current)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }

    // Push a new node to the linked list
    void pushNode(int data)
    {
        // Dynamic memory allocation on the heap for a new node
        Node *newNode = new Node();
        // Assign values
        newNode->m_data = data;
        // Point the new node to the head
        newNode->next = head;
        // Shift the head to the new node
        head = newNode;
    }
    // Print the linked list
    void printList()
    {
        // Set a temporary variable to traverse the linked list starting from the head, then print values of all nodes on each iteration
        Node *temp = head;
        while (temp)
        {
            std::cout << "Linked list: " << temp->m_data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

int main()
{
    // Instantiate the linked list class
    LinkedList ll;
    // Push new nodes to the linked list at the beginning
    ll.pushNode(30);
    ll.pushNode(40);
    ll.pushNode(50);
    ll.pushNode(60);
    ll.pushNode(85);
    ll.printList();
    ll.reverseList();
    ll.printList();
    return 0;
}