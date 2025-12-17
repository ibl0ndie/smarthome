#include "HighPerformanceState.h"
#include "MSHController.h"
#include "DeviceManager.h"
#include "Light.h"
#include "TV.h"
#include "SoundSystem.h"
#include <iostream>

void HighPerformanceState::enter(MSHController* controller) {
    // High performance: optimize all devices
    DeviceManager* dm = controller->getDeviceManager();
    if (dm) {
        Light* light = dm->getLight("Living Room Light");
        if (light) {
            light->powerOn();
            light->setBrightness(100);
        }
    }
}

void HighPerformanceState::exit(MSHController* controller) {
    // Return to normal settings
}

std::string HighPerformanceState::getName() const {
    return "High Performance";
} 

