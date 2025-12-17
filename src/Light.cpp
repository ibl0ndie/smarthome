#include "Light.h"
#include <sstream>

Light::Light(const std::string& name) 
    : Device(name), brightness_(50), flashing_(false) {
}

Light::~Light() {
}

void Light::powerOn() {
    powered_ = true;
}

void Light::powerOff() {
    powered_ = false;
    flashing_ = false;
}

std::string Light::getStatus() const {
    std::ostringstream oss;
    oss << "Light [" << name_ << "] - ";
    if (powered_) {
        oss << "ON (Brightness: " << brightness_ << "%)";
        if (flashing_) {
            oss << " [FLASHING]";
        }
    } else {
        oss << "OFF";
    }
    return oss.str();
}

void Light::setBrightness(int level) {
    if (level < 0) level = 0;
    if (level > 100) level = 100;
    brightness_ = level;
}

int Light::getBrightness() const {
    return brightness_;
}

void Light::setFlashing(bool flashing) {
    flashing_ = flashing;
}

bool Light::isFlashing() const {
    return flashing_;
}

