#include<stdio.h>

int calculateUnderRoot(int n) {
    int root = 0;
    for(int i = 1; i <= n; i++) {
        if(i * i > n) {
            root = i - 1;
            break;
        }
    }
    return root;
}

int main() {
    int n;
    printf("Enter the number: ");
    scanf("%d", &n);
    int root = calculateUnderRoot(n);
    printf("The integer root of %d is %d\n", n, root);
    return 0;
}