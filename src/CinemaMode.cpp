#include "CinemaMode.h"
#include "DeviceManager.h"
#include "Light.h"
#include "TV.h"
#include "SoundSystem.h"

void CinemaMode::apply(DeviceManager* deviceManager) {
    // Cinema mode: dim lights, high TV volume, enhanced sound
    Light* light = deviceManager->getLight("Living Room Light");
    if (light) {
        light->powerOn();
        light->setBrightness(10);
    }
    
    TV* tv = deviceManager->getTV("Living Room TV");
    if (tv) {
        tv->powerOn();
        tv->setVolume(70);
    }
    
    SoundSystem* sound = deviceManager->getSoundSystem("Main Sound System");
    if (sound) {
        sound->powerOn();
        sound->setVolume(75);
        sound->setBass(70);
    }
}

std::string CinemaMode::getName() const {
    return "Cinema";
}

