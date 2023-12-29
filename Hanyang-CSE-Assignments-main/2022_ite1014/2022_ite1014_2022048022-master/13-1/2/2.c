#include <stdio.h>

int arr[3][2];

int main(){
    for(int i=0; i<3; i++){
        for(int j=0; j<2; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    for(int i=0; i<3; i++){
        for(int j=0; j<2; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}