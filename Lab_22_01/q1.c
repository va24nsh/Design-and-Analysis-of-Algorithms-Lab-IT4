// TC for each case
// case 1 - O(1)
// case 2 - O(1)
// case 3 - O(n)

#include<stdio.h>
#include<stdlib.h>

int findMaxCase1(int arr[], int n) {
    int max1 = arr[0];
    int max2 = arr[1];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max1) {
            max2 = max1;
            max1 = arr[i];
        } else if (arr[i] > max2 && arr[i] != max1) {
            max2 = arr[i];
        }
    }
    return max2;
} // Worst Case Time Complexity - O(n)

int findMaxCase2(int arr[], int n) {
    int max1 = arr[0];
    int max2 = arr[1];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max1) {
            max2 = max1;
            max1 = arr[i];
        } else if (arr[i] > max2 && arr[i] != max1) {
            max2 = arr[i];
        }
    }
    return max2;
} // Best Case Time Complexity - O(1)

int findMaxCase3(int arr[], int n) {
    int max1 = arr[0];
    int max2 = arr[1];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max1) {
            max2 = max1;
            max1 = arr[i];
        } else if (arr[i] > max2 && arr[i] != max1) {
            max2 = arr[i];
        }
    }
    return max2;
} // Average Case Time Complexity - O(n)

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    int arr[n];
    // Case 1
    for(int i=0; i<n; i++) {
        arr[i] = i;
    }
    printf("Second max in case 1: %d\n", findMaxCase1(arr, n));
    // Case 2
    for(int i=n; i>0; i--) {
        arr[n-i] = i;
    }
    printf("Second max in case 2: %d\n", findMaxCase2(arr, n));
    // Case 3
    for(int i=0; i<n; i++) {
        arr[i] = rand() % 100;
    }
    printf("Second max in case 3: %d\n", findMaxCase3(arr, n));
    return 0;
}