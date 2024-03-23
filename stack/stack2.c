/* Stack DSA implementation using linked lists in C */
#include <stdio.h>
#include <stdlib.h>

/* Node struct */
struct Node
{
    int data;
    struct Node *next;
};

/* Function forward declaration & prototyping */

// Push a new element onto the stack
void pushElement(struct Node **headRef, int data);

// Pop the top element from the stack
void popElement(struct Node **headRef);

// Print the stack
void printStack(struct Node *head);

int main()
{
    // Let's assume the stack is empty at the beginning
    struct Node *head = NULL;
    pushElement(&head, 30);
    pushElement(&head, 40);
    pushElement(&head, 50);
    printStack(head);
    popElement(&head);
    popElement(&head);
    popElement(&head);
    popElement(&head);
    printStack(head);
}

/* Function definition */

void pushElement(struct Node **headRef, int data)
{
    // Dynamic memory allocation on the heap for a new element of the stack
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    // Assign values
    newNode->data = data;
    // Point the new node to the head
    newNode->next = *headRef;
    // Shift the head to the new node
    *headRef = newNode;
}

void popElement(struct Node **headRef)
{
    // Check if the list is empty, there's nothing to pop
    if (!*headRef)
    {
        printf("The stack is empty!");
        return;
    }
    // Shift the head to the next node
    struct Node *temp = *headRef;
    *headRef = temp->next;
    // Deallocate memory for the top node
    free(temp);
}

void printStack(struct Node *head)
{
    // Traverse the stack starting from the head
    struct Node *temp = head;
    while (temp)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
