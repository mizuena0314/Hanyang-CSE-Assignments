#include <stdio.h>
#include <string.h>

char str1[22];
char str2[22];
char concat[22];

int main(){
    scanf("%s", str1);
    scanf("%s", str2);
    printf("str1: %s\n", str1);
    printf("str2: %s\n", str2);

    printf("length of str1: %llu\n", strlen(str1));
    printf("length of str2: %llu\n", strlen(str2));

    for(int i=0; i<=strlen(str1); i++){
        concat[i]=str1[i];
    }

    printf("str1+str2: %s\n", strncat(concat, str2, strlen(str2)));
    if(strcmp(str1, str2)==0){
        printf("same");
    }
    else printf("not same");
}