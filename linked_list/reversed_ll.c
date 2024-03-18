/* Full implementation of the reversed linked list data structure using the iterative method in the C programming language */
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

// Reverse the linked list using the iterative approach
void reverseList(struct Node **headRef);

// Print the linked list
void printList(struct Node *head);

int main()
{
    // Let's assume that the linked list is empty at the beginning
    struct Node *head = NULL;
    pushNode(&head, 25);
    pushNode(&head, 35);
    pushNode(&head, 56);
    pushNode(&head, 95);
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
    // Change the next pointer of the new node to the head in order to insert it at the beginning of the linked list
    newNode->next = *headRef;
    // Shift the head pointer to the new node so that the new node is now the first one
    *headRef = newNode;
}

void reverseList(struct Node **headRef)
{
    // Consider the case when the head points to null or the next node points to null, therefore we've got nothing to reverse
    struct Node *temp = *headRef;
    if (!temp || !temp->next)
    {
        return;
    }
    // Create a couple of pointers to traverse the linked list
    struct Node *current = *headRef;
    struct Node *prev = NULL;
    struct Node *next = NULL;
    // Traverse the linked list till the current pointer points to null and change the links to the opposite direction
    while (current)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    // Shift the head pointer to the last node (prev)
    *headRef = prev;
}

void printList(struct Node *head)
{
    // Set a temp variable to traverse the linked list
    struct Node *temp = head;
    // Iterate through the linked list till the end and print the values of every node on each iteration
    while (temp)
    {
        printf("Linked list: %d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
