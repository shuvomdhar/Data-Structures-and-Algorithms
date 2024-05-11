#include <stdio.h>
#include <stdlib.h>
int minimum(int x, int y)
{
    if (x < y)
    {
        return x;
    }
    else
    {
        return y;
    }
}

int maximum(int x, int y)
{
    if (x > y)
    {
        return x;
    }
    else
    {
        return y;
    }
}

int *batcher_merge(int *U, int *V, int m, int n)
{
    int *S;
    if (m == 0 && n == 0)
    {
        return NULL;
    }
    else if (n == 0)
    {
        S = (int *)malloc(m * sizeof(int));
        for (int i = 0; i < m; i++)
        {
            S[i] = U[i];
        }
    }
    else if (m == 0)
    {
        S = (int *)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++)
        {
            S[i] = V[i];
        }
    }
    else if (m == 1 && n == 1)
    {
        S = (int *)malloc(2 * sizeof(int));
        S[0] = minimum(U[0], V[0]);
        S[1] = maximum(U[0], V[0]);
    }
    else
    {
        int *Ou = (int *)malloc(((m + 1) / 2) * sizeof(int));
        int k = 0;
        for (int i = 0; i < m; i = i + 2)
        {
            Ou[k++] = U[i];
        }
        int *Ov = (int *)malloc(((n + 1) / 2) * sizeof(int));
        k = 0;
        for (int i = 0; i < n; i = i + 2)
        {
            Ov[k++] = V[i];
        }
        int *A = batcher_merge(Ou, Ov, (m + 1) / 2, (n + 1) / 2);
        free(Ou);
        free(Ov);

        int *Eu = (int *)malloc((m / 2) * sizeof(int));
        k = 0;
        for (int i = 1; i < m; i = i + 2)
        {
            Eu[k++] = U[i];
        }
        int *Ev = (int *)malloc((n / 2) * sizeof(int));
        k = 0;
        for (int i = 1; i < n; i = i + 2)
        {
            Ev[k++] = V[i];
        }
        int *B = batcher_merge(Eu, Ev, (m / 2), (n / 2));
        free(Eu);
        free(Ev);

        int c;
        if ((m % 2 == 0) && (n % 2 == 0))
        {
            c = ((m / 2) + (n / 2)) - 1;
        }
        else
        {
            c = (m / 2) + (n / 2);
        }
        k = 0;
        S = (int *)malloc((m + n) * sizeof(int));
        S[k++] = A[0];
        for (int i = 1; i <= c; i++)
        {
            S[k++] = minimum(A[i], B[i - 1]);
            S[k++] = maximum(A[i], B[i - 1]);
        }
        if ((m % 2 == 0) && (n % 2 == 0))
        {
            S[k++] = B[(m / 2) + (n / 2) - 1];
        }
        else if ((m % 2 != 0) && (n % 2 != 0))
        {
            S[k++] = A[(m / 2) + (n / 2) + 1];
        }
        free(A);
        free(B);
    }
    return S;
}

int main()
{
    int size1, size2;
    printf("Enter the size of the first sorted array: ");
    scanf("%d", &size1);
    printf("Enter the elements of the first sorted array:\n");
    int *arr1 = (int *)malloc(size1 * sizeof(int));
    for (int i = 0; i < size1; i++)
    {
        scanf("%d", &arr1[i]);
    }
    printf("Enter the size of the second sorted array: ");
    scanf("%d", &size2);
    printf("Enter the elements of the second sorted array:\n");
    int *arr2 = (int *)malloc(size2 * sizeof(int));
    for (int i = 0; i < size2; i++)
    {
        scanf("%d", &arr2[i]);
    }
    int *array = batcher_merge(arr1, arr2, size1, size2);
    printf("The sorted array is:\n");
    for (int i = 0; i < (size1 + size2); i++)
    {
        printf("%d ", array[i]);
    }
    free(arr1);
    free(arr2);
    free(array);
    return 0;
}