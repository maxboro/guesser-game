#ifndef GAMEENGINE_H
#define GAMEENGINE_H

class GameEngine {
public:
    void set_game(int number, int lives);
    bool guess(int n);
    bool game_status();
    void stop_game();
    int get_number();
    int get_lives();
    bool have_lives();

private:
    int _number, _lives;
    bool _is_game_running = false;
};

#endif
