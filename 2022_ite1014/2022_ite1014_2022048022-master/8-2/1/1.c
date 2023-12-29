#include <stdio.h>

int main(){
    float a=1.23456789, b=0.0000123456789;
    printf("%.10f %.10f\n", a, b);
    printf("%e %e\n", a, b);
    printf("%E %E\n", a, b);
    printf("%g %g\n", a, b);
    printf("%G %G\n", a, b);
}