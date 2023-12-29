#include <iostream>
#include <string>
#include <cstdlib>
#include "my_string.h"

using namespace std;

MyString MyString::operator+(const MyString& b){
    MyString tmp;
    tmp.str = this->str + b.str;
    return tmp;
}

MyString MyString::operator*(const int b){
    MyString tmp;
    for(int i=0; i<b; i++) tmp = tmp + *this;
    return tmp;
}

ostream& operator<<(ostream& out, MyString& my_string){
    out << my_string.str << endl;
    return out;
}

istream& operator>>(istream& in, MyString& my_string){
    in >> my_string.str;
    return in;
}
