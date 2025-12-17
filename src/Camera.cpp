#include "Camera.h"
#include "Observer.h"
#include <sstream>

Camera::Camera(const std::string& name) 
    : Device(name), observer_(0), motionDetected_(false) {
}

Camera::~Camera() {
}

void Camera::powerOn() {
    powered_ = true;
    motionDetected_ = false;
}

void Camera::powerOff() {
    powered_ = false;
    motionDetected_ = false;
}

std::string Camera::getStatus() const {
    std::ostringstream oss;
    oss << "Camera [" << name_ << "] - ";
    if (powered_) {
        oss << "ON";
        if (motionDetected_) {
            oss << " [MOTION DETECTED]";
        }
    } else {
        oss << "OFF";
    }
    return oss.str();
}

void Camera::attach(Observer* observer) {
    observer_ = observer;
}

void Camera::detach(Observer* observer) {
    if (observer_ == observer) {
        observer_ = 0;
    }
}

void Camera::notifyMotion() {
    if (observer_) {
        observer_->onMotionDetected();
    }
}

bool Camera::detectMotion() {
    return motionDetected_;
}

void Camera::simulateMotion() {
    if (powered_) {
        motionDetected_ = true;
        notifyMotion();
    }
}

