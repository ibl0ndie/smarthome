#ifndef TVFACTORY_H
#define TVFACTORY_H

#include "TV.h"
#include <string>

// REQ: Factory Method Pattern for TV creation
// Student Part: Factory Method Pattern - Creator
class TVFactory {
public:
    virtual ~TVFactory();
    
    // Factory Method
    virtual TV* createTV(const std::string& name) = 0;
    
    // Utility method
    static TVFactory* getFactory(const std::string& brand);
};

// REQ: Samsung TV Factory - Factory Method Concrete Creator
class SamsungTVFactory : public TVFactory {
public:
    virtual TV* createTV(const std::string& name);
};

// REQ: LG TV Factory - Factory Method Concrete Creator
class LGTVFactory : public TVFactory {
public:
    virtual TV* createTV(const std::string& name);
};

#endif // TVFACTORY_H

