#include <iostream>
#include "shapes.h"
using namespace std;

int main(){
    while(1){
        cout << "shape?" << endl;
        char inst;
        cin >> inst;
        if(inst=='Q'){
            return 0;
        }
        if(inst=='C'){
            double x, y, r;
            cin >> x >> y >> r;
            Circle c(x,y,r);
            cout << "area: " << c.area() << ", perimeter: " << c.perimeter() << endl;
        }
        if(inst=='R'){
            double x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            Rectangle r(x1, y1, x2, y2);
            cout << "area: " << r.area() << ", perimeter: " << r.perimeter() << endl;
        }
    }
}

