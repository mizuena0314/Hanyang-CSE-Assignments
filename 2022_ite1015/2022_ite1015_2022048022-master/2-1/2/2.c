#include <stdio.h>

typedef struct
{
    int xpos;
    int ypos;
} Point;

Point getScale2xPoint(const Point* p){
    Point newp;
    newp.xpos = p->xpos*2;
    newp.ypos = p->ypos*2;
    return newp;
}

void swapPoints(Point* p1, Point* p2){
    Point temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main(void){
    Point p1, p2;

    scanf("%d %d", &p1.xpos, &p1.ypos);
    scanf("%d %d", &p2.xpos, &p2.ypos);

    printf("Calling getScale2xPoint()\n");
    p1=getScale2xPoint(&p1);
    p2=getScale2xPoint(&p2);
    printf("P1 : %d %d\n", p1.xpos, p1.ypos);
    printf("P2 : %d %d\n", p2.xpos, p2.ypos);

    printf("Calling swapPoint()\n");
    swapPoints(&p1,&p2);
    
    printf("P1 : %d %d\n", p1.xpos, p1.ypos);
    printf("P2 : %d %d\n", p2.xpos, p2.ypos);
}
