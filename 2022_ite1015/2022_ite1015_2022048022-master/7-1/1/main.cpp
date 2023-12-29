#include <iostream>
#include <string>
#include "sorted.h"
using namespace std;

SortedArray arr;

int main(){
    while(1){
        int pos;
        string s;
        cin >> s;
        if(atoi(s.c_str())){
           arr.AddNumber(stoi(s)) ;
        }
        else{
            if(s=="ascend"){
                vector<int>tmp = arr.GetSortedAscending();
                for(int &i:tmp){
                    cout << i << ' ';
                }
                cout << endl;
            }
            
            if(s=="descend"){
                vector<int>tmp = arr.GetSortedDescending();
                for(int &i:tmp){
                    cout << i << ' ';
                }
                cout << endl;
            }

            if(s=="max"){
                cout << arr.GetMax() << endl;
            }
            if(s=="min"){
                cout << arr.GetMin() << endl;
            }
            if(s=="quit") return 0;
        }
    }
}
