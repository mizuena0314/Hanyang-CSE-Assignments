#pragma once
#include <cstdlib>

class Circle
{
    private:
        double x;
        double y;
        double r;
    public:
        Circle(double &x, double& y, double& r);
        double area();
        double perimeter();
};

class Rectangle
{
    private:
        double x1;
        double x2;
        double y1;
        double y2;
    public:
        Rectangle(double &x1, double& y1, double& x2, double& y2);
        double area();
        double perimeter();
};
