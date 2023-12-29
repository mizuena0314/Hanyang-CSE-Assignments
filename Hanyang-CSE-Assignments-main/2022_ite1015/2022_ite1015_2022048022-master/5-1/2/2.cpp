#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

struct Person{
    double score;
    string name;
};

int main(int argc, char** argv){

    Person* arr = new Person[(argc/2)]();
    for(int i=1; i<argc; i+=2){
        arr[i/2].name = argv[i];
        arr[i/2].score = stod(argv[i+1]);
    }

    for(int i=0; i<argc/2; i++){
        cout << "Name:" << arr[i].name << ", Score:" << arr[i].score << endl;
    }

    delete[] arr;

    return 0;
}
