#include "Alarm.h"
#include <sstream>

Alarm::Alarm(const std::string& name) 
    : Device(name), triggered_(false) {
}

Alarm::~Alarm() {
}

void Alarm::powerOn() {
    powered_ = true;
}

void Alarm::powerOff() {
    powered_ = false;
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

