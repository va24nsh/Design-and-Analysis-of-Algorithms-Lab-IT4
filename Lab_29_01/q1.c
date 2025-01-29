#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_SIZE 1000

int main() {
    int N;
    int arr[MAX_SIZE];
    int s_smallest = INT_MAX, smallest = INT_MAX;
    int s_largest = INT_MIN, largest = INT_MIN;
    FILE *file = fopen("numbers.txt", "r");

    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    printf("Enter the number of elements to read from file: ");
    scanf("%d", &N);

    if (N > MAX_SIZE) {
        printf("Wrong Input!\n");
        return 1;
    }

    // Loop to read from the file
    for (int i = 0; i < N; i++) {
        fscanf(file, "%d", &arr[i]);
    }
    fclose(file);

    // Loop to display content of the array and find second smallest and second largest
    printf("Contents of the array are: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", arr[i]);
        if (arr[i] > largest) {
            s_largest = largest;
            largest = arr[i];
        } else if (arr[i] > s_largest && arr[i] != largest) {
            s_largest = arr[i];
        }

        if (arr[i] < smallest) {
            s_smallest = smallest;
            smallest = arr[i];
        } else if (arr[i] < s_smallest && arr[i] != smallest) {
            s_smallest = arr[i];
        }
    }
    printf("\n");

    if (s_smallest == INT_MAX) {
        printf("Second smallest element not found. ");
    } else {
        printf("Second smallest: %d ", s_smallest);
    }

    if (s_largest == INT_MIN) {
        printf("Second largest element not found. ");
    } else {
        printf("Second largest: %d ", s_largest);
    }

    return 0;
}