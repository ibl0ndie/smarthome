#ifndef LGTV_H
#define LGTV_H

#include "TV.h"

// REQ: LG TV - Factory Method Concrete Product
// Student Part: Factory Method Pattern - Concrete Product
class LGTV : public TV {
public:
    LGTV(const std::string& name);
    virtual ~LGTV();
    
    virtual void setChannel(int channel);
    virtual int getChannel() const;
    virtual void setVolume(int volume);
    virtual int getVolume() const;
    
private:
    static const int MAX_CHANNEL = 999;
    static const int MAX_VOLUME = 100;
};

#endif // LGTV_H

