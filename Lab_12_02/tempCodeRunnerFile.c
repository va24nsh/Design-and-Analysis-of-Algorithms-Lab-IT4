#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5000

long long quickSortComparisons = 0;

int partition(int arr[], int low, int high, long long *comparisons) {
    int pivot = arr[high]; 
    int i = (low - 1);

    for (int j = low; j < high; j++) {
        (*comparisons)++;
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

void quickSort(int arr[], int low, int high, long long *comparisons) {
    if (low < high) {
        int pi = partition(arr, low, high, comparisons);
        quickSort(arr, low, pi - 1, comparisons);
        quickSort(arr, pi + 1, high, comparisons);
    }
}

void shuffle(int arr[], int n) {
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void generateDatasets(int randArr[], int inc[], int dec[]) {
    for (int i = 0; i < SIZE; i++) {
        randArr[i] = i + 1;
        inc[i] = i + 1;
        dec[i] = SIZE - i;
    }
    shuffle(randArr, SIZE);
}

int main() {
    srand(time(NULL));

    int randArr[SIZE], inc[SIZE], dec[SIZE], arr[SIZE];

    generateDatasets(randArr, inc, dec);

    for (int i = 0; i < SIZE; i++) arr[i] = randArr[i];
    clock_t start = clock();
    quickSortComparisons = 0;
    quickSort(arr, 0, SIZE - 1, &quickSortComparisons);
    clock_t end = clock();
    printf("Quick Sort (Random): Comparisons = %lld, Time = %lf sec\n", quickSortComparisons, (double)(end - start) / CLOCKS_PER_SEC);

    for (int i = 0; i < SIZE; i++) arr[i] = inc[i];
    start = clock();
    quickSortComparisons = 0;
    quickSort(arr, 0, SIZE - 1, &quickSortComparisons);
    end = clock();
    printf("Quick Sort (Increasing): Comparisons = %lld, Time = %lf sec\n", quickSortComparisons, (double)(end - start) / CLOCKS_PER_SEC);

    for (int i = 0; i < SIZE; i++) arr[i] = dec[i];
    start = clock();
    quickSortComparisons = 0;
    quickSort(arr, 0, SIZE - 1, &quickSortComparisons);
    end = clock();
    printf("Quick Sort (Decreasing): Comparisons = %lld, Time = %lf sec\n", quickSortComparisons, (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}
