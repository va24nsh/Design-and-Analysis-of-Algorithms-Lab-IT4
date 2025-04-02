#include<stdio.h>

int power_a(int a, int n) {
    if(n == 0) {
        return 1;
    } else if (n % 2 == 0) {
        return power_a(a, n / 2) * power_a(a, n / 2);
    } else {
        return a * power_a(a, n-1);
    }
}

int main() {
    int n, a;
    printf("Enter a number: ");
    scanf("%d", &a);
    printf("Enter the power: ");
    scanf("%d", &n);
    int result = power_a(a, n);
    printf("%d^%d = %d\n", a, n, result);
    return 0;
}