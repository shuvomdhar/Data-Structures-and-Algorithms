#include <stdio.h>
int linearsearch(int a[], int element)
{
    int i, n;
    for (i = 0; i < n; i++)
    {
        if (a[i] == element)
        {
            printf("%d found at index %d", element, i);
            break;
        }
        if(i==n)
        {
            printf("Element not found");
            break;
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
    int a[50], n, i, element;
    printf("Enter the size of the array:");
    scanf("%d", &n);
    printf("Enter elements in the array:-\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printarray(a, n);
    printf("Enter an element you want to search:");
    scanf("%d", &element);
    linearsearch(a, element);
}