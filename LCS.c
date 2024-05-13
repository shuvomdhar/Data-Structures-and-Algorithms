#include <stdio.h>
#include <string.h>
#define MAX 100

// Function to find the maximum of two integers
int max(int a, int b)
{
    return (a > b) ? a : b;
}

// Function to calculate the length of the Longest Common Subsequence
int longestCommonSubsequence(char *X, char *Y, int m, int n, char *LCS_string)
{
    int LCS[m + 1][n + 1];
    // Build the LCS array
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
            {
                LCS[i][j] = 0;
            }
            else if (X[i - 1] == Y[j - 1])
            {
                LCS[i][j] = LCS[i - 1][j - 1] + 1;
            }
            else
            {
                LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
            }
        }
    }

    // Finding the LCS string
    int index = LCS[m][n];
    LCS_string[index] = '\0';
    int i = m, j = n;
    while (i > 0 && j > 0)
    {
        if (X[i - 1] == Y[j - 1])
        {
            LCS_string[index - 1] = X[i - 1];
            i--;
            j--;
            index--;
        }
        else if (LCS[i - 1][j] > LCS[i][j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    return LCS[m][n];
}

int main()
{
    char X[MAX], Y[MAX], LCS_string[MAX];
    printf("Enter the first string: ");
    scanf("%s", X);
    printf("Enter the second string: ");
    scanf("%s", Y);
    int m = strlen(X);
    int n = strlen(Y);
    int length = longestCommonSubsequence(X, Y, m, n, LCS_string);
    printf("The length of the Longest Common Subsequence is: %d\n", length);
    printf("The Longest Common Subsequence is: %s\n", LCS_string);
    return 0;
}