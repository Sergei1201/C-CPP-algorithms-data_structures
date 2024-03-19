/* Full implementation of the reversed linked list data using recursion in the C programming language  */
#include <stdio.h>
#include <stdlib.h>

/* Node struct */
struct Node
{
    int data;
    struct Node *next;
};

/* Function forward declaration & prototyping */

// Push a new node to the linked list
void pushNode(struct Node **headRef, int data);

// Reverse the linked list recursively
void reverseList(struct Node **headRef);

// Print the linked list
void printList(struct Node *head);

int main()
{
    // Let's assume that we've got an empty list at the beginning
    struct Node *head = NULL;
    pushNode(&head, 25);
    pushNode(&head, 35);
    pushNode(&head, 95);
    pushNode(&head, 99);
    pushNode(&head, 100);
    printList(head);
    reverseList(&head);
    printList(head);
    return 0;
}

/* Function definition */

void pushNode(struct Node **headRef, int data)
{
    // Dynamic memory allocation on the heap for a new node
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    // Assign data
    newNode->data = data;
    // Change the next pointer of the new node to the head pointer
    newNode->next = *headRef;
    // Shift the head reference to the new node
    *headRef = newNode;
}

void reverseList(struct Node **headRef)
{
    // Case list is empty
    if (!*headRef)
    {
        return;
    }
    // Make pointers to traverse the list recursively
    struct Node *firstNode = *headRef;
    struct Node *rest = firstNode->next;
    // Check if the rest is not equal to null
    if (!rest)
    {
        *headRef = firstNode;
        return;
    }
    // Traverse the list recursively
    reverseList(&rest);
    firstNode->next->next = firstNode;
    firstNode->next = NULL;
    *headRef = rest;
}

void printList(struct Node *head)
{
    // Assign a temp variable to traverse the linked list
    struct Node *temp = head;
    // Traverse the linked list from the beginning and print values on each iteration
    while (temp)
    {
        printf("Linked list: %d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}