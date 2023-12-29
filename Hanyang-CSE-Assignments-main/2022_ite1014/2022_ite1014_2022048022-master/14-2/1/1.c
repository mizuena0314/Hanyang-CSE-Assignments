#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
입력이 몇개 들어오는지 모름
배열 크기도 몰루

적어도 배열은 동적으로 선언

동적 할당 배열 -> 전역?

size를 유동적으로 업데이트

size만 변수로 따로 tracking해주고
바뀔때마다 동적할당

(2*n) ??? #의문점 1
-문제는 납득이 안가 설명이- 머리로는 이해되는데 마음이 납득을 못함

첫번째 입력 처리 #문제점 1
-> 예외처리
free를 해주는 시점 #문제점 2
-> probably when valid input is given in order
to  re malloc

(char**)malloc()
*/

int main(){
    int cnt = 0; // number of 
    int memory = 0;
    char** wordList;
    char** tempList;
    while(1){
        int flg = 0;
        char tmp[21];
        printf("Enter a word (Enter \'end\' to quit): ");
        scanf("%s", tmp);
        if(strcmp(tmp, "end")==0){
            break;
        }
        for(int i=0; i<cnt; i++){
            if(strcmp(tmp, wordList[i])==0){
                printf("This word already exists. Please enter another word.\n");
                flg = 1;
                break;
            }
        }
        if(flg) continue;
        if(cnt==0){
            memory += 1;
            wordList = (char**)malloc(sizeof(char*)*(memory));
            for (int i = 0; i < memory; i++) wordList[i] = (char*)malloc(sizeof(char) * (21));
            strcpy(wordList[0],tmp);
        }
        else{
            if(cnt==memory) memory *= 2;
            tempList = (char**)malloc(sizeof(char*)*(memory));
            for (int i = 0; i < memory; i++) tempList[i] = (char*)malloc(sizeof(char) * (21));
            for(int i=0; i<cnt; i++) strcpy(tempList[i],wordList[i]);
            strcpy(tempList[cnt],tmp);
            wordList = tempList;
        }
        cnt += 1;
    }
    printf("%d\n", cnt);
    for(int i=0; i<cnt; i++) printf("%s ", wordList[i]);
    printf("\n");
    while(1){
        int flg = 0;
        char tmp[21];
        printf("Enter a word to search (Enter \'end\' to quit): ");
        scanf("%s", tmp);
        if(strcmp(tmp, "end")==0){
            break;
        }
        for(int i=0; i<cnt; i++){
            if(strcmp(tmp, wordList[i])==0){
                printf("This word is in the list.\n");
                flg = 1;
                break;
            }
        }
        if(!flg) printf("This word is NOT in the list.\n");
    }
    free(wordList);
    free(tempList);
}