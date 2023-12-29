#include <iostream>
#include "setfunc.h"

using namespace std;

int main(){
    while(1){
        string s;
        getline(cin, s);
        if(s=="0") return 0;

        string set1, set2;
        char inst;
        int cursor=0;
        while(cursor<s.size()){
            if(s[cursor]=='}'){
                set1+=s[cursor++];
                break;
            }
            set1+=s[cursor++];
        }
        inst = s[cursor+1];
        cursor+=3;

        while(cursor<s.size()){
            if(s[cursor]=='}'){
                set2+=s[cursor++];
                break;
            }
            set2+=s[cursor++];
        }

        set<int>setA = parseSet(set1);
        set<int>setB = parseSet(set2);
        /*
        printSet(setA);
        printSet(setB);
        */
        set<int>res;

        if(inst=='+'){
            res = getUnion(setA, setB);
            printSet(res);
        }

        if(inst=='-'){
            res = getDifference(setA, setB);
            printSet(res);
        }
        
        if(inst=='*'){
            res = getIntersection(setA, setB);
            printSet(res);
        }
    }
}
        
