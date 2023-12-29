#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include "my_string2.h"

using namespace std;

int main(){
    MyString2 a, b;
    vector<MyString2*> cs;
    bool status=0; //0 is copy 1 is operator
    while(1){
        string inst;
        getline(cin, inst);
        if(inst.substr(0,3)=="set"){
            if(inst.substr(4,inst.size())=="assign"){
                status = 1;
            }
            if(inst.substr(4,inst.size())=="copy"){
                status = 0;
            }
        }
        if(inst == "new"){
            cout << "enter a" << endl;
            cin >> a;

            cout << "enter b" << endl;
            cin >> b;
        }
        if(inst[5] == '+'){
            if(inst[3] == 'a' && inst[7]=='a'){
                if(status){
                    MyString2* newc = new MyString2;
                    cs.push_back(newc);
                    *cs[cs.size()-1] = a+a;
                }
                else{
                    MyString2 d(a+a);
                    MyString2* newc = new MyString2(d);
                    cs.push_back(newc);
                }
            }
            if(inst[3] == 'a' && inst[7]=='b'){
                if(status){ 
                    MyString2* newc = new MyString2;
                    cs.push_back(newc);
                    *cs[cs.size()-1] = a+b;
                }
                else{
                    MyString2 d(a+b);
                    MyString2* newc = new MyString2(d);
                    cs.push_back(newc);
                }
            }
            if(inst[3] == 'b' && inst[7]=='a'){
                if(status){
                    MyString2* newc = new MyString2;
                    cs.push_back(newc);
                    *cs[cs.size()-1] = b+a;
                }
                else{
                    MyString2 d(b+a);
                    MyString2* newc = new MyString2(d);
                    cs.push_back(newc);
                }
            }
            if(inst[3] == 'b' && inst[7]=='b'){
                if(status){
                    MyString2* newc = new MyString2;
                    cs.push_back(newc);
                    *cs[cs.size()-1] = b+b;
                }
                else{
                    MyString2 d(b+b);
                    MyString2* newc = new MyString2(d);
                    cs.push_back(newc);
                }
            }
        }
        if(inst[5] == '*'){
            int repeat = stoi(inst.substr(7,inst.size()));
            if(inst[3] == 'a'){
                if(status){
                    MyString2* newc = new MyString2;
                    cs.push_back(newc);
                    *cs[cs.size()-1] = a*repeat;
                }
                else{
                    MyString2 d(a*repeat);
                    MyString2* newc = new MyString2(d);
                    cs.push_back(newc);
                }
            }
            if(inst[3] == 'b'){
                if(status){
                    MyString2* newc = new MyString2;
                    cs.push_back(newc);
                    *cs[cs.size()-1] = b*repeat;
                }
                else{
                    MyString2 d(b*repeat);
                    MyString2* newc = new MyString2(d);
                    cs.push_back(newc);
                }
            }
        }
        if(inst.substr(0,5)=="print"){
            if(inst[6]=='a') cout << a;
            if(inst[6]=='b') cout << b;
            if(inst[6]=='c') {
                if(!cs.empty())cout << *cs[cs.size()-1];
                else cout << endl;
            }
        }
        if(inst == "quit"){
            for(auto i:cs) delete i;
            return 0;
        }
    }
}
