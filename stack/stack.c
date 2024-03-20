/* Implementation of the stack DSA using C-style arrays in the C programming language */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the MAX number of element in an array
#define MAX 6

// Global variables
int count = 0;

/* Stack struct */
struct Stack
{
    int items[MAX];
    int top;
};
typedef struct Stack st;

/* Function forward declaration & prototyping */

// Create an empty stack
void createEmtpyStack(st *s);

// Check if the stack is empty
bool isEmpty(st *s);

// Check if the stack is full
bool isFull(st *s);

// Push a new element into the stack
void pushElement(st *s, int data);

// Pop an element from the top of the stack
void popElement(st *s);

// Print the stack
void printStack(st *s);

int main()
{
    // Dynamic memory allocation for a new stack on the heap
    st *s = (st *)malloc(sizeof(st));
    createEmtpyStack(s);
    pushElement(s, 25);
    pushElement(s, 35);
    pushElement(s, 45);
    printStack(s);
    popElement(s);
    pushElement(s, 55);
    pushElement(s, 65);
    pushElement(s, 66);
    pushElement(s, 33);
    pushElement(s, 88);
    printStack(s);
    return 0;
}

/* Function definition */

void createEmtpyStack(st *s)
{
    s->top = -1;
}

bool isEmpty(st *s)
{
    if (s->top == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isFull(st *s)
{
    if (s->top == MAX - 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void pushElement(st *s, int data)
{
    // Check if the stack is full
    if (isFull(s))
    {
        printf("The stack is full\n");

        return;
    }
    else
    {
        s->top++;
        s->items[s->top] = data;
    }
    count++;
}

void popElement(st *s)
{
    // Check if the stack is empty
    if (isEmpty(s))
    {
        printf("The stack is empty\n");
        return;
    }
    else
    {
        printf("The popped item is %d\n ", s->items[s->top]);
        s->top--;
    }
    count--;
}

void printStack(st *s)
{
    printf("Stack elements: ");
    for (int i = 0; i < count; i++)
    {
        printf("%d ", s->items[i]);
    }
    printf("\n");
}