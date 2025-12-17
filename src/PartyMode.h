#ifndef PARTYMODE_H
#define PARTYMODE_H

#include "ModeStrategy.h"

// REQ: Party Mode - Strategy Concrete Strategy
// Student Part: Strategy Pattern - Concrete Strategy
class PartyMode : public ModeStrategy {
public:
    virtual void apply(DeviceManager* deviceManager);
    virtual std::string getName() const;
};

#endif // PARTYMODE_H

