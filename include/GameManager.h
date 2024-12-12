#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <unordered_map>
#include <string>
#include "GameEngine.h"

using namespace std;

class GameManager {
public:
    GameManager(unordered_map<string, int> settings): _settings(settings) {}
    void game_init(GameEngine *game_engine_inst);
    void _submit_guess(int number);
    void run_game_loop();
    void show_current_game_status();
    
private:
    GameEngine* _game_engine_inst;
    unordered_map<string, int> _settings;
    int _get_random_number(int min, int max);
};

#endif