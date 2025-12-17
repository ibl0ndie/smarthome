#include "GasDetector.h"
#include <sstream>
#include <iostream>

GasDetector::GasDetector(const std::string& name) 
    : Device(name), gasDetected_(false) {
    // Critical safety device: must start powered on
    powered_ = true;
}

GasDetector::~GasDetector() {
}

void GasDetector::powerOn() {
    powered_ = true;
    gasDetected_ = false;
}

void GasDetector::powerOff() {
    // Critical safety device: cannot be turned off
    // Inform user and keep device powered on
    std::cout << "This device is critical safety; you cannot turn it off." << std::endl;
    gasDetected_ = false;
}

std::string GasDetector::getStatus() const {
    std::ostringstream oss;
    oss << "Gas Detector [" << name_ << "] - ";
    if (powered_) {
        if (gasDetected_) {
            oss << "ON [GAS DETECTED - ALERT!]";
        } else {
            oss << "ON [MONITORING]";
        }
    } else {
        oss << "OFF";
    }
    return oss.str();
}

void GasDetector::simulateGas() {
    if (powered_) {
        gasDetected_ = true;
    }
}

bool GasDetector::isGasDetected() const {
    return gasDetected_;
}

