#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_NODES 100

typedef struct Node {
    char data;
    int freq;
    struct Node *left, *right;
} Node;

typedef struct {
    Node *array[MAX_TREE_NODES];
    int size;
} MinHeap;

Node *newNode(char data, int freq) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->freq = freq;
    node->left = node->right = NULL;
    return node;
}

MinHeap *createMinHeap() {
    MinHeap *heap = (MinHeap *)malloc(sizeof(MinHeap));
    heap->size = 0;
    return heap;
}

void swapNodes(Node **a, Node **b) {
    Node *temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(MinHeap *heap, int idx) {
    int smallest = idx, left = 2 * idx + 1, right = 2 * idx + 2;
    if (left < heap->size && heap->array[left]->freq < heap->array[smallest]->freq)
        smallest = left;
    if (right < heap->size && heap->array[right]->freq < heap->array[smallest]->freq)
        smallest = right;
    if (smallest != idx) {
        swapNodes(&heap->array[idx], &heap->array[smallest]);
        minHeapify(heap, smallest);
    }
}

Node *extractMin(MinHeap *heap) {
    Node *temp = heap->array[0];
    heap->array[0] = heap->array[--heap->size];
    minHeapify(heap, 0);
    return temp;
}

void insertMinHeap(MinHeap *heap, Node *node) {
    int i = heap->size++;
    while (i && node->freq < heap->array[(i - 1) / 2]->freq) {
        heap->array[i] = heap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    heap->array[i] = node;
}

void buildMinHeap(MinHeap *heap) {
    for (int i = (heap->size - 2) / 2; i >= 0; i--)
        minHeapify(heap, i);
}

Node *buildHuffmanTree(char data[], int freq[], int size) {
    MinHeap *heap = createMinHeap();
    for (int i = 0; i < size; i++)
        heap->array[heap->size++] = newNode(data[i], freq[i]);

    buildMinHeap(heap);
    while (heap->size > 1) {
        Node *left = extractMin(heap);
        Node *right = extractMin(heap);
        Node *top = newNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        insertMinHeap(heap, top);
    }
    return extractMin(heap);
}

void printCodes(Node *root, char *code, int top, char huffmanCodes[128][20]) {
    if (root->left) {
        code[top] = '0';
        printCodes(root->left, code, top + 1, huffmanCodes);
    }
    if (root->right) {
        code[top] = '1';
        printCodes(root->right, code, top + 1, huffmanCodes);
    }
    if (!root->left && !root->right) {
        code[top] = '\0';
        strcpy(huffmanCodes[(int)root->data], code);
        printf("%c: %s\n", root->data, code);
    }
}

int main() {
    char input[] = "#ILOVENITJ#WELOVENITJ";
    int freq[128] = {0};

    for (int i = 0; i < strlen(input); i++)
        freq[(int)input[i]]++;

    char chars[20];
    int freqs[20], size = 0;

    for (int i = 0; i < 128; i++) {
        if (freq[i] > 0) {
            chars[size] = (char)i;
            freqs[size] = freq[i];
            size++;
        }
    }

    Node *root = buildHuffmanTree(chars, freqs, size);

    char code[20];
    char huffmanCodes[128][20] = {{0}};

    printf("Huffman Codes:\n");
    printCodes(root, code, 0, huffmanCodes);

    int totalBits = 0;
    for (int i = 0; i < strlen(input); i++)
        totalBits += strlen(huffmanCodes[(int)input[i]]);

    printf("Expected length of encoded message: %d bits\n", totalBits);

    return 0;
}
