#ifndef DEVICE_H
#define DEVICE_H

#include <string>

// REQ: Base Device class for all home automation devices
// Student Part: Device Interface Design
class Device {
public:
    Device(const std::string& name);
    virtual ~Device();
    
    // Virtual functions as per requirements
    virtual void powerOn() = 0;
    virtual void powerOff() = 0;
    virtual std::string getStatus() const = 0;
    
    std::string getName() const;
    bool isPowered() const;
    
protected:
    std::string name_;
    bool powered_;
};

#endif // DEVICE_H

