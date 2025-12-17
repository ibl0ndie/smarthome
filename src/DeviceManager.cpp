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

// ---------------- Constructor / Destructor ----------------

DeviceManager::DeviceManager() {
}

DeviceManager::~DeviceManager() {
    for (std::vector<Device*>::iterator it = devices_.begin();
         it != devices_.end(); ++it) {
        delete *it;
    }
    devices_.clear();
}

// ---------------- Registry ----------------

void DeviceManager::addDevice(Device* device) {
    if (device) {
        devices_.push_back(device);
    }
}

void DeviceManager::removeDevice(const std::string& name) {
    for (std::vector<Device*>::iterator it = devices_.begin();
         it != devices_.end(); ++it) {
        if ((*it)->getName() == name) {
            delete *it;
            devices_.erase(it);
            break;
        }
    }
}

Device* DeviceManager::findDevice(const std::string& name) const {
    for (std::vector<Device*>::const_iterator it = devices_.begin();
         it != devices_.end(); ++it) {
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
    return dynamic_cast<Light*>(findDevice(name));
}

TV* DeviceManager::getTV(const std::string& name) {
    return dynamic_cast<TV*>(findDevice(name));
}

SoundSystem* DeviceManager::getSoundSystem(const std::string& name) {
    return dynamic_cast<SoundSystem*>(findDevice(name));
}

Camera* DeviceManager::getCamera(const std::string& name) {
    return dynamic_cast<Camera*>(findDevice(name));
}

Alarm* DeviceManager::getAlarm(const std::string& name) {
    return dynamic_cast<Alarm*>(findDevice(name));
}

SmokeDetector* DeviceManager::getSmokeDetector(const std::string& name) {
    return dynamic_cast<SmokeDetector*>(findDevice(name));
}

GasDetector* DeviceManager::getGasDetector(const std::string& name) {
    return dynamic_cast<GasDetector*>(findDevice(name));
}

// ---------------- Info ----------------

void DeviceManager::listAllDevices() const {
    std::cout << "\n=== All Devices ===" << std::endl;
    for (std::vector<Device*>::const_iterator it = devices_.begin();
         it != devices_.end(); ++it) {
        std::cout << (*it)->getStatus() << std::endl;
    }
}

std::vector<Device*> DeviceManager::getAllDevices() const {
    return devices_;
}

// ======================
// Facade operations
// ======================

// Light
bool DeviceManager::setLightBrightness(const std::string& name, int level) {
    Light* l = getLight(name);
    if (!l) return false;
    l->setBrightness(level);
    return true;
}

bool DeviceManager::setLightFlashing(const std::string& name, bool flashing) {
    Light* l = getLight(name);
    if (!l) return false;
    l->setFlashing(flashing);
    return true;
}

// Camera
bool DeviceManager::cameraSimulateMotion(const std::string& name) {
    Camera* c = getCamera(name);
    if (!c) return false;
    c->simulateMotion();
    return true;
}

bool DeviceManager::cameraDetectMotion(const std::string& name, bool &detected) {
    Camera* c = getCamera(name);
    if (!c) return false;
    detected = c->detectMotion();
    return true;
}

// Alarm
bool DeviceManager::isAlarmTriggered(const std::string& name, bool &triggered) {
    Alarm* a = getAlarm(name);
    if (!a) return false;
    triggered = a->isTriggered();
    return true;
}
