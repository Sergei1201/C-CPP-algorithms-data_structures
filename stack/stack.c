/* Stack DSA implementation with arrays in C */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define a global const variable to figure out the size of an array
#define MAX 5

/* Stack struct */
struct Stack
{
    int items[MAX];
    int top;
};

// Global variable to count the number of elements in the stack
int count = 0;

/* Function forward declaration */

// Check if stack is empty
bool isEmpty(struct Stack *s);

// Check if stack is full
bool isFull(struct Stack *s);

// Create a new empty stack
void createEmptyStack(struct Stack *s);

// Pop the uppermost element of the stack
void popElement(struct Stack *s);

// Push an element to the top of the stack
void pushElement(struct Stack *s, int element);

// Print the stack
void printStack(struct Stack *s);

int main()
{
    // Dynamic memory allocation on the heap for a new stack
    struct Stack *s = (struct Stack *)malloc(sizeof(struct Stack));
    // Create an empty stack to get started with
    createEmptyStack(s);
    pushElement(s, 1);
    pushElement(s, 3);
    pushElement(s, 5);
    pushElement(s, 10);
    pushElement(s, 20);
    popElement(s);
    popElement(s);
    popElement(s);
    popElement(s);
    popElement(s);
    popElement(s);
    printStack(s);

    return 0;
}

/* Function definition */

bool isEmpty(struct Stack *s)
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

bool isFull(struct Stack *s)
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

void createEmptyStack(struct Stack *s)
{
    // The top element is zero
    s->top = -1;
}

void pushElement(struct Stack *s, int element)
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
        s->items[s->top] = element;
    }
    // Increment the size of the stack by 1
    count++;
}

void popElement(struct Stack *s)
{
    // Check if the stack is empty
    if (isEmpty(s))
    {
        printf("The stack is empty\n");
        return;
    }
    else
    {
        // Printing the popped element
        printf("The popped element is %d ", s->items[s->top]);
        // Decrease the current index of the array by 1
        s->top--;
    }
    // Decrement the size of the stack by 1
    count--;
}

void printStack(struct Stack *s)
{
    printf("The stack is: ");
    for (int i = 0; i < count; i++)
    {
        printf("%d ", s->items[i]);
    }
    printf("\n");
}