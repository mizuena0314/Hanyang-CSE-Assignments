#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int xpos;
    int ypos;
} Point;

int main(){
    Point *pt = (Point*)malloc(sizeof(Point));
    scanf("%d %d", (&(pt->xpos)), (&(pt->ypos)));
    printf("%d %d", (pt->xpos), (pt->ypos));
    free(pt);
}
