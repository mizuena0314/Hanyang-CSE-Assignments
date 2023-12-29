#include <stdio.h>

int add(int a, int b){
    return a+b;
}

int sub(int a, int b){
    return a-b;
}

int mul(int a, int b){
    return a*b;
}

double div(int a, int b){
    return ((double)(a)/(double)(b));
}

int mod(int a, int b){
    return a%b;
}

void printMsg(){
    printf("completed");
}

int main(){
    int n1,n2;
    scanf("%d",&n1);
    scanf("%d",&n2);
    printf("sum: %d\n", add(n1,n2));
    printf("difference: %d\n", sub(n1,n2));
    printf("product: %d\n", mul(n1,n2));
    printf("division: %.16f\n", div(n1,n2));
    printf("reaminder: %d\n", mod(n1,n2));
    printMsg();
}