#include <string>
#include <iostream>
#include <stdexcept>
#include <random>

#define MIN_VAL 0
#define MAX_VAL 10
#define N_LIVES 3

using namespace std;


class GameEngine {
    // GameEngine(){ }

public:
    void set_game(int number, int lives){
        _number = number;
        _lives = lives;
        _is_game_running = true;
    }
    
    bool guess(int n){
        _lives--;
        if (n == _number){
            return true;
        } else {
            return false;
        }
    }

    bool game_status(){
        return _is_game_running;
    }

    void stop_game(){
        _is_game_running = false;
    }

    int get_number(){
        return _number;
    }
    
    int get_lives(){
        return _lives;
    }

    bool have_lives(){
        return _lives > 0;
    }

private:
    int _number, _lives;
    bool _is_game_running = false;
};

class GameManager {
public:
    // Guesser(){ }

    void game_init(GameEngine &game_engine_inst){
        _game_engine_inst = game_engine_inst;
        int number_to_guess = _get_random_number(MIN_VAL, MAX_VAL);
        _game_engine_inst.set_game(number_to_guess, N_LIVES);
    }
    
    void _submit_guess(int number){
        bool result = _game_engine_inst.guess(number);
        if (result){
            cout << "You guessed! Game over." << endl;
            _game_engine_inst.stop_game();
        } else {
            cout << "Nope. This is not a " << number << endl;
            if (!_game_engine_inst.have_lives()){
                cout << "No more lives" << endl;
                _game_engine_inst.stop_game();
            }
        }
    }

    void run_game_loop(){
        while (_game_engine_inst.game_status()){
            cout << "write you guess: ";
            string user_input;
            cin >> user_input;
            int user_input_cast = stoi(user_input);
            _submit_guess(user_input_cast);
        }
        cout << "End of game loop" << endl;
        
    }
    
    void show_current_game_status(){
        cout << "Lives: " << _game_engine_inst.get_lives() << "; Number was: " << _game_engine_inst.get_number() << endl;
    }
    
private:
    GameEngine _game_engine_inst;

    int _get_random_number(int min, int max){
        // Initialize a random number generator
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> distrib(min, max);

        // Generate random number in the range [min, max]
        int randomValue = distrib(gen);

        return randomValue;
    }
};

void run(){
    GameManager manager_inst;
    GameEngine game_engine_inst;

    manager_inst.game_init(game_engine_inst);
    manager_inst.run_game_loop();
}

bool ask_for_rerun(){
    cout << "Wanna rerun? y / n: ";
    string user_input;
    cin >> user_input;
    if (user_input == "y"){
        cout << "Ok, let's rerun" << endl;
        return true;
    } else if (user_input == "n"){
        cout << "Ok, no rerun for you" << endl;
        return false;
    } else {
        cout << user_input << " is not a valid response" << endl;
        return ask_for_rerun();
    }
    
}

int main()
{
    do {
        run();
    } while (ask_for_rerun());
    cout << "End" << endl;
    return 0;
}