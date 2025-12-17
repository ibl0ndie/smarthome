#include "GasDetector.h"
#include <sstream>

GasDetector::GasDetector(const std::string& name) 
    : Device(name), gasDetected_(false) {
}

GasDetector::~GasDetector() {
}

void GasDetector::powerOn() {
    powered_ = true;
    gasDetected_ = false;
}

void GasDetector::powerOff() {
    powered_ = false;
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

bool GasDetector::detectGas() {
    return gasDetected_;
}

void GasDetector::simulateGas() {
    if (powered_) {
        gasDetected_ = true;
    }
}

bool GasDetector::isGasDetected() const {
    return gasDetected_;
}

