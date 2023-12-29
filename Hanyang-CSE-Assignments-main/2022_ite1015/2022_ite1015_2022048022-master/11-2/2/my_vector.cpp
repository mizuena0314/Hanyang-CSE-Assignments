#include <iostream>
#include <cstdlib>
#include "my_vector.h"

using namespace std;

MyVector::MyVector(){}

MyVector::MyVector(int length){
    a = new double(length);
    this->length = length;
}

MyVector::~MyVector(){
    delete[] a;
}

MyVector MyVector::operator+(const MyVector& b){
    for(int i=0; i<(this->length); i++){
        (this->a)[i] += b.a[i];
    }
    return *this;
}

MyVector MyVector::operator-(const MyVector& b){}

MyVector MyVector::operator+(const int b){}

MyVector MyVector::operator-(const int b){}

ostream& operator<<(ostream& out, MyVector& b){
    for(int i=0; i<b.length; i++){
        out << (b.a)[i] << ' ';
    }
    out << endl;
    return out;
}

istream& operator>>(istream& in, MyVector& b){
    for(int i=0; i<b.length; i++){
        in >> (b.a)[i];
    }
    return in;
}
