#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include "clocks.h"
#include "clock_time.h"

using namespace std;

int runtime;
int alarms[5];

int main(){
    vector<Clock*>arr;

    for(int i=0; i<5; i++) cin >> alarms[i];

    arr.push_back(new SundialClock(0,0,0,alarms[0]));
    arr.push_back(new CuckooClock(0,0,0,alarms[1]));
    arr.push_back(new GrandFatherClock(0,0,0,alarms[2]));
    arr.push_back(new WristClock(0,0,0,alarms[3]));
    arr.push_back(new AtomicClock(0,0,0,alarms[4]));

    for(auto i:arr) i->reset();

    cin >> runtime;

    cout << "Reported clock times after resetting:" << endl;
    for(auto i:arr) i->displayTime();

    cout << endl << "Running the clocks ...\n" << endl;

    for(int i=0; i<runtime; i++){
        if(i==0){
            for(auto x:arr) x->displayAlarm(0);
        }
        for(auto x:arr){
            x->tick();
            x->displayAlarm(i+1);
        }
    }

    cout <<  endl << "Reported clock times after running:" << endl;
    for(auto i:arr) i->displayTime();

    for(auto i:arr) delete i;
    return 0;
}
