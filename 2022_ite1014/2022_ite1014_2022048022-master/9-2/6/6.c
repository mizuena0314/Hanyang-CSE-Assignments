#include <stdio.h>

int ncr(int n, int r){
    if(r==0 || r==n) return 1;
    return (ncr(n-1,r)+ncr(n-1,r-1));
}

int main(){
    int n,r;
    scanf("%d %d", &n, &r);
    printf("%d", ncr(n,r));
}