#ifndef LOGGERFAST_H
#define LOGGERFAST_H

#include <unordered_map>
#include <fstream>
#include "Logger.h"

class LoggerFast : public Logger {
public:
    LoggerFast(const std::unordered_map<std::string, int>& settings);
    ~LoggerFast();
protected:
    void _log(const std::string& msg, std::string type) override;
private:
    std::ofstream _log_file;
    void _write_to_logfile(std::string logging_line);
};

#endif
