#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "GameEngine.h"

#define MIN_VAL 0
#define MAX_VAL 10
#define N_LIVES 3

class GameManager {
public:
    void game_init(GameEngine &game_engine_inst);
    void _submit_guess(int number);
    void run_game_loop();
    void show_current_game_status();
    
private:
    GameEngine _game_engine_inst;

    int _get_random_number(int min, int max);
};

#endif