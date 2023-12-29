#include <stdio.h>

void square(double* pd){
    (*pd) *= (*pd);
}

int main(){
    double dvar;
    scanf("%lf", &dvar);
    square(&dvar);
    printf("%lf", dvar);
}