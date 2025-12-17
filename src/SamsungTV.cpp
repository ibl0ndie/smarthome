#include "SamsungTV.h"

SamsungTV::SamsungTV(const std::string& name) 
    : TV(name, "Samsung") {
}

SamsungTV::~SamsungTV() {
}

void SamsungTV::setChannel(int channel) {
    if (channel >= 1 && channel <= MAX_CHANNEL) {
        channel_ = channel;
    }
}

int SamsungTV::getChannel() const {
    return channel_;
}

void SamsungTV::setVolume(int volume) {
    if (volume < 0) volume = 0;
    if (volume > MAX_VOLUME) volume = MAX_VOLUME;
    volume_ = volume;
}

int SamsungTV::getVolume() const {
    return volume_;
}

