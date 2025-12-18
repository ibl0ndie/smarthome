#include "MSHController.h"
#include "DeviceManager.h"
#include "SystemState.h"
#include "ModeStrategy.h"
#include "Observer.h"
#include "SecurityObserver.h"
#include "Logger.h"
#include "Alarm.h"
#include "Light.h"
#include "TV.h"
#include "SoundSystem.h"
#include "Camera.h"
#include "SmokeDetector.h"
#include "GasDetector.h"
#include "Device.h"
#include <iostream>
#include <vector>

MSHController* MSHController::instance_ = 0;

MSHController::MSHController() 
    : deviceManager_(0), currentState_(0), previousState_(0), 
      currentMode_(0), securityObserver_(0) {
    deviceManager_ = new DeviceManager();
    securityObserver_ = new SecurityObserver(this);
    log("MSH System initialized");
}

MSHController::~MSHController() {
    shutdown();
}


MSHController& MSHController::getInstance() {
    static MSHController instance;
    return instance;
}


DeviceManager* MSHController::getDeviceManager() {
    return deviceManager_;
}

void MSHController::setState(SystemState* state) {
    if (currentState_) {
        currentState_->exit(this);
    }
    previousState_ = currentState_;
    currentState_ = state;
    if (currentState_) {
        currentState_->enter(this);
        log("System state changed to: " + currentState_->getName());
    }
}

SystemState* MSHController::getCurrentState() const {
    return currentState_;
}

void MSHController::saveCurrentState() {
    previousState_ = currentState_;
}

void MSHController::restorePreviousState() {
    if (previousState_) {
        setState(previousState_);
    }
}

void MSHController::setMode(ModeStrategy* mode) {
    if (mode && deviceManager_) {
        currentMode_ = mode;
        mode->apply(deviceManager_);
        log("Mode changed to: " + mode->getName());
    }
}

ModeStrategy* MSHController::getCurrentMode() const {
    return currentMode_;
}

void MSHController::log(const std::string& message) {
    Logger::getInstance().log(message);
}

Observer* MSHController::getSecurityObserver() const {
    return securityObserver_;
}

void MSHController::handleSecurityAlert() {
    // Security workflow is handled by SecurityObserver
    log("Security alert handled");
}

void MSHController::handleSmokeDetection() {
    // Detection workflow: Smoke detected → alarm → flashing lights → fire station call
    if (deviceManager_) {
        Alarm* alarm = deviceManager_->getAlarm("Main Alarm");
        if (alarm) {
            alarm->powerOn();
            alarm->trigger();
        }
        
        Light* light = deviceManager_->getLight("Living Room Light");
        if (light) {
            light->powerOn();
            light->setFlashing(true);
            light->setBrightness(100);
        }
        
        log("SMOKE DETECTED! Alarm triggered. Lights flashing. Calling fire station...");
    }
}

void MSHController::handleGasDetection() {
    // Detection workflow: Gas detected → alarm → flashing lights → fire station call
    if (deviceManager_) {
        Alarm* alarm = deviceManager_->getAlarm("Main Alarm");
        if (alarm) {
            alarm->powerOn();
            alarm->trigger();
        }
        
        Light* light = deviceManager_->getLight("Living Room Light");
        if (light) {
            light->powerOn();
            light->setFlashing(true);
            light->setBrightness(100);
        }
        
        log("GAS DETECTED! Alarm triggered. Lights flashing. Calling fire station...");
    }
}

void MSHController::printHomeStatus() {
    std::cout << "\n========================================" << std::endl;
    std::cout << "         HOME STATUS SUMMARY" << std::endl;
    std::cout << "========================================" << std::endl;
    
    // Current System State
    std::cout << "\n[System State]" << std::endl;
    if (currentState_) {
        std::cout << "  Current State: " << currentState_->getName() << std::endl;
    } else {
        std::cout << "  Current State: Not Set" << std::endl;
    }
    
    // Current Mode
    std::cout << "\n[System Mode]" << std::endl;
    if (currentMode_) {
        std::cout << "  Current Mode: " << currentMode_->getName() << std::endl;
    } else {
        std::cout << "  Current Mode: Not Set" << std::endl;
    }
    
    if (!deviceManager_) {
        std::cout << "\nNo devices available." << std::endl;
        std::cout << "========================================" << std::endl;
        return;
    }
    
    // Device counts
    std::vector<Device*> devices = deviceManager_->getAllDevices();
    
    int lightCount = 0, lightOn = 0, lightOff = 0;
    int tvCount = 0, tvOn = 0, tvOff = 0;
    int soundCount = 0, soundOn = 0, soundOff = 0;
    int cameraCount = 0, cameraOn = 0, cameraOff = 0;
    int smokeCount = 0, smokeDetected = 0;
    int gasCount = 0, gasDetected = 0;
    bool alarmFound = false;
    bool alarmOn = false;
    bool alarmTriggered = false;
    
    for (std::vector<Device*>::iterator it = devices.begin(); it != devices.end(); ++it) {
        Device* dev = *it;
        if (!dev) continue;
        
        // Count Lights
        Light* light = dynamic_cast<Light*>(dev);
        if (light) {
            lightCount++;
            if (light->isPowered()) {
                lightOn++;
            } else {
                lightOff++;
            }
            continue;
        }
        
        // Count TVs
        TV* tv = dynamic_cast<TV*>(dev);
        if (tv) {
            tvCount++;
            if (tv->isPowered()) {
                tvOn++;
            } else {
                tvOff++;
            }
            continue;
        }
        
        // Count Sound Systems
        SoundSystem* sound = dynamic_cast<SoundSystem*>(dev);
        if (sound) {
            soundCount++;
            if (sound->isPowered()) {
                soundOn++;
            } else {
                soundOff++;
            }
            continue;
        }
        
        // Count Cameras
        Camera* camera = dynamic_cast<Camera*>(dev);
        if (camera) {
            cameraCount++;
            if (camera->isPowered()) {
                cameraOn++;
            } else {
                cameraOff++;
            }
            continue;
        }
        
        // Count Smoke Detectors
        SmokeDetector* smoke = dynamic_cast<SmokeDetector*>(dev);
        if (smoke) {
            smokeCount++;
            if (smoke->isSmokeDetected()) {
                smokeDetected++;
            }
            continue;
        }
        
        // Count Gas Detectors
        GasDetector* gas = dynamic_cast<GasDetector*>(dev);
        if (gas) {
            gasCount++;
            if (gas->isGasDetected()) {
                gasDetected++;
            }
            continue;
        }
        
        // Check Alarm
        Alarm* alarm = dynamic_cast<Alarm*>(dev);
        if (alarm) {
            alarmFound = true;
            alarmOn = alarm->isPowered();
            alarmTriggered = alarm->isTriggered();
            continue;
        }
    }
    
    // Print device summaries
    std::cout << "\n[Devices Summary]" << std::endl;
    
    std::cout << "  Lights: " << lightCount << " total";
    if (lightCount > 0) {
        std::cout << " (" << lightOn << " ON, " << lightOff << " OFF)";
    }
    std::cout << std::endl;
    
    std::cout << "  TVs: " << tvCount << " total";
    if (tvCount > 0) {
        std::cout << " (" << tvOn << " ON, " << tvOff << " OFF)";
    }
    std::cout << std::endl;
    
    std::cout << "  Sound Systems: " << soundCount << " total";
    if (soundCount > 0) {
        std::cout << " (" << soundOn << " ON, " << soundOff << " OFF)";
    }
    std::cout << std::endl;
    
    std::cout << "  Cameras: " << cameraCount << " total";
    if (cameraCount > 0) {
        std::cout << " (" << cameraOn << " ON, " << cameraOff << " OFF)";
    }
    std::cout << std::endl;
    
    std::cout << "  Smoke Detectors: " << smokeCount << " total";
    if (smokeCount > 0) {
        std::cout << " (" << smokeDetected << " detecting smoke)";
    }
    std::cout << std::endl;
    
    std::cout << "  Gas Detectors: " << gasCount << " total";
    if (gasCount > 0) {
        std::cout << " (" << gasDetected << " detecting gas)";
    }
    std::cout << std::endl;
    
    std::cout << "  Alarm: ";
    if (alarmFound) {
        if (alarmOn) {
            std::cout << "ON";
            if (alarmTriggered) {
                std::cout << " [TRIGGERED]";
            }
        } else {
            std::cout << "OFF";
        }
    } else {
        std::cout << "Not found";
    }
    std::cout << std::endl;
    
    std::cout << "\n========================================" << std::endl;
    
    log("Home status displayed");
}

void MSHController::shutdown() {
    log("MSH System shutting down");
    
    if (deviceManager_) {
        delete deviceManager_;
        deviceManager_ = 0;
    }
    
    if (securityObserver_) {
        delete securityObserver_;
        securityObserver_ = 0;
    }
    
    // Note: States and modes are managed externally
    currentState_ = 0;
    previousState_ = 0;
    currentMode_ = 0;
}

