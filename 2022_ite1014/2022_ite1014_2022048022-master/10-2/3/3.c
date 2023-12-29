#include <stdio.h>
#include <stdlib.h>

int main(){
    double sum = 0;
    double *arr = (double*)malloc(5*sizeof(double));
    for(int i=0; i<5; i++){
        scanf("%lf", arr+i);
    }
    double *parr = arr;
    for(int i=0; i<5; i++){
        sum += *(parr+i);
        printf("%lf\n", 2*(*(parr+i)));
    }
    printf("sum: %lf", 2*sum);
}