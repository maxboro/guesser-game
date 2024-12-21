#ifndef GAMEENGINE_H
#define GAMEENGINE_H
#include <unordered_map>
#include <string>

// Executes game rules based of provided input
class GameEngine {
public:
    GameEngine(std::unordered_map<std::string, int> settings): _settings(settings) {};

    void set_game(int number, int lives);
    bool guess(int n);
    bool game_status();
    void stop_game();
    int get_number();
    int get_lives();
    bool have_lives();

private:
    int _number, _lives;
    std::unordered_map<std::string, int> _settings;
    bool _is_game_running = false;
};

#endif
