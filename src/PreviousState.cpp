#include "PreviousState.h"
#include "MSHController.h"
#include <iostream>

PreviousState::PreviousState(SystemState* savedState) 
    : savedState_(savedState) {
}

PreviousState::~PreviousState() {
    // Don't delete savedState_ - it's managed by controller
}

void PreviousState::enter(MSHController* controller) {
    // Restore previous state
    if (savedState_) {
        controller->setState(savedState_);
        savedState_->enter(controller);
    }
}

void PreviousState::exit(MSHController* controller) {
    // Nothing special
}

std::string PreviousState::getName() const {
    if (savedState_) {
        return "Previous (" + savedState_->getName() + ")";
    }
    return "Previous";
}

SystemState* PreviousState::getSavedState() const {
    return savedState_;
}

