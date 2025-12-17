#ifndef DETECTORFACTORY_H
#define DETECTORFACTORY_H

#include "SmokeDetector.h"
#include "GasDetector.h"

// REQ: Abstract Factory Pattern for Detectors
// Student Part: Abstract Factory Pattern - Abstract Factory
class DetectorFactory {
public:
    virtual ~DetectorFactory();
    
    // Abstract Factory methods
    virtual SmokeDetector* createSmokeDetector(const std::string& name) = 0;
    virtual GasDetector* createGasDetector(const std::string& name) = 0;
    
    // Utility method
    static DetectorFactory* getFactory();
};

// REQ: Standard Detector Factory - Abstract Factory Concrete Factory
class StandardDetectorFactory : public DetectorFactory {
public:
    virtual SmokeDetector* createSmokeDetector(const std::string& name);
    virtual GasDetector* createGasDetector(const std::string& name);
};

#endif // DETECTORFACTORY_H

