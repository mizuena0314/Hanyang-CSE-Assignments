#include <stdio.h>

int gMul=1;

int addTotal(int n){
    return (n*(n+1)/2);
}

void mulTotal(int n){
    n += 1;
    while(n-->1){
        gMul *= n;
    }
}

int main(){
    int n;
    scanf("%d", &n);
    printf("addTotal(): %d\n", addTotal(n));
    mulTotal(n);
    printf("gMul: %d\n", gMul);
}