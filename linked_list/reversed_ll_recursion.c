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
    // Consider the case where there's no head or no next node. In this case there's nothing to work on, just return and that's it
    struct Node *temp = *headRef;
    if (!temp || !temp->next)
    {
        return;
    }
    // Divide the linked list in two parts: the first one is the first node, the second one is the rest of the list
    struct Node *first = *headRef;
    struct Node *rest = first->next;
    // Check if there's not rest, return
    if (!rest)
    {
        return;
    }
    // Call the reverse function recursively
    reverseList(&rest);
    first->next->next = first;
    first->next = NULL;
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