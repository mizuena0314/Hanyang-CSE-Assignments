#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include "clocks.h"
#include "clock_time.h"

using namespace std;

int runtime;

int main(){
    vector<Clock*>arr;
    arr.push_back(new SundialClock(0,0,0));
    arr.push_back(new CuckooClock(0,0,0));
    arr.push_back(new GrandFatherClock(0,0,0));
    arr.push_back(new WristClock(0,0,0));
    arr.push_back(new AtomicClock(0,0,0));

    for(auto i:arr) i->reset();

    cin >> runtime;

    cout << "Reported clock times after resetting:" << endl;
    for(auto i:arr) i->displayTime();

    cout << endl << "Running the clocks ...\n" << endl;

    for(int i=0; i<runtime; i++){
        for(auto x:arr) x->tick();
    }

    cout << "Reported clock times after running:" << endl;
    for(auto i:arr) i->displayTime();

    for(auto i:arr) delete i;
    return 0;
}
