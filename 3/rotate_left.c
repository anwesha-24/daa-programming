#include<stdio.h>
void EXCHANGE(int *p, int *q){
    int temp;
    temp = *p;
    *p = *q;
    *q = temp;
}
void ROTATE_LEFT(int *p1, int p2){
    if(p2<=0)
        return;
    int temp=p1[0];
    for(int i=0; i<p2-1; i++){
        EXCHANGE(&p1[i],&p1[i+1]);
    }
    p1[p2-1] = temp;
}
int main() {
    int arr[] = {1, 2};
    int p2 = 1; 
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("Original array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    ROTATE_LEFT(arr, p2);
    printf("Array after rotation: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}