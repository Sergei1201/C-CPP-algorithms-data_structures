/* Implementation of the selection sort alrogithm in C++ */

/* Strategy
1. We need to set the first element of the array as the minimum element
2. We should compare the min element with the next adjacent element. If the next element is less than the min, the next becomes the new min element. If the next element is not less than the min element, we do nothing, just go to the next element of the array.
3. We we've reached the end of the array, put the min element at the beginning of the array.
4. After each iteration we should start comparing our element with the next unsorted element.
5. The process goes on until all the elements are placed in the correct order
 */
#include <iostream>

/* Function prototyping & forward declaration */

// Declare the swap function
void swap(int *a, int *b);

// Selection sort function
void selectionSort(int arr[], int size);

// Print elements function
void printArray(int arr[], int size);

int main()
{
    // Define a new array
    int arr1[] = {50, 25, 3, 5, 100, 9, 0, 7};
    int size = sizeof(arr1) / sizeof(arr1[0]);
    std::cout << "The original array: ";
    for (int i = 0; i < size; i++)
    {
        std::cout << arr1[i] << " ";
    }
    std::cout << std::endl;
    // Invoke selection sort function
    selectionSort(arr1, size);
    printArray(arr1, size);
    return 0;
}

/* Function definition */

void swap(int *a, int *b)
{
    // Temp variable in order to swap to adjacent elements
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int arr[], int size)
{
    // Iterate throught all the elements of the array
    for (int step = 0; step < size - 1; step++)
    {
        // Define the minIndex variable
        int minIndex = step;
        for (int i = step + 1; i < size; i++)
        {
            // Compare the two adjacent elements starting from the beginning of the array. If the next element is less than the previous one, then the next is new min
            if (arr[i] > arr[minIndex])
            {
                minIndex = i;
            }
        }
        // Put the min element at the beginning of the array
        // Invoke the swap function
        swap(&arr[minIndex], &arr[step]);
    }
}

void printArray(int arr[], int size)
{
    // Iterate through each element of the array and print its values on each iteration
    std::cout << "The sorted array: ";
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    };
    std::cout << std::endl;
}