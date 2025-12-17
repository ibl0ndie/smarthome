#ifndef LIGHT_H
#define LIGHT_H

#include "Device.h"

// REQ: Light device implementation
// Student Part: Device Implementation
class Light : public Device {
public:
    Light(const std::string& name);
    virtual ~Light();
    
    virtual void powerOn();
    virtual void powerOff();
    virtual std::string getStatus() const;
    
    void setBrightness(int level); // 0-100
    int getBrightness() const;
    void setFlashing(bool flashing);
    bool isFlashing() const;
    
private:
    int brightness_;
    bool flashing_;
};

#endif // LIGHT_H

