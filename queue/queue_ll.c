/* Queue implementation DSA using linked lists in C */
#include <stdio.h>
#include <stdlib.h>

/* Node struct */
struct Node
{
    int data;
    struct Node *next;
};

/* Queue struct */
struct Queue
{
    struct Node *front, *rear;
};

/* Function forward declaration & prototyping */

// Create a new node
struct Node *createNode(int data);

// Create an empty queue
struct Queue *createEmptyQueue();

// Push a new node to the back of the queue
void enqueue(struct Queue *q, int data);

// Dequeue
void dequeue(struct Queue *q);

// Print the queue
void printQueue(struct Queue *q);

int main()
{
    struct Queue *q = createEmptyQueue();
    enqueue(q, 5);
    enqueue(q, 10);
    printQueue(q);
    dequeue(q);
    printQueue(q);

    return 0;
}

/* Function definition */

struct Node *createNode(int data)
{
    // Dynamic memory allocation on the heap for a new node
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    // Assign values
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Queue *createEmptyQueue()
{
    // Dynamic memory allocation for on the heap for a new queue
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(struct Queue *q, int data)
{
    // Create a new node to put at the back of the queue
    struct Node *newNode = createNode(data);
    // If the queue is empty, make the new node the front and back, then return
    if (!q->front)
    {
        q->front = q->rear = newNode;
        return;
    } // otherwise, push the node at the back of the our queue - linked list
    q->rear->next = newNode;
    q->rear = newNode;
}

void dequeue(struct Queue *q)
{
    // Check if the queue is empty
    if (!q->front)
    {
        return;
    }
    // otherwise, shift the pointer to the front node to the next one
    struct Node *temp = q->front;
    q->front = q->front->next;
    // If we've reached the end of the queue, set rear and front to null - reset the queue
    if (q->front == NULL)
    {
        q->front = q->rear = NULL;
    }
    // Free memory for the deleted node to destroy it from the heap
    free(temp);
}

void printQueue(struct Queue *q)
{
    struct Node *temp = q->front;
    printf("The queue: ");
    while (q->front)
    {
        printf("%d ", q->front->data);
        q->front = q->front->next;
    }
    printf("\n");
}