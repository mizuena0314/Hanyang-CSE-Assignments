#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include "clocks.h"
#include "clock_time.h"

using namespace std;

Clock::Clock(int hour, int minute, int second,int alarm, double driftPerSecond){
    _driftPerSecond = driftPerSecond;
    _totalDrift = 0;
    _alarm = alarm;
    _clockTime = ClockTime(hour, minute, second, 1);
}

NaturalClock::NaturalClock(int hour, int minute, int second,int alarm, double driftPerSecond):Clock(hour, minute, second,alarm, driftPerSecond){}

MechanicalClock::MechanicalClock(int hour, int minute, int second,int alarm, double driftPerSecond):Clock(hour, minute, second, alarm, driftPerSecond){}

DigitalClock::DigitalClock(int hour, int minute, int second, int alarm,  double driftPerSecond):Clock(hour, minute, second,alarm, driftPerSecond){}

QuantumClock::QuantumClock(int hour, int minute, int second, int alarm, double driftPerSecond):Clock(hour, minute, second,alarm, driftPerSecond){}

SundialClock::SundialClock(int hour, int minute, int second, int alarm):NaturalClock(hour, minute, second, alarm, 0.0){}

CuckooClock::CuckooClock(int hour, int minute, int second, int alarm):MechanicalClock(hour, minute, second,alarm, 0.0){}

GrandFatherClock::GrandFatherClock(int hour, int minute, int second, int alarm):MechanicalClock(hour, minute, second,alarm, 0.000694444){}

WristClock::WristClock(int hour, int minute, int second, int alarm):DigitalClock(hour, minute, second,alarm, 0.000347222){}

AtomicClock::AtomicClock(int hour, int minute, int second, int alarm):QuantumClock(hour, minute, second, alarm, 0.000034722){}

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

void SundialClock::displayAlarm(int t){
    if(t==_alarm){
        cout << "Sundial alarm at ";
        _clockTime.display();
        cout << endl;
    }
}

void CuckooClock::displayAlarm(int t){
    if(t==_alarm){
        cout << "Cuckoo alarm at ";
        _clockTime.display();
        cout << endl;
    }
}

void GrandFatherClock::displayAlarm(int t){
    if(t==_alarm){
        cout << "GrandFather alarm at ";
        _clockTime.display();
        cout << endl;
    }
}

void WristClock::displayAlarm(int t){
    if(t==_alarm){
        cout << "Wrist alarm at ";
        _clockTime.display();
        cout << endl;
    }
}

void AtomicClock::displayAlarm(int t){
    if(t==_alarm){
        cout << "Atomic alarm at ";
        _clockTime.display();
        cout << endl;
    }
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
