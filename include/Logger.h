#ifndef LOGGER_H
#define LOGGER_H

#include <unordered_map>

using namespace std;

class Logger{
public:
    void info(const string& msg);
    void error(const string& msg);
protected:
    unordered_map<string, int> _settings;
    bool _perform_logging;
    string _get_current_timestamp() const;
    virtual void _log(const string& msg, string type) = 0;
};

#endif