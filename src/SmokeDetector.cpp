#include "SmokeDetector.h"
#include <sstream>
#include <iostream>

SmokeDetector::SmokeDetector(const std::string& name) 
    : Device(name), smokeDetected_(false) {
    // Critical safety device: must start powered on
    powered_ = true;
}

SmokeDetector::~SmokeDetector() {
}

void SmokeDetector::powerOn() {
    powered_ = true;
    smokeDetected_ = false;
}

void SmokeDetector::powerOff() {
    // Critical safety device: cannot be turned off
    // Inform user and keep device powered on
    std::cout << "This device is critical safety; you cannot turn it off." << std::endl;
    smokeDetected_ = false;
}

std::string SmokeDetector::getStatus() const {
    std::ostringstream oss;
    oss << "Smoke Detector [" << name_ << "] - ";
    if (powered_) {
        if (smokeDetected_) {
            oss << "ON [SMOKE DETECTED - ALERT!]";
        } else {
            oss << "ON [MONITORING]";
        }
    } else {
        oss << "OFF";
    }
    return oss.str();
}

void SmokeDetector::simulateSmoke() {
    if (powered_) {
        smokeDetected_ = true;
    }
}

bool SmokeDetector::isSmokeDetected() const {
    return smokeDetected_;
}

