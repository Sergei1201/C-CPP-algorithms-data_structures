/* Implementation of a reversed linked list using recursion in the C programming language */
#include <stdio.h>
#include <stdlib.h>

/* Node structure */
struct Node
{
    int data;
    struct Node *next;
};

/* Function forward declaration & prototyping */

// Push a new node to the linked list
void pushNode(struct Node **headRef, int data);

// Reverse the linked list using recursion
void reverseList(struct Node **headRef);

// Print the linked list
void printList(struct Node *head);

int main()
{
    // Lets' assume that the list is empty at the beginning
    struct Node *head = NULL;
    pushNode(&head, 20);
    pushNode(&head, 25);
    pushNode(&head, 35);
    pushNode(&head, 50);
    pushNode(&head, 99);
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
    // Assign values
    newNode->data = data;
    // Point the new node to the head
    newNode->next = *headRef;
    // Shift the head to the new node
    *headRef = newNode;
}

void reverseList(struct Node **headRef)
{
    // Initialize two variables: first and rest
    struct Node *first, *rest;
    first = *headRef;
    rest = first->next;
    // Check if the list is empty
    if (!*headRef)
    {
        return;
    }
    // Check if there's only one node
    if (!rest)
    {
        return;
    }
    reverseList(&rest);
    first->next->next = first;
    first->next = NULL;
    *headRef = rest;
}

void printList(struct Node *head)
{
    // Set a temporary variable to traverse the linked list and print values of every node on each iteration starting at the beginning
    struct Node *temp = head;
    while (temp)
    {
        printf("Linked list: %d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}