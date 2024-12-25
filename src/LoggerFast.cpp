#include <unordered_map>
#include <string>
#include <iostream>
#include <filesystem>
#include "LoggerFast.h"
#include "utils.h"

using namespace std;

LoggerFast::LoggerFast(const unordered_map<string, int>& settings): Logger(settings){
    if (_perform_logging){
        cout << "Logging is enabled" << endl;
        cout << "Fast logging mode" << endl;
        filesystem::create_directories("./logs");

        // Open log file
        _log_file.open(_log_file_name, ios::app);
        if (!_log_file.is_open()) {
            cerr << "Error: Unable to open log file!" << endl;
            _perform_logging = false;
        }
    } else {
        cout << "Logging is disabled" << endl;
    }
}

LoggerFast::~LoggerFast() {
    if (_log_file.is_open()) {
        _log_file.close();
    }
}

void LoggerFast::_write_to_logfile(const string logging_line){
    if (_log_file.is_open()) {
        _log_file << get_current_timestamp_ms() << " - " << logging_line << endl;
        _log_file.flush();
    } else {
        cerr << "Error opening the file!" << endl;
    } 
}

void LoggerFast::_log(const string& msg, string type){
    if (_perform_logging){
        string logging_line = type + " - " + msg;
        _write_to_logfile(logging_line);
    }
}
