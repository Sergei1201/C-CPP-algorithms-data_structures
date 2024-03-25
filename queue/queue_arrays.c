/* Queue DSA implementation using arrays in C */
#include <stdio.h>
#include <stdbool.h>
/* Define constants */
#define SIZE 5

/* Global variables */
int queue[SIZE], front = -1, rear = -1;

/* Function prototyping*/

// Check if the queue is empty
bool isEmpty();

// Check if the queue is full
bool isFull();

// Enqueue
void enqueue(int data);

// Dequeue
int dequeue();

// Print queue
void printQueue();

int main()
{
    enqueue(1);
    enqueue(25);
    enqueue(-7);
    enqueue(100);
    enqueue(25);
    enqueue(300);
    printQueue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    printQueue();
    return 0;
}

/* Function definition */

bool isEmpty()
{
    // If the rear and front indices equal to -1, the queue is empty
    if (front == -1 && rear == -1)
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
    // If the front index equals to 0 and the rear index is equal to SIZE - 1, then the queue is full
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
    }
    else
    {
        // Push a new element at the back of the queue
        rear++;
        front = 0;
        queue[rear] = data;
    }
}

int dequeue()
{
    // Declare a local variable to store the popped element of the queue
    int element;
    // Check if the queue is empty
    if (isEmpty())
    {
        printf("The queue is empty!\n");
        return (-1);
    }
    else
    {
        // Pop out the first element of the queue and increment the index of the first element by 1
        element = queue[front];
        front++;
    }
    // If we've reached the end of the queue, reset the front and rear indices to -1
    if (front > rear)
    {
        front = rear = -1;
    }
    // Return the popped element
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