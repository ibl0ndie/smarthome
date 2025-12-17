#ifndef SYSTEMSTATE_H
#define SYSTEMSTATE_H

#include <string>

class MSHController;

// REQ: State Pattern for System States
// Student Part: State Pattern - State Interface
class SystemState {
public:
    virtual ~SystemState();
    virtual void enter(MSHController* controller) = 0;
    virtual void exit(MSHController* controller) = 0;
    virtual std::string getName() const = 0;
};

#endif // SYSTEMSTATE_H

 