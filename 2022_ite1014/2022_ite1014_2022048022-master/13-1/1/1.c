#include <stdio.h>

const double pi = 3.141592;

int main(){
    double r;
    scanf("%lf", &r);
    printf("Perimeter: %lf\n", 2*pi*r);
    printf("Area: %lf", pi*r*r);
}