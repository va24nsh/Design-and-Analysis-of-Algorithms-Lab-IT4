#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

void countDuplicates(int arr[], int n, int *totalDuplicates, int *mostRepeated) {
    int freq[MAX_SIZE] = {0};
    int maxCount = 0;

    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
        if (freq[arr[i]] > maxCount) {
            maxCount = freq[arr[i]];
            *mostRepeated = arr[i];
        }
    }
    *totalDuplicates = 0;
    for (int i = 0; i < MAX_SIZE; i++) {
        if (freq[i] > 1) {
            *totalDuplicates += (freq[i] - 1);
        }
    }
}

int main() {
    FILE *file = fopen("numbers.txt", "r");
    int n, arr[MAX_SIZE];
    int totalDuplicates, mostRepeated;
    
    if (!file) {
        printf("Error: Unable to open file.\n");
        return 1;
    }
    printf("Enter how many numbers you want to read from file: ");
    scanf("%d", &n);
    if(n>50) {
        printf("Please Enter something less than 50!");
        return 1;
    }
    // Loop to take input from the file
    for (int i = 0; i < n; i++) {
        fscanf(file, "%d", &arr[i]);
    }
    fclose(file);
    printf("The content of the array: ");
    // Loop to print the contents of the array
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    countDuplicates(arr, n, &totalDuplicates, &mostRepeated);

    printf("Total number of duplicate values = %d\n", totalDuplicates);
    printf("The most repeating element in the array = %d\n", mostRepeated);

    return 0;
}
