#include <iostream>
#include <cstdlib>
#include <vector>
#include "canvas.h"

using namespace std;

Canvas::Canvas(size_t row, size_t col){
    _width = row;
    _height = col;
    _grid.resize(_height, vector<char>(_width, '.'));
}

Canvas::~Canvas(){}

void Canvas::Resize(size_t w, size_t h){
    _grid.resize(h, vector<char>(w,'.'));
    for(int i=0; i<h; i++) _grid[i].resize(w, '.');

    _width = w;
    _height = h;

    /*
    cout << "h: " << _grid.size() << endl;
    cout << "w: " << _grid[0].size() << endl;
    */
}

bool Canvas::DrawPixel(int x, int y, char brush){
    if(x<0 || x>=_width || y<0 || y>=_height) return false;
    
    _grid[y][x]=brush;
    return true;
}

void Canvas::Print(){
    cout << " ";
    for(int i=0; i<_width; i++) cout << i%10;
    cout << endl;

    for(int i=0; i<_height; i++){
        cout << i%10;
        for(int j=0; j<_width; j++){
            cout << _grid[i][j];
        }
        cout << endl;
    }
}

void Canvas::Clear(){
    for(int i=0; i<_height; i++){
        for(int j=0; j<_width; j++){
            _grid[i][j]='.';
        }
    }
}

Shape::Shape(int peakX, int peakY, int width, int height, char brush){
    _peakX = peakX;
    _peakY = peakY;
    _width = width;
    _height = height;
    _brush = brush;
}

Shape::~Shape(){ /*cout << "Del shape" << endl;*/ }

Rectangle::Rectangle(int peakX, int peakY, int width, int height, char brush):
    Shape(peakX, peakY, width, height, brush){}

Rectangle::~Rectangle(){}

void Rectangle::Draw(Canvas* canvas){
    for(int i=_peakY; i<_peakY+_height; i++){
        for(int j=_peakX; j<_peakX+_width; j++){
            canvas->DrawPixel(j, i, _brush);
        }
    }
}

void Rectangle::getInfo(){
    cout << "rect " <<  _peakX << ' ' << _peakY << ' ' << _width << ' ' << _height << ' ' << _brush << endl;
}

Diamond::Diamond(int peakX, int peakY, int width, int height, char brush):
    Shape(peakX, peakY, width, height, brush){}

Diamond::~Diamond(){}

void Diamond::Draw(Canvas* canvas){
    int empty = 1;
    int diff = _width-2;
    int tempH = _height*2+1;
    int tempW = _width*2+1;

    for(int i=_peakY; i<=_peakY+tempH/2; i++){
        for(int j=_peakX+tempW/2-empty-1-diff; j<_peakX+tempH/2-empty+(2*empty-1)-1-diff; j++){
            canvas->DrawPixel(j, i, _brush);
        }
        empty++;
    }

    empty=1;

    for(int i=_peakY+tempH-1; i>=_peakY+tempH/2; i--){
        for(int j=_peakX+tempW/2-empty-1-diff; j<_peakX+tempH/2-empty+(2*empty-1)-1-diff; j++){
            canvas->DrawPixel(j, i, _brush);
        }
        empty++;
    }
}

void Diamond::getInfo(){
    cout << "diamond " <<  _peakX << ' ' << _peakY << ' ' << _width << ' ' << _brush << endl;
}


UpTriangle::UpTriangle(int peakX, int peakY, int width, int height, char brush):
    Shape(peakX, peakY, width, height, brush){}

UpTriangle::~UpTriangle(){}

void UpTriangle::Draw(Canvas* canvas){
    int empty = 1;
    int diff = _width-2;

    for(int i=_peakY; i<_peakY+_height; i++){
        for(int j=_peakX+_width-empty-1-diff; j<_peakX+_height-empty+(2*empty-1)-1-diff; j++){
            canvas->DrawPixel(j, i, _brush);
        }
        empty++;
    }
}

void UpTriangle::getInfo(){
    cout << "tri_up " <<  _peakX << ' ' << _peakY << ' ' << _height << ' ' << _brush << endl;
}

DownTriangle::DownTriangle(int peakX, int peakY, int width, int height, char brush):
    Shape(peakX, peakY, width, height, brush){}

DownTriangle::~DownTriangle(){}

void DownTriangle::Draw(Canvas* canvas){
    int empty = 1;
    int diff = _width-2;

    for(int i=_peakY; i>_peakY-_height; i--){
        for(int j=_peakX+_width-empty-1-diff; j<_peakX+_height-empty+(2*empty-1)-1-diff; j++){
            canvas->DrawPixel(j, i, _brush);
        }
        empty++;
    }
}

void DownTriangle::getInfo(){
    cout << "tri_down " <<  _peakX << ' ' << _peakY << ' ' << _height << ' ' << _brush << endl;
}
