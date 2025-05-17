#include <stdio.h>

void computePrefixSum(int arr[], int prefixSum[], int n) {
    prefixSum[0] = arr[0]; 

    for (int i = 1; i < n; i++) {
        prefixSum[i] = prefixSum[i - 1] + arr[i];
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5}; 
    int n = sizeof(arr) / sizeof(arr[0]);
    int prefixSum[n];

    computePrefixSum(arr, prefixSum, n);

    printf("Prefix Sum array: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", prefixSum[i]);
    }
    printf("\n");

    return 0;
}
