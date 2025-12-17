#include "NormalState.h"
#include "MSHController.h"
#include "DeviceManager.h"
#include <iostream>

void NormalState::enter(MSHController* controller) {
    // Normal state: standard operation
}

void NormalState::exit(MSHController* controller) {
    // Cleanup if needed
}

std::string NormalState::getName() const {
    return "Normal";
}

