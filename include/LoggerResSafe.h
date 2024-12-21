#ifndef LOGGERRESSAFE_H
#define LOGGERRESSAFE_H

#include <unordered_map>
#include <fstream>

#include "Logger.h"

class LoggerResSafe: public Logger{
public:
    LoggerResSafe(const std::unordered_map<std::string, int>& settings);
protected:
    void _log(const std::string& msg, std::string type) override;
private:
    void _write_to_logfile(std::string logging_line);
};

#endif
