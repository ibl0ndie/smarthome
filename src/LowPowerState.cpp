#include "LowPowerState.h"
#include "MSHController.h"
#include "DeviceManager.h"
#include "Light.h"
#include "TV.h"
#include "SoundSystem.h"
#include <iostream>

void LowPowerState::enter(MSHController* controller) {
    // Low power: minimize energy consumption
    DeviceManager* dm = controller->getDeviceManager();
    if (dm) {
        Light* light = dm->getLight("Living Room Light");
        if (light) {
            light->setBrightness(20);
        }
        
        TV* tv = dm->getTV("Living Room TV");
        if (tv && tv->isPowered()) {
            tv->powerOff();
        }
        
        SoundSystem* sound = dm->getSoundSystem("Main Sound System");
        if (sound && sound->isPowered()) {
            sound->powerOff();
        }
    }
}

void LowPowerState::exit(MSHController* controller) {
    // Restore previous settings
}

std::string LowPowerState::getName() const {
    return "Low Power";
}

