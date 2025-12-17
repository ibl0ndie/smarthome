#include "DeviceManager.h"
#include "Device.h"
#include "Light.h"
#include "TV.h"
#include "SoundSystem.h"
#include "Camera.h"
#include "Alarm.h"
#include "SmokeDetector.h"
#include "GasDetector.h"
#include <iostream>
#include <algorithm>

DeviceManager::DeviceManager() {
}

DeviceManager::~DeviceManager() {
    for (std::vector<Device*>::iterator it = devices_.begin(); it != devices_.end(); ++it) {
        delete *it;
    }
    devices_.clear();
}

void DeviceManager::addDevice(Device* device) {
    if (device) {
        devices_.push_back(device);
    }
}

void DeviceManager::removeDevice(const std::string& name) {
    for (std::vector<Device*>::iterator it = devices_.begin(); it != devices_.end(); ++it) {
        if ((*it)->getName() == name) {
            delete *it;
            devices_.erase(it);
            break;
        }
    }
}

Device* DeviceManager::findDevice(const std::string& name) const {
    for (std::vector<Device*>::const_iterator it = devices_.begin(); it != devices_.end(); ++it) {
        if ((*it)->getName() == name) {
            return *it;
        }
    }
    return 0;
}

Device* DeviceManager::getDevice(const std::string& name) {
    return findDevice(name);
}

Light* DeviceManager::getLight(const std::string& name) {
    Device* dev = findDevice(name);
    return dynamic_cast<Light*>(dev);
}

TV* DeviceManager::getTV(const std::string& name) {
    Device* dev = findDevice(name);
    return dynamic_cast<TV*>(dev);
}

SoundSystem* DeviceManager::getSoundSystem(const std::string& name) {
    Device* dev = findDevice(name);
    return dynamic_cast<SoundSystem*>(dev);
}

Camera* DeviceManager::getCamera(const std::string& name) {
    Device* dev = findDevice(name);
    return dynamic_cast<Camera*>(dev);
}

Alarm* DeviceManager::getAlarm(const std::string& name) {
    Device* dev = findDevice(name);
    return dynamic_cast<Alarm*>(dev);
}

SmokeDetector* DeviceManager::getSmokeDetector(const std::string& name) {
    Device* dev = findDevice(name);
    return dynamic_cast<SmokeDetector*>(dev);
}

GasDetector* DeviceManager::getGasDetector(const std::string& name) {
    Device* dev = findDevice(name);
    return dynamic_cast<GasDetector*>(dev);
}

void DeviceManager::listAllDevices() const {
    std::cout << "\n=== All Devices ===" << std::endl;
    for (std::vector<Device*>::const_iterator it = devices_.begin(); it != devices_.end(); ++it) {
        std::cout << (*it)->getStatus() << std::endl;
    }
}

std::vector<Device*> DeviceManager::getAllDevices() const {
    return devices_;
}

