#include <iostream>
#include "number.h"

using namespace std;

int main(){
    while(1){
        string inst;
        cin >> inst;
        if(inst == "number"){
            Number num;
            int n;
            cin >> n;
            num.setNumber(n);
            cout << "getNumber():" << num.getNumber() << endl;
        }
        
        if(inst == "square"){
            Square num;
            int n;
            cin >> n;
            num.setNumber(n);
            cout << "getNumber():" << num.getNumber() << endl;
            cout << "getSquare():" << num.getSquare() << endl;
        }

        if(inst == "cube"){
            Cube num;
            int n;
            cin >> n;
            num.setNumber(n);
            cout << "getNumber():" << num.getNumber() << endl;
            cout << "getSquare():" << num.getSquare() << endl;
            cout << "getCube():" << num.getCube() << endl;
        }

        if(inst == "quit") return 0;
    }
}
