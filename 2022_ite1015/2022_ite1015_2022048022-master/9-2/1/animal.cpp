#include <iostream>
#include <cstdlib>
#include <string>
#include "animal.h"

using namespace std;

Animal::Animal(string _name, int _age){
    name = _name;
    age = _age;
}

Animal::~Animal(){
    //cout << "del Animal" << endl;
}

Cat::Cat(string _name, int _age, string _favoriteToy):Animal(_name, _age){
    favoriteToy = _favoriteToy;
}

Cat::~Cat(){
    //cout << "del Cat" << endl;
}

void Cat::printInfo(){
    cout << "Cat, Name: " << name << ", Age: " << age << ", Favorite toy: " << favoriteToy << endl;
}

Zebra::Zebra(string _name, int _age, int _numStripes):Animal(_name, _age){
    numStripes = _numStripes;
}

Zebra::~Zebra(){
    //cout << "del Zeb" << endl;
}

void Zebra::printInfo(){
    cout << "Zebra, Name: " << name << ", Age: " << age << ", Number of stripes: " << numStripes << endl;
}
