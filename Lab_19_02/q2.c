#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char data;
    int freq;
    struct Node *left, *right;
} Node;

Node* createNode(char data, int freq, Node* left, Node* right) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->freq = freq;
    node->left = left;
    node->right = right;
    return node;
}

void printCodes(Node* root, char* code, int depth) {
    if (!root) return;
    if (!root->left && !root->right) {
        code[depth] = '\0';
        printf("%c: %s\n", root->data, code);
    }
    code[depth] = '0';
    printCodes(root->left, code, depth + 1);
    code[depth] = '1';
    printCodes(root->right, code, depth + 1);
    
}

int main() {
    Node *a = createNode('a', 45, NULL, NULL);
    Node *b = createNode('b', 13, NULL, NULL);
    Node *c = createNode('c', 12, NULL, NULL);
    Node *d = createNode('d', 16, NULL, NULL);
    Node *e = createNode('e', 9, NULL, NULL);
    Node *f = createNode('f', 5, NULL, NULL);
    
    Node *n1 = createNode('$', 14, f, e);
    Node *n2 = createNode('$', 26, n1, d);
    Node *n3 = createNode('$', 25, c, b);
    Node *n4 = createNode('$', 51, n3, n2);
    Node *root = createNode('$', 96, a, n4);
    
    char code[10];
    printCodes(root, code, 0);
    return 0;
}