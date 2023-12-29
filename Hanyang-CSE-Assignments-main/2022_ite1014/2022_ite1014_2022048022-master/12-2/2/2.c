#include <stdio.h>

typedef struct{
    char name[7];
    int score;
} Person;

int main(){
    Person p[3];
    for(int i=0; i<3; i++){
        scanf("%s %d", p[i].name, &p[i].score);
    }
    for(int i=0; i<3; i++){
        printf("%s ", p[i].name);
        for(int j=5; j<=p[i].score; j+=5){
            printf("*");
        }
        printf("\n");
    }
}