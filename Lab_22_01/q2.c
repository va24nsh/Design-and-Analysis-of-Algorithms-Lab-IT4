// TC is O(n^3) because for n order we need to traverse the matrices and calculate the product at a place by traversing the row and column of the matrices respectively.
// For fixed n=10 TC will be constant O(1);
#include<stdio.h>
#include<time.h>
void multiplyMatrices(int firstMatrix[][10], int secondMatrix[][10], int result[][10], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = 0;
            for (int k = 0; k < n; k++) {
                result[i][j] += firstMatrix[i][k] * secondMatrix[k][j];
            }
        }
    }
}
void printMatrix(int matrix[][10], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n = 10;
    int firstMatrix[10][10], secondMatrix[10][10], result[10][10];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            firstMatrix[i][j] = 3*(i + j)/2;
            secondMatrix[i][j] = 2*(i - j);
        }
    }
    multiplyMatrices(firstMatrix, secondMatrix, result, n);
    printf("Result matrix:\n");
    printMatrix(result, n);
    return 0;
}