#include <iostream>
#include <string>
#include <cstdlib>
#include "my_container.h"

using namespace std;

int main(){
    int len1, len2, len3;
    cin >> len1;
    MyContainer<double>c1(len1);
    cin >> c1;
    cout << c1 << endl;

    cin >> len2;
    MyContainer<string>c2(len2);
    cin >> c2;
    cout << c2 << endl;

    cin >> len3;
    MyContainer<int>c3(len3);
    cin >> c3;
    cout << c3 << endl;
}
