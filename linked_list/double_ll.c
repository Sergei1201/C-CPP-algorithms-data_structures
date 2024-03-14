/* Full implementation of a double linked list in the C programming language */
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

// Delete node
void deleteNode(struct Node **headRef, struct Node *delNode);

// Print list
void printList(struct Node *head);

int main()
{
    // At the beginning the list is empty
    struct Node *head = NULL;
    insertFirst(&head, 20);
    insertFirst(&head, 30);
    insertFirst(&head, 50);
    insertLast(&head, 190);
    insertLast(&head, 135);
    insertFirst(&head, 295);
    insertAfter(head, 350);
    insertAfter(head->next->next, 999);
    deleteNode(&head, head);
    deleteNode(&head, head->next->next);
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
    newNode->next = *headRef;
    newNode->prev = NULL;
    // Check if the head is empty, change the head to the new node
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
    // Check if there's no previous node
    if (!prevNode)
    {
        printf("The previous node cannot be null!");
        return;
    }
    // Dynamic memory allocation on the heap for a new node
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    // Assign values
    newNode->data = data;
    // Change the next pointer of the new node to the next pointer of the previous node
    newNode->next = prevNode->next;
    // Change the next pointer of the previous node to the new node
    prevNode->next = newNode;
    // Change the previous pointer of the new node to the previous node
    newNode->prev = prevNode;
    // Check if the next node is not null, change its previous pointer to the new node to rearrange the links
    if (newNode->next != NULL)
    {
        newNode->next->prev = newNode;
    }
}

// Insert last
void insertLast(struct Node **headRef, int data)
{
    // Dynamic memory allocation on the heap for a new node
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    // Set a temp variable to traverse the list starting at the head
    struct Node *temp = *headRef;
    // Assign values
    newNode->data = data;
    newNode->next = NULL;
    // Check if there's not head, point the new node to the head
    if (!*headRef)
    {
        newNode->prev = NULL;
        *headRef = newNode;
    }
    // Traverse the list, point the last node to the new node, point the new node to the previous one, thus rebuilding links
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

// Delete node
void deleteNode(struct Node **headRef, struct Node *delNode)
{
    // If there's no head or delNode, return
    if (*headRef == NULL || delNode == NULL)
    {
        printf("There's no node to be deleted");
        return;
    }
    // Check if the delNode is in the head, move the head to the next node
    if (*headRef == delNode)
    {
        *headRef = delNode->next;
    }
    // Check if the delNode is not the last node, change the previous pointer of the next node to the previous pointer of the delNode
    if (delNode->next)
    {
        delNode->next->prev = delNode->prev;
    }
    // Check if the delNode is not the first node (head), change the next pointer of the previous node to the next pointer of the delNode
    if (delNode->prev)
    {
        delNode->prev->next = delNode->next;
    }
    // When done, deallocate memory for delNode
    free(delNode);
}

// Print list
void printList(struct Node *head)
{
    // Traverse the list and print data of the nodes on each iteration
    struct Node *temp = head;
    while (temp)
    {
        printf("Linked list: %d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}