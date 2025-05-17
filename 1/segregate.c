#include<stdio.h>
int main(){
    int ar[]={34,45,75,24,8,23};
    int n=sizeof(ar)/sizeof(ar[0]);
    int even=0;
    int temp;
    for(int i=0;i<n;i++){
        if(ar[i]%2==0){
            temp=ar[i];
            ar[i]=ar[even];
            ar[even]=temp;
            even++;
        }
    }
    printf("Array after rearranging: ");
    for(int i=0;i<n;i++){
        printf("%d ",ar[i]);
    }
    return 0;
}