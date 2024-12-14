#include <iostream>
#include <sstream>
#include <fstream>
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
