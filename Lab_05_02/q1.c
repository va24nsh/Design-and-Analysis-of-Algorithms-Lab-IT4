#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void generateBestCase(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }
}

void generateWorstCase(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = n - i;
    }
}

void generateAverageCase(int arr[], int n) {
    srand(time(0));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }
}

int main() {
    int choice;
    do {
        printf("\n0. Quit\n");
        printf("1. Time Complexity to sort ascending of data for all Cases (Data Ascending, Data in Descending & Random Data) in Tabular form for values n=5000 to 50000, step=5000\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("\nSl.No.\tValue of n\tTime Complexity(Random Data)\tTime Complexity(Data in Ascending)\tTime Complexity(Data in Descending)\n");
            for (int i = 1, n = 5000; n <= 50000; i++, n += 5000) {
                int arr[n];
                clock_t start, end;
                double timeRandom, timeAscending, timeDescending;
                generateAverageCase(arr, n);
                start = clock();
                insertionSort(arr, n);
                end = clock();
                timeRandom = (double)(end - start);
                generateBestCase(arr, n);
                start = clock();
                insertionSort(arr, n);
                end = clock();
                timeAscending = (double)(end - start);
                generateWorstCase(arr, n);
                start = clock();
                insertionSort(arr, n);
                end = clock();
                timeDescending = (double)(end - start);
                printf("%d\t%d\t \t \t%lf\t \t \t%lf\t \t \t%lf\n", i, n, timeRandom, timeAscending, timeDescending);
            }
        }
    } while (choice != 0);
    return 0;
}
