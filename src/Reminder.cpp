#include <iostream>
#include <chrono>
#include "utils.h"
#include <thread>
#include "Reminder.h"

using namespace std;

Reminder::Reminder(atomic<bool> *exit_is_requested_ptr, unordered_map<string, int> &settings){
    _reminder_period = settings["reminder_period"];
    _max_n_reminds= settings["max_n_reminds"];
    _exit_is_requested_ptr = exit_is_requested_ptr;
}


void Reminder::set_start(){
    _n_reminds = 0;
    _start_timestamp = get_current_timestamp();
    try {
        _reminder_loop();
    } catch (const exception& e) {
        _exit_is_requested_ptr->store(true);
        cout << "Exception in Reminder thread: " << e.what() << endl;
    } catch (...) {
        _exit_is_requested_ptr->store(true);
        cout << "Unknown error in Reminder thread" << endl;
    }
}

void Reminder::_reminder_loop(){
    cout << "Reminds are enabled" << endl;

    // Time checking loop
    while (!_exit_is_requested_ptr->load()){
        this_thread::sleep_for(chrono::seconds(1));
        _current_timestamp = get_current_timestamp();
        bool is_time_to_remind = _current_timestamp - _start_timestamp > _reminder_period;
        if (is_time_to_remind){
            cout << endl;
            cout << "Buddy, maybe it's time to get some rest?" << endl;
            _start_timestamp = _current_timestamp;
            _n_reminds++;
        }

        if (_n_reminds >= _max_n_reminds){
            cout << "That was the last remind" << endl;
            break;
        }
    }

    cout << "Reminds are disabled" << endl;
}