#include <iostream>
#include <string>
#include <cstdlib>
#include "my_string2.h"

using namespace std;

MyString2::MyString2(){}

MyString2::MyString2(string mystr){
    str = mystr;
}

MyString2::MyString2(const MyString2 &my_string){
    str = my_string.str;
    cout << "(copy constructor)" << endl;
}

MyString2& MyString2::operator=(const MyString2& b){
    this->str = b.str;
    cout << "(assignment operator)" << endl;
    return *this;
}

MyString2 MyString2::operator+(const MyString2& b){
    MyString2 tmp;
    tmp.str = this->str + b.str;
    return tmp;
}

MyString2 MyString2::operator*(const int b){
    string blank = "";
    for(int i=0; i<b; i++) blank += this->str;
    MyString2 tmp(blank);
    return tmp;
}

ostream& operator<<(ostream& out, MyString2& my_string){
    out << my_string.str << endl;
    return out;
}

istream& operator>>(istream& in, MyString2& my_string){
    in >> my_string.str;
    return in;
}
