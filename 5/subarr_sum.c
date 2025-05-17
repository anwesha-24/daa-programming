#include<stdio.h>
int maxSubarray(int arr[], int n){
    int max_so_far = arr[0];
    int current_max = arr[0];
    for (int i = 1; i < n; i++) {
        current_max = (arr[i] > current_max + arr[i])? arr[i] : current_max + arr[i];
        max_so_far = (current_max > max_so_far)? current_max : max_so_far;
    }
    return max_so_far;
}
int main(){
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int maxSum = maxSubarray(arr, n);
    printf("Maximum sum of a contiguous subarray: %d", maxSum);
    return 0;
}