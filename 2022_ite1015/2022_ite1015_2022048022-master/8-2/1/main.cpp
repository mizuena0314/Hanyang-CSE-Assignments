#include <iostream>
#include "rect.h"
using namespace std;

int main(){
    while(1){
        string shape;
        cin >> shape;
        if(shape=="quit") return 0;

        if(shape=="nonsquare"){
            int w, h;
            cin >> w >> h;
            NonSquare ns(w, h);
            ns.print();
        }

        if(shape=="square"){
            int l;
            cin >> l;
            Square s(l);
            s.print();
        }
    }
}
