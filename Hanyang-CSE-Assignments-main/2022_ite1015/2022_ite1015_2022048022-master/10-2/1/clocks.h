#pragma once
#include "clock_time.h"

class Clock{
    public:
        Clock(int hour, int minute, int second, double driftPerSecond);
        virtual ~Clock();
        void reset();
        void tick();
        virtual void displayTime() = 0;

    protected:
        ClockTime _clockTime;
        double _driftPerSecond;
        double _totalDrift;
};

class NaturalClock:public Clock{
    public:
        virtual ~NaturalClock();
        NaturalClock(int hour, int minute, int second, double driftPerSecond);
        virtual void displayTime() = 0;
};

class MechanicalClock:public Clock{
    public:
        virtual ~MechanicalClock();
        MechanicalClock(int hour, int minute, int second, double driftPerSecond);
        virtual void displayTime() = 0;
};

class DigitalClock:public Clock{
    public:
        virtual ~DigitalClock();
        DigitalClock(int hour, int minute, int second, double driftPerSecond);
        virtual void displayTime() = 0;
};

class QuantumClock:public Clock{
    public:
        virtual ~QuantumClock();
        QuantumClock(int hour, int minute, int second, double driftPerSecond);
        virtual void displayTime() = 0;
};

class SundialClock:public NaturalClock{
    public:
        virtual ~SundialClock();
        SundialClock(int hour, int minute, int second);
        virtual void displayTime();
};

class CuckooClock:public MechanicalClock{
    public:
        virtual ~CuckooClock();
        CuckooClock(int hour, int minute, int second);
        virtual void displayTime();
};

class GrandFatherClock:public MechanicalClock{
    public:
        virtual ~GrandFatherClock();
        GrandFatherClock(int hour, int minute, int second);
        virtual void displayTime();
};

class WristClock:public DigitalClock{
    public:
        virtual ~WristClock();
        WristClock(int hour, int minute, int second);
        virtual void displayTime();
};

class AtomicClock:public QuantumClock{
    public:
        virtual ~AtomicClock();
        AtomicClock(int hour, int minute, int second);
        virtual void displayTime();
};
