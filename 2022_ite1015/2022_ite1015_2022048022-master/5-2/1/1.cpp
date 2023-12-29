#include <iostream>
#include <string>
using namespace std;

int main(int argc, char** argv){
    string res = "";
    int sum = 0;
    for(int i=1; i<argc; i++){
        if(atoi(argv[i])) sum += atoi(argv[i]);
        else res += argv[i];
    }
    cout << res << endl;
    cout << sum << endl;
    return 0;
}
