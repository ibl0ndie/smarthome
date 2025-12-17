#ifndef EVENINGMODE_H
#define EVENINGMODE_H

#include "ModeStrategy.h"

// REQ: Evening Mode - Strategy Concrete Strategy
// Student Part: Strategy Pattern - Concrete Strategy
class EveningMode : public ModeStrategy {
public:
    virtual void apply(DeviceManager* deviceManager);
    virtual std::string getName() const;
};

#endif // EVENINGMODE_H

