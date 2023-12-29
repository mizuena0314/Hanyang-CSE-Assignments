#include "shapes.h"

Circle::Circle(double& x, double& y, double& r){
    this->x=x;
    this->y=y;
    this->r=r;
}

double Circle::area(){
    return 3.14*r*r;
}

double Circle::perimeter(){
    return 6.28*r;
}

Rectangle::Rectangle(double& x1, double& y1, double& x2, double& y2){
    this->x1=x1;
    this->y1=y1;
    this->x2=x2;
    this->y2=y2;
}

double Rectangle::area(){
    return abs(x2-x1)*abs(y2-y1);
}
        
double Rectangle::perimeter(){
     return 2*(abs(x2-x1)+abs(y2-y1));
}
