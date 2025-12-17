#ifndef HIGHPERFORMANCESTATE_H
#define HIGHPERFORMANCESTATE_H

#include "SystemState.h"

// REQ: High Performance State - State Pattern Concrete State
// Student Part: State Pattern - Concrete State
class HighPerformanceState : public SystemState {
public:
    virtual void enter(MSHController* controller);
    virtual void exit(MSHController* controller);
    virtual std::string getName() const;
};

#endif // HIGHPERFORMANCESTATE_H

 