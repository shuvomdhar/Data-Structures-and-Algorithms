#include <iostream>
#define N 4
using namespace std;

int board[N];
int col[N];
int ld[2 * N - 1];
int rd[2 * N - 1];

bool pq(int i)
{
    int j;
    for (j = 1; j <= N; j++)
    {
        if (col[j] == 0 && ld[i + N - j] == 0 && rd[i + j - 1] == 0)
        {
            board[i] = j;
            col[j] = 1, ld[i + N - j] = 1, rd[i + j - 1] = 1;
            if (i == N)
            {
                return true;
            }
            else if (pq(i + 1) == true)
            {
                return true;
            }
            board[i] = 0, col[j] = 0, ld[i + N - j] = 0, rd[i + j - 1] = 0;
        }
    }
    return false;
}

int main()
{
    int i;
    for (i = 0; i < N; i++)
    {
        board[i] = 0;
        col[i] = 0;
    }
    for (i = 1; i <= 2 * N - 1; i++)
    {
        ld[i] = 0;
        rd[i] = 0;
    }
    i = 1;
    bool val = pq(i++);
    cout<<"Board array is: ";
    for (i = 1; i <= N; i++)
    {
        cout << " " << board[i];
    }
    return 0;
}