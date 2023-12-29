#pragma once

#include <vector>

class Canvas {
    public:
        Canvas(size_t row, size_t col);
        ~Canvas();

        void Resize(size_t w, size_t h);

        bool DrawPixel(int x, int y, char brush);

        void Print();

        void Clear();

    private:
        int _width, _height;
        std::vector<std::vector<char> > _grid;
};

class Shape {
    public:
        Shape(int peakX, int peakY, int width, int height, char brush);
        virtual ~Shape();
        virtual void Draw(Canvas* canvas) {};
        virtual void getInfo() {};
    protected:
        int _peakX;
        int _peakY;
        int _width;
        int _height;
        char _brush;
};

class Rectangle : public Shape {
    public:
        Rectangle(int peakX, int peakY, int width, int height, char brush);
        virtual ~Rectangle();
        virtual void Draw(Canvas* canvas);
        virtual void getInfo();
};

class Diamond : public Shape {
    public:
        Diamond(int peakX, int peakY, int width, int height, char brush);
        virtual ~Diamond();
        virtual void Draw(Canvas* canvas);
        virtual void getInfo();
};

class UpTriangle : public Shape {
    public:
        UpTriangle(int peakX, int peakY, int width, int height, char brush);
        virtual ~UpTriangle();
        virtual void Draw(Canvas* canvas);
        virtual void getInfo();
};

class DownTriangle : public Shape {
    public:
        DownTriangle(int peakX, int peakY, int width, int height, char brush);
        virtual ~DownTriangle();
        virtual void Draw(Canvas* canvas);
        virtual void getInfo();
};
