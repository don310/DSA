#include <stdio.h>

void display(int arr[], int n)
{
    // Traversal
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", arr[i]);
    }
    printf("\n");
}

int indsortedInsertion(int arr[], int size, int element, int capacity, int index)
{
    if (size >= capacity)
    {
        return -1;
    }
    // Check if the new element should be inserted before the current element at the specified index
    if (element < arr[index])
    {
        for (int i = size - 1; i >= index; i--)
        {
            arr[i + 1] = arr[i];
        }
        arr[index] = element;
        return 1;
    }
    else
    {
        return -1;
    }
}

int main()
{
    int arr[100] = {7, 8, 12, 27, 88};
    int size = 5, element = 45, index = 3;
    display(arr, size);
    int result = indsortedInsertion(arr, size, element, 100, index);
    if (result == 1)
    {
        size += 1;
        display(arr, size);
    }
    else
    {
        printf("Insertion failed. Array is full or element is greater than all elements in the array.\n");
    }

    return 0;
}