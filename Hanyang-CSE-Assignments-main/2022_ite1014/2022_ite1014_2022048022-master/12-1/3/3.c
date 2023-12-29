#include <stdio.h>

typedef struct{
    int xpos;
    int ypos;
} Point;

Point getScale2xPoint(Point p1){
    Point p2 = {p1.xpos*2, p1.ypos*2};
    return p2;
}

int main(){
    Point p1;
    scanf("%d %d", &p1.xpos, &p1.ypos);
    Point p2 = getScale2xPoint(p1);
    printf("%d %d", p2.xpos, p2.ypos);
}