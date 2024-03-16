/* Full implementation of a reversed linked list in the C programming language */
#include <stdio.h>
#include <stdlib.h>

/* Node structure */
struct Node
{
    int data;
    struct Node *next;
};

/* Function forward declaration & prototyping */

// Reverse a linked list
void reverseList(struct Node **headRef);

// Push a new node to the linked list
void pushNode(struct Node **headRef, int data);

// Print the linked list
void printList(struct Node *head);

int main()
{
    // Lets' assume that the linked list is empty at the beginning
    struct Node *head = NULL;
    pushNode(&head, 25);
    pushNode(&head, 35);
    pushNode(&head, 45);
    pushNode(&head, 55);
    pushNode(&head, 65);
    printList(head);
    reverseList(&head);
    printList(head);
    return 0;
}

/* Function definition */

void reverseList(struct Node **headRef)
{
    // Create pointers to traverse the linked list
    struct Node *current = *headRef;
    struct Node *next = NULL;
    struct Node *prev = NULL;
    // Traverse the linked list
    while (current)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *headRef = prev;
}

void pushNode(struct Node **headRef, int data)
{
    // Dynamic memory allocation on the heap for a new node
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    // Assign values
    newNode->data = data;
    // Point new node to the head
    newNode->next = *headRef;
    // Shift the head to the new node
    *headRef = newNode;
}

void printList(struct Node *headRef)
{
    // Set a temporary variable to traverse the linked list starting from the head
    struct Node *temp = headRef;
    while (temp)
    {
        printf("Linked list: %d ", temp->data);
        temp = temp->next;
    };
    printf("\n");
}