#include <stdio.h>
#include <stdlib.h>
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <source file> <destination file>\n", argv[0]);
        return 1;
    }
    FILE *sourceFile = fopen(argv[1], "r");
    if (sourceFile == NULL) {
        perror("Error opening source file");
        return 1;
    }
    FILE *destFile = fopen(argv[2], "w");
    if (destFile == NULL) {
        perror("Error opening destination file");
        fclose(sourceFile);
        return 1;
    }
    int a, b;
    int count = 0;
    while (fscanf(sourceFile, "%d %d", &a, &b) == 2) {
        int result = gcd(a, b);
        fprintf(destFile, "GCD of %d and %d is %d\n", a, b, result);
        count++;
    }
    if (count < 20) {
        printf("The source file must contain at least 20 pairs of numbers.\n");
    } else {
        printf("GCDs computed and written to %s successfully.\n", argv[2]);
    }
    fclose(sourceFile);
    fclose(destFile);
    return 0;
}