#include "GameEngine.h"

void GameEngine::set_game(int number, int lives) {
    _number = number;
    _lives = lives;
    _is_game_running = true;
}

bool GameEngine::guess(int n) {
    _lives--;
    if (n == _number) {
        return true;
    } else {
        return false;
    }
}

bool GameEngine::game_status() {
    return _is_game_running;
}

void GameEngine::stop_game() {
    _is_game_running = false;
}

int GameEngine::get_number() {
    return _number;
}

int GameEngine::get_lives() {
    return _lives;
}

bool GameEngine::have_lives() {
    return _lives > 0;
}