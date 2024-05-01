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

int insertArray(int arr[], int size, int capacity, int element, int index)
{
    if (N <= size)
    {
        printf("Array Overflow !!!!!  You can't insert any element in the array\n");
    }
    else
    {
        // Array Insertion
        for (int i = size - 1; i >= index; i--)
        {
            arr[i + 1] = arr[i];
        }
        arr[index] = element;
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

    int element, index;
    printf("Enter the element you want to insert: ");
    scanf("%d", &element);
    printf("Enter the index: ");
    scanf("%d", &index);
    insertArray(arr, size, N, element, index);
    size += 1;
    printArray(arr, size);
    return 0;
}