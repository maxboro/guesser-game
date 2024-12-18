#ifndef LOGGERFAST_H
#define LOGGERFAST_H

#include <unordered_map>
#include <fstream>
#include "Logger.h"

using namespace std;

class LoggerFast : public Logger {
public:
    LoggerFast(const unordered_map<string, int>& settings);
    ~LoggerFast();
protected:
    void _log(const string& msg, string type) override;
private:
    string _log_file_name;
    ofstream _log_file;
    void _write_to_logfile(string logging_line);
};

#endif
