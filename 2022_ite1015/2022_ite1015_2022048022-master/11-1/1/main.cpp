#include <iostream>
#include <string>
#include <cstdlib>
#include "my_string.h"

using namespace std;

int main(){
    MyString a, b, c;
    while(1){
        string inst;
        getline(cin, inst);
        if(inst == "new"){
            cout << "enter a" << endl;
            cin >> a;
            cout << "enter b" << endl;
            cin >> b;
        }
        if(inst[5] == '+'){
            MyString s1,s2;
            if(inst[3]=='a') s1=a;
            else if(inst[3]=='b') s1 = b;

            if(inst[7]=='a') s2=a;
            else if(inst[7]=='b') s2 = b;

            c = s1+s2;
        }
        if(inst[5] == '*'){
            if(inst[3] == 'a'){
                c = a * stoi(inst.substr(7,inst.size()));
            }
            if(inst[3]=='b'){
                c = b * stoi(inst.substr(7,inst.size()));
            }
        }
        if(inst.substr(0,5)=="print"){
            if(inst[6]=='a') cout << a;
            if(inst[6]=='b') cout << b;
            if(inst[6]=='c') cout << c;
        }
        if(inst == "quit") return 0;
    }
}
