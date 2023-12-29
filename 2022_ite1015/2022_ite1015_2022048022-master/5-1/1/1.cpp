#include <iostream>
#include <string>
using namespace std;

int main(int argc, char** argv){
    string s = argv[1];
    int cnt = stoi(argv[2]);
    while(cnt--){
        cout << s << endl;
    }
    return 0;
}

