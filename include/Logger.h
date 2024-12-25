#ifndef LOGGER_H
#define LOGGER_H

#include <unordered_map>
#include <string>

class Logger{
public:
    Logger(const std::unordered_map<std::string, int>& settings);
    virtual ~Logger() = default;
    void info(const std::string& msg);
    void error(const std::string& msg);
protected:
    std::unordered_map<std::string, int> _settings;
    bool _perform_logging;
    std::string _log_file_name;
    virtual void _log(const std::string& msg, std::string type) = 0;
};

#endif