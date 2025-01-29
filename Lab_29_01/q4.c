#include<stdio.h>

void EXCHANGE(int *p, int *q) {
    int temp = *p;
    *p = *q;
    *q = temp;
}

void ROTATE_RIGHT(int *p1, int p2) {
    for(int i=p2-1; i>0; i--){
        EXCHANGE(&p1[i], &p1[i-1]);
    }
}

int main() {
    int N, x; // x is the number of elements to be rotated
    printf("Enter the value of N: ");
    scanf("%d", &N);
    int A[N];
    // Loop to enter elements in the array
    for(int i=0; i<N; i++) {
        printf("Enter element %d : ", i+1);
        scanf("%d", &A[i]);
    }
    printf("Enter the value of x : ");
    scanf("%d", &x);
    ROTATE_RIGHT(A, x);
    // Loop to display the elements of the array
    for(int i=0; i<N; i++) {
        printf("%d ", A[i]);
    }
    return 0;
}