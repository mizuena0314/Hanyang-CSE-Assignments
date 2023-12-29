#include <cstdio>
#include <iostream>

typedef struct

{
    double x;
    double y;
} Point;

typedef struct

{
    char name[7];
    Point points[3];
} Person;

int main(void){
    Person info[3];
    for(int i=0; i<3; i++){
        scanf("%s %lf %lf %lf %lf %lf %lf", info[i].name, &info[i].points[0].x, &info[i].points[0].y, &info[i].points[1].x, &info[i].points[1].y, &info[i].points[2].x, &info[i].points[2].y);
    }
    for(int i=0; i<3; i++){
        printf("%s (%lf %lf) (%lf %lf) (%lf %lf)\n", info[i].name, info[i].points[0].x, info[i].points[0].y, info[i].points[1].x, info[i].points[1].y, info[i].points[2].x, info[i].points[2].y);
    }
    return 0;
}
