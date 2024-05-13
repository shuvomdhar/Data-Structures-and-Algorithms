#include<stdio.h>
int Insertion_Sort(int arr[],int n)
{
    for (int i = 1; i < n; i++)
    {
        int j;
        int key=arr[i];
        for (j = i-1; j>=0 && arr[j]<key; j--)
        {
            arr[j+1]=arr[j];
        }
        arr[j+1]=key;
    }
}

int printarray(int arr[],int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[50],n,i;
    printf("Enter the size of the array:");
    scanf("%d",&n);
    printf("Enter elements in the array:\n");
    for ( i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    printarray(arr,n);
    Insertion_Sort(arr,n);
    printarray(arr,n);
}