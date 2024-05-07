#include <stdio.h>
#include <stdlib.h>
int maximum(int a[], int n)
{
    int max;
    for (int i = 0; i < n; i++)
    {
        if (max < a[i])
        {
            max = a[i];
        }
    }
    return max;
}

void countsort(int a[], int n)
{
    int i, j;
    int max = maximum(a, n);
    int *count = (int *)malloc((max + 1) * sizeof(int));
    for (int i = 0; i < max + 1; i++)
    {
        count[i] = 0;
    }
    for (i = 0; i < n; i++)
    {
        count[a[i]] = count[a[i]] + 1;
    }
    i = 0;
    j = 0;
    while (i <= max)
    {
        if (count[i] > 0)
        {
            a[j] = i;
            count[i] = count[i] - 1;
            j++;
        }
        else
        {
            i++;
        }
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
    countsort(a, n);
    printarray(a, n);
}