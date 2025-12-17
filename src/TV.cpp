#include "TV.h"
#include <sstream>

TV::TV(const std::string& name, const std::string& brand) 
    : Device(name), brand_(brand), channel_(1), volume_(50) {
}

TV::~TV() {
}

void TV::powerOn() {
    powered_ = true;
}

void TV::powerOff() {
    powered_ = false;
}

std::string TV::getStatus() const {
    std::ostringstream oss;
    oss << "TV [" << name_ << "] - Brand: " << brand_ << ", ";
    if (powered_) {
        oss << "ON (Channel: " << channel_ << ", Volume: " << volume_ << ")";
    } else {
        oss << "OFF";
    }
    return oss.str();
}

