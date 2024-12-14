#include <iostream>
#include "GameEngine.h"
#include "GameManager.h"
#include "Logger.h"
#include "utils.h"

using namespace std;

void run(unordered_map<string, int> settings, bool &exit_is_requested){
    Logger logger {settings};
    GameManager manager_inst {settings};
    GameEngine game_engine_inst {settings};

    manager_inst.game_init(&game_engine_inst, &logger);
    try {
        // Game session loop
        manager_inst.run_game_loop();
    } catch (const std::runtime_error& e) {
        logger.error(e.what());
        std::cout << "Game loop interrupted: " << e.what() << std::endl;
        exit_is_requested = true;
    }
}

int main()
{
    bool exit_is_requested = false;
    unordered_map<string, int> settings = read_config();

    // Rerun loop
    do {
        run(settings, exit_is_requested);
    } while (!exit_is_requested && ask_for_rerun());

    cout << "End" << endl;
    return 0;
}