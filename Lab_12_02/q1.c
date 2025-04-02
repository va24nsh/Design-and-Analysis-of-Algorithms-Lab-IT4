#include<stdio.h>
#include<time.h>

int binarySearch(int n, int arr[], int key) {
    int e = n-1;
    int s = 0;

    while(s <= e) {
        int mid = (e+s) / 2;
        if(arr[mid] == key) {
            return 1;
        } else if(arr[mid] > key) {
            e = mid - 1;
        } else {
            s = mid + 1;
        }
    }

    return 0;
}

int modifiedBinarySearch(int n, int arr[n], int key) {
    int e = n-1;
    int s = 0;

    while(s <= e) {
        int mid = e-2;
        if(mid < s) {
            mid = s;
        }
        if(arr[mid] == key) {
            return 1;
        } else if(arr[mid] > key) {
            e = mid - 1;
        } else {
            s = mid + 1;
        }
    }

    return 0;
}

int main() {
    int n, searchNumber;
    double tc1, tc2;

    printf("Enter the value of n: ");
    scanf("%d", &n);
    int arr[n];
    printf("Start entering array elements: \n");
    for(int i=0; i<n; i++) {
        printf("Enter element %d ", i+1);
        scanf("%d", &arr[i]);
    }
    
    printf("Enter the value of searchNumber: ");
    scanf("%d", &searchNumber);
    int keys[searchNumber];
    printf("Start entering keys: \n");
    for(int i=0; i<searchNumber; i++) {
        printf("Enter element %d ", i+1);
        scanf("%d", &keys[i]);
    }

    // searching keys
    int start = clock();
    printf("Searching elements in normal binary search: \n");
    for(int i=0; i<searchNumber; i++) {
        int found = binarySearch(n, arr, keys[i]);
        if(found) {
            printf("%d yes ", keys[i]);
        } else {
            printf("%d no ", keys[i]);
        }
    }
    int end = clock();
    tc1 = (double)(end-start);

    printf("\n");

    // searching keys in modified BS
    start = clock();
    printf("Searching elements in modified binary search: \n");
    for(int i=0; i<searchNumber; i++) {
        int found = modifiedBinarySearch(n, arr, keys[i]);
        if(found) {
            printf("%d yes ", keys[i]);
        } else {
            printf("%d no ", keys[i]);
        }
    }
    end = clock();
    tc2 = (double)(end - start);

    printf("\n");

    printf("%f is the time taken for normal binary search\n%f is the time taken in the modified binary search\n", tc1, tc2);
    return 0;
}