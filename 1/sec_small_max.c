#include <stdio.h>
#include <limits.h>

int main() {
    int ar[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(ar) / sizeof(ar[0]);
    int i;
    int max, second_max, min, second_min;

    if (n < 2) {
        printf("Array must have at least two elements\n");
        return 0;
    }

    max = second_max = INT_MIN;
    min = second_min = INT_MAX;

    for (i = 0; i < n; i++) {
        if (ar[i] > max) {
            second_max = max;
            max = ar[i];
        } else if (ar[i] > second_max && ar[i] != max) {
            second_max = ar[i];
        }

        if (ar[i] < min) {
            second_min = min;
            min = ar[i];
        } else if (ar[i] < second_min && ar[i] != min) {
            second_min = ar[i];
        }
    }

    if (second_max == INT_MIN || second_min == INT_MAX) {
        printf("There is no second largest or second smallest element\n");
    } else {
        printf("Second largest = %d\n", second_max);
        printf("Second smallest = %d\n", second_min);
    }

    return 0;
}
