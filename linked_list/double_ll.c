#include <stdio.h>
#include <stdlib.h>

/* Node struct */
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

/* Function forward declaration & prototyping */

// Insert first
void insertFirst(struct Node **headRef, int data);

// Insert last
void insertLast(struct Node **headRef, int data);

// Print list
void printList(struct Node *head);

int main()
{
    // Assume that we've got an empty list at the beginning
    struct Node *head = NULL;
    insertFirst(&head, 50);
    insertFirst(&head, 90);
    insertFirst(&head, 95);
    insertLast(&head, 506);
    insertLast(&head, 207);
    printList(head);
    return 0;
}

/* Function definition */
void insertFirst(struct Node **headRef, int data)
{
    // Dynamic memory allocation on the heap for a new node
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    // Assign values
    newNode->data = data;
    // Point the next pointer to the head
    newNode->next = *headRef;
    // Point the previous pointer to NULL since it's a newly created head of the list
    newNode->prev = NULL;
    // Check if the head is empty, assign the new node to the head so that we can access that particular memory block, shift the head pointer to the new node
    if (*headRef == NULL)
    {
        newNode->prev = NULL;
        *headRef = newNode;
    }
    else
    {
        (*headRef)->prev = newNode;
        *headRef = newNode;
    }
}

// Print last
void printLast(struct Node **headRef, int data)
{
    // Dynamically allocate memory on the heap for a new node
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    // Declare a temp variable to traverse the list
    struct Node *temp = *headRef;
    // Assign values
    newNode->data = data;
    newNode->next = NULL;
    // Check if there's not head, set the new node to the head and return
    if (*headRef == NULL)
    {
        newNode->prev = NULL;
        *headRef = newNode;
    }
    // Traverse the list and point the last node to the new node in both directions
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    // Change pointers to point to the previous node
    newNode->prev = temp;
}

void printList(struct Node *head)
{
    // Set a temp value to traverse the linked list
    struct Node *temp = head;
    while (temp)
    {
        printf("Linked list: %d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
