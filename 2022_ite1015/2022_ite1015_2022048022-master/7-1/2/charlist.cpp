#include "charlist.h"

CharList::CharList(const char* str){
    int i=0;
    while(str[i]!='\0'){
        mystring_.push_back(str[i]);
        i++;
    }
}

CharList::~CharList(){}

bool CharList::CheckPalindrome(){
    std::list<char>::iterator pt1 = mystring_.begin();
    std::list<char>::iterator pt2 = mystring_.end();
    pt2--;
    while(1){
        if(pt1==mystring_.end() || pt2==mystring_.begin()) break;
        if(*pt1 != *pt2) return false;
        pt1++;
        pt2--;
    }
    return true;
}

std::list<char> CharList::GetAll(){
    return mystring_;
}    


