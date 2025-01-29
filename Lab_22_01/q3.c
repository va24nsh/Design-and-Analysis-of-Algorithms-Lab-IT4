// TC of the algorithm is :
// Case : 5 numbers only, O(log min(a, b)) 
// Case : n numbers, O(n * log min(a, b))
#include <stdio.h>
int gcd(int a, int b) {
    if(b == 0) {
        return a;
    }
    gcd(b, a%b);
} // Euclidian Approach

int findGCD(int arr[], int n) {
    int result = arr[0];
    for (int i = 1; i < n; i++) {
        result = gcd(result, arr[i]);
        if (result == 1) { // Early Return Handled when 2 numbers are have 1 GCD
            return 1;
        }
    }
    return result;
}

int main() {
    int arr[5];
    printf("Enter 5 numbers: ");
    for (int i = 0; i < 5; i++) {
        scanf("%d", &arr[i]);
    }
    int result = findGCD(arr, 5);
    printf("GCD of the 5 numbers is: %d\n", result);
    return 0;
}
