#ifndef GASDETECTOR_H
#define GASDETECTOR_H

#include "Device.h"

// REQ: Gas Detector - Abstract Factory Product
// Student Part: Abstract Factory Pattern - Product
class GasDetector : public Device {
public:
    GasDetector(const std::string& name);
    virtual ~GasDetector();
    
    virtual void powerOn();
    virtual void powerOff();
    virtual std::string getStatus() const;
    
    bool detectGas();
    void simulateGas();
    bool isGasDetected() const;
    
private:
    bool gasDetected_;
};

#endif // GASDETECTOR_H

