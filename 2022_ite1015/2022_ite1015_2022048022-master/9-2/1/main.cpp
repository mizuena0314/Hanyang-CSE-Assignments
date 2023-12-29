#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include "animal.h"

using namespace std;

int main(){
    vector<Animal*>animals;
    while(1){
        char type;
        cin >> type;
        if(type=='0') break;
        
        if(type=='z'){
            string name;
            int age;
            int numStripes;
            cin >> name >> age >> numStripes;
            Animal* a = new Zebra(name, age, numStripes);

            animals.push_back(a);
        }

        if(type=='c'){
            string name;
            int age;
            string favoriteToy;
            cin >> name >> age >> favoriteToy;
            Animal* a = new Cat(name, age, favoriteToy);

            animals.push_back(a);
        }
    }

    for(auto i:animals){
        i->printInfo();
        delete i;
    }
}
