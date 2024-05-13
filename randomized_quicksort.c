#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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
    printf("The array is:-\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void fill_random(int array[], int length, int max)
{
    for (int i = 0; i < length; i++)
    {
        array[i] = (rand() % max) + 1;
    }
}

int main()
{
    int size, length, max;
    srand(time(NULL));
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    printf("Enter the number from where you want to make the random number: ");
    scanf("%d", &length);
    printf("Enter the final number till what you want to generate the random number: ");
    scanf("%d", &max);
    int a[100], i;
    fill_random(a, length, max);
    for (i = 0; i < size; i++)
    {
        printf("a[%d]=%d\n", i, a[i]);
    }
    PrintArray(a, size);
    printf("The sorted array is:\n");
    QuickSort(a, 0, size - 1, size);
    PrintArray(a, size);
    return 0;
}