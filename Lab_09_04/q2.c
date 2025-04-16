#include <stdio.h>
#include <string.h>
#define INT_MAX 999999

int mc[50][50];
int split[50][50];

int min(int a, int b) {
    return (a < b) ? a : b;
}

int DynamicProgramming(int c[], int i, int j) {
    if (i == j) {
        return 0;
    }
    if (mc[i][j] != -1) {
        return mc[i][j];
    }
    mc[i][j] = INT_MAX;
    for (int k = i; k < j; k++) {
        int cost = DynamicProgramming(c, i, k) + DynamicProgramming(c, k + 1, j) + c[i - 1] * c[k] * c[j];
        if (cost < mc[i][j]) {
            mc[i][j] = cost;
            split[i][j] = k;
        }
    }
    return mc[i][j];
}

void printParenthesis(int i, int j) {
    if (i == j) {
        printf("M%d", i);
    } else {
        printf("(");
        printParenthesis(i, split[i][j]);
        printParenthesis(split[i][j] + 1, j);
        printf(")");
    }
}

int Matrix(int c[], int n) {
    int i = 1, j = n - 1;
    return DynamicProgramming(c, i, j);
}

int main() {
    int arr[] = {40, 20, 30, 10, 30};
    int n = sizeof(arr) / sizeof(arr[0]);
    memset(mc, -1, sizeof(mc));
    memset(split, -1, sizeof(split));

    int minCost = Matrix(arr, n);
    printf("Minimum number of multiplications is: %d\n", minCost);
    printf("Optimal parenthesization is: ");
    printParenthesis(1, n - 1);
    printf("\n");
    return 0;
}