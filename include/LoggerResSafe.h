#ifndef LOGGERRESSAFE_H
#define LOGGERRESSAFE_H

#include <unordered_map>
#include <fstream>

#include "Logger.h"

using namespace std;

class LoggerResSafe: public Logger{
public:
    LoggerResSafe(const unordered_map<string, int>& settings);
protected:
    void _log(const string& msg, string type) override;
private:
    string _log_file_name;
    void _write_to_logfile(string logging_line);
};

#endif
