#include <stdio.h>

int main() {
    int n, i, j;

    printf("Array size: ");
    scanf("%d", &n);

    int array[n];

    printf("Enter elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    int totalDuplicates = 0;
    int mostRepeatingElement = array[0];
    int maxFreq = 0;

    for (i = 0; i < n; i++) {
        int curr = array[i];
        int freq = 0;

        for (j = 0; j < n; j++) {
            if (array[j] == curr) {
                freq++;
            }
        }

        if (freq > 1 && freq > maxFreq) {
            if (freq > maxFreq) {
                maxFreq = freq;
                mostRepeatingElement = curr;
            }
            totalDuplicates++;
        }
    }

    printf("No. of duplicate values = %d\n", totalDuplicates);
    printf("Most repeating element = %d\n", mostRepeatingElement);

    return 0;
}
