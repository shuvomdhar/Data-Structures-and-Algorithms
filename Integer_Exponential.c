#include<stdio.h>
#include<math.h>
int integer_exponential(int x, int n)
{
    if (n == 0)
    {
        return 1;
    }
    else if (n % 2 == 0)
    {
        int y = integer_exponential(x, n / 2);
        return y * y;
    }
    else
    {
        return  x * integer_exponential(x, n - 1);
    }
}

int main()
{
    int x, n;
    printf("Enter the base number: ");
    scanf("%d", &x);
    printf("Enter the exponential number: ");
    scanf("%d", &n);
    int val = integer_exponential(x, n);
    printf("The answer is %d",val);
}