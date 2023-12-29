#include <stdio.h>

int main(){
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if(a>=b && b>=c){
        printf("min: %d\n", c);
        printf("max: %d", a);
    }
    else if(a>=c && c>=b){
        printf("min: %d\n", b);
        printf("max: %d", a);
    }
    else if(b>=a && a>=c){
        printf("min: %d\n", c);
        printf("max: %d", b);
    }
    else if(b>=c && c>=a){
        printf("min: %d\n", a);
        printf("max: %d", b);
    }
    else if(c>=a && a>=b){
        printf("min: %d\n", b);
        printf("max: %d", c);
    }
    else if(c>=b && b>=a){
        printf("min: %d\n", a);
        printf("max: %d", c);
    }
}