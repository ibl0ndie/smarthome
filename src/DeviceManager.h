#ifndef DEVICEMANAGER_H
#define DEVICEMANAGER_H

#include <vector>
#include <string>

class Device;
class Light;
class TV;
class SoundSystem;
class Camera;
class Alarm;
class SmokeDetector;
class GasDetector;

// REQ: DeviceManager for storing/managing all devices
// Student Part: Device Management System
class DeviceManager {
public:
    DeviceManager();
    ~DeviceManager();
    
    // Device registration
    void addDevice(Device* device);
    void removeDevice(const std::string& name);
    
    // Device retrieval
    Device* getDevice(const std::string& name);
    Light* getLight(const std::string& name);
    TV* getTV(const std::string& name);
    SoundSystem* getSoundSystem(const std::string& name);
    Camera* getCamera(const std::string& name);
    Alarm* getAlarm(const std::string& name);
    SmokeDetector* getSmokeDetector(const std::string& name);
    GasDetector* getGasDetector(const std::string& name);
    
    // List all devices
    void listAllDevices() const;
    std::vector<Device*> getAllDevices() const;
    
private:
    std::vector<Device*> devices_;
    
    // Helper to find device by name
    Device* findDevice(const std::string& name) const;
};

#endif // DEVICEMANAGER_H

