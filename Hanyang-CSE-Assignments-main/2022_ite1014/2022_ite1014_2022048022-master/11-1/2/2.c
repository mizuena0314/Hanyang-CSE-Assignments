#include <stdio.h>
#include <ctype.h>

char str1[20];

int main(){
    scanf("%s", str1);
    int idx=0;
    while(str1[idx]){
        if(str1[idx]>='a' && str1[idx]<='z'){
            printf("%c", toupper(str1[idx]));
        }
        else if(str1[idx]>='A' && str1[idx]<='Z'){
            printf("%c", tolower(str1[idx]));
        }
        idx++;
    }
}