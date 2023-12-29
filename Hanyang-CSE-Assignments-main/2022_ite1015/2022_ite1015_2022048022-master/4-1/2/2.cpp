#include <iostream>
using namespace std;

int main(){
    int n, target, count=0;
    cin >> n;
    int* arr = new int[n];
    for(int i=0; i<n; i++) cin >> arr[i];
    cin >> target;
    for(int i=0;i<n; i++){
        if(arr[i]==target) count++;
    }
    cout << "target value: " << target << endl;
    cout << "target count: " << count << endl;
    return 0;
}
