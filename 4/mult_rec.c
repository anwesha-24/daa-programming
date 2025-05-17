#include<stdio.h>
int func(int a, int b) {
    if (b == 0)
        return 0;
    else if (b == 1) {
        return a;
    }
    else if(b<0)
        return -func(a, -b);
    return a + func(a, b - 1);
}
int main(){
    int a, b;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    printf("Product of %d and %d is %d\n", a, b, func(a, b));
    return 0;
}