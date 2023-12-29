#pragma once

class Shape {
    public:
        Shape();
        Shape(int topx, int topy, int width, int height, char brush);
        double GetArea() {};
        int GetPerimeter() {};
        void Draw(int canvas_width, int canvas_height) {};
    protected:
    // Define common properties for all shape types
        char _brush;
        int _topx;
        int _topy;
        int _width;
        int _height;
};

class Rectangle:public Shape{
    public:
        Rectangle(int topx, int topy, int width, int height, char brush);
        double GetArea();
        int GetPerimeter();
        void Draw(int canvas_width, int canvas_height);
};

class Square:public Shape{
    public:
        Square(int topx, int topy, int width, int height, char brush);
        double GetArea();
        int GetPerimeter();
        void Draw(int canvas_width, int canvas_height);
};

class Diamond:public Shape{
    public:
        Diamond(int topx, int topy, int width, int height, char brush);
        double GetArea();
        int GetPerimeter();
        void Draw(int canvas_width, int canvas_height);
};
