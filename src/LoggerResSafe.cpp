#include <unordered_map>
#include <string>
#include <iostream>
#include <filesystem>
#include "LoggerResSafe.h"

using namespace std;

LoggerResSafe::LoggerResSafe(const unordered_map<string, int>& settings): Logger(settings){
    if (_perform_logging){
        cout << "Logging is enabled" << endl;
        cout << "Safe logging mode" << endl;
        filesystem::create_directories("./logs");
    } else {
        cout << "Logging is disabled" << endl;
    }
}

void LoggerResSafe::_write_to_logfile(const string logging_line){
    ofstream _log_file(_log_file_name, ios::app);

    if (_log_file.is_open()) {
        _log_file << _get_current_timestamp() << " - " << logging_line << endl;
        _log_file.flush();
    } else {
        throw runtime_error("Error opening the file!");
    } 
}

void LoggerResSafe::_log(const string& msg, string type){
    if (_perform_logging){
        string logging_line = type + " - " + msg;
        _write_to_logfile(logging_line);
    }
}
