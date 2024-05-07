#include <stdio.h>
int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low + 1;
    int j = high;
    int temp;
    do
    {
        while (arr[i] <= pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    } while (i < j);
    temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;
    return j;
}

void QuickSort(int arr[], int low, int high, int n)
{
    int partitionindex;
    if (low < high)
    {
        partitionindex = partition(arr, low, high);
        QuickSort(arr, low, partitionindex - 1, n);
        QuickSort(arr, partitionindex + 1, high, n);
    }
}

int PrintArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[50], n, i;
    printf("Enter the size of the array:");
    scanf("%d", &n);
    printf("Enter the elements in the array:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    PrintArray(arr, n);
    printf("The sorted array is:\n");
    QuickSort(arr, 0, n - 1, n);
    PrintArray(arr, n);
}