#include <iostream>
#include <cmath>
#include "shapes.h"

using namespace std;

Shape::Shape() {}

Shape::Shape(int topx, int topy, int width, int height, char brush){
    _topx = topx;
    _topy = topy;
    _width = width;
    _height = height;
    _brush = brush;
}

Rectangle::Rectangle(int topx, int topy, int width, int height, char brush):Shape(topx, topy, width, height, brush){}

Square::Square(int topx, int topy, int width, int height, char brush):Shape(topx, topy, width, height, brush){}

Diamond::Diamond(int topx, int topy, int width, int height, char brush):Shape(topx, topy, width, height, brush){}

double Rectangle::GetArea(){
    return ((double)(_width*_height));
}

double Square::GetArea(){
    return ((double)(_width*_height));
}

double Diamond::GetArea(){
    return (((double)(_width*_height))/(2.0f));
}

int Rectangle::GetPerimeter(){
    return 2*(_width+_height);
}

int Square::GetPerimeter(){
    return 4*_width;
}

int Diamond::GetPerimeter(){
    return 4*(_width/2+1);
}

void Rectangle::Draw(int canvas_width, int canvas_height){
    char grid[canvas_height][canvas_width];
    for(int i=0; i<canvas_height; i++){
        for(int j=0; j<canvas_width; j++){
            grid[i][j]='.';
        }
    }

    for(int i=_topy; i<_topy+_height; i++){
        for(int j=_topx; j<_topx+_width; j++){
           if(i<canvas_height && j<canvas_width) grid[i][j]=_brush;
        }
    }

    cout << "Area: " << GetArea() << endl;
    cout << "Perimeter: " << GetPerimeter() << endl;
    cout << " ";

    for(int i=0; i<canvas_width; i++) cout << i;
    cout << endl;

    for(int i=0; i<canvas_height; i++){
        cout << i;
        for(int j=0; j<canvas_width; j++){
            cout << grid[i][j];
        }
        cout << endl;
    }
}

void Square::Draw(int canvas_width, int canvas_height){
    char grid[canvas_height][canvas_width];
    for(int i=0; i<canvas_height; i++){
        for(int j=0; j<canvas_width; j++){
            grid[i][j]='.';
        }
    }

    for(int i=_topy; i<_topy+_height; i++){
        for(int j=_topx; j<_topx+_width; j++){
           if(i<canvas_height && j<canvas_width) grid[i][j]=_brush;
        }
    }

    cout << "Area: " << GetArea() << endl;
    cout << "Perimeter: " << GetPerimeter() << endl;
    cout << " ";

    for(int i=0; i<canvas_width; i++) cout << i;
    cout << endl;

    for(int i=0; i<canvas_height; i++){
        cout << i;
        for(int j=0; j<canvas_width; j++){
            cout << grid[i][j];
        }
        cout << endl;
    }
}

void Diamond::Draw(int canvas_width, int canvas_height){
    char grid[canvas_height][canvas_width];
    for(int i=0; i<canvas_height; i++){
        for(int j=0; j<canvas_width; j++){
            grid[i][j]='.';
        }
    }

    int empty=1;
    int diff = _width/2-2;
    for(int i=_topy; i<=_topy+_height/2; i++){
        for(int j=_topx-_width/2-1-diff; j<_topx+_height/2-empty-1-diff; j++){
            if(i<canvas_height && j<canvas_width && i>=0 && j>=0) grid[i][j]='.';
        }
        for(int j=_topx+_height/2-empty-1-diff; j<_topx+_height/2-empty+(2*empty-1)-1-diff; j++){
            if(i<canvas_height && j<canvas_width && i>=0 && j>=0){
                grid[i][j]=_brush;
                //cout << i << ' ' << j << endl;
            }
        }
        empty++;
    }
    empty=1;
    for(int i=_topy+_height-1; i>=_topy+_height/2; i--){
        for(int j=_topx-_width/2-1-diff; j<_topx+_height/2-empty-1-diff; j++){
            if(i<canvas_height && j<canvas_width && i>=0 && j>=0) grid[i][j]='.';
        }
        for(int j=_topx+_height/2-empty-1-diff; j<_topx+_height/2-empty+(2*empty-1)-1-diff; j++){
            if(i<canvas_height && j<canvas_width && i>=0 && j>=0){
                grid[i][j]=_brush;
                //cout << i << ' ' << j << endl;
            }
        }
        empty++;
    }

    cout << "Area: " << GetArea() << endl;
    cout << "Perimeter: " << GetPerimeter() << endl;
    cout << " ";

    for(int i=0; i<canvas_width; i++) cout << i;
    cout << endl;

    for(int i=0; i<canvas_height; i++){
        cout << i;
        for(int j=0; j<canvas_width; j++){
            cout << grid[i][j];
        }
        cout << endl;
    }
}
