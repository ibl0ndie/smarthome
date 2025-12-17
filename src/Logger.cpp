#include "Logger.h"
#include <ctime>
#include <iostream>
#include <sstream>


Logger* Logger::instance_ = 0;

Logger::Logger() {
    logFile_.open("msh.log", std::ios::app);
    if (!logFile_.is_open()) {
        std::cerr << "Warning: Could not open log file!" << std::endl;
    }
}

Logger::~Logger() {
    close();
}

Logger& Logger::getInstance() {
    if (!instance_) {
        instance_ = new Logger();
    }
    return *instance_;
}

void Logger::log(const std::string& message) {
    if (logFile_.is_open()) {
        time_t rawtime;
        struct tm* timeinfo;
        char buffer[80];
        
        time(&rawtime);
        timeinfo = localtime(&rawtime);
        strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", timeinfo);
        
        logFile_ << "[" << buffer << "] " << message << std::endl;
        logFile_.flush();
    }
    std::cout << "[LOG] " << message << std::endl;
}

void Logger::close() {
    if (logFile_.is_open()) {
        logFile_.close();
    }
}

