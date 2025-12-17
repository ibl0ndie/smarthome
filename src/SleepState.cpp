#include "SleepState.h"
#include "MSHController.h"
#include "DeviceManager.h"
#include "Light.h"
#include "TV.h"
#include "SoundSystem.h"
#include <iostream>

void SleepState::enter(MSHController* controller) {
    // Sleep: turn off most devices, keep security on
    DeviceManager* dm = controller->getDeviceManager();
    if (dm) {
        Light* light = dm->getLight("Living Room Light");
        if (light) {
            light->powerOff();
        }
        
        TV* tv = dm->getTV("Living Room TV");
        if (tv) {
            tv->powerOff();
        }
        
        SoundSystem* sound = dm->getSoundSystem("Main Sound System");
        if (sound) {
            sound->powerOff();
        }
    }
}

void SleepState::exit(MSHController* controller) {
    // Wake up devices
}

std::string SleepState::getName() const {
    return "Sleep";
}

