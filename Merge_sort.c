#include <stdio.h>
void merge(int a[], int low, int mid, int high)
{
    int i, j, k, b[50];
    i = low;
    j = mid + 1;
    k = low;
    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            b[k] = a[i];
            i++;
            k++;
        }
        else
        {
            b[k] = a[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        b[k] = a[i];
        i++;
        k++;
    }
    while (j <= high)
    {
        b[k] = a[j];
        j++;
        k++;
    }
    for (int i = low; i <= high; i++)
    {
        a[i] = b[i];
    }
}

void mergesort(int a[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergesort(a, low, mid);
        mergesort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}

int printarray(int a[], int n)
{
    printf("The array is:-\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main()
{
    int a[50], n, i;
    printf("Enter the size of the array:");
    scanf("%d", &n);
    printf("Enter elements in the sorted array:-\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printarray(a, n);
    mergesort(a, 0, n - 1);
    printarray(a, n);
}