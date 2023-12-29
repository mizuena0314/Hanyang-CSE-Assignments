#include <iostream>
#include <string>
#include "charlist.h"

using namespace std;

int main(){
    while(1){
        string s;
        cin >> s;
        if(s=="quit") return 0;
        CharList str(s.c_str());

        if(str.CheckPalindrome()){
            cout << "true" << endl;
        }
        else cout << "false" << endl;
    }
}
