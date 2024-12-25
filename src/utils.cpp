#include <iostream>
#include <sstream>
#include <fstream>
#include <chrono>
#include <iomanip>
#include "utils.h"

using namespace std;

unordered_map<string, int> read_config(){
    string config_line;

    cout << "Reading the settings." << endl;

    unordered_map<string, int> settings;
    string settings_name;
    string settings_value_str;
    int equal_sign_position;

    // Read from the text file
    ifstream config_file("settings.txt");

    while (getline(config_file, config_line)) {

        equal_sign_position = config_line.find("=");
        settings_name = config_line.substr(0, equal_sign_position);
        settings_value_str = config_line.substr(equal_sign_position + 1, config_line.length());
        cout << settings_name << ": " << settings_value_str << endl;
        settings[settings_name] = stoi(settings_value_str);
    }

    cout << "Read all" << endl;

    // Close the file
    config_file.close();
    cout << "Settings are loaded." << endl;
    return settings;
}


bool ask_for_rerun(){
    cout << "Wanna rerun? y / n: ";
    string user_input;
    cin >> user_input;
    if (user_input == "y"){
        cout << "Ok, let's rerun" << endl;
        return true;
    } else if (user_input == "n" || user_input == "e"){
        cout << "Ok, no rerun for you" << endl;
        return false;
    } else {
        cout << user_input << " is not a valid response" << endl;
        return ask_for_rerun();
    }  
}

string get_current_timestamp_ms(){
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

int get_current_timestamp(){
    // time_t timestamp = time(NULL);
    auto now = chrono::system_clock::now();
    // Convert to a time_t (seconds since epoch)
    auto now_time_t = chrono::system_clock::to_time_t(now);
    return now_time_t;
}

