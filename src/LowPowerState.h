#ifndef LOWPOWERSTATE_H
#define LOWPOWERSTATE_H

#include "SystemState.h"

// REQ: Low Power State - State Pattern Concrete State
// Student Part: State Pattern - Concrete State
class LowPowerState : public SystemState {
public:
    virtual void enter(MSHController* controller);
    virtual void exit(MSHController* controller);
    virtual std::string getName() const;
};

#endif // LOWPOWERSTATE_H

 