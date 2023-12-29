#pragma once

class Shape{
    public:
        Shape(double width, double height);
        virtual ~Shape();

        virtual double getArea() = 0;

    protected:
        double _width;
        double _height;
};

class Triangle:public Shape{
    public:
        Triangle(double width, double height);
        virtual ~Triangle();

        virtual double getArea();
};

class Rectangle:public Shape{
    public:
        Rectangle(double width, double height);
        virtual ~Rectangle();

        virtual double getArea();
};
