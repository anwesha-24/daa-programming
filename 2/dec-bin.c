#include <stdio.h>
#include <stdlib.h>
void decimalToBinary(int decimal, FILE *outputFile) {
    if (decimal == 0) {
        return;
    }
    decimalToBinary(decimal / 2, outputFile);
    fprintf(outputFile, "%d", decimal % 2);
}
void convertNumbersToBinary(const char *inputFileName, const char *outputFileName, int n) {
    FILE *inputFile = fopen(inputFileName, "r");
    FILE *outputFile = fopen(outputFileName, "w");
    if (inputFile == NULL || outputFile == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    int decimal, count = 0;
    while (fscanf(inputFile, "%d", &decimal) == 1 && count < n) {
        decimalToBinary(decimal, outputFile);
        fprintf(outputFile, "\n");  
        count++;
    }
    fclose(inputFile);
    fclose(outputFile);
}
int main() {
    const char *inputFileName = "input.txt";
    const char *outputFileName = "output.txt";
    int n;
    printf("Enter the number of decimal numbers to convert: ");
    scanf("%d", &n);
    convertNumbersToBinary(inputFileName, outputFileName, n);
    printf("Conversion complete. Check the output file: %s\n", outputFileName);
    return 0;
}