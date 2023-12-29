#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include "clocks.h"
#include "clock_time.h"

using namespace std;

Clock::Clock(int hour, int minute, int second, double driftPerSecond){
    _driftPerSecond = driftPerSecond;
    _totalDrift = 0;
    _clockTime = ClockTime(hour, minute, second, 1);
}

NaturalClock::NaturalClock(int hour, int minute, int second, double driftPerSecond):Clock(hour, minute, second, driftPerSecond){}

MechanicalClock::MechanicalClock(int hour, int minute, int second, double driftPerSecond):Clock(hour, minute, second, driftPerSecond){}

DigitalClock::DigitalClock(int hour, int minute, int second, double driftPerSecond):Clock(hour, minute, second, driftPerSecond){}

QuantumClock::QuantumClock(int hour, int minute, int second, double driftPerSecond):Clock(hour, minute, second, driftPerSecond){}

SundialClock::SundialClock(int hour, int minute, int second):NaturalClock(hour, minute, second, 0.0){}

CuckooClock::CuckooClock(int hour, int minute, int second):MechanicalClock(hour, minute, second, 0.0){}

GrandFatherClock::GrandFatherClock(int hour, int minute, int second):MechanicalClock(hour, minute, second, 0.000694444){}

WristClock::WristClock(int hour, int minute, int second):DigitalClock(hour, minute, second, 0.000347222){}

AtomicClock::AtomicClock(int hour, int minute, int second):QuantumClock(hour, minute, second, 0.000034722){}

void Clock::reset(){
    _clockTime.reset();
}

void Clock::tick(){
    _clockTime.increment();
    _totalDrift += _driftPerSecond;
}

void SundialClock::displayTime(){
    cout << "SundialClock ";
    _clockTime.display();
    cout << ", total drift: " << _totalDrift << endl;
}

void CuckooClock::displayTime(){
    cout << "CuckooClock ";
    _clockTime.display();
    cout << ", total drift: " << _totalDrift << endl;
}

void GrandFatherClock::displayTime(){
    cout << "GrandFatherClock ";
    _clockTime.display();
    cout << ", total drift: " << _totalDrift << endl;
}

void WristClock::displayTime(){
    cout << "WristClock ";
    _clockTime.display();
    cout << ", total drift: " << _totalDrift << endl;
}

void AtomicClock::displayTime(){
    cout << "AtomicClock ";
    _clockTime.display();
    cout << ", total drift: " << _totalDrift << endl;
}

Clock::~Clock(){ /*cout << "del clock" << endl;*/ }

NaturalClock::~NaturalClock(){ /*cout << "del nature" << endl;*/ }

MechanicalClock::~MechanicalClock(){ /*cout << "del mech" << endl;*/ }

DigitalClock::~DigitalClock(){ /*cout << "del digital" << endl;*/ }

QuantumClock::~QuantumClock(){ /*cout << "del quantum" << endl;*/ }

SundialClock::~SundialClock(){ /*cout << "del sundial" << endl;*/ }

WristClock::~WristClock(){ /*cout << "del wrist" << endl;*/ }

AtomicClock::~AtomicClock(){ /*cout << "del atomic" << endl;*/ }

CuckooClock::~CuckooClock(){ /*cout << "del cuckoo" << endl;*/ }

GrandFatherClock::~GrandFatherClock(){/* cout << "del grandpa" << endl;*/ }
