/* Here is the full implementation of the singly linked list algorithm in the C language */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define Node structure
struct Node
{
    int data;
    struct Node *next;
};

/* Function forward declaration & prototyping*/

// Insert at the beginning of the linked list
void insertFirst(struct Node **headRef, int data);

// Insert after
void insertAfter(struct Node *prevNode, int data);

// Insert at the end of the linked list
void insertLast(struct Node **headRef, int data);

// Delete a node
void deleteNode(struct Node **headRef, int key);

// Search for a node
bool searchNode(struct Node **headRef, int key);

// Sort a linked list
void sortList(struct Node **headRef);

// Print linked list onto the screen
void printList(struct Node *head);

int main()
{
    // At the beginning the list is empty and the head does not point to anything
    struct Node *head = NULL;
    insertFirst(&head, 70);
    insertFirst(&head, -25);
    insertAfter(head->next, 120);
    insertAfter(head->next, 130);
    insertLast(&head, 110);
    insertLast(&head, 250);
    insertFirst(&head, 2);
    insertFirst(&head, 2500);
    insertLast(&head, 99);
    deleteNode(&head, -25);
    deleteNode(&head, 99);
    int key = 196;
    if (searchNode(&head, key))
    {
        printf("The node %d has been found in the list ", key);
        printf("\n");
    }
    else
    {
        printf("The node %d hasn't been found in the list ", key);
        printf("\n");
    }
    sortList(&head);
    printList(head);
    return 0;
}

/* Function definition*/

void insertFirst(struct Node **headRef, int data)
{
    // Dynamically memory allocation for a new node
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    // Assign data to the newly created node
    newNode->data = data;
    // Point the node to the head
    newNode->next = *headRef;
    // Shift the head to the newly created node (change the head)
    *headRef = newNode;
}

void insertAfter(struct Node *prevNode, int data)
{
    // Check if there's no previous node
    if (prevNode == NULL)
    {
        printf("The previous node cannot be null");
        return;
    }
    // Dynamically memory allocation on the heap for a new node
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    // Assign values
    newNode->data = data;
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

void insertLast(struct Node **headRef, int data)
{
    // Dynamic memory allocation for a new node
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    // Create temp variable to traverse the list
    struct Node *temp = *headRef;
    // Assign values
    newNode->data = data;
    newNode->next = NULL;

    // Check if the head is null, assign the newly created node to the head and return
    if (*headRef == NULL)
    {
        *headRef = newNode;
        return;
    }

    // Traverse the list till the end and point the last node to the new node
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void deleteNode(struct Node **headRef, int key)
{
    struct Node *temp = *headRef, *prev;

    // Check if the head is to be deleted, point the head to the next node
    if (temp->next != NULL && temp->data == key)
    {
        *headRef = temp->next;
        free(temp);
        return;
    }
    // Traverse the list and find the key to be deleted
    while (temp->next != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }
    // No match
    if (temp == NULL)
    {
        printf("No node to be deleted");
        return;
    }
    // Delete the particular node in the list
    prev->next = temp->next;
    free(temp);
}

bool searchNode(struct Node **headRef, int key)
{
    // Set the current node to search for a particular node
    struct Node *current = *headRef;
    while (current != NULL)
    {
        if (current->data == key)
        {
            return true;
        }
        current = current->next;
    }
    return false;
}

void sortList(struct Node **headRef)
{
    // Declare the current element at the beginning
    struct Node *current = *headRef;
    // Define an index (next node)
    struct Node *index = NULL;
    // Declare a temp variable for swapping adjacent nodes
    int temp;
    // Check if the head is null
    if (headRef == NULL)
    {
        return;
    }
    while (current != NULL)
    {
        index = current->next;
        while (index != NULL)
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

void printList(struct Node *head)
{
    // Traverse the list and print data on each iteration
    struct Node *temp = head;
    do
    {
        printf("Linked list: %d ", temp->data);
        temp = temp->next;

    } while (temp != NULL);
    printf("\n");
}