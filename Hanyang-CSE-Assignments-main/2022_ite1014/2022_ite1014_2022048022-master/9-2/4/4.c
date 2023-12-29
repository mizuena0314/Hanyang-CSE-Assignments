#include <stdio.h>

void printLine(int n){
    for(int i=1; i<=n; i++){
        printf("%d ", i);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        printLine(i);
        printf("\n");
    }
    for(int i=n; i>=1; i--){
        printLine(i);
        printf("\n");
    }
}