#include <stdio.h>

int main(){
    char c[11];
    int len = 0;
    scanf("%s", c);
    while(c[len]){
        len++;
    }
    printf("%d", len);
}