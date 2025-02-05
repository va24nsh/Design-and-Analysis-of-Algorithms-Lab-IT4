#include<stdio.h>

typedef struct Set {
    int arr[100];
    int size;
} Set;

void makeSet(int arr[], int n, Set *S) {
    S->size = n;
    for(int i = 0; i < n; i++) {
        S->arr[i] = arr[i];
    }
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(S->arr[i] > S->arr[j]) {
                int temp = S->arr[i];
                S->arr[i] = S->arr[j];
                S->arr[j] = temp;
            }
        }
    }
}

void insert(int x, Set *S) {
    int i=0;
    while(i < S->size && S->arr[i] < x) {
        i++;
    }
    for(int j = S->size; j > i; j--) {
        S->arr[j] = S->arr[j - 1];
    }
    S->arr[i] = x;
    S->size++;
}

void printSet(Set S) {
    for(int i = 0; i < S.size; i++) {
        printf("%d ", S.arr[i]);
    }
    printf("\n");
}

void removeSmallestHalf(Set S) {
    int n = S.size;
    for(int i = n/2; i < n ; i++) {
        printf("%d ", S.arr[i]);
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter distinct elements: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    // Print the elements in the input order
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    Set S;
    makeSet(arr, n, &S);
    printSet(S);
    int x;
    printf("Enter the element to insert: ");
    scanf("%d", &x);
    insert(x, &S);
    printSet(S);
    printf("The elements after removing smallest half are: ");
    removeSmallestHalf(S);
    return 0;
}
