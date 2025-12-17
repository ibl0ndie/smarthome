#include "NormalMode.h"
#include "DeviceManager.h"
#include "Light.h"
#include "TV.h"
#include "SoundSystem.h"
#include <iostream>

void NormalMode::apply(DeviceManager* deviceManager) {
    // Normal mode: moderate settings
    Light* light = deviceManager->getLight("Living Room Light");
    if (light) {
        light->powerOn();
        light->setBrightness(60);
    }
    
    TV* tv = deviceManager->getTV("Living Room TV");
    if (tv) {
        tv->powerOn();
        tv->setVolume(40);
    }
    
    SoundSystem* sound = deviceManager->getSoundSystem("Main Sound System");
    if (sound) {
        sound->powerOn();
        sound->setVolume(30);
    }
}

std::string NormalMode::getName() const {
    return "Normal";
}

