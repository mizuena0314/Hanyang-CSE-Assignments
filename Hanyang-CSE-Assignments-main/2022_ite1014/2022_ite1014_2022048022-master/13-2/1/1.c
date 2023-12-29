#include <stdio.h>

const char* arr[2]={"aaa", "bbb"};

void swap(const char* arr[]){
    const char* tmp = arr[0];
    arr[0]=arr[1];
    arr[1]=tmp;
}

void printArray(const char* arr[]){
    printf("Array [0]:%s, [1]:%s,\n", arr[0], arr[1]);
}

int main(){
    printArray(arr);
    swap(arr);
    printArray(arr);
}