#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*

*/

typedef struct{
    char name[11];
    int score;
} Person;

void printScoreStars(Person* persons, int len){
    for(int i=0; i<len; i++){
        printf("%s \t", persons[i].name);
        int len = (persons[i].score)/5;
        for(int i=0; i<len; i++) printf("*");
        printf("\n");
    }
}

int main(){
    int cnt = 0;
    int memory = 0;
    Person* persons;
    Person* temp;
    while(1){
        char str[11];
        int scr;
        scanf("%s %d", str, &scr);
        if(strcmp(str,"END")==0 && scr==0){
            break;
        }
        if(cnt==0){
            memory += 1;
            persons = (Person*)malloc(sizeof(Person)*memory);
            strcpy(persons[0].name, str);
            persons[0].score=scr;
        }
        else{
            if(cnt==memory) memory *= 2;
            temp = (Person*)malloc(sizeof(Person)*(memory));
            for(int i=0; i<cnt; i++) temp[i]=persons[i];
            strcpy(temp[cnt].name, str);
            temp[cnt].score = scr;
            persons = temp;
        }
        cnt += 1;
    }
    printScoreStars(persons, cnt);
    free(temp);
    free(persons);
}