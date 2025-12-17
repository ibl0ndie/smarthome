#ifndef PREVIOUSSTATE_H
#define PREVIOUSSTATE_H

#include "SystemState.h"

// REQ: Previous State - State Pattern for History Management
// Student Part: State Pattern - History Manager
class PreviousState : public SystemState {
public:
    PreviousState(SystemState* savedState);
    virtual ~PreviousState();
    
    virtual void enter(MSHController* controller);
    virtual void exit(MSHController* controller);
    virtual std::string getName() const;
    
    SystemState* getSavedState() const;
    
private:
    SystemState* savedState_;
};

#endif // PREVIOUSSTATE_H
 
