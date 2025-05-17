#include <stdio.h>
#include <stdlib.h>
void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void swap(int *a, int *b);
void displayArray(int arr[], int size);
int main() {
    int choice;
    int arr[100], n = 0;
    char inputFile[50], outputFile[50];
    FILE *inFile, *outFile;
    while (1) {
        printf("\n--- Quick Sort Menu ---\n");
        printf("1. Select Input File\n");
        printf("2. Sort and Save to Output File\n");
        printf("3. Display Sorted Array\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter input file name: ");
                scanf("%s", inputFile);
                inFile = fopen(inputFile, "r");
                if (inFile == NULL) {
                    printf("Error: Unable to open file %s\n", inputFile);
                    break;
                }
                n = 0;
                while (fscanf(inFile, "%d", &arr[n]) != EOF) {
                    n++;
                }
                fclose(inFile);
                printf("Successfully read %d elements from %s\n", n, inputFile);
                break;
            case 2:
                if (n == 0) {
                    printf("No elements to sort. Please select an input file first.\n");
                    break;
                }
                quickSort(arr, 0, n - 1);
                printf("Enter output file name: ");
                scanf("%s", outputFile);
                outFile = fopen(outputFile, "w");
                if (outFile == NULL) {
                    printf("Error: Unable to open file %s\n", outputFile);
                    break;
                }
                for (int i = 0; i < n; i++) {
                    fprintf(outFile, "%d\n", arr[i]);
                }
                fclose(outFile);
                printf("Sorted elements saved to %s\n", outputFile);
                break;
            case 3:
                if (n == 0) {
                    printf("No elements to display. Please select an input file and sort the elements first.\n");
                    break;
                }
                displayArray(arr, n);
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}
void displayArray(int arr[], int size) {
    printf("Sorted Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
