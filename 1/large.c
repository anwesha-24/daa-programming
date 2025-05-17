#include<stdio.h>
int main() {
    int ar[] = {24, 56, 12, 9};
    int n = sizeof(ar) / sizeof(ar[0]);
    int max = ar[0]; 
    for(int i = 1; i < n; i++) { 
        if(ar[i] > max) {
            max = ar[i];
        }
    }
    printf("Maximum element in the array is: %d\n", max);
    return 0;
}
