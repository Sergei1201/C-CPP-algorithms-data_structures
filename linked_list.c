#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node
{
    int data;
    struct Node *next;
};

// Function declaration & prototyping
/* Insert first element into the list*/
void insertFirst(struct Node **headRef, int data);

/* Insert after a certain node in the list*/
void insertAfter(struct Node *prevNode, int data);

/* Insrt last element into the list*/
void insertLast(struct Node **headRef, int data);

/* Print the list*/
void printList(struct Node *node);

int main()
{
    struct Node *head = NULL;
    insertFirst(&head, 20);
    insertFirst(&head, 30);
    insertLast(&head, 70);
    insertLast(&head, 100);
    insertAfter(head->next, 90);
    printList(head);
    return 0;
}

// Function definition
void insertFirst(struct Node **headRef, int data)
{
    // Dynamic memory allocation
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *headRef;
    *headRef = newNode;
}
void insertAfter(struct Node *prevNode, int data)
{
    // Check if the previous node is null
    if (prevNode == NULL)
    {
        printf("The previous node cannot be null");
        return;
    }
    // Dynamic memory allocation for a new node
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}
void insertLast(struct Node **headRef, int data)
{
    // Dynamic memory allocation
    struct Node *newNode = malloc(sizeof(struct Node));
    struct Node *temp = *headRef;
    newNode->data = data;
    newNode->next = NULL;

    if (*headRef == NULL)
    {
        *headRef = newNode;
        return;
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}
void printList(struct Node *node)
{
    struct Node *temp = node;
    do
    {
        printf("Linked list: %d ", temp->data);
        temp = temp->next;

    } while (temp->next != NULL);
}
