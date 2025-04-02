#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5000

long long mergeSortComparisons = 0, threeWayMergeComparisons = 0;

void merge(int arr[], int l, int m, int r, long long *comparisons) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int i = 0; i < n2; i++) R[i] = arr[m + 1 + i];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        (*comparisons)++;
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r, long long *comparisons) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m, comparisons);
        mergeSort(arr, m + 1, r, comparisons);
        merge(arr, l, m, r, comparisons);
    }
}

void threeWayMerge(int arr[], int l, int m1, int m2, int r, long long *comparisons) {
    int n1 = m1 - l + 1;
    int n2 = m2 - m1;
    int n3 = r - m2;
    int L[n1], M[n2], R[n3];

    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int i = 0; i < n2; i++) M[i] = arr[m1 + 1 + i];
    for (int i = 0; i < n3; i++) R[i] = arr[m2 + 1 + i];

    int i = 0, j = 0, k = 0, x = l;
    while (i < n1 || j < n2 || k < n3) {
        (*comparisons)++;
        int minVal = __INT_MAX__, minIdx = -1;
        if (i < n1 && L[i] < minVal) { minVal = L[i]; minIdx = 0; }
        if (j < n2 && M[j] < minVal) { minVal = M[j]; minIdx = 1; }
        if (k < n3 && R[k] < minVal) { minVal = R[k]; minIdx = 2; }

        if (minIdx == 0) arr[x++] = L[i++];
        else if (minIdx == 1) arr[x++] = M[j++];
        else if (minIdx == 2) arr[x++] = R[k++];
    }
}

void threeWayMergeSort(int arr[], int l, int r, long long *comparisons) {
    if (l < r) {
        int m1 = l + (r - l) / 3;
        int m2 = l + 2 * (r - l) / 3;
        threeWayMergeSort(arr, l, m1, comparisons);
        threeWayMergeSort(arr, m1 + 1, m2, comparisons);
        threeWayMergeSort(arr, m2 + 1, r, comparisons);
        threeWayMerge(arr, l, m1, m2, r, comparisons);
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

void generateDatasets(int inc[], int dec[]) {
    for (int i = 0; i < SIZE; i++) {
        inc[i] = i + 1;
        dec[i] = SIZE - i;
    }
    shuffle(inc, SIZE);
    shuffle(dec, SIZE);
}

int main() {
    srand(time(NULL));
    
    int inc[SIZE], dec[SIZE], arr1[SIZE], arr2[SIZE];
    
    generateDatasets(inc, dec);

    for (int i = 0; i < SIZE; i++) arr1[i] = inc[i];
    clock_t start = clock();
    mergeSort(arr1, 0, SIZE - 1, &mergeSortComparisons);
    clock_t end = clock();
    printf("Merge Sort (Increasing): Comparisons = %lld, Time = %lf sec\n", mergeSortComparisons, (double)(end - start) / CLOCKS_PER_SEC);

    for (int i = 0; i < SIZE; i++) arr2[i] = inc[i];
    start = clock();
    threeWayMergeSort(arr2, 0, SIZE - 1, &threeWayMergeComparisons);
    end = clock();
    printf("3-Way Merge Sort (Increasing): Comparisons = %lld, Time = %lf sec\n", threeWayMergeComparisons, (double)(end - start) / CLOCKS_PER_SEC);

    mergeSortComparisons = 0;
    threeWayMergeComparisons = 0;

    for (int i = 0; i < SIZE; i++) arr1[i] = dec[i];
    start = clock();
    mergeSort(arr1, 0, SIZE - 1, &mergeSortComparisons);
    end = clock();
    printf("Merge Sort (Decreasing): Comparisons = %lld, Time = %lf sec\n", mergeSortComparisons, (double)(end - start) / CLOCKS_PER_SEC);

    for (int i = 0; i < SIZE; i++) arr2[i] = dec[i];
    start = clock();
    threeWayMergeSort(arr2, 0, SIZE - 1, &threeWayMergeComparisons);
    end = clock();
    printf("3-Way Merge Sort (Decreasing): Comparisons = %lld, Time = %lf sec\n", threeWayMergeComparisons, (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}
