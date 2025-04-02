#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_HT 100

typedef struct HuffmanNode {
    char data;
    unsigned freq;
    struct HuffmanNode *left, *right;
} HuffmanNode;

typedef struct MinHeap {
    unsigned size;
    unsigned capacity;
    HuffmanNode** array;
} MinHeap;

HuffmanNode* newNode(char data, unsigned freq) {
    HuffmanNode* temp = (HuffmanNode*)malloc(sizeof(HuffmanNode));
    temp->left = temp->right = NULL;
    temp->data = data;
    temp->freq = freq;
    return temp;
}

MinHeap* createMinHeap(unsigned capacity) {
    MinHeap* minHeap = (MinHeap*)malloc(sizeof(MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (HuffmanNode**)malloc(minHeap->capacity * sizeof(HuffmanNode*));
    return minHeap;
}

void swapMinHeapNode(HuffmanNode** a, HuffmanNode** b) {
    HuffmanNode* t = *a;
    *a = *b;
    *b = t;
}

void minHeapify(MinHeap* minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq)
        smallest = left;

    if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq)
        smallest = right;

    if (smallest != idx) {
        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

HuffmanNode* extractMin(MinHeap* minHeap) {
    HuffmanNode* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    minHeap->size--;
    minHeapify(minHeap, 0);
    return temp;
}

void insertMinHeap(MinHeap* minHeap, HuffmanNode* node) {
    int i = minHeap->size++;
    while (i && node->freq < minHeap->array[(i - 1) / 2]->freq) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->array[i] = node;
}

HuffmanNode* buildHuffmanTree(char data[], int freq[], int size) {
    MinHeap* minHeap = createMinHeap(size);
    for (int i = 0; i < size; i++)
        minHeap->array[i] = newNode(data[i], freq[i]);
    
    minHeap->size = size;

    while (minHeap->size > 1) {
        HuffmanNode *left = extractMin(minHeap);
        HuffmanNode *right = extractMin(minHeap);
        HuffmanNode *top = newNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        insertMinHeap(minHeap, top);
    }
    return extractMin(minHeap);
}

void calculateHuffmanCodes(HuffmanNode* root, int arr[], int top, int freq[], int* totalBits) {
    if (root->left) {
        arr[top] = 0;
        calculateHuffmanCodes(root->left, arr, top + 1, freq, totalBits);
    }
    if (root->right) {
        arr[top] = 1;
        calculateHuffmanCodes(root->right, arr, top + 1, freq, totalBits);
    }
    if (!root->left && !root->right) {
        printf("Character: %c, Code: ", root->data);
        for (int i = 0; i < top; i++) {
            printf("%d", arr[i]);
        }
        printf("\n");
        *totalBits += freq[root->data] * top;
    }
}

int main() {
    char message[] = "summer courses";
    int freq[256] = {0};

    for (int i = 0; message[i] != '\0'; i++) {
        freq[(unsigned char)message[i]]++;
    }

    char data[256];
    int freqList[256];
    int size = 0;

    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            data[size] = i;
            freqList[size] = freq[i];
            size++;
        }
    }

    HuffmanNode* root = buildHuffmanTree(data, freqList, size);

    int arr[MAX_TREE_HT], totalBits = 0;
    printf("Huffman Codes:\n");
    calculateHuffmanCodes(root, arr, 0, freq, &totalBits);

    printf("\nTotal bits required to encode '%s': %d\n", message, totalBits);

    return 0;
}
