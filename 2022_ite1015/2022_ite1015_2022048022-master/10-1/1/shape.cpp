#include "shape.h"
#include <iostream>

Shape::Shape(double width, double height){
    _width = width;
    _height = height;
}

Shape::~Shape(){ /*std::cout << "del shape" << std::endl;*/ }

Triangle::Triangle(double width, double height):Shape(width, height){}

Triangle::~Triangle(){ /*std::cout << "del Tri" << std::endl;*/ }

double Triangle::getArea(){
    return (_width*_height)/2;
}

Rectangle::Rectangle(double width, double height):Shape(width, height){}

Rectangle::~Rectangle(){ /*std::cout << "del rect" << std::endl;*/ }

double Rectangle::getArea(){
    return (_width*_height);
}
