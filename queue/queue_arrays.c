/* Queue DSA implementation with arrays in C */
#include <stdio.h>
#include <stdbool.h>
/* Define constants - the max number of the elements of an array */
#define SIZE 5

/* Global variables */
int rear = -1;
int front = -1;
int queue[SIZE];

/* Function forward declaration & prototyping */

// Check if the queue is empty
bool isEmpty();

// Check if the queue if full
bool isFull();

// Enqueue
void enqueue(int data);

// Dequeue
int dequeue();

// Print the queue
void printQueue();

int main()
{
    enqueue(1);
    dequeue();
    dequeue();
    printQueue();

    return 0;
}

/* Function definition */

bool isEmpty()
{
    if (front == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isFull()
{
    if (front == 0 && rear == SIZE - 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void enqueue(int data)
{
    // Check if the queue is full
    if (isFull())
    {
        printf("The queue is full!\n");
        return;
    } // otherwise push a new element into the queue
    else
    {
        front = 0;
        rear++;
        queue[rear] = data;
        printf("Inserted element: %d ", data);
    }
}

int dequeue()
{
    int element;
    // Check if the queue is empty
    if (isEmpty())
    {
        printf("The queue is empty!\n");
        return (-1);
    }
    else
    {
        element = queue[front];
        printf("The popped element: %d ", element);
        front++;
    }
    // Check if the fron is equal or greater thant rear, reset the queue
    if (front >= rear)
    {
        front = -1;
        rear = -1;
    }
    return element;
}

void printQueue()
{
    printf("The queue: ");
    for (int i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }
    printf("\n");
}