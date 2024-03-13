/* Full implementation of a double linked list data structure in the C programming language */
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

// Insert after
void insertAfter(struct Node *prevNode, int data);

// Insert last
void insertLast(struct Node **headRef, int data);

// Print list
void printList(struct Node *head);

// Delete node
void deleteNode(struct Node **headRef, struct Node *delNode);

int main()
{
    // Assume that we've got an empty list at the beginning
    struct Node *head = NULL;
    insertFirst(&head, 50);
    insertFirst(&head, 90);
    insertFirst(&head, 95);
    insertLast(&head, 506);
    insertLast(&head, 207);
    insertAfter(head->next->next->next, 3300);
    insertAfter(head->next->next->next->next->next, 1000);
    deleteNode(&head, head->next->next->next->next);
    deleteNode(&head, head->next->next->next->next->next);
    deleteNode(&head, head);
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

// Insert after
void insertAfter(struct Node *prevNode, int data)
{
    // Check if there's the previous node in the list
    if (!prevNode)
    {
        printf("The previous node can't be null");
        return;
    }
    // Dynamically memory allocation on the heap for a new node
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    // Assign values
    newNode->data = data;
    // Point the next pointer of the new node to the next node after the previous one
    newNode->next = prevNode->next;
    // Point the next pointer of the previous node to the new node
    prevNode->next = newNode;
    // Point the previous pointer of the new node to the previous one
    newNode->prev = prevNode;
    // Check if there is the next node after the new node, point the next node to the new node
    if (newNode->next)
    {
        newNode->next->prev = newNode;
    }
}

// Print last
void insertLast(struct Node **headRef, int data)
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

// Delete node
void deleteNode(struct Node **headRef, struct Node *delNode)
{
    // If there's no head or not delNode, return
    if (*headRef == NULL || delNode == NULL)
    {
        printf("No node to be deleted");
        return;
    }
    // Check if the delNode is in the head, move the next pointer of the head to the next node
    if (*headRef == delNode)
    {
        *headRef = delNode->next;
    }
    // Check if the delNode is node the last node, change the previous pointer of the next node to the previous pointer of the delNode
    if (delNode->next != NULL)
    {
        delNode->next->prev = delNode->prev;
    }
    // Check if the delNode is not in the head, change the next pointer of the previous node to the next pointer of the delNode
    if (delNode->prev != NULL)
    {
        delNode->prev->next = delNode->next;
    }
    // Deallocate memory for delNode after completion
    free(delNode);
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
