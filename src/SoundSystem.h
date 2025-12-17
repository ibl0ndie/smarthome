#ifndef SOUNDSYSTEM_H
#define SOUNDSYSTEM_H

#include "Device.h"

// REQ: Sound System device
// Student Part: Device Implementation
class SoundSystem : public Device {
public:
    SoundSystem(const std::string& name);
    virtual ~SoundSystem();
    
    virtual void powerOn();
    virtual void powerOff();
    virtual std::string getStatus() const;
    
    void setVolume(int volume);
    int getVolume() const;
    void setBass(int level);
    int getBass() const;
    
private:
    int volume_;
    int bass_;
};

#endif // SOUNDSYSTEM_H

