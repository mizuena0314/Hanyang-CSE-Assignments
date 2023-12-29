#include <iostream>
#include <cstdlib>
#include "minmax.h"

using namespace std;

int main(int argc, char** argv){
    if(argc==1) return 0;
    int* arr = new int[argc-1]();
    for(int i=0; i<argc-1; i++){
        arr[i] = atoi(argv[i+1]);
    }
    int min;
    int max;
    getMinMax(arr, argc-1, min, max);
    cout << "min: " << min << endl;
    cout << "max: " << max << endl;
    delete[] arr;
    return 0;
}

