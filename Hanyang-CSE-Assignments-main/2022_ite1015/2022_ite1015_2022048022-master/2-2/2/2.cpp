#include <cstdio>
#include <cmath>

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

Point origin={0,0};

Point ans[3];

double dist(Point* p1, Point* p2){
    double diff1 = (p1->x)-(p2->x);
    double diff2 = (p1->y)-(p2->y);
    return(sqrt(diff1*diff1+diff2*diff2));
}

int main(void){
    Person info[3];
    for(int i=0; i<3; i++){
        scanf("%s %lf %lf %lf %lf %lf %lf", info[i].name, &info[i].points[0].x, &info[i].points[0].y, &info[i].points[1].x, &info[i].points[1].y, &info[i].points[2].x, &info[i].points[2].y);
    }
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(j==0 || dist(&info[i].points[j],&origin)>dist(&ans[i],&origin)){
                ans[i] = info[i].points[j];
            }
        }
    }
    for(int i=0; i<3; i++){
        printf("%s (%lf %lf)\n", info[i].name, ans[i].x, ans[i].y);
    }
    return 0;
}
