#include <stdio.h>

const char* arr[3] = {"One", "Two", "Three"};

void printString(const char* str){
    printf("%s\n", str);
}

int main(){
    for(int i=0; i<3; i++){
        printString(arr[i]);
    }
}