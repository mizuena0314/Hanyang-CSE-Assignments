#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include "canvas.h"

using namespace std;

int canvasW, canvasH;
vector<Shape*>shapes;

int main(){
    cin >> canvasW >> canvasH;
    Canvas* canvas = new Canvas(canvasW, canvasH);
    canvas->Print();

    while(1){
        string inst;
        cin >> inst;
        if(inst == "quit"){
            for(auto i:shapes){
                delete i;
            }
            return 0;
        }

        if(inst == "draw"){
            canvas->Clear();
            for(auto i:shapes){
                i->Draw(canvas);
            }
            canvas->Print();
        }

        if(inst == "delete"){
            int idx;
            cin >> idx;
            if(!shapes.empty() && idx>=0 && idx<shapes.size()){
                delete shapes[idx];
                shapes.erase(shapes.begin()+idx);
            }
        }

        if(inst == "dump"){
            for(int i=0; i<shapes.size(); i++){
                cout << i << ' ';
                shapes[i]->getInfo();
            }
        }

        if(inst == "resize"){
            int newW, newH;
            cin >> newW >> newH;
            canvas->Resize(newW, newH);
        }

        if(inst == "add"){
            string type;
            cin >> type;
            if(type == "rect"){
                int x, y, w, h;
                char brush;
                cin >> x >> y >> w >> h >> brush;
                Shape* s = new Rectangle(x,y,w,h,brush);
                shapes.push_back(s);
            }

            if(type == "diamond"){
                int x, y, dist;
                char brush;
                cin >> x >> y >> dist >> brush;
                Shape* s = new Diamond(x,y,dist,dist,brush);
                shapes.push_back(s);
            }

            if(type == "tri_up"){
                int x, y, h;
                char brush;
                cin >> x >> y >> h >> brush;
                Shape* s = new UpTriangle(x,y,h,h,brush);
                shapes.push_back(s);
            }

            if(type == "tri_down"){
                int x, y, h;
                char brush;
                cin >> x >> y >> h >> brush;
                Shape* s = new DownTriangle(x,y,h,h,brush);
                shapes.push_back(s);
            }
        }
    }
}
