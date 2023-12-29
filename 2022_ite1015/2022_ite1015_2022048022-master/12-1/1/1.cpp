#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

template <typename T>

void myswap(T & a, T & b){
    T temp = a;
    a = b;
    b = temp;
}

int main(){
    int n1, n2;
    cin >> n1 >> n2;
    myswap(n1,n2);
    cout << "After calling myswap(): " << n1 << ' ' << n2 << endl;
    double d1, d2;
    cin >> d1 >> d2;
    myswap(d1, d2);
    cout << "After calling myswap(): " << d1 << ' ' << d2 << endl;
    string s1, s2;
    cin >> s1 >> s2;
    myswap(s1, s2);
    cout << "After calling myswap(): " << s1 << ' ' << s2 << endl;
}
