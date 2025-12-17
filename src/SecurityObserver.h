#ifndef SECURITYOBSERVER_H
#define SECURITYOBSERVER_H

#include "Observer.h"

class MSHController;

// REQ: Security Observer - Observer Pattern Concrete Observer
// Student Part: Observer Pattern - Concrete Observer
// Workflow: Camera motion → alarm → turn lights on → call police
class SecurityObserver : public Observer {
public:
    SecurityObserver(MSHController* controller);
    virtual ~SecurityObserver();
    
    virtual void onMotionDetected();
    
private:
    MSHController* controller_;
};

#endif // SECURITYOBSERVER_H

