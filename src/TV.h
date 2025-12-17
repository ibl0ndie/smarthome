#ifndef TV_H
#define TV_H

#include "Device.h"
#include <string>

// REQ: Base TV class for Factory Method pattern
// Student Part: Factory Method Pattern - Product Base Class
class TV : public Device {
public:
    TV(const std::string& name, const std::string& brand);
    virtual ~TV();
    
    virtual void powerOn();
    virtual void powerOff();
    virtual std::string getStatus() const;
    
    virtual void setChannel(int channel) = 0;
    virtual int getChannel() const = 0;
    virtual void setVolume(int volume) = 0;
    virtual int getVolume() const = 0;
    
protected:
    std::string brand_;
    int channel_;
    int volume_;
};

#endif // TV_H

