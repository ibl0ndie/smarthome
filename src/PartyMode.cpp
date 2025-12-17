#include "PartyMode.h"
#include "DeviceManager.h"
#include "Light.h"
#include "TV.h"
#include "SoundSystem.h"

void PartyMode::apply(DeviceManager* deviceManager) {
    // Party mode: bright lights, loud sound
    Light* light = deviceManager->getLight("Living Room Light");
    if (light) {
        light->powerOn();
        light->setBrightness(100);
    }
    
    TV* tv = deviceManager->getTV("Living Room TV");
    if (tv) {
        tv->powerOn();
        tv->setVolume(80);
    }
    
    SoundSystem* sound = deviceManager->getSoundSystem("Main Sound System");
    if (sound) {
        sound->powerOn();
        sound->setVolume(90);
        sound->setBass(80);
    }
}

std::string PartyMode::getName() const {
    return "Party";
}

