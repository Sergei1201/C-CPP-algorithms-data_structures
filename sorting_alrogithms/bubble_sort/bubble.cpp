/* The bubble sorting algorithm implementation in C++*/
#include <iostream>

/* Function prototyping */

// Bubble sort function using an array
void bubbleSort(int arr[], int size);

// Print the sorted array
void printArray(int arr[], int size);

int main()
{
    // Create an array of integers for the sake of simplicity
    int arr1[] = {50, 25, 1, 99, 15, 2, 99, 30, 11, 9, 66};
    // Calculate the size of the array
    int size = sizeof(arr1) / sizeof(arr1[0]);
    // Invoke the bubble sort function
    bubbleSort(arr1, size);
    // Print the array
    printArray(arr1, size);
    return 0;
}

void bubbleSort(int arr[], int size)
{
    // Iterate to access each element of an array
    for (int step = 1; step < size; step++)
    {
        // Iterate to compare to adjacent element of the array
        for (int i = 0; i < size - step; i++)
        {
            /* Compare two adjacent elements of the array */
            // Make a temp variable to swap to adjacent elements of the array
            int temp;
            // If the previous element is greater than the next element, swap them
            if (arr[i] > arr[i + 1])
            {
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
    }
}

void printArray(int arr[], int size)
{
    std::cout << "The sorted array: ";
    // Iterate through the array and print its values on each iteration
    for (int i = 0; i < size - 1; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}