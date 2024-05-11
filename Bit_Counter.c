#include <stdio.h>
#include <math.h>

void Counter(int a[], int k)
{
    int n = pow(2, k);
    while (n > 1)
    {
        int i = k - 1;
        while (i < k && a[i] == 1)
        {
            a[i] = 0;
            i = i - 1;
        }
        if (i < k)
        {
            a[i] = 1;
        }
        for (int i = 0; i < k; i++)
        {
            printf("%d ", a[i]);
        }
        printf("\n");
        n--;
    }
}

int main()
{
    int a[100], k;
    printf("Enter the number of bits you want to insert: ");
    scanf("%d", &k);
    printf("Enter 0 in the array:-\n");
    for (int i = 0; i < k; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("The bit-counter result:-\n");
    for (int i = 0; i < k; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    Counter(a, k);
    return 0;
}