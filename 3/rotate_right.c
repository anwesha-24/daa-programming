#include<stdio.h>
void EXCHANGE(int *p, int *q){
    int temp;
    temp = *p;
    *p = *q;
    *q = temp;
}
void ROTATE_RIGHT(int *p1, int p2){
    if(p2<=0)
        return;
    for(int i=p2-1; i>0; i--){
        EXCHANGE(&p1[i],&p1[i-1]);
    }
}
int main() {
    int size;
    printf("Enter size: ");
    scanf("%d", &size);
    int arr[size]; 
    printf("Enter elements: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Before rotation: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    int p2 = 1; 
    ROTATE_RIGHT(&arr, p2);
    printf("After rotation: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}