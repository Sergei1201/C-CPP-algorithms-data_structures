/* Here is a full implementation of singly linked list algorithm in the C++ language */
#include <iostream>

// Define Node structure
struct Node
{
    int data;
    Node *next;
};

/* Function forward declaration & prototyping */

// Insert at the beginning of the linked list
void insertFirst(Node **headdRef, int data);

// Insert after a particular node
void insertAfter(Node *prevNode, int data);

// Insert last
void insertLast(Node **headRef, int data);

// Delete node
void deleteNode(Node **headRef, int key);

// Search for a node
bool searchNode(Node **headRef, int key);

// Sort list
void sortList(Node **headRef);

// Print the linked list
void printList(Node *head);

int main()
{
    // At the beginning the list is empty and the head points to null
    Node *head = NULL;
    insertFirst(&head, 50);
    insertFirst(&head, 100);
    insertFirst(&head, 200);
    insertLast(&head, 750);
    insertAfter(head->next, 350);
    deleteNode(&head, 350);
    deleteNode(&head, 750);
    deleteNode(&head, 960);
    insertFirst(&head, 567);
    insertLast(&head, 990);
    insertAfter(head->next->next, 3968);
    insertFirst(&head, 5690);
    sortList(&head);
    int key = 200;
    if (searchNode(&head, key))
    {
        std::cout << "The node " << key << " has been found" << std::endl;
    }
    else
    {
        std::cout << "The node " << key << " has not been found" << std::endl;
    }
    printList(head);
    return 0;
}

/* Function definition */

void insertFirst(Node **headRef, int data)
{
    // Dynamically allocate memory on the heap for a new node
    Node *newNode = new Node;
    // Assign values
    newNode->data = data;
    // Point the new node to the head
    newNode->next = *headRef;
    // Shift the head pointer to the new node
    *headRef = newNode;
}

void insertAfter(Node *prevNode, int data)
{
    // Make sure the previous node exists
    if (prevNode == NULL)
    {
        std::cout << "The previous node can't be null" << std::endl;
        return;
    }
    // Dynamically allocate memory on the heap for a new node
    Node *newNode = new Node;
    // Assign values
    newNode->data = data;
    // Point the new node to the node next to the previous one
    newNode->next = prevNode->next;
    // Point the previous node to the new node to change links
    prevNode->next = newNode;
}

void insertLast(Node **headRef, int data)
{
    // Create temp variable to traverse the linked list
    Node *temp = *headRef;
    // Dynamically allocate memory on the heap for a new node
    Node *newNode = new Node;

    // Check if the head is empty, then assign the node to the head and return
    if (*headRef == NULL)
    {
        *headRef = newNode;
        return;
    }
    // Assign values
    newNode->data = data;
    newNode->next = NULL;

    // Traverse the linked list till the end and point the last node to the new node
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void deleteNode(Node **headRef, int key)
{
    // Check if the node to be deleted is in the head, point the head to the next position
    Node *temp = *headRef, *prev;
    if (temp->next != NULL && temp->data == key)
    {
        *headRef = temp->next;
        delete temp;
    }
    // Traverse the linked list and find the key to delete
    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }
    // Check if there's no match in the list
    if (temp == NULL)
    {
        std::cout << "There's no node to be deleted" << std::endl;
        return;
    }
    // Delete the node
    prev->next = temp->next;
}

bool searchNode(Node **headRef, int key)
{
    // Check if there's no head
    if (headRef == NULL)
    {
        return false;
    }
    // Make the current variable to traverse the linked list
    Node *current = *headRef;
    while (current)
    {
        if (current->data == key)
        {
            return true;
        }
        current = current->next;
    }
    return false;
}

void printList(Node *head)
{
    // Temp variable to traverse the list
    Node *temp = head;
    while (temp != NULL)
    {
        std::cout << "Linked list " << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

void sortList(Node **headRef)
{
    Node *current = *headRef;
    Node *index = NULL;
    int temp;

    // Check if there's no head
    if (headRef == NULL)
    {
        return;
    }
    // Implement a swapping algorithm
    while (current)
    {
        index = current->next;
        while (index)
        {
            if (current->data > index->data)
            {
                temp = current->data;
                current->data = index->data;
                index->data = temp;
            }
            index = index->next;
        }
        current = current->next;
    }
}
