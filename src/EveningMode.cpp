#include "EveningMode.h"
#include "DeviceManager.h"
#include "Light.h"
#include "TV.h"
#include "SoundSystem.h"

void EveningMode::apply(DeviceManager* deviceManager) {
    // Evening mode: dim lights, moderate TV
    Light* light = deviceManager->getLight("Living Room Light");
    if (light) {
        light->powerOn();
        light->setBrightness(30);
    }
    
    TV* tv = deviceManager->getTV("Living Room TV");
    if (tv) {
        tv->powerOn();
        tv->setVolume(35);
    }
    
    SoundSystem* sound = deviceManager->getSoundSystem("Main Sound System");
    if (sound) {
        sound->powerOff();
    }
}

std::string EveningMode::getName() const {
    return "Evening";
}

