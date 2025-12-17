#ifndef SAMSUNGTV_H
#define SAMSUNGTV_H

#include "TV.h"

// REQ: Samsung TV - Factory Method Concrete Product
// Student Part: Factory Method Pattern - Concrete Product
class SamsungTV : public TV {
public:
    SamsungTV(const std::string& name);
    virtual ~SamsungTV();
    
    virtual void setChannel(int channel);
    virtual int getChannel() const;
    virtual void setVolume(int volume);
    virtual int getVolume() const;
    
private:
    static const int MAX_CHANNEL = 999;
    static const int MAX_VOLUME = 100;
};

#endif // SAMSUNGTV_H

