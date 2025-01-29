#include<stdio.h>

int main() {
    int N;
    printf("Enter the value of N: ");
    scanf("%d", &N);
    int arr[N];
    int prefixSum[N];
    int cumulative = 0;
    // Loop to enter elements in the array
    for(int i=0; i<N; i++) {
        printf("Enter element %d : ", i+1);
        scanf("%d", &arr[i]);
    }
    // Loop to find the prefix sum of the array
    for(int i=0; i<N; i++) {
        cumulative += arr[i];
        prefixSum[i] = cumulative;
    }
    // Loop to print the array
    for(int i=0; i<N; i++) {
        printf("%d ", prefixSum[i]);
    }
    return 0;
}