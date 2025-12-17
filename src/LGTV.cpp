#include "LGTV.h"

LGTV::LGTV(const std::string& name) 
    : TV(name, "LG") {
}

LGTV::~LGTV() {
}

void LGTV::setChannel(int channel) {
    if (channel >= 1 && channel <= MAX_CHANNEL) {
        channel_ = channel;
    }
}

int LGTV::getChannel() const {
    return channel_;
}

void LGTV::setVolume(int volume) {
    if (volume < 0) volume = 0;
    if (volume > MAX_VOLUME) volume = MAX_VOLUME;
    volume_ = volume;
}

int LGTV::getVolume() const {
    return volume_;
}

