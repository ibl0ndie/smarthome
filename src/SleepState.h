#ifndef SLEEPSTATE_H
#define SLEEPSTATE_H

#include "SystemState.h"

// REQ: Sleep State - State Pattern Concrete State
// Student Part: State Pattern - Concrete State
class SleepState : public SystemState {
public:
    virtual void enter(MSHController* controller);
    virtual void exit(MSHController* controller);
    virtual std::string getName() const;
};

#endif // SLEEPSTATE_H

