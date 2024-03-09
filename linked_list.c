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

/* Insrt last element into the list*/
void insertLast(struct Node **headRef, int data);

/* Print the list*/
void printList(struct Node *node);

int main()
{
    struct Node *head = NULL;
    insertFirst(&head, 1);
    insertFirst(&head, 10);
    insertFirst(&head, 12);
    insertLast(&head, 25);
    insertLast(&head, 30);
    insertLast(&head, 40);
    insertLast(&head, 50);
    insertFirst(&head, 150);
    insertLast(&head, 200);
    insertLast(&head, 300);
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