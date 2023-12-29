#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include "my_vector.h"

using namespace std;

int main(){
    MyVector a, b, c;
    while(1){
        string inst;
        cin >> inst;
        if(inst == "new"){
            int len;
            cin >> len;
            a = MyVector(len);
            b = MyVector(len);
            //
            cout << "enter a" << endl;
            cin >> a;
            cout << "enter b" << endl;
            cin >> b;
            //
        }
        //
        c = a + b;
        cout << c;
        //


        if(inst == "quit"){
            return 0;
        }
    }
}
