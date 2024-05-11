#include <stdio.h>
#include <math.h>
void swap(int *m, int *n)
{
    int temp = *m;
    *m = *n;
    *n = temp;
}

void compare_interchange(int a[], int x, int y)
{
    if (a[x] > a[y])
    {
        swap(&a[x], &a[y]);
    }
}

int Batcher(int a[], int start, long int c, int gap)
{
    int x = gap * 2;
    if (x < c)
    {
        Batcher(a, start, c, x);
        Batcher(a, start + gap, c, x);
        for (int i = start + gap; i + gap < start + c; i = i + x)
        {
            compare_interchange(a, i, i + gap);
        }
    }
    else
    {
        compare_interchange(a, start, start + gap);
    }
}

void Bsort(int a[], int start, long int c)
{
    int mid;
    if (c > 1)
    {
        mid = c / 2;
        Bsort(a, start, mid);
        Bsort(a, mid + start, mid);
        Batcher(a, start, c, 1);
    }
}

void print_array(int a[], long int s)
{
    for (int i = 1; i <= s; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main()
{
    int n;
    printf("Enter a value which will be the power of 2: ");
    scanf("%d", &n);
    long int c = pow(2, n);
    printf("The size of the array is: %ld\n", c);
    int a[c];
    printf("Enter elements into the array:\n");
    for (int i = 1; i <= c; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("User input array is: ");
    print_array(a, c);
    Bsort(a, 1, c);
    printf("The sorted array is: ");
    print_array(a, c);
    return 0;
}