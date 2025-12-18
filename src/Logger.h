#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <fstream>

class Logger {
public:
    static Logger& getInstance();

    void log(const std::string& message);
    void close();

private:
    Logger();
    ~Logger();

    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

    std::ofstream logFile_;
};

#endif // LOGGER_H
