#include <iostream>
#include <algorithm>
#include "message.h"

using namespace std;

MessageBook book;

int main(){
    while(1){
        int num; string inst;
        cin >> inst;
        if(inst=="add"){
            string message;
            cin >> num >> ws;
            getline(cin, message);
            book.AddMessage(num, message);
        }
        if(inst=="delete"){
            cin >> num;
            book.DeleteMessage(num);
        }
        if(inst=="print"){
            cin >> num;
            cout << book.GetMessage(num) << '\n' << endl;
        }
        if(inst=="list"){
            vector<int>tmp = book.GetNumbers();
            sort(tmp.begin(), tmp.end());
            for(int& i:tmp){
                cout << i << ": " <<  book.GetMessage(i) << endl;
            }
        }
        if(inst=="quit") return 0;
    }
}
