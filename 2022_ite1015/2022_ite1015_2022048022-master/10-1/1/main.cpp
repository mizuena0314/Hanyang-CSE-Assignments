#include <iostream>
#include <cstdlib>
#include <vector>
#include "shape.h"

using namespace std;

int main(){
    vector<Shape*>arr;

    while(1){
        char type;
        cin >> type;
        if(type=='r'){
            double w,h;
            cin >> w >> h;
            arr.push_back(new Rectangle(w,h));
        }
        if(type=='t'){
            double w,h;
            cin >> w >> h;
            arr.push_back(new Triangle(w,h));
        }
        if(type=='0') break;
    }

    for(auto i:arr){
        cout << i->getArea() << endl;
        delete i;
    }
}
