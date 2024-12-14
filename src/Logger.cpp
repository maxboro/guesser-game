#include <unordered_map>
#include <string>
#include <iostream>
#include <fstream>
#include <chrono>
#include <iomanip>
#include <sstream>
#include <filesystem>
#include "Logger.h"

using namespace std;

Logger::Logger(const unordered_map<string, int>& settings){
    _settings = settings;
    _perform_logging = _settings["logging"];
    _log_file_name = "./logs/run_log"+_get_current_timestamp()+".log";

    if (_perform_logging){
        cout << "Logging is enabled" << endl;
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

Logger::~Logger() {
    if (_log_file.is_open()) {
        _log_file.close();
    }
}

string Logger::_get_current_timestamp(){
    // time_t timestamp = time(NULL);
    auto now = std::chrono::system_clock::now();
    // Convert to a time_t (seconds since epoch)
    auto now_time_t = std::chrono::system_clock::to_time_t(now);

    // Extract the fractional seconds part
    auto now_ms = std::chrono::duration_cast<std::chrono::milliseconds>(
        now.time_since_epoch()) % 1000;

    // Format and print the time with fractional seconds
    std::tm tm = *std::localtime(&now_time_t);

    // String with time with ms
    ostringstream oss;
    oss << put_time(&tm, "%Y-%m-%d %H.%M.%S") << '.' << setfill('0') << setw(3) << now_ms.count();
    return oss.str();
}

void Logger::_write_to_logfile(const string logging_line){
    if (_log_file.is_open()) {
        _log_file << _get_current_timestamp() << " - " << logging_line << endl;
        _log_file.flush();
    } else {
        cerr << "Error opening the file!" << endl;
    } 
}

void Logger::_log(const string& msg, string type){
    if (_perform_logging){
        string logging_line = type + " - " + msg;
        _write_to_logfile(logging_line);
    }
}

void Logger::info(const string& msg){
    _log(msg, "INFO");
}

void Logger::error(const string& msg){
    _log(msg, "ERROR");
}
