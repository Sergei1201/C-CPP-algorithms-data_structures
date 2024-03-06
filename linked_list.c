#include <stdio.h>
#include <stdlib.h>

// Create Node
struct Node
{
    int data;
    struct Node *next;
};

// Global variables
struct Node *head;

// Function forward declaration & prototype
void insertFirst(int data);
void printList();

int main()
{
    head = NULL;
    // Variables declaration
    int data;
    int size;
    int num;
    printf("Enter the number of the linked list elements: ");
    scanf("%d", &size);
    for (int i = 0; i < size; i++)
    {
        printf("Enter elements of the linked list: ");
        scanf("%d", &num);
        insertFirst(num);
        printList();
    }
    return 0;
}

// Function definition
void insertFirst(int data)
{
    // Dynamically allocate memory for a new node
    struct Node *temp;
    temp = malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = head;
    head = temp;
}
void printList()
{
    struct Node *temp;
    temp = head;
    while (temp != NULL)
    {
        printf("Linked list %d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}