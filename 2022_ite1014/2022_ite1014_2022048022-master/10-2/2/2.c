#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main(){
    int *arr = (int*)malloc(5*sizeof(int));
    for(int i=0; i<5; i++){
        scanf("%d", arr+i);
    }
    for(int i=0; i<2; i++){
        swap(arr+i,arr+4-i);
    }
    for(int i=0; i<5; i++){
        printf("%d ", *(arr+i));
    }
}