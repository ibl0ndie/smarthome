#include "SmokeDetector.h"
#include <sstream>

SmokeDetector::SmokeDetector(const std::string& name) 
    : Device(name), smokeDetected_(false) {
}

SmokeDetector::~SmokeDetector() {
}

void SmokeDetector::powerOn() {
    powered_ = true;
    smokeDetected_ = false;
}

void SmokeDetector::powerOff() {
    powered_ = false;
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

bool SmokeDetector::detectSmoke() {
    return smokeDetected_;
}

void SmokeDetector::simulateSmoke() {
    if (powered_) {
        smokeDetected_ = true;
    }
}

bool SmokeDetector::isSmokeDetected() const {
    return smokeDetected_;
}

