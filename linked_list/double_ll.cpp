/*Full implementation of double linked list in the C++ programming language in the object-oriented fashion*/
#include <iostream>

/* Node class */
class Node
{
public:
    int m_data;
    Node *next;
    Node *prev;

public:
    // Default constructor
    Node()
        : m_data(0),
          next(NULL), prev(NULL)
    {
    }
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

public:
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
    void deleteNode(Node *delData);

    // Print list
    void printList();
};

void LinkedList::insertFirst(int data)
{
    // Dynamic memory allocation for a new node on the heap
    Node *newNode = new Node(data);
    // Point the next pointer to the head
    newNode->next = head;
    newNode->prev = NULL;
    // Check if the head is empty, set the new node to the head and shift the pointer of the head to it
    if (head == NULL)
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
    // Check if the previous node is null
    if (prevNode == NULL)
    {
        std::cout << "The previous node cannot be null!";
        return;
    }
    // Dynamic memory allocation for a new node on the heap
    Node *newNode = new Node();
    // Assign values
    newNode->m_data = data;
    // Point the next pointer to the node that is next to the previous pointer
    newNode->next = prevNode->next;
    // Point the previous pointer to the previous node
    newNode->prev = prevNode;
    // Point the next pointer of the previous node to the new node
    prevNode->next = newNode;
    // If the new node is not the last one, change the next pointer to the new node
    if (prevNode->next)
    {
        prevNode->next->prev = newNode;
    }
}

void LinkedList::insertLast(int data)
{
    // Dynamic memory allocation for a new node on the heap
    Node *newNode = new Node();
    // Set temp variable to traverse the linked list from the head
    Node *temp = head;
    // Assign values to the memory block - dereferene pointers
    newNode->m_data = data;
    newNode->next = NULL;
    // Check if the head is NULL, set the new node to the head
    if (head == NULL)
    {
        head = newNode;
        newNode->prev = NULL;
        return;
    }
    // Traverse the list till the end and point the last node to the new node
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    // Change the previous pointer of the new node to the previous node to readjust the links
    newNode = temp;
}

void LinkedList::deleteNode(Node *delNode)
{
    // If there's no head or no node to be deleted
    if (!head || !delNode)
    {
        std::cout << "There's no node to be deleted from the list!";
        return;
    }
    // Check if the key is in the head, shift the head to the next node
    if (head == delNode)
    {
        head = delNode->next;
    }
    // Check if the node is not the last one, change the previous pointer of the next node to the previous ponter of the current node
    if (delNode->next)
    {
        delNode->next->prev = delNode->prev;
    }
    // Check if the delNode is not in the head, change the next pointer of the previous node to the next pointer of the delNode
    if (delNode->prev)
    {
        delNode->prev->next = delNode->next;
    }
    // Deallocate memory for the delNode on the heap
    delete delNode;
}

void LinkedList::printList()
{
    {
        // Traverse the list and print the value of nodes on each iteration
        Node *temp = head;
        while (temp)
        {
            std::cout << "Double linked list: " << temp->m_data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
}

int main()
{
    // Instantiate a linked list class by creating an object
    LinkedList ll;
    ll.insertFirst(20);
    ll.insertFirst(30);
    ll.insertFirst(55);
    ll.insertLast(100);
    ll.insertLast(200);
    ll.insertAfter(ll.head->next, 260);
    ll.insertAfter(ll.head->next->next, 350);
    ll.insertAfter(ll.head, 956);
    ll.insertAfter(ll.head->next->next->next->next->next, 1001);
    ll.insertLast(2002);
    ll.insertLast(20055);
    ll.deleteNode(ll.head->next);
    ll.printList();
    return 0;
}