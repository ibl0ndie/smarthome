#include "DetectorFactory.h"
#include "SmokeDetector.h"
#include "GasDetector.h"

DetectorFactory::~DetectorFactory() {
}

SmokeDetector* StandardDetectorFactory::createSmokeDetector(const std::string& name) {
    return new SmokeDetector(name);
}

GasDetector* StandardDetectorFactory::createGasDetector(const std::string& name) {
    return new GasDetector(name);
}

DetectorFactory* DetectorFactory::getFactory() {
    return new StandardDetectorFactory();
}

