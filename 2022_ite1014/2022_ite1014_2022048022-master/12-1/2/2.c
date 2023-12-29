#include <stdio.h>

struct person{
    char name[15];
    int age;
};

int main(){
    struct person p1;
    scanf("%s %d", p1.name, &p1.age);
    printf("name: %s\n", p1.name);
    printf("age: %d", p1.age);
}