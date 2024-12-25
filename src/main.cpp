#include <iostream>
#include <memory>
#include <atomic>
#include <thread>
#include "GameEngine.h"
#include "GameManager.h"
#include "Logger.h"
#include "LoggerFast.h"
#include "LoggerResSafe.h"
#include "Reminder.h"
#include "utils.h"

using namespace std;

// Session loop
void run(unordered_map<string, int> settings, atomic<bool> &exit_is_requested){
    unique_ptr<Logger> logger;

    if (settings["fast_logging"] == 1) {
        logger = make_unique<LoggerFast>(settings);
    } else {
        logger = make_unique<LoggerResSafe>(settings);
    }
    
    GameManager manager_inst {settings};
    GameEngine game_engine_inst {settings};

    manager_inst.game_init(&game_engine_inst, logger.get());
    try {
        manager_inst.run_game_loop();
    } catch (const runtime_error& e) {
        logger->error(e.what());
        logger->info(manager_inst.get_current_game_status());
        cout << "Game loop interrupted: " << e.what() << endl;
        exit_is_requested = true;
    }
}

// Runtime loop
int main()
{
    atomic<bool> exit_is_requested{false};
    unordered_map<string, int> settings = read_config();

    // Reminder thread
    Reminder reminder {exit_is_requested, settings};
    thread reminder_thread(&Reminder::set_start, &reminder);
    reminder_thread.detach();

    // Session relaunch
    do {
        run(settings, exit_is_requested);
    } while (!exit_is_requested && ask_for_rerun());

    cout << "End" << endl;
    return 0;
}
