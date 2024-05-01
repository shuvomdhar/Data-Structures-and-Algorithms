#include <stdio.h>
int binarysearch(int a[], int n, int key)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (a[mid] == key)
        {
            printf("%d found at index %d", key, mid);
            break;
        }
        else if (a[mid] > key)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
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
    int a[50], n, i, key;
    printf("Enter the size of the array:");
    scanf("%d", &n);
    printf("Enter elements in the array:-\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printarray(a, n);
    printf("Enter an element you want to search:");
    scanf("%d", &key);
    binarysearch(a, n, key);
}