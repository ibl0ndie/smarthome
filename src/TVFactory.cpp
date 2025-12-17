#include "TVFactory.h"
#include "SamsungTV.h"
#include "LGTV.h"

TVFactory::~TVFactory() {
}

TV* SamsungTVFactory::createTV(const std::string& name) {
    return new SamsungTV(name);
}

TV* LGTVFactory::createTV(const std::string& name) {
    return new LGTV(name);
}

TVFactory* TVFactory::getFactory(const std::string& brand) {
    if (brand == "Samsung") {
        return new SamsungTVFactory();
    } else if (brand == "LG") {
        return new LGTVFactory();
    }
    return 0;
}

