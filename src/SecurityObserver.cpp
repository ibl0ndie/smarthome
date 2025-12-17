#include "SecurityObserver.h"
#include "MSHController.h"
#include "DeviceManager.h"
#include "Alarm.h"
#include "Light.h"
#include <iostream>

SecurityObserver::SecurityObserver(MSHController* controller) 
    : controller_(controller) {
}

SecurityObserver::~SecurityObserver() {
}

void SecurityObserver::onMotionDetected() {
    // Security workflow: Camera motion → alarm → turn lights on → call police
    if (controller_) {
        DeviceManager* dm = controller_->getDeviceManager();
        if (dm) {
            // Trigger alarm
            Alarm* alarm = dm->getAlarm("Main Alarm");
            if (alarm) {
                alarm->powerOn();
                alarm->trigger();
            }
            
            // Turn lights on
            Light* light = dm->getLight("Living Room Light");
            if (light) {
                light->powerOn();
                light->setBrightness(100);
            }
            
            // Call police (simulated)
            controller_->log("SECURITY ALERT: Motion detected! Alarm triggered. Lights turned on. Calling police...");
        }
    }
}

