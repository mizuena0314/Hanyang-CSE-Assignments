#include <iostream>
#include "drop.h"

using namespace std;

int main(){
    while(1){
        string planet;
        int droph;
        cin >> planet;
        if(planet == "Earth"){
            cin >> droph;
            Earth e;
            e.simulate(droph);
        }
        if(planet == "Moon"){
            cin >> droph;
            Moon m;
            m.simulate(droph);
        }
        if(planet == "quit") return 0;
    }
}
