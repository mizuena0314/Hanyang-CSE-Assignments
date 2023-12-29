#include <stdio.h>
#include <string.h>
#include <ctype.h>

char str1[15];

int main(){
    scanf("%s", str1);
    int idx1=0;
    int idx2=(int)(strlen(str1))-1;
    while(idx1<idx2){
        if(toupper(str1[idx1])!=toupper(str1[idx2])){
            printf("This is not a palindrome");
            return 0;
        }
        idx1++;
        idx2--;
    }
    printf("This is a palindrome");
}