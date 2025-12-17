#ifndef NORMALSTATE_H
#define NORMALSTATE_H

#include "SystemState.h"

// REQ: Normal State - State Pattern Concrete State
// Student Part: State Pattern - Concrete State
class NormalState : public SystemState {
public:
    virtual void enter(MSHController* controller);
    virtual void exit(MSHController* controller);
    virtual std::string getName() const;
};

#endif // NORMALSTATE_H

