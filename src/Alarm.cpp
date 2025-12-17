#include "Alarm.h"
#include <sstream>
#include <iostream>

Alarm::Alarm(const std::string& name) 
    : Device(name), triggered_(false) {
    // Critical safety device: must start powered on
    powered_ = true;
}

Alarm::~Alarm() {
}

void Alarm::powerOn() {
    powered_ = true;
}

void Alarm::powerOff() {
    // Critical safety device: cannot be turned off
    // Inform user and keep device powered on
    std::cout << "This device is critical safety; you cannot turn it off." << std::endl;
    triggered_ = false;
}

std::string Alarm::getStatus() const {
    std::ostringstream oss;
    oss << "Alarm [" << name_ << "] - ";
    if (powered_) {
        if (triggered_) {
            oss << "ON [TRIGGERED - SOUNDING]";
        } else {
            oss << "ON [READY]";
        }
    } else {
        oss << "OFF";
    }
    return oss.str();
}

void Alarm::trigger() {
    if (powered_) {
        triggered_ = true;
    }
}

void Alarm::stop() {
    triggered_ = false;
}

bool Alarm::isTriggered() const {
    return triggered_;
}

