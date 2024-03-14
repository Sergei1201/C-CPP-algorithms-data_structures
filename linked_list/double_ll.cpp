/* Full implementation of a double linked list with C++ in the object-oriented-fashion */
#include <iostream>

/* Node class */
class Node
{
public:
    int m_data;
    Node *next;
    Node *prev;
    // Default constructor
    Node() = default;
    // Parameterized constructor
    Node(int data)
        : m_data(data), next(NULL), prev(NULL)
    {
    }
};

/* Linked list class */
class LinkedList
{
public:
    Node *head;
    // Default constructor
    LinkedList()
        : head(NULL)
    {
    }

    /* Public member functions */

    // Insert first
    void insertFirst(int data);

    // Insert after
    void insertAfter(Node *prevNode, int data);

    // Insert last
    void insertLast(int data);

    // Delete node
    void deleteNode(Node *delNode);

    // Print linked list
    void printList();
};

void LinkedList::insertFirst(int data)
{
    // Dynamic memory allocation on the heap for a new node
    Node *newNode = new Node();
    // Assign values to the allocated memory (type of Node)
    newNode->m_data = data;
    // Change the next pointer of the new node to the head
    newNode->next = head;
    // Change the previous pointer of the new node to NULL (make it the head node)
    newNode->prev = NULL;
    // Check if the head is NULL
    if (!head)
    {
        head = newNode;
        newNode->prev = NULL;
    }
    else
    {
        head->prev = newNode;
        head = newNode;
    }
}

void LinkedList::insertAfter(Node *prevNode, int data)
{
    // Check if there's no previous node
    if (!prevNode)
    {
        std::cout << "The previous node cannot be null!";
        return;
    }
    // Dynamically memory allocation on the heap for a new node
    Node *newNode = new Node();
    // Assign values
    newNode->m_data = data;
    // Change the next link of the new node to the next link of the previous node
    newNode->next = prevNode->next;
    // Change the previous link of the new node to the previous node
    newNode->prev = prevNode;
    // Change the link of the next node of the previous node to the new node
    prevNode->next = newNode;
    // Check if the new node is not the last node in the list, change the previous pointer of the next node to the new node (to readjust links)
    if (newNode->next)
    {
        newNode->next->prev = newNode;
    }
}

void LinkedList::deleteNode(Node *delNode)
{
    // Check if there's no head or no delNode
    if (!head || !delNode)
    {
        std::cout << "No data to be deleted!";
        return;
    }
    // Check if the delNode is in the head, shift the head node to the next node
    if (head == delNode)
    {
        head = delNode->next;
    }
    // Check if the delNode is not the last node in the linked list
    // Point the previous pointer of the next node to the previous pointer of the current node
    if (delNode->next)
    {
        delNode->next->prev = delNode->prev;
    }
    // Check if the delNode is not in the head
    if (delNode->prev)
    {
        delNode->prev->next = delNode->next;
    }
    // Free memory for delNode pointer
    delete delNode;
}

void LinkedList::insertLast(int data)
{
    // Dynamically memory allocation on the heap for a new node
    Node *newNode = new Node();
    // Set temp variable to traverse the linked list
    Node *temp = head;
    // Assign values
    newNode->m_data = data;
    // Point the next pointer of the new node to NULL since it's going to be the last node
    newNode->next = NULL;
    // Check if the head points to null, change the head to the new node and return
    if (!head)
    {
        head = newNode;
        newNode->prev = NULL;
        return;
    }
    // Traverse the linked list from the head, point the last node to the new node, point the new node to the previous node
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void LinkedList::printList()
{
    // Traverse the linked list till the end and print values of each node
    Node *temp = head;
    while (temp)
    {
        std::cout << "Linked list: " << temp->m_data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

int main()
{
    // Instantiate the linked list class
    LinkedList ll;
    ll.insertFirst(25);
    ll.insertFirst(30);
    ll.insertFirst(40);
    ll.insertAfter(ll.head->next, 100);
    ll.insertLast(192);
    ll.insertLast(-192);
    ll.insertAfter(ll.head->next->next->next->next, 302);
    ll.insertFirst(35);
    ll.printList();
    return 0;
}