#include <stdio.h>

int sum, max=-2000000000, min=2000000000;

int main(){
    int arr[5];
    for(int i=0; i<5; i++){
        scanf("%d", &arr[i]);
        if(arr[i]>=max) max=arr[i];
        if(arr[i]<=min) min=arr[i];
        sum += arr[i];
    }
    printf("min: %d\n", min);
    printf("max: %d\n", max);
    printf("sum: %d\n", sum);
}