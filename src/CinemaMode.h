#ifndef CINEMAMODE_H
#define CINEMAMODE_H

#include "ModeStrategy.h"

// REQ: Cinema Mode - Strategy Concrete Strategy
// Student Part: Strategy Pattern - Concrete Strategy
class CinemaMode : public ModeStrategy {
public:
    virtual void apply(DeviceManager* deviceManager);
    virtual std::string getName() const;
};

#endif // CINEMAMODE_H

