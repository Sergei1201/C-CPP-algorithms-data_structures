#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

/* Delete a node */
void deleteNode(struct Node **headRef, int key);

/* Search for a node */
bool searchNode(struct Node **headRef, int key);

/*Sort the linked list*/
void sortList(struct Node **headRef);

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
    // deleteNode(&head, 20);
    insertLast(&head, 560);
    insertFirst(&head, 95);
    sortList(&head);
    //  int searchedItem = 10;
    //  if (searchNode(&head, searchedItem))
    //  {
    //      printf("The item \n%d has been found", searchedItem);
    //      printf("\n");
    //  }
    //  else
    //  {
    //      printf("The item \n%d has not been found", searchedItem);
    //      printf("\n");
    //  }
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
void deleteNode(struct Node **headRef, int key)
{
    // Create a temp variable to traverse the linked list
    struct Node *temp = *headRef, *prev;
    // Check if there's a match at the head of the linked list thus removing the head
    if (temp->next != NULL && temp->data == key)
    {
        // Move the head to the next node
        *headRef = temp->next;
        // Free memory for temp
        free(temp);
        return;
    }
    // Traverse the list until you find the key
    while (temp->next != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }
    // Check if there's no node to be found
    if (temp == NULL)
    {
        printf("No match to be found");
        return;
    }
    // Delete a node
    prev->next = temp->next;
    free(temp);
}
bool searchNode(struct Node **headRef, int key)
{
    struct Node *current = *headRef;
    while (current != NULL)
    {
        if (current->data == key)
        {
            return true;
        }
        current = current->next;
    }
    return false;
}
void sortList(struct Node **headRef)
{
    // Initialize the current variable that points to the head at the beginning
    struct Node *current = *headRef;
    // Initialize the index to null (pointer to the next node) at the beginning
    struct Node *index = NULL;
    // Initialize temp variable to swap two elements
    int temp;
    // If the head points to null, return
    if (headRef == NULL)
    {
        return;
    }
    else
    {
        while (current->next != NULL)
        {
            index = current->next;
            while (index->next != NULL)
            {
                if (current->data > index->data)
                {
                    temp = current->data;
                    current->data = index->data;
                    index->data = temp;
                }
                index = index->next;
            }
            current = current->next;
        }
    }
}
void printList(struct Node *node)
{
    struct Node *temp = node;
    do
    {
        printf("Linked list: %d ", temp->data);
        temp = temp->next;

    } while (temp->next != NULL);
    printf("\n");
}
