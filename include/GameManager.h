#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <unordered_map>
#include <string>
#include "GameEngine.h"
#include "Logger.h"

using namespace std;

class GameManager {
public:
    GameManager(unordered_map<string, int> settings): _settings(settings) {}
    void game_init(GameEngine *game_engine_inst, Logger *logger);
    void run_game_loop();
    string get_current_game_status();
    
private:
    GameEngine* _game_engine_inst;
    Logger* _logger;
    unordered_map<string, int> _settings;
    int _get_random_number(int min, int max);
    void _submit_guess(int number);
    void _check_for_exit_request(string &user_input);
};

#endif
