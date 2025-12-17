#ifndef LOGGER_H
#define LOGGER_H


#include <string>
#include <fstream>

// REQ: Logger for all operations
// Student Part: Logging System
class Logger {
public:
    static Logger& getInstance();
    
    void log(const std::string& message);
    void close();
    
private:
    Logger();
    ~Logger();
    Logger(const Logger&);
    Logger& operator=(const Logger&);
    
    std::ofstream logFile_;
    static Logger* instance_;
};

#endif // LOGGER_H

