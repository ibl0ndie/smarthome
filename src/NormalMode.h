#ifndef NORMALMODE_H
#define NORMALMODE_H

#include "ModeStrategy.h"

// REQ: Normal Mode - Strategy Concrete Strategy
// Student Part: Strategy Pattern - Concrete Strategy
class NormalMode : public ModeStrategy {
public:
    virtual void apply(DeviceManager* deviceManager);
    virtual std::string getName() const;
};

#endif // NORMALMODE_H

