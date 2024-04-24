/* Bubble sort algorithm implementation in C++ using arrays */
#include <iostream>

/* Function declaration & prototyping */

// Bubble sorting algorithm
void bubbleSort(int arr[], int size);

// Print all the elements of the sorted array onto the screen
void printArray(int arr[], int size);

int main()
{
    // Create an array of integers
    int arr1[] = {10, 5, 1, 2, 99, 3, -10, -15, 20, 0};
    int size = sizeof(arr1) / sizeof(arr1[0]);
    // Invoke bubble sorting function
    bubbleSort(arr1, size);
    printArray(arr1, size);
    return 0;
}

/* Function definition */

void bubbleSort(int arr[], int size)
{
    // Iterate through the array from the beginning (we need to access each element of the array)
    for (int step = 1; step < size; step++)
    {
        // Iterate through the array and compare two adjacent element of the array along the way
        for (int i = 0; i < size - step; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                // Create a temp variable to perform swapping
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
    }
}

void printArray(int arr[], int size)
{
    std::cout << "The sorted array: ";
    // Iterate through the array till the end and print each value onto the screen
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}