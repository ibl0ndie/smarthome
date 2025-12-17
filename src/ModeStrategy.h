#ifndef MODESTRATEGY_H
#define MODESTRATEGY_H

#include <string>

class DeviceManager;

// REQ: Strategy Pattern for System Modes
// Student Part: Strategy Pattern - Strategy Interface
class ModeStrategy {
public:
    virtual ~ModeStrategy();
    virtual void apply(DeviceManager* deviceManager) = 0;
    virtual std::string getName() const = 0;
};

#endif // MODESTRATEGY_H

