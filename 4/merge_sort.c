#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 500
int comparisons = 0;
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        comparisons++;
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
void readFile(const char *filename, int arr[], int *n) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Cannot open file %s\n", filename);
        exit(1);
    }
    *n = 0;
    while (fscanf(file, "%d", &arr[*n]) != EOF) {
        (*n)++;
    }

    fclose(file);
}
void writeFile(const char *filename, int arr[], int n) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: Cannot open file %s\n", filename);
        exit(1);
    }
    for (int i = 0; i < n; i++) {
        fprintf(file, "%d\n", arr[i]);
    }
    fclose(file);
}
void sortAndMeasure(const char *inFile, const char *outFile) {
    int arr[MAX], n;
    readFile(inFile, arr, &n);
    comparisons = 0;
    clock_t start = clock();
    mergeSort(arr, 0, n - 1);
    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Sorting completed.\n");
    printf("Number of comparisons: %d\n", comparisons);
    printf("Time taken: %f seconds\n", time_spent);
    writeFile(outFile, arr, n);
}
void displayMenu() {
    printf("\nMenu:\n");
    printf("1. Sort Ascending Order\n");
    printf("2. Sort Descending Order\n");
    printf("3. Sort Random Order\n");
    printf("4. Exit\n");
}
int main() {
    int choice;
    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                sortAndMeasure("inAsce.dat", "outMergeAsce.dat");
                break;
            case 2:
                sortAndMeasure("inDesc.dat", "outMergeDesc.dat");
                break;
            case 3:
                sortAndMeasure("inRand.dat", "outMergeRand.dat");
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}