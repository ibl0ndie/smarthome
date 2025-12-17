#ifndef CAMERA_H
#define CAMERA_H

#include "Device.h"

// Forward declaration for Observer pattern
class Observer;

// REQ: Camera device with motion detection
// Student Part: Observer Pattern - Subject
class Camera : public Device {
public:
    Camera(const std::string& name);
    virtual ~Camera();
    
    virtual void powerOn();
    virtual void powerOff();
    virtual std::string getStatus() const;
    
    // Observer pattern methods
    void attach(Observer* observer);
    void detach(Observer* observer);
    void notifyMotion();
    
    bool detectMotion();
    void simulateMotion();
    
private:
    Observer* observer_;
    bool motionDetected_;
};

#endif // CAMERA_H

