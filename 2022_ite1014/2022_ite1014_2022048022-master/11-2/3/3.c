#include <stdio.h>
#include <string.h>

char str1[20];
int occur[200];

int main(){
    scanf("%s", str1);
    for(int i=0; i<(int)(strlen(str1)); i++){
        occur[str1[i]]++;
    }
    for(int i=0; i<200; i++){
        if(occur[i]){
            printf("\'%c\': %d\n", i, occur[i]);
        }
    }
}