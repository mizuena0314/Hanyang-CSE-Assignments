#include <stdio.h>

void addTotal(int n, int sum){
    if(n==0){
        printf("%d", sum);
        return;
    }
    addTotal(n-1, sum+n);
}

int main(){
    int n;
    scanf("%d", &n);
    addTotal(n,0);
}