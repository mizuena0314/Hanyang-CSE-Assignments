#include <stdio.h>
#include <stdbool.h>
#include <string.h>

char arr[11][25];

int main(){
    int idx = 0;
    while(1){
        char tmp[25];
        printf("Enter a word (Enter \'end\' to quit): ");
        scanf("%s", tmp);
        bool flg = false;
        if(strcmp(tmp, "end")==0){
            break;
        }
        for(int i=0; i<idx; i++){
            if(strcmp(arr[i],tmp)==0){
                flg = true;
                break;
            }
        }
        if(flg){
            printf("This word already exists. Please enter another word.\n");
            continue;
        }
        else{
            strcpy(arr[idx++],tmp);
        }
    }
    printf("%d words in the list\n", idx);
    for(int i=0; i<idx; i++){
        printf("%s ", arr[i]);
    }
    printf("\n");
    while(1){
        char tmp[25];
        printf("Enter a word to search (Enter \'end\' to quit): ");
        scanf("%s", tmp);
        bool flg = false;
        if(strcmp(tmp, "end")==0){
            break;
        }
        for(int i=0; i<idx; i++){
            if(strcmp(arr[i],tmp)==0){
                flg = true;
                break;
            }
        }
        if(flg){
            printf("This word is in the list.\n");
        }
        else{
            printf("This word is NOT in the list.\n");
        }
    }
}