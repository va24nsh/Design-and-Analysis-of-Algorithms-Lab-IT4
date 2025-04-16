#include <stdio.h>
#include <stdbool.h>

#define MAX 10

int board[MAX][MAX];
int n;

void printSolution()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

bool isSafe(int row, int col)
{
    for (int i = 0; i < col; i++)
    {
        if (board[row][i])
        {
            return false;
        }
    }

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j])
        {
            return false;
        }
    }

    for (int i = row, j = col; j >= 0 && i < n; i++, j--)
    {
        if (board[i][j])
        {
            return false;
        }
    }

    return true;
}

bool solveNQueens(int col)
{
    if (col >= n)
    {
        printSolution();
        return true;
    }

    bool res = false;
    for (int i = 0; i < n; i++)
    {
        if (isSafe(i, col))
        {
            board[i][col] = 1;

            res = solveNQueens(col + 1) || res;

            board[i][col] = 0;
        }
    }

    return res;
}

int main()
{
    printf("Enter the value of N (number of queens): ");
    scanf("%d", &n);

    if (n < 1 || n > MAX)
    {
        printf("Please enter a value between 1 and %d.\n", MAX);
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            board[i][j] = 0;
        }
    }

    if (!solveNQueens(0))
    {
        printf("No solution exists for %d queens.\n", n);
    }

    return 0;
}