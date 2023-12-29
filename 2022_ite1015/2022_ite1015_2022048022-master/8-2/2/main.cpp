#include <iostream>
#include "shapes.h"

using namespace std;

int canvasW, canvasH;

int main(){
    cin >> canvasW >> canvasH;
    while(1){
        string shape;
        cin >> shape;
        
        if(shape=="quit") return 0;

        if(shape=="rect"){
            int topx, topy, width, height;
            char brush;
            cin >> topx >> topy >> width >> height >> brush;
            Rectangle r(topx, topy, width, height, brush);
            r.Draw(canvasW, canvasH);
        }

        if(shape=="square"){
            int topx, topy, width;
            char brush;
            cin >> topx >> topy >> width >> brush;
            Square s(topx, topy, width, width, brush);
            s.Draw(canvasW, canvasH);
        }

        if(shape=="diamond"){
            int topx, topy, dist;
            char brush;
            cin >> topx >> topy >> dist >> brush;
            Diamond d(topx, topy, 2*dist+1, 2*dist+1, brush);
            d.Draw(canvasW, canvasH);
        }
    }
}
