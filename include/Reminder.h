#include <atomic>
#include <unordered_map>
#include <string>

class Reminder{
public:
    Reminder(std::atomic<bool> *exit_is_requested_ptr, std::unordered_map<std::string, int> &settings);
    void set_start();

private:
    int _start_timestamp;
    int _current_timestamp;
    int _reminder_period;
    int _n_reminds;
    int _max_n_reminds;
    std::atomic<bool> * _exit_is_requested_ptr;

    void _reminder_loop();
};