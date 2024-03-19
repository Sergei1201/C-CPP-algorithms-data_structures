/* Full implementation of the reversed linked list data structure using recursion in C++ */
#include <iostream>

/* Node class */
class Node
{
public:
    int m_data;
    Node *next;
    // Default constructor
    Node() = default;
    // Parameterized constructor
    Node(int data)
        : m_data(data), next(NULL)
    {
    }
};

/* Linked list class */
class LinkedList
{
public:
    Node *head;

public:
    // Default constructor
    LinkedList()
        : head(NULL)
    {
    }
    /* Public member functions */

    // Push a new node to the linked list
    void pushNode(int data)
    {
        // Dynamic memory allocation on the heap for a new node
        Node *newNode = new Node();
        // Assign values
        newNode->m_data = data;
        // Point next to the head
        newNode->next = head;
        // Shift the head to the new node
        head = newNode;
    }

    // Reverse the linked list using recurson
    Node *reverseList(Node *head)
    {
        // Let's assume there's no head
        if (!head || !head->next)
        {
            return head;
        }
        // Divide the linked list in two parts: the first node and the rest, then reverse the rest
        Node *rest = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        // Fist the head pointer
        return rest;
    }

    // Print the linked list
    void printList()
    {
        // Set a temp variable to travese the list starting at the head
        Node *temp = head;
        while (temp)
        {
            std::cout << temp->m_data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

int main()
{
    // Instantiate the Linked list class
    LinkedList ll;
    ll.pushNode(25);
    ll.pushNode(35);
    ll.pushNode(45);
    ll.pushNode(3);
    ll.pushNode(2);
    ll.printList();
    ll.head = ll.reverseList(ll.head);
    ll.printList();
    return 0;
}