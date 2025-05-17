#include <stdio.h>
#include <stdlib.h>

// Structure for storing symbols
struct SYMBOL {
    char alphabet;
    int frequency;
    struct SYMBOL *left, *right;
};


struct SYMBOL* createNode(char alphabet, int frequency) {
    struct SYMBOL* newNode = (struct SYMBOL*)malloc(sizeof(struct SYMBOL));
    newNode->alphabet = alphabet;
    newNode->frequency = frequency;
    newNode->left = newNode->right = NULL;
    return newNode;
}


void findTwoMin(struct SYMBOL *arr[], int n, int *firstMin, int *secondMin) {
    *firstMin = -1;
    *secondMin = -1;

    for (int i = 0; i < n; i++) {
        if (arr[i] != NULL) {
            if (*firstMin == -1 || arr[i]->frequency < arr[*firstMin]->frequency) {
                *secondMin = *firstMin;
                *firstMin = i;
            } else if (*secondMin == -1 || arr[i]->frequency < arr[*secondMin]->frequency) {
                *secondMin = i;
            }
        }
    }
}


struct SYMBOL* buildHuffmanTree(struct SYMBOL *symbols[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int firstMin, secondMin;
        findTwoMin(symbols, n, &firstMin, &secondMin);

        struct SYMBOL* newNode = createNode('$', symbols[firstMin]->frequency + symbols[secondMin]->frequency);
        newNode->left = symbols[firstMin];
        newNode->right = symbols[secondMin];

        symbols[firstMin] = newNode;
        symbols[secondMin] = NULL;
    }


    for (int i = 0; i < n; i++) {
        if (symbols[i] != NULL) {
            return symbols[i];
        }
    }

    return NULL;
}

void inOrderTraversal(struct SYMBOL* root) {
    if (!root)
        return;

    inOrderTraversal(root->left);
    if (root->alphabet != '$')
        printf("%c ", root->alphabet);
    inOrderTraversal(root->right);
}

void main() {
    int n;

    printf("Enter the number of distinct alphabets: ");
    scanf("%d", &n);

    struct SYMBOL *symbols[n];

    printf("Enter the alphabets: ");
    for (int i = 0; i < n; i++) {
        char alphabet;
        scanf(" %c", &alphabet);
        symbols[i] = createNode(alphabet, 0);
    }

    printf("Enter their frequencies: ");
    for (int i = 0; i < n; i++) {
        int frequency;
        scanf("%d", &frequency);
        symbols[i]->frequency = frequency;
    }

    struct SYMBOL* root = buildHuffmanTree(symbols, n);

    printf("In-order traversal of the tree (Huffman): ");
    inOrderTraversal(root);
    printf("\n");
}
