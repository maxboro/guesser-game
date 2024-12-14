#ifndef LOGGER_H
#define LOGGER_H

#include <unordered_map>
#include <fstream>

using namespace std;

class Logger{
public:
    Logger(const unordered_map<string, int>& settings);
    ~Logger();
    void info(const string& msg);
    void error(const string& msg);
private:
    unordered_map<string, int> _settings;
    bool _perform_logging;
    string _log_file_name;
    ofstream _log_file;
    string _get_current_timestamp();
    void _write_to_logfile(string logging_line);
    void _log(const string& msg, string type);
};

#endif
