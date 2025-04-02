#include <stdio.h>

typedef struct {
    int rollNumber;
    float CGPA;
} Student;

void swap(Student* a, Student* b) {
    Student temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(Student heap[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && heap[left].CGPA > heap[largest].CGPA)
        largest = left;

    if (right < n && heap[right].CGPA > heap[largest].CGPA)
        largest = right;

    if (largest != i) {
        swap(&heap[i], &heap[largest]);
        heapify(heap, n, largest);
    }
}

void buildMaxHeap(Student heap[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(heap, n, i);
    }
}

void findHighLowCGPA(Student heap[], int n, Student* highest, Student* lowest) {
    *highest = heap[0];

    int startLeaf = n / 2;
    *lowest = heap[startLeaf];
    
    for (int i = startLeaf; i < n; i++) {
        if (heap[i].CGPA < lowest->CGPA) {
            *lowest = heap[i];
        }
    }
}

void sortStudents(Student heap[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (heap[j].CGPA < heap[j + 1].CGPA) {
                swap(&heap[j], &heap[j + 1]);
            }
        }
    }
}

void pairStudents(Student heap[], int n) {
    sortStudents(heap, n);

    printf("\nStudent Pairs (Highest CGPA paired with Lowest):\n");
    for (int i = 0; i < n / 2; i++) {
        printf("Roll No %d (CGPA: %.2f) <-> Roll No %d (CGPA: %.2f)\n",
               heap[i].rollNumber, heap[i].CGPA, heap[n - 1 - i].rollNumber, heap[n - 1 - i].CGPA);
    }
}

int main() {
    Student students[] = {
        {101, 9.5}, {102, 8.7}, {103, 8.9}, {104, 7.1}, {105, 7.4},
        {106, 8.2}, {107, 6.5}, {108, 5.9}, {109, 6.0}, {110, 9.0}
    };
    int n = sizeof(students) / sizeof(students[0]);

    buildMaxHeap(students, n);

    Student H, L;
    findHighLowCGPA(students, n, &H, &L);
    printf("Highest CGPA -> Roll No: %d, CGPA: %.2f\n", H.rollNumber, H.CGPA);
    printf("Lowest CGPA -> Roll No: %d, CGPA: %.2f\n", L.rollNumber, L.CGPA);

    pairStudents(students, n);

    return 0;
}
