#include <stdio.h>

// Function to find the maximum of two integers
int max(int a, int b)
{
    return (a > b) ? a : b;
}

// Function to solve the 0/1 Knapsack problem
int knapsack(int maxWeight, int weights[], int values[], int numItems)
{
    int dp[numItems + 1][maxWeight + 1];
    for (int i = 0; i <= numItems; i++)
    {
        for (int w = 0; w <= maxWeight; w++)
        {
            if (i == 0 || w == 0)
            {
                dp[i][w] = 0;
            }
            else if (weights[i - 1] <= w)
            {
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            }
            else
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    return dp[numItems][maxWeight];
}

int main()
{
    int maxWeight, numItems;
    printf("Enter the maximum weight capacity of the knapsack: ");
    scanf("%d", &maxWeight);
    printf("Enter the number of items: ");
    scanf("%d", &numItems);
    int weights[numItems], values[numItems];
    printf("Enter the weight and value of each item:\n");
    for (int i = 0; i < numItems; i++)
    {
        printf("Item %d - Enter weight and value: ", i + 1);
        scanf("%d %d", &weights[i], &values[i]);
    }
    int maxValue = knapsack(maxWeight, weights, values, numItems);
    printf("The maximum value that can be put into the knapsack is: %d\n", maxValue);
    return 0;
}