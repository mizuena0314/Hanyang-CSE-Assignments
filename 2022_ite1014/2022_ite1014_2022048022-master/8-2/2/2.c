#include <stdio.h>

int main(){
    while(1){
        char ch;
        scanf(" %c", &ch);
        if(ch>='A' && ch<='Z'){
            printf("-> %c\n", ch+32);
        }
        else if(ch>='a' && ch<='z'){
            printf("-> %c\n", ch-32);
        }
        else if(ch>='0' && ch<='9'){
            printf("-> %c\n", ch);
        }
        else{
            printf("exit\n");
            return 0;
        }
    }
}