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

/*
 * DeviceManager
 * - Acts as a REGISTRY: stores and retrieves devices
 * - Acts as a FACADE: provides simple high-level operations
 */
class DeviceManager {
public:
    DeviceManager();
    ~DeviceManager();

    // Registry: device management
    void addDevice(Device* device);
    void removeDevice(const std::string& name);

    // Registry: retrieval
    Device* getDevice(const std::string& name);
    Light* getLight(const std::string& name);
    TV* getTV(const std::string& name);
    SoundSystem* getSoundSystem(const std::string& name);
    Camera* getCamera(const std::string& name);
    Alarm* getAlarm(const std::string& name);
    SmokeDetector* getSmokeDetector(const std::string& name);
    GasDetector* getGasDetector(const std::string& name);

    // Info
    void listAllDevices() const;
    std::vector<Device*> getAllDevices() const;

    // ======================
    // Facade operations
    // (MATCH YOUR REAL APIs)
    // ======================

    // Light
    bool setLightBrightness(const std::string& name, int level); // 0-100
    bool setLightFlashing(const std::string& name, bool flashing);

    // Camera
    bool cameraSimulateMotion(const std::string& name);
    bool cameraDetectMotion(const std::string& name, bool &detected);

    // Alarm
    bool isAlarmTriggered(const std::string& name, bool &triggered);

private:
    std::vector<Device*> devices_;

    // Helper
    Device* findDevice(const std::string& name) const;
};

#endif // DEVICEMANAGER_H
