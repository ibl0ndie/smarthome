#ifndef MSHCONTROLLER_H
#define MSHCONTROLLER_H

#include <string>

class DeviceManager;
class SystemState;
class ModeStrategy;
class Observer;


// REQ: MSHController - Singleton Pattern
// Student Part: Singleton Pattern - Central Controller
class MSHController {
public:
    static MSHController& getInstance();
    
    // Device management
    DeviceManager* getDeviceManager();
    
    // State management
    void setState(SystemState* state);
    SystemState* getCurrentState() const;
    void saveCurrentState();
    void restorePreviousState();
    
    // Mode management
    void setMode(ModeStrategy* mode);
    ModeStrategy* getCurrentMode() const;
    
    // Logging
    void log(const std::string& message);
    
    // Observer access
    Observer* getSecurityObserver() const;
    
    // Security workflow
    void handleSecurityAlert();
    
    // Detection workflow
    void handleSmokeDetection();
    void handleGasDetection();
    
    // Home status
    void printHomeStatus();
    
    // Cleanup
    void shutdown();
    
private:
    MSHController();
    ~MSHController();
    MSHController(const MSHController&);
    MSHController& operator=(const MSHController&);
    
    static MSHController* instance_;
    DeviceManager* deviceManager_;
    SystemState* currentState_;
    SystemState* previousState_;
    ModeStrategy* currentMode_;
    Observer* securityObserver_;
};

#endif // MSHCONTROLLER_H

