#pragma once
#include <string>
inline void swapInt(int &n1, int &n2){
    int temp = n1;
    n1 = n2;
    n2 = temp;
}

void swapString(std::string& s1, std::string& s2);

