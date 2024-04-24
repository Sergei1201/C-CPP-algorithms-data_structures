# Implementing the bubble sort algorithm using Python

# Bubble sort function
def bubble_sort(array):
    # We need to iterate through each element of the list

    # Iteration through the list
    for i in range(len(array)):
        swapped = False

        # Compare two adjacent elements of the list and in the case the first one is greater thatn the second one, just swap them
        for j in range(len(array) - i - 1):
            if (array[j] > array[j+1]):
                temp = array[j]
                array[j] = array[j+1]
                array[j+1] = temp

                swapped = True
        # If the swappped is false, then we do not need to swap the two adjacent elements
        if not swapped:
            break


if __name__ == '__main__':
    # Define a list to get started with
    array1 = [50, 30, 20, 10, 5, 100, 25, 6]
    print(f'The original array: {array1}')
    bubble_sort(array1)
    print(f'The sorted array: {array1}')
