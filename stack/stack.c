/* Stack DSA implementation using arrays in C */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define const with a max number of elements in the array
#define MAX 5

// Define a global variable to store a count of elements in the array
int count = 0;

/* Stack struct */
struct Stack
{
    int items[MAX];
    int top;
};

/* Function forward declaration & prototyping */

// Check if the stack is empty
bool isEmpty(struct Stack *s);

// Check if the stack is full
bool isFull(struct Stack *s);

// Create an empty stack
void createEmptyStack(struct Stack *s);

// Push a new element onto the stack
void pushElement(struct Stack *s, int element);

// Pop an element from the top of the stack
void popElement(struct Stack *s);

// Print the stack
void printStack(struct Stack *s);

int main()
{
    // Dynamic memory allocation on the heap for a new stack
    struct Stack *st = (struct Stack *)malloc(sizeof(struct Stack));
    // Create an empty stack to get started with
    createEmptyStack(st);
    // Push
    pushElement(st, 5);
    pushElement(st, 10);
    pushElement(st, 20);
    pushElement(st, 25);
    pushElement(st, 35);
    // Print
    printStack(st);
    // Push one more element to make the stack full
    pushElement(st, 50);
    pushElement(st, 55);
    printStack(st);
    // Pop
    popElement(st);
    popElement(st);
    popElement(st);
    popElement(st);
    popElement(st);
    popElement(st);
    printStack(st);
}

/* Function definition */

bool isEmpty(struct Stack *s)
{
    // If the index of the top element is equal to -1, then the stack is empty
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
    // If the index of the top element of the array is equal to MAX - 1, then the stack is full
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
    // The stack is empty if the index of the top element is equal to -1
    s->top = -1;
}

void pushElement(struct Stack *s, int element)
{
    // If the stack is full, you can't add a new element onto it
    if (isFull(s))
    {
        printf("The stack is full!\n");
        return;
    } // otherwise increase the index of the current element of the array and assign it to a value that's passed in
    else
    {
        s->top++;
        s->items[s->top] = element;
    }
    // Increment the number of elements in the stack by 1
    count++;
}

void popElement(struct Stack *s)
{
    // If the stack is empty, there's nothing to pop
    if (isEmpty(s))
    {
        printf("The stack is empty!\n");
        return;
    } // otherwise return the popped element and decrement the top by 1
    else
    {
        printf("The popped element is %d\n ", s->items[s->top]);
        s->top--;
    }
    // Decrement the number of elements in the stack by 1
    count--;
}

void printStack(struct Stack *s)
{
    printf("The stack elements: ");
    for (int i = 0; i < count; i++)
    {
        printf("%d ", s->items[i]);
    }
    printf("\n");
}
