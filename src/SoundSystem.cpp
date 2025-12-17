#include "SoundSystem.h"
#include <sstream>

SoundSystem::SoundSystem(const std::string& name) 
    : Device(name), volume_(50), bass_(50) {
}

SoundSystem::~SoundSystem() {
}

void SoundSystem::powerOn() {
    powered_ = true;
}

void SoundSystem::powerOff() {
    powered_ = false;
}

std::string SoundSystem::getStatus() const {
    std::ostringstream oss;
    oss << "Sound System [" << name_ << "] - ";
    if (powered_) {
        oss << "ON (Volume: " << volume_ << "%, Bass: " << bass_ << "%)";
    } else {
        oss << "OFF";
    }
    return oss.str();
}

void SoundSystem::setVolume(int volume) {
    if (volume < 0) volume = 0;
    if (volume > 100) volume = 100;
    volume_ = volume;
}

int SoundSystem::getVolume() const {
    return volume_;
}

void SoundSystem::setBass(int level) {
    if (level < 0) level = 0;
    if (level > 100) level = 100;
    bass_ = level;
}

int SoundSystem::getBass() const {
    return bass_;
}

