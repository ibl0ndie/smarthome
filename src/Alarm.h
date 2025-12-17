#ifndef ALARM_H
#define ALARM_H

#include "Device.h"

// REQ: Alarm device
// Student Part: Device Implementation
class Alarm : public Device {
public:
    Alarm(const std::string& name);
    virtual ~Alarm();
    
    virtual void powerOn();
    virtual void powerOff();
    virtual std::string getStatus() const;
    
    void trigger();
    void stop();
    bool isTriggered() const;
    
private:
    bool triggered_;
};

#endif // ALARM_H

