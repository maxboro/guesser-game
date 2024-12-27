#include <unordered_map>
#include <string>
#include "Logger.h"
#include "utils.h"

using namespace std;


Logger::Logger(const unordered_map<string, int>& settings){
    _settings = settings;
    _perform_logging = _settings["logging"];
    _log_file_name = "./logs/run_log"+get_current_timestamp_ms()+".log";
}

void Logger::info(const string& msg){
    _log(msg, "INFO");
}
void Logger::error(const string& msg){
    _log(msg, "ERROR");
}