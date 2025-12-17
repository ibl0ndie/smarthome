#ifndef SMOKEDETECTOR_H
#define SMOKEDETECTOR_H

#include "Device.h"

// REQ: Smoke Detector - Abstract Factory Product
// Student Part: Abstract Factory Pattern - Product
class SmokeDetector : public Device {
public:
    SmokeDetector(const std::string& name);
    virtual ~SmokeDetector();
    
    virtual void powerOn();
    virtual void powerOff();
    virtual std::string getStatus() const;
    
    void simulateSmoke();
    bool isSmokeDetected() const;
    
private:
    bool smokeDetected_;
};

#endif // SMOKEDETECTOR_H

