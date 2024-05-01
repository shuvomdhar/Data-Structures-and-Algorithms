#include <stdio.h>
#define N 50
void printArray(int arr[], int n)
{
    // Array Traversal
    printf("The array is: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void deleteArray(int arr[], int size, int capacity, int index)
{
    if (index >= capacity || index < 0)
    {
        printf("Array Underflow !!!!!  You can't delete any element from the array\n");
    }
    else
    {
        // Array Deletion
        for (int i = index; i < size; i++)
        {
            arr[i] = arr[i + 1];
        }
    }
}

int main()
{
    int arr[N], size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    printf("Enter elements in the array:\n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    printArray(arr, size);

    int index;
    printf("Enter the index you want to delete:  ");
    scanf("%d", &index);
    deleteArray(arr, size, N, index);
    size -= 1;
    printArray(arr, size);
    return 0;
}