#ifndef LOGGER_H
#define LOGGER_H

#include <unordered_map>

class Logger{
public:
    virtual ~Logger() = default;
    void info(const std::string& msg);
    void error(const std::string& msg);
protected:
    std::unordered_map<std::string, int> _settings;
    bool _perform_logging;
    std::string _get_current_timestamp() const;
    virtual void _log(const std::string& msg, std::string type) = 0;
};

#endif