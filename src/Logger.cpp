#include <chrono>
#include <iomanip>
#include <sstream>
#include "Logger.h"

using namespace std;


string Logger::_get_current_timestamp() const {
    // time_t timestamp = time(NULL);
    auto now = chrono::system_clock::now();
    // Convert to a time_t (seconds since epoch)
    auto now_time_t = chrono::system_clock::to_time_t(now);

    // Extract the fractional seconds part
    auto now_ms = chrono::duration_cast<chrono::milliseconds>(
        now.time_since_epoch()) % 1000;

    // Format and print the time with fractional seconds
    tm tm = *localtime(&now_time_t);

    // String with time with ms
    ostringstream oss;
    oss << put_time(&tm, "%Y-%m-%d %H.%M.%S") << '.' << setfill('0') << setw(3) << now_ms.count();
    return oss.str();
}

void Logger::info(const string& msg){
    _log(msg, "INFO");
}
void Logger::error(const string& msg){
    _log(msg, "ERROR");
}