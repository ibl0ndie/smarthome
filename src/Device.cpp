#include "Device.h"

Device::Device(const std::string& name) : name_(name), powered_(false) {
}

Device::~Device() {
}

std::string Device::getName() const {
    return name_;
}

bool Device::isPowered() const {
    return powered_;
}

