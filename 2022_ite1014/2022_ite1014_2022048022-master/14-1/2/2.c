#include <stdio.h>
#include <stdlib.h>

int min = 2000000000, max = -2000000000;

int main(){
    int n;
    scanf("%d", &n);
    int * arr = (int*)malloc(sizeof(int)*n);
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
        if(arr[i]<=min) min = arr[i];
        if(arr[i]>=max) max = arr[i];
    }
    printf("min: %d\n", min);
    printf("max: %d", max);
    free(arr);
}