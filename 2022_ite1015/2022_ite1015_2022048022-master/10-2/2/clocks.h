#pragma once
#include "clock_time.h"

class Clock{
    public:
        Clock(int hour, int minute, int second, int alarm, double driftPerSecond);
        virtual ~Clock();
        void reset();
        void tick();
        virtual void displayTime() = 0;
        virtual void displayAlarm(int t) = 0;

    protected:
        ClockTime _clockTime;
        int _alarm;
        double _driftPerSecond;
        double _totalDrift;
};

class NaturalClock:public Clock{
    public:
        virtual ~NaturalClock();
        NaturalClock(int hour, int minute, int second,int alarm,  double driftPerSecond);
        virtual void displayTime() = 0;
        virtual void displayAlarm(int t) = 0;
};

class MechanicalClock:public Clock{
    public:
        virtual ~MechanicalClock();
        MechanicalClock(int hour, int minute, int second, int alarm,  double driftPerSecond);
        virtual void displayTime() = 0;
        virtual void displayAlarm(int t) = 0;
};

class DigitalClock:public Clock{
    public:
        virtual ~DigitalClock();
        DigitalClock(int hour, int minute, int second,int alarm, double driftPerSecond);
        virtual void displayTime() = 0;
        virtual void displayAlarm(int t) = 0;
};

class QuantumClock:public Clock{
    public:
        virtual ~QuantumClock();
        QuantumClock(int hour, int minute, int second,int alarm, double driftPerSecond);
        virtual void displayTime() = 0;
        virtual void displayAlarm(int t) = 0;
};

class SundialClock:public NaturalClock{
    public:
        virtual ~SundialClock();
        SundialClock(int hour, int minute, int second, int alarm);
        virtual void displayTime();
        virtual void displayAlarm(int t);
};

class CuckooClock:public MechanicalClock{
    public:
        virtual ~CuckooClock();
        CuckooClock(int hour, int minute, int second, int alarm);
        virtual void displayTime();
        virtual void displayAlarm(int t);
};

class GrandFatherClock:public MechanicalClock{
    public:
        virtual ~GrandFatherClock();
        GrandFatherClock(int hour, int minute, int second, int alarm);
        virtual void displayTime();
        virtual void displayAlarm(int t);
};

class WristClock:public DigitalClock{
    public:
        virtual ~WristClock();
        WristClock(int hour, int minute, int second, int alarm);
        virtual void displayTime();
        virtual void displayAlarm(int t);
};

class AtomicClock:public QuantumClock{
    public:
        virtual ~AtomicClock();
        AtomicClock(int hour, int minute, int second, int alarm);
        virtual void displayTime();
        virtual void displayAlarm(int t);
};
